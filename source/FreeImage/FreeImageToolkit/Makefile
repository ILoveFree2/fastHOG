.PHONY: all clean

OBJS=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

%.o: %.cpp ../Utilities.h
	@ln -s ../Utilities.h ./.
	$(CC) -c -o $@ $<
	@rm Utilities.h

clean:
	rm -f *.o
