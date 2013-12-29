
#  Makefile for fltk applications
# copied from http://www.di.uminho.pt/mcss2010/files/Makefile.mac

TARGET=fasthog

HOME=/home/johannes
#HOME=/home/bi83hybe

CUDA_INSTALL=/usr/local/cuda
#CUDA_INSTALL=/opt/cuda
CUDA_BIN=$(CUDA_INSTALL)/bin
CUDA_INC=$(CUDA_INSTALL)/include
CUDA_LIB=$(CUDA_INSTALL)/lib
CUDA_SDK_DIR=$(HOME)/NVIDIA_GPU_Computing_SDK

CC=g++

NVCC=nvcc 
NVCC_INC=-I$(CUDA_INC)

CFLAGS=
NVCCFLAGS=

INCLUDE=-I$(CUDA_SDK_DIR)/C/common/inc -I$(CUDA_INC) -I$(HOME)/FreeImage/Source \
-I.
#-I$(HOME)/boost_1_55_0

LD_FLAGS =-L$(CUDA_LIB) -L$(CUDA_SDK_DIR)/C/lib/ -lcudart \
-L$(HOME)/FreeImage -lfreeimage \
-lGL -lglut
#-lboost_thread -lboost_system

%.o: %.cu %.h
	$(NVCC) $(NVCCFLAGS) $(INCLUDE) -c -o $*.o $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(INCLUDE) $(NVCC_INC) -c -o $*.o $<

OBJS = fastHOG.o HOG/HOGConvolution.o HOG/HOGEngineDevice.o HOG/HOGEngine.o HOG/HOGHistogram.o HOG/HOGImage.o HOG/HOGNMS.o HOG/HOGPadding.o HOG/HOGScale.o HOG/HOGUtils.o HOG/HOGSVMSlider.o Utils/ImageWindow.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LD_FLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

clean_all:
	rm -f $(OBJS) $(TARGET)
