.PHONY: all clean clean_all clean_libs objects bmp_only

DIRS=FreeImage fastHOG

all: 
	@$(MAKE) objects
	@$(MAKE) link

link:
	@$(MAKE) -C ../objs

objects:
	@$(MAKE) -C ../objs clean
	@$(foreach DIR,$(DIRS), $(MAKE) -C $(DIR);)

bmp_only:
	@$(MAKE) -C ../objs clean
	@$(MAKE) -C FreeImage bmp
	@$(MAKE) -C fastHOG all

clean:
	@$(MAKE) -C fastHOG clean

clean_all: 
	@$(foreach DIR,$(DIRS), $(MAKE) -C $(DIR) clean;)

clean_libs:
	@$(MAKE) -C FreeImage clean

