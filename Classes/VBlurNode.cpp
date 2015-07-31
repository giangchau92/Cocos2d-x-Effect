//
//  VBlurNode.cpp
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/31/15.
//
//

#include "VBlurNode.h"

bool VBlurNode::init()
{
    if (!ShaderNode::init())
        return false;
    
    GLProgram* program = GLProgram::createWithFilenames("Shaders/ccShader_blur.vert", "Shaders/Blur_vertical_sampling.frag");
    setGLProgram(program);
    
    setContentSize(_texture->getContentSizeInPixels());
    
    return true;
}

VBlurNode* VBlurNode::create()
{
    VBlurNode* result = new VBlurNode();
    if (result && result->init())
        result->retain();
    else {
        delete result;
        result = nullptr;
    }
    return result;
}

void VBlurNode::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    _customCommand.init(_globalZOrder);
    _customCommand.func = [=]() {
        CC_NODE_DRAW_SETUP();
        GLint uResolution = getGLProgram()->getUniformLocation("u_resolution");
        Size winSize = this->getBoundingBox().size;
        glUniform2f(uResolution, winSize.width, winSize.height);
        GL::bindTexture2D(_texture->getName());
        GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_TEX_COORD);
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0,  &_vertices[0]);
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, 0, &_texCoords[0]);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)_vertices.size());
    };
    Director::getInstance()->getRenderer()->addCommand(&_customCommand);
}