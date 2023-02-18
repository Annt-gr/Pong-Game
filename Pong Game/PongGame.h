#pragma once
#include "Player.h"
#include "Ball.h"

class PongGame {
	typedef enum { STATUS_START, STATUS_PLAYING, STATUS_FINISH } status_t;

	Player* player1 = nullptr;
	Player* player2 = nullptr;
	Ball* ball = nullptr;
	std::vector<Ball*> balls;

	status_t status = STATUS_START;
	void updateStartScreen();
	void updateLevelScreen();
	void drawStartScreen();
	void drawLevelScreen();
	void updateFinishScreen();
	void drawFinishScreen();
	void updateBalls();
	int numBalls = 1;

public:
	bool checkCollision();
	void checkGoal();
	void ScoreUp(Player* player);
	void SpawnBall();
	void CheckActiveBall();
	PongGame();
	~PongGame();
	void init();
	void update();
	void draw();

};
