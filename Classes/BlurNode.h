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
#include "HBlurNode.h"
#include "VBlurNode.h"

class BlurNode : public Node
{
public:
    BlurNode();
    ~BlurNode();
    virtual bool initWithWH(float w, float h, unsigned int n);
    virtual void addChild(Node * child);
    
    static BlurNode* createWithWH(float w, float h, unsigned int n);
private:
    HBlurNode* _hnode;
    VBlurNode* _vnode;
};

#endif /* defined(__CocosEffect__BlurNode__) */
