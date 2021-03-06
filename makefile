output: src.o src2.o
	g++ src.o src2.o -o output

src.o: src.cpp header1.h
	g++ -c src.cpp

src2.o: src2.cpp header1.h
	g++ -c src2.cpp

clean:
	rm *.o