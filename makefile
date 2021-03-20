output: src.o functions.o
	g++ src.o functions.o -o output

src.o: src.cpp header.h
	g++ -c src.cpp

src2.o: functions.cpp header.h
	g++ -c functions.cpp

clean:
	rm *.o
	rm *.txt