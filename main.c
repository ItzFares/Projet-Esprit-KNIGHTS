#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

int main(int argc, char *argv[])
{   
	int continuer = 1,test=1;
	int up=0,down=0;
	SDL_Event event;
	int volume=5;
	int yes=0;
	int choix_perso=1;
	
menuu menu; 

menu.ecran = NULL;
menu.ecran2= NULL;
menu.image1 = NULL;
menu.image1G = NULL;
menu.image2 = NULL;
menu.image2G = NULL;
menu.image3 = NULL;
menu.image3G = NULL;
menu.image_backg = NULL;
menu.options = NULL;
menu.texte = NULL;
menu.quitter = NULL;
menu.ring = NULL;
menu.ringG = NULL;
menu.confirm = NULL;
menu.yes = NULL;
menu.no = NULL;

Mix_AllocateChannels(32);

	SDL_Color policeNoire = {0,0,0};
 	SDL_Color policeBlanche = {255,255,255}; 
 	SDL_Color policeRouge = {255,0,0};




SDL_Init(SDL_INIT_VIDEO); 
TTF_Init();

menu.police = TTF_OpenFont("Fonts/Redressed-Regular.ttf",40); 
menu.quitter = TTF_RenderText_Blended(menu.police, "Press 'esc' to quit ", policeNoire);


SDL_WM_SetCaption("Rewind", NULL);


   menu.ecran = SDL_SetVideoMode(1200,627,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   menu.ecran2 = SDL_SetVideoMode(1200,627,32, SDL_HWSURFACE | SDL_DOUBLEBUF);



if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
     { printf("%s", Mix_GetError()); }


   
   menu.musique = Mix_LoadMUS("sounds/tracks/musique2.mp3");
   Mix_PlayMusic(menu.musique, -1);
   menu.bref = Mix_LoadWAV("sounds/son.wav");
   
   menu.image_backg = IMG_Load ("image/bgcarth.jpg");  
   menu.image1 = IMG_Load ("image/Asset_1.png");
   menu.image1G = IMG_Load ("image/Asset_2.png");
   menu.image2 = IMG_Load ("image/Asset_3.png");
   menu.image2G = IMG_Load ("image/Asset_4.png");
   menu.image3 = IMG_Load ("image/Asset_5.png");
   menu.image3G = IMG_Load ("image/Asset_6.png");
   menu.options = IMG_Load ("image/bg.png");
   menu.Fullscreen1 = IMG_Load("image/FullscreenOn.png");
   menu.Fullscreen2 = IMG_Load("image/FullscreenOff.png");
   menu.son1 = IMG_Load("image/-.png");
   menu.son2 = IMG_Load("image/Son2.png");
   menu.son3= IMG_Load("image/+.png");
   menu.son4= IMG_Load("image/Son1.png");
   menu.ring = IMG_Load("image/Asset_7.png");
   menu.ringG = IMG_Load("image/Asset_8.png");
   menu.confirm = IMG_Load("image/Asset_9.png");
   menu.yes = IMG_Load("image/Asset_10.png");
   menu.no = IMG_Load("image/Asset_11.png");
   
	//SDL_LoadBMP("image.bmp");


   menu.posimage.x = 0;
   menu.posimage.y = 0;
   menu.posimage.w = menu.ecran -> w;   
   menu.posimage.h = menu.ecran -> h;

   menu.posimage1.x = 800;
   menu.posimage1.y = 200;
   menu.posimage1.w = menu.ecran -> w;   
   menu.posimage1.h = menu.ecran -> h;

   menu.posimage2.x = 800;
   menu.posimage2.y = 300;
   menu.posimage2.w = menu.ecran -> w;   
   menu.posimage2.h = menu.ecran -> h;

   menu.posimage3.x = 800;
   menu.posimage3.y = 400;
   menu.posimage3.w = menu.ecran -> w;   
   menu.posimage3.h = menu.ecran -> h;

   menu.posimage1G.x = 800;
   menu.posimage1G.y = 200;
   menu.posimage1G.w = menu.ecran -> w;   
   menu.posimage1G.h = menu.ecran -> h;

   menu.posimage2G.x = 800;
   menu.posimage2G.y = 300;
   menu.posimage2G.w = menu.ecran -> w;   
   menu.posimage2G.h = menu.ecran -> h;

   menu.posimage3G.x = 800;
   menu.posimage3G.y = 400;
   menu.posimage3G.w = menu.ecran -> w;   
   menu.posimage3G.h = menu.ecran -> h;

   menu.postexte.x = 50;
   menu.postexte.y = 350;

   menu.posquitter.x = 0;
   menu.posquitter.y = 10;

   menu.posoptions.x = 0;
   menu.posoptions.y = 0;
   menu.posoptions.w = menu.ecran ->w;   
   menu.posoptions.h = menu.ecran ->h;

   menu.posFullscreen1.x = 800;
   menu.posFullscreen1.y = 200;
   menu.posFullscreen1.w =menu.ecran->w;   
   menu.posFullscreen1.h =menu.ecran->h;

   menu.posFullscreen2.x = 900;
   menu.posFullscreen2.y = 200;
   menu.posFullscreen2.w =menu.ecran -> w;   
   menu.posFullscreen2.h =menu.ecran -> h;

   menu.posson1.x = 900;
   menu.posson1.y = 300;
   menu.posson1.w = menu.ecran -> w;   
   menu.posson1.h = menu.ecran -> h;

   menu.posson2.x = 900;
   menu.posson2.y = 300;
   menu.posson2.w = menu.ecran -> w;   
   menu.posson2.h = menu.ecran -> h;

   menu.posson3.x = 1000;
   menu.posson3.y = 400;
   menu.posson3.w = menu.ecran -> w;   
   menu.posson3.h = menu.ecran -> h;

   menu.posson4.x = 800;
   menu.posson4.y = 300;
   menu.posson4.w = menu.ecran2 -> w;   
   menu.posson4.h = menu.ecran2 -> h;
   
   menu.posring.x = 1050;
   menu.posring.y = 50;
   menu.posring.w = menu.ecran -> w;   
   menu.posring.h = menu.ecran -> h;

   menu.posconfirm.x = 300;
   menu.posconfirm.y = 300;
   menu.posconfirm.w = menu.ecran -> w;   
   menu.posconfirm.h = menu.ecran -> h;

   menu.posyes.x = 400;
   menu.posyes.y = 380;
   menu.posyes.w = menu.ecran -> w;   
   menu.posyes.h = menu.ecran -> h;

   menu.posno.x = 650;
   menu.posno.y = 380;
   menu.posno.w = menu.ecran -> w;   
   menu.posno.h = menu.ecran -> h;

  

SDL_BlitSurface(menu.image_backg, NULL, menu.ecran, &menu.posimage);
   SDL_Flip(menu.ecran);
   SDL_Delay(500);
   SDL_BlitSurface(menu.image3, NULL, menu.ecran, &menu.posimage3);
   SDL_Flip(menu.ecran);
   SDL_Delay(1000);
   SDL_BlitSurface(menu.image2, NULL, menu.ecran, &menu.posimage2); 
   SDL_Flip(menu.ecran);
   SDL_Delay(1500);
   SDL_BlitSurface(menu.image1, NULL, menu.ecran, &menu.posimage1);  
   SDL_Flip(menu.ecran);
   SDL_BlitSurface(menu.texte, NULL, menu.ecran, &menu.postexte); 
   SDL_BlitSurface(menu.quitter, NULL, menu.ecran, &menu.posquitter);
   SDL_BlitSurface(menu.ring, NULL, menu.ecran, &menu.posring);
   SDL_Flip(menu.ecran);
   

   while(menu.continuer)
   {
      SDL_WaitEvent(&event);

      switch(event.type)
      {
         case SDL_QUIT:
            menu.continuer = 0;
            break;

//	INTERFACE OPTIONS

case SDL_MOUSEBUTTONUP:
if((event.motion.x>800 &&event.motion.y>403 && event.motion.x<1162 && event.motion.y<492)&&(event.button.button == SDL_BUTTON_LEFT))
{
SDL_BlitSurface(menu.confirm, NULL,menu. ecran, &menu.posconfirm);
SDL_BlitSurface(menu.yes, NULL,menu. ecran, &menu.posyes);
SDL_BlitSurface(menu.no, NULL,menu. ecran, &menu.posno);
SDL_Flip(menu.ecran);
}

do
{
SDL_WaitEvent(&event);
if((event.motion.x>400 &&event.motion.y>380 && event.motion.x<562 && event.motion.y<440)&&(event.button.button == SDL_BUTTON_LEFT))
{menu.continuer=0;}
}while((menu.continuer==1) || (event.button.button != SDL_BUTTON_LEFT));

if((event.motion.x>650 &&event.motion.y>380 && event.motion.x<813 && event.motion.y<440)&&(event.button.button == SDL_BUTTON_LEFT))
{
SDL_BlitSurface(menu.image_backg,NULL,menu.ecran,&menu.posimage);
 SDL_BlitSurface(menu.image1,NULL,menu.ecran,&menu.posimage1);
 SDL_BlitSurface(menu.image2,NULL,menu.ecran,&menu.posimage2);
 SDL_BlitSurface(menu.image3,NULL,menu.ecran,&menu.posimage3);
 SDL_BlitSurface(menu.quitter, NULL, menu.ecran, &menu.posquitter); 
 SDL_BlitSurface(menu.ring, NULL, menu.ecran, &menu.posring);
 SDL_Flip(menu.ecran);
}
if((event.motion.x>800 && event.motion.y>303 && event.motion.x<1162 && event.motion.y<392)&&(event.button.button == SDL_BUTTON_LEFT))
{
SDL_BlitSurface(menu.options, NULL,menu. ecran2, &menu.posoptions);
SDL_BlitSurface(menu.Fullscreen1, NULL, menu.ecran2, &menu.posFullscreen1);
SDL_BlitSurface(menu.Fullscreen2, NULL, menu.ecran2, &menu.posFullscreen2);
//SDL_BlitSurface(menu->son1, NULL, menu->ecran2, &menu.posson1);
SDL_BlitSurface(menu.son2, NULL,menu.ecran2, &menu.posson2);
//SDL_BlitSurface(son3, NULL, menu->ecran2, &menu.posson3);
SDL_BlitSurface(menu.son4, NULL,menu.ecran2, &menu.posson4);
SDL_Flip(menu.ecran2);
do
{if(((event.motion.x>menu.posson4.x)&&(event.motion.x<menu.posson4.x+menu.posson4.w)&&(event.motion.y>menu.posson4.y)&&(event.motion.y<menu.posson4.y+menu.posson4.h)&& (event.button.button == SDL_BUTTON_LEFT)))
Mix_VolumeMusic(0);
if(((event.motion.x>menu.posson2.x)&&(event.motion.x<menu.posson2.x+menu.posson2.w)&&(event.motion.y>menu.posson2.y)&&(event.motion.y<menu.posson2.y+menu.posson2.h)&& (event.button.button == SDL_BUTTON_LEFT)))
if( Mix_PlayingMusic() == 0 )
Mix_PlayMusic( menu.musique, -1 );
if(((event.motion.x>menu.posFullscreen1.x)&&(event.motion.x<menu.posFullscreen1.x+menu.posFullscreen1.w)&&(event.motion.y>menu.posFullscreen1.y)&&(event.motion.y<menu.posFullscreen1.y+menu.posFullscreen1.h)&& (event.button.button == SDL_BUTTON_LEFT)))
SDL_WM_ToggleFullScreen(menu.ecran);

if(((event.motion.x>menu.posFullscreen2.x)&&(event.motion.x<menu.posFullscreen2.x+menu.posFullscreen2.w)&&(event.motion.y>menu.posFullscreen2.y)&&(event.motion.y<menu.posFullscreen2.y+menu.posFullscreen2.h)&& (event.button.button == SDL_BUTTON_LEFT)))
SDL_WM_ToggleFullScreen(menu.ecran);

SDL_WaitEvent(&event);
}
while(event.key.keysym.sym!=SDLK_s);
SDL_BlitSurface(menu.image_backg,NULL,menu.ecran,&menu.posimage);
 SDL_BlitSurface(menu.image1,NULL,menu.ecran,&menu.posimage1);
 SDL_BlitSurface(menu.image2,NULL,menu.ecran,&menu.posimage2);
 SDL_BlitSurface(menu.image3,NULL,menu.ecran,&menu.posimage3);
 SDL_BlitSurface(menu.quitter, NULL, menu.ecran, &menu.posquitter);
 SDL_BlitSurface(menu.ring, NULL, menu.ecran, &menu.posring);
 SDL_Flip(menu.ecran);

}
break;

//	EVENEMENT SOURIS

case SDL_MOUSEMOTION:
if(((event.motion.x>menu.posring.x)&&(event.motion.x<menu.posring.x+menu.posring.w)&&(event.motion.y>menu.posring.y)&&(event.motion.y<menu.posring.y+menu.posring.h)))
 {
 SDL_BlitSurface(menu.ringG, NULL, menu.ecran, &menu.posring);
 SDL_Flip(menu.ecran);

/*if (menu.test==1)
{
Mix_PlayChannel(1,menu.bref,0);
menu.test=0;
}*/
} if(((event.motion.x>menu.posimage3.x)&&(event.motion.x<menu.posimage3.x+menu.posimage3.w)&&(event.motion.y>menu.posimage3.y)&&(event.motion.y<menu.posimage3.y+menu.posimage3.h)))
 {
 SDL_BlitSurface(menu.image_backg,NULL,menu.ecran,&menu.posimage);
 SDL_BlitSurface(menu.image1,NULL,menu.ecran,&menu.posimage1);
 SDL_BlitSurface(menu.image2,NULL,menu.ecran,&menu.posimage2);
 SDL_BlitSurface(menu.image3G,NULL,menu.ecran,&menu.posimage3G);
 SDL_BlitSurface(menu.quitter,NULL, menu.ecran, &menu.posquitter); 
 SDL_BlitSurface(menu.ring, NULL, menu.ecran, &menu.posring);
 SDL_Flip(menu.ecran);
if (menu.test==1)
{
Mix_PlayChannel(1,menu.bref,0);
menu.test=0;
}
}
 if(((event.motion.x>menu.posimage2.x)&&(event.motion.x<menu.posimage2.x+menu.posimage2.w)&&(event.motion.y>menu.posimage2.y)&&(event.motion.y<menu.posimage2.y+menu.posimage2.h)))
 {
 SDL_BlitSurface(menu.image_backg,NULL,menu.ecran,&menu.posimage);
 SDL_BlitSurface(menu.image1,NULL,menu.ecran,&menu.posimage1);
 SDL_BlitSurface(menu.image2G,NULL,menu.ecran,&menu.posimage2);
 SDL_BlitSurface(menu.image3,NULL,menu.ecran,&menu.posimage3);
 SDL_BlitSurface(menu.quitter, NULL,menu.ecran, &menu.posquitter); 
 SDL_BlitSurface(menu.ring, NULL, menu.ecran, &menu.posring);
 SDL_Flip(menu.ecran);
if (menu.test==1)
{
Mix_PlayChannel(1,menu.bref,0);
menu.test=0;

}
}


  if(((event.motion.x>menu.posimage1.x)&&(event.motion.x<menu.posimage1.x+menu.posimage1.w)&&(event.motion.y>menu.posimage1.y)&&(event.motion.y<menu.posimage1.y+menu.posimage1.h)))
{
 SDL_BlitSurface(menu.image_backg,NULL,menu.ecran,&menu.posimage);
 SDL_BlitSurface(menu.image1G,NULL,menu.ecran,&menu.posimage1);
 SDL_BlitSurface(menu.image2,NULL,menu.ecran,&menu.posimage2);
 SDL_BlitSurface(menu.image3,NULL,menu.ecran,&menu.posimage3);
 SDL_BlitSurface(menu.quitter, NULL,menu.ecran, &menu.posquitter); 
 SDL_BlitSurface(menu.ring, NULL, menu.ecran, &menu.posring);
 SDL_Flip(menu.ecran);
if (menu.test==1)
{
Mix_PlayChannel(1,menu.bref,0);
menu.test=0;

}
}


 if((event.motion.x >menu. posimage.x && event.motion.x<menu.posimage1.x) ||(event.motion.y<menu.posimage1.y && event.motion.y>menu.posimage.y)|| (event.motion.y> menu.posimage3.y+menu.posimage3.h)|| (event.motion.x>menu.posimage1.x+menu.posimage1.w))
{
 SDL_BlitSurface(menu.image_backg,NULL,menu.ecran,&menu.posimage);
 SDL_BlitSurface(menu.image1,NULL,menu.ecran,&menu.posimage1);
 SDL_BlitSurface(menu.image2,NULL,menu.ecran,&menu.posimage2);
 SDL_BlitSurface(menu.image3,NULL,menu.ecran,&menu.posimage3);
 SDL_BlitSurface(menu.quitter,NULL,menu.ecran,&menu.posquitter);
 SDL_BlitSurface(menu.ring, NULL, menu.ecran, &menu.posring);
 SDL_Flip(menu.ecran);
menu.test=1;
}
break;
SDL_Flip(menu.ecran);


//	EVENEMENT CLAVIER
int up=0;
	case SDL_KEYUP:
		switch(event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			menu.continuer=0;
		break;


	case SDLK_F5:
	SDL_WM_ToggleFullScreen(menu.ecran);
	break;


	case SDLK_p:
                            if( Mix_PlayingMusic() == 0 )
                            {
                                Mix_PlayMusic( menu.musique, -1 );
                            }
                            else
                            {
                                if( Mix_PausedMusic() == 1 )
                                {
                                    Mix_ResumeMusic();
                                }
                                else
                                {
                                    Mix_PauseMusic();
                                }
                            }
                            break;

                            
	case SDLK_F9:
                            Mix_HaltMusic();
                            break;



	case SDLK_k:
	menu.volume--;
            
            
	switch(menu.volume)
	{	
		case 0 :
		Mix_PauseMusic();
		case 1 :
			menu.x1= Mix_VolumeMusic(MIX_MAX_VOLUME/10);
			break;

		case 2 :
			menu.x2=Mix_VolumeMusic(MIX_MAX_VOLUME/5);
			break;

		case 3 :
			menu.x3= Mix_VolumeMusic(MIX_MAX_VOLUME/3);
			break;

                case 4 :
			Mix_VolumeMusic(MIX_MAX_VOLUME/2);
			break;

		case 5 :
			Mix_VolumeMusic(MIX_MAX_VOLUME/(3/2));
			break;


	}
		break;

	case SDLK_j:
	menu.volume++;


	switch(menu.volume)
	{
              
              
		case 1 :
			Mix_ResumeMusic();
			break;

		case 2 :
			Mix_VolumeMusic(menu.x1);
			break;

		case 3 :
			Mix_VolumeMusic(menu.x2);
			break;

		case 4 :
			Mix_VolumeMusic(menu.x3);
			break;

		case 5 :
			Mix_VolumeMusic(MIX_MAX_VOLUME);
			break;
	}



       }
      }
   }

	SDL_FreeSurface(menu.image1);
	SDL_FreeSurface(menu.image1G);
	SDL_FreeSurface(menu.image2);
	SDL_FreeSurface(menu.image2G);
	SDL_FreeSurface(menu.image3);
	SDL_FreeSurface(menu.image3G);
	SDL_FreeSurface(menu.image_backg);
	SDL_FreeSurface(menu.options);
	SDL_FreeSurface(menu.texte);
	SDL_FreeSurface(menu.quitter);

	TTF_Quit();
	Mix_FreeMusic(menu.musique); 
	Mix_CloseAudio(); 
	SDL_Quit();
	return EXIT_SUCCESS;
}


