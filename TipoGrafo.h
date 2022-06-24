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

        /* Atribudo que armazena o número de vértices do grafo. */
        long numVertices;

        /* Array contendo as listas de adjacências dos vértices. */
        TipoLista<T>* listaDeAdjacencia;


        /* Método que faz os cursores de todas as listas de adjacencia */
        /* do grafo apontarem para a primeira aresta da lista.         */
        void resetCursores();


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
        void auxPesquisarCaminhoPesoMaximo( long u, long v, 
                                            bool verticeVisitado[], 
                                            long& pesoMaximo, long pesoAtual );


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

        /*  Metodo que insere uma aresta de peso p entre os   */
        /*  vertices u e v do grafo passado como parametro.   */
        /*  A aresta é inserida na lista de adjacência de u   */
        /*  em ordem decrescente de peso.                     */
        void  inserirArestaOrdenadoDecrescente(  long peso, long u, long v  );        
                
        /*  Metodo que retira a aresta entre os vertices u e v */
        /*  do grafo passado como parametro.                   */
        void  retirarAresta(  long u, long v  );
                
        /*  Metodo que retorna a lista de adjacencias */
        /*  do vertice passado como parametro.        */
        //TipoLista*  obtemListaAdjacencia(  TipoGrafo* grafo,  long  vertice   );      


        /* Metodo que pesquisa pelo caminho entre u e v, */
        /* capaz de transportar o maior peso possível.   */
        long pesquisarCaminhoPesoMaximo( long u, long v );


        /*  Metodo que mostra o grafo na saida padrao */
        void imprimir();  

};



#include  "TipoGrafo.cpp"


#endif	/* TIPOGRAFO_H */


/*  Fim do cabecalho com a declaracao do tipo abstrato de dados TipoGrafo  */