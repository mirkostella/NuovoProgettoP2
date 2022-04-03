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
    prova.aggiungiCoordinata("ciao",32);
    prova.salva("C:/Users/stell/Desktop/cartellaProvaFile/nuovo.txt");
    GestoreCaricamento gestore("C:/Users/stell/Desktop/cartellaProvaFile/nuovo.txt");
    Grafico* graficoCaricato=gestore.carica();
    Barre* graficoBarre=dynamic_cast<Barre*>(graficoCaricato);
    std::map<QString,double> datiGrafico=graficoBarre->getCoordinate();
    if(datiGrafico.empty())
        cout<<"vuoto";
    else
        cout<<"contiene elementi"<<std::endl;

    cout<<*graficoBarre;







    return a.exec();
}
