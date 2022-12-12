scanner:
	flex -o scanner.cpp scanner.l 
parser:
	bison parser.y -o parser.tab.cc -Wcounterexamples

sp: scanner parser

all: scanner parser
	g++ -g main.cpp scanner.cpp parser.tab.cc  -o interx.out

clean:
	rm -rf scanner.cpp
	rm -rf parser.tab.cc
	rm -rf parser.tab.hh
	rm -rf interx.out