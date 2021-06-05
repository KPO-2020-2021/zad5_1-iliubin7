#pragma once

#include "Block.hpp"
/*!
* \file Cuboid.hpp
*
*/

/*! \class Cuboid
*
*/
class Cuboid : public Block
{

public:

Cuboid(Vector3D center=Vector3D(), double x=50,double y=50, double z=50,std::string name="../datasets/cuboid.dat");

~Cuboid(){delete sizes_of_block;}
};
