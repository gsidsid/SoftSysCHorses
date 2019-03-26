# operating system
HOST_OS := $(shell uname -s 2>/dev/null | tr "[:upper:]" "[:lower:]")

# architecture 
ARCH := $(shell getconf LONG_BIT)

NVCC := nvcc

ifeq ($(HOST_OS),darwin)
	CXX := clang++
else
	CXX := g++
endif

STD := --std=c++11

CXX_FLAGS  := $(STD) -I../ -I../../

# uncomment for debug
#DEBUG_FLAGS := -g -DDEBUG
#DEBUG_FLAGS_NVCC := -G

# comment for debug
CXX_FLAGS += -O2

CXX_FLAGS += $(DEBUG_FLAGS)

NVCC_FLAGS := $(CXX_FLAGS) $(DEBUG_FLAGS_NVCC) --expt-extended-lambda

all: kmeans_device kmeans_host_nvcc

kmeans_device: time_kmeans.c kmeans.c point.c gpu_distance.cpp
	$(NVCC) $? $(NVCC_FLAGS) -x cu -o $@

kmeans_host_nvcc: time_kmeans.c kmeans.c point.c gpu_distance.cpp
	$(NVCC) $? $(CXX_FLAGS) -x c++ -o $@

clean:
	rm -rf kmeans_device kmeans_host_nvcc kmeans_host
