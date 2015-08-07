//
//  BlurNode.cpp
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/31/15.
//
//

#include "BlurNode.h"

BlurNode::BlurNode()
: _hnode(nullptr), _vnode(nullptr)
{
}

BlurNode::~BlurNode()
{
    CC_SAFE_RELEASE(_hnode);
    CC_SAFE_RELEASE(_vnode);
}

bool BlurNode::initWithWH(float w, float h, unsigned int n)
{
    if (!ShaderNode::initWithWH(w, h))
        return false;
    
    _hnode = HBlurNode::createWithWH(w, h, n);
    if (!_hnode)
        return false;
    _hnode->retain();
    Node::addChild(_hnode);
    
    _vnode = VBlurNode::createWithWH(w, h, n);
    if (!_vnode)
        return false;
    _vnode->retain();
    _hnode->addChild(_vnode);
    //_hnode->getRenderer()->setKeepMatrix(true);
    
    return true;
}

BlurNode* BlurNode::createWithWH(float w, float h, unsigned int n)
{
    BlurNode* result = new BlurNode();
    if (result && result->initWithWH(w, h, n))
        result->autorelease();
    else {
        delete result;
        result = nullptr;
    }
    return result;
}

void BlurNode::addChild(Node * child)
{
    _vnode->addChild(child);
}