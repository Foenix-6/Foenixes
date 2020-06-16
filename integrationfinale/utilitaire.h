/**
* @struct Text
* @brief struct for Text
*/
/**
* @struct image
* @brief struct for image
*/
/**
* @struct Time
* @brief struct for time
*/
/**
* @struct input
* @brief struct for input
*/
/**
* @struct collision
* @brief struct for collisions
*/
#ifndef UTILITAIRE_H_INCLUDED
#define UTILITAIRE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>




typedef struct 
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
}background;


struct text {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
};
typedef struct text Text;
typedef struct image {
	SDL_Surface* image;
	SDL_Rect posimage;
}image;
typedef struct time
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;
typedef struct input
{ int clavier[322]; 
  int souris[3];
}input;

typedef struct collision
{
  int colbackgenigme;//perfectpixel
  int colcoin;//boundingbox
  int colenmie;//boundingbox
  int colenigme;//trigo
  int colbackgtrou;//perfectpixel
}collision;
typedef struct
{
SDL_Surface *perso; /*!< Surface. */
SDL_Rect perso_pos ;/*!< Rectangle*/
}personnage ;
/*void initperso(pers* p)
{int ltv,lts;
ltv=initvie(&(p->textevie),&(p->vie));
lts=initscore(&(p->textescore),&(p->score));
}
int initvie(texte* textevie,int* vie)
{int ltv;
*vie=3;
ltv=initTextvie(textevie);
return ltv;
}
int initscore(texte* textescore,int *score)
{int lts;
*score=0;
lts=initTextescore(textescore);
return lts;
} 
*/
//vie:
int initTextvie(Text* T);
void update_vie(Text* T, int *vies,collision col);
void displayvie(Text T,SDL_Surface *screen);
void freeTextvie(Text T);
int loadFontvie(Text* T, char* path);
//time:
void inittemps(Time *t);
void Timer(int *tempsdebut);
int initTexttime(Text* T);
int loadFonttime(Text* T, char* angelina);
void update_time(Time* T);
void displaytime(Time T,SDL_Surface *screen);
void freeTexttime(Text T);

//score:
int initTextscore(Text* T);
void update_score(Text* T, int *score, collision col);
void displayscore(Text T,SDL_Surface *screen);
void freeTextscore(Text T);
int loadFontscore(Text* T, char* path);

int menu(SDL_Surface* screen);
void option(SDL_Surface* screen);
void jouer(SDL_Surface* screen);
#endif
