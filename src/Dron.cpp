#include "../include/Dron.hpp"

Dron::Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Vector3D position) : Lacze(Lacze)
{
    angle=0;
    this->id = id;
    orginal.set_name("../datasets/korpus" + std::to_string(id) + ".dat");

    for (int i = 0; i < 4; i++)
        oryg_rotor[i].set_name("../datasets/rotor" + std::to_string(i) + std::to_string(id) + ".dat");

    Lacze.DodajNazwePliku(orginal.get_name().c_str(), PzG::RR_Ciagly, 2);
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(oryg_rotor[i].get_name().c_str(), PzG::RR_Ciagly, 2);
    copy = orginal;

    copy.translate(position);
    for (int i = 0; i < 4; i++)
        copy_rotor[i] = oryg_rotor[i];

    for (int i = 0; i < 4; i++)
        copy_rotor[i].translate(orginal[i * 2] + position);

    this->way = this->way + position;
}

void Dron::lifting(double way)
{
    Vector3D way_o;
   way_o[2] = way;

    this->way = this->way + way_o;
    copy.translation(rot);
    copy.translate(this->way);
}

void Dron::translate(double way)
{
    Vector3D way_o;
    way_o[0] = way * cos(angle * M_PI / 180);
    way_o[1] = way * sin(angle * M_PI / 180);
    this->way = this->way + way_o;
    copy.translation(rot);
    copy.translate(this->way);
}

void Dron::rotate(double angle)
{
    this->angle += angle;
    Matrix3D matr;
    rot = matr * matrix_rot_z(this->angle);
    copy.translation(rot);
    copy.translate(this->way);
}
void Dron::rotor_rotation()
{
    static int angle = 0;
    angle += 3;
    if (angle == 360)
        angle = 0;

    Matrix3D matr;
    matr = matr * matrix_rot_z(angle);
    for (int i = 0; i < 4; i++)
    {
        copy_rotor[i].translation(matr);
    }

    for (int i = 0; i < 4; i++)
    {
        copy_rotor[i].translate(copy[i * 2]);
    }
}

void Dron::write_to_file()
{
    copy.write_to_file();
    for (int i = 0; i < 4; i++)
        copy_rotor[i].write_to_file();
}

void Dron::control()
{
    double way;
    double angle;
    char op;

    write_to_file();
    cout << "opcje :";
    cin >> op;
    switch (op)
    {
    case 'p':
        cout << "podaj dlugosc lotu:";
        cin >> way;
        def_way(way);
        Lacze.DodajNazwePliku("../datasets/droga.dat", PzG::RR_Ciagly, 2);
        for (int i = 0; i < 100; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            lifting(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            /*!
            * Uzywamy ta funkcje dlatego, zeby byla widoczna animacja drona. 
            * Ta funckja zawiesza wykonanie na czas wyrazony w mikrosekundach.
            */
            usleep(TIME);
        }

        for (int i = 0; i < way; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            translate(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }

        for (int i = 0; i < 100; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            lifting(-1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }
    Lacze.UsunOstatniaNazwe();
        break;
    case 'o':
        cout << "podaj kierunek lotu (kat w stopniach):";
        cin >> angle;
        if (angle > 0)
        {
            for (int i = 0; i < angle; i++)
            {
                copy = orginal;
                for (int i = 0; i < 4; i++)
                    copy_rotor[i] = oryg_rotor[i];
                rotate(1);
                rotor_rotation();
                write_to_file();
                Lacze.Rysuj();
                usleep(TIME);
            }
        }
        else
        {
            for (int i = 0; i > angle; i--)
            {
                copy = orginal;
                rotate(-1);
                rotor_rotation();
                write_to_file();
                Lacze.Rysuj();
                usleep(TIME);
            }
        }

        break;
    default:
        break;
    }
}

void Dron::def_way(double way)
{
    Vector3D next = copy.get_center();
    next[2] = 0;
    dron_way.push_back(next);
    next[2] = 100;
    dron_way.push_back(next);
    next[0] += way * cos(angle * M_PI / 180);
    next[1] += way * sin(angle * M_PI / 180);
    dron_way.push_back(next);
    next[2] = 0;
    dron_way.push_back(next);

    std::fstream file;

    file.open("../datasets/droga.dat", std::ios::out);
    for (int i = 0; i < (int)dron_way.size(); i++)
    {

        file << dron_way[i] << std::endl;
    }
    file.close();
}