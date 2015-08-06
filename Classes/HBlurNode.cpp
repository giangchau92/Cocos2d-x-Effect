//
//  HBlurNode.cpp
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/31/15.
//
//

#include "HBlurNode.h"

bool HBlurNode::initWithWH(float w, float h, unsigned int n)
{
    if (!ShaderNode::initWithWH(w, h))
        return false;
    
    GLProgram* program = GLProgram::createWithFilenames("Shaders/ccShader_blur.vert", "Shaders/Blur_horizontal_sampling.frag");
    setGLProgram(program);
    
    _n = n;
    
    return true;
}

HBlurNode* HBlurNode::createWithWH(float w, float h, unsigned int n)
{
    HBlurNode* result = new HBlurNode();
    if (result && result->initWithWH(w, h, n))
        result->autorelease();
    else {
        delete result;
        result = nullptr;
    }
    return result;
}

void HBlurNode::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    _customCommand.init(_globalZOrder);
    _customCommand.func = [=]() {
        CC_NODE_DRAW_SETUP();
        GLint uResolution = getGLProgram()->getUniformLocation("u_resolution");
        Size winSize = Director::getInstance()->getWinSize();
        glUniform2f(uResolution, winSize.width, winSize.height);
        GL::bindTexture2D(_texture->getName());
        GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_TEX_COORD);
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0,  &_vertices[0]);
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, 0, &_texCoords[0]);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, (int)_vertices.size());
    };
    Director::getInstance()->getRenderer()->addCommand(&_customCommand);
}