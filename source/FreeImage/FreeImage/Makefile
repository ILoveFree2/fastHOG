.PHONY: all clean plugin_simple

OBJS_ALL=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp" -not -name "Plugin*.cpp"))
OBJS_PLUGIN=$(shell find . -name "Plugin*.o")

all: Plugin_all.cpp Plugin_all.o PluginBMP.o PluginGIF.o PluginJPEG.o PluginPNG.o $(OBJS_ALL)
	@cp Plugin_all.o PluginBMP.o PluginGIF.o PluginJPEG.o PluginPNG.o $(OBJS_ALL) $(BINDIR)

plugin_simple: Plugin_simple.cpp Plugin_simple.o PluginBMP.o PluginGIF.o $(OBJS_ALL)
	@cp Plugin_simple.o PluginBMP.o PluginGIF.o $(OBJS_ALL) $(BINDIR)

clean:
	rm -f $(OBJS_ALL) $(OBJS_PLUGIN)
	@rm -f Plugin_simple.cpp Plugin_all.cpp

Conversion.o: Conversion.cpp ../FreeImage.h ../Utilities.h ../Quantizers.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

Conversion%.o: Conversion%.cpp ../FreeImage.h ../Utilities.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

BitmapAccess.o: BitmapAccess.cpp ../FreeImage.h ../FreeImageIO.h ../Utilities.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

PixelAccess.o: PixelAccess.cpp ../FreeImage.h ../Utilities.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

Plugin_%.cpp: Plugin_%_part.cpp Plugin_.cpp
	$(shell cat Plugin_.cpp > $@)
	$(shell cat $< >> $@)

Plugin_%.o: Plugin_%.cpp ../FreeImage.h ../FreeImageIO.h ../Plugin.h ../Utilities.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

PluginPNG.o: PluginPNG.cpp ../FreeImage.h ../ZLib/zlib.h ../LibPNG/png.h
	$(CC) $(CC_Flags) -c -I.. -I../ZLib -I../LibPNG -o $@ $<

Plugin%.o: Plugin%.cpp ../FreeImage.h 
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

GetType.o: GetType.cpp ../FreeImage.h ../FreeImageIO.h ../Plugin.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<

%Quantizer.o: %Quantizer.cpp ../FreeImage.h 
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

FreeImage.o: FreeImage.cpp ../FreeImage.h ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<

%IO.o: %IO.cpp ../FreeImage.h ../FreeImageIO.h ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<

