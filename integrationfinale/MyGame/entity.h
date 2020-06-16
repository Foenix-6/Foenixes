#ifndef entite_H_INCLUDED
#define entite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "utilitaire.h"
#include<time.h>
/**
* @struct the entity 
* @brief struct for the entity
*/
typedef struct {
SDL_Surface *entity ; /*!< Surface. */
SDL_Rect pos_entity;/*!< Rectangle*/
SDL_Rect anim_entity[70];/*!< Rectangle*/
int frame_entity;
int direction;
int col ;
int type;
int maxi_up,maxi_down;
int show;

}entity ;
/**
* @struct personnage
* @brief struct for the personnage 
*/
typedef struct
{
SDL_Surface *perso; /*!< Surface. */
SDL_Rect perso_pos ;/*!< Rectangle*/
}personnage ;

void init_tab_anim_entity(SDL_Rect* clip,entity *e); 
void initialiser_entity (entity *e, int t) ;
void afficher_entity(entity * e , SDL_Surface *screen);
void anim(entity *e);
void mvt_entity(entity *e,personnage *p);
void update_entity(entity *e,personnage *p);
void initialiser_perso(personnage *p);
void afficher_perso(personnage * p , SDL_Surface *screen);
void rand_min_max(entity *e);
int detect_collision(personnage *p, entity* e);
int gestion(entity* e);


#endif 
