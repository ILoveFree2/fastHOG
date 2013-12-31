
#  Makefile for fltk applications
# copied from http://www.di.uminho.pt/mcss2010/files/Makefile.mac

all:
	@#$(MAKE) -C boost/make
	@$(MAKE) -C FreeImage
	@$(MAKE) -C fastHOG
	@$(MAKE) -C objs ../fasthog

clean:
	@rm -f fasthog bin/*.o
	@$(MAKE) -C fastHOG clean

clean_all: clean
	@#$(MAKE) -C boost/make clean
	@$(MAKE) -C FreeImage clean
	@$(MAKE) -C fastHOG clean
