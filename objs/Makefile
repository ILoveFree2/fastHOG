.PHONY: all clean

CC=g++

OBJS=$(shell find . -name "*.o")

HOME=/home/inf3/bi83hybe

CUDA_SDK_DIR=$(HOME)/NVIDIA_GPU_Computing_SDK

LDFLAGS=-L/opt/cuda/lib -L/opt/cuda/lib64  -L$(CUDA_SDK_DIR)/C/lib -lcudart -lGL -lglut -lboost_thread

all: ../fasthog

../fasthog: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
