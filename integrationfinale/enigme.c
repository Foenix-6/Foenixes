#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include "time.h"
void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;
}
		
void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	
	srand(time(NULL));
 *alea = 1+ rand()%3;

 sprintf(image ,"%d.jpg",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
}

int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"2.jpg")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		solution =3;	
 	}
 	return solution;
 }

void resolution (int *r )
{
	SDL_Event event ;
  	int continuer=1;
	
	while(continuer)
	{SDL_WaitEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
		continuer=0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  *r= 1;
				continuer=0;
			   break ;
			   case  SDLK_z :
			   *r= 2;
				continuer=0;
			   break;
			   case SDLK_e: 
			   *r=3 ;
			continuer=0;
			  break;
			    }
       break ;

                 
	}
	}
	
  
}
int afficher_resultat(SDL_Surface * screen,int solution,int r,enigme *en)
 {int rep;
 
 	if (r==solution)
 	{       rep=1;
 		en->img=IMG_Load("00.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
	SDL_Delay(3000);
 	}
 	else
 	{       rep=0;
 		en->img=IMG_Load("11.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
		SDL_Delay(3000);
 	}
 return rep;
 }


