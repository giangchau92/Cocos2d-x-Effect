//
//  BlurNode.cpp
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/31/15.
//
//

#include "BlurNode.h"

bool BlurNode::init()
{
    if (!ShaderNode::init())
        return false;
    
    //GLProgram* program = GLProgram::createWithFilenames(const std::string &vShaderFilename, const std::string &fShaderFilename)
    
    //setGLProgram(GLProgramCache::loadDefaultGLProgram(<#cocos2d::GLProgram *program#>, <#int type#>))
    
    return true;
}