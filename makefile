all: main.c
	gcc -o list main.c

run:
	./list

clear:
	rm *.o