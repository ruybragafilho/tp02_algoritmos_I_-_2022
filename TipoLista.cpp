/*  Definicoes das funcoes do tipo abstrato de dados TipoLista.   */
/*  Esse TAD eh implementado por meio de uma estrutura duplamente */
/*  encadeada com nodo cabeca e cursor.                           */
/*                                                                */
/*  Autor: Ruy Braga Filho                                        */



#include  "TipoLista.h"
#include  <iostream>

using std::cout;
using std::endl;



/* Metodo auxiliar que cria uma lista vazia */
template <class T>
void TipoLista<T>::criarListaVazia()  {
    
    TipoCelula<T>* temp;
    T item;
    
    /* Alocando memoria para o nodoCabeca */
    temp = new TipoCelula<T>();        

    /* Armazenando um item nulo no nodoCabeca */
    temp->item = item;        

    /* Ligando o nodoCabeca na lista */
    temp->proximo = temp->anterior  = temp;
    this->cursor = this->nodoCabeca = temp;        
    this->numElementos = 0;	            

}  /*  Fim da definicao do método auxiliar criarListaVazia.  */



/* Metodo auxiliar que clona a lista passada como parâmetro */
template <class T>
void TipoLista<T>::clonarLista( TipoLista<T>& outraLista )  {

    T item;

    outraLista.primeiro();

    while( outraLista.temMais() )   {

        item = outraLista.getItem();
        this->inserirNoFim( item );  
        outraLista.proximo();
    }
   
    this->primeiro();

}  /*  Fim da definicao do método auxiliar clonarLista.  */        




/* Construtor padrão da classe TipoLista. Cria uma lista vazia */
template <class T>
TipoLista<T>::TipoLista()  {

    this->criarListaVazia();

}  /*  Fim da definicao do construtor padrão da classe TipoLista.  */



/* Construtor de cópia da classe TipoLista. */
template <class T>
TipoLista<T>::TipoLista( TipoLista<T>& outraLista )  {

    this->criarListaVazia();    

    this->clonarLista( outraLista );

}  /*  Fim da definicao do construtor de cópia da classe TipoLista.  */        



/* Destrutor da classe TipoLista */
template <class T>
TipoLista<T>::~TipoLista()  {

    if( this->numElementos > -1 )  {

        /* Desaloca as celulas da lista */
        primeiro();
        while( temMais() )   {
            retirarItem();
        }      
          
        /* Anula a lista */
        delete( this->nodoCabeca );
        this->cursor = this->nodoCabeca = nullptr;
        this->numElementos = -1;    
    }    

}  /*  Fim da definicao do destrutor da classe TipoLista.  */        



/* Definição da sobrecarga do operador de atribuição para a classe TipoLista */
template <class T>
TipoLista<T>& TipoLista<T>::operator=( TipoLista<T>& outraLista )  {

    if( &outraLista != this )  { // Evitar auto atribuição

        this->clonarLista( outraLista );
    }    
    
    return *this;

}  /* Fim da definição da sobrecarga do operador de atribuição para a classe TipoLista */



/*  Se a lista estiver vazia, o metodo retorna  */
/*  o valor true. Senao, retorna o valor false. */
template <class T>
bool TipoLista<T>::listaVazia()  {

    return( !(this->numElementos) );

}  /*  Fim da definicao do metodo listaVazia.  */



/*  Metodo que retorna o numero de elementos da lista . */
template <class T>
long TipoLista<T>::tamanhoLista()  {

    return( this->numElementos );

}  /*  Fim da definicao do metodo tamanhoLista.  */



/*  Metodo que retorna se o cursor                  */
/*  esta apontado para um elemento valido, ou seja, */
/*  se o elemento apontado pelo cursor nao eh o     */
/*  nodo cabeca.                                    */
/*  Se tiver mais elementos, a funcao retorna       */
/*  o valor true. Senao, retorna o valor false.     */
template <class T>
bool TipoLista<T>::temMais()  {

    return( this->cursor != this->nodoCabeca );

}  /*  Fim da definicao do metodo temMais.  */



/*  Metodo que retorna se ha mais um                  */
/*  elemento valido aa direita do cursor, ou seja,    */
/*  se esse elemento nao eh o nodo cabeca.            */
/*  Se existir um proximo elemento, a funcao retorna  */
/*  o valor true. Senao, retorna o valor false.       */
template <class T>
bool TipoLista<T>::temProximo()  {

    return( this->cursor->proximo != this->nodoCabeca );

}  /*  Fim da definicao do metodo temProximo.  */



/*  Metodo que aponta o cursor para o primeiro elemento da lista. */
template <class T>
void TipoLista<T>::primeiro()  {

    this->cursor = this->nodoCabeca->proximo;

}  /*  Fim da definicao do metodo primeiro.  */



/*  Metodo que aponta o cursor para o elemento a direita */
/*  do elemento apontado pelo cursor no momento.         */
template <class T>
void TipoLista<T>::proximo()  {

    this->cursor = this->cursor->proximo;

}  /*  Fim da definicao do metodo proximo.  */        



