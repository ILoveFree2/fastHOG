.PHONY: all clean

OBJS=$(shell find . -name "*.o")


all: ../fasthog

../fasthog: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
