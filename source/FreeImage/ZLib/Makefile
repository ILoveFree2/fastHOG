.PHONY: all clean

OBJS=$(patsubst %.c,%.o,$(shell find . -name "*.c"))

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

clean:
	rm -f $(OBJS)
