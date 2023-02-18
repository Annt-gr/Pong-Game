#pragma once
#include "GameObject.h"
#include "config.h"
#include "graphics.h"
#include <iostream>
#include "Vector.h"
#include "util.h"
#include <random>

class Ball : public GameObject, public Collidable {

	Vector2D direction = Vector2D(0.0f, -1.0f);
	float ball_start;
	float position_x = CANVAS_WIDTH / 2;
	float position_y = CANVAS_HEIGHT / 2;
	float size;
	float speed = 3.0f;
	bool active=true;
	bool collided = false;
	graphics::Brush brush;
public:
	Disk getCollisionHull(float x, float y) const override;
	float getX() { return position_x; }
	float getY() { return position_y; }
	bool isActive() { return active; }
	bool isCollided() { return collided; }
	void SetActive(bool a) { active = a; }
	void SetCollided(bool a) { collided = a; }

	
	void ChangeOrientationX() {
		direction.x *= -1.0f;
	}

	void ChangeOrientationY() {
		direction.y *= -1.0f;
	}
	
	/*
	void ChangeOriRight() { 
		//std::cout << ori << std::endl;
		//return ori;
		//ori =180-(90-ori);
		ori =180-( 270-ori);

		//std::cout << ori << std::endl;
	}
	void ChangeOriLeft() {
		ori = 180 - (90 - ori);
		//ori =180-( 270-ori);
	}
	*/

	//bool Reset();

	void update() override;
	void draw() override;
	void init() override;
	Ball();
	~Ball();
};