# Copyright (c) 2016, NVIDIA CORPORATION. All rights reserved.

#ACCEL_TYPE=PGI-multicore
ACCEL_TYPE=PGI-tesla
#ACCEL_TYPE=PGI

CC = pgc++
CFLAGS = -DUSE_DOUBLE -std=c++11

ifeq ($(ACCEL_TYPE),PGI)
	CFLAGS += -fast
else ifeq ($(ACCEL_TYPE),PGI-tesla)
	CFLAGS += -Minfo=accel -fast -acc -ta=tesla:cc70
else ifeq ($(ACCEL_TYPE),PGI-multicore)
	CFLAGS += -Minfo=accel -fast -acc -ta=multicore
endif


conv2d: conv2d.cpp conv2d.h  Makefile
	$(CC) $(CFLAGS) conv2d.cpp -o $@

timing: timing.cpp Makefile
	$(CC) $(CFLAGS) timing.cpp -o $@

.PHONY: clean 

clean:
	rm -f timing conv2d *.csv *.o