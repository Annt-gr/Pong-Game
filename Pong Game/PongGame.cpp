#include "PongGame.h"
#include "graphics.h"
#include "config.h"
#include <iostream>
#include "Player.h"
#include "Ball.h"

void PongGame::init()
{
	player1 = new Player();
		
	player2 = new Player();
	//ball = new Ball();
	graphics::setFont(std::string(ASSET_PATH) + "score.ttf");

	graphics::playMusic(std::string(ASSET_PATH) + "themeSong.mp3", 0.2f, true, 0);
}

void PongGame::update()
{

	switch (status) {
	case STATUS_START:
		updateStartScreen();
		break;
	case STATUS_PLAYING:
		updateLevelScreen();
		break;
	case STATUS_FINISH:
		updateFinishScreen();
		break;
	default:
		std::cout << "Not implemented status" << std::endl;

	}

	/*
	if (player1) 
	{
		player1->update();
	}
	
	if (player2) 
	{
		player2->update();
	}


	//checkCollision();
	//checkGoal();
	//CheckActiveBall();
	//SpawnBall();
	CheckActiveBall();
	SpawnBall();
	checkCollision();
	checkGoal();
	if (ball) 
	{
		
		ball->update();
	}


	//checkCollision();
	//checkGoal();
	
	*/

}

void PongGame::draw()
{


	switch (status) {
	case STATUS_START:
		drawStartScreen();
		break;
	case STATUS_PLAYING:
		drawLevelScreen();
		break;
	case STATUS_FINISH:
		drawFinishScreen();
		break;
	default:
		std::cout << "Not implemented status" <<std:: endl;

	}
	/*
	graphics::Brush br;
	char score_c[40];
	sprintf_s(score_c, "%6.0f", player2->getPlayerGoals());
	graphics::drawText(500.0f, 50.0f, 50.0f, score_c, br);

	sprintf_s(score_c, "%6.0f", player1->getPlayerGoals());
	graphics::drawText(400.0f, 50.0f, 50.0f, score_c, br);
	br.texture = std::string(ASSET_PATH) + "table.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	
	player1->draw();
	player2->draw();
	if (ball) {
		ball->draw();
	}
	
	*/
}

void PongGame::updateStartScreen()
{

	if (graphics::getKeyState(graphics::SCANCODE_1)) {
		numBalls = 1;
	}
	if (graphics::getKeyState(graphics::SCANCODE_2)) {
		numBalls = 2;
	}
	if (graphics::getKeyState(graphics::SCANCODE_3)) {
		numBalls = 3;
	}

	if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
		status = STATUS_PLAYING;
	}
}

void PongGame::updateLevelScreen()
{

	if (player1)
	{
		player1->update();
	}

	if (player2)
	{
		player2->update();
	}

	CheckActiveBall();
	SpawnBall();
	checkCollision();
	checkGoal();
	updateBalls();

	if (player1->getPlayerGoals() == 1|| player2->getPlayerGoals() == 1) {
		status = STATUS_FINISH;
	}

}

void PongGame::drawStartScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "init_background.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	graphics::setFont(std::string(ASSET_PATH) + "names2.ttf");
	graphics::Brush bru;
	char info[200];
	sprintf_s(info, "PONG GAME ");
	graphics::drawText(450, 55, 25, info, bru);//g spot
	sprintf_s(info, "Press 1-2-3 for 1-2 or 3 balls ");
	graphics::drawText(350, 350, 25, info, bru);//g spot
	sprintf_s(info, "Player 1 ");
	graphics::drawText(200, 200, 20, info, bru);//g spot
	sprintf_s(info, "You can move your paddle ");
	graphics::drawText(130, 250, 20, info, bru);
	sprintf_s(info, "using W to go up and S to go down");
	graphics::drawText(100, 300, 20, info, bru);
	sprintf_s(info, "Player 2 ");
	graphics::drawText(700, 200, 20, info, bru);//g spot
	sprintf_s(info, "You can move your paddle ");
	graphics::drawText(600, 250, 20, info, bru);
	sprintf_s(info, "using UP to go up and DOWN to go down");
	graphics::drawText(550, 300, 20, info, bru);
	sprintf_s(info, "Press ENTER to start!!");
	graphics::drawText(350, 400, 30, info, bru);
	//sprintf_s(info, "Player 2");
	//graphics::drawText(700, 200, 20, info, bru);
	//graphics::drawText(200, 250, 20, info, bru);
	//sprintf_s(info, "You can move your paddle using  to go up and  to go down");
	//graphics::drawText(700, 250, 20, info, bru);
}

void PongGame::drawLevelScreen()
{
	graphics::setFont(std::string(ASSET_PATH) + "score.ttf");
	graphics::Brush br;
	char score_c[40];
	sprintf_s(score_c, "%6.0f", player2->getPlayerGoals());
	graphics::drawText(500.0f, 50.0f, 50.0f, score_c, br);

	sprintf_s(score_c, "%6.0f", player1->getPlayerGoals());
	graphics::drawText(400.0f, 50.0f, 50.0f, score_c, br);
	br.texture = std::string(ASSET_PATH) + "table.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

		player1->draw();
	player2->draw();
	
	for (Ball* b : balls) {
		b->draw();
	}
}

void PongGame::updateFinishScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_R)) {
		status = STATUS_PLAYING;
		player1->resetPlayerGoals();
		player2->resetPlayerGoals();
	}
	
	//if (graphics::getKeyState(graphics::SCANCODE_ESCAPE)) {
	//	graphics::destroyWindow();
	//}
	
}

