.PHONY: all clean clean_all cleanLibs objects

DIRS=FreeImage fastHOG

all: objects
	@$(MAKE) -C ../objs

objects:
	@$(foreach DIR,$(DIRS), $(MAKE) -C $(DIR);)

clean:
	@$(MAKE) -C fastHOG clean

clean_all: 
	@$(foreach DIR,$(DIRS), $(MAKE) -C $(DIR) clean;)

cleanLibs:
	@$(MAKE) -C FreeImage clean

