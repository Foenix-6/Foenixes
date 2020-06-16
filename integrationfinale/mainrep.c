#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "time.h"
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include "enigme.h"
int mainrep(SDL_Surface *screen)
{
  
  /*SDL_Surface *screen = NULL;
	SDL_Init(SDL_INIT_VIDEO);
  /*if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("unable to init SDL %s\n", SDL_GetError());
		return 1;}*/



	//screen = SDL_SetVideoMode(952,535,24,SDL_HWSURFACE | SDL_DOUBLEBUF);
	/*if(screen == NULL){
		printf("unable to set video mode %s\n", SDL_GetError());
		return 1;
	}*/

  char image[20];
  enigme e;
  int alea,solution,r,running=0,run=0,rep=0;
  


	init_enigme(&e);
	
	generate_afficher (screen, image,&e,&alea);
	solution=solution_e (image);
	resolution (&r );
	rep=afficher_resultat (screen,solution,r,&e);
	
return rep;









	
}
