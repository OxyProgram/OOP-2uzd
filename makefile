output: vector.o src_2.o
	g++ vector.o src_2.o -o output

src.o: vector.cpp header.h
	g++ -c vector.cpp

src2.o: src_2.cpp header.h
	g++ -c src_2.cpp

clean:
	rm *.o