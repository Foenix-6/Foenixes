/**
 * @file entity.c 
 */
#include "entity.h"



int 
nb_frame=12 ,
entity_h=195,
entity_w=135,
entity_y=0,
entity_x=0,
ennemie_h=135,
ennemie_w=129,
ennemie_y=1,
ennemie_x=6;


void init_tab_anim_entity(SDL_Rect *clip,entity *e)
{	if (e->type==1){	
	for (int j=0;j<nb_frame; j++)
	{
   	 clip[j].h=entity_h;
         clip[j].w=entity_w;
        clip[j].x = j*entity_w;
	clip[j].y = 0;
        }  
}
else if (e->type==0){
for (int j=0;j<nb_frame; j++)
	{
   	 clip[j].h=ennemie_h;
         clip[j].w=ennemie_w;
        clip[j].x = j*ennemie_w;
	clip[j].y = 0;
        }
}

}


/**
* @brief To initialize the entity e  .
* @param e the entity
* @return Nothing
*/

void initialiser_entity(entity *e, int t)
{
e->type=t;
if(e->type==0)
    e->entity = IMG_Load("ENNEMIE5.png");
else if(e->type==1)
    e->entity = IMG_Load("ES4.png");
else printf("loading error\n");
    e->pos_entity.x = 700;
    e->pos_entity.y = 100;
    init_tab_anim_entity(e->anim_entity,e);
    e->frame_entity=0;
    e->direction=0;  
    e->col=0;
    e->show=1;
    
    
}
/**
* @brief To show the entity e .
* @param screen the screen
* @param e the entity
* @return Nothing
*/


void afficher_entity(entity * e , SDL_Surface *screen)
{
   
   SDL_BlitSurface(e->entity,&e->anim_entity[e->frame_entity], screen, &e->pos_entity);
  
  

}
/**
* @brief for the random movement of the secondary entity and the automation ennemi  .
* @param e the entity
* @param p the personnage  
* @return Nothing
*/

void mvt_entity(entity *e,personnage *p)
{	srand (time(0));
	int diff;
	int maxi_down=300+rand()%300;
	int maxi_up=50+rand()%300;

  	printf("maxup : %d\tmaxdown : %d\n",maxi_up,maxi_down );


if(e->pos_entity.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_entity.y<=maxi_up)
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_entity.y-=5;
 


}
if(e->direction==0)
{
        
	e->pos_entity.y+=5;


}
if(!e->type){
  diff=e->pos_entity.x-p->perso_pos.x;
  
  if (diff<350 && diff>50 ){

e->pos_entity.x-=3;
  }

if (diff >-350 && diff < 0){
  
  e->pos_entity.x+=3;
  }

}
}

/**
* @brief for the animation the secondary entity .
* @param e the entity 
* @return Nothing
*/

void anim(entity *e)
{   if (e->frame_entity >=0 && e->frame_entity <(nb_frame-1)) 
 e->frame_entity++;
    if ( e->frame_entity ==(nb_frame-1)) 
       e->frame_entity=0;


}
/**
* @brief for the integration of two functions (anim,mouv) .
* @param e the entity 
* @param p the personnage 
* @return Nothing
*/


void update_entity(entity *e,personnage *p)
{ 	mvt_entity(e,p);
	anim(e);
	

}
/**
* @brief to change the maxi down and the maxi up randomly .
* @param e the entity 
* @return Nothing
*/


/*void rand_min_max(entity *e){
	srand (time(0));
  	e->maxi_up=50+rand()%100;
 	e->maxi_down=350+rand()%100;

  	printf("maxup : %d\tmaxdown : %d\n",e->maxi_up,e->maxi_down );

}*/

input getinput(int *done,input in)
{ 
 
              

    return in;
}
/**
* @brief To initialize the personnage p  .
* @param p the personnage
* @return Nothing
*/
void initialiser_perso(personnage *p)
{
    p->perso= IMG_Load("per.png");
    p->perso_pos.x = 100;
    p->perso_pos.y = 100;
    p->perso_pos.h = 281;
    p->perso_pos.w = 217;
    
    
}
/**
* @brief To show the personnage p .
* @param screen the screen
* @param p the personnage 
* @return Nothing
*/
void afficher_perso(personnage * p , SDL_Surface *screen)
{
   SDL_BlitSurface(p->perso,NULL, screen, &p->perso_pos);

}
/**
* @brief for the detection of a collision bounding box  .
* @param e the entity 
* @param p the personnage 
* @return collision  
*/
int detect_collision(personnage *p, entity* e)
{
	if (e->col==0)
{
if ((p->perso_pos.x + p->perso_pos. w< e->pos_entity. x) || (p->perso_pos.x> e->pos_entity. x + e->pos_entity. w) ||
(p->perso_pos.y + p->perso_pos.h< e->pos_entity. y) || (p->perso_pos.y> e->pos_entity. y + e->pos_entity. h ))
e->col=0;
else 
e->col=1;
 }
return e->col ;
}
/**
* @brief if the type of the entity is good so it will disappear in case of collision   .
* @param e the entity  
* @return 0
*/
int gestion(entity* e)
{
if (!e->type) return 1 ;
if (e->type)
{e->show=0; 
return 0;
}
}
