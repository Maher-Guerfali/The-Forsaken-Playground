#include <stdio.h>
#include  <stdlib.h>
 #include  <SDL/SDL.h>
 #include <SDL/SDL_image.h>
 #include <stdbool.h>

 


int main()
{
SDL_Surface *screen , *image , *image1; 
SDL_Rect position , position1 ; 
SDL_Event event,event2 ; 
int done=0 ,x,y,donee=0 ; 




 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1920 ,  1080 ,  16 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102 )); 
  
     image  =  IMG_Load( "2.png" ); 
     if  ( image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     position.x  =  80 ; 
     position.y  =  80 ; 
     position.w  =  image -> w ; 
     position.h  =  image -> h ; 
         SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);



//img 2

          image1  =  IMG_Load( "1.png" ); 
     if  ( image1  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     position1.x  =  250 ; 
     position1.y  =  250 ; 
     position1.w  =  image1 -> w ; 
     position1.h  =  image1 -> h ; 
         SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
          


      while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
                 
             case SDL_KEYDOWN : 
                     switch( event.key.keysym.sym )
                        {
							case SDLK_RIGHT : 
							position.x+=50;
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_LEFT : 
							position.x-=50 ;
							
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen); 
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_UP : 
							position.y-=50 ;
							
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102)); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen); 
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_DOWN  : 
						    position.y+=50;
						    
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
        

							break ;

					case SDLK_d : 
							position1.x+=50;
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102 )); 
							             SDL_BlitSurface(image1, NULL, screen, &position1);
					  SDL_Flip(screen);
						   SDL_BlitSurface(image, NULL , screen, &position);
					  SDL_Flip(screen);
							break ; 
							case SDLK_q : 
							position1.x-=50 ;
							
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102 )); 
							             SDL_BlitSurface(image1, NULL, screen, &position1);
          SDL_Flip(screen); 
                   SDL_BlitSurface(image, NULL , screen, &position);
          SDL_Flip(screen);
							break ; 
							case SDLK_z : 
							position1.y-=50 ;
							
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102)); 
							             SDL_BlitSurface(image1, NULL, screen, &position1);
          SDL_Flip(screen); 
                   SDL_BlitSurface(image, NULL , screen, &position);
          SDL_Flip(screen);
							break ; 
							case SDLK_s  : 
						    position1.y+=50;
						    
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  50 ,  102 )); 
							             SDL_BlitSurface(image1, NULL, screen, &position1);
          SDL_Flip(screen);
                   SDL_BlitSurface(image, NULL , screen, &position);
          SDL_Flip(screen);
        

							break ;
						}

						}

						  
break ;  
}
}



 



return 0 ; 
}
