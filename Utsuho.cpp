#include "Bosses.h"


void Utsuho::prepare()

{
	bounceCount = 0;
	diff = 0;
	print = 0;
	//first circle
	ballX = 400;
	ballY = 300;
	moveX = 0;
	moveY = 0;
	playerX = 0;
	distance = 0;
	distancelast = 0;
	Xtrue = 0;
	Ytrue = 0;
	BallHit = 0;

	RandomSet = 0;
	Texture = 0;
	TextureUp = 1;
	NukeTimer = 0;
	distance2 = 0;
	BossX = 400;
	BossY = 300;
	BossX2 = 400;
	BossY2 = 300;
	BossMoveX = 0;
	BossMoveY = 0;
	i = 0;
	while (i != 100)
	{
		bulletsScale[i] = 0;
		bulletTime[i] = 0;
		bulletsX[i] = 0;
		bulletsY[i] = 0;
		++i;
	}
	PlaySound(NULL, 0, 0);
	//PlaySound("./res/Nuclear.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void Utsuho::draw(int d, int r, int w, int u)                                                          //draw stuff
{
	GAMEOVER = 0;
	while (sfw::stepContext() && GAMEOVER != 1) //lol fonts actually work
	{
		if (RandomSet == 0)
		{
			srand((unsigned)time(0));
			RandomSet = 20;
		}
		--RandomSet;
		sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);




		//draw the boss

		if (TextureUp == 1)
		{
			sfw::drawString(BossFont, "b", BossX - 144, BossY + 180, 300, 300);
			sfw::drawString(BossFont, "l", BossX - 146, BossY + 185, 300, 300);
			if (Texture == 15)
			{
				TextureUp = 0;
			}
			++Texture;

		}
		else
		{
			sfw::drawString(BossFont, "c", BossX - 144, BossY + 180, 300, 300);
			sfw::drawString(BossFont, "l", BossX - 146, BossY + 185, 300, 300);
			--Texture;
			if (Texture == 0)
			{
				TextureUp = 1;
			}

		}
		if (distance <= 11)
		{
			BossMoveX = rand() % 14 - 7;
			BossMoveY = rand() % 14 - 7;
		}
		if (distance < 50 && distance > distancelast)
		{
			BossX = BossX + BossMoveX;
			BossY = BossY + BossMoveY;
			BossX2 = BossX;
			BossX2 = BossY;
		}
		else
		{


			// direction
			BossMoveX = (ballX - BossX  + 1) / (distance + 1);
			BossMoveY = (ballY - BossY  + 1) / (distance + 1);

			

			// apply movement
			BossX = BossX + (BossMoveX);
			BossY = BossY + (BossMoveY);

		}

		distancelast = distance;


		i = 0;
		//random bullets lol         this totally works now yay



		while (i != 100)
		{


			if (bulletsScale[i] <= 1) bulletsX[i] = (rand() % 800 + 1);
			if (bulletsScale[i] <= 1) bulletsY[i] = (rand() % 600 + 1);
			if (bulletsScale[i] <= 1 && bulletTime[i] <= 0) bulletTime[i] = (rand() % 400 + 1);

			++i;
		}
		i = 0;

		//loop catcher here
		while (i != 100 && GAMEOVER != 1)
		{
			//insert touhou here lol
			--bulletTime[i];

			if (bulletTime[i] <= 0)
			{
				bulletsScale[i] = bulletsScale[i] + 2;
				if (bulletsScale[i] > 150) bulletsScale[i] = 0;
				sfw::drawString(BossFont, "d", bulletsX[i] - bulletsScale[i] / 2, bulletsY[i] + bulletsScale[i] / 2, bulletsScale[i], bulletsScale[i]);
				//hitchecker
				if (bulletsScale[i] > 120 && bulletsScale[i] < 151)
				{
					distance2 = sqrt((bulletsX[i] - sfw::getMouseX()) * (bulletsX[i] - sfw::getMouseX()) +
						(bulletsY[i] - sfw::getMouseY()) * (bulletsY[i] - sfw::getMouseY()));
					if (distance2 < bulletsScale[i] / 2) GAMEOVER = 1;
				}
			}
			++i;
			// draw player and the ball
		}
		sfw::drawCircle(ballX, ballY, distance, 120, CYAN);
		sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);
		sfw::drawString(d, std::to_string(bounceCount).c_str(), sfw::getMouseX()-15, sfw::getMouseY()+15, 30, 30, '\0');
		if (GAMEOVER == 1) sfw::drawString(d, "You Lost", 300, 300, 24, 24);
		{
			//------------------------------------------------------------------------------------------------------------first ball
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
					if (print == 0) GAMEOVER = 1;
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
			
		}
	}
}
APP_STATE Utsuho::next()
{
	printf("You hit the ball %d times!\n", bounceCount);
	if (GAMEOVER == 1)
	{
		return TERMINATE3;
	}
	return UTSUHO;
}