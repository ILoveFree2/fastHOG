.PHONY: all clean

OBJS=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

clean:
	rm -f *.o

FreeImageTag.o: FreeImageTag.cpp FreeImageTag.h ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<

%.o: %.cpp ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<

