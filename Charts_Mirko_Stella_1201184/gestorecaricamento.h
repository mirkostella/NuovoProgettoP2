#ifndef GESTORECARICAMENTO_H
#define GESTORECARICAMENTO_H

//gerarchia
#include "barre.h"
#include <iostream>
#include <QXmlParseException>

//standard
#include <map>

//QT
#include <QString>
#include <QFile>
#include <QtXml/QDomDocument>

using std::map;

class GestoreCaricamento
{
private:
    QString path;
public:
    GestoreCaricamento(const QString& p);
    Grafico* carica() const;
};

#endif // GESTORECARICAMENTO_H
