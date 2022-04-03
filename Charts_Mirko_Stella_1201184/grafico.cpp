#include "grafico.h"

Grafico::Grafico():nome("")
{

}

QString Grafico::getNome() const
{
    return nome;
}

void Grafico::setNome(const QString & nuovoNome)
{
    nome=nuovoNome;
}

