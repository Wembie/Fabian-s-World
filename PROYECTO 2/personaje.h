#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <list>
#include <allegro.h>

using std::cin;
using std::cout;
using std::endl; 
using std::string;

//Se crea la clase Personaje, con sus respetivos atributos, constructor y metodos

class Personaje{
    protected:
        string nombre;
        int vida;
        int ataque;
        int resistencia;
    public:
    	Personaje();
        Personaje( string, int, int, int );
        void moverBatalla( BITMAP *, BITMAP *, int  , int , int  );
        int getVida();
        int	getAtaque();
        int getResistencia();
        void setVida(int vida);
		void setResistencia(int resistencia);
		void setAtaque(int ataque);
        
};
#endif // PERSONAJE_H
