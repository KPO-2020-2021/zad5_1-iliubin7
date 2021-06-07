#pragma once

#include "Block.hpp"
/*!
* \file Cuboid.hpp
*
*/

/*! \class Cuboid (dziedziczy klas Block)
*
*/
class Cuboid : public Block
{

public:
/*!
* Konstruktor parametryczny prostopadloscianu
*/
Cuboid(Vector3D center=Vector3D(), double x=50,double y=50, double z=50,std::string name="../datasets/cuboid.dat");
/*!
* Destruktor klasy prostopadloscianu
* Argumenty:
*    Brak argumentow.
* Zwraca:
* Usuwa dynamicznie stworzony obiekt.
*/
~Cuboid()
{
    delete sizes_of_block;
}
};
