#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

int main()
{
    scrolling scro;
    image newgame,settings,help,exit,menu,level1;
    SDL_Surface *ecran=NULL, *imageDeFond=NULL,*imageDePerso=NULL;;
    int continuer = 1,i=0,choix=0;
    ennemie e;
    int mvmspeed=50;
    int x=0;
    int gravit=350;
    SDL_Rect positionFond ,positionmilieu;
    SDL_Rect position;
    position.x=700;
    position.y=650;
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =1000;
    positionFond.w =1000;
    positionmilieu.x = 200/2 - 50 / 2;
    positionmilieu.y = 350;
    SDL_Event event;

    ecran = SDL_SetVideoMode(1000,650, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    affichagecoat(ecran);
    musique_menu();
    affichagemenu(menu,ecran);
    e=initialiser_ennemie(e);
////////////////////////////////////////////////////////////////
    imageDeFond = IMG_Load("stage1.png");
    imageDePerso = IMG_Load("attachments/1.png");
       SDL_EnableKeyRepeat(10, 10);
    images minimap,icon;
    minimap=init_image("maptest.png",799,0);
    icon=init_image("icontest.png",804,60);

    while (continuer)
    { 
      if(choix==1)
      {
       e=deplacer_ennemie(e,ecran,position,positionmilieu);
       }
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if ( event.button.x >21 && event.button.y >236 && event.button.x < 192 && event.button.y <276)
                {
                    choix=1;
                    soundclic();
                    bouttonplay(newgame,ecran);
                }

                if ( event.button.x >21 && event.button.y >291 && event.button.x <192 && event.button.y <333)
                {
                    soundclic();
                    bouttonsettings(newgame,ecran);
                }
                if ( event.button.x >21 && event.button.y >354 && event.button.x < 192 && event.button.y <395)

                {
                    soundclic();
                    bouttonhelp(newgame,ecran);
                }
                if ( event.button.x >41 && event.button.y >417 && event.button.x < 167 && event.button.y <459)
                {
                    soundclic();
                    bouttonexit(newgame,ecran);
                    continuer=0;
                }
            }
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)// win teta9ra l click
            {
            case SDLK_RIGHT:
if(choix==1)
{
moving_right(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);
animationright(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);  
icon.pos.x += 2;
}            
            break;
            case SDLK_LEFT:
if(choix==1)
{
moving_left(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);
animationleft(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);
icon.pos.x -= 2;
}
                break;
            case SDLK_RETURN: //bouton entrer
                if (i==1)
                {
                    choix=1;
                    SDL_BlitSurface(imageDeFond,NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if (i==2)
                {

                }
                else if (i==3)
                {

                }
                else if (i==4)
                {
                    soundclic();

                    continuer=0;
                };
                break;

            case SDLK_DOWN:
            if(choix==1)
            {
                gravit=250;
            }
                //if(choix!=1)
                {
                i++;
                if(i==5)
                {
                    i=1;
                }
                if(i==1)
                {
                    soundclic();
                    bouttonplay(newgame,ecran);
                }
                if(i==2)
                {
                    soundclic();
                    bouttonsettings(settings,ecran);
                }
                if(i==3)
                {
                    soundclic();
                    bouttonhelp(help,ecran);

                }
                if(i==4)
                {
                    soundclic();
                    bouttonexit(exit,ecran);
                }
                }
                break;
            case SDLK_UP:
                if(choix==1)
                {
                jump(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);
                }
                if(choix!=1)
                {
                i--;
                if(i<=0)

                {
                    i=4;
                }
                if(i==1)
                {
                    soundclic();
                    bouttonplay(newgame,ecran);
                }
                if(i==2)
                {
                    soundclic();
                    bouttonsettings(settings,ecran);
                }
                if(i==3)
                {
                    soundclic();
                    bouttonhelp(help,ecran);
                }
                if(i==4)
                {
                    soundclic();
                    bouttonexit(exit,ecran);
                }

                }
                break;
            }
        }
      
        gravity(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso,gravit); 
        if(choix==1)
        {
        affichage(ecran,minimap); 
        affichage(ecran,icon); 
        }
        SDL_Flip(ecran);
 
        
    }
    librer_image(minimap);
    librer_image(icon);
    Mix_CloseAudio();//tsakr e sout
    SDL_Quit(); // Arrêt de la SDL
    return EXIT_SUCCESS; // Fermeture du programme
}


