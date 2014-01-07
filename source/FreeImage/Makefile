.PHONY: all clean bmp

DIRS_ALL=ZLib LibPNG DeprecationManager FreeImageToolkit Metadata FreeImage
DIRS_BMP=DeprecationManager FreeImageToolkit Metadata

all: 
	@$(foreach DIR,$(DIRS_ALL),$(MAKE) -C $(DIR) $@;)

bmp:
	@$(foreach DIR,$(DIRS_BMP),$(MAKE) -C $(DIR);)
	@$(MAKE) -C FreeImage plugin_bmp
	
clean:
	@$(foreach DIR,$(DIRS_ALL),$(MAKE) -C $(DIR) $@;)

