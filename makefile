main: main.cpp Graph.o Router.o Packet.o
	g++ main.cpp Graph.o Router.o Packet.o -o main
Graph.o: Graph.cpp
	g++ -c Graph.cpp
Router.o: Router.cpp
	g++ -c Router.cpp
Packet.o: Packet.cpp
	g++ -c Packet.cpp
clean:
	rm -rf *.o main
