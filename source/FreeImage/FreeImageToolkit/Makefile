.PHONY: all clean

OBJS=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)
clean:
	rm -f $(OBJS)

%.o: %.cpp ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<
