#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
    char schema[500];
    SDL_Rect rect;
}image;

typedef struct
{
	SDL_Surface *back;//wyn chnachargo image
	SDL_Rect positiond;// Position mta3 background
}scrolling;


SDL_Surface* openwindow(SDL_Surface *ecran,int h,int w);

image init_boutton(image img,char schema[500],float x,float y);

scrolling init_img(char nomimage[100],int x,int y);

void Scroll(SDL_Surface *ecran,scrolling scro,SDL_Rect camera);

SDL_Surface* afficher_boutton(image img,SDL_Surface *ecran);

void soundclic();
void affichagecoat(SDL_Surface *ecran);
void musique_menu();
void affichagemenu(image menu,SDL_Surface *ecran);
void bouttonplay(image newgame,SDL_Surface *ecran);
void bouttonsettings(image settings,SDL_Surface *ecran);
void bouttonhelp(image help,SDL_Surface *ecran);
void bouttonexit(image exit,SDL_Surface *ecran);
void play(image level1,SDL_Surface *ecran,SDL_Rect camera);

#endif
