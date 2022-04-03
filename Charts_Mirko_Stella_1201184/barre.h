#ifndef BARRE_H
#define BARRE_H

//standard
#include <map>
#include <iostream>

//gerarchia
#include <grafico.h>
using std::map;
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

    //virtual
    void salva(const QString&) const;
    void popola(const QDomElement&);
    QString getTipo() const;
};
std::ostream& operator<<(std::ostream&,const Barre&);
#endif // BARRE_H
