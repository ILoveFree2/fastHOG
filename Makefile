.PHONY: all clean clean_all cleanLibs objects proper proper_objects

ARM_COMPILE=1
LAPTOP=0

ifeq ($(ARM_COMPILE), 1)
CC=arm-linux-gnueabihf-g++
NVCC_FLAGS=-target-cpu-arch ARM -ccbin $(CC)
ifeq ($(LAPTOP), 1)
CUDA_INSTALL=/usr/local/cuda-arm
ARM_GLUT=/usr/arm-linux-gnueabihf/lib
else
$(error missing location of cuda librariries for ARM)
CUDA_INSTALL= #TODO
$(error missing location of GL and glut librariries for ARM)
ARM_GLUT= #TODO
endif
else
CC=g++
NVCC_FLAGS=
endif


ifeq ($(LAPTOP), 1)
ifeq ($(ARM_COMPILE), 0)
CUDA_INSTALL=/usr/local/cuda
endif
HOME=/home/johannes
BINDIR=$(HOME)/workspace/fasthog/objs
else
ifeq ($(ARM_COMPILE), 0)
CUDA_INSTALL=/opt/cuda
endif
HOME=/home/inf3/bi83hybe
BINDIR=$(HOME)/fasthog/objs
endif

NVCC=nvcc

CC_FLAGS=

CUDA_LIB=-L$(CUDA_INSTALL)/lib -L$(CUDA_INSTALL)/lib64
NVCC_INC=-I$(CUDA_SDK_DIR)/C/common/inc -I$(CUDA_INSTALL)/include

CUDA_SDK_DIR=$(HOME)/NVIDIA_GPU_Computing_SDK

ifeq ($(ARM_COMPILE), 1)
LD_FLAGS=-ccbin $(CC) $(CUDA_LIB) -L$(ARM_GLUT) -L$(CUDA_SDK_DIR)/C/lib -lcudart -lGL -lglut
else
LD_FLAGS=$(CUDA_LIB) -L$(CUDA_SDK_DIR)/C/lib -lcudart -lGL -lglut
endif

export ARM_COMPILE
export BINDIR
export CC
export CC_FLAGS
export NVCC_FLAGS
export LD_FLAGS
export NVCC
export NVCC_INC

all:
	@$(MAKE) -C source

proper: clean_all all

proper_objects: clean_all objects

objects:
	@$(MAKE) -C source objects

clean:
	@$(MAKE) -C source clean

clean_all:
	@$(MAKE) -C source clean_all
	@$(MAKE) -C objs clean

cleanLibs:
	@$(MAKE) -C source cleanLibs