void PongGame::drawFinishScreen()
{
	graphics::setFont(std::string(ASSET_PATH) + "names2.ttf");
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "init_background.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	char info[60];
	sprintf_s(info, "PONG GAME ");
	graphics::drawText(450, 65, 25, info, br);//g spot
	sprintf_s(info, "Press R to Play again!!");
	graphics::drawText(350, 400, 30, info, br);

	if (player1->getPlayerGoals() > player2->getPlayerGoals()) {
		sprintf_s(info, "Player 1-won");
		graphics::drawText(200, 200, 25, info, br);
		sprintf_s(info, "Player 2-lost");
		graphics::drawText(650, 200, 25, info, br);
	}
	else {
		sprintf_s(info, "Player 1-lost");
		graphics::drawText(200, 200, 25, info, br);
		sprintf_s(info, "Player 2-won");
		graphics::drawText(650, 200, 25, info, br);
	}
	char score_c[12];
	sprintf_s(score_c, "%6.0f", player1->getPlayerGoals());
	graphics::drawText(250.0f, 250.0f, 25.0f, score_c, br);
	sprintf_s(score_c, "%6.0f", player2->getPlayerGoals());
	graphics::drawText(700.0f, 250.0f, 25.0f, score_c, br);


}

void PongGame::updateBalls()
{
	for (Ball* b : balls)
	{
		b->update();
	}
}

bool PongGame::checkCollision()
{
	if (!player1)
	{
		return false;
	}

	for (Ball* b : balls) {
		Disk d2 = b->getCollisionHull(b->getX(), b->getY());
		
		//Player 1
		for (int i = -25; i <= 25; i = i + 10)
		{
			Disk hull2 = player2->getCollisionHull(player2->getX2(), player2->getY2() + i);
			float dx = hull2.cx - d2.cx;
			float dy = hull2.cy - d2.cy;
			
			if (sqrt(dx * dx + dy * dy) < hull2.radius + d2.radius && !b->isCollided())
			{
				graphics::playSound(std::string(ASSET_PATH) + "ball_hit_.mp3", 0.4f, false);
				b->ChangeOrientationX();
				b->SetCollided(true);
				return true;
			}
		}

		//Player 2
		for (int i = -25; i <= 25; i = i + 10) {
			Disk hull1 = player1->getCollisionHull(player1->getX1(), player1->getY1() + i);
			float dx = hull1.cx - d2.cx;
			float dy = hull1.cy - d2.cy;
			if (sqrt(dx * dx + dy * dy) < hull1.radius + d2.radius && !b->isCollided())
			{
				graphics::playSound(std::string(ASSET_PATH) + "ball_hit_.mp3", 0.4f, false);
				b->ChangeOrientationX();
				b->SetCollided(true);
				return true;
			}
		}

		b->SetCollided(false);
	}
	

	/*
	for (int i = -25; i <= 25; i = i + 10) {
		Disk hull2 = player2->getCollisionHull(player2->getX2(), player1->getY2() + i);
		player2->hulls2.push_back(hull2);
	}

	//Disk d1 = player1->getCollisionHull(player1->getX1(),player1->getY1());
	//Disk d3 = player2->getCollisionHull(player2->getX2(), player2->getY2());
	//Disk d2 = ball->getCollisionHull(ball->getX(),ball->getY());

	for (Disk e : player1 ->hulls ) {
		float dx = e.cx - d2.cx;
		float dy = e.cy - d2.cy;
		if (sqrt(dx * dx + dy * dy) < e.radius + d2.radius)
		{
			return true;
		}
	}
	for (Disk e : player2->hulls2) {
		float dx = e.cx - d2.cx;
		float dy = e.cy - d2.cy;
		if (sqrt(dx * dx + dy * dy) < e.radius + d2.radius)
		{
			return true;
		}
	}
		
	*/
	
	return false;
}

void PongGame::checkGoal()
{
	//left wall
	for (Ball* b : balls) {
		if (b->getX() <= player1->getX1() - 20 && b->isActive())
		{
			graphics::playSound(std::string(ASSET_PATH) + "point.mp3", 0.4f, false);
			ScoreUp(player2);
			//std::cout << "Player 2: " << std::to_string(player2->getPlayerGoals()) << std::endl;
			//reset
			//delete ball;
			//ball = nullptr;
		}

		//right wall 
		if (b->getX() >= player2->getX2() + 20 && b->isActive())
		{
			graphics::playSound(std::string(ASSET_PATH) + "point.mp3", 0.4f, false);

			//graphics::playSound(std::string(ASSET_PATH) + "clap.mp3", 0.4f, false);
			ScoreUp(player1);
			//std::cout << "Player 1: " << std::to_string(player1->getPlayerGoals()) << std::endl;
			//reset
			//delete ball;
			//ball = nullptr;

		}
	}
}

void PongGame::ScoreUp(Player* player)
{
	player-> setPlayerGoals();
}

void PongGame::SpawnBall()
{
	while (balls.size() < numBalls) {
		Ball* b = new Ball();
		std::cout << "Adding new Ball" <<std::endl;
		balls.push_back(b);
	}
	/*
	if (!ball) {
		ball = new Ball();
		ball->SetActive(true);
	}*/
}

void PongGame::CheckActiveBall()
{
	bool activeBallStatus[3];

	for (int i = 0; i < balls.size(); i++) {
		activeBallStatus[i] = balls[i]->isActive();
	}

	for (int i = balls.size() - 1; i >= 0; i--) {
		if (!activeBallStatus[i]) {
			delete balls[i];
			balls.erase(balls.begin() + i);
		}
	}
	/*
	if (ball &&!ball->isActive()) {
		delete ball;
		ball = nullptr;
	}*/
}

PongGame::PongGame()
{

}

PongGame::~PongGame()
{

}
