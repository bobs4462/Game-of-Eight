CC=gcc -I. -g


OBJ=main.o eight.o search.o btree.o
HEADER=eight.h btree.h


PARAM= -O2 -o


game:$(OBJ)
	$(CC) $(PARAM) game $(OBJ)

$(OBJ):$(HEADER) 

clean:
	rm $(OBJ) game
