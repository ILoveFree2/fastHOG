.PHONY: all clean

#  Makefile for fltk applications
# copied from http://www.di.uminho.pt/mcss2010/files/Makefile.mac

#HOME=/home/johannes
HOME=/home/inf3/bi83hybe

#CUDA_INSTALL=/usr/local/cuda
CUDA_INSTALL=/opt/cuda
CUDA_BIN=$(CUDA_INSTALL)/bin
CUDA_INC=$(CUDA_INSTALL)/include
CUDA_LIB=$(CUDA_INSTALL)/lib
CUDA_LIB=$(CUDA_INSTALL)/lib64
CUDA_SDK_DIR=$(HOME)/NVIDIA_GPU_Computing_SDK

CC=g++

NVCC=nvcc 

INC=-I$(CUDA_INC)
NVCC_INC=-I$(CUDA_SDK_DIR)/C/common/inc

CFLAGS=
NVCCFLAGS=

INCLUDE=-I$(CUDA_SDK_DIR)/C/common/inc -I$(CUDA_INC) \
-I. -I../FreeImage

all: $(OBJS)
	@cp $(OBJS) ../objs


%.o: %.cu
	$(NVCC) $(NVCCFLAGS) $(INC) $(NVCC_INC) -c -o $*.o $<

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $(INC) -c -o $*.o $<

OBJS = fastHOG.o \
HOG/HOGConvolution.o HOG/HOGEngineDevice.o HOG/HOGEngine.o HOG/HOGHistogram.o HOG/HOGImage.o HOG/HOGNMS.o HOG/HOGPadding.o HOG/HOGScale.o HOG/HOGUtils.o HOG/HOGSVMSlider.o Utils/ImageWindow.o 

clean:
	rm -f $(OBJS)

clean_all:
	rm -f $(OBJS) $(TARGET)
