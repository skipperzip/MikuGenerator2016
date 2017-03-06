
#include "main.h"
#include "Particle.h"
#include "Miku.h"
//written by Skipperzip and Chase

void main()
{
	int select = 0;
	sfw::initContext(1920, 1080, "Miku compliment generator 2016");
	//load some textures
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
	unsigned w = sfw::loadTextureMap("./res/waifu.jpg");
	unsigned p = sfw::loadTextureMap("./res/particle.png");
	//initiate Splash_Screen.exe

	bool quit = false;

	//initiate Exe.menu
	APP_STATE menu = ENTER_MIKU;

	Miku miku;
	//PS PS;


	while (sfw::stepContext())
	{
		bool quit = false;

		//draw buttons to be pressed
		while (sfw::stepContext() && select != 1)
		{
			sfw::drawString(d, "Press M to Miku", 300, 450, 24, 24);
			if (sfw::getKey('M'))
			{
				menu = START_MIKU;
				select = 1;
			}

		}
		select = 0;
		miku.prepare();
		//PS.prepare();


		//take data into switch here
		srand(time(0));

		switch (menu)
		{


		case START_MIKU:
			//initiate TOUHOU.EXE
			PlaySound(NULL, 0, 0);
			//PlaySound("./res/Nuclear.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

			APP_STATE state = ENTER_MIKU;
			while (sfw::stepContext() && !quit)
			{
				switch (state)
				{
				case ENTER_MIKU:
					miku.prepare();
				case MIKU:
					miku.draw(d, r, w, u, p);
					state = miku.next();
					break;
				case TERMINATE: quit = true;
				}
			}
		}

	}

	sfw::termContext();
}



//written by skipperzip