SOURCE_DIR    =  .
BIN_DIR       =  .
OBJECT_DIR    =  .
INPUT_DIR     =  .
OUTPUT_DIR    =  .


CPP = g++
CPPFLAGS = -std=c++11  -Wall   -Werror  




Compile:  TipoItem  Principal
	$(CPP)   -o   $(BIN_DIR)/tp2   $(OBJECT_DIR)/TipoItem.o   $(OBJECT_DIR)/main.o


run:  $(BIN_DIR)/tp2
	valgrind   $(BIN_DIR)/tp2 < caso_teste_01.txt





Principal:  TipoItem  $(SOURCE_DIR)/main.cpp
	$(CPP)   $(CPPFLAGS)   -c   $(SOURCE_DIR)/main.cpp   -o   $(OBJECT_DIR)/main.o




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
	rm  -f  $(BIN_DIR)/tp2	
	rm  -f  $(OBJECT_DIR)/*.o	
	rm  -f -r  $(SOURCE_DIR)/*~     
	clear






	



	
	

	
	
	
	
	
	
	





	

	
	
	
	
