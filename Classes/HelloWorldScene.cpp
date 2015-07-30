#include "HelloWorldScene.h"
#include "ShaderNode.h"

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
    
    ShaderNode* node = ShaderNode::create();
    addChild(node);
    node->setPosition(100, 100);
    
    Sprite* sprite = Sprite::create("HelloWorld.png");
    sprite->setAnchorPoint(Point::ZERO);
    sprite->setPosition(-100, -100);
    node->addChild(sprite);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
