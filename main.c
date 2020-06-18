/**
*@file main.c
*@brief  testing program
*@author C team
*@date may 13, 2020
*
* testing program for map
*/

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define W_Screen 800
#define H_Screen 600


#define SPEED 5


#define SPRITE_H 148
#define SPRITE_W 102
#define MAX_FRAMES 6 



#define W_BackgImg 259
#define H_BackgImg 194


int main(int argc, char *argv[])
{
SDL_Event event;
 
int run=1;

 
    SDL_Surface *screen = NULL, *imageDeFond = NULL ,*detective =NULL, *imageDeFond1=NULL ,*detective1 =NULL;;

    SDL_Rect positionFond;
    SDL_Rect positionFond1;
    SDL_Rect positiondetective;
    SDL_Rect positiondetective1;
   
 
  screen = SDL_SetVideoMode(1300, 400, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("mini Map", NULL);



positionFond.x =1200;
positionFond.y =370 ;
positiondetective.x = 1200;
positiondetective.y =380;

positionFond1.x =0;
positionFond1.y =0 ;
positiondetective1.x = 100;
positiondetective1.y =250;
SDL_Init(SDL_INIT_VIDEO);


   
    imageDeFond = SDL_LoadBMP("background.bmp");
    imageDeFond1 = SDL_LoadBMP("Flat_Game_Background_1.bmp");
    detective = IMG_Load("testpt.png");
    detective1 = IMG_Load("test.png");
    SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0)) ;
    SDL_BlitSurface(imageDeFond1, NULL, screen, &positionFond1);
    SDL_BlitSurface(detective1, NULL, screen, &positiondetective1);
    SDL_BlitSurface(imageDeFond, NULL,screen, &positionFond);
    SDL_BlitSurface(detective, NULL, screen, &positiondetective);
    SDL_Flip(screen);



 while(run)
{


while (SDL_PollEvent(&event))
       {//while event
 switch(event.type)
        {//switch event
            case SDL_QUIT:
		{// case sdl quit
            run = 0;
            
		}
case SDL_KEYDOWN:
                {
 switch (event.key.keysym.sym)
            {
				case SDLK_RIGHT:
				{
positiondetective.x+=25;
positiondetective1.x+= 300;
SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0)) ;
SDL_BlitSurface(imageDeFond1, NULL, screen, &positionFond1);
SDL_BlitSurface(detective1, NULL, screen, &positiondetective1);
    SDL_BlitSurface(imageDeFond, NULL, screen, &positionFond);
SDL_BlitSurface(detective, NULL, screen, &positiondetective);
  


    SDL_Flip(screen);

}
                                 case SDLK_LEFT:
{

 positiondetective.x-=20;
positiondetective1.x-=250;
 

SDL_BlitSurface(imageDeFond1, NULL, screen, &positionFond1);
SDL_BlitSurface(detective1, NULL, screen, &positiondetective1);
SDL_BlitSurface(imageDeFond, NULL, screen, &positionFond);
SDL_BlitSurface(detective, NULL, screen, &positiondetective);


    SDL_Flip(screen);
}
}


}
}

}
}

SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(detective);
SDL_FreeSurface(imageDeFond1);
SDL_FreeSurface(detective1);
    SDL_Quit();

    return EXIT_SUCCESS;
}
