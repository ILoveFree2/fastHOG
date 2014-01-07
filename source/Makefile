.PHONY: all clean clean_all clean_libs objects simple

DIRS=FreeImage fastHOG

all: 
	@$(MAKE) objects
	@$(MAKE) link

link:
	@$(MAKE) -C ../objs

objects:
	@$(MAKE) -C ../objs clean
	@$(foreach DIR,$(DIRS), $(MAKE) -C $(DIR);)

simple:
	@$(MAKE) -C ../objs clean
	@$(MAKE) -C FreeImage simple
	@$(MAKE) -C fastHOG all

clean:
	@$(MAKE) -C fastHOG clean

clean_all: 
	@$(foreach DIR,$(DIRS), $(MAKE) -C $(DIR) clean;)

clean_libs:
	@$(MAKE) -C FreeImage clean

