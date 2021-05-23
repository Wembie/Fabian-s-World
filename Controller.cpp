#include "Controller.h"
Controller :: Controller(){

}

Jugador Controller::getJugador(){
	return this->jugador;
}

Enemigo Controller::getEnemigo(){
	return this->enemigo;
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