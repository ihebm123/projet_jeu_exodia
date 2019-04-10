#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "menu.h"


SDL_Surface* openwindow(SDL_Surface *ecran,int h,int w)
{

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_WM_SetCaption("Menu Iheb",NULL);

    ecran=SDL_SetVideoMode(h, w,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    return ecran;

}  

void affichagecoat(SDL_Surface *ecran)
{
     SDL_Event event;
     int continuer=1;
     int j=1;
     SDL_Surface *coat_[500];
     char coat[500];
    for (j=1; j<=143 && continuer!=0 ;j+=3)
    {
        //affichage coat of arms
        sprintf(coat,"coat/%d.png",j);
        coat_[j]=IMG_Load(coat);
        SDL_BlitSurface(coat_[j],NULL,ecran,NULL);
        SDL_Flip(ecran);
        printf("[coat]->j=%d \n",j);
        if(j>1)
        {
            SDL_FreeSurface(coat_[j]);
            printf("Free[coat]->j=%d \n",j);
        }
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT: 
        continuer = 0; 
        break;            
        case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
        case SDLK_ESCAPE:continuer=0;break;
        case SDLK_BACKSPACE:continuer=0;break;}
       }
    }
}

image init_boutton(image img,char schema[500],float x,float y)
{
    img.rect.x=x;
    img.rect.y=y;
    strcpy(img.schema,schema);
    return img;
}

SDL_Surface* afficher_boutton(image img,SDL_Surface *ecran)
{
    SDL_Surface *image;
    image=IMG_Load(img.schema);
    SDL_BlitSurface(image,NULL,ecran,&img.rect);
    SDL_Flip(ecran);
    return image;
}

void soundclic()
{
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }
Mix_Chunk *soundclic;
soundclic = Mix_LoadWAV("button.wav");
Mix_PlayChannel(1, soundclic, 0);
}

void musique_menu()
{
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }
    
    Mix_Music *musique;
    musique = Mix_LoadMUS("musique.mp3");
    Mix_PlayMusic(musique, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
}
void bouttonplay(image newgame,SDL_Surface *ecran)
{
    newgame=init_boutton(newgame,"newgame.png",0,0);
    afficher_boutton(newgame,ecran);

}
void bouttonsettings(image settings,SDL_Surface *ecran)
{
    settings=init_boutton(settings,"settings.png",0,0);
    afficher_boutton(settings,ecran);

}
void bouttonhelp(image help,SDL_Surface *ecran)
{
    help=init_boutton(help,"help.png",0,0);
    afficher_boutton(help,ecran);

}
void bouttonexit(image exit,SDL_Surface *ecran)
{
    exit=init_boutton(exit,"exit.png",0,0);
    afficher_boutton(exit,ecran);

}
void affichagemenu(image menu,SDL_Surface *ecran)
{
    menu=init_boutton(menu,"menu.png",0,0);
    afficher_boutton(menu,ecran);
}

scrolling init_img(char nomimage[100],int x,int y)
{
scrolling scro;
scro.back=IMG_Load(nomimage);//load image
scro.positiond.x=x;//position x de bg
scro.positiond.y=y;//position y de bg
return scro;
}

void Scroll(SDL_Surface *ecran,scrolling scro,SDL_Rect camera)
{    
SDL_BlitSurface(scro.back,&camera,ecran,&scro.positiond);//afficher l image
SDL_Flip(ecran);//refresh ecran
}



