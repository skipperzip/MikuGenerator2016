
#include "main.h"
#include "Splash.h"
//reuploading again
//written by Skipperzip
/*
class Circle
{
public:
	float ballX = 400;
	float ballY = 300;
	float moveX = 0;
	float moveY = 0;
	float playerX = 0;
	float distance = 0;
	int Xtrue = 0;
	int Ytrue = 0;
	int BallHit = 0;
	
};

//this is laggy for seemingly no reason

void main()
{

	Circle circle[3];

	
	const int C_COUNT = 3;
	//name
	sfw::initContext(800, 600, "PONG!");
	//load some textures
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	//unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
	//unsigned w = sfw::loadTextureMap("./res/waifu.jpg");
	//play some music
	int Choice = 1;
	if (Choice == 1) PlaySound("theme1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if (Choice == 2) PlaySound("theme2.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if (Choice == 3) PlaySound("theme3.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else PlaySound("theme1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);


	//set variables


	int bounceCount = 0;
	float diff = 0;
	int print = 0;


	int i = 0;

	i = i - 1;
//check if in hitbox
	while (sfw::stepContext())
	
	{
		i = i + 1;


		//don't do the second or third ball until later
		if (bounceCount >= 10 && bounceCount < 15 && print != 1)
		{
			sfw::drawString(d, "SECOND BALL INCOMING", 200, 300, 24, 24);
		}
		else if (bounceCount >= 30 && bounceCount < 35 && print != 1)
		{
			sfw::drawString(d, "THIRD BALL INCOMING", 200, 300, 24, 24);
		}
		if (bounceCount <= 15 && i == 1)
		{
			i = 0;
		}
		else if (bounceCount <= 35 && i == 2)
		{
			i = 0;
		}

		//draw stuff
		//sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);
		//sfw::drawTexture(w, 0, 600, 800, 600, 0, false, 0, 0x88888888);

		sfw::drawCircle(circle[0].ballX, circle[0].ballY, circle[0].distance, 5, CYAN);
		sfw::drawCircle(circle[1].ballX, circle[1].ballY, circle[1].distance, 5, CYAN);
		sfw::drawCircle(circle[2].ballX, circle[2].ballY, circle[2].distance, 5, CYAN);
		sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);

		//check hitbox
		if (sfw::getMouseX() >= (circle[i].ballX - circle[i].distance) && sfw::getMouseX() <= circle[i].ballX + circle[i].distance)
			circle[i].Xtrue = 1;
		else circle[i].Xtrue = 0;


		if (sfw::getMouseY() >= circle[i].ballY - circle[i].distance && sfw::getMouseY() <= circle[i].ballY + circle[i].distance)
			circle[i].Ytrue = 1;
		else circle[i].Ytrue = 0;
		//check if in zone


		if (circle[i].ballX <= 200 - circle[i].distance * 4 && circle[i].moveX <= 0) circle[i].moveX = circle[i].moveX - (2 * circle[i].moveX);
		if (circle[i].ballX >= 600 + circle[i].distance * 4 && circle[i].moveX >= 0) circle[i].moveX = circle[i].moveX - (2 * circle[i].moveX);
		if (circle[i].ballY <= 50 - circle[i].distance && circle[i].moveY <= 0) circle[i].moveY = circle[i].moveY - (2 * circle[i].moveY);
		if (circle[i].ballY >= 550 + circle[i].distance && circle[i].moveY >= 0) circle[i].moveY = circle[i].moveY - (2 * circle[i].moveY);


		//back
		if (circle[i].BallHit == 0)
		{

			if (circle[i].distance <= 50) circle[i].distance += sfw::getDeltaTime() * 10 + diff / 10;
			else
			{
				sfw::drawString(d, "You Lost", 300, 300, 24, 24);
				circle[i].distance += sfw::getDeltaTime() * 240;
				if (print == 0) printf("you hit the ball %d time(s)", bounceCount);
				print = 1;
			}

			circle[i].ballX = circle[i].ballX + circle[i].moveX;
			circle[i].ballY = circle[i].ballY + circle[i].moveY;
		}
		//and forth
		else if (circle[i].BallHit == 1)
		{
			if (circle[i].distance >= 10) circle[i].distance -= sfw::getDeltaTime() * 10 + diff / 10;
			else circle[i].BallHit = 0;

			circle[i].ballX = circle[i].ballX + circle[i].moveX;
			circle[i].ballY = circle[i].ballY + circle[i].moveY;
		}


		//hitchecking
		if (circle[i].distance > 30 && circle[i].distance < 50 && circle[i].BallHit != 1)
		{
			sfw::drawString(d, "!", circle[i].ballX - circle[i].distance / 2, circle[i].ballY + circle[i].distance / 2, circle[i].distance, circle[i].distance);
			if (circle[i].Xtrue == 1 && circle[i].Ytrue == 1)
			{
				circle[i].BallHit = 1;
				circle[i].moveX = circle[i].ballX - sfw::getMouseX();
				circle[i].moveY = circle[i].ballY - sfw::getMouseY();
				circle[i].moveX = circle[i].moveX / 20;
				circle[i].moveY = circle[i].moveY / 20;
				bounceCount = bounceCount + 1;
			}
		}
		//draw texture and circle

	}

	sfw::termContext();
	//written by skipperzip
}


	*/	
	//name
