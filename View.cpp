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

void View::verificarInicioBatalla( list<int> listaPosicionesEnemigos, int x, int y, int *comienzaBatalla, int * xEnemigo, int * yEnemigo ){
	list<int>::iterator it2 = listaPosicionesEnemigos.begin();
	it2++;
	for( list<int>::iterator it = listaPosicionesEnemigos.begin(); it != listaPosicionesEnemigos.end(); it++ , it2 ++ ){
		if(x+3 + 32 >= *it2 && x+3 + 32 <= *it2 + 50 && ( (y + 5 >= *it && y + 5 <= *it + 50) || (y + 35 >= *it && y + 35 <= *it + 50 )) ){
			*xEnemigo = (*it-50)/50;
			*yEnemigo = (*it2-50)/50;
			*comienzaBatalla = 1;
			return;
		}
		else if(x-3  >= *it2 && x-3  <= *it2 + 50 && ( (y + 5 >= *it && y + 5 <= *it + 50) || (y + 35 >= *it && y + 35 <= *it + 50 )) ){
			*xEnemigo = (*it-50)/50;
			*yEnemigo = (*it2-50)/50;
			*comienzaBatalla = 1;
		}
		else if(y+3+40  >= *it && y+3+40  <= *it + 50 && ( (x + 5 >= *it2+1 && x + 5 <= *it2 + 49) || (x + 32 >= *it2+1 && x + 32 <= *it2 + 49 ))){
			*xEnemigo = (*it-50)/50;
			*yEnemigo = (*it2-50)/50;
			*comienzaBatalla = 1;
		}
		else if(y-3 >= *it && y-3  <= *it + 50 && ( (x + 5 >= *it2 && x + 5 <= *it2 + 50 ) || (x + 32 >= *it2 && x + 32 <= *it2 + 50 ))){
			*xEnemigo = (*it-50)/50;
			*yEnemigo = (*it2-50)/50;
			*comienzaBatalla = 1;
		}
		it++;
		it2++;
	}
}

void View::verificarLimites(list<int> listaLimites ,int * prohibidoArriba, int *  prohibidoAbajo, int *  prohibidoIzquierda, int *  prohibidoDerecha, int x, int y){
	list<int>::iterator it2 = listaLimites.begin();
	it2++;
	for( list<int>::iterator it = listaLimites.begin(); it != listaLimites.end(); it++ , it2 ++ ){
		if(x+3 + 32 >= *it2 && x+3 + 32 <= *it2 + 50 && ( (y + 5 >= *it && y + 5 <= *it + 50) || (y + 35 >= *it && y + 35 <= *it + 50 )) ){
			*prohibidoDerecha = 1;
		}
		if(x-3  >= *it2 && x-3  <= *it2 + 50 && ( (y + 5 >= *it && y + 5 <= *it + 50) || (y + 35 >= *it && y + 35 <= *it + 50 )) ){
			*prohibidoIzquierda = 1;
		}
		if(y+3+40  >= *it && y+3+40  <= *it + 50 && ( (x + 5 >= *it2+1 && x + 5 <= *it2 + 49) || (x + 32 >= *it2+1 && x + 32 <= *it2 + 49 ))){
			*prohibidoAbajo = 1;
		}
		if(y-3 >= *it && y-3  <= *it + 50 && ( (x + 5 >= *it2 && x + 5 <= *it2 + 50 ) || (x + 32 >= *it2 && x + 32 <= *it2 + 50 ))){
			*prohibidoArriba = 1;
		}
		it++;
		it2++;
	}
}

void View::ponerFondo(BITMAP * lobbyA, BITMAP * lobbyA2,BITMAP * lobbyB ,  BITMAP * lobbyB2, int fase, BITMAP * buffer){
	if(fase == 1){
		blit( lobbyA, buffer,0 ,0 , 0, 0, 800, 700);
	}
	else if( fase == 2){
		blit( lobbyA2, buffer,0 ,0 , 0, 0, 800, 700);
	}
	else if( fase == 3){
		blit( lobbyB, buffer,0 ,0 , 0, 0, 800, 700);
	}
	else if( fase == 4){
		blit( lobbyB2, buffer,0 ,0 , 0, 0, 800, 700);
	}
	else{
		blit( lobbyB2, buffer,0 ,0 , 0, 0, 800, 700);
	}
}


