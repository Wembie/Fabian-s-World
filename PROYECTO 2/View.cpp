#include "View.h"
//Iniciamos el controller pa controlar xd, a
View::View(){
    controller = Controller();
}
//Inicializacion del allegro
void View::inicializarAllegro(){
	allegro_init();
	install_keyboard();
	install_mouse();
	//CREAMOS VENTANA
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 700, 0, 0);
}
//Verifica donde esta el enemigo, esto se hace con la listaPosicionesEnemigos, que en controller la funcion es (encontrarPosicionesEnemigos), ya con esta lista, recorre con dos iteradores, el primero es donde empieza la lista de enemigos una posicion mas, y el otro iterador es donde empieza la lista de enemigos. Luego se verifica las posiciones en "x y "y" con sus diferentes dimensiones, i si lo encuentra va a colocar comienzaBatalla en 1, esto se hace con apuntador para que mas abajo se pueda verificar, al igual que xEnemigo y yEnemigo (posiciones del enemigo)
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
//Verifica las colisiones dependiendo de las prohibiciones recibidas por parametro
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
//Pone el fondo del nivel dependiendo de la fase en que vaya
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
//funcion que retorna un 1 si gana o un 0 si pierde, y el ciclo de batalla obviamente
int View::cicloBatalla(BITMAP * buffer, BITMAP * fondoBatalla, BITMAP * enemigo, BITMAP * cursor, BITMAP *  numeros, BITMAP * numeritos, int fase ){
	int salirBatalla = 0;
	Enemigo enemigoBatalla;
	if(fase == 1 || fase == 2){ //se crea un enemigo dependiendo del nivel
		enemigoBatalla = Enemigo("WembiePeque", 50, 2, 2 );
	}
	else{
		enemigoBatalla = Enemigo("WembieMediano", 100, 5, 4 );
	}
	
	do{
		controller.usarInventario( &enemigoBatalla );
		if( mouse_x > 14 && mouse_x < 196 && mouse_y > 494  && mouse_y < 531 ){ //Boton Atacar
 		  	if( mouse_b & 1  ){ //que di� click
 		  		if(controller.getJugador().getAtaque() >= enemigoBatalla.getResistencia() ){
 		  			enemigoBatalla.setVida(enemigoBatalla.getVida() - (controller.getJugador().getAtaque() - enemigoBatalla.getResistencia()));
				   }
 		  		
				do{
 		  			//para que el click sostenido no haga prrrrrrrrrrr
				}while( mouse_b & 1  );
				controller.cambiarVidaJugador( enemigoBatalla );
			}
		}
		//HABILIDADES
		else if( mouse_x > 216 && mouse_x < 313 && mouse_y > 494  && mouse_y < 531 ){ //Boton Fuego
			if( mouse_b & 1  ){
				if( controller.getJugador().getMana() > 0 && ( controller.getJugador().getMana() - 25 ) >= 0 ){
					enemigoBatalla.setVida(enemigoBatalla.getVida() - ( 30 - enemigoBatalla.getResistencia()));
					do{
 		  			//para que el click sostenido no haga prrrrrrrrrrr
					}while( mouse_b & 1  );
					controller.cambiarMana( 25 );
				}
				
			}
		}
		else if( mouse_x > 216 && mouse_x < 313 && mouse_y > 552 && mouse_y < 589 ){ //Boton UTIL
			if( mouse_b & 1  ){
				if( controller.getJugador().getMana() > 0 && ( controller.getJugador().getMana() - 75 ) >= 0 ){	
					enemigoBatalla.setVida(enemigoBatalla.getVida() - ( 100 - enemigoBatalla.getResistencia()));
					do{
 		  			//para que el click sostenido no haga prrrrrrrrrrr
					}while( mouse_b & 1  );
					controller.cambiarMana( 75 );
				}
			}
		}		
		blit( fondoBatalla, buffer,0 ,0 , 0, 0, 800, 700);
		masked_blit(enemigo, buffer, 1, 1, 0, 0, 372, 300 ); 
		controller.mostrarDatosPersonaje(numeros, buffer);
		controller.mostrarDatosEnemigo( numeros, buffer, enemigoBatalla );
		controller.mostrarInventario(buffer, numeritos);
		masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22 ); 
		blit(buffer, screen, 0, 0, 0, 0, 800, 700);
		if(enemigoBatalla.getVida() <= 0){
			return 1; //que gan� :D
		}
		else if(controller.getJugador().getVida() <= 0){
			return 0; //que perdi� :(
		}
		if ( key[KEY_ESC] ) salirBatalla = 1;
	}while(salirBatalla != 1);
		
}


