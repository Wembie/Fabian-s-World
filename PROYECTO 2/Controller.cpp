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
	else if(*faseActual == 4 && *x >= 50 && *x <= 100 && *y >= 500 && *y <= 550  ){
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

void Controller :: mostrarNumeroPequenio(int numero, BITMAP * numeros, int x, int y, BITMAP * buffer){
	int i, pixelesHaciaLaDerecha;
	for(i = 2; i > 0; i--){
		pixelesHaciaLaDerecha = ((numero % 10) * 7);
		masked_blit(numeros, buffer, pixelesHaciaLaDerecha , 0 , x + (7*i), y, 7, 7 ); 
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

void Controller::cambiarVidaJugador( Enemigo enemigoBatalla ){
	if(enemigoBatalla.getAtaque() >= jugador.getResistencia()){
		jugador.setVida( jugador.getVida() - (enemigoBatalla.getAtaque() - jugador.getResistencia()) );
	}
	
}

void Controller::reiniciarVida( ){
	jugador.setVida( 200 );
}

void Controller::darItemAleatorio(){
	int numeroAleatorio;
	srand(time(NULL));
	numeroAleatorio =  rand()%8;
	if(jugador.getInventario().size() <= 9){
		jugador.agregarItem( numeroAleatorio );
	}
	
}

void Controller::mostrarInventario( BITMAP * buffer, BITMAP * numeritos ){
	int i = 0, j = 0;
	list<Item*> inventarioJugador =  jugador.getInventario();
	for(list<Item *>::iterator it = inventarioJugador.begin(); it != inventarioJugador.end(); it++ ){
		
		Item * item = *it;
		item->mostrarItem( 589 + i, 606 + j, buffer );
		switch(item->getTipo()){
			case ESPADA:{
				Arma * espada = dynamic_cast< Arma * >( item );
				mostrarNumeroPequenio( espada->getDurabilidad(), numeritos ,597 + i, 626 + j, buffer  );
				break;
				}
			case ARCO:{
				Arma * arco = dynamic_cast< Arma * >( item );
				mostrarNumeroPequenio( arco->getDurabilidad(), numeritos ,597 + i, 626 + j, buffer  );
				break;
				}
				
			case LANZA:{
				Arma * lanza = dynamic_cast< Arma * >( item );
				mostrarNumeroPequenio( lanza->getDurabilidad(), numeritos ,597 + i, 626 + j, buffer  );
				break;
				}
				
		}
		i += 35;
		if(i/35 >= 5){
			
			j = 50;
		}
		if(i/35 == 5){
			i = 0;
		}
	}
	
}

void Controller::vaciarInventario(){
	list< Item * > inventarioVacio;
	jugador.setInventario( inventarioVacio );
}

void Controller::cambiarMana( int costoMana ){
	jugador.setMana( jugador.getMana() - costoMana );
}

void Controller::usarInventario( Enemigo * enemigoBatalla ){
	
	int inicioX = 589, inicioY = 608, inicioXAbajo = 589, inicioYAbajo = 658, cantidadItems = 0;
	list<Item*> inventarioJugador =  jugador.getInventario();
	for(list<Item *>::iterator it = inventarioJugador.begin(); it != inventarioJugador.end(); it++ ){
		if( mouse_x > inicioX && mouse_x < inicioX + 27 && mouse_y > inicioY && mouse_y < inicioY + 27 ){
			if( mouse_b & 1  ){
				do{
 		  			//para que el click sostenido no haga prrrrrrrrrrr
				}while( mouse_b & 1  );	
				Item * item = *it;			
				switch( item->getTipo() ){
					case ESPADA:{
						Arma * espada = dynamic_cast< Arma * >( item );
						if( espada != 0 ){
							enemigoBatalla->setVida(enemigoBatalla->getVida() - espada->getPuntosAtaque());
							cambiarVidaJugador( *enemigoBatalla );
							espada->setDurabilidad( espada->getDurabilidad() - 1 );
							if( espada->getDurabilidad() == 0 ){
								inventarioJugador.erase( it );
							}
						}
						break;
					}
					case ARCO:{
						Arma * arco = dynamic_cast< Arma * >( item );
						if( arco != 0 ){
							enemigoBatalla->setVida(enemigoBatalla->getVida() - arco->getPuntosAtaque());
							cambiarVidaJugador( *enemigoBatalla );
							arco->setDurabilidad( arco->getDurabilidad() - 1 );
							if( arco->getDurabilidad() == 0 ){
								inventarioJugador.erase( it );
							}
						}
						break;
					}
					case LANZA:{
						Arma * lanza = dynamic_cast< Arma * >( item );
						if( lanza != 0 ){
							enemigoBatalla->setVida(enemigoBatalla->getVida() - lanza->getPuntosAtaque());
							cambiarVidaJugador( *enemigoBatalla );
							lanza->setDurabilidad( lanza->getDurabilidad() - 1 );
							if( lanza->getDurabilidad() == 0 ){
								inventarioJugador.erase( it );
							}
						}
						break;
					}
					case POCION_VIDA:{
						Pocion * pocionVida = dynamic_cast< Pocion * >( item );
						if( pocionVida != 0 ){
							if( jugador.getVida() + pocionVida->getCantidadDeAumento() <= 200 ){
								jugador.setVida( pocionVida->getCantidadDeAumento() + jugador.getVida() );
							}
							else{
								jugador.setVida( 200 );
							}
							inventarioJugador.erase( it );						
						}
						break;
					}
					case POCION_RESISTENCIA:{
						Pocion * pocionResistencia = dynamic_cast< Pocion * >( item );
						if( pocionResistencia != 0 ){
							jugador.setResistencia( pocionResistencia->getCantidadDeAumento() + jugador.getResistencia() );
							inventarioJugador.erase( it );
						}
						break;
					}
					case POCION_ATAQUE:{
						Pocion * pocionAtaque = dynamic_cast< Pocion * >( item );
						if( pocionAtaque != 0 ){
							jugador.setAtaque( pocionAtaque->getCantidadDeAumento() + jugador.getAtaque() );
							inventarioJugador.erase( it );
						}
						break;
					}
					case POCION_MANA:{
						Pocion * pocionMana = dynamic_cast< Pocion * >( item );
						if( pocionMana != 0 ){
							if( jugador.getMana() + pocionMana->getCantidadDeAumento() <= 100)
							jugador.setMana( pocionMana->getCantidadDeAumento() + jugador.getMana() );
						}
						else{
							jugador.setMana( 100 );
						}
						inventarioJugador.erase( it );
						break;
					}
					case POCION_DANIO:{
						Pocion * pocionDanio = dynamic_cast< Pocion * >( item );
						if( pocionDanio != 0 ){
							enemigoBatalla->setVida(enemigoBatalla->getVida() - pocionDanio->getCantidadDeAumento());
							inventarioJugador.erase( it );
						}
						break;
					}
				}
				
			}
		}
		if( cantidadItems < 4 ){
			inicioX += 35;
		} 
		if( cantidadItems >= 5 ){
			if( mouse_x > inicioXAbajo && mouse_x < inicioXAbajo + 27 && mouse_y > inicioYAbajo && mouse_y < inicioYAbajo + 27 ){
				if( mouse_b & 1  ){
					do{
	 		  			//para que el click sostenido no haga prrrrrrrrrrr
					}while( mouse_b & 1  );
					Item * item = *it;	
					switch( item->getTipo() ){
					case ESPADA:{
						Arma * espada = dynamic_cast< Arma * >( item );
						if( espada != 0 ){
							enemigoBatalla->setVida(enemigoBatalla->getVida() - espada->getPuntosAtaque());
							cambiarVidaJugador( *enemigoBatalla );
							espada->setDurabilidad( espada->getDurabilidad() - 1 );
							if( espada->getDurabilidad() == 0 ){
								//Saber cuando se toma pociones de ataque y eso pense en hacerlo con ataque base y con ello una vez se utilize 
								//seria reiniciar el ataque el cual se aumenta del uso del arma y con ello se restableze el ataque al ataque base que habia
								
								//pero mientras dejarlo asi
								inventarioJugador.erase( it );
							}
						}
						break;
					}
					case ARCO:{
						Arma * arco = dynamic_cast< Arma * >( item );
						if( arco != 0 ){
							enemigoBatalla->setVida(enemigoBatalla->getVida() - arco->getPuntosAtaque());
							cambiarVidaJugador( *enemigoBatalla );
							arco->setDurabilidad( arco->getDurabilidad() - 1 );
							if( arco->getDurabilidad() == 0 ){
								inventarioJugador.erase( it );
							}
						}
						break;
					}
					case LANZA:{
						Arma * lanza = dynamic_cast< Arma * >( item );
						if( lanza != 0 ){
							enemigoBatalla->setVida(enemigoBatalla->getVida() - lanza->getPuntosAtaque());
							cambiarVidaJugador( *enemigoBatalla );
							lanza->setDurabilidad( lanza->getDurabilidad() - 1 );
							if( lanza->getDurabilidad() == 0 ){
								inventarioJugador.erase( it );
							}
						}
						break;
					}
					case POCION_VIDA:{
						Pocion * pocionVida = dynamic_cast< Pocion * >( item );
						if( pocionVida != 0 ){
							if( jugador.getVida() + pocionVida->getCantidadDeAumento() <= 200 ){
								jugador.setVida( pocionVida->getCantidadDeAumento() + jugador.getVida() );
							}
							else{
								jugador.setVida( 200 );
							}
							inventarioJugador.erase( it );						
						}
						break;
					}
					case POCION_RESISTENCIA:{
						Pocion * pocionResistencia = dynamic_cast< Pocion * >( item );
						if( pocionResistencia != 0 ){
							jugador.setResistencia( pocionResistencia->getCantidadDeAumento() + jugador.getResistencia() );
							inventarioJugador.erase( it );
						}
						break;
					}
					case POCION_ATAQUE:{
						Pocion * pocionAtaque = dynamic_cast< Pocion * >( item );
						if( pocionAtaque != 0 ){
							jugador.setAtaque( pocionAtaque->getCantidadDeAumento() + jugador.getAtaque() );
							inventarioJugador.erase( it );
						}
						break;
					}
					case POCION_MANA:{
						Pocion * pocionMana = dynamic_cast< Pocion * >( item );
						if( pocionMana != 0 ){
							if( jugador.getMana() + pocionMana->getCantidadDeAumento() <= 100)
							jugador.setMana( pocionMana->getCantidadDeAumento() + jugador.getMana() );
						}
						else{
							jugador.setMana( 100 );
						}
						inventarioJugador.erase( it );
						break;
					}
					case POCION_DANIO:{
						Pocion * pocionDanio = dynamic_cast< Pocion * >( item );
						if( pocionDanio != 0 ){
							enemigoBatalla->setVida(enemigoBatalla->getVida() - pocionDanio->getCantidadDeAumento());
							inventarioJugador.erase( it );
						}
						break;
					}
				}
				}
			}
			inicioXAbajo += 35;
		}
		cantidadItems++;	
	}
	jugador.setInventario( inventarioJugador );				
}			
			