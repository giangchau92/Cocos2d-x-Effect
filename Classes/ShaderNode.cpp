//
//  ShaderNode.cpp
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/30/15.
//
//

#include "ShaderNode.h"

ShaderNode::ShaderNode()
:_texture(nullptr), _rendertTexture(nullptr)
{
}

ShaderNode::~ShaderNode()
{
    CC_SAFE_RELEASE(_texture);
    CC_SAFE_RELEASE(_rendertTexture);
}

bool ShaderNode::init()
{
    if (!Node::init())
        return false;
    
    Size winsize = Director::getInstance()->getWinSize();
    
    _rendertTexture = RenderTexture::create(winsize.width, winsize.height);
    _rendertTexture->retain();
    
    //_texture = Director::getInstance()->getTextureCache()->addImage("HelloWorld.png");
    //_texture->retain();
    _texture = _rendertTexture->getSprite()->getTexture();
    
    Size size = _texture->getContentSizeInPixels();
    _vertices.push_back(Point::ZERO);
    _vertices.push_back(Point(size.width, 0));
    _vertices.push_back(Point(0, size.height));
    _vertices.push_back(Point(size.width, size.height));
    
    _texCoords.push_back(Point::ZERO);
    _texCoords.push_back(Point(1, 0));
    _texCoords.push_back(Point(0, 1));
    _texCoords.push_back(Point(1, 1));
    
    setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE));
    
    return true;
}

void ShaderNode::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
{
    if (!_visible)
        return;
    
    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    
    _director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    _director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    
    bool visibleByCamera = isVisitableByVisitingCamera();
    int i = 0;
    _rendertTexture->beginWithClear(0, 0, 0, 0);
    if (!_children.empty())
    {
        sortAllChildren();
        for( ; i < _children.size(); i++ )
        {
            auto node = _children.at(i);
            
            if (node && node->getLocalZOrder() < 0)
                node->visit(renderer, Mat4::IDENTITY, flags);
            else
                break;
        }
        
        for(auto it=_children.cbegin()+i; it != _children.cend(); ++it)
            (*it)->visit(renderer, Mat4::IDENTITY, flags);
    }
    _rendertTexture->end();
    
    if (visibleByCamera)
    {
        this->draw(renderer, _modelViewTransform, flags);
    }
}

void ShaderNode::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    _customCommand.init(_globalZOrder);
    _customCommand.func = [=]() {
        CC_NODE_DRAW_SETUP();
        GL::bindTexture2D(_texture->getName());
        GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_TEX_COORD);
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0,  &_vertices[0]);
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, 0, &_texCoords[0]);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)_vertices.size());
    };
    Director::getInstance()->getRenderer()->addCommand(&_customCommand);
}