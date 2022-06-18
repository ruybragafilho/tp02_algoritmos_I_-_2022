/* Módulo principal do programa. Contém a função main e */
/* funções para carregar dados e mostrar resultados.    */
/*                                                      */
/* Autor: Ruy Braga Filho                               */


#include "Ponto2D.h"
#include "Bicicleta.h"
#include "Pessoa.h"
#include "TipoItem.h"
#include "TipoLista.h"
//#include "CasamentoEstavel.h"

#include <iostream>
#include <string>
//#include <cmath>
#include <array>

using std::size_t;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;



/* Prototipo da função que carrega o número de pessoas e bicicletas */
void carregarNumeroDeEntidades( long& n );


/* Prototipo da função que carrega as dimenções do grid */
void carregarDimensoesGrid( long& linhas, long& colunas );

/* Prototipo da função que cria um mapa (grid) */
char** criarMapa( long linhas, long colunas );


/* Prototipo da função que carrega o mapa (grid) */
void carregarMapa( char** mapa, long linhas, long colunas );


/* Prototipo da função que mostra o mapa (grid) */
void mostrarMapa( char** mapa, long linhas, long colunas );


/* Prototipo da função que desaloca o mapa (grid) */
void destruirMapa( char** mapa, long linhas );


/* Prototipo da função que carrega a tabela de preferência das pessoas pelas bicicletas */
TipoLista<TipoItem>* carregarTabelaPreferenciaDasPessoas( long numEntidades );



/* Prototipo da função que carrega as bicicletas */
void carregarBicicletas( TipoLista<Bicicleta>& bicicleta, long numBicicletas );


/* Prototipo da função que carrega as pessoas */
void carregarPessoas( TipoLista<Pessoa>& pessoa, long numPessoas );



/* Prototipo da função que imprime o resultado do casamento estavel de acordo com o TP.  */
/* A função imprime as pares Pessoa - Bicicleta.                                         */
void imprimirCasamentoEstavel( TipoLista<Pessoa>* match );                        



/* Definição da função main */
int main()  {

    cout << "\n\nInicio\n\n";


    /* Número de Pessoas e Bicicletas */
    long n;
    carregarNumeroDeEntidades( n );
    cout << "n: " << n;


    /* Dimensões do grid */
    long linhas = 0;
    long colunas = 0;
    carregarDimensoesGrid( linhas, colunas );
    cout << "\nDimensoes Grid: (" << linhas << ", " << colunas << ")\n\n";


    /* Mapa */
 
    char** mapa = criarMapa( linhas, colunas );

    carregarMapa( mapa, linhas, colunas );
    mostrarMapa( mapa, linhas, colunas );

    destruirMapa( mapa, linhas );



    /* Lista de Bicicletas */
    TipoLista<Bicicleta> bicicleta;
    carregarBicicletas( bicicleta, n );

    cout << "\n\n Lista de Bicicletas\n";
    bicicleta.imprimir();


    /* Lista de Pessoas */
    TipoLista<Pessoa> pessoa;
    carregarPessoas( pessoa, n );

    cout << "\n\n Lista de Pessoas\n";
    pessoa.imprimir(); 

       
   
    /* Tabela de Preferencia Das Pessoas por bicicletas */
    TipoLista<TipoItem>* tabelaPreferenciaDasPessoas = carregarTabelaPreferenciaDasPessoas( n );
    cout << "\n\nTabela de Preferências das Pessoas\n"; 
    for(long i=0; i<n; ++i)  {

        tabelaPreferenciaDasPessoas[i].imprimir();        
    }
    if( tabelaPreferenciaDasPessoas != nullptr ) delete[] tabelaPreferenciaDasPessoas;

    /* Tabela que conterá o resultado. Cada linha i da tabela representa */
    /* o par Pessoa - Bicicleta.             */
//    TipoLista<Pessoa>* match = new TipoLista<Cliente>[ loja.tamanhoLista() ];

    /* Criando uma instância do casamento estável */
//    CasamentoEstavel ce( &cliente, &loja );

    /* Executa o algoritmo de Gale-Shapley */
//    ce.galeShapley( match );

    /* Imprime o resultado */
//    imprimirCasamentoEstavel( match, loja.tamanhoLista() );

    /* Desalocando a tabela com o resultado do casamento estável */
//    delete[] match;

   
    cout << "\n\nFim\n\n";    

    return 0;

}  /* Fim da definição da função main */