int View::cicloBatalla(BITMAP * buffer, BITMAP * fondoBatalla, BITMAP * enemigo, BITMAP * cursor, BITMAP *  numeros  ){
	int salirBatalla = 0;
	Enemigo enemigoBatalla("WembiePeque", 50, 2, 5 );
	do{
		if( mouse_x > 14 && mouse_x < 196 && mouse_y > 494  && mouse_y < 531 ){
 		  	if( mouse_b & 1  ){ //que diï¿½ click
 		  		enemigoBatalla.setVida(enemigoBatalla.getVida() - (controller.getJugador().getAtaque() - enemigoBatalla.getResistencia()));
				   do{
 		  			//para que el click sostenido no haga prrrrrrrrrrr
				}while(mouse_b & 1  );
				controller.cambiarVidaJugador( enemigoBatalla );
			}
		}
		blit( fondoBatalla, buffer,0 ,0 , 0, 0, 800, 700);
		masked_blit(enemigo, buffer, 1, 1, 0, 0, 372, 300 ); 
		controller.mostrarDatosPersonaje(numeros, buffer);
		controller.mostrarDatosEnemigo( numeros, buffer, enemigoBatalla );
		masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22 ); 
		blit(buffer, screen, 0, 0, 0, 0, 800, 700);
		if(enemigoBatalla.getVida() <= 0){
			return 1; //que ganó :D
		}
		else if(controller.getJugador().getVida() <= 0){
			return 0; //que perdió :(
		}
		if ( key[KEY_ESC] ) salirBatalla = 1;
	}while(salirBatalla != 1);
		
}


