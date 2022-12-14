GTEST_DIR=/usr/src/googletest/googletest
CXX=g++
CXXFLAGS=-g -Wall -Wextra -pthread -I$(GTEST_DIR)/include
TEST_OBJS=tests/EvalResult_test.o tests/Environment_test.o
LIBS=-L/usr/lib/x86_64-linux-gnu/
BISON=/usr/local/bin/bison

scanner:
	flex -o scanner.cpp scanner.l 
parser:
	$(BISON) parser.y -o parser.tab.cc

sp: scanner parser

all: scanner parser
	$(CXX) $(LIBS) -g main.cpp scanner.cpp parser.tab.cc -lboost_regex  -o interx.out

clean:
	rm -rf scanner.cpp
	rm -rf parser.tab.cc
	rm -rf parser.tab.hh
	rm -rf interx.out
	rm -rf tests/*.o
	rm -rf tests/gtest

gtest: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) $(GTEST_DIR)/src/gtest_main.cc  $(LIBS) -lgtest -o ./tests/$@
	./tests/$@