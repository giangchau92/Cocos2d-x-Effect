//
//  BlurNode.h
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/31/15.
//
//

#ifndef __CocosEffect__BlurNode__
#define __CocosEffect__BlurNode__

#include "ShaderNode.h"

class BlurNode : public ShaderNode
{
public:
    virtual bool init();
    CREATE_FUNC(BlurNode);
};

#endif /* defined(__CocosEffect__BlurNode__) */
