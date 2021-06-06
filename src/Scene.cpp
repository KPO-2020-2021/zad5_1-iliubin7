#include "../include/Scene.hpp"


 Scene::Scene()
 {

        Lacze.ZmienTrybRys(PzG::TR_3D);

       Lacze.UstawZakresY(-300, 300);
       Lacze.UstawZakresX(-300, 300);
       Lacze.UstawZakresZ(-300, 300);

       double tab_wym[3]={600,600,0};
       Vector3D size_bottom(tab_wym);
       bottom=new Surface(size_bottom,20);
       Lacze.DodajNazwePliku(bottom->get_name().c_str(), PzG::RR_Ciagly, 2);
       bottom->write_to_file();
       for(int i=0;i<N; i++)
       {
           double position[3]={(double)(rand()%440-220),(double)(rand()%440-220),25};
       tab[i]=new Dron(i,Lacze,Vector3D(position));
       tab[i]->write_to_file();
       }

       Lacze.Rysuj();
 }
 void  Scene::draw()
 {
     
   Lacze.Rysuj();
 }
 bool  Scene::interface()
 {
    cout<<"Wprowadz numer aktywnego drona:"<<endl;
    int nr;
    cin>>nr;
    if(nr<N)
    {
        tab[nr]->control();
    }
    else
    {
        return false;
    }
  return true;
 }

 Scene::~Scene()
 {
delete bottom;
for(int i=0; i<N; i++)
delete tab[i];
 }