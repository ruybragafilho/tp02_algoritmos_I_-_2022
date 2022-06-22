/*  Definicoes das funcoes do tipo abstrato de dados TipoGrafo,   */
/*  implementado por meio de listas de adjacâncias.               */
/*                                                                */
/*  Autor: Ruy Braga Filho                                        */



#include  "TipoGrafo.h"
#include  <iostream>

using std::cout;
using std::endl;


/* Construtor da classe TipoGrafo. */
template <class T>
TipoGrafo<T>::TipoGrafo(  long numVertices  )  {

    this->numVertices = numVertices;

    this->listaDeAdjacencia = new TipoLista<T>[numVertices];    

}  /*  Fim da definicao do construtor da classe TipoGrafo.  */        



/* Destrutor da classe TipoGrafo. */
template <class T>
TipoGrafo<T>::~TipoGrafo()  {

    this->numVertices = -1;
    
    delete[] this->listaDeAdjacencia;    

}  /*  Fim da definicao do destrutor da classe TipoGrafo.  */       



/*  Metodo que retorna o numero de vertices do grafo  */
template <class T>
long TipoGrafo<T>::getNumVertices()  {

    return this->numVertices;

}  /*  Fim da definicao do metodo getNumVertices.  */       



/*  Metodo que verifica se existe a aresta (u, v). */
/*  Se a aresta existir, o metodo retorna 1.       */
/*  Senao, retorna 0.                              */
template <class T>
long TipoGrafo<T>::existeAresta( long u, long v )  {

    /* Lista de adjacencia do vertice u */	
    TipoLista<T>*  listaAdjacenteVerticeU  =  &(this->listaDeAdjacencia[u]);
    
    /* Vertice adjacente v a ser pesquisado */
    T  verticeAdjacente( v, 0 ); 
    
    /* Vertice adjacente na posicao atual da lista de adjacencia */
    T  verticeAdjacenteAtual;
     
  	    
    /* Obtem o primeiro vertice da lista de adjacentia de u */
    listaAdjacenteVerticeU->primeiro();
    verticeAdjacenteAtual = listaAdjacenteVerticeU->getItem();
  
    do  {                            	 
          
        /* Testa se encontrou a aresta pesquisada. */
        /* Se encontrou, retorna 1.                */
        if(  verticeAdjacente == verticeAdjacenteAtual  )   return( 1 );
             	 
        /* Obtem o proximo vertice da lista de adjacentia de u, se a */
        /* aresta pesquisada nao foi encontrada no passo anterior.   */
        listaAdjacenteVerticeU->proximo();
        verticeAdjacenteAtual = listaAdjacenteVerticeU->getItem();

    }  while(  listaAdjacenteVerticeU->temMais()  );  	    
      
    /* Se nao encontrou a aresta pesquisada, no loop anterior, retorna 0. */
    return( 0 );    

}  /*  Fim da definicao do metodo existeAresta.  */       



/*  Metodo que insere uma aresta de peso p entre os   */
/*  vertices u e v do grafo passado como parametro.   */
template <class T>
void TipoGrafo<T>::inserirAresta(  long peso, long u, long v  )  {

    T aresta( v, peso );
    this->listaDeAdjacencia[u].inserirNoFim( aresta );   

}  /*  Fim da definicao do metodo inserirAresta.  */  



/*  Metodo que retira a aresta entre os vertices u e v */
/*  do grafo passado como parametro.                   */
template <class T>
void TipoGrafo<T>::retirarAresta(  long u, long v  )  {

    /* Lista de adjacencia do vertice u */	
    TipoLista<T>*  listaAdjacenteVerticeU  =  &(this->listaDeAdjacencia[u]);
    
    /* Vertice adjacente v a ser pesquisado */
    T  verticeAdjacente( v, 0 ); 
    
    /* Vertice adjacente na posicao atual da lista de adjacencia */
    T  verticeAdjacenteAtual;

  	    
    /* Obtem o primeiro vertice da lista de adjacentia de u */
    listaAdjacenteVerticeU->primeiro();
    verticeAdjacenteAtual = listaAdjacenteVerticeU->getItem();
  
    do  {                            	 
          
        /* Testa se encontrou a aresta pesquisada. */
        /* Se encontrou, a retira do grafo.        */
        if(  verticeAdjacente == verticeAdjacenteAtual  )   {

            listaAdjacenteVerticeU->retirarItem();
            break;
        }
             	 
        /* Obtem o proximo vertice da lista de adjacentia de u, se a */
        /* aresta pesquisada nao foi encontrada no passo anterior.   */
        listaAdjacenteVerticeU->proximo();
        verticeAdjacenteAtual = listaAdjacenteVerticeU->getItem();

    }  while(  listaAdjacenteVerticeU->temMais()  );  	    

}  /*  Fim da definicao do metodo retirarAresta.  */  



/* Metodo que pesquisa pelo caminho entre u e v, */
/* capaz de transportar o maior peso possível.   */
template <class T>
long TipoGrafo<T>::pesquisarCaminhoPesoMaximo( long u, long v )  {

    bool verticeVisitado[ this->numVertices ] = {false};
    long pesoMaximo = 0;
    long pesoAtual = 0;

    long caminho = auxPesquisarCaminhoPesoMaximo( u, v, verticeVisitado, pesoMaximo, pesoAtual );

    return caminho;

} /*  Fim da definicao do metodo pesquisarCaminhoPesoMaximo.  */



/*  Metodo que mostra o grafo na saida padrao */
template <class T>
void TipoGrafo<T>::imprimir()  {

    long numVertices = this->numVertices;

    for( long i=0; i<numVertices; ++i )  {
        cout << "\nVertice " << i << ": " ;
        this->listaDeAdjacencia[i].imprimir();
        cout << "\n";
    }

} /*  Fim da definicao do metodo imprimir.  */     



/* Metodo auxiliar que pesquisa pelo caminho entre u e v,        */
/* capaz de transportar o maior peso possível.                   */
/*                                                               */
/*   u: vertice de origem                                        */
/*   v: vertice de destino                                       */
/*   verticeVisitado: array de booleano que indicar se o vertice */
/*                    i já foi visitado no caminhamento atual.   */
/*   pesoMaximo: peso do caminho de maior peso encontrado até    */
/*               o momento.                                      */
/*   pesoAtual: peso do caminho atual                            */        
/*                                                               */
template <class T>
long TipoGrafo<T>::auxPesquisarCaminhoPesoMaximo( long u, long v, 
                                                  bool verticeVisitado[], 
                                                  long& pesoMaximo, long& pesoAtual )  {

    return 0;

} /*  Fim da definicao do metodo auxPesquisarCaminhoPesoMaximo.  */     
