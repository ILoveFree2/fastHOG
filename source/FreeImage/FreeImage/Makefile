.PHONY: all clean

OBJS=$(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

clean:
	@rm -f *.h
	rm -f *.o

Conversion.o: Conversion.cpp ../FreeImage.h ../Utilities.h ../Quantizers.h
	@ln -s ../Utilities.h ../Quantizers.h ./.
	$(CC) $(CFlags) -c -o $@ $<
	@rm  Utilities.h Quantizers.h 

Conversion%.o: Conversion%.cpp ../FreeImage.h ../Utilities.h
	@ln -s ../Utilities.h ./.
	$(CC) $(CFlags) -c -o $@ $<
	@rm  Utilities.h 

BitmapAccess.o: BitmapAccess.cpp ../FreeImage.h ../FreeImageIO.h ../Utilities.h
	@ln -s ../Utilities.h ../FreeImageIO.h ./.
	$(CC) $(CFLAGS) -c -o $@ $<
	@rm  Utilities.h FreeImageIO.h

PixelAccess.o: PixelAccess.cpp ../FreeImage.h ../Utilities.h
	@ln -s ../Utilities.h ./.
	$(CC) $(CFlags) -c -o PixelAccess.o PixelAccess.cpp
	@rm  Utilities.h

Plugin.o: Plugin.cpp ../FreeImage.h ../FreeImageIO.h ../Plugin.h ../Utilities.h
	@ln -s  ../FreeImageIO.h ../Plugin.h ../Utilities.h ./.
	$(CC) $(CFlags) -c -o Plugin.o Plugin.cpp
	@rm  FreeImageIO.h Plugin.h Utilities.h

Plugin%.o: Plugin%.cpp ../FreeImage.h 
	@ln -s ../Utilities.h ./.
	$(CC) $(CFlags) -c -o $@ $<
	@rm  Utilities.h

GetType.o: GetType.cpp ../FreeImage.h ../FreeImageIO.h ../Plugin.h
	@ln -s ../Utilities.h ../FreeImageIO.h ../Plugin.h ./.
	@ln -s ../Utilities.h ../DeprecationManager/.
	$(CC) $(CFLAGS) -c -o $@ $<
	@rm  Utilities.h FreeImageIO.h Plugin.h
	@rm ../DeprecationManager/Utilities.h

%Quantizer.o: %Quantizer.cpp ../FreeImage.h 
	@ln -s ../Utilities.h ../Quantizers.h ./.
	$(CC) $(CFlags) -c -o $@ $<
	@rm  Utilities.h Quantizers.h

FreeImage.o: FreeImage.cpp ../FreeImage.h ../Utilities.h
	@ln -s ../Utilities.h ./.
	$(CC) $(CFLAGS) -c -o $@ $<
	@rm  Utilities.h

FreeImageIO.o: FreeImageIO.cpp ../FreeImage.h ../FreeImageIO.h ../Utilities.h
	@ln -s ../Utilities.h ../FreeImageIO.h ./.
	$(CC) $(CFLAGS) -c -o $@ $<
	@rm  Utilities.h FreeImageIO.h

