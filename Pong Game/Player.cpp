#include "Player.h"
#include "graphics.h"
#include "config.h"

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_W)) {
		pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S)) {
		pos_y += speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_UP)) {
		thesi_y -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN)) {
		thesi_y += speed * graphics::getDeltaTime() / 10.0f;
	}

	
	if (pos_y - 30 < 0) {
		pos_y = 30;
	}
	if (pos_y + 30 > CANVAS_HEIGHT) {
		pos_y = CANVAS_HEIGHT - 30;
	}


	if (thesi_y - 30 < 0) {
		thesi_y = 30;
	}
	if (thesi_y + 30 > CANVAS_HEIGHT) {
		thesi_y = CANVAS_HEIGHT - 30;
	}
	
	
}

void Player::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	graphics::drawRect(pos_x, pos_y, 10, 60, br);

	graphics::Brush bru;
	br.fill_color[0] = 1.0f;
	graphics::drawRect(thesi_x, thesi_y, 10, 60, bru);

	
	
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = .3f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
/*
		for (int i = -25; i <= 25; i=i+10) {
			Disk hull1= getCollisionHull(pos_x + i, pos_y + i);
			hulls.push_back(hull1);
		}

		for (int i = -25; i <= 25; i=i+10) {
			
			Disk hull2 = getCollisionHull(pos_x + i, pos_y + i);
			hulls.push_back(hull2);
			
		}

		

		//Disk hull = getCollisionHull(thesi_x,pos_y);

		Disk hull01 = getCollisionHull(thesi_x, thesi_y - 25);
		Disk hull02 = getCollisionHull(thesi_x, thesi_y - 15);
		Disk hull00 = getCollisionHull(thesi_x, thesi_y - 5);
		Disk hull03 = getCollisionHull(thesi_x, thesi_y + 5);
		Disk hull04 = getCollisionHull(thesi_x, thesi_y + 15);
		Disk hull05 = getCollisionHull(thesi_x, thesi_y + 25);

		//hulls.push_back(hull);
		Disk hull11 = getCollisionHull(pos_x, pos_y - 25);
		Disk hull12 = getCollisionHull(pos_x, pos_y - 15);
		Disk hull13 = getCollisionHull(pos_x, pos_y - 5);
		Disk hull14 = getCollisionHull(pos_x, pos_y + 5);
		Disk hull15 = getCollisionHull(pos_x, pos_y + 15);
		Disk hull16 = getCollisionHull(pos_x, pos_y + 25);
		
		//Disk hulls[12] = { hull00,hull01,hull02,hull03,hull04,hull05,hull11,hull12,hull13,hull14,hull15,hull16 };

		graphics::drawDisk(hull00.cx, hull00.cy, hull00.radius, br);
		graphics::drawDisk(hull01.cx, hull01.cy, hull01.radius, br);
		graphics::drawDisk(hull02.cx, hull02.cy ,hull02.radius, br);
		graphics::drawDisk(hull03.cx, hull03.cy ,hull03.radius, br);
		graphics::drawDisk(hull04.cx, hull04.cy, hull04.radius, br);
		graphics::drawDisk(hull05.cx, hull05.cy, hull05.radius, br);

		graphics::drawDisk(hull11.cx, hull11.cy  ,hull11.radius, br);
		graphics::drawDisk(hull12.cx, hull12.cy , hull12.radius, br);
		graphics::drawDisk(hull13.cx, hull13.cy , hull13.radius, br);
		graphics::drawDisk(hull14.cx, hull14.cy , hull14.radius, br);
		graphics::drawDisk(hull15.cx, hull15.cy , hull15.radius, br);
		graphics::drawDisk(hull16.cx, hull16.cy , hull16.radius, br);



*/

}


void Player::init()
{
	
}

void Player::setPlayerGoals()
{
	player_goals++;
}

void Player::resetPlayerGoals()
{
	player_goals = 0.0f;
}

float Player::getPlayerGoals()
{
	return player_goals;
}

Player::Player()
{

}

Player::~Player()
{

}
Disk Player::getCollisionHull(float x,float y) const
{
	Disk disk;
	disk.cx = x;
	disk.cy = y;
	disk.radius = 5.0f;
	return disk;
}
