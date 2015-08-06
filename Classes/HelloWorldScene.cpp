#include "HelloWorldScene.h"
#include "ShaderNode.h"
#include "BlurNode.h"

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
    
    // init event
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = [=](Touch*, Event*)->bool {
        
        std::string path = FileUtils::getInstance()->getWritablePath();
        //_shaderNode->saveTexture("capture.png");
        int a;
        a = 1;
        return true;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    Sprite* sprite = Sprite::create("HelloWorld.png");
    sprite->setAnchorPoint(Point::ZERO);
    sprite->setPosition(0, 0);
    
    Sprite* sprite2 = Sprite::create("HelloWorld.png");
    sprite2->setAnchorPoint(Point::ZERO);
    sprite2->setPosition(0, 0);
    
    Size size = sprite->getContentSize();
    Size winsize = Director::getInstance()->getWinSize();
    
    BlurNode* node = BlurNode::createWithWH(size.width, size.height, 10);
    addChild(node);
    node->setPosition(600, 100);
    node->addChild(sprite);
    
//    HBlurNode* hNode = HBlurNode::createWithWH(size.width, size.height, 10);
//    addChild(hNode);
//    hNode->setPosition(100, 100);
//    
//    VBlurNode* vNode = VBlurNode::createWithWH(size.width, size.height, 10);
//    hNode->addChild(vNode);
//    //vNode->addChild(sprite);
    
    ShaderNode* shaderNode = ShaderNode::createWithWH(size.width, size.height);
    addChild(shaderNode);
    shaderNode->addChild(sprite2);
    shaderNode->setPosition(100, 100);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
