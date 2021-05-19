#include <iostream> 
#include <allegro.h>
#include "View.h"

using std::cin;
using std::cout;
using std::endl;
 

int main() 
{ 
	View view;
	view.inicializarAllegro();
 
 BITMAP *buffer = create_bitmap(800, 600);
 BITMAP *prota  = load_bmp("personaje3.bmp",NULL);
 BITMAP  *casa_a = load_bmp("fondoIniciobmp.bmp",NULL);	//FONDO DE START EN BLANCO
 BITMAP * cursor = load_bmp( "cursor.bmp", NULL );		//imagen de cursor
 BITMAP * casa_b = load_bmp("fondoInicio2.bmp",NULL);		//FONDO DE START EN AMARILLO
 BITMAP *fondo;
 fondo = casa_a;
 BITMAP * lobbyA = load_bmp("Nivel1.bmp",NULL);
 bool salir, salir2;
 int x,y;
  
 // inicializar vbles
 x = 60; //posicion en el mapa de personaje
 y = 60;
 salir = false;
 salir2 = false;
 while (!salir2){
 	//clear_to_color(buffer, 0xaaaaaa);
 	
         if( mouse_x > 288 && mouse_x < 538 && mouse_y > 388 && mouse_y < 430 ){
 		  	blit( casa_b, buffer, 0, 0, 0, 0, 800, 600 ); //poner imagen
 		  	if( mouse_b & 1  ){ //que dió click
 		  		
 		  		blit( lobbyA, buffer,0 ,0 , 0, 0, 800, 600); 
 		  		masked_blit(prota, buffer, 0,130, x, y, 32,40); //crea blit
 		  		salir2 = true;
			   }
		   }
		
		  else{
		  blit( casa_a, buffer,0 ,0 , 0, 0, 800, 600); //muestra pantalla de start en blanco
		}
		masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22 );
         if ( key[KEY_ESC] ) salir2 = true;
         blit( buffer, screen, 0, 0, 0, 0, 800, 600 ); //actualiza pantalla
        
 }
 
 while ( !salir ){ 
          //clear_to_color(buffer, 0xaaaaaa);
        blit( lobbyA, buffer,0 ,0 , 0, 0, 800, 600); 
 		masked_blit(prota, buffer, 0,130, x, y, 32,40);
          
          // teclas control usuario
          if ( key[KEY_UP] && y > 50 )
          {
          	masked_blit(prota, buffer, 0,85, x, y, 32,40);
               y-= 3;
          }
          if ( key[KEY_DOWN] && y < 510  )
          {
          	masked_blit(prota, buffer, 0,130, x, y, 32,40);
               y+= 3;
          }
          if ( key[KEY_LEFT] && x > 50 )
          {
          	masked_blit(prota, buffer, 0,40, x, y, 32,40);
               x-= 3;
          }
          if ( key[KEY_RIGHT]  && x < 720 )
          {
          	masked_blit(prota, buffer, 0,0, x, y, 32,40);
               x+= 3;   
               if( ( x > 830 && y > 230 ) ){
          		x+=3;
		  		}
          }  
          if( ( x > 830 && y > 230 ) ){
          	x+=3;
		  }
		  //Condional de entrada FALTA!      
          // limites
          if ( x < 0 ) x = 0;
          if ( x > 800 ) x = 800;
          if ( y < 0 ) y = 0;
          if ( y > 600 ) y = 600;          
        
        
           
       blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        
       rest(10);
       // tecla de salida
       if ( key[KEY_ESC] ) salir = true;
     
    }  
   
 destroy_bitmap(prota);
 destroy_bitmap(buffer);
 return 0;

}
END_OF_MAIN();
