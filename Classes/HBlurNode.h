//
//  HBlurNode.h
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/31/15.
//
//

#ifndef __CocosEffect__HBlurNode__
#define __CocosEffect__HBlurNode__

#include "ShaderNode.h"

class HBlurNode : public ShaderNode
{
public:
    virtual bool initWithWH(float w, float h);
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
    static HBlurNode* createWithWH(float w, float h);
};

#endif /* defined(__CocosEffect__HBlurNode__) */
