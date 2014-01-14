.PHONY: all clean simple

DIRS_COMPLEX=ZLib LibJPEG LibPNG
#DIRS_COMPLEX=ZLib LibPNG
DIRS_SIMPLE=DeprecationManager Metadata

all:
	@$(foreach DIR,$(DIRS_SIMPLE),$(MAKE) -C $(DIR);)
	@$(foreach DIR,$(DIRS_COMPLEX),$(MAKE) -C $(DIR);)
	@$(MAKE) -C FreeImage all
	@$(MAKE) -C FreeImageToolkit all

simple:
	@$(foreach DIR,$(DIRS_SIMPLE),$(MAKE) -C $(DIR);)
	@$(MAKE) -C FreeImage plugin_simple
	@$(MAKE) -C FreeImageToolkit plugin_simple
	
clean:
	@$(foreach DIR,$(DIRS_SIMPLE),$(MAKE) -C $(DIR) clean;)
	@$(foreach DIR,$(DIRS_COMPLEX),$(MAKE) -C $(DIR) clean;)
	@$(MAKE) -C FreeImage clean
	@$(MAKE) -C FreeImageToolkit clean
	

