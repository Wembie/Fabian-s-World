#include "Controller.h"
Controller :: Controller(){

}

Jugador Controller::getJugador(){
	return this->jugador;
}

Enemigo Controller::getEnemigo(){
	return this->enemigo;
}

Personaje Controller::getPersonaje(){
	return this->personaje;
}


list<int> Controller:: encontrarLimites( int matrizNivel[10][14] ){
	int i, j;
	list <int> listaLimitesProhibidos;
	for(i = 0; i < 10; i++ ){
		for(j = 0; j < 14; j++){
			if (matrizNivel[i][j] == 1){
				listaLimitesProhibidos.push_back(i*50+50);
				listaLimitesProhibidos.push_back(j*50+50);
			}
		}
	}
	return listaLimitesProhibidos;
}

list<int> Controller:: encontrarPosicionesEnemigos( int matrizNivel[10][14] ){
	int i, j;
	list <int> listaEnemigos;
	for(i = 0; i < 10; i++ ){
		for(j = 0; j < 14; j++){
			if (matrizNivel[i][j] == 2){
				listaEnemigos.push_back(i*50+50);
				listaEnemigos.push_back(j*50+50);
			}
		}
	}
	return listaEnemigos;
}

void Controller::verificarFase(int * x, int * y, int * faseActual ){
	if(*faseActual == 1 &&  *x >= 150 && *x <= 200 && *y >= 50 && *y <= 100  ){
		*faseActual += 1;
	}
	else if(*faseActual == 2 && *x >= 50 && *x <= 100 && *y >= 500 && *y <= 550 ){
		*faseActual += 1;
		*x = 52;
		*y = 52;
	}
	else if(*faseActual == 3 && *x >= 150 && *x <= 200 && *y >= 150 && *y <= 200  ){
		*faseActual += 1;
	}
	else if(*faseActual == 4 && *x >= 50 && *x <= 100 && *y >= 150 && *y <= 200  ){
		*faseActual += 1;
	}
}


void Controller::verificarFaseBatalla(int * x, int * y, int * faseActualBatalla ){
	if(*faseActualBatalla == 1 &&  *x >= 150 && *x <= 200 && *y >= 50 && *y <= 100  ){
		*faseActualBatalla += 1;
	}
	else if(*faseActualBatalla == 2 && *x >= 50 && *x <= 100 && *y >= 500 && *y <= 550 ){
		*faseActualBatalla += 1;
		*x = 52;
		*y = 52;
	}
	else if(*faseActualBatalla == 3 && *x >= 150 && *x <= 200 && *y >= 150 && *y <= 200  ){
		*faseActualBatalla += 1;
	}
	else if(*faseActualBatalla == 4 && *x >= 50 && *x <= 100 && *y >= 150 && *y <= 200  ){
		*faseActualBatalla += 1;
	}
}

void Controller :: mostrarNumero(int numero, BITMAP * numeros, int x, int y, BITMAP * buffer){
	int i, pixelesHaciaLaDerecha;
	for(i = 2; i > -1; i--){
		pixelesHaciaLaDerecha = ((numero % 10) * 25);
		masked_blit(numeros, buffer, pixelesHaciaLaDerecha , 0 , x + (25*i), y, 25, 25 ); 
		//masked_blit(prota, buffer, 0, direccion, x, y, 32,40);
		numero -= numero % 10;
		numero = numero / 10;
	}
	
}

void Controller :: mostrarDatosPersonaje(BITMAP * numeros, BITMAP * buffer){
	mostrarNumero(jugador.getVida(), numeros, 0, 665, buffer);
	mostrarNumero(jugador.getResistencia(), numeros, 100, 665, buffer);
	mostrarNumero(jugador.getAtaque(), numeros, 200, 665, buffer);
	mostrarNumero(jugador.getMana(), numeros, 300, 665, buffer);
}

void Controller :: mostrarDatosEnemigo(BITMAP * numeros, BITMAP * buffer, Enemigo enemigoBatalla){
	mostrarNumero(enemigoBatalla.getVida(), numeros, 450, 40, buffer);
	mostrarNumero(enemigoBatalla.getResistencia(), numeros, 450, 95, buffer);
	mostrarNumero(enemigoBatalla.getAtaque(), numeros, 450, 145, buffer);
}


