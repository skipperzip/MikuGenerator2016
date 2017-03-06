#pragma once
#include "sfwdraw.h"
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#pragma comment( lib, "Winmm.lib" )

enum APP_STATE
{
	ENTER_MENU, START_MIKU,

	ENTER_SPLASH, SPLASH, 
	
	ENTER_MIKU, MIKU, UTSUHO, PONG,

	PARTICLE,

	TERMINATE
};