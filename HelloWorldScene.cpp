#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);


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



	//scheduleUpdate();
	//schedule(schedule_selector(HelloWorld::addballs), 0.1f);

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
			(b->getPositionX() > visibleSize.width) ||
			(b->getPositionY() < 0) ||
			(b->getPositionY() > visibleSize.height))
		{
			balls.eraseObject(b);
			removeChild(b);
			n--;
		}
	}
}

void HelloWorld::onEnter()
{
	
	Layer::onEnter();
	addEdges();
	
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch *t,Event *){
		this->addBall(t->getLocation().x, t->getLocation().y);
		return false;
	};

	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::addEdges()
{
	auto body = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,3);
	auto edgeShape = Node::create();
	edgeShape->setPhysicsBody(body);
	edgeShape->setPosition(visibleSize.width/2,visibleSize.height/2);
	addChild(edgeShape);
}

void HelloWorld::addBall(float positionX, float positionY)
{
	auto ball = PhysicsBody::createCircle(20);
	auto ballShape = Node::create();
	ballShape->setPhysicsBody(ball);
	ballShape->setPosition(ccp(positionX,positionY));
	addChild(ballShape);
}

