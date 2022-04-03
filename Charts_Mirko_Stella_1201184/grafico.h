#ifndef GRAFICO_H
#define GRAFICO_H


//inclusioni QT
#include <QString>
#include <QFile>
#include <QDomDocument>
#include <QXmlStreamWriter>

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
    virtual void popola(const QDomElement&)=0;
    virtual QString getTipo() const=0;
};

#endif // GRAFICO_H
