#ifndef VIEW_H
#define VIEW_H

#include <allegro.h>
#include "Controller.h"

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
};

#endif //VIEW_H

