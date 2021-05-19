#ifndef VIEW_H
#define VIEW_H

#include <allegro.h>
#include "Controller.h"

class View{
private:
    // Objeto de tipo controller para enlazar la logica
    Controller controller;
    

public:
    View();
    void verPrincipal();
    void inicializarAllegro();
    void cicloPrincipal();
};

#endif //VIEW_H

