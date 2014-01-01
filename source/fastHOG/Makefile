.PHONY: all clean

OBJS=fastHOG.o
HOG_OBJS=HOG/HOGConvolution.o HOG/HOGEngineDevice.o HOG/HOGEngine.o HOG/HOGHistogram.o HOG/HOGImage.o HOG/HOGNMS.o HOG/HOGPadding.o HOG/HOGScale.o HOG/HOGUtils.o HOG/HOGSVMSlider.o 
UTILS_OBJS=Utils/ImageWindow.o 

all: $(OBJS) $(HOG_OBJS) $(UTILS_OBJS)
	@cp $^ $(BINDIR)

%.o: %.cu
	$(NVCC) $(NVCC_FLAGS) $(NVCC_INC) -c -o $*.o $<

%.o: %.cpp
	$(CC) $(CC_FLAGS) -I. -c -o $*.o $<

clean:
	rm -f $(OBJS) $(HOG_OBJS) $(UTILS_OBJS)

clean_all: clean

