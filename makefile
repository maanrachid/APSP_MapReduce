CC = g++
CPPFLAGS =  -ansi -pedantic -O3

objects = mapper.o reducer.o sha1.o  

default: 
	$(CC) $(CPPFLAGS) APSP_mapper.cpp sha1.cpp -o mapper 
	$(CC) $(CPPFLAGS) APSP_reducer.cpp sha1.cpp -o reducer 


clean:
	rm -f core *.exe *.o *~ mapper reducer 



