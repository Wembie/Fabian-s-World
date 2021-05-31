#include <iostream> 
#include <allegro.h>
#include "View.h"

using std::cin;
using std::cout;
using std::endl;
//Se crea un variable de tipo View, para poder acceder a los metodos y que funcione :D
int main() { 
	View view;
	view.inicializarAllegro();
    view.cicloPrincipal();
    return 0;
}
END_OF_MAIN(); //Funcion para saber que termina el allegro :D
