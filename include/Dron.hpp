#pragma once

#include "Cuboid.hpp"
#include "Prism.hpp"
#include "lacze_do_gnuplota.hpp"
#include <unistd.h> // biblioteka dla usleep
#define TIME 20000

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
    Cuboid  oryg_rotor[4];
    /*!
    *  Te rotory beda widoczne na ekranie
    */
    Cuboid  copy_rotor[4];
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
  * Konstruktor klasy Dron
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
  void translate(double way);
  /*!
  * kat (podajemy w stopniach)
  */
  void rotate(double angle);
  /*! 
  * kat (podajemy w stopniach)
  */
  void rotor_rotation();
  /*! 
  * Metoda zapisu do pliku wszystkich elementow drona.
  */
  void write_to_file();
  void control();
  /*! 
  * Metoda okreslenia drogi drona.
  */
  void def_way(double way);
};