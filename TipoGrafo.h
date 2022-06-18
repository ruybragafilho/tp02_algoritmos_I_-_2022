/*  Cabecalho com a declaracao do tipo abstrato de dados TipoGrafo,  */
/*  implementado por meio de listas de adjacâncias.                  */
/*                                                                   */
/*  Autor: Ruy Braga Filho                                           */




#ifndef  TIPOGRAFO_H
#define  TIPOGRAFO_H

#include "TipoLista.h"


/*  Definicao do TipoGrafo, implementado usando   */
/*  listas de adjacencias.                        */
/*                                                */
/*  Atributos:                                    */
/*                                                */
/*    .listaAdjacente - array contendo as listas  */
/*                      de adjacencia do grafo.   */
/*                                                */
/*    .numVertices - numero de vertices do grafo. */
/*                                                */
template <class T>
class TipoGrafo   {
    
    private: 

        long numVertices;
        TipoLista<T>* listaDeAdjacencia;


    public:

        /* Construtor da classe TipoGrafo. Cria um grafo com numvertices vértices */
        TipoGrafo( long numVertices );

        /* Destrutor da classe TipoGrafo */
        ~TipoGrafo();


        /*  Metodo que retorna o numero de vertices do grafo  */
        long  getNumVertices();
                
        /*  Metodo que verifica se existe a aresta (u, v). */
        /*  Se a aresta existir, o metodo retorna 1.       */
        /*  Senao, retorna 0.                              */
        long  existeAresta( long u, long v );
                
        /*  Metodo que insere uma aresta de peso p entre os   */
        /*  vertices u e v do grafo passado como parametro.   */
        void  inserirAresta(  long peso, long u, long v  );
                
        /*  Metodo que retira a aresta entre os vertices u e v */
        /*  do grafo passado como parametro.                   */
        void  retirarAresta(  long u, long v  );
                
        /*  Prototipo do procedimento que retorna a lista de */
        /*  adjacencias do vertice passado como parametro.   */
        //TipoLista*  obtemListaAdjacencia(  TipoGrafo* grafo,  long  vertice   );      

        /*  Metodo que mostra o grafo na saida padrao */
        void imprimir();  

};



#include  "TipoGrafo.cpp"


#endif	/* TIPOGRAFO_H */


/*  Fim do cabecalho com a declaracao do tipo abstrato de dados TipoGrafo  */