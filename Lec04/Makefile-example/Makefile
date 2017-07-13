main: main.cpp isPositive.o isNegative.o
	g++ main.cpp isPositive.o isNegative.o -o main 

mainAssembly: main.cpp
	g++ -S main.cpp

isPositive.o: isPositive.cpp
	g++ -c isPositive.cpp

isNegative.o: isNegative.cpp
	g++ -c isNegative.cpp

clean:
	rm -f *.o *.S main

linkerError: main.cpp isPositive.o # forgot isNegative.o
	g++ main.cpp isPositive.o -o main 