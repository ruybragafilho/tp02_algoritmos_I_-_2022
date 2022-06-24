/*  Cabecalho com a declaracao do tipo abstrato de dados TipoItem        */
/*  utilizado para representar um elemento da lista duplamente encadeada */
/*                                                                       */
/*  Autor: Ruy Braga Filho                                               */




#ifndef  TIPOITEM_H
#define  TIPOITEM_H




/*  Definicao do tipo TipoItem, usado para representar    */
/*  um elemento da lista duplamente encadeada.            */
/*                                                        */
/*  id - id do registro que será armazenado na lista.     */
/*  peso - Peso do registro. Usado para ordenar a lista.  */
/*                                                        */
class TipoItem   {
	
	private: 
    
        long  id;
        long  peso;      

        
    public:
    
        /*  Construtores  */
        TipoItem(): id(-1), peso(-1.0) {}    
        TipoItem( long id, double peso ): id(id), peso(peso) {}
    	
    
        /*  Método que ajusta o atributo id com */
        /*  o valor passado como parametro.     */
        void setID( long id );    
        
        /*  Método que retorna o atributo id  */
        long getID();
            
        /*  Método que ajusta o atributo peso com  */
        /*  o valor passado como parametro.        */
        void setPeso( long peso );    
        
        /*  Método que retorna o atributo peso  */
        long getPeso();          

        /*  Método que imprime o item  */
        void imprimir();        

        /* Sobrecarga de operadores relacionais */
        bool operator<=(TipoItem& i) const;
        bool operator>=(TipoItem& i) const;              
        bool operator==(TipoItem& i) const;
};


#endif	/* TIPOITEM_H */


/*  Fim do cabecalho com a declaracao do tipo abstrato de dados TipoItem  */







