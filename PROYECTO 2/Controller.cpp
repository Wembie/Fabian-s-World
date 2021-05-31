#include "Controller.h"
/*Se crea el constructor por defecto*/
Controller :: Controller(){

}
//Funcion para traer el jugador
Jugador Controller::getJugador(){
	return this->jugador;
}
//Funcion para traer el enemigo
Enemigo Controller::getEnemigo(){
	return this->enemigo;
}
//Funcion para traer el personaje
Personaje Controller::getPersonaje(){
	return this->personaje;
}
//Funcion de tipo Lista que lo que hacer es recorrer la matriz del nivel y ver donde esta el enemigo, y lo guarda en la lista de limitesProhibidos
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

//Funcion que retorna la lista de pociones en pixeles de los enemigos de cada matriz que le pasemos
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
//Funcion que verifica la fase del juego, Fase = 1 es donde esta la llave del primer nivel, Fase = 2, donde esta el trofeo del primer nivel,  Fase = 3 es donde esta la llave del segundo nivel, Fase = 4, donde esta el trofeo del segundo nivel
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

//Funcion que verifica si entro en batalla o no
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

//Funcion que muestra los numeros en posicion x, y grandes
void Controller :: mostrarNumero(int numero, BITMAP * numeros, int x, int y, BITMAP * buffer){
	int i, pixelesHaciaLaDerecha;
	for(i = 2; i > -1; i--){
		pixelesHaciaLaDerecha = ((numero % 10) * 25);
		masked_blit(numeros, buffer, pixelesHaciaLaDerecha , 0 , x + (25*i), y, 25, 25 ); 
		numero -= numero % 10;
		numero = numero / 10;
	}
	
}

//Funcion que muestra los numeros en posicion x, y pequenios
void Controller :: mostrarNumeroPequenio(int numero, BITMAP * numeros, int x, int y, BITMAP * buffer){
	int i, pixelesHaciaLaDerecha;
	for(i = 2; i > 0; i--){
		pixelesHaciaLaDerecha = ((numero % 10) * 7);
		masked_blit(numeros, buffer, pixelesHaciaLaDerecha , 0 , x + (7*i), y, 7, 7 ); 
		numero -= numero % 10;
		numero = numero / 10;
	}
	
}
//Funcion que se llama en view, muestra los datos del personaje (Vida, resistencia, ataque y mana)
void Controller :: mostrarDatosPersonaje(BITMAP * numeros, BITMAP * buffer){
	mostrarNumero(jugador.getVida(), numeros, 0, 665, buffer);
	mostrarNumero(jugador.getResistencia(), numeros, 100, 665, buffer);
	mostrarNumero(jugador.getAtaque(), numeros, 200, 665, buffer);
	mostrarNumero(jugador.getMana(), numeros, 300, 665, buffer);
}

//Funcion que se llama en view, y muestra la vida resistencia y ataque del enemigo en batalla
void Controller :: mostrarDatosEnemigo(BITMAP * numeros, BITMAP * buffer, Enemigo enemigoBatalla){
	mostrarNumero(enemigoBatalla.getVida(), numeros, 450, 40, buffer);
	mostrarNumero(enemigoBatalla.getResistencia(), numeros, 450, 95, buffer);
	mostrarNumero(enemigoBatalla.getAtaque(), numeros, 450, 145, buffer);
}
//Funcion que cambia la vida del jugador en batalla, (VidaJugador = VidaJugador ( ataqueEnemigo - resistenciaEnemigo ))
void Controller::cambiarVidaJugador( Enemigo enemigoBatalla ){
	if(enemigoBatalla.getAtaque() >= jugador.getResistencia()){
		jugador.setVida( jugador.getVida() - (enemigoBatalla.getAtaque() - jugador.getResistencia()) );
	}
	
}

//Funcion que cuando muere el jugador se le reinicia la vida en 200 ya que es la vida maxima
void Controller::reiniciarVida( ){
	jugador.setVida( 200 );
}

//Funcion que da un item aleatorio dependiendo de lo que sea segun el enum de item en cada pelea
void Controller::darItemAleatorio(){
	int numeroAleatorio;
	srand(time(NULL));
	numeroAleatorio =  rand()%8;
	if(jugador.getInventario().size() <= 9){
		jugador.agregarItem( numeroAleatorio );
	}
	
}
//Funcion que se llama en View y muestra el inventario del jugador, con su respectivo dibujo y si es una espada, arco o lanza se muestra la durabilidad de cada item
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
//Funcion que se llama en el View, cuando muere el jugador el inventario queda vacio
void Controller::vaciarInventario(){
	list< Item * > inventarioVacio;
	jugador.setInventario( inventarioVacio );
}

//Funcion que cambia el cama del jugador
void Controller::cambiarMana( int costoMana ){
	jugador.setMana( jugador.getMana() - costoMana );
}

//Funcion el cual solo se puede usar en batalla la cual verifica en cada cuadrito del inventario de que tipo de item es
//si es arma o pocion y actua mediante eso y alfinal se le remplaza el inventario que tenia a este y asi susecivamente
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