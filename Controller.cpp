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
				listaLimitesProhibidos.push_back(i);
				listaLimitesProhibidos.push_back(j);
			}
		}
	}
	return listaLimitesProhibidos;
}





