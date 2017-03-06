#pragma once
#include "main.h"

class PS
{

public:



	unsigned MikuFont = sfw::loadTextureMap("./res/Miku.png", 16, 6);
	unsigned MikuFont2 = sfw::loadTextureMap("./res/Miku2.png", 16, 6);
	int i = 0;
	float particlesX[50];
	int particlesY[50];
	int Texture[50];
	int TextureUp[50];
	int New = -40;
	// Called on startup
	void prepare();

	// Called on update
	void draw();

	APP_STATE next();
};
