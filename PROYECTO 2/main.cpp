#include <iostream> 
#include <allegro.h>
#include "View.h"

using std::cin;
using std::cout;
using std::endl;
 
int main() { 
	View view;
	view.inicializarAllegro();
    view.cicloPrincipal();
    return 0;
}
END_OF_MAIN();