void View::cicloPrincipal(){
	BITMAP *buffer = create_bitmap(800, 700);
	BITMAP *prota  = load_bmp("personaje.bmp",NULL);
	BITMAP  *casa_a = load_bmp("fondoInicio.bmp",NULL);	//FONDO DE START EN BLANCO
	BITMAP * cursor = load_bmp( "cursor.bmp", NULL );		//imagen de cursor
	BITMAP * casa_b = load_bmp("fondoInicio2.bmp",NULL);		//FONDO DE START EN AMARILLO
	BITMAP *fondo;
	fondo = casa_a;
	BITMAP * lobbyA = load_bmp("nivel1Cerrado.bmp",NULL);
	BITMAP * lobbyA2 = load_bmp("nivel1Abierto.bmp", NULL);
	BITMAP * lobbyB = load_bmp("nivel2Cerrado.bmp", NULL);
	BITMAP * lobbyB2 = load_bmp("nivel2Abierto.bmp", NULL);
	BITMAP * enemigoBase = load_bmp("enemigoNivel1.bmp" , NULL);
	BITMAP * enemigoEnBatalla1 = load_bmp("enemigoEnBatallaNivel1.bmp" , NULL);
	BITMAP * numeros = load_bmp("numeros.bmp" , NULL);
	BITMAP * pantallaWin = load_bmp("pantallaWin.bmp", NULL);
	
	
	BITMAP * fondoBatalla = load_bmp("batallaNivel1.bmp" , NULL);
	BITMAP * prueba2 = load_bmp("espacio.bmp" , NULL);
	
	FONT * font = load_font("a.pcx", NULL, NULL);
	MIDI * sonidoSi = load_midi("musicaFondo.mid");
	bool salir, salir2;
	int x,y;
	int prohibidoArriba, prohibidoAbajo, prohibidoIzquierda, prohibidoDerecha;
	int comienzaBatalla;
	// inicializar vbles
	x = 60; //posicion en el mapa de personaje
	y = 60;
	salir = false;
	salir2 = false;
	int fase = 1;
	int faseEnemigo = 1;
	if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "") != 0){
		cout << ":D";
	}
	else{
		play_midi(sonidoSi, FALSE);
	}
	
	while (!salir2){
 	//clear_to_color(buffer, 0xaaaaaa);
 	//textout_ex(buffer, font, "sonido si :3", 50, 50, makecol(255, 0, 0), -1);
        if( mouse_x > 288 && mouse_x < 538 && mouse_y > 388 && mouse_y < 430 ){
 		  	blit( casa_b, buffer, 0, 0, 0, 0, 800, 700 ); //poner imagen
 		  	if( mouse_b & 1  ){ //que diï¿½ click
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
	int matrizNivel1[10][14]= {{0, 0, 0 ,0 ,2 ,0 ,2 ,1 ,0 ,2 ,0 ,1 ,0 ,0},
								{0, 1, 1 ,1 ,1 ,1 ,0 ,2 ,0 ,1 ,0 ,0 ,2 ,1},
								{0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
								{0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 2, 0, 1},
								{0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 1, 0, 1, 1},
								{0, 1, 2, 1, 0, 1, 0, 2, 0, 2, 1, 0, 1, 0},
								{0, 2, 0, 1, 0, 1, 2, 1, 1, 0, 1, 2, 1, 0},
								{0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0},
								{0, 1, 1, 1, 0, 2, 0, 1, 2, 1, 1, 0, 1, 0},
								{0, 2, 0, 2, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}};
								
	int matrizNivel2[10][14] = {{0, 0, 2, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2},
								{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
								{2, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 2, 1, 0},
								{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
								{2, 1, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 1, 2},
								{0, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
								{0, 1, 0, 1, 2, 0, 2, 1, 0, 2, 0, 1, 1, 2},
								{0, 1, 0, 2, 0, 1, 0, 2, 0, 1, 0, 0, 0, 0},
								{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 1},
								{0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 1, 1}};
	int ganoBatalla;
	int xEnemigoPixeles;
	int yEnemigoPixeles;
	list<int> listaLimites = controller.encontrarLimites(matrizNivel1);
	list<int> listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel1);
	while ( !salir ){ 
	
		if ( key[KEY_ESC] ) salir = true;
 		prohibidoArriba = 0;
 		prohibidoAbajo = 0;
 		prohibidoIzquierda = 0;
 		prohibidoDerecha = 0;
        ponerFondo(lobbyA, lobbyA2, lobbyB, lobbyB2, fase, buffer);
        controller.getEnemigo().ponerEnemigo(enemigoBase, buffer, listaPosicionesEnemigos);
        controller.mostrarDatosPersonaje(numeros, buffer);
        controller.mostrarInventario(buffer);
        
 		verificarLimites(listaLimites, &prohibidoArriba, &prohibidoAbajo, &prohibidoIzquierda, &prohibidoDerecha, x, y );
        controller.getJugador().teclas(prota, buffer, &x, &y, prohibidoDerecha, prohibidoIzquierda, prohibidoAbajo, prohibidoArriba );
        controller.verificarFase(&x, &y, &fase);
        if(fase == 3 ){
        	listaLimites = controller.encontrarLimites(matrizNivel2);
        	listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel2);
		}
		if(fase == 5){
			while(!key[KEY_ESC]){
				blit( pantallaWin, buffer,0 ,0 , 0, 0, 800, 700);
				blit(buffer, screen, 0, 0, 0, 0, 800, 700);
			}
		}
		//controller verificar fase para batalla
		
		
		verificarInicioBatalla(listaPosicionesEnemigos, x, y, &comienzaBatalla, &xEnemigoPixeles, &yEnemigoPixeles );
 		if( comienzaBatalla == 1 ){
 			
 				ganoBatalla = cicloBatalla ( buffer, fondoBatalla, enemigoEnBatalla1, cursor, numeros);
 				if(ganoBatalla == 1){
 					//celebra :D
 					if(fase == 1 || fase == 2){
 						matrizNivel1[xEnemigoPixeles][yEnemigoPixeles] = 0;
 						listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel1);
					 }
					 else{
					 	matrizNivel2[xEnemigoPixeles][yEnemigoPixeles] = 0;
					 	listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel2);
					 }
					 controller.darItemAleatorio();
					 
					 
 					
				 }
				 else{
				 	x = 55;
				 	y = 55;
				 	controller.reiniciarVida();
				 	controller.vaciarInventario();
				 }
		 }
		 comienzaBatalla = 0;
		 
 		//Hacer lo de enemigo(arriba)
		
	
        // limites
        if ( x < 0 ) x = 0;
        if ( x > 800 ) x = 800;
        if ( y < 0 ) y = 0;
        if ( y > 600 ) y = 600;          
       masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22 ); 
       blit(buffer, screen, 0, 0, 0, 0, 800, 700);
       rest(10);
       // tecla de salida
    }  
	destroy_bitmap(prota);
	destroy_bitmap(buffer);
}
