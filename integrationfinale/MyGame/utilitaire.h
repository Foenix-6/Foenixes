#ifndef UTILITAIRE_H_INCLUDED
#define UTILITAIRE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
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
void displayTexttime(Text T,SDL_Surface *screen);
void freeTexttime(Text T);

//score:
int initTextscore(Text* T);
void update_score(Text* T, int *score, collision col);
void displayscore(Text T,SDL_Surface *screen);
void freeTextscore(Text T);
int loadFontscore(Text* T, char* path);


#endif
