.PHONY: all clean

OBJS=$(patsubst %.c,%.o,$(shell find . -name "*.c"))
HEADERS=$(shell find . -name "*.h")

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

clean:
	rm -f $(OBJS)

%.o: %.c $(HEADERS)
	@$(CC) $(CCFLAGS) -c -I. -o $@ $<
