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



/* Método que faz os cursores de todas as listas de adjacencia */
/* do grafo apontarem para a primeira aresta da lista.         */
template <class T>
void TipoGrafo<T>::resetCursores()  {

    long numVertices = this->numVertices;

    for( long i=0; i<numVertices; ++i )  {

        this->listaDeAdjacencia[i].primeiro();
    }    

}  /*  Fim da definicao do metodo resetarCursores.  */       



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



/*  Metodo que insere uma aresta de peso p entre os   */
/*  vertices u e v do grafo passado como parametro.   */
/*  A aresta é inserida na lista de adjacência de u   */
/*  em ordem decrescente de peso.                     */
template <class T>
void TipoGrafo<T>::inserirArestaOrdenadoDecrescente(  long peso, long u, long v  )  {

    T aresta( v, peso );
    this->listaDeAdjacencia[u].inserirOrdenadoDecrescente( aresta );   
    
}  /*  Fim da definicao do metodo inserirAresta.  */  



/*  Metodo que retira a aresta entre os vertices u e v */
/*  do grafo passado como parametro.                   */
template <class T>
void TipoGrafo<T>::retirarAresta(  long u, long v  )  {

    /* Lista de adjacencia do vertice u */	
    TipoLista<T>*  listaAdjacenciaVerticeU  =  &(this->listaDeAdjacencia[u]);
    
    /* Vertice adjacente v a ser pesquisado */
    T  verticeAdjacente( v, 0 ); 
    
    /* Vertice adjacente na posicao atual da lista de adjacencia */
    T  verticeAdjacenciaAtual;

  	    
    /* Obtem o primeiro vertice da lista de adjacentia de u */
    listaAdjacenciaVerticeU->primeiro();
    verticeAdjacenciaAtual = listaAdjacenciaVerticeU->getItem();
  
    do  {                            	 
          
        /* Testa se encontrou a aresta pesquisada. */
        /* Se encontrou, a retira do grafo.        */
        if(  verticeAdjacente == verticeAdjacenciaAtual  )   {

            listaAdjacenciaVerticeU->retirarItem();
            break;
        }
             	 
        /* Obtem o proximo vertice da lista de adjacentia de u, se a */
        /* aresta pesquisada nao foi encontrada no passo anterior.   */
        listaAdjacenciaVerticeU->proximo();
        verticeAdjacenciaAtual = listaAdjacenciaVerticeU->getItem();

    }  while(  listaAdjacenciaVerticeU->temMais()  );  	    

}  /*  Fim da definicao do metodo retirarAresta.  */  



/* Metodo que pesquisa pelo caminho entre u e v, */
/* capaz de transportar o maior peso possível.   */
template <class T>
long TipoGrafo<T>::pesquisarCaminhoPesoMaximo( long u, long v )  {

    bool verticeVisitado[ this->numVertices ] = {false};
    long pesoMaximo = 0;
    long pesoAtual = 0;


    // Aponta os cursores do grafo para o inicio das listas de adjacencia
    resetCursores();

    // obtem o peso da aresta de maior peso , que sai do vertice u
    TipoLista<T>*  listaAdjacenciaVerticeU  =  &(this->listaDeAdjacencia[u]);
    listaAdjacenciaVerticeU->primeiro();
    TipoItem item = listaAdjacenciaVerticeU->getItem();
    pesoAtual = item.getPeso();

    // chama o metodo que vai calcular o caminho de peso maximo    
    auxPesquisarCaminhoPesoMaximo( u, v, verticeVisitado, pesoMaximo, pesoAtual );

    // retorna o caminho de peso maximo
    return pesoMaximo;

} /*  Fim da definicao do metodo pesquisarCaminhoPesoMaximo.  */



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
void TipoGrafo<T>::auxPesquisarCaminhoPesoMaximo( long u, long v, 
                                                  bool verticeVisitado[], 
                                                  long& pesoMaximo, long pesoAtual )  {

    /* Testa se chegou ao destino */
    if( u == v )  {

        if( pesoMaximo < pesoAtual )  pesoMaximo = pesoAtual;
        return;
    }

    /* Registra a visita ao vertice atual */
    verticeVisitado[u] = true;

    /* Lista de adjacencia do vertice atual */
    TipoLista<T>*  listaAdjacenciaVerticeU  =  &(this->listaDeAdjacencia[u]);


    /* procura caminhos a partir do vertice atual ate o vertice v */
    /* usando busca em profundidade.                              */  

    listaAdjacenciaVerticeU->primeiro();

    while( listaAdjacenciaVerticeU->temMais() ) {

        T item = listaAdjacenciaVerticeU->getItem();
        long idItem = item.getID();

        /* visita o proximo vertice nao visitado da lista da */
        /* lista de adjacencia do vertice atual              */
        if( !verticeVisitado[idItem] ) {           

            long pesoItem = item.getPeso();    
    
            /* faz uma poda nas buscas, descartando caminhos */
            /* que serao piores que o melhor caminho atual.  */
            if( pesoItem >= pesoMaximo ) {

                /* Contabiliza o peso maximo do caminho ate o proximo vertice */            
                if( pesoAtual > pesoItem )  { 
        
                    pesoAtual = pesoItem;
                }             
    
                auxPesquisarCaminhoPesoMaximo( idItem, v, verticeVisitado, pesoMaximo, pesoAtual );         
            }
        } 

        listaAdjacenciaVerticeU->proximo();
    }

    /* backtracking */
    verticeVisitado[u] = false;
    listaAdjacenciaVerticeU->primeiro();

} /*  Fim da definicao do metodo auxPesquisarCaminhoPesoMaximo.  */     



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