/* Definição da função que carrega o número de pessoas e bicicletas */
void carregarNumeroDeEntidades( long& n )  {

    cin >> n;

}  /* Fim da definição da função carregarNumeroDeEntidades */



/* Definição da função que carrega as dimenções do grid */
void carregarDimensoesGrid( long& linhas, long& colunas )  {

    cin >> linhas;
    cin >> colunas;

}  /* Fim da definição da função carregarDimensoesGrid */


/* Definição da função que cria um mapa (grid) */
char** criarMapa( long linhas, long colunas )  {

    char** mapa = new char*[linhas];

    for( long i=0; i<linhas; ++i )  {
        mapa[i] = new char[colunas];
    }

    return mapa;
}  /* Fim da definição da função criarMapa */


/* Definição da função que carrega o mapa (grid) */
void carregarMapa( char** mapa, long linhas, long colunas )  {

    if( mapa != nullptr )  {

        for( long i=0; i<linhas; ++i )  {

            for( long j=0; j<colunas; ++j )  {
                // mapa[i][j] = 'b';
                cin >> mapa[i][j];
            }
        }
    }
}  /* Fim da definição da função carregarMapa */



/* Definição da função que mostra o mapa (grid) */
void mostrarMapa( char** mapa, long linhas, long colunas )  {

    if( mapa != nullptr )  {

        for( long i=0; i<linhas; ++i )  {
    
            for( long j=0; j<colunas; ++j )  {
                cout << mapa[i][j] << ' ';            
            }
            cout << '\n';
        }    
    }
}  /* Fim da definição da função mostrarMapa */


/* Definição da função que desaloca o mapa (grid) */
void destruirMapa( char** mapa, long linhas )  {

    if( mapa != nullptr )  {
   
        for( long i=0; i<linhas; ++i )  {
    
            delete[] mapa[i];        
        }    
        delete[] mapa;
    }
}  /* Fim da definição da função destruirMapa */


/* Definição da função que carrega a tabela de preferência das pessoas pelas bicicletas */
TipoLista<TipoItem>* carregarTabelaPreferenciaDasPessoas( long numEntidades )  {

    TipoLista<TipoItem>* tabelaPreferenciaPessoas = new TipoLista<TipoItem>[numEntidades];
    long preferencia;

    for( long i=0; i<numEntidades; ++i ) {

        for( long j=0; j<numEntidades; ++j ) {
           
            cin >> preferencia;
            TipoItem preferenciaBike( j, preferencia );
            tabelaPreferenciaPessoas[i].inserirOrdenadoDecrescente( preferenciaBike );                
        }        
    }    

    return tabelaPreferenciaPessoas;

}  /* Fim da definição da função carregarTabelaPreferenciaDasPessoas */


/* Definição da função que desaloca a memória da tabela de preferência das pessoas pelas bicicletas */
void desalocarTabela( TipoLista<TipoItem>* tabela )  {

    delete[] tabela;

}  /* Fim da definição da função desalocarTabelaPreferenciaDasPessoas */





/* Definição da função que carrega as bicicletas */
void carregarBicicletas( TipoLista<Bicicleta>& bicicleta, long numBicicletas  )  {

    // Carrega os dados de cada bicicleta
    for( long i=0; i<numBicicletas; ++i )  {

        Ponto2D ponto;
        Bicicleta b( i, ponto );

        bicicleta.inserirNoFim( b );
    }    

}  /* Fim da definição da função carregarBicicletas */



/* Definição da função que carrega as pessoas */
void carregarPessoas( TipoLista<Pessoa>& pessoa, long numPessoas )  {

    // Carrega os dados de cada pessoa
    for( long i=0; i<numPessoas; ++i )  {

        Ponto2D ponto;
        Pessoa p( i, ponto );

        pessoa.inserirNoFim( p );
    }    

}  /* Fim da definição da função carregarPessoas */


/* Definição da função que imprime o resultado do casamento estavel de acordo com o TP.  */
/* A função imprime a lista de clientes de cada loja.                                    */
//void imprimirCasamentoEstavel( TipoLista<Cliente>* match,
//                               long numLojas )  {

//    for( long i=0; i<numLojas; ++i )  {

//        cout << i << endl;
//        match[i].imprimir();
//    }

//}  /* Fim da definição da função imprimirCasamentoEstavel */                        