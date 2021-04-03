output: src.o functions.o functionsList.o functionsDeque.o
	g++ src.o functions.o functionsList.o functionsDeque.o -o output

src.o: src.cpp header.h
	g++ -c src.cpp

src2.o: functions.cpp header.h
	g++ -c functions.cpp

src3.o: functionsList.cpp header.h
	g++ -c functionsList.cpp

src4.o: functionsDeque.cpp header.h
	g++ -c functionsDeque.cpp

clean:
	rm *.o
	rm *.txt