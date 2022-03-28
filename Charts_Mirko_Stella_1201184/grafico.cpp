#include "grafico.h"

Grafico::Grafico()
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

