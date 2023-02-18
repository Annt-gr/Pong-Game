#pragma once
#include "util.h"

class Collidable {

public:
	virtual Disk getCollisionHull(float x, float y) const = 0;

};
class GameObject {
	
public:
	virtual void update();
	virtual void draw();
	virtual void init();
	GameObject();
	~GameObject();
};