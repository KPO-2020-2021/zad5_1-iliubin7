#pragma once

#include <iostream>
#include "Vector.hpp"
#include <cmath>
using namespace std;
/*!
* \file matrix.hpp
*
*/

/*! \class Matrix
*
*/
template <int Size>
class Matrix{
/*!
* \brief Tablica wartosci macierzy
*/
  double Mat[Size][Size];
  public:
/*!
  * \brief Konstruktor klasy Matrix.                                                 |
  * Argumenty:                                                                |
  *     Brak argumentow.                                                      |
  *  Zwraca:                                                                   |
  *     Macierz wypelnione wartoscia 0. 
  */
Matrix();  // Konstruktor klasy
/*!
    * \brief Realizuje mnozenie macierzy przez wektor.  
    * Argumenty:                                                                |
    *   this - macierz, czyli pierwszy skladnik mnozenia,                     |
    *   cor - wektor, czyli drugi skladnik mnozenia.                            |
    * Zwraca:                                                                   |
    *    Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
    */
Vector<Size> operator * (Vector<Size> cor);
 /*!
 *  \brief Zwraca wynik mnozenia dwoch macierzy                                                      
 *  Argumenty:                                                               
 *      this - macierz 1 
 *      cor - macierz 2                                                              
 *  Zwraca:                                                                  
 *      result - wynik mnozenia macierzy               
 */
Matrix<Size> operator * (Matrix<Size> cor);
 /*!
  * \brief Funktor macierzy                                                          |
  * Argumenty:                                                                |
  *     row - numer wiersza.                                                  |
  *     column - numer kolumny.                                               |
  * Zwraca:                                                                   |
  *    Wartosc macierzy w danym miejscu tablicy.                             |
  */
double &operator()(int row, int column);
/*!
   * \brief Funktor macierzy                                                          |
   * Argumenty:                                                                |
   *     row - numer wiersza.                                                  |
   *     column - numer kolumny.                                               |
   * Zwraca:                                                                   |
   *     Wartosc macierzy w danym miejscu tablicy jako stala.                  |
   */
double operator()(int row, int column) const;
};


#include "../src/Matrix.ipp"