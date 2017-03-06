#pragma once
#include "main.h"

class Miku
{

public:



	unsigned MikuFont;


	int Texture = 0;
	int TextureUp = 1;
	int Emotion = 0;
	int timer = 10;
	int compliment = 0;
	float random = 0;
	float random2 = 0;
	float random3 = 0;
	float randomcompliment;
	float MikuX = 400;
	float MikuY = 300;
	float MikuX2 = 400;
	float MikuY2 = 300;
	float MikuMoveX = 0;
	float MikuMoveY = 0;
	int test = 0;
	int quit = 1;
	int i = 0;
	int music = 1;
	float pX[3];
	float pY[3];
	float pR[3];

	Miku()
	{
		MikuFont = sfw::loadTextureMap("./res/Miku.png", 16, 6);

	}


	float ObjectPoolX[25];
	// Called on startup
	void prepare();

	// Called on update
	void draw(int d, int r, int w, int u, int p);

	APP_STATE next();
};
