#include "barre.h"

Barre::Barre()
{

}

map<QString, double> Barre::getCoordinate() const
{
    return coordinate;
}

//se la chiave é giá presente ritorna false
bool Barre::aggiungiCoordinata(const QString& chiave, const double& valore)
{
    pair<map<QString,double>::iterator,bool> ris=coordinate.insert(pair<QString,double>(chiave,valore));
    return ris.second;
}
//se la chiave non esiste ritorna false
bool Barre::modificaCoordinata(const QString & chiave, const double &nuovoValore)
{
   try {
       coordinate.at(chiave)=nuovoValore;
   }  catch (const out_of_range& e) {
        return false;
   }
    return true;
}
//chiave
void Barre::eliminaCoordinata(const QString& chiave)
{
    coordinate.erase(chiave);
}

void Barre::salva(const QString& path) const
{
    QFile file(path);
    file.open(QFile::WriteOnly | QFile::Text);
    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("radice");
    stream.writeTextElement("tipo","barre");
    stream.writeTextElement("nome",getNome());
    stream.writeStartElement("dati");
    //ciclo che scrive i dati presenti in coordinate
    for(auto it=coordinate.cbegin();it!=coordinate.cend();++it){
        stream.writeStartElement("dato");
        stream.writeTextElement("chiave",it->first);
        stream.writeTextElement("valore",QString::number(it->second));
        stream.writeEndElement();
    }
    stream.writeEndElement();//fine dati
    stream.writeEndDocument();//fine radice
    stream.writeEndDocument();//fine documento
    file.close();
}

void Barre::popola(const QDomElement & radice)
{
    QDomElement elementoNome=radice.firstChildElement("nome");
    setNome(elementoNome.text());
    QDomNodeList listaNodoDati=radice.elementsByTagName("dati");
    QDomNode nodoDati=listaNodoDati.item(0);
    QDomElement elementoDati=nodoDati.toElement();
    QDomNodeList listaDati=elementoDati.elementsByTagName("dato");
    //per ogni nodo
    for(int i=0;i<listaDati.count();++i){
        QDomElement elementoChiave=listaDati.item(i).firstChildElement("chiave");
        QDomElement elementoValore=listaDati.item(i).firstChildElement("valore");
        QString chiave=elementoChiave.text();
        double valore=elementoValore.text().toDouble();
        coordinate.insert(pair<QString,double>(chiave,valore));
    }
}

QString Barre::getTipo() const
{
    return "barre";
}
std::ostream& operator<<(std::ostream& os,const Barre& b){
    os<<"nome:";
    os<<b.getNome().toStdString();
    os<<std::endl;
    map<QString,double> coordinate=b.getCoordinate();
    for(auto it=coordinate.cbegin();it!=coordinate.cend();++it){
        os<<"chiave:";
        os<<it->first.toStdString();
        os<<std::endl;
        os<<"valore:";
        os<<it->second;
        os<<std::endl;
        os<<std::endl;
    }
    return os;
}
