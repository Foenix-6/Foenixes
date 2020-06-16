#include "background.h"

void initialiser_background(background *back)
{
back->calque=NULL;
back->image=NULL;
back->calque=IMG_Load("calque.png");
back->image=IMG_Load("background.png");
back->positionback.x=0;
back->positionback.y=0;
back->positionback2.x=0;
back->positionback2.y=0;
back->positionback2.h=1000;
back->positionback2.w=1600;
back->gravity=3;

/*back->calque2=NULL;
back->image2=NULL;
back->calque2=IMG_Load("calque.png");
back->image2=IMG_Load("background.png");
back->cam1.x=0;
back->cam1.y=450;
back->poscam1.x=0;
back->poscam1.y=0;
back->poscam1.h=450;
back->poscam1.w=1600;*/
}

void Affiche_back(background back,SDL_Surface *ecran)
{
SDL_BlitSurface(back.image,&(back.positionback2),ecran,&(back.positionback));
//SDL_BlitSurface(back.image2,&(back.poscam1),ecran,&(back.cam1));//
}
void scrolling1 (pers *p,background *back,int d,int co)
{

	switch(d)
	{ 	
	case 1:

		if(co==0)
		{
		 if ((back->positionback2.x<7340)&&(p->pos_perso.x>=800))
		 {
              	  back->positionback2.x+=5;
              	  p->pos_perso.x=800;
		 }
		if(p->pos_perso.x==4940)
		 {
		  back->positionback2.x==4940;
		  while (p->pos_perso.x<7340)
		  {
		  p->pos_perso.x+=5;
		  }
		}
               }
		else
		{if(d==1){
		 p->pos_perso.x=p->pos_perso.x;}
		}

	break;
	case 2:

		if(co==0)
		{
		if ((back->positionback2.x>0)&&((p->pos_perso.x<800)||(p->pos_perso.x>6540)))
		{
                back->positionback2.x-=5;
		}                
		}
		else
		{if(d==2){
		 p->pos_perso.x=p->pos_perso.x;}
		}
	break;
     }
}
void gravity(pers *p,background back)
{

	if(p->pos_perso.y<550)//if not touching the groud
	{
	p->pos_perso.y+=back.gravity;
	p->pos_perso_relative.y+=back.gravity;
	p->jump=0;
	}
	//if touching the ground
	else p->jump=1;

}




