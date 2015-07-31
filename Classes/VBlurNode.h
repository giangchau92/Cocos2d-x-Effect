//
//  VBlurNode.h
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/31/15.
//
//

#ifndef __CocosEffect__VBlurNode__
#define __CocosEffect__VBlurNode__

#include "ShaderNode.h"

class VBlurNode : public ShaderNode
{
public:
    virtual bool init();
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
    static VBlurNode* create();
};

#endif /* defined(__CocosEffect__VBlurNode__) */
