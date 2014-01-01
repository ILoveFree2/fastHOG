.PHONY: all clean clean_all cleanLibs

all:
	@#$(MAKE) -C boost/make
	@$(MAKE) -C FreeImage
	@$(MAKE) -C fastHOG
	@$(MAKE) -C ../objs ../fasthog

clean:
	@rm -f fasthog bin/*.o
	@$(MAKE) -C fastHOG clean

clean_all: clean cleanLibs

cleanLibs:
	@#$(MAKE) -C boost/make clean
	@$(MAKE) -C FreeImage clean
	@$(MAKE) -C fastHOG clean
