.PHONY: all clean clean_all cleanLibs

CC = g++
NVCC=nvcc

CCFLAGS=
NVCCFLAGS=

HOME=/home/johannes
#HOME=/home/inf3/bi83hybe
CUDA_INSTALL=/usr/local/cuda
#CUDA_INSTALL=/opt/cuda
BINDIR=$(HOME)/workspace/fasthog/objs
#BINDIR=$(HOME)/fasthog/objs

CUDA_LIB=-L$(CUDA_INSTALL)/lib -L$(CUDA_INSTALL)/lib64
CUDA_SDK_DIR=$(HOME)/NVIDIA_GPU_Computing_SDK
NVCC_INC=-I$(CUDA_SDK_DIR)/C/common/inc -I$(CUDA_INSTALL)/include

LDFLAGS=$(CUDA_LIB) -L$(CUDA_SDK_DIR)/C/lib -lcudart -lGL -lglut

export BINDIR
export CC
export LDFLAGS
export NVCC
export NVCC_INC
export NVCC_FLAGS

all:
	@$(MAKE) -C source

clean:
	@$(MAKE) -C source clean

clean_all:
	@$(MAKE) -C source clean_all
	rm -f fasthog

cleanLibs:
	@$(MAKE) -C source cleanLibs

