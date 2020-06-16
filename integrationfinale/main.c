#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "utilitaire.h"

int main()
{

	int a=0,continuer=1;
        int hauteur_fenetre = 1000 , largeur_fenetre = 1500;
   	SDL_Surface* screen;
	
	
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
     
	
        while(continuer)
 	{
	a=menu(screen);
	printf("%d \n",a);
	switch(a)
	{
	case 1 : jouer(screen);
		break;
	case 2 :
		option(screen);
		break;
	case 3 : 
		continuer=0;
		break;
	}
	}

	
return 0;





}
