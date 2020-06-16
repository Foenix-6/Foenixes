#ifndef entite_H_INCLUDED
#define entite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include<time.h>
#include "pers.h"
/**
* @struct the entity 
* @brief struct for the entity
*/

/**
* @struct personnage
* @brief struct for the personnage 
*/
//typedef struct
//{
//SDL_Surface *perso; /*!< Surface. */
//SDL_Rect perso_pos ;/*!< Rectangle*/
//}personnage ;*/

void init_tab_anim_entity(SDL_Rect* clip,entity *e); 
void initialiser_entity (entity *e) ;
void afficher_entity(entity * e , SDL_Surface *screen);
void anim(entity *e);
void mvt_entity(entity *e);
void update_entity(entity *e);
//void initialiser_perso(pers *p);
//void afficher_perso(pers * p , SDL_Surface *screen);
void rand_min_max(entity *e);
int detect_collision(pers *p, entity* e);
int gestion(entity* e);

void init_tab_anim_ennemie(SDL_Rect* clip,ennemie *en); 
void initialiser_ennemie (ennemie *en) ;
void afficher_ennemie(ennemie * en , SDL_Surface *screen);
void anim_ennemie(ennemie *en);
void mvt_ennemie(ennemie *en,pers *p);
void update_ennemie(ennemie *en,pers *p);



int detect_collision_ennemie(pers *p, ennemie* en);


#endif 
