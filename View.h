#ifndef VIEW_H
#define VIEW_H

#include <allegro.h>
#include "Controller.h"
#include "enemigo.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

class View{
private:
    // Objeto de tipo controller para enlazar la logica
    Controller controller;
    

public:
    View();
    void verPrincipal();
    void inicializarAllegro();
    void cicloPrincipal();
    void verificarLimites(list <int> ,int *, int *,  int *,  int *, int, int);
    void ponerFondo(BITMAP * lobbyA, BITMAP * lobbyA2,BITMAP * lobbyB ,  BITMAP * lobbyB2, int fase, BITMAP * buffer);
    void verificarInicioBatalla( list <int>, int, int, int *, int *, int * );
    int cicloBatalla( BITMAP * buffer, BITMAP * fondoBatalla, BITMAP * enemigo, BITMAP * cursor, BITMAP * numeros   );
};

#endif //VIEW_H

