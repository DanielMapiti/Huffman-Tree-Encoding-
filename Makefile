CC=g++
LIBS=-lm

huffencode: HuffmanTree.o HuffmanNode.o Huffencode.o HuffmanNode.h HuffmanTree.h 
	$(CC)  *.o *.h -o huffencode $(LIBS)

HuffmanTree.o: HuffmanTree.cpp
	$(CC)  HuffmanTree.cpp -c

HuffmanNode.o: HuffmanNode.cpp
	$(CC)  HuffmanNode.cpp -c

Huffencode.o: Huffencode.cpp
	$(CC)  Huffencode.cpp -c

clean:
	@rm -f *.o

install:
	@mv huffencode ~/bin

run:
	./huffencode

