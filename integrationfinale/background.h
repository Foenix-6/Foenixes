#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include <stdio.h>
	#include <stdlib.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_mixer.h>
	#include <SDL/SDL_ttf.h>
	#include <time.h>
	#include <unistd.h>
#include "pers.h"
#include "utilitaire.h"



/*typedef struct 
{
	SDL_Surface *image;
	SDL_Surface *image2;
	SDL_Surface *calque;
	SDL_Surface *calque2;
	SDL_Rect positionback;
	SDL_Rect positionback2;
	SDL_Rect cam1;
	SDL_Rect poscam1;
	int gravity;
}background;*/
void initialiser_background(background *back);
void scrolling1 (pers *p,background *back,int d,int co);
//void scrolling2 (hero *hero,background *back,int d2,int co);
void Affiche_back(background back,SDL_Surface *ecran);
void gravity(pers *p, background back);


void freebackground(background background);
#endif
