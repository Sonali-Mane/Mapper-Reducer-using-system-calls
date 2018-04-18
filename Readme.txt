mapper-

  1. mapper takes input from input.txt
  2. then run command to make executable file for mapper.c: gcc -o mapper mapper.c


Reducer- 
  1.Reducer takes input from standard input
  2.To make executable file for reducer.c run command:      gcc -o reducer reducer.c



Combiner-
  1. to make executable file for combiner run command:      gcc -o combiner combiner.c
  2.  Run combiner using command:  ./combiner 
  Note that- combiner takes executable file- make sure that name of executable file for mapper.c sould be- mapper
     and reducer must be- reducer.c

---------------------------------------------------------------------------------------------------------------------

OR

1.make sure that input.txt file is present to feed input to mapper and 
2.Run Makefile  execute command:     make -f Makefile
