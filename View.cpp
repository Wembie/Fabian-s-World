#include "View.h"

View::View(){
    controller = Controller();
}

void View::inicializarAllegro(){
	allegro_init();
 	install_keyboard();
 	install_mouse();
 	
	//CREAMOS VENTANA
 	set_color_depth(32);
 	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
}
