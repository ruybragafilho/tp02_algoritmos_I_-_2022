/*  Definicoes dos metodos do tipo abstrato de dados TipoItem, utilizado    */
/*  para representar um elemento da lista duplamente encadeada.             */
/*                                                                          */
/*  Autor: Ruy Braga Filho                                                  */



#include "TipoItem.h"

#include <iostream>

using std::cout;


  
/*  Definicao do Método que ajusta o atributo registro  */
/*  com o valor passado como parametro.                 */
void TipoItem::setID( long id )   {
    this->id  =  id;  
}    


/*  Definicao do Método que retorna o atributo registro  */
long TipoItem::getID()   {
    return( id );  
}        


/*  Definicao do Método que ajusta o atributo peso  */
/*  com o valor passado como parametro.                 */
void TipoItem::setPeso( long peso )   {
    this->peso  =  peso;  
}    


/*  Definicao do Método que retorna o atributo peso  */
long TipoItem::getPeso()   {
    return( peso );  
}           


/*  Método que imprime o item  */
void TipoItem::imprimir() { cout << this->id; }


/* Sobrecarga de operadores relacionais */
bool TipoItem::operator<=(TipoItem& i) const  {
    return(  this->peso <= i.peso  );
}

bool TipoItem::operator>=(TipoItem& i) const  {
    return(  this->peso >= i.peso  );
}

bool TipoItem::operator==(TipoItem& i) const  {
    return(  this->id == i.id  );
}


/*  Fim das definicoes dos métodos do tipo abstrato de dados TipoItem  */