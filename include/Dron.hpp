#pragma once

#include "Cuboid.hpp"
#include "Prism.hpp"
#include "lacze_do_gnuplota.hpp"
#include <unistd.h> // biblioteka dla usleep
#define TIME 20000
/*!
* \file Dron.hpp
*
*/

/*! \class Dron
*
*/
class Dron
{
    std::vector<Vector3D> dron_way;
    PzG::LaczeDoGNUPlota &Lacze;
    /*!
    *   Do tego prostopadloscianu bedziemy sie odwolywac
    */
    Cuboid orginal;
    /*!
    *  Ten prostopadloscian bedzie widoczny na ekranie
    */
    Cuboid  copy;
    /*!
    *   Do tych rotorow bedziemy sie odwolywac
    */
    Prism  oryg_rotor[4];
    /*!
    *  Te rotory beda widoczne na ekranie
    */
    Prism  copy_rotor[4];
    /*!
    * Macierz obrotu potrzebna jest, zeby dron pamietal, o ile jest obrocony
    */
    Matrix3D rot;
    /*!
    * Vector drogi, ktora przebyl dron
    */
    Vector3D way;
    /*! 
    * Kat, o jaki jest obrocony dron
    */
    double angle;
    /*!
    * W tym polu definiuje zmienna, potrzebna dla rozroznienia miedzy soba dronow, stworzonych w jednej przestrzeni
    */
    int id; 
public:
  /*!
  * Konstruktor parametryczny klasy Dron
  */
  Dron(int id,PzG::LaczeDoGNUPlota &Lacze,Vector3D position);
  /*!
  * Metoda dla unoszenia drona.
  * Argumenty:
  * way - droga drona.
  * Zwraca:
  * Przesuwa dron o podana droge do gory
  */
  void lifting(double way);
  /*!
  * Metoda przesuniecia drona o podana droge
  */
  void translate(double way);
  /*!
  * Metoda rotacji drona o podany kat
  * kat (podajemy w stopniach)
  */
  void rotate(double angle);
  /*! 
  * Metoda obrotu rotorow drona wokol wlasnej osi (rotory obracaja sie przeciwlegle do siebie)
  * kat (podajemy w stopniach)
  */
  void rotor_rotation();
  /*! 
  * Metoda zapisu do pliku wszystkich elementow drona.
  */
  void write_to_file();
  /*!
  * Metoda kontroli nad dronem(wybieramy odpowiednie opcje przesuniecia lub obrotu i 
  * podajemy odpowiednio dlugosc lotu lub kierunek lotu(podajemy jako kat w stopniach)))
  */
  void control();
  /*! 
  * Metoda okreslenia drogi drona.
  */
  void def_way(double way,double angle);
  /*! 
  * Modyfikacja - metoda przelotu drona po okregu.
  * (zostalo zrealizowane jako przelot drona po osmiokatu)
  * Argumenty:
  * r - promien okregu. 
  * Zwraca:
  * przemieszcza dron ruchem po okregu i nastepnie zwraca go na swoja poczatkowa pozycje.
  */
  void way_by_circle(double r);
}; 