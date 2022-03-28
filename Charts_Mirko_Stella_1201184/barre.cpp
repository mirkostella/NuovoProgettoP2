#include "barre.h"

Barre::Barre()
{

}

map<QString, double> Barre::getCoordinate() const
{
    return coordinate;
}

//chiave,valore (se la coordinata é giá presente la modifica)
void Barre::aggiungiCoordinata(const QString& chiave, const double& valore)
{
    coordinate.insert(pair<QString,double>(chiave,valore));
}
//chiave
void Barre::eliminaCoordinata(const QString& chiave)
{
    coordinate.erase(chiave);
}

void Barre::salva(const QString& path) const
{

}

