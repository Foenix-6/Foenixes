/**
 * @file map.c 
 */
#include "map.h"
/**
* @brief To initialize the map m and the mini entity   .
* @param m map 
* @param screen the screen
* @return Nothing
*/

void initialiser_map (map *m,SDL_Surface *screen,entity *e,pers *p,ennemie *en)
{
m->map=IMG_Load("mini_background.jpg");
m->pos_map.x = 10;
m->pos_map.y = 80;

m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);
SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,0,0,255));
m->perso_pos_map.x=0;
m->perso_pos_map.y=0;

m->mini_entity=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);
SDL_FillRect(m->mini_entity,NULL,SDL_MapRGB(screen->format,0,255,0));
m->entity_pos_map.x=0;
m->entity_pos_map.y=0;

m->mini_ennemie=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);
SDL_FillRect(m->mini_ennemie,NULL,SDL_MapRGB(screen->format,255,0,0));
m->ennemie_pos_map.x=0;
m->ennemie_pos_map.y=0;



}

/**
* @brief To initialize the postion of the mini_entity m .
* @param m the map 
* @param e the entity 
* @return Nothing
*/
void entity_map(map *m, entity *e){
  m->entity_pos_map.x=e->pos_entity.x/10+m->pos_map.x;
    m->entity_pos_map.y=e->pos_entity.y/10+10+m->pos_map.y;
}

void ennemie_map(map *m, ennemie *en){
  m->ennemie_pos_map.x=en->pos_ennemie.x/10+m->pos_map.x;
    m->ennemie_pos_map.y=en->pos_ennemie.y/10+10+m->pos_map.y;
}
/**
* @brief To initialize the postion of the mini_perso m .
* @param m the map 
* @param p the perso
* @return Nothing
*/
void perso_map(map *m,pers *p){
  m->perso_pos_map.x=p->pos_perso.x/10+m->pos_map.x;
    m->perso_pos_map.y=p->pos_perso.y/10+10+m->pos_map.y;
}
/**
* @brief To show the map m and the mini_entity m and the mini_perso p .
* @param screen the screen
* @param m the map 
* @param e the entity
* @param p the perso
* @return Nothing
*/

void affiche_map(map *m , SDL_Surface *screen, entity *e,pers *p,ennemie *en){
      SDL_BlitSurface(m->map, NULL, screen,&m->pos_map);
      SDL_BlitSurface(m->mini_perso, NULL, screen,&m->perso_pos_map);
	SDL_BlitSurface(m->mini_ennemie, NULL, screen,&m->ennemie_pos_map);
if (e->show)
      SDL_BlitSurface(m->mini_entity, NULL, screen,&m->entity_pos_map);

}
/**
* @brief for the integration of two functions (entity_map,affiche_map,perso_map) .
* @param m the map 
* @param e the entity 
* @param p the personnage 
* @param screen the screen
* @return Nothing
*/

void mise_a_jour_map(map *m , SDL_Surface *screen, pers *p, entity *e,ennemie *en){
   perso_map(m,p);  
   entity_map(m,e);
   ennemie_map(m,en);


}


