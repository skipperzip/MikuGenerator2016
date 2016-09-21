#pragma once
#include "main.h"

class Pong
{

public:	
							//set variables
	int bounceCount = 0;
	float diff = 0;
	int print = 0;
	//first circle
	float ballX = 400;
	float ballY = 300;
	float moveX = 0;
	float moveY = 0;
	float playerX = 0;
	float distance = 0;
	int Xtrue = 0;
	int Ytrue = 0;
	int BallHit = 0;
	//second circle
	float ballX2 = 400;
	float ballY2 = 300;
	float moveX2 = 0;
	float moveY2 = 0;
	int Xtrue2 = 0;
	int Ytrue2 = 0;
	float distance2 = 0;
	int BallHit2 = 0;
	//third circle
	float ballX3 = 400;
	float ballY3 = 300;
	float moveX3 = 0;
	float moveY3 = 0;
	int Xtrue3 = 0;
	int Ytrue3 = 0;
	float distance3 = 0;
	int BallHit3 = 0;

							//Not variables now
	// Called on startup
	void prepare(int w);

	// Called on update
	void draw(int d, int r, int w, int u);

	APP_STATE next();
};
