#This is the makefile to make the emulator
CC=gcc
LD=gcc

CFLAGS=-O2 -std=gnu99 -g
OBJS=OpenFileTable.o DataBlockAccess.o InodeAccess.o DiskEmulator.o FileSystem.o SuperBlock.o FreeListNode.o
USEFLAGS=`pkg-config fuse --cflags --libs`
SRCS=DiskEmulator.c

all: init test

init: $(OBJS) InitFSTest

test: $(OBJS) Layer0Test Layer1Test

Layer1Test: $(OBJS) Layer1Test.o
	$(CC) $(CFLAGS) -o $@ $^

InitFSTest: $(OBJS) InitFSTest.o
	$(CC) $(CFLAGS) -o $@ $^

Layer0Test: $(OBJS) Layer0Test.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -fr *.o Layer0Test InitFSTest

