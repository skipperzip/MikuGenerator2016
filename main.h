#pragma once
#include "sfwdraw.h"
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#pragma comment( lib, "Winmm.lib" )

enum APP_STATE
{
	ENTER_MENU, START_PONG, START_TOUHOU,

	ENTER_SPLASH, SPLASH, 
	
	ENTER_PONG, PONG,

	ENTER_UTSUHO, UTSUHO,

	TERMINATE, TERMINATE2, TERMINATE3
};