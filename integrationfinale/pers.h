/**
* @struct pers
* @brief struct for personnage
*/

#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "utilitaire.h"









typedef struct
{
  SDL_Surface *image_perso;
  SDL_Rect pos_perso;
  SDL_Rect pos_perso_relative;

  SDL_Rect animation_perso[60];
  int comp_tab_animation_perso;

  int direction; // right=0 | left=1
  int stable; // stable = 1 | en mvt=0
  double vitesse_perso;
  int vitesse_max_perso;
  int jump; //determine si perso est capable de sauter

	int score,vie;
        Text textevie;
        Text textescore;
	 double acc;
  int acceleration;
}pers;

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
typedef struct {
SDL_Surface *ennemie ; /*!< Surface. */
SDL_Rect pos_ennemie;/*!< Rectangle*/
SDL_Rect anim_ennemie[70];/*!< Rectangle*/
int frame_ennemie;
int direction;
int col ;
int type;
int maxi_up,maxi_down;
int show;

}ennemie ;


void initialiser_animation_perso(SDL_Rect *clip);
void initialiser_perso(pers *p);
//void initbackground(image *background);
void initgameover(image *gameover);
int initvie(Text* textevie,int* vie);
int initscore(Text* textescore,int *score);
void initperso(pers* p);
void initinput(input *in);
input getinput(int *done,input in);
void avancer_perso(pers *p,Uint32 dt);
void reculer_perso(pers *p,Uint32 dt);
void animation_perso_stable(pers *p);
void animation_perso_mvt_droite(pers *p);
void animation_perso_mvt_gauche(pers *p);
void acceleration(pers *p,Uint32 dt);
void jump_perso(pers *p);
void updateperso(pers *p,input in,collision *col,entity *e,int b ,ennemie *en,int b1,int *a);
int deplacerperso(pers *p,Uint32 dt,background back );
void displaygameover(int *done,int vie,image gameover,SDL_Surface* screen);
//void displaybackground(image background,SDL_Surface* screen);
void dipslayperso(pers p,SDL_Surface* screen);
//void freebackground(image background);
void afficher_perso(pers *p, SDL_Surface *screen);




#endif
