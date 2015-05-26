#include "HelloWorldScene.h"

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
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	scheduleUpdate();
	schedule(schedule_selector(HelloWorld::addballs), 0.1f);

    return true;
}

void HelloWorld::addballs(float dt)
{
	shootball *ball = shootball::create();
	ball->setPosition(visibleSize / 2);
	addChild(ball);

	balls.pushBack(ball);
}

void HelloWorld::update(float delta)
{
	shootball * b;
	for (int n = 0; n < balls.size();n++)
	{
		b = balls.at(n);
		b->move();

		if ((b->getPositionX() < 0) ||
			(b->getPositionX() > visibleSize.x) ||
			(b->getPositionY() < 0) ||
			(b->getPositionY() > visibleSize.y))
		{
			balls.eraseObject(b);
			removeChild(b);
			n--;
		}
	}
}

