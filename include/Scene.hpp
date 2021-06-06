#pragma once 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Block.hpp"
#include "lacze_do_gnuplota.hpp"
#include "Dron.hpp"
#include "Surface.hpp"

#define N 2
/*!
* \file Scene.hpp
*
*/

/*! \class Scene
*
*/
class Scene
{
 PzG::LaczeDoGNUPlota Lacze;
 /*!
 * Tablica dronow
 */
 Dron *tab[N];
 Surface *bottom;

 public:
 /*! 
 * Konstruktor klasy Scene
 */
 Scene();
 /*!
 * Metoda do rysowania calej Sceny
 */
 void draw();
 bool interface();
 /*!
 * Destruktor klasy Scene
 * Argumenty:
    Brak argumentow.
* Zwraca:
*   Zwalnia dynamicznie zaalokowana pamiec.
 */
 ~Scene();
};
