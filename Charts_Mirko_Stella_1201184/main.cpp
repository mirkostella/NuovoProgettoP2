#include "mainwindow.h"

#include <QApplication>
#include "barre.h"
#include "gestorecaricamento.h"
#include <iostream>
#include <map>
using std::cout;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Barre prova;
    prova.setNome("sono il nome del grafico");
    prova.aggiungiCoordinata("ciao",32);
    prova.aggiungiCoordinata("come",1);
    prova.aggiungiCoordinata("stai",46);
    prova.aggiungiCoordinata("mirko");
    if(prova.modificaCoordinata("lupo",14))
        cout<<"coordinata modificata con successo"<<std::endl;
    else
        cout<<"coordinata non presente"<<std::endl;



    prova.salva("C:/Users/stell/Desktop/cartellaProvaFile/nuovo.txt");
    GestoreCaricamento gestore("C:/Users/stell/Desktop/cartellaProvaFile/nuovo.txt");
    Grafico* graficoCaricato=gestore.carica();
    Barre* graficoBarre=static_cast<Barre*>(graficoCaricato);
    std::map<QString,double> datiGrafico=graficoBarre->getCoordinate();
    if(datiGrafico.empty())
        cout<<"vuoto";
    else
        cout<<"contiene elementi"<<std::endl;

    cout<<*graficoBarre;







    return a.exec();
}