void main()
{
	sfw::initContext(800, 600, "PONG!");
	//load some textures
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
	unsigned w = sfw::loadTextureMap("./res/waifu.jpg");
	Splash splash;
	splash.init(f);
	APP_STATE state = ENTER_SPLASH;

	bool quit = false;
	while (sfw::stepContext() && !quit)
	{
		sfw::drawTexture(w, 0, 600, 800, 600, 0, false, 0, 0x88888888);
		sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);
		switch (state)
		{
		case ENTER_SPLASH:
				splash.play();
		case SPLASH:
				splash.step();
				splash.draw();
				state = splash.next();
				break;
		case TERMINATE: quit = true;
		}
	}

	/*

	sfw::drawTexture(w, 0, 600, 800, 600, 0, false, 0, 0x88888888);
	//play some music
	int Choice = 1;
	if (Choice == 1) PlaySound("theme1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if (Choice == 2) PlaySound("theme2.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else if (Choice == 3) PlaySound("theme3.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	else PlaySound("theme1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
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
	//spike1
	float SpikeX = 0;
	float SpikeY = 300;
	
	int SpikeTrueX = 0;
	int SpikeTrueY = 0;

	int Spike = 0;
	//spike2
	float SpikeX2 = 800;
	float SpikeY2 = 300;

	int SpikeTrueX2 = 0;
	int SpikeTrueY2 = 0;

	int Spike2 = 0;
	
	//the loop!
	while (sfw::stepContext() && bounceCount != 100)
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
		//Spike 1
		if (sfw::getMouseX() >= SpikeX - 25 && sfw::getMouseX() <= SpikeX + 25) SpikeTrueX = 1;
		else SpikeTrueX = 0;
		if (sfw::getMouseY() >= SpikeY - 25 && sfw::getMouseY() <= SpikeY + 25) SpikeTrueY = 1;
		else SpikeTrueY = 0;

		if (sfw::getMouseX() > SpikeX) SpikeX = SpikeX + 2;
		else if (sfw::getMouseX() < SpikeX) SpikeX = SpikeX - 2;
		else SpikeX = SpikeX;
		if (sfw::getMouseY() > SpikeY) SpikeY = SpikeY + 2;
		else if (sfw::getMouseY() < SpikeY) SpikeY = SpikeY - 2;
		else SpikeY = SpikeY;

		if (SpikeTrueX == 1 && SpikeTrueY == 1)
		{
			sfw::drawString(d, "X", SpikeX - 25 / 2, SpikeY + 25 / 2, 25, 25);
			sfw::drawString(d, "You Lost", 300, 300, 24, 24);

			if (print == 0) printf("you hit the ball %d time(s)", bounceCount);
			print = 1;
			Spike = 1;
		}
		if (Spike == 1)
		{
			sfw::drawString(d, "!", SpikeX - 25 / 2, SpikeY + 25 / 2, 25, 25);
			sfw::drawString(d, "You Lost", 300, 300, 24, 24);
		}
		//Spike 2
		if (sfw::getMouseX() >= SpikeX2 - 25 && sfw::getMouseX() <= SpikeX2 + 25) SpikeTrueX2 = 1;
		else SpikeTrueX2 = 0;
		if (sfw::getMouseY() >= SpikeY - 25 && sfw::getMouseY() <= SpikeY + 25) SpikeTrueY2 = 1;
		else SpikeTrueY2 = 0;

		if (sfw::getMouseX() > SpikeX2) SpikeX2 = SpikeX2 + 2;
		else if (sfw::getMouseX() < SpikeX2) SpikeX2 = SpikeX2 - 2;
		else SpikeX2 = SpikeX2;
		if (sfw::getMouseY() > SpikeY2) SpikeY2 = SpikeY2 + 2;
		else if (sfw::getMouseY() < SpikeY2) SpikeY2 = SpikeY2 - 2;
		else SpikeY2 = SpikeY2;

		if (SpikeTrueX2 == 1 && SpikeTrueY2 == 1)
		{
			sfw::drawString(d, "X", SpikeX2 - 25 / 2, SpikeY2 + 25 / 2, 25, 25);
			sfw::drawString(d, "You Lost", 300, 300, 24, 24);

			if (print == 0) printf("you hit the ball %d time(s)", bounceCount);
			print = 1;
			Spike2 = 1;
		}
		if (Spike2 == 1)
		{
			sfw::drawString(d, "!", SpikeX2 - 25 / 2, SpikeY2 + 25 / 2, 25, 25);
			sfw::drawString(d, "You Lost", 300, 300, 24, 24);
		}
		//draw texture and circle

		sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);
		sfw::drawTexture(w, 0, 600, 800, 600, 0, false, 0, 0x88888888);

		sfw::drawCircle(ballX, ballY, distance, 120, CYAN);
		sfw::drawCircle(ballX2, ballY2, distance2, 120, CYAN);
		sfw::drawCircle(ballX3, ballY3, distance3, 120, CYAN);
		sfw::drawCircle(SpikeX, SpikeY, 25, 120, RED);
		sfw::drawCircle(SpikeX2, SpikeY2, 25, 120, RED);


		sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);
	}
	*/
	//initiate TOUHOU.EXE
	unsigned BossFont = sfw::loadTextureMap("./res/Boss.png", 16, 6);


	int Texture = 0;
	int TextureUp = 1;
	int NukeTimer = 0;
	float BossX = 400;
	float BossY = 300;

	PlaySound(NULL, 0, 0);
	PlaySound("./res/Nuclear.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);


	while (sfw::stepContext()) //lol fonts actually work
	{
		sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);


		if (NukeTimer >= 300 && NukeTimer <= 450)
		{
			if (NukeTimer <= 390)
			{
				sfw::drawString(BossFont, "b", BossX - 125, BossY + 200, 300, 400);
			}
			if (NukeTimer > 390)
			{
				sfw::drawString(BossFont, "c", BossX - 125, BossY + 200, 300, 400);
				--NukeTimer;
			}
			++NukeTimer;
		}
		else if (TextureUp == 1)
		{
			sfw::drawString(BossFont, "`", BossX - 125, BossY + 200, 300, 400);
			if (Texture == 15) 
			{ 
				TextureUp = 0; 
			}
			++Texture;
			++NukeTimer;
		}
		else
		{
			sfw::drawString(BossFont, "a", BossX - 125, BossY + 200, 300, 400);
			--Texture;
			if (Texture == 0)
			{
				TextureUp = 1;
			}
		}
		sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);



		//INSERT BULLLET HELL HERE LOL
	}




	sfw::termContext();
	}


	//written by skipperzip