#include "gestorecaricamento.h"

GestoreCaricamento::GestoreCaricamento(const QString &p):path(p)
{

}

Grafico *GestoreCaricamento::carica() const
{
 QFile f(path);
 f.open(QFile::ReadOnly | QFile::Text);
 QDomDocument documento;
 try{
         documento.setContent(&f);
 }
 catch(QXmlParseException a){
     //errore nell'analisi del file
 }
 f.close();
 QDomNodeList listaElementoTipo=documento.elementsByTagName("radice");
 QDomNode nodoRadice=listaElementoTipo.item(0);
 QDomElement elementoRadice=nodoRadice.toElement();
 QDomElement elementoTipo=elementoRadice.firstChildElement("tipo");
 QString tipoGrafico=elementoTipo.text();
 std::cout<<tipoGrafico.toStdString();
 Grafico* g=nullptr;
 if(tipoGrafico=="barre"){
     g=new Barre();
     g->popola(elementoRadice);
 }
return g;

}
