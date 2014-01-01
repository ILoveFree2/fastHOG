.PHONY: all clean


OBJS=DeprecationMgr.o

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

clean:
	rm -f $(OBJS)


DeprecationMgr.o: DeprecationMgr.cpp DeprecationMgr.h ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<
