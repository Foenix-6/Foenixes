#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct 
{
 SDL_Surface  *img;
 SDL_Rect 	p;
}enigme;

void init_enigme(enigme * e);
void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea);
int solution_e (char image []);
void resolution (int *r );
int mainrep(SDL_Surface *screen);
int afficher_resultat (SDL_Surface * screen,int solution,int r,enigme *en);
#endif // ENIGME_H_INCLUDED
