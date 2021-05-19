#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl; 
using std::string;

class Item{
    private:
        string nombre;
        string descripcion;
    public:
        Item( string, string );
};

#endif // ITEM_H
