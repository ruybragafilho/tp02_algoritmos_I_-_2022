/*  Cabecalho com a declaracao do tipo abstrato de dados TipoLista.  */
/*  Esse TAD eh implementado por meio de uma estrutura duplamente    */
/*  encadeada com nodo cabeca e cursor.                              */
/*                                                                   */
/*  Autor: Ruy Braga Filho                                           */




#ifndef  TIPOLISTA_H
#define  TIPOLISTA_H




/*  Definicao do Tipo TipoCelula, usado para construir uma */
/*  estrutura duplamente encadeada, circular, com cursor   */
/*  e nodo cabeca. Os atributos do tipo sao:               */
/*                                                         */
/*  item           -   Elemento armazenado na lista.       */
/*  anterior       -   proxima celula da lista.            */
/*  proximo        -   celula anterior da lista.           */
/*                                                         */
template <class T>
class TipoCelula   {
    
    public: 

        T  item;
        TipoCelula*  anterior;
        TipoCelula*  proximo;    
};




/*  Definicao do Tipo TipoLista, implementada por uma    */
/*  estrutura duplamente encadeada, circular, com cursor */
/*  e nodo cabeca. Os atributos do tipo sao:             */
/*                                                       */
/*  nodoCabeca     -   Nodo cabeca da lista.             */
/*  cursor         -   Cursor da lista. Ele sempre       */
/*                     aponta para a celula atual. No    */
/*                     caso de insercao, ele aponta para */
/*                     a nova celula. Na retirada, ele   */
/*                     aponta para a celula da direita.  */
/*  numElementos   -   Numero de elementos na lista.     */
/*                                                       */
template <class T>
class TipoLista   {

    private:

        TipoCelula<T>* nodoCabeca = nullptr;
        TipoCelula<T>* cursor = nullptr;
        long numElementos = -1;


        /* Metodo auxiliar que cria uma lista vazia */
        void criarListaVazia();

        /* Metodo auxiliar que clona a lista passada como parâmetro */
        void clonarLista( TipoLista<T>& outraLista );        


    public:

        /* Construtor padrão da classe TipoLista. Cria uma lista vazia */
        TipoLista();

        /* Construtor de cópia da classe TipoLista. */
        TipoLista( TipoLista<T>& outraLista );        

        /* Destrutor da classe TipoLista */
        ~TipoLista();
        
        /* Sobrecarga do operador de atribuição para a classe TipoLista */        
        TipoLista<T>& operator=( TipoLista<T>& outraLista  );

        /*  Se a lista estiver vazia, o metodo retorna  */
        /*  o valor true. Senao, retorna o valor false. */
        bool listaVazia();  

        /*  Metodo que retorna o numero de elementos da lista . */
        long tamanhoLista();        

        /*  Metodo que retorna se o cursor                  */
        /*  esta apontado para um elemento valido, ou seja, */
        /*  se o elemento apontado pelo cursor nao eh o     */
        /*  nodo cabeca.                                    */
        /*  Se tiver mais elementos, a funcao retorna       */
        /*  o valor true. Senao, retorna o valor false.     */
        bool temMais();    

        /*  Metodo que retorna se ha mais um                  */
        /*  elemento valido aa direita do cursor, ou seja,    */
        /*  se esse elemento nao eh o nodo cabeca.            */
        /*  Se existir um proximo elemento, a funcao retorna  */
        /*  o valor true. Senao, retorna o valor false.       */
        bool temProximo();            

        /*  Metodo que aponta o cursor para o primeiro elemento da lista. */
        void primeiro();        

        /*  Metodo que aponta o cursor para o elemento a direita */
        /*  do elemento apontado pelo cursor no momento.         */
        void proximo();     

        /*  Metodo que aponta o cursor para o ultimo elemento da lista.   */
        void ultimo();           

        /*  Metodo que aponta o cursor para o elemento a esquerda  */
        /*  do elemento apontado pelo cursor no momento.           */
        void anterior();        

        /*  Metodo que retorna o item apontado pelo cursor no momento.  */
        T getItem();        

        /*  Metodo que insere um item na lista.                    */
        /*  O item eh inserido antes do item apontado pelo cursor  */
        /*  Apos a insercao, o cursor passa a apontar para o novo  */
        /*  item.                                                  */
        void inserirItem( T& item );        

        /*  Metodo que retira o item apontado pelo                       */
        /*  cursor no momento. Apos a remocao, o cursor passa a apontar  */
        /*  para a celula a direita.                                     */
        void retirarItem();        

        /*  Metodo que insere um item no inicio da lista. */
        void inserirNoInicio( T& item );

        /*  Metodo que retira um item do inicio da lista. */
        void retirarDoInicio();        

        /*  Metodo que insere um item no fim da lista.      */
        void inserirNoFim( T& item );

        /*  Metodo que retira um item do fim da lista.  */
        void retirarDoFim();        

        /*  Metodo que faz uma insercao ordenada de item na lista.  */
        /*  A insercao eh feita em ordem crescente.                 */
        void inserirOrdenadoCrescente( T& item );

        /*  Metodo que faz uma insercao ordenada de item na lista.  */
        /*  A insercao eh feita em ordem decrescente.               */
        void inserirOrdenadoDecrescente( T& item );

        /*  Metodo que mostra a lista na saida padrao */
        void imprimir();        
};


#include  "TipoLista.cpp"


#endif	/* TIPOLISTA_H */



/*  Fim do cabecalho com a declaracao do tipo abstrato de dados TipoLista  */







