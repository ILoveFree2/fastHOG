
#  Makefile for fltk applications
# copied from http://www.di.uminho.pt/mcss2010/files/Makefile.mac
#

TARGET=fasthog

HOME=/home/inf3/bi83hybe

CUDA_INSTALL=/opt/cuda
CUDA_BIN=$(CUDA_INSTALL)/bin
CUDA_INC=$(CUDA_INSTALL)/include
CUDA_LIB=$(CUDA_INSTALL)/lib
CUDA_SDK_DIR=$(HOME)/NVIDIA_GPU_Computing_SDK

CC = g++

NVCC =nvcc 
NVCC_INC =-I$(CUDA_INC)

CFLAGS=
NVCCFLAGS=

INCLUDE=-I$(CUDA_SDK_DIR)/C/common/inc -I$(HOME)/FreeImage/Source \
-I.
#-I$(HOME)/boost_1_55_0

LD_FLAGS =-L$(CUDA_LIB) -L$(CUDA_LIB)64 -L/usr/lib64 -L$(CUDA_SDK_DIR)/C/lib/ -lcudart \
-L$(HOME)/FreeImage -lfreeimage \
-lboost_thread -lboost_system

%.o: %.cu
	$(NVCC) $(NVCCFLAGS) $(INCLUDE) -c -o $*.o $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(INCLUDE) $(NVCC_INC) -c -o $*.o $<

OBJS = fastHOG.o HOG/HOGConvolution.o HOG/HOGEngineDevice.o HOG/HOGEngine.o HOG/HOGHistogram.o HOG/HOGImage.o HOG/HOGNMS.o HOG/HOGPadding.o HOG/HOGScale.o HOG/HOGUtils.o HOG/HOGSVMSlider.o Utils/ImageWindow.o

all: $(TARGET)

$(TARGET): $(OBJS) $(BOOST_OBS) $(HEADERS_WITH_IMPL)
	$(CC) $(LD_FLAGS) -o $@ $(OBJS) $(BOOST_OBS)

clean:
	rm -f $(OBJS)

clean_all:
	rm -f $(OBJS) $(TARGET)
