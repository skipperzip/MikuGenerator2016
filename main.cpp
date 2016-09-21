
#include "main.h"
#include "Splash.h"
#include "Bosses.h"
#include "Pong.h"
//written by Skipperzip
//reuploading
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
	int select = 0;
	sfw::initContext(800, 600, "PONG!");
	//load some textures
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
	unsigned w = sfw::loadTextureMap("./res/waifu.jpg");
	//initiate Splash_Screen.exe
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

	//initiate Exe.menu
	APP_STATE menu = START_TOUHOU;

	APP_STATE state2 = ENTER_PONG;
	bool escape = 0;
	Utsuho utsuho;
	Pong pong;


	while (sfw::stepContext() && !escape)
	{
		bool quit3 = false;
		bool quit2 = false;
		//draw buttons to be pressed
		/*while (sfw::stepContext() && select != 1)
		{
			sfw::drawTexture(w, 0, 600, 800, 600, 0, false, 0, 0x88888888);
			sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);
			sfw::drawString(d, "Pong", 300, 400, 24, 24);
			sfw::drawString(d, "Touhou", 300, 200, 24, 24);
			//on click stuff
	
		}
		*/
		
		
		
		
		
		//take data into switch here
		
		
		switch (menu)

		{
		case START_PONG:
			//initiate Pong.exe
			PlaySound(NULL, 0, 0);



			pong.prepare(w);
			
			while (sfw::stepContext() && !quit2)
			{
				switch (state2)
				{
				case ENTER_PONG:
					pong.prepare(w);
				case PONG:
					pong.draw(f, r, w, u);
					state2 = pong.next();
					break;
				case TERMINATE2:
					quit2 = true;
				}
			}


		case START_TOUHOU:
			//initiate TOUHOU.EXE
			PlaySound(NULL, 0, 0);
			//PlaySound("./res/Nuclear.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

			APP_STATE state3 = ENTER_UTSUHO;

			utsuho.prepare();

		
			while (sfw::stepContext() && !quit3)
			{
				sfw::drawTexture(w, 0, 600, 800, 600, 0, false, 0, 0x88888888);
				sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);
				switch (state3)
				{
				case ENTER_UTSUHO:
					utsuho.prepare();
				case UTSUHO:
					srand((unsigned)time(0));
					utsuho.draw(d, r, w, u);
					state3 = utsuho.next(d);
					break;
				case TERMINATE3: quit3 = true;
				}
			}
		}
		
	}
}



	//written by skipperzip