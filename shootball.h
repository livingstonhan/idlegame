#ifndef SHOOTBALL
#define SHOOTBALL

#include <cocos2d.h>

USING_NS_CC;

class shootball: public Sprite
{
public:

	virtual bool init(){
		speedx = rand_0_1() * 10 - 5;
		speedy = rand_0_1() * 10 - 5;
		Sprite::initWithFile("CloseSelected.png");
		return true;
	}

	void move(){
		setPositionX(getPositionX() + speedx);
		setPositionY(getPositionY() + speedy);
	}

	CREATE_FUNC(shootball);

private:
	float speedx, speedy;
};


#endif