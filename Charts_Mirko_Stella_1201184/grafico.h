#ifndef GRAFICO_H
#define GRAFICO_H


//inclusioni QT
#include <QString>

//classe base astratta
class Grafico
{
private:
    QString nome;
public:
    Grafico();
    QString getNome() const;
    void setNome(const QString&);
    virtual void salva(const QString&) const=0;
};

#endif // GRAFICO_H
