#ifndef BARRE_H
#define BARRE_H

//standard
#include <map>
#include <iostream>
#include <stdexcept>
using std::map;
using std::pair;
using std::out_of_range;

//gerarchia
#include <grafico.h>

//classe istaziabile
class Barre:public Grafico
{
private:
   map<QString,double> coordinate;
public:
    Barre();
    map<QString,double> getCoordinate() const;
    bool aggiungiCoordinata(const QString&,const double& valore=0);
    bool modificaCoordinata(const QString&,const double& nuovoValore);
    void eliminaCoordinata(const QString&);

    //virtual
    void salva(const QString&) const;
    void popola(const QDomElement&);
    QString getTipo() const;
};
std::ostream& operator<<(std::ostream&,const Barre&);
#endif // BARRE_H
