.PHONY: all clean

OBJS=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

clean:
	rm -f $(OBJS)

Conversion.o: Conversion.cpp ../FreeImage.h ../Utilities.h ../Quantizers.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

Conversion%.o: Conversion%.cpp ../FreeImage.h ../Utilities.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

BitmapAccess.o: BitmapAccess.cpp ../FreeImage.h ../FreeImageIO.h ../Utilities.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

PixelAccess.o: PixelAccess.cpp ../FreeImage.h ../Utilities.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

Plugin.o: Plugin.cpp ../FreeImage.h ../FreeImageIO.h ../Plugin.h ../Utilities.h
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

Plugin%.o: Plugin%.cpp ../FreeImage.h 
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

GetType.o: GetType.cpp ../FreeImage.h ../FreeImageIO.h ../Plugin.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<

%Quantizer.o: %Quantizer.cpp ../FreeImage.h 
	$(CC) $(CC_Flags) -c -I.. -o $@ $<

FreeImage.o: FreeImage.cpp ../FreeImage.h ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<

FreeImageIO.o: FreeImageIO.cpp ../FreeImage.h ../FreeImageIO.h ../Utilities.h
	$(CC) $(CC_FLAGS) -c -I.. -o $@ $<
