#pragma once
#include <iostream>
#include <math.h>

class Vector2D {
public:
	float x;
	float y;


	Vector2D() {
		x = sqrt(2.0f) * 0.5f;
		y = sqrt(2.0f) * 0.5f;
	}

	Vector2D(float xx, float yy) {
		x = xx; y = yy;
	}

	void normalize() {
		float length = x * x + y * y;
		if (length == 0)
			std::cout << "Kapou ta gamises " << std::endl;
		x /= length;
		y /= length;
	}

	void fromAngle(float a) {
		//Convert angles to rad
		float arad = (3.141592653f * (90.0f + a) / 180.0f);
		x = cosf(arad);
		y = -sinf(arad); //Eisai ilithios
		normalize();
		//std::cout << "Updated Vector " << x << " " << y << std::endl;
	}
};