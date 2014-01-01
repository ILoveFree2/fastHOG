.PHONY: all ../fasthog clean

OBJS=$(shell find . -name "*.o")

all: ../fasthog

../fasthog: $(OBJS)
	$(CC) $(LD_FLAGS) -o $@ $^

clean:
	rm -f $(OBJS) ../fasthog

