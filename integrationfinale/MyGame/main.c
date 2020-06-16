/**
* @file main.c
* @brief exécution de programme.
* @author Oussama Boussetta
* @version 0.1
* @date june 07, 2020
*
* exécuter le programme pour l'entitée secondaire et l'ennemi .
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
#include "entity.h"
#include "map.h"

int main()
{
    int hauteur_fenetre = 1000,t,
        largeur_fenetre = 1500;
	
printf("donner type : \n 0 ->  bad || 1 -> good ");
scanf("%d",&t);

   

	SDL_Init(SDL_INIT_VIDEO);

//creation de la fenetre 
	SDL_Surface *screen;
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
	SDL_WM_SetCaption("CORONA", NULL); 
// creation background
 	SDL_Surface *background ;
	SDL_Rect background_pos;
	background = IMG_Load("background.jpeg");
	background_pos.x = 0;
	background_pos.y = 0;
// afficher background 
	//SDL_BlitSurface(background,NULL,screen,&background_pos);

 
//init entity

input in;
entity e;
map m;

initialiser_entity (&e,t) ;

personnage p;
initialiser_perso (&p) ;
SDL_EnableKeyRepeat(200, 0);
SDL_Event event;
initialiser_map (&m,screen,&e,&p) ;
perso_map(&m,&p);
entity_map(&m,&e);

int a=1; 


int done = 1;
        while (done)
	{ 	 
	e.col=0;
	
  	//in=getinput(&done,in);
SDL_PollEvent(&event);

           
                        switch (event.type) 
                        {

                        case SDL_QUIT: 
                                done = 0;
                                break;

                        //avec clavier
                        case SDL_KEYDOWN:                     
                                switch (event.key.keysym.sym) 
                                {

                                
                                case SDLK_RIGHT: 
                                         
                                      p.perso_pos.x += 10;

                                        break;

                                case SDLK_LEFT: 
                                        p.perso_pos.x -= 10;
                                     
                                         
                                        break;
                                case SDLK_UP: 
                                        p.perso_pos.y -= 10;
                                        break;

                                case SDLK_DOWN: 
                                      p.perso_pos.y += 10;
                                        break;
                                }
                        } //fin switch



	update_entity(&e,&p);
	
	
	SDL_BlitSurface(background,NULL,screen,&background_pos);
	if(detect_collision(&p,&e)) a=gestion(&e);

	if (a){ afficher_entity(&e ,screen);}
  //if (e.col==0)
	 afficher_perso(&p ,screen);
	affiche_map(&m,screen,&e,&p);
	mise_a_jour_map(&m ,screen,&p,&e);
	SDL_Delay(10);

	SDL_Flip(screen);

	}
	
	
	
	SDL_FreeSurface(background);
	SDL_Quit();

    return 0;
}
