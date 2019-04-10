#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"
#define SCREEN_W 1000
#define SCREEN_H 650
int main()
{
    scrolling scro;
    image newgame,settings,help,exit,menu,level1;
    SDL_Surface *ecran=NULL;
    int continuer = 1,i=0;
    SDL_Rect camera;
    camera.x=0;
    camera.y=0;
    camera.h=SCREEN_H;
    camera.w=SCREEN_W;
    SDL_Event event;

    ecran=openwindow(ecran,SCREEN_W,SCREEN_H);

    affichagecoat(ecran);
    musique_menu();
    affichagemenu(menu,ecran);

    SDL_EnableKeyRepeat(100,100);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:// nzelt ala felsa f souris
            if (event.button.button == SDL_BUTTON_LEFT)// itha kan nzelt ysar
            {

                if ( event.button.x >21 && event.button.y >236 && event.button.x < 192 && event.button.y <276)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
                {
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
                camera.x += 20;
                if(camera.x>4120)// fixation de la Position
                {
                    camera.x=4120;
                }
                break;
            case SDLK_LEFT:
                camera.x -= 20;
                if(camera.x<0) // fixation de la Position
                {
                    camera.x=0;
                }
                break;
            case SDLK_RETURN: //bouton entrer
                if (i==1)
                {
                    scro=init_img("stage1.png",0,0);
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

                break;
            case SDLK_UP:
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


                break;
            }
        }
        Scroll(ecran,scro,camera);
    }

    Mix_CloseAudio();//tsakr e sout
    SDL_Quit(); // Arrêt de la SDL



    return EXIT_SUCCESS; // Fermeture du programme
}


