
#include <stdio.h>
#include  <stdlib.h>
 #include  <SDL/SDL.h>
 #include <SDL/SDL_image.h>
 #include <stdbool.h>

 bool CollisionBB( SDL_Surface *Player , SDL_Surface *C_Object , SDL_Rect position , SDL_Rect position1  )
 {
	 
	 if (((position.x+position.w == position1.x)&&(position.y+position.h==position1.y+position1.h))  || ((position.x == position1.x + position1.w)&&(position.y+position.h==position1.y+position1.h)) || ((position.y+position.h == position1.y)&&(position.x==position1.x)) || ((position.y == position1.y + position1.h)&&(position.x==position1.x))) 
     {
		 return true ; 
	 }
   else return false ; 
	 
	 
 }


int main()
{
SDL_Surface *screen , *image , *image1; 
SDL_Rect position , position1 ; 
SDL_Event event ; 
int done=0 ,x,y ; 




 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1920 ,  1080 ,  16 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0 ,  0 ,  255 )); 
  
     image  =  IMG_Load( "C.png" ); 
     if  ( image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     position.x  =  50 ; 
     position.y  =  50 ; 
     position.w  =  image -> w ; 
     position.h  =  image -> h ; 
         SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);
          image1  =  IMG_Load( "F.png" ); 
     if  ( image1  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     position1.x  =  600 ; 
     position1.y  =  500 ; 
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
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0 ,  0 ,  255 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_LEFT : 
							position.x-=50 ;
							
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0 ,  0 ,  255 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen); 
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_UP : 
							position.y-=50 ;
							
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0 ,  0 ,  255 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen); 
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_DOWN  : 
						    position.y+=50;
						    
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0 ,  0 ,  255 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
        

							break ;
						}

 if (CollisionBB(image,image1,position,position1))
 { 
	  SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  255 ,  255 ,  255 )); 
	            SDL_Flip(screen);  
	 }
						  
break ;  
}
}
}



return 0 ; 
}
