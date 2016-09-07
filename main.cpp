
#include "sfwdraw.h"
#include "main.h"
#include "iostream"
#include <Windows.h>
//written by Skipperzip
void main()
{
	//name
	sfw::initContext(800, 600, "PONG!");
	//load some textures
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
	unsigned w = sfw::loadTextureMap("./res/waifu.jpg");
	//play some music
	int Choice = 1;
	if (Choice == 1) PlaySound("theme1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if (Choice == 2) PlaySound("theme2.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if (Choice == 3) PlaySound("theme3.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else PlaySound("theme1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//set variables

	float ballX = 400;
	float ballY = 300;
	float moveX = 0;
	float moveY = 0;
	float playerX = 0;
	float distance = 0;
	int Xtrue = 0;
	int Ytrue = 0;
	int BallHit = 0;
	char c = '\0';
	int bounceCount = 0;
	float diff = 0;
	int print = 0;
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

	


	//the loop!
	while (sfw::stepContext())
	{	

		if (bounceCount < 10) diff = bounceCount / 2;
		//check if in hitbox
		if (sfw::getMouseX() >= ballX - distance && sfw::getMouseX() <= ballX + distance) Xtrue = 1;
		else Xtrue = 0;
		if (sfw::getMouseY() >= ballY - distance && sfw::getMouseY() <= ballY + distance) Ytrue = 1;
		else Ytrue = 0;
		//check if in zone
		if (ballX <= 200 - distance * 4 && moveX <= 0) moveX = moveX - (2 * moveX);
		if (ballX >= 600 + distance * 4 && moveX >= 0) moveX = moveX - (2 * moveX);
		if (ballY <= 50 - distance && moveY <= 0) moveY = moveY - (2 * moveY);
		if (ballY >= 550 + distance && moveY >= 0) moveY = moveY - (2 * moveY);
		//back
		if (BallHit == 0)
		{
			
			if (distance <= 50) distance += sfw::getDeltaTime() * 10 + diff / 10;

			else
			{
				sfw::drawString(d, "You Lost", 300, 300, 24, 24);
				distance += sfw::getDeltaTime() * 240;
				if (print == 0) printf("you hit the ball %d time(s)", bounceCount);
				print = 1;
			}
			ballX = ballX + moveX;
			ballY = ballY + moveY;
		}
		//and forth
		else if (BallHit == 1)
		{
			if (distance >= 10) distance -= sfw::getDeltaTime() * 10 + diff / 10;
			else BallHit = 0;
			ballX = ballX + moveX;
			ballY = ballY + moveY;
		}
		//hitchecking
		if (distance > 30 && distance < 50 && BallHit != 1)
		{
			sfw::drawString(d, "!", ballX - distance / 2, ballY + distance / 2, distance, distance);
			if (Xtrue == 1 && Ytrue == 1)
			{
				BallHit = 1;
				moveX = ballX - sfw::getMouseX();
				moveY = ballY - sfw::getMouseY();
				moveX = moveX / 20;
				moveY = moveY / 20;
				bounceCount = bounceCount + 1;
			}
		}

		//------------------------------------------------------------------------------------------------------------second ball
		if (bounceCount >= 10 && bounceCount < 15 && print != 1) sfw::drawString(d, "SECOND BALL INCOMING", 200, 300, 24, 24);
		if (bounceCount >= 15) 
		{
			
			//check if in hitbox
			if (sfw::getMouseX() >= ballX2 - distance2 && sfw::getMouseX() <= ballX2 + distance2) Xtrue2 = 1;
			else Xtrue2 = 0;
			if (sfw::getMouseY() >= ballY2 - distance2 && sfw::getMouseY() <= ballY2 + distance2) Ytrue2 = 1;
			else Ytrue2 = 0;
			//check if in zone
			if (ballX2 <= 200 - distance2 * 4 && moveX2 <= 0) moveX2 = moveX2 - (2 * moveX2);
			if (ballX2 >= 600 + distance2 * 4 && moveX2 >= 0) moveX2 = moveX2 - (2 * moveX2);
			if (ballY2 <= 50 - distance2 && moveY2 <= 0) moveY2 = moveY2 - (2 * moveY2);
			if (ballY2 >= 550 + distance2 && moveY2 >= 0) moveY2 = moveY2 - (2 * moveY2);
			//back
			if (BallHit2 == 0)
			{

				if (distance2 <= 50) distance2 += sfw::getDeltaTime() * 10 + diff / 10;

				else
				{
					sfw::drawString(d, "You Lost", 300, 300, 24, 24);
					distance2 += sfw::getDeltaTime() * 240;
					if (print == 0) printf("you hit the ball %d time(s)", bounceCount);
					print = 1;
				}
				ballX2 = ballX2 + moveX2;
				ballY2 = ballY2 + moveY2;
			}
			//and forth
			else if (BallHit2 == 1)
			{
				if (distance2 >= 10) distance2 -= sfw::getDeltaTime() * 10 + diff / 10;
				else BallHit2 = 0;
				ballX2 = ballX2 + moveX2;
				ballY2 = ballY2 + moveY2;
			}
			//hitchecking
			if (distance2 > 30 && distance2 < 50 && BallHit2 != 1)
			{
				sfw::drawString(d, "!", ballX2 - distance2 / 2, ballY2 + distance2 / 2, distance2, distance2);
				if (Xtrue2 == 1 && Ytrue2 == 1)
				{
					BallHit2 = 1;
					moveX2 = ballX2 - sfw::getMouseX();
					moveY2 = ballY2 - sfw::getMouseY();
					moveX2 = moveX2 / 20;
					moveY2 = moveY2 / 20;
					bounceCount = bounceCount + 1;
				}
			}
		}
//------------------------------------------------------------------------------------------------------------third ball
		if (bounceCount >= 30 && bounceCount < 35 && print != 1) sfw::drawString(d, "THIRD BALL INCOMING", 200, 300, 24, 24);
		if (bounceCount >= 35)
		{
			
			//check if in hitbox
			if (sfw::getMouseX() >= ballX3 - distance3 && sfw::getMouseX() <= ballX3 + distance3) Xtrue3 = 1;
			else Xtrue3 = 0;
			if (sfw::getMouseY() >= ballY3 - distance3 && sfw::getMouseY() <= ballY3 + distance3) Ytrue3 = 1;
			else Ytrue3 = 0;
			//check if in zone
			if (ballX3 <= 200 - distance3 * 4 && moveX3 <= 0) moveX3 = moveX3 - (2 * moveX3);
			if (ballX3 >= 600 + distance3 * 4 && moveX3 >= 0) moveX3 = moveX3 - (2 * moveX3);
			if (ballY3 <= 50 - distance3 && moveY3 <= 0) moveY3 = moveY3 - (2 * moveY3);
			if (ballY3 >= 550 + distance3 && moveY3 >= 0) moveY3 = moveY3 - (2 * moveY3);
			//back
			if (BallHit3 == 0)
			{

				if (distance3 <= 50) distance3 += sfw::getDeltaTime() * 10 + diff / 10;

				else
				{
					sfw::drawString(d, "You Lost", 300, 300, 24, 24);
					distance3 += sfw::getDeltaTime() * 240;
					if (print == 0) printf("you hit the ball %d time(s)", bounceCount);
					print = 1;
				}
				ballX3 = ballX3 + moveX3;
				ballY3 = ballY3 + moveY3;
			}
			//and forth
			else if (BallHit3 == 1)
			{
				if (distance3 >= 10) distance3 -= sfw::getDeltaTime() * 10 + diff / 10;
				else BallHit3 = 0;
				ballX3 = ballX3 + moveX3;
				ballY3 = ballY3 + moveY3;
			}
			//hitchecking
			if (distance3 > 30 && distance3 < 50 && BallHit3 != 1)
			{
				sfw::drawString(d, "!", ballX3 - distance3 / 2, ballY3 + distance3 / 2, distance3, distance3);
				if (Xtrue3 == 1 && Ytrue3 == 1)
				{
					BallHit3 = 1;
					moveX3 = ballX3 - sfw::getMouseX();
					moveY3 = ballY3 - sfw::getMouseY();
					moveX3 = moveX3 / 20;
					moveY3 = moveY3 / 20;
					bounceCount = bounceCount + 1;
				}
			}
		}


		//draw texture and circle
		
		sfw::drawTexture(r, 0, 600, 800, 600, 0, false,0, 0x88888888);
		sfw::drawTexture(w, 0, 600, 800, 600, 0, false, 0, 0x88888888);

		sfw::drawCircle(ballX, ballY, distance, 120, CYAN);
		sfw::drawCircle(ballX2, ballY2, distance2, 120, CYAN);
		sfw::drawCircle(ballX3, ballY3, distance3, 120, CYAN);

		sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2, sfw::getTextureHeight(u)/2);
	}

	sfw::termContext();
}