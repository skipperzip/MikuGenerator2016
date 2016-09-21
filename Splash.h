#pragma once


#include "main.h"

class Splash
{
	int font;
	float timer;
public:
	// Called on startup
	void init(int a_font);

	// Called on activation
	void play();

	// Called on update
	void draw();
	void step();

	APP_STATE next();
};