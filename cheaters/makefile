plagarismChecker: main.o linkedlist.o
	g++ -std=c++11 -o plagarismChecker main.o linkedlist.o
driver: main.cpp linkedlist.h
	g++ -std=c++11 -c -g main.cpp
linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -std=c++11 -c -g linkedlist.cpp
