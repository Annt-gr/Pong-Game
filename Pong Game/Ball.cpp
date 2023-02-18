#include "Ball.h"
#include "graphics.h"
#include "config.h"
#include <iostream>\
#include "player.h"

Disk Ball::getCollisionHull(float x, float y) const
{
	Disk disk;
	disk.cx = x;
	disk.cy = y;
	disk.radius = 18.0f;
	return disk;
}
/*
bool Ball::Reset()
{
	delete ball;
	ball = nullptr;
	position_x = CANVAS_WIDTH / 2;
	position_y = CANVAS_HEIGHT / 2;
}
*/
void Ball::update()
{
	if (getX() <= CANVAS_WIDTH / 8 - 20 || getX() >= 7 * (CANVAS_WIDTH) / 8 + 20)
	{
		active = false;
	}
	//pos_x -= sin(ori* M_PI /180)* speed * graphics::getDeltaTime()/10.0f;
	//std::cout << "ori apo update " << ori << std::endl;

	position_x += direction.x * speed * graphics::getDeltaTime() / 10.0f;
	position_y -= direction.y * speed * graphics::getDeltaTime() / 10.0f;
/*
	if (ori >270  && ori <= 360) {
		//std::cout << "ori >270  && ori <= 360" << std::endl;
		//std::cout << "POS_X AND POS_Y " << position_x << " " << position_y << " " << ori << std::endl;

		//position_x += sin(ori * 3.14159265359 / 180) * speed * graphics::getDeltaTime() / 10.0f;
		//position_y -= cos(ori * 3.14159265359 / 180) * speed * graphics::getDeltaTime() / 10.0f;
		position_x += direction.x * speed * graphics::getDeltaTime() / 10.0f;
		position_y -= direction.y* speed * graphics::getDeltaTime() / 10.0f;
	}
	if (ori > 180 && ori <= 270) {
		//std::cout << "ori > 180 && ori <= 270" << std::endl;
		//std::cout << "POS_X AND POS_Y " << position_x << " " << position_y << " " << ori << std::endl;

		//position_x += sin(ori * 3.14159265359 / 180) * speed * graphics::getDeltaTime() / 10.0f;
	//	position_y -= cos(ori * 3.14159265359 / 180) * speed * graphics::getDeltaTime() / 10.0f;

		position_x += direction.x * speed * graphics::getDeltaTime() / 10.0f;
		position_y -= direction.y * speed * graphics::getDeltaTime() / 10.0f;
	}
	if (ori > 90 && ori<=180 ) {
		//std::cout << "ori > 90 && ori<=180" << std::endl;

		//position_x += sin(ori * 3.14159265359 / 180) * speed * graphics::getDeltaTime() / 10.0f;
		//position_y -= cos(ori * 3.14159265359 / 180) * speed * graphics::getDeltaTime() / 10.0f;
		position_x += direction.x * speed * graphics::getDeltaTime() / 10.0f;
		position_y -= direction.y * speed * graphics::getDeltaTime() / 10.0f;
	}
	if (ori <= 90 && ori >=0) {
		//std::cout << "ori <= 90 && ori >=0" << std::endl;

		//position_x += sin(ori * 3.14159265359 / 180) * speed * graphics::getDeltaTime() / 10.0f;
		//position_y -= cos(ori * 3.14159265359 / 180) * speed * graphics::getDeltaTime() / 10.0f;
		position_x += direction.x * speed * graphics::getDeltaTime() / 10.0f;
		position_y -= direction.y * speed * graphics::getDeltaTime() / 10.0f;
	}
	*/
	
	if (position_y > WINDOW_HEIGHT-100 || position_y < 0.0f) {

		ChangeOrientationY();
	}
	
	//position_x -= sin(ori* 3.14159265359 /180) *speed * graphics::getDeltaTime() / 10.0f;
	//position_y -= cos (ori * 3.14159265359/189) *speed * graphics::getDeltaTime() / 10.0f;

}

void Ball::draw()
{

	brush.outline_opacity = 0.0f;
	brush.texture = std::string(ASSET_PATH) + "ball.png";
	brush.fill_opacity = 1.0f;
	graphics::drawRect(position_x, position_y, 40, 50, brush);

	//Disk hull = getCollisionHull(position_x, position_y);
	//brush.outline_opacity = 1.0f;
	//brush.texture = "";
	//brush.fill_color[0] = 0.3f;
	//brush.fill_color[1] = 0.0f;
	//brush.fill_color[2] = 1.3f;
	//brush.fill_opacity = 0.3f;
	//brush.gradient = false;
	//graphics::drawDisk(hull.cx, hull.cy, hull.radius, brush);


}

void Ball::init()
{
	ball_start = rand() % 6 + 1;
	float ori = 133.0f * ball_start;
	direction.fromAngle(ori);
	speed = 3.0f;
}

Ball::Ball()
{
	init();
}

Ball::~Ball()
{

}
