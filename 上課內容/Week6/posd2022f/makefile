.PHONY: dirs clean stat

SRC = src/hello.h src/circle.h src/square.h src/shape.h src/composite_shape.h src/iterator.h src/null_iterator.h src/find_first_visitor.h

TEST = test/ut_hello.h test/ut_circle.h test/ut_sort.h test/ut_square.h test/ut_shape.h

all: dirs ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC) obj/iterator.o obj/find_first_visitor.o
	g++ -std=c++11 -Wfatal-errors -Wall test/ut_main.cpp obj/iterator.o obj/find_first_visitor.o -o bin/ut_main -lgtest -lpthread

obj/iterator.o: src/iterator.h src/iterator.cpp
	g++ -std=c++11 -Wfatal-errors -Wall -c src/iterator.cpp -o obj/iterator.o

obj/find_first_visitor.o: src/find_first_visitor.h src/find_first_visitor.cpp
	g++ -std=c++11 -Wfatal-errors -Wall -c src/find_first_visitor.cpp -o obj/find_first_visitor.o

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/* obj/*

stat:
	wc -l src/* test/*.h test/*.cpp
