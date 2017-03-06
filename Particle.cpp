#include "Particle.h"


void PS::prepare()

{
	New = -300;
	i = 0;
	while (i != 50)
	{
		particlesX[i] = New;
		particlesY[i] = 200;
		Texture[i] = 1;
		TextureUp[i] = 0;
		i++;
		New = New - 500;
	}
	i = 0;

	PlaySound(NULL, 0, 0);
	//PlaySound("./res/Nuclear.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void PS::draw()                                                          //draw stuff
{
	while (sfw::stepContext() && i != 1) //lol fonts actually work
	{
		if (Texture[i] == 1 && TextureUp[i] <= 5) //running 1
		{
			sfw::drawString(MikuFont, "b", particlesX[i], 300, 300, 300);
		}
		if (Texture[i] == 1 && TextureUp[i] >= 6)
		{
			sfw::drawString(MikuFont, "c", particlesX[i], 300, 300, 300);
		}

		particlesX[i] = particlesX[i] + 4;
		if (particlesX[i] > 2000) particlesX[i] = -300;


		if (TextureUp[i] == 10) TextureUp[i] = 0;
		else ++TextureUp[i];
		++i;

	}
	i = 0;
}

APP_STATE PS::next()
{
	return MIKU;
}
