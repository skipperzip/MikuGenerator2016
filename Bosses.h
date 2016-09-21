#pragma once
#include "main.h"

class Utsuho
{

public:


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
	float distancelast = 0;
	int Xtrue = 0;
	int Ytrue = 0;
	int BallHit = 0;


	unsigned BossFont = sfw::loadTextureMap("./res/Boss.png", 16, 6);

	int RandomSet = 0;
	int Texture = 0;
	int TextureUp = 1;
	int NukeTimer = 0;
	float distance2 = 0;
	float BossX = 400;
	float BossY = 300;
	float BossX2 = 400;
	float BossY2 = 300;
	float BossMoveX = 0;
	float BossMoveY = 0;
	int i = 0;
	int bulletsX[100];
	int bulletsY[100];
	int bulletsScale[100];
	int bulletTime[100];
	int MouseX = 0;
	int MouseY = 0;
	int GAMEOVER = 0;

	// Called on startup
	void prepare();

	// Called on update
	void draw(int d, int r, int w, int u);

	APP_STATE next();
};