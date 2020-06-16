#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "map.h"
#include "entity.h"

#include "enigme.h"
#include "background.h"





void jouer(SDL_Surface* screen)
{	SDL_Event event;
	collision col;
        input in;
        pers p;
	entity e;
	ennemie en;
	map m;
	Uint32 t_dep,t_fin,dt=1;
        int fps=30,ran,rep=0;
	t_dep=SDL_GetTicks();
        int collision=1,l=0,a=1,b=0,b1=0,d=0,co=0;  
	background back;
	image gameover;
	int done = 1;
	Time temps;
	
        srand(time(NULL));
     	ran==rand()%3+1;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	
        //initbackground(&background);
	initialiser_background(&back);
	inittemps(&temps);
        initgameover(&gameover);
        initinput(&in);
	initialiser_entity (&e) ;
	initialiser_ennemie(&en);
	initperso(&p);
	initialiser_map (&m,screen,&e,&p,&en) ;
	perso_map(&m,&p);
	entity_map(&m,&e);
	ennemie_map(&m,&en);
	
	while (done)
	{  
	  d=deplacerperso(&p,dt,back);
	  
          b=detect_collision(&p,&e);
	  b1=detect_collision_ennemie(&p,&en);
	  scrolling1 (&p,&back,d,co);
	  
          updateperso(&p,in,&col,&e,b,&en,b1,&a);
	  
       	  update_time(&temps);
	  update_entity(&e);
	  update_ennemie(&en,&p);
	 gravity(&p,back);
	   
	  
	  mise_a_jour_map(&m ,screen,&p,&e,&en);
	  if(b1==1){
	  do{
	   rep=mainrep(screen);
	}while(rep==0);
	 }
	 //displaybackground(background,screen);
	 Affiche_back(back,screen);
	 dipslayperso(p,screen);
       	 displaygameover(&done,p.vie,gameover,screen);
	 displaytime(temps,screen);
	 if(b) a=gestion(&e);
         if (a){ afficher_entity(&e ,screen);}
	
         afficher_ennemie(&en ,screen);
	 affiche_map(&m,screen,&e,&p,&en);
	
 
       	 SDL_Flip(screen);
	 SDL_Delay(100);
	}

	freeTextvie(p.textevie);
    	freeTextscore(p.textescore);
    	//freebackground(back);
    	freeTexttime(temps.temps);
	SDL_Quit();


}
