.PHONY: all clean

OBJS=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

plugin_simple: Channels.o
	@cp $^ $(BINDIR)

clean:
	rm -f $(OBJS)

%.o: %.cpp ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<
