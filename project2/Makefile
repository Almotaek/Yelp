#THE MAKE FILE

CC=gcc
CFLAGS = -I
OBJ= main.o ArrayList.o ArrayListStrings.o btl.o btName.o loadData.o Restaurant.o userInter.o


all: $(OBJ)
	$(CC) *o -o ./test

main.o: main.c 
	$(CC) -c -g main.c

btl.o: btl.c btl.h
	$(CC) -c -g btl.c
ArrayList.o: ArrayList.c ArrayList.h
	$(CC) -c -g ArrayList.c
btName.o: btName.c btName.h
	$(CC) -c -g btName.c
loadData.o: loadData.c loadData.h
	$(CC) -c -g loadData.c
Restaurant.o: Restaurant.c Restaurant.h
	$(CC) -c -g Restaurant.c
userInter.o: userInter.c userInter.h
	$(CC) -c -g userInter.c

.PHONY: clean
clean:
	rm *.o
	rm ./test


