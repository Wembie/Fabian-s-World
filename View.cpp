#include "View.h"

View::View(){
    controller = Controller();
}

void View::inicializarAllegro(){
	allegro_init();
 	install_keyboard();
 	install_mouse();
 	
	//CREAMOS VENTANA
 	set_color_depth(32);
 	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 700, 0, 0);
}

void View::cicloPrincipal(){
 
 BITMAP *buffer = create_bitmap(800, 700);
 BITMAP *prota  = load_bmp("personaje3.bmp",NULL);
 BITMAP  *casa_a = load_bmp("fondoIniciobmp.bmp",NULL);	//FONDO DE START EN BLANCO
 BITMAP * cursor = load_bmp( "cursor.bmp", NULL );		//imagen de cursor
 BITMAP * casa_b = load_bmp("fondoInicio2.bmp",NULL);		//FONDO DE START EN AMARILLO
 BITMAP *fondo;
 fondo = casa_a;
 BITMAP * lobbyA = load_bmp("Nivel1Abierto.bmp",NULL);
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
 		  	blit( casa_b, buffer, 0, 0, 0, 0, 800, 700 ); //poner imagen
 		  	if( mouse_b & 1  ){ //que dió click
 		  		
 		  		blit( lobbyA, buffer,0 ,0 , 0, 0, 800, 700); 
 		  		controller.getJugador().moverJugador(prota, buffer, x, y, 130);
 		  		salir2 = true;
			   }
		   }
		
		  else{
		  blit( casa_a, buffer,0 ,0 , 0, 0, 800, 700); //muestra pantalla de start en blanco
		}
		masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22 );
         if ( key[KEY_ESC] ) salir2 = true;
         blit( buffer, screen, 0, 0, 0, 0, 800, 700 ); //actualiza pantalla
        
 }
 
 int matrizNivel1[10][14]= {{0,1,0,0,0,0,0,1,0,0,0,1,0,0},
 						    {0,1,1,1,1,1,0,0,0,1,0,0,0,1},
						    {0,1,0,0,0,1,1,1,1,1,1,1,0,0},
						    {0,1,0,1,0,1,0,0,0,1,0,0,0,1},
						    {0,1,0,1,0,0,0,1,0,1,1,0,1,1},
							{0,1,0,1,0,1,0,0,0,0,1,0,1,0},
							{0,0,0,1,0,1,0,1,1,0,1,0,1,0},
							{0,1,0,1,1,1,0,1,0,0,1,0,1,0},
							{0,1,1,1,0,0,0,1,0,1,1,0,1,0},
							{0,0,0,0,0,1,0,1,0,0,0,0,0,0}};
list<int> listaLimites = controller.encontrarLimites(matrizNivel1);
 
 while ( !salir ){ 
        blit( lobbyA, buffer,0 ,0 , 0, 0, 800, 700); 
 		controller.getJugador().moverJugador(prota, buffer, x, y, 130);
 		//por implementar :D
        controller.getJugador().teclas(prota, buffer, &x, &y);
          // teclas control usuario
          
		  //Condional de entrada FALTA!      
          // limites
          if ( x < 0 ) x = 0;
          if ( x > 800 ) x = 800;
          if ( y < 0 ) y = 0;
          if ( y > 600 ) y = 600;          
        
        
           masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22 ); //borrar
       blit(buffer, screen, 0, 0, 0, 0, 800, 700);
        
       rest(10);
       // tecla de salida
       if ( key[KEY_ESC] ) salir = true;
     
    }  
   
 destroy_bitmap(prota);
 destroy_bitmap(buffer);
}
