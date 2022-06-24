/* Módulo principal do programa. Contém a função main e */
/* funções para carregar dados e mostrar resultados.    */
/*                                                      */
/* Autor: Ruy Braga Filho                               */



#include "TipoItem.h"
#include "TipoLista.h"
#include "TipoGrafo.h"

#include <iostream>
#include <string>
#include <array>

using std::size_t;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;



/* Prototipo da funcao que carrega o Grafo contendo    */
/* as n cidades (vertices) e as m rodovias (arestas).  */
void carregarGrafo( TipoGrafo<TipoItem>& grafo, long m );



/* Definição da função main */
int main()  {

    long maiorCaminho;

    /* Número de Cidades */
    long n; 
    cin >> n;    

    /* Número de Rodovias */
    long m;
    cin >> m;

    /* Número de Consultas */
    long q;
    cin >> q;
    
    /* Grafo contendo as cidades (vertices) e as */
    /* rodovias (arestas).                       */
    TipoGrafo<TipoItem> grafo( n );
    carregarGrafo( grafo, m );

    /* Consultas */    
    long u;
    long v;
    for( long i=0; i<q; ++i )  {

        cin >> u;
        cin >> v;
   
        maiorCaminho = grafo.pesquisarCaminhoPesoMaximo( u-1, v-1 );
        cout << maiorCaminho << "\n";
    }

    return 0;

}  /* Fim da definição da função main */




/* Definicao da funcao que carrega o Grafo contendo    */
/* as n cidades (vertices) e as m rodovias (arestas).  */  
void carregarGrafo( TipoGrafo<TipoItem>& grafo, long m )  {

    long u;
    long v;
    long capacidade;

    for( long i=0; i<m; ++i )  {

        cin >> u;
        cin >> v;
        cin >> capacidade;

        grafo.inserirArestaOrdenadoDecrescente( capacidade, u-1, v-1 );
    }

} // Fim da funcao carregarGrafo