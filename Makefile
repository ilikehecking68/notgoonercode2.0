# Detect the operating system
UNAME_S := $(shell uname -s)

# Set the number of parallel jobs based on the OS
ifeq ($(UNAME_S),Linux)
    NPROC := $(shell nproc)
else ifeq ($(UNAME_S),Darwin)
    NPROC := $(shell sysctl -n hw.ncpu)
else ifeq ($(OS),Windows_NT)
    NPROC := $(NUMBER_OF_PROCESSORS)
else
    NPROC := 1
endif

all:
	@$(MAKE) -f Makefile2 -j$(NPROC)

clean:
	@$(MAKE) -f Makefile2 clean