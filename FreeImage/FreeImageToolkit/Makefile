.PHONY: all clean

CC=g++

OBJS=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))

all: $(OBJS)
	@cp $(OBJS) ../../objs

%.o: %.cpp ../Utilities.h
	@ln -s ../Utilities.h ./.
	$(CC) -c -o $@ $<
	@rm Utilities.h

clean:
	rm -f *.o
