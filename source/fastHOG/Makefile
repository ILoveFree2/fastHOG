.PHONY: all clean

OBJS = fastHOG.o \
HOG/HOGConvolution.o HOG/HOGEngineDevice.o HOG/HOGEngine.o HOG/HOGHistogram.o HOG/HOGImage.o HOG/HOGNMS.o HOG/HOGPadding.o HOG/HOGScale.o HOG/HOGUtils.o HOG/HOGSVMSlider.o Utils/ImageWindow.o 

all: $(OBJS)
	@cp $(OBJS) $(BINDIR)

%.o: %.cu
	$(NVCC) $(NVCCFLAGS) $(NVCC_INC) -c -o $*.o $<

%.o: %.cpp
	$(CC) $(CFLAGS) -I. -c -o $*.o $<

clean:
	rm -f $(OBJS)

clean_all: clean
