CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

small: main.o ll.o
	$(CXX) $(CXXFLAGS) main.o ll.o -o small

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

ll.o: ll.cc ll.h
	$(CXX) $(CXXFLAGS) -c ll.cc
clean:
	-rm -f small *.o
