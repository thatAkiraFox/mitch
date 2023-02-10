mitch: src/main.o src/funcs.o
	gcc src/main.o src/funcs.o -o mitch

src/main.o: src/main.c
	gcc -c src/main.c -o src/main.o

src/funcs.o: src/funcs.c
	gcc -c src/funcs.c -o src/funcs.o

clean:
	rm src/*.o
