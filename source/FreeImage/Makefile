.PHONY: all clean

DIRS=ZLib LibPNG DeprecationManager FreeImage FreeImageToolkit Metadata

all:
	@$(foreach DIR,$(DIRS),$(MAKE) -C $(DIR) $@;)

clean:
	@$(foreach DIR,$(DIRS),$(MAKE) -C $(DIR) $@;)