void View::cicloPrincipal(){\

	//Inicializacion de BITMAPS
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
	BITMAP * enemigoBase2 = load_bmp("enemigoNivel2.bmp" , NULL);
	BITMAP * enemigoEnBatalla2 = load_bmp("enemigoEnBatallaNivel2.bmp" , NULL);
	BITMAP * numeros = load_bmp("numeros.bmp" , NULL);
	BITMAP * pantallaWin = load_bmp("pantallaWin.bmp", NULL);
	BITMAP * numeritos = load_bmp("numeritos.bmp", NULL);
	BITMAP * fondoBatalla = load_bmp("batallaNivel1.bmp" , NULL);
	//Musica
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
	//Lobby de start 
	while (!salir2){
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
	
	//Matriz nivel 1
	int matrizNivel1[10][14]=  {{0, 0, 0 ,0 ,2 ,0 ,2 ,1 ,0 ,2 ,0 ,1 ,0 ,0},
								{0, 1, 1 ,1 ,1 ,1 ,0 ,2 ,0 ,1 ,0 ,0 ,2 ,1},
								{0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
								{0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 2, 0, 1},
								{0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 1, 0, 1, 1},
								{0, 1, 2, 1, 0, 1, 0, 2, 0, 2, 1, 0, 1, 0},
								{0, 2, 0, 1, 0, 1, 2, 1, 1, 0, 1, 2, 1, 0},
								{0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0},
								{0, 1, 1, 1, 0, 2, 0, 1, 2, 1, 1, 0, 1, 0},
								{0, 2, 0, 2, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}};
	//Matriz nivel 2							
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
	//Empieza el ciclo del juego como tal
	while ( !salir ){ 
	
		if ( key[KEY_ESC] ) salir = true;
 		prohibidoArriba = 0;
 		prohibidoAbajo = 0;
 		prohibidoIzquierda = 0;
 		prohibidoDerecha = 0;
        ponerFondo(lobbyA, lobbyA2, lobbyB, lobbyB2, fase, buffer);
        if(fase == 1 || fase == 2){// segun cada fase coloca enemigos de un item u otro
        	controller.getEnemigo().ponerEnemigo(enemigoBase, buffer, listaPosicionesEnemigos);
		}
        else{ //Lo mismo de arriba, pero en fase del nivel 2
        	controller.getEnemigo().ponerEnemigo(enemigoBase2, buffer, listaPosicionesEnemigos);
		}
        controller.mostrarDatosPersonaje(numeros, buffer);
        controller.mostrarInventario(buffer, numeritos);
        
 		verificarLimites(listaLimites, &prohibidoArriba, &prohibidoAbajo, &prohibidoIzquierda, &prohibidoDerecha, x, y );
        controller.getJugador().teclas(prota, buffer, &x, &y, prohibidoDerecha, prohibidoIzquierda, prohibidoAbajo, prohibidoArriba );
        controller.verificarFase(&x, &y, &fase);
        if(fase == 3 ){// cuando pasa al nivel 2 se cambia de matriz y con ello la posicion de los enemigos
        	listaLimites = controller.encontrarLimites(matrizNivel2);
        	listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel2);
		}
		if(fase == 5){ // si la fase esta en 5 es decir que gano y se muestra dicha pantalla
			while(!key[KEY_ESC]){
				blit( pantallaWin, buffer,0 ,0 , 0, 0, 800, 700);
				blit(buffer, screen, 0, 0, 0, 0, 800, 700);
			}
		}
		//controller verificar fase para batalla
		
		
		verificarInicioBatalla(listaPosicionesEnemigos, x, y, &comienzaBatalla, &xEnemigoPixeles, &yEnemigoPixeles );
 		if( comienzaBatalla == 1 ){ //Si encontro un enemigo por donde sea y lo toco
 				if (fase == 1 || fase == 2){ //Y si la fase es 1 o 2 (Nivel 1) va a colocar el enemigo correspondiente, en este caso es del nivel 1
 					ganoBatalla = cicloBatalla ( buffer, fondoBatalla, enemigoEnBatalla1, cursor, numeros, numeritos, fase);
				 }
 				else{ //Lo mismo de arriba, pero con el nivel 2
 					ganoBatalla = cicloBatalla ( buffer, fondoBatalla, enemigoEnBatalla2, cursor, numeros, numeritos, fase);
				 }
 				if(ganoBatalla == 1){
 					//celebra :D
 					if(fase == 1 || fase == 2){//dependiendo de la fase se elimina un enemigo u otro
 						matrizNivel1[xEnemigoPixeles][yEnemigoPixeles] = 0;
 						listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel1);
					 }
					 else{ // Lo mismo de arriba, pero con el nivel 2
					 	matrizNivel2[xEnemigoPixeles][yEnemigoPixeles] = 0;
					 	listaPosicionesEnemigos = controller.encontrarPosicionesEnemigos(matrizNivel2);
					 }
					 controller.darItemAleatorio();				
				 }
				 else{
					//se devuelve al personaje en la posicion original y se le reinicia la vida y chao inventario
				 	x = 55;
				 	y = 55;
				 	controller.reiniciarVida(); //F por la vida
				 	controller.vaciarInventario(); //F por el inventario
				 }
		 }
		 comienzaBatalla = 0;//se reestablece que ya no esta en batalla
		
		/////////////////////////////////////////////////////
		//SI LEES ESTO SIGINIFICA QUE NOS VAS A EXONERAR :D//
		/////////////////////////////////////////////////////
	
        // limites de los bordes para que el personaje no se salga del cuadrado de los bloques
        if ( x < 0 ) x = 0;
        if ( x > 800 ) x = 800;
        if ( y < 0 ) y = 0;
        if ( y > 600 ) y = 600;  
		//Se muestra el cursor y luego actualiza la pantalla
        masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22 ); 
        blit(buffer, screen, 0, 0, 0, 0, 800, 700); //actualiazar pantalla de todo lo acumulado en el buffer
        rest(10);//se demora 10 milisegundos en hacer lo anterior
       // tecla de salida
    }  
	//muricion de los bitsmaps por q ya se acabo el game :c
	destroy_bitmap(prota);
	destroy_bitmap(buffer);
}