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
	FONT * font = load_font("a.pcx", NULL, NULL);
	MIDI * sonidoSi = load_midi("musicaFondo.mid");
	bool salir, salir2;
	int x,y;
	int prohibidoArriba, prohibidoAbajo, prohibidoIzquierda, prohibidoDerecha;
	// inicializar vbles
	x = 60; //posicion en el mapa de personaje
	y = 60;
	salir = false;
	salir2 = false;
	int fase = 1;
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
 		  	if( mouse_b & 1  ){ //que di� click
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
								{2, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 2, 0, 1},
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
	list<int> listaLimites = controller.encontrarLimites(matrizNivel1);
	list<int> listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel1);
	while ( !salir ){ 
 		prohibidoArriba = 0;
 		prohibidoAbajo = 0;
 		prohibidoIzquierda = 0;
 		prohibidoDerecha = 0;
        ponerFondo(lobbyA, lobbyA2, lobbyB, lobbyB2, fase, buffer);
        controller.getEnemigo().ponerEnemigo(enemigoBase, buffer, listaPosicionesEnemigos);
 		verificarLimites(listaLimites, &prohibidoArriba, &prohibidoAbajo, &prohibidoIzquierda, &prohibidoDerecha, x, y );
        controller.getJugador().teclas(prota, buffer, &x, &y, prohibidoDerecha, prohibidoIzquierda, prohibidoAbajo, prohibidoArriba );
        controller.verificarFase(&x, &y, &fase);
        if(fase == 3 ){
        	listaLimites = controller.encontrarLimites(matrizNivel2);
        	listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel2);
		}
        // limites
        if ( x < 0 ) x = 0;
        if ( x > 800 ) x = 800;
        if ( y < 0 ) y = 0;
        if ( y > 600 ) y = 600;          
       masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22 ); //borrar
       blit(buffer, screen, 0, 0, 0, 0, 800, 700);
       rest(10);
       // tecla de salida
    }  
	destroy_bitmap(prota);
	destroy_bitmap(buffer);
}
