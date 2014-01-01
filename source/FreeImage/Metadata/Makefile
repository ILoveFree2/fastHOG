.PHONY: all clean

OBJS=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

FreeImageTag.o: FreeImageTag.cpp FreeImageTag.h ../Utilities.h
	@ln -s ../Utilities.h ./.
	$(CC) -c -o $@ $<
	@rm Utilities.h

TagLib.o: TagLib.cpp ../Utilities.h
	@ln -s ../Utilities.h ./.
	$(CC) -c -o $@ $<
	@rm Utilities.h

clean:
	rm -f *.o
