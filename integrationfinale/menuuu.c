#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int menu(SDL_Surface* screen)
{
    SDL_Surface *texte,*retour;
    SDL_Surface *jouer,*image,*parametre,*quitter,*personnage,*pierre,*jouer1,*parametre1,*quitter1,*volume,*volume1,*f[13],*a[5];
    SDL_Surface *vol,*reso,*reso1;
    SDL_Rect postionimage,posjouer,posparametre,posquitter,postionjoueur,posretour,posvolume,posvolume1,posvol,posimage1,postexte;
    SDL_Event event;
    unsigned int frameLimit = SDL_GetTicks() + 16;
    void delay(unsigned int frameLimit);
    void display(SDL_Surface *screen,SDL_Surface *t,SDL_Surface *x,SDL_Surface *y,SDL_Surface *z,SDL_Surface *w,SDL_Rect postexte,SDL_Rect postionimage,SDL_Rect posjouer,SDL_Rect posparametre,SDL_Rect posquitter);
    char pause;
    TTF_Init();
    int continuer=1,x=0,done=1,ta2=0,tp2=0,i1=128,p1,done1=1,i=1,re=1,w=1,resultat=0;
    Mix_Chunk *music,*music1;
    Mix_AllocateChannels(2);
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",Mix_GetError());
    }
    music=Mix_LoadWAV("Click De Souris.wav");
    music1=Mix_LoadWAV("fond.wav");
    Mix_VolumeChunk(music1,i1);
    /*if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
    screen=SDL_SetVideoMode(1360,765,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }*/
    vol=IMG_Load("V1.png");
    volume=IMG_Load("volume2.png");
    volume1=IMG_Load("volume3.png");
    SDL_WM_SetCaption("GAME!", NULL);
    f[1]=IMG_Load("t1.png");
    f[2]=IMG_Load("t2.png");
    f[3]=IMG_Load("t3.png");
    f[4]=IMG_Load("t4.png");
    f[5]=IMG_Load("t5.png");
    f[6]=IMG_Load("t6.png");
    f[7]=IMG_Load("t7.png");
    f[8]=IMG_Load("t8.png");
    f[9]=IMG_Load("t9.png");
    f[10]=IMG_Load("t10.png");
    image=IMG_Load("background.jpeg");
    a[1]=IMG_Load("a1.jpg");
    a[2]=IMG_Load("a2.jpg");
    a[3]=IMG_Load("a3.jpg");
    a[4]=IMG_Load("a4.jpg");
    a[5]=IMG_Load("a5.jpg");
    jouer=IMG_Load("12.png");
    jouer1=IMG_Load("11.png");
    parametre1=IMG_Load("21.png");
    parametre=IMG_Load("22.png");
    quitter=IMG_Load("31.png");
    quitter1=IMG_Load("32.png");
    personnage=IMG_Load("per.png");
    postionimage.x=0;
    postionimage.y=0;
    posjouer.x=580;
    posjouer.y=250;
    posparametre.x=580;
    posparametre.y=366;
    posquitter.x=580;
    posquitter.y=480;
    postexte.x=300;
    postexte.y=100;
    posvolume.x=600;
    posvolume.y=125;
    posvolume1.x=882;
    posvolume1.y=120;
    posvol.x=200;
    posvol.y=100;
    postionjoueur.x=5;
    postionjoueur.y=300;
    TTF_Font *fontTest;
    fontTest=TTF_OpenFont("LemonMilk.ttf",80);
    SDL_Color fontColor= {0,0,0};
    texte= TTF_RenderText_Solid(fontTest,"Against Corona",fontColor);
    while(i!=10)
    {

        ta2 = SDL_GetTicks();


        if (ta2 - tp2 >= 250)
        {
            i++;

            SDL_BlitSurface(f[i],NULL,screen,&postionimage);
            SDL_Flip(screen);
            tp2 = ta2;

        }
    }
    posjouer.x=250;
    posjouer.y=280;
    posparametre.x=250;
    posparametre.y=380;
    posquitter.x=250;
    posquitter.y=480;
    ta2=0;
    tp2=0;
    while(w!=5)
    {
        ta2 = SDL_GetTicks();
        if (ta2 - tp2 >= 250)
        {
            w++;

            SDL_BlitSurface(a[w],NULL,screen,&postionimage);
            SDL_Flip(screen);
            tp2 = ta2;

        }
    }
    Mix_PlayChannel(2,music1,-1);
    SDL_BlitSurface(image,NULL,screen,&postionimage);
    SDL_BlitSurface(texte,NULL,screen,&postexte);
    SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
    SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
    SDL_BlitSurface(quitter,NULL,screen,&posquitter);
    SDL_Flip(screen);
    while(continuer)
    {

        done=1;
        done1=1;
        SDL_WaitEvent(&event);
        switch(event.type)
        {

        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
            /*case SDLK_k:
                screen=SDL_SetVideoMode(1360,765,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
                break ;
            case SDLK_j:
                screen=SDL_SetVideoMode(1360,765,0,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
                break ;//case
	*/
            case SDLK_UP:
                if(x==0)
                {   
                    x=2;
                    break;
                }
                if(x==2)
                {
                    x=1;
                    break;
                }
                if(x==1)
                {
                    x=0;
                    break;
                }

                break;
            case SDLK_DOWN:

                x++;
                x=x%3;

                break;
            case SDLK_SPACE:
                if(x==0)
                    continuer=0;
                if(x==2)
                {
                    Mix_PlayChannel(1,music,0);
                    while(done1)
                    {
                        SDL_PollEvent(&event);
                        SDL_BlitSurface(image,NULL,screen,&postionimage);
                        SDL_BlitSurface(volume,NULL,screen,&posvolume);
                        SDL_BlitSurface(volume1,NULL,screen,&posvolume1);
                        SDL_BlitSurface(vol,NULL,screen,&posvol);
                        SDL_Flip(screen);
                        switch(event.type)
                        {
                        case SDL_MOUSEBUTTONDOWN :
                            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<900&&event.button.x>600)&&(event.button.y<133&&event.button.y>125))
                            {
                                posvolume1.x=event.button.x;
                                if(((posvolume1.x-600)/2)>22)
                                    i1=((posvolume1.x-600)/2)-22;
                                if(((posvolume1.x-600)/2)<=22)
                                    i1=-(((posvolume1.x-600)/2)-22);
                            }
                            Mix_VolumeChunk(music1,i1);
                            break;
                        case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                            case SDLK_ESCAPE:
                                done1=0;
                                break;
                            }
                            break;
                        }

                    }
                }
                if(x==1)
                {
                    Mix_PlayChannel(1,music,0);
                    x=1;
                    while(done)
                    {



                    }
                }
                break;

                done=1;
            }
            if(x==1)
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            if(x==2)
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            if(x==0)
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter1,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            break;
        case SDL_MOUSEMOTION:
            if((event.motion.x<668&&event.motion.x>332)&&(event.motion.y<382&&event.motion.y>300))
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            if(!(((event.motion.x<668&&event.motion.x>332)&&(event.motion.y<382&&event.motion.y>300))||(event.motion.x<668&&event.motion.x>332)&&(event.motion.y<494&&event.motion.y>412)||(event.motion.x<668&&event.motion.x>332)&&(event.motion.y<686&&event.motion.y>524)))
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);

            }
            if((event.motion.x<668&&event.motion.x>332)&&(event.motion.y<494&&event.motion.y>412))
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            if((event.motion.x<668&&event.motion.x>332)&&(event.motion.y<686&&event.motion.y>524))
            {
                SDL_BlitSurface(image,NULL,screen,&postionimage);
                SDL_BlitSurface(texte,NULL,screen,&postexte);
                SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                SDL_BlitSurface(quitter1,NULL,screen,&posquitter);
                SDL_Flip(screen);
            }
            break;
        case SDL_MOUSEBUTTONDOWN :
            //play
            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<668&&event.button.x>332)&&(event.button.y<382&&event.button.y>300))
            {   return 1;
                Mix_PlayChannel(1,music,0);
                /*while((done)&&(re))
                {   retour=IMG_Load("retour.png");
                    posretour.x=1000;
                    posretour.y=50;
                    SDL_BlitSurface(image,NULL,screen,&postionimage);
                    SDL_BlitSurface(retour,NULL,screen,&posretour);
                    SDL_BlitSurface(personnage,NULL,screen,&postionjoueur);
                    SDL_Flip(screen);
                    SDL_WaitEvent(&event);
                    switch(event.type)
                    {
                    case SDL_MOUSEBUTTONDOWN:
                        if((event.button.x>1000&&event.button.x<1200)&&(event.button.y>50&&event.button.y<300))
                        {
                            Mix_PlayChannel(1,music,0);

                            re=0;
                            SDL_BlitSurface(image,NULL,screen,&postionimage);
                            SDL_BlitSurface(texte,NULL,screen,&postexte);
                            SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
                            SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
                            SDL_BlitSurface(quitter,NULL,screen,&posquitter);
                            SDL_Flip(screen);
                        }
                        break;
                    }
                    SDL_PollEvent(&event);
                    switch(event.type)
                    {
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            done=0;
                            break;
                        case SDLK_UP:
                            postionjoueur.y=postionjoueur.y-10;
                            break;
                        case SDLK_DOWN:
                            postionjoueur.y=postionjoueur.y+10;
                            break;
                        case SDLK_RIGHT:
                            postionjoueur.x=postionjoueur.x+10;
                            break;
                        case SDLK_LEFT:
                            postionjoueur.x=postionjoueur.x-10;
                            break;
                        }
                        break;
                    }
                }*/
             delay(frameLimit);
             frameLimit = SDL_GetTicks() + 16;

            }
            
            re=1;
            SDL_Flip(screen);
            //settings
            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<668&&event.button.x>332)&&(event.button.y<494&&event.button.y>412))
            {   return 2;
                Mix_PlayChannel(1,music,0);

                while((done1)&&(re))
                {
                    retour=IMG_Load("retour.png");
                    posretour.x=1000;
                    posretour.y=50;
                    SDL_PollEvent(&event);
                    SDL_BlitSurface(image,NULL,screen,&postionimage);
                    SDL_BlitSurface(volume,NULL,screen,&posvolume);
                    SDL_BlitSurface(volume1,NULL,screen,&posvolume1);
                    SDL_BlitSurface(vol,NULL,screen,&posvol);
                    SDL_BlitSurface(retour,NULL,screen,&posretour);
                    SDL_Flip(screen);
                    switch(event.type)
                    {
                    case SDL_MOUSEBUTTONDOWN :
                        if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<900&&event.button.x>600)&&(event.button.y<133&&event.button.y>125))
                        {
                            posvolume1.x=event.button.x;
                            if(((posvolume1.x-600)/2)>22)
                                i1=((posvolume1.x-600)/2)-22;
                            if(((posvolume1.x-600)/2)<=22)
                                i1=-(((posvolume1.x-600)/2)-22);
                        }
                        Mix_VolumeChunk(music1,i1);


                        if((event.button.x>1000&&event.button.x<1100)&&(event.button.y>50&&event.button.y<200))
                        {


                            Mix_PlayChannel(1,music,0);
                            re=0;

                        }

                        break;


                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            done1=0;
                            break;
                        }
                        break;
                    }

                }


            }
            re=1;

            SDL_Flip(screen);

            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<668&&event.button.x>332)&&(event.button.y<686&&event.button.y>524))
            {   resultat=3;
                Mix_PlayChannel(1,music,0);
                continuer=0;
                SDL_Flip(screen);
            }
        }
    }
    Mix_FreeChunk(music);
    Mix_FreeChunk(music1);
    SDL_FreeSurface(image);
    SDL_FreeSurface(texte);
    SDL_FreeSurface(jouer1);
    SDL_FreeSurface(parametre1);
    SDL_FreeSurface(quitter);
    SDL_Quit();
    return resultat;
}
/*void display(SDL_Surface *screen,SDL_Surface *t,SDL_Surface *x,SDL_Surface *y,SDL_Surface *z,SDL_Surface *w,SDL_Rect postexte,SDL_Rect postionimage,SDL_Rect posjouer,SDL_Rect posparametre,SDL_Rect posquitter)
{
    SDL_BlitSurface(x,NULL,screen,&postionimage);
    SDL_BlitSurface(t,NULL,screen,&postexte);
    SDL_BlitSurface(y,NULL,screen,&posjouer);
    SDL_BlitSurface(z,NULL,screen,&posparametre);
    SDL_BlitSurface(w,NULL,screen,&posquitter);
    SDL_Flip(screen);
}*/
void delay(unsigned int frameLimit)
  {

    /* Gestion des 60 fps (images/stories/seconde) */

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
