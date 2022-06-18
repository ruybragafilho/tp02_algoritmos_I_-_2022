/*  Programa que testa as funcionalidades do TAD TipoLista. */
/*  Autor: Ruy Braga Filho                                  */




#include  <iostream>
#include  <string>

#include  "TipoItem.h"
#include  "TipoLista.h"

using namespace std;


/*  Inicio do programa  */
int main( void )   {
    
//    long i;  
   
    cout << "\n\n\n\nCriando itens";   
    TipoItem i1( 0, 10);
    TipoItem i2( 1, 11);    
    TipoItem i3( 2, 12);
    TipoItem i4( 3, 12);
    TipoItem i5( 4, 10);

    TipoItem i6( 0, 10.3);     
    TipoItem i7( 1, 11.8);
    TipoItem i8( 2, 12.1);
    TipoItem i9( 3, 12.1);
    TipoItem i10( 4, 10.3);
    cout << "\nItens criados";         

    cout << "\n\n\n\nCriando as listas" ;
    TipoLista<TipoItem> listaP;    
    TipoLista<TipoItem> listaCS;
    

    cout << "\n\nMostrando listaP Vazia\n" ;
    listaP.imprimir();
    
    cout << "\nMostrando listaCS Vazia\n" ;     
    listaCS.imprimir();

  
    
    printf( "\n\nInserindo itens na listaP, em ordem cresecnte" );
    listaP.inserirOrdenadoCrescente( i1 );
    listaP.inserirOrdenadoCrescente( i2 );
    listaP.inserirOrdenadoCrescente( i3 );
    listaP.inserirOrdenadoCrescente( i4 );
    listaP.inserirOrdenadoCrescente( i5 );

    printf( "\n\nInserindo itens na listaCS, em ordem decresecnte" );
    listaCS.inserirOrdenadoDecrescente( i6 );
    listaCS.inserirOrdenadoDecrescente( i7 );
    listaCS.inserirOrdenadoDecrescente( i8 );
    listaCS.inserirOrdenadoDecrescente( i9 );
    listaCS.inserirOrdenadoDecrescente( i10 );


    cout << "\n\nMostrando listaP - crescente\n" ;
    listaP.imprimir();
    
    cout << "\n\nMostrando listaCS - decrescente\n" ;     
    listaCS.imprimir(); 
    
    
    cout << "\n\nTestando o construtor de copia de listas";
    TipoLista<TipoItem> clone( listaP ); 
    

    cout << "\n\nMostrando clone da listaP\n" ;     
    clone.imprimir();


    cout << "\n\nAlterando o clone e mostrando as duas listas";
    clone.retirarDoFim();
    clone.retirarDoFim();

    cout << "\n\nClone\n";
    clone.imprimir();

    cout << "\n\nListaP\n";
    listaP.imprimir();

    
    cout << "\n\nDestruir Lista";    
    
    cout << "\n\n\n\nFim do teste do TAD TipoLista\n\n\n\n" ;
    
    
    return 0 ;
    
}
/*  Fim do programa.  */






