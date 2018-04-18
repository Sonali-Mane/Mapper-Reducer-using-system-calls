all: 
	gcc -o mapper mapper.c -I.
	gcc -o reducer reducer.c -I.
	gcc -o combiner combiner.c -I.
	./combiner

