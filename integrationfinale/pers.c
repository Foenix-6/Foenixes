/**
* @file pers.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2020
*
* Testing pers
*
*/


#include "pers.h"

int nb_image_par_ligne_spritesheet = 8,
nb_ligne_spritesheet=2;

void initialiser_animation_perso(SDL_Rect *clip)
{

  //init width and height
for (int j=0; j<nb_image_par_ligne_spritesheet*nb_ligne_spritesheet;j++){
  clip[j].w = 100;
  clip[j].h = 100;
}


    //vers droite : ligne 1
    int i = 0;
    for (i = 0; i < nb_image_par_ligne_spritesheet; i++)
    {

        clip[i].x = clip[i].w * i;
        clip[i].y = 0;
    }

    //vers gauche : ligne 2
    i = 8;
    for (i = 8; i < (2 * nb_image_par_ligne_spritesheet); i++)
    {
        clip[i].x =(i-8)* clip[i].w;
        clip[i].y =  clip[0].y+clip[0].h;
    }

}




/**
* @brief To initialize the background background .
* @param background the background
* @return Nothing
*/
/*void initbackground(image *background)
{
	(*background).image=IMG_Load("background.jpeg");
	((*background).posimage).x = 0;
	((*background).posimage).y = 0;
}*/
/**
* @brief To initialize the image gameover .
* @param gameover the image
* @return Nothing
*/
void initgameover(image *gameover)
{
	 (*gameover).image=IMG_Load("gameover.jpeg");
	((*gameover).posimage).x=50;
        ((*gameover).posimage).y=90;		
}
/**
* @brief To initialize the life .
* @param vie the number of life
* @param textevie the text of life
* @return int 
*/
int initvie(Text* textevie,int* vie)
{int ltv;
	*vie=3;
	ltv=initTextvie(textevie);
	return ltv;
}
/**
* @brief To initialize the pers p.
* @param p the pers
* @return nothing
*/
void initperso(pers* p)
{int ltv,lts;
	p->pos_perso.x=10;
	p->pos_perso.y=560;
	p->pos_perso.h=100;
	p->pos_perso.w=100;
	p->image_perso=IMG_Load("src/perso.png");
	p->vitesse_perso=200;
	p->vitesse_max_perso=200;
	p->stable=1;
	p->direction=0;
	p->jump=1; //1-> peut sauter | 0-> ne peut pas sauter
	p->comp_tab_animation_perso=30;
	p->acc=0;
	p->acceleration=0;
	initialiser_animation_perso(p->animation_perso);
	ltv=initvie(&(p->textevie),&(p->vie));
	lts=initscore(&(p->textescore),&(p->score));
}
/**
* @brief To initialize the score .
* @param score the number of score
* @param textescore the text of score
* @return int 
*/
int initscore(Text* textescore,int *score)
{int lts;
	(*score)=0;
	lts=initTextscore(textescore);
	return lts;

} 
/**
* @brief To initialize the input .
* @param in the input 
* @return nothing
*/
void initinput(input *in)
{int i;
	for(i=0;i<322;i++)
	{in->clavier[i]=0;}
}


void avancer_perso(pers *p,Uint32 dt)
{
  	acceleration(p,dt);
  	p->direction=0;
 	 p->stable=0;
 	 if (p->pos_perso.x+p->pos_perso.w<1500)
		p->pos_perso.x+=p->vitesse_perso;
	p->pos_perso_relative.x+=p->vitesse_perso;
	animation_perso_mvt_droite(p);
}
void reculer_perso(pers *p,Uint32 dt){
  	acceleration(p,dt);
  	p->direction=1;
   	 p->stable=0;
	p->pos_perso.x-=p->vitesse_perso;
	p->pos_perso_relative.x-=p->vitesse_perso;
	animation_perso_mvt_gauche(p);
}

void animation_perso_stable(pers *p)
{

  	p->comp_tab_animation_perso++;
    //regarder droite
	if (!p->direction)
	{
 	 if(p->comp_tab_animation_perso < 0 || p->comp_tab_animation_perso>7)
 		 p->comp_tab_animation_perso=0;
	}

  //regarder gauche
       if(p->direction){
          if(p->comp_tab_animation_perso < 8 || p->comp_tab_animation_perso>15)
 		 p->comp_tab_animation_perso=8;
	}



}

void animation_perso_mvt_droite(pers *p)
{
    p->comp_tab_animation_perso++;

  if(p->comp_tab_animation_perso < 0 || p->comp_tab_animation_perso>7)
  p->comp_tab_animation_perso=0;
}

void animation_perso_mvt_gauche(pers *p)
{
  p->comp_tab_animation_perso++;
  if(p->comp_tab_animation_perso < 8 || p->comp_tab_animation_perso>15)
    p->comp_tab_animation_perso=8;
}

void acceleration(pers *p,Uint32 dt)
{
	if (p->acceleration%2==0) 
	{
 	    p->acc=0;
            p->vitesse_perso=3;
	}
 	if(p->acceleration%2==1)
 	{
          if(p->vitesse_perso<p->vitesse_max_perso)
 	   {
          //p->acc+=0.000001;
          p->acc+=1;
          p->vitesse_perso+=0.5*p->acc*dt*dt+p->vitesse_perso*dt/1000;
           }
        }
}

