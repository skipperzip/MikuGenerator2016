#pragma once
#include "sfwdraw.h"
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#pragma comment( lib, "Winmm.lib" )

enum APP_STATE
{
	ENTER_SPLASH, SPLASH, // Intro Screen
	TERMINATE // Leaves
};