/*  Metodo que aponta o cursor para o ultimo elemento da lista.   */
template <class T>
void TipoLista<T>::ultimo()  {

    this->cursor = this->nodoCabeca->anterior;

}  /*  Fim da definicao do metodo ultimo.  */              



/*  Metodo que aponta o cursor para o elemento a esquerda  */
/*  do elemento apontado pelo cursor no momento.           */
template <class T>
void TipoLista<T>::anterior()  {

    this->cursor = this->cursor->anterior;

}  /*  Fim da definicao do metodo anterior.  */



/*  Metodo que retorna o item apontado pelo cursor no momento.  */
template <class T>
T TipoLista<T>::getItem()  {

    return( this->cursor->item );

}  /*  Fim da definicao do metodo getItem.  */



/*  Metodo que insere um item na lista.                    */
/*  O item eh inserido antes do item apontado pelo cursor  */
/*  Apos a insercao, o cursor passa a apontar para o novo  */
/*  item.                                                  */
template <class T>
void TipoLista<T>::inserirItem( T& item )  {

    /* Aponta para a nova celula. */    
    TipoCelula<T>* temp;    
    
    /* Aponta para o cursor. Usado para     */
    /* diminuir o numero de dereferencias.  */
    TipoCelula<T>* auxCursor;    
    
    
    /* Alocando memoria para a nova celula */
    temp =  new TipoCelula<T>();	
	
    /* Armazenando o item */	   
    temp->item  =  item;
	    
    /* Ligando o auxCursor ao cursor da lista */
    auxCursor  =  this->cursor;
	    
    /* Ligando a nova Celula a Lista */
    temp->anterior = auxCursor->anterior;
    temp->proximo = auxCursor;
  	    
    /* Ligando a lista a nova Celula */
    auxCursor->anterior->proximo = temp;
    auxCursor->anterior = temp;
	    
    /* Posicionando o cursor na nova celula */
    this->cursor = temp;
    
    /* Incrementando o numero de elementos na lista */
    ++this->numElementos;    

}  /*  Fim da definicao do metodo inserirItem.  */     



/*  Metodo que retira o item apontado pelo                       */
/*  cursor no momento. Apos a remocao, o cursor passa a apontar  */
/*  para a celula a direita.                                     */
template <class T>
void TipoLista<T>::retirarItem()  {

    if( !listaVazia() )   {

        /* Aponta para a celula que sera removida. */
        TipoCelula<T>* aux;    
	  
        /* Salvando o endereco da celula que sera removida */        
        aux = this->cursor;

        /* Posicionando o cursor na celula a direita da atual */
        this->cursor = aux->proximo;
	    
        /* Desligando a lista da celula */	    
        this->cursor->anterior = aux->anterior;
        aux->anterior->proximo = this->cursor;
	    
        /* Decrementando o numero de elementos na lista */
        --this->numElementos;
	    
        /* Desalocando a celula */
        delete( aux );       
    }

}  /*  Fim da definicao do metodo retirarItem.  */ 



/*  Metodo que insere um item no inicio da lista. */
template <class T>
void TipoLista<T>::inserirNoInicio( T& item )  {

    primeiro();    
    inserirItem( item );

}  /*  Fim da definicao do metodo inserirNoInicio.  */ 



/*  Metodo que retira um item do inicio da lista. */
template <class T>
void TipoLista<T>::retirarDoInicio()  {

    primeiro();    
    retirarItem();    

}  /*  Fim da definicao do metodo retirarDoInicio.  */ 



/*  Metodo que insere um item no fim da lista.      */
template <class T>
void TipoLista<T>::inserirNoFim( T& item )  {

    ultimo();    
    proximo();
    inserirItem( item );    

}  /*  Fim da definicao do metodo inserirNoFim.  */ 



/*  Metodo que retira um item do fim da lista.  */
template <class T>
void TipoLista<T>::retirarDoFim()  {

    ultimo();    
    retirarItem();    

}  /*  Fim da definicao do metodo retirarDoFim.  */ 



/*  Metodo que faz uma insercao ordenada de item na lista.  */
/*  A insercao eh feita em ordem crescente.                 */
template <class T>
void TipoLista<T>::inserirOrdenadoCrescente( T& item )  {

    primeiro();
    
    while( temMais()  &&
           item >= this->cursor->item )   {
        proximo();
    }
    
    inserirItem( item );    

}  /*  Fim da definicao do metodo inserirOrdenadoCrescente.  */



/*  Metodo que faz uma insercao ordenada de item na lista.  */
/*  A insercao eh feita em ordem decrescente.               */
template <class T>
void TipoLista<T>::inserirOrdenadoDecrescente( T& item )  {

    primeiro();
    
    while( temMais()  &&
           item <= this->cursor->item )   {
        proximo();
    }
    
    inserirItem( item );    

}  /*  Fim da definicao do metodo inserirOrdenadoCrescente.  */



/*  Metodo que mostra a lista na saida padrao */
template <class T>
void TipoLista<T>::imprimir()  {
    

    this->primeiro();
    while( this->temMais() ) {

        this->getItem().imprimir();
        this->proximo();

        if(this->temMais()) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

}  /*  Fim da definicao do metodo mostrarLista.  */



/*  Fim das definicoes dos métodos do tipo abstrato de dados TipoLista  */







