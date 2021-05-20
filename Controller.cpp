#include "Controller.h"
Controller :: Controller(){

}

Jugador Controller::getJugador(){
	return this->jugador;
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

void Controller::verificarFase(int x, int y, int * faseActual ){
	if(*faseActual == 1 && x >= 150 && x <= 200 && y >= 50 && y <= 100  ){
		*faseActual += 1;
	}
}





