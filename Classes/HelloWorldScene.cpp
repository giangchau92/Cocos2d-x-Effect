#include "HelloWorldScene.h"
#include "ShaderNode.h"
#include "HBlurNode.h"
#include "VBlurNode.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Sprite* sprite = Sprite::create("HelloWorld.png");
    sprite->setAnchorPoint(Point::ZERO);
    sprite->setPosition(0, 0);
    
    Size size = sprite->getContentSize();
    Size winsize = Director::getInstance()->getWinSize();
    //size = winsize;
    
    HBlurNode* node = HBlurNode::createWithWH(size.width, size.height);
    //node->addChild(sprite);
    node->setPosition(0, 0);
    
    
    ShaderNode* shader = ShaderNode::createWithWH(size.width, size.height);
    shader->addChild(sprite);
    //addChild(shader);
    
    ShaderNode* shader2 = ShaderNode::createWithWH(winsize.width, winsize.height);
    shader2->addChild(shader);
    addChild(shader2);
    
    //addChild(node->getRenderer());
    
    //HBlurNode* node2 = HBlurNode::createWithWH(size.width, size.height);
    //node2->addChild(node);
    //node2->setPosition(0, 0);
    
    
    //addChild(node2);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
