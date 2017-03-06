#include "Miku.h"
#include "main.h"


void Miku::prepare()

{
	Texture = 0;
	TextureUp = 0;
	MikuX = 400;
	MikuY = 300;
	MikuX2 = 400;
	MikuY2 = 300;
	MikuMoveX = 0;
	MikuMoveY = 0;
	Emotion = 0;
	random = (rand() % 1920 + 1);
	timer = 15;
	compliment = 1000;
	random3 = (rand() % 50 + 1);
	music = (rand() % 7 + 1);
	test = 0;
	quit = 0;

	while (i != 3)
	{
		pX[i] = random;
		pY[i] = random3 * i * (50 - random3);
		pR[i] = random3 * random3 * i;
		++i;
		random = (rand() % 1920 + 1);
	}
	i = 0;
	while (i != 25)
	{
		ObjectPoolX[i] = -5000;
		++i;
	}
	i = 0;
	
	
	if (music == 1) PlaySound("./res/LOL.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	if (music == 2) PlaySound("./res/ben.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	if (music == 3) PlaySound("./res/aot.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	if (music == 4) PlaySound("./res/doot.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	if (music == 5) PlaySound("./res/HEY.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	if (music == 6) PlaySound("./res/nya.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	if (music == 7) PlaySound("./res/pon.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void Miku::draw(int d, int r, int w, int u, int p)                                                          //draw stuff
{
	while (sfw::stepContext() && quit != 1) //lol fonts actually work
	{


		// PARTICLE SYSTEM

		while (i != 3)
		{
			if (compliment >= 1000)
			{
				pR[i] = pR[i] + 2;
			}
			else pR[i] = pR[i] + 1;
			sfw::drawTexture(p, pX[i], pY[i], 2000, 2000, pR[i]);
			++i;
		}
		i = 0;

		//make miku change texture
		if (Texture == 0 && TextureUp == 0) //standing 0
		{
			sfw::drawString(MikuFont, "`", MikuX, MikuY, 300, 300);
		}
		if (Texture == 0 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "a", MikuX-1.5, MikuY+1.5, 300, 300);
		}

		if (Texture == 0 && TextureUp == 2) //happy standing 0
		{
			sfw::drawString(MikuFont, "x", MikuX, MikuY, 300, 300);
		}
		if (Texture == 1 && TextureUp == 0) //running 1
		{
			sfw::drawString(MikuFont, "b", MikuX, MikuY, 300, 300);
		}
		if (Texture == 1 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "c", MikuX, MikuY, 300, 300);
		}
		if (Texture == 2 && TextureUp == 0) //jump 2
		{
			sfw::drawString(MikuFont, "d", MikuX, MikuY, 300, 300);
		}
		if (Texture == 2 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "e", MikuX, MikuY, 300, 300);
		}
		if (Texture == 2 && TextureUp == 2)
		{
			sfw::drawString(MikuFont, "f", MikuX, MikuY, 300, 300);
		}
		if (Texture == 3 && TextureUp == 0) //Mario jump 3
		{
			sfw::drawString(MikuFont, "g", MikuX, MikuY, 300, 300);
		}
		if (Texture == 3 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "h", MikuX, MikuY, 300, 300);
		}
		if (Texture == 4 && TextureUp == 0) //annoyed 4
		{
			sfw::drawString(MikuFont, "i", MikuX, MikuY, 300, 300);
		}
		if (Texture == 4 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "j", MikuX, MikuY, 300, 300);
		}
		if (Texture == 5 && TextureUp == 0) //sad 5
		{
			sfw::drawString(MikuFont, "k", MikuX, MikuY, 300, 300);
		}
		if (Texture == 5 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "l", MikuX, MikuY, 300, 300);
		}
		if (Texture == 5 && TextureUp == 2)
		{
			sfw::drawString(MikuFont, "m", MikuX, MikuY, 300, 300);
		}
		if (Texture == 6 && TextureUp == 0) //dead lol 6
		{
			sfw::drawString(MikuFont, "n", MikuX, MikuY, 300, 300);
		}
		if (Texture == 7 && TextureUp == 0) //cheering 7
		{
			sfw::drawString(MikuFont, "o", MikuX, MikuY, 300, 300);
		}
		if (Texture == 7 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "p", MikuX, MikuY, 300, 300);
		}
		if (Texture == 8 && TextureUp == 0) //staring into the abyss 8
		{
			sfw::drawString(MikuFont, "q", MikuX, MikuY, 300, 300);
		}
		if (Texture == 8 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "r", MikuX, MikuY, 300, 300);
		}
		if (Texture == 9 && TextureUp == 0) //falling over 9
		{
			sfw::drawString(MikuFont, "s", MikuX, MikuY, 300, 300);
		}
		if (Texture == 9 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "t", MikuX, MikuY, 300, 300);
		}
		if (Texture == 9 && TextureUp == 2)
		{
			sfw::drawString(MikuFont, "u", MikuX, MikuY, 300, 300);
		}
		if (Texture == 10 && TextureUp == 0) //mining 10
		{
			sfw::drawString(MikuFont, "v", MikuX, MikuY, 300, 300);
		}
		if (Texture == 10 && TextureUp == 1)
		{
			sfw::drawString(MikuFont, "w", MikuX, MikuY, 300, 300);
		}

		if (Emotion != 0)
		{
			if (sfw::getKey('A'))
			{
				Emotion = 1;
			}
			if (sfw::getKey('C'))
			{
				Emotion = 2;
			}
			if (sfw::getKey('N'))
			{
				Emotion = 3;
			}
			else
			{
				Emotion = 0;
			}
		}

		//"emotions"


		if (Emotion == 0)
		{

			Texture = 0;
			if (TextureUp == 1)
			{
				--timer;
				if (timer == 0)
				{
					timer = 15;
					TextureUp = 0;
				}
			}

			if (TextureUp != 1 && random == 150)
			{
				if (random2 == 1)
				{
					random = 120;
					random2 = 0;
				}
				TextureUp = 1;

			}
			if (random != 150)
			{
				++random;
			}
			else
			{
				random = (rand() % 90);
				random2 = (rand() % 10);
			}

		}




		++compliment;
		
