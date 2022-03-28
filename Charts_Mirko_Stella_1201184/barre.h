#ifndef BARRE_H
#define BARRE_H

//standard
#include <map>
#include<fstream>
//QT
#include <QFile>
#include <QXmlStreamWriter>
//gerarchia
#include <grafico.h>
using std::map;
using std::fstream;
using std::pair;

//classe istaziabile
class Barre:public Grafico
{
private:
   map<QString,double> coordinate;
public:
    Barre();
    map<QString,double> getCoordinate() const;
    void aggiungiCoordinata(const QString&,const double&);
    void eliminaCoordinata(const QString&);
    void salva(const QString&) const;
};

#endif // BARRE_H
