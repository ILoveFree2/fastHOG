
#  Makefile for fltk applications
# copied from http://www.di.uminho.pt/mcss2010/files/Makefile.mac
#

TARGET=fasthog


CUDA_INSTALL=/opt/cuda
CUDA_BIN=$(CUDA_INSTALL)/bin
CUDA_INC=$(CUDA_INSTALL)/include
CUDA_LIB=$(CUDA_INSTALL)/lib
CUDA_SDK_DIR=/home/inf3/bi83hybe/NVIDIA_GPU_Computing_SDK

LOCAL = /usr/local

CC = g++

NVCC =$(CUDA_BIN)/nvcc 
NVCC_INC =-I$(CUDA_INC)

CFLAGS=
NVCCFLAGS=
INCLUDE=-I$(CUDA_SDK_DIR)/C/common/inc -I . -I /home/inf3/bi83hybe/FreeImage/Source -I./boost/
LD_FLAGS =-L$(CUDA_LIB) -L$(CUDA_LIB)64 -L/usr/lib64 -lX11 -lXi -ldl -L$(CUDA_SDK_DIR)/C/lib/ -lcudart -L /home/inf3/bi83hybe/bi83hybe/FreeImage -lfreeimage -lboost_thread -lboost_system

%.o: %.cu 
	$(NVCC) $(NVCCFLAGS) $(INCLUDE) -c -o $*.o $<

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $(NVCC_INC) -c -o $*.o $<

BOOST_OBS=
OBJS = fastHOG.o HOG/HOGConvolution.o HOG/HOGEngineDevice.o HOG/HOGEngine.o HOG/HOGHistogram.o HOG/HOGImage.o HOG/HOGNMS.o HOG/HOGPadding.o HOG/HOGScale.o HOG/HOGUtils.o HOG/HOGSVMSlider.o Utils/ImageWindow.o

all: $(TARGET)

$(TARGET): $(OBJS) $(BOOST_OBS)
	$(CC) $(LD_FLAGS) -o $@ $(OBJS) $(BOOST_OBS)

clean:
	rm -f $(OBJS) $(TARGET) 

clean_all:
	rm -f $(OBJS) $(TARGET)


