TARGET = main
LIBS = -lm #Math library, just a placeholder
HEADERS = Router.h Graph.h Packet.h
SRCS = main.cpp Router.cpp Packet.cpp Graph.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
CXX = g++
CXX_FLAGS = -g -Wall -std=c++11 #C++11 is just for reference, not necessary

.PHONY: default all clean

%.o: %.cpp $(HEADERS)
		    $(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
				$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
				-rm -f *.o
				-rm -f ./.depend
				-rm -f $(TARGET)
