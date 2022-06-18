/*  Programa que testa as funcionalidades do TAD TipoGrafo. */
/*  Autor: Ruy Braga Filho                                  */




#include   <iostream>

#include  "TipoItem.h"
#include  "TipoLista.h"
#include  "TipoGrafo.h"

using namespace std;


#define  NUM_VERTICES  10




int  main()   {
  
    TipoGrafo<TipoItem> g( NUM_VERTICES ); 
    
    
    cout <<  "\n\n\n\nInicio do teste do TAD TipoGrafo\n\n\n\n\n\n";

    
    cout <<  "\n\n\n\n\nMostrando Grafo Vazio\n\n";
    g.imprimir();
    cout <<  "\nGrafo mostrado";
    
    
    cout <<  "\n\n\n\n\nInserindo arestas no Grafo (4,7) = 143, (3,8) = 458, (1,1) = 987, (1,4) = 749, (1,8) = 529.84, (9,2) = 901 ";
    g.inserirAresta(  143, 4, 7  );    
    g.inserirAresta(  458, 3, 8  );
    g.inserirAresta(  987, 1, 1  );
    g.inserirAresta(  749, 1, 4  );
    g.inserirAresta(  529, 1, 8  );
    g.inserirAresta(  901, 9, 2  );    
    cout <<  "\nArestas Inseridas";
    
    
    cout <<  "\n\n\n\n\nMostrando Grafo\n\n";
    g.imprimir();
    cout <<  "\nGrafo mostrado";
    
    
    cout <<  "\n\n\n\nVerificando a existencia de arestas";
    cout <<  "\nAresta (1,4):  " <<  ( g.existeAresta( 1, 4 ) ?  "EXISTE" : "NAO EXISTE" );
    cout <<  "\nAresta (4,7):  " <<  ( g.existeAresta( 4, 7 ) ?  "EXISTE" : "NAO EXISTE" );    
    cout <<  "\nAresta (7,1):  " <<  ( g.existeAresta( 7, 1 ) ?  "EXISTE" : "NAO EXISTE" );
    cout <<  "\nExistencia de arestas verificada";


    cout << "\n\n\n\n\nRetirando a aresta (4,7) do Grafo";
    g.retirarAresta(  4, 7  );
    cout << "\nAresta retirada";    


    cout <<  "\n\n\n\nVerificando a existencia de arestas";
    cout <<  "\nAresta (1,4):  " <<  ( g.existeAresta( 1, 4 ) ?  "EXISTE" : "NAO EXISTE" );
    cout <<  "\nAresta (4,7):  " <<  ( g.existeAresta( 4, 7 ) ?  "EXISTE" : "NAO EXISTE" );    
    cout <<  "\nAresta (7,1):  " <<  ( g.existeAresta( 7, 1 ) ?  "EXISTE" : "NAO EXISTE" );
    cout <<  "\nExistencia de arestas verificada";    
    
        
    cout <<  "\n\n\n\n\n\nFim do teste do TAD TipoGrafo\n\n\n\n";    
  
  
    return( 0 );  
  
}
/*  Fim do programa.  */