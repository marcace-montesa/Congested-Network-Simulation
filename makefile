main: main.cpp Graph.o Router.o Packet.o Observer.o Subject.o
	g++ main.cpp Graph.o Router.o Packet.o Observer.o Subject.o -o main
Graph.o: Graph.cpp
	g++ -c Graph.cpp
Router.o: Router.cpp
	g++ -c Router.cpp
Packet.o: Packet.cpp
	g++ -c Packet.cpp
Observer.o: Observer.h
	g++ -c Observer.h
Subject.o: Subject.h
	g++ -c Subject.h
clean:
	rm -rf *.o main
