#pragma once

#include "Vector3D.hpp"
#include "Matrix3D.hpp"
#include <fstream>
#include <vector>
/*!
* \file Block.hpp
*
*/

/*! \class Block
*
*/
class Block
{
 protected:
 Vector3D *sizes_of_block;          
 std::vector<Vector3D> vertex;    
 Vector3D center;          
 std::string name;
 public:

 Vector3D &operator[](int index);
 Vector3D operator[](int index)const;

 void set_center(Vector3D center);
 void set_name(std::string name);
 Vector3D get_center() const;
 std::string get_name() const;

 void translate(Vector3D trans);
 void translation(Matrix3D rot);
 void write_to_file();

~Block()
{
delete sizes_of_block;
}
};