//  _____   __  __   _____     ____    _____    _______              _   _   _______   
// |_   _| |  \/  | |  __ \   / __ \  |  __ \  |__   __|     /\     | \ | | |__   __|  
//   | |   | \  / | | |__) | | |  | | | |__) |    | |       /  \    |  \| |    | |     
//   | |   | |\/| | |  ___/  | |  | | |  _  /     | |      / /\ \   | . ` |    | |     
//  _| |_  | |  | | | |      | |__| | | | \ \     | |     / ____ \  | |\  |    | |     
// |_____| |_|  |_| |_|       \____/  |_|  \_\    |_|    /_/    \_\ |_| \_|    |_|    

//                         Made with permission from Arturo.

		if (compliment >= 1000)
		{
			//                                                                                                              |
			if (random3 == 1) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 2) sfw::drawString(d, "Arturo is a conspicuously well-mannered fellow and a nice guy.", 140, 1000, 24, 24);
			if (random3 == 3) sfw::drawString(d, "Arturo is an unutterably behaved rapscallion and a great chromosome \n		       	indeficient display of decency.", 140, 1000, 24, 24);
			if (random3 == 4) sfw::drawString(d, "Arturo is an incalculably wonderful man and a beautiful \n			  strong-minded role model of genetics.", 140, 1000, 24, 24);
			if (random3 == 5) sfw::drawString(d, "Arturo is a devilishly handsome fellow and a scholar.", 200, 1000, 24, 24);
			if (random3 == 6) sfw::drawString(d, "Damn Mexicans...", 750, 1000, 24, 24);
			if (random3 == 7) sfw::drawString(d, "Arturo wilt fall upward when he hast less wit.", 300, 1000, 24, 24);
			if (random3 == 8) sfw::drawString(d, "Arturo's brain is as dry as the remainder biscuit after a voyage.", 170, 1000, 24, 24);
			if (random3 == 9) sfw::drawString(d, "Arturo ist well endowed like an impressive specimen.", 400, 1000, 24, 24);
			if (random3 == 10) sfw::drawString(d, "Arturo , I adore you, scurvy companion. What, you rich, cultured, nice,\n	   cheating, lack-linen mate! Come, you nice guy, come!", 140, 1000, 24, 24);
			if (random3 == 11) sfw::drawString(d, "ARTURO IS SUCH A NICE GUY!", 690, 1000, 24, 24);
			if (random3 == 12) sfw::drawString(d, "Arturo is an anime loving fellow.", 550, 1000, 24, 24);
			if (random3 == 13) sfw::drawString(d, "Arturo, I'd make fun of you about your height,\n      but those jokes are beneath me. :3", 400, 1000, 24, 24);

			if (random3 == 14) // lol the best compliment
			{

				while (i != 25)
				{
					ObjectPoolX[i] = -5000;
					++i;
				}
				i = 0;
				if (compliment >= 1000 && compliment < 1020)	ObjectPoolX[0] = 700;
				if (compliment >= 1020 && compliment < 1040)	ObjectPoolX[1] = 700;
				if (compliment >= 1040 && compliment < 1060)	ObjectPoolX[2] = 700;
				if (compliment >= 1060 && compliment < 1080)	ObjectPoolX[3] = 700;
				if (compliment >= 1080 && compliment < 1100)	ObjectPoolX[4] = 700;
				if (compliment >= 1100 && compliment < 1120)	ObjectPoolX[5] = 700;
				if (compliment >= 1120 && compliment < 1140)	ObjectPoolX[6] = 700;
				if (compliment >= 1140 && compliment < 1160)	ObjectPoolX[7] = 700;
				if (compliment >= 1160 && compliment < 1180)	ObjectPoolX[8] = 700;
				if (compliment >= 1180 && compliment < 1200)	ObjectPoolX[9] = 700;
				if (compliment >= 1200 && compliment < 1220)	ObjectPoolX[10] = 700;
				if (compliment >= 1220 && compliment < 1240)	ObjectPoolX[11] = 700;
				if (compliment >= 1240 && compliment < 1260)	ObjectPoolX[12] = 700;
				if (compliment >= 1260 && compliment < 1280)	ObjectPoolX[13] = 700;
				if (compliment >= 1280 && compliment < 1300)	ObjectPoolX[14] = 700;
				if (compliment >= 1300 && compliment < 1320)	ObjectPoolX[15] = 700;
				if (compliment >= 1320 && compliment < 1340)	ObjectPoolX[16] = 700;
				if (compliment >= 1340 && compliment < 1360)	ObjectPoolX[17] = 700;
				if (compliment >= 1360 && compliment < 1380)	ObjectPoolX[18] = 700;
				if (compliment >= 1380 && compliment < 1400)	ObjectPoolX[19] = 700;
				if (compliment >= 1400 && compliment < 1420)	ObjectPoolX[20] = 700;
				if (compliment >= 1420 && compliment < 1440)	ObjectPoolX[21] = 700;
				if (compliment >= 1440 && compliment < 1460)	ObjectPoolX[22] = 700;
				if (compliment >= 1460 && compliment < 1480)	ObjectPoolX[23] = 700;
				if (compliment >= 1480 && compliment < 1500)	ObjectPoolX[24] = 700;
			}

			if (random3 == 15) sfw::drawString(d, "A nice guy is Arturo, yes.", 700, 1000, 24, 24);
			if (random3 == 16) sfw::drawString(d, "When I hear the word nice guy, I look at Arturo.", 400, 1000, 24, 24);
			if (random3 == 17) sfw::drawString(d, "Welcome to college Arturo.", 700, 1000, 24, 24);
			if (random3 == 18) sfw::drawString(d, "Arturo really is the biggest nice guy in the room", 400, 1000, 24, 24);
			if (random3 == 19) sfw::drawString(d, "ArTur0 cmA't tEII lf tHls 15 Sp31lEd wr0Mq,", 620, 1000, 15, 42);
			if (random3 == 20) sfw::drawString(d, "Derek is such an amazing programmer. He even made me! :3", 300, 1000, 24, 24);
			if (random3 == 21) sfw::drawString(d, "Chase is so humble for totally not writing about how\ngreat he is right here, because I am great aren't I? \n\n											 -Chase", 300, 1000, 24, 24); //written by Chase
			if (random3 == 22) sfw::drawString(d, "Henry derives pleasure from the consumption of lightly baked pastries\n			   		 in a grandiose fashion.\n													 -Henry", 140, 1000, 24, 24); //written by google lol
			if (random3 == 23)
			{
				sfw::drawString(d, "It's time for Chase to stop all this adventuring. He needs to settle down.\n						  Find a farm, a family.", 70, 1000, 24, 24);
				if (compliment > 1250)
				{
					sfw::drawString(d, "\n\n\n		  Then slaughter them all and find a new farm and family.", 70, 1000, 24, 24);
				}
			}

			if (random3 == 24) sfw::drawString(d, "Let`s share Arturo! You take the cake, I`ll take the pie!", 200, 1000, 24, 24);
			if (random3 == 25) sfw::drawString(d, "I love you Derek!", 700, 1000, 24, 24);

			//alpha quotes ^ :D
			//                                                                                                              |
			if (random3 == 26) sfw::drawString(d, "Arturo, Your high five is a great thing.", 400, 1000, 24, 24);
			if (random3 == 27) sfw::drawString(d, "Arturo, Get a ladder and get on my level.", 400, 1000, 24, 24);
			if (random3 == 28) sfw::drawString(d, "Are these jokes falling short, Arturo?", 400, 1000, 24, 24);
			if (random3 == 29) sfw::drawString(d, "I would push you, but that would be very mean, Arturo.", 225, 1000, 24, 24);
			if (random3 == 30) sfw::drawString(d, "Your mom is a lovely woman.", 600, 1000, 24, 24);
			if (random3 == 31) sfw::drawString(d, "Arturo are you feeling ok?????", 600, 1000, 24, 24);
			if (random3 == 32) sfw::drawString(d, "Arturo, You are tall enough to be taken seriously.", 400, 1000, 24, 24);
			if (random3 == 33) sfw::drawString(d, "I'd make fun of you again Arturo, But I don't want to be a mean person.", 100, 1000, 24, 24);
			if (random3 == 34) sfw::drawString(d, "If Pluto isn't a planet because it's too small, then are you really a \n                                 person Arturo?", 100, 1000, 24, 24);
			if (random3 == 35) sfw::drawString(d, "I used to be short like you Arturo, but I grew out of it.", 300, 1000, 24, 24);
			if (random3 == 36) sfw::drawString(d, "My dad told me to appreciate the little things in life. \n        That's why I hang out with you Arturo.", 300, 1000, 24, 24);
			if (random3 == 37) sfw::drawString(d, "Arturo? What do you want to be when you grow up?", 400, 1000, 24, 24);
			if (random3 == 38) sfw::drawString(d, "Arturo, Do you have a pot of gold at the end of your rainbow?", 200, 1000, 24, 24);
			if (random3 == 39) sfw::drawString(d, "Arturo if you were a bard you'd have a charisma of thirty.", 250, 1000, 24, 24);
			if (random3 == 40) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 41) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 42) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 43) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 44) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 45) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 46) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 47) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 48) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 49) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);
			if (random3 == 50) sfw::drawString(d, "Arturo is such a nice guy.", 700, 1000, 24, 24);

			//beta quotes ^ :3
			//                                                                                                              |


			//select a new compliment :D
			if (compliment >= 1500)
			{
				random3 = (rand() % 25 + 1);
				compliment = 0;
			}

		sfw::drawString(d, "Arturo is such a prince.", ObjectPoolX[0], 1000, 24, 24);
		sfw::drawString(d, "aRturo is such a prince.", ObjectPoolX[1], 1000, 24, 24);
		sfw::drawString(d, "arTuro is such a prince.", ObjectPoolX[2], 1000, 24, 24);
		sfw::drawString(d, "artUro is such a prince.", ObjectPoolX[3], 1000, 24, 24);
		sfw::drawString(d, "artuRo is such a prince.", ObjectPoolX[4], 1000, 24, 24);
		sfw::drawString(d, "arturO is such a prince.", ObjectPoolX[5], 1000, 24, 24);
		sfw::drawString(d, "arturo Is such a prince.", ObjectPoolX[6], 1000, 24, 24);
		sfw::drawString(d, "arturo iS such a prince.", ObjectPoolX[7], 1000, 24, 24);
		sfw::drawString(d, "arturo is Such a prince.", ObjectPoolX[8], 1000, 24, 24);
		sfw::drawString(d, "arturo is sUch a prince.", ObjectPoolX[9], 1000, 24, 24);
		sfw::drawString(d, "arturo is suCh a prince.", ObjectPoolX[10], 1000, 24, 24);
		sfw::drawString(d, "arturo is sucH a prince.", ObjectPoolX[11], 1000, 24, 24);
		sfw::drawString(d, "arturo is such A prince.", ObjectPoolX[12], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a Prince.", ObjectPoolX[13], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a pRince.", ObjectPoolX[14], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a prInce.", ObjectPoolX[15], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a priNce.", ObjectPoolX[16], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a prinCe.", ObjectPoolX[17], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a princE.", ObjectPoolX[18], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a prince!", ObjectPoolX[19], 1000, 24, 24);
		sfw::drawString(d, "ARTURO IS SUCH A PRINCE!", ObjectPoolX[20], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a prince.", ObjectPoolX[21], 1000, 24, 24);
		sfw::drawString(d, "ARTURO IS SUCH A PRINCE!", ObjectPoolX[22], 1000, 24, 24);
		sfw::drawString(d, "arturo is such a prince.", ObjectPoolX[23], 1000, 24, 24);
		sfw::drawString(d, "ARTURO IS SUCH A PRINCE!", ObjectPoolX[24], 1000, 24, 24);
		while (i != 25)
		{
			if (ObjectPoolX[i] == 700)
			{
				random3 = 14;
			}
			++i;
		}
		i = 0;
		}
		



	}
}
APP_STATE Miku::next()
{
	return MIKU;
}