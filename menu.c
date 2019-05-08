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
        SDL_PollEvent(&event);
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

//////////////////////////////////////////////////////////////////////////////
void moving_right(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
if  (positionmilieu->x>=400 && positionFond->x<=6000)
            positionFond->x += 25;
        else if (positionmilieu->x<=750) 
            positionmilieu->x +=65;

}

void moving_left(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
if (positionmilieu->x<=180 && positionFond->x>=10)
            positionFond->x -= 25;
      else if (positionmilieu->x>=0)
      positionmilieu->x -= 65;

}

void gravity(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso,int gravity){
 while(positionmilieu->y<gravity){
positionmilieu->y+=10;
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(imageDePerso,NULL, ecran,positionmilieu);     
    SDL_Flip(ecran);
}}


void animationright(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
SDL_Surface *image1=NULL, *image2=NULL;
image1=IMG_Load("attachments/1.png");
image2=IMG_Load("attachments/2.png");
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
SDL_BlitSurface(image1,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);

SDL_Delay(150);
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image2,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(150);
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);

}


void animationleft(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
SDL_Surface *image1=NULL, *image2=NULL;
image1=IMG_Load("attachments/3.png");
image2=IMG_Load("attachments/4.png");
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
SDL_BlitSurface(image1,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);

SDL_Delay(150);
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image2,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(150);
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);
}


void jump(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
for(int i=0;i<20;i++){
positionmilieu->y-=10;
            
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(imageDePerso,NULL, ecran, positionmilieu);
    SDL_Flip(ecran);
}}


////////////////////////////////////////////////////////////////////////////////////

ennemie initialiser_ennemie(ennemie e)
{

 e.direction=1;/* indice for chad el left */

 e.pos.x=700;
 e.pos.y=400;
 e.pos.w=137;
 e.pos.h=64;
/*loading image of walking 22 33  left 2 3 right */
 e.tab[0] = IMG_Load("22.png");

 e.tab[1] = IMG_Load("33.png");

 e.tab[2] = IMG_Load("2.png");

 e.tab[3] = IMG_Load("3.png");

/* loading image of running 44 55 left */
 e.tab2[0] = IMG_Load("44.png");

 e.tab2[1] = IMG_Load("55.png");


/*variable so we could save the time */
 e.p1=0;
 e.p2=0;

 e.etat=0; /*for walking */
 e.etat2=0;/*for running left */
 e.etat3=0; /*for running right */


return e;
}

ennemie deplacer_ennemie( ennemie e ,SDL_Surface *ecran, SDL_Rect pos,SDL_Rect positionperso)
{int i=0;
// calculer distance entre personnage et ennemie 
int d=e.pos.x-(positionperso.x+positionperso.w);


if(((d<=0)&&(d>=-180))&&(e.pos.y>=positionperso.y))
{


printf("collision \n");
return e;
}
/*********************************************************************************************************************************/

/*personnage a gauche de l'ennemie distance positive */
if((d>=0)&&(d<=200))
{
if((d>=0)&&(d<=200))
{
e.p1 = SDL_GetTicks();
if (e.p1 - e.p2 >=500 )
{
e.direction=1;	/* chad yisar*/
if((e.direction==1)&&(e.pos.x>positionperso.x)){e.pos.x-=25;}/* perso mazel a gauche de enemie enimie yoriblou yijri wra */
else if((e.direction==1)&&(e.pos.x<=positionperso.x)){e.direction=0;
e.pos.x+=25;} /* perso fat enemmie distance negative hkayit x we y  */



SDL_BlitSurface(e.tab2[e.etat2], NULL, ecran, &e.pos);
printf("pos e :x %d \n",e.pos.x );
printf("etat running left  %d \n",e.etat2 );
printf("d %d \n",d );
SDL_Flip(ecran);
e.p2=e.p1;
if(e.etat2<1){e.etat2++;} /*  yibda taswira 2 we mba3id 3  2 3 2 3 2 3 2 3  */
else{e.etat2=0;}
}
}
return e;
}
  /******************************************************************************************************************************************************************/

/******************************************************************************************************************************************/
else { /*  kan ma 9robtich lil ennimie yimchy wala ki tnakiz fou9ou we tfoutou */
e.p1 = SDL_GetTicks();
if (e.p1 - e.p2 >=500 )
{
if((e.direction==1)&&(e.pos.x>pos.y)){e.pos.x-=10;}
else if((e.direction==1)&&(e.pos.x<=pos.y)){e.direction=0;e.etat=2;e.pos.x+=10;}
else if((e.direction==0)&&(e.pos.x<pos.x)){e.pos.x+=10;}
else {e.direction=1;e.etat=0;}


SDL_BlitSurface(e.tab[e.etat], NULL, ecran, &e.pos);
printf(" pos  pos e :x %d \n",e.pos.x );
printf("etat walking  %d \n",e.etat );
printf("direction %d \n",e.direction );
printf("distance %d \n",d );
SDL_Flip(ecran);
e.p2=e.p1;
if((e.direction==1)&&(e.etat<1)){e.etat++;} 
else if(e.etat==1){e.etat=0;}
else if((e.direction==0)&&(e.etat<3)){e.etat++;}
else{e.etat=2;}

}

return e;
}

}




//////////////////////////////////////////////////////////////
images init_image(char nameofpicture[100],int x,int y)
{
images image;
image.img=IMG_Load(nameofpicture);//load image
image.pos.x=x;//position x de bg
image.pos.y=y;//position y de bg
return image;
}
void affichage(SDL_Surface *ecran,images image)
{
SDL_BlitSurface(image.img,NULL,ecran,&image.pos);
}

void librer_image(images image)
{
 SDL_FreeSurface(image.img);//Liberer memoire
}
