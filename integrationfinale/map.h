#ifndef map_H_INCLUDED
#define map_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "entity.h"

/**
* @struct the map 
* @brief struct for the map 
*/
typedef struct {
SDL_Surface *map ;/*!< Surface. */
SDL_Rect pos_map;/*!< Rectangle*/

SDL_Surface *mini_entity;
SDL_Rect entity_pos_map;
SDL_Surface *mini_ennemie;
SDL_Rect ennemie_pos_map;

SDL_Surface *mini_perso;
SDL_Rect perso_pos_map;
}map ;
void initialiser_map (map *m,SDL_Surface *screen, entity *e,pers *p,ennemie *en) ;
void entity_map(map *m, entity *e);
void ennemie_map(map *m, ennemie *en);
void perso_map(map *m,pers *p);
void affiche_map(map *m, SDL_Surface *screen, entity *e,pers *p,ennemie *en);
void mise_a_jour_map(map *m , SDL_Surface *screen, pers *p, entity *e,ennemie *en);
#endif
