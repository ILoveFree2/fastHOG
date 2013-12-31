.PHONY: all clean

CC=g++

all: DeprecationMgr.o
	@cp $< ../../objs
clean:
	@rm -f Utilities.h
	rm -f *.o

DeprecationMgr.o: DeprecationMgr.cpp DeprecationMgr.h ../Utilities.h
	@ln ../Utilities.h ./.
	$(CC) -c -o $@ $<
	@rm Utilities.h
