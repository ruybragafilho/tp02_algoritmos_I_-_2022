SOURCE_DIR    =  .
BIN_DIR       =  .
OBJECT_DIR    =  .
INPUT_DIR     =  .
OUTPUT_DIR    =  .


CPP = g++
CPPFLAGS = -std=c++11  -Wall   -Werror  




Compile:  Ponto2D  TipoItem  Bicicleta  Pessoa  Principal
	$(CPP)   -o   $(BIN_DIR)/tp1   $(OBJECT_DIR)/Ponto2D.o   $(OBJECT_DIR)/TipoItem.o   $(OBJECT_DIR)/Bicicleta.o   $(OBJECT_DIR)/Pessoa.o   $(OBJECT_DIR)/main.o
#	$(CPP)   -o   $(BIN_DIR)/tp1   $(OBJECT_DIR)/Ponto2D.o   $(OBJECT_DIR)/TipoItem.o   $(OBJECT_DIR)/Bicicleta.o   $(OBJECT_DIR)/Pessoa.o   $(OBJECT_DIR)/CasamentoEstavel.o   $(OBJECT_DIR)/main.o	

run:  $(BIN_DIR)/tp1
	valgrind   $(BIN_DIR)/tp1 < caso_teste_01.txt





#Principal:  Ponto2D  Loja  Cliente CasamentoEstavel  $(SOURCE_DIR)/main.cpp
Principal:  Ponto2D  TipoItem  Bicicleta  Pessoa $(SOURCE_DIR)/main.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/main.cpp   -o   $(OBJECT_DIR)/main.o


CasamentoEstavel:  $(SOURCE_DIR)/CasamentoEstavel.h  $(SOURCE_DIR)/CasamentoEstavel.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/CasamentoEstavel.cpp   -o   $(OBJECT_DIR)/CasamentoEstavel.o	


Pessoa:  $(SOURCE_DIR)/Pessoa.h  $(SOURCE_DIR)/Pessoa.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/Pessoa.cpp   -o   $(OBJECT_DIR)/Pessoa.o	


Bicicleta:  $(SOURCE_DIR)/Bicicleta.h  $(SOURCE_DIR)/Bicicleta.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/Bicicleta.cpp   -o   $(OBJECT_DIR)/Bicicleta.o	


Ponto2D:  $(SOURCE_DIR)/Ponto2D.h  $(SOURCE_DIR)/Ponto2D.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/Ponto2D.cpp   -o   $(OBJECT_DIR)/Ponto2D.o	


TesteTipoGrafo:  TipoItem  $(SOURCE_DIR)/TipoLista.h  $(SOURCE_DIR)/TipoGrafo.h
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/TesteTipoGrafo.cpp   -o   $(OBJECT_DIR)/TesteTipoGrafo.o	
	$(CPP)   -o   $(BIN_DIR)/testeTipoGrafo.bin   $(OBJECT_DIR)/TesteTipoGrafo.o   $(OBJECT_DIR)/TipoItem.o
	valgrind   $(BIN_DIR)/testeTipoGrafo.bin	


TesteTipoLista2:  TipoItem  $(SOURCE_DIR)/TipoLista.h  $(SOURCE_DIR)/TesteTipoLista2.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/TesteTipoLista2.cpp   -o   $(OBJECT_DIR)/TesteTipoLista2.o	
	$(CPP)   -o   $(BIN_DIR)/testeTipoLista2.bin   $(OBJECT_DIR)/TesteTipoLista2.o   $(OBJECT_DIR)/TipoItem.o
	valgrind   $(BIN_DIR)/testeTipoLista2.bin


TesteTipoLista:  TipoItem  $(SOURCE_DIR)/TipoLista.h  $(SOURCE_DIR)/TesteTipoLista.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/TesteTipoLista.cpp   -o   $(OBJECT_DIR)/TesteTipoLista.o	
	$(CPP)   -o   $(BIN_DIR)/testeTipoLista.bin   $(OBJECT_DIR)/TesteTipoLista.o   $(OBJECT_DIR)/TipoItem.o
	valgrind   $(BIN_DIR)/testeTipoLista.bin


TipoItem:  $(SOURCE_DIR)/TipoItem.h  $(SOURCE_DIR)/TipoItem.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/TipoItem.cpp   -o   $(OBJECT_DIR)/TipoItem.o	


clean:
	rm  -f  $(BIN_DIR)/*.bin
	rm  -f  $(BIN_DIR)/tp1	
	rm  -f  $(OBJECT_DIR)/*.o	
	rm  -f -r  $(SOURCE_DIR)/*~     
	clear






	



	
	

	
	
	
	
	
	
	





	

	
	
	
	