void jump_perso(pers *p)
{
 	if(p->jump)
	{
 	 p->pos_perso_relative.y-=100;
  	p->pos_perso.y-=100;
	}
}


/*void gravity(pers *p,background back)
{

	if(p->pos_perso.y<310)//if not touching the groud
	{
	p->pos_perso.y+=back.gravity;
	p->pos_perso_relative.y+=back.gravity;
	p->jump=0;
	}
	//if touching the ground
	else p->jump=1;

}*/

input getinput(int *done,input in)
{SDL_Event event;
        if (SDL_PollEvent(&event))
	{
	        switch(event.type)
	        {
	
	        case SDL_QUIT:
	            *done=0;
	            break;
	        case SDL_KEYDOWN: 
	             in.clavier[event.key.keysym.sym]=1;
	             break;
	        case SDL_KEYUP:
	             in.clavier[event.key.keysym.sym]=0;
	             break;
	
         
		}
	
	}
     return in;
}
/**
* @brief To update the pers .
* @param p the pers 
* @param in the input
* @param col the collision
* @return nothing 
*/
/*
void updateperso(personnage *p1,pers *p,collision *col,int a)
{//mise a jour des autres champs du hero
  
  //exemple : col.coin=collisonboundingbox entre personnage et coin.
 //col->colcoin=in.clavier[SDLK_k];/*sdlk_k*/
 //col->colenigme=in.clavier[SDLK_j];/*sdlk_j*/
 /*col->colenigme=a;
 update_vie(&(p->textevie),&(p->vie),*col);
 update_score(&(p->textescore),&(p->score),*col);
 if(a=1)
	{p1->perso_pos.x = 100;
	p1->perso_pos.y = 100;
    	p1->perso_pos.h = 281;
    	p1->perso_pos.w = 217;}

//} */


void updateperso(pers *p,input in,collision *col,entity *e,int b ,ennemie *en,int b1,int *a)
{//mise a jour des autres champs du hero
  
  //exemple : col.coin=collisonboundingbox entre personnage et coin.
 //col->colcoin=in.clavier[SDLK_k];/*sdlk_k*/
 //col->colenigme=in.clavier[SDLK_j];/*sdlk_j
	
	      if(col->colenigme=b1)
		{if (p->pos_perso.x<=en->pos_ennemie.x)p->pos_perso.x-=350;
		if (p->pos_perso.x>=en->pos_ennemie.x)p->pos_perso.x=en->pos_ennemie.x-400;
		}
	     if (col->colcoin=b){e->pos_entity.y=0;e->pos_entity.x=0;*a=0;}
	  update_vie(&(p->textevie),&(p->vie),*col);
	  update_score(&(p->textescore),&(p->score),*col);
 

}
int deplacerperso(pers *p,Uint32 dt,background back )
{

SDL_Event event;
int a=0;
if(SDL_PollEvent(&event))
	{
	        switch(event.type)
	        {
	
	        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{//right button
   			 case SDLK_RIGHT:
				{avancer_perso(p,dt);
				a=1;}
   			 break;

   			 case SDLK_UP:

				jump_perso(p);
 			   break;
			//left button
  		      case SDLK_LEFT:
                         {reculer_perso(p,dt);
			a=2;}
                     break;

                  //acceleration button
                   case SDLK_a:
                  p->acceleration++;
                 break;
	      
  		}
  	   break;
	     case SDL_KEYUP:
  		switch (event.key.keysym.sym) 
		{
		//right button
   		 case SDLK_RIGHT:
		  {p->vitesse_perso=7;
		   a=1;}
  		  break;
		//left button
 		 case SDLK_LEFT:
		{p->vitesse_perso=7;
		a=2;}
   		 break;
  		}
  	  break;

        }	}
	if(p->stable)

animation_perso_stable(p);


 return a;

}
	  
void afficher_perso(pers *p, SDL_Surface *screen)
{
  SDL_BlitSurface(p->image_perso,&p->animation_perso[p->comp_tab_animation_perso],screen,&p->pos_perso);
}

/**
* @brief To display the pers 
* @param p the pers 
* @param screen the screen 
* @return nothing 
*/
void dipslayperso(pers p,SDL_Surface* screen)
{ 
//afficher image perso 
	afficher_perso(&p,screen);
	displayvie(p.textevie,screen);
	displayscore(p.textescore,screen);
}
/**
* @brief To display the background 
* @param background the background
* @param screen the screen 
* @return nothing 
*/
/*void displaybackground(image background,SDL_Surface* screen)
{
	SDL_BlitSurface(background.image,NULL,screen,&background.posimage);
}*/
/**
* @brief To display the gameover
* @param gameover the image of gameover
* @param screen the screen 
* @param vie the number of life 
* @return nothing 
*/
void displaygameover(int *done,int vie,image gameover,SDL_Surface* screen)
{
  if(vie==0)   
	{SDL_BlitSurface(gameover.image,NULL,screen,&gameover.posimage);
	*done=0;}
}
/**
* @brief To free  background.
* @param background the background.
* @return Nothing
*/
/*void freebackground(image background)
{
	SDL_FreeSurface(background.image);
}*/
