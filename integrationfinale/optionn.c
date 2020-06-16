#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


void option(SDL_Surface* screen)
{ 
      	int re=1,i1;
	SDL_Surface *retour,*image,*volume,*volume1,*vol;
	SDL_Rect posretour,posvolume,posvolume1,posvol,postionimage;
	SDL_Event event;
	
	
	image=IMG_Load("background.jpeg");
	retour=IMG_Load("retour.png");
        vol=IMG_Load("V1.png");
        volume=IMG_Load("volume2.png");
        volume1=IMG_Load("volume3.png");
	posvolume.x=600;
  	posvolume.y=125;
   	posvolume1.x=882;
    	posvolume1.y=120;
	posvol.x=200;
    	posvol.y=100;
	posretour.x=1000;
        posretour.y=50;
	postionimage.x=0;
   	postionimage.y=0;
    	
 	while(re)
                {    
                    SDL_PollEvent(&event);
                    SDL_BlitSurface(image,NULL,screen,&postionimage);
                    SDL_BlitSurface(volume,NULL,screen,&posvolume);
                    SDL_BlitSurface(volume1,NULL,screen,&posvolume1);
                    SDL_BlitSurface(vol,NULL,screen,&posvol);
                    SDL_BlitSurface(retour,NULL,screen,&posretour);
                    SDL_Flip(screen);
                    switch(event.type)
                    {
                    case SDL_MOUSEBUTTONDOWN :
                        if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<900&&event.button.x>600)&&(event.button.y<133&&event.button.y>125))
                        {
                            posvolume1.x=event.button.x;
                            if(((posvolume1.x-600)/2)>22)
                                i1=((posvolume1.x-600)/2)-22;
                            if(((posvolume1.x-600)/2)<=22)
                                i1=-(((posvolume1.x-600)/2)-22);
                        }
                        


                        if((event.button.x>1000&&event.button.x<1100)&&(event.button.y>50&&event.button.y<200))
                        {


                           
                            re=0;

                        }

                        break;
		}
}
		
}
