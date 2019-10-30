# Use the C++ compiler to link
LINK.o = $(LINK.cc)
# Flags to compile for the debugger
CXXFLAGS =-Wall -g

all: runtests

runtests: runtests.o
runtests.o: List.h Stack.h Queue.h

clean:
	rm -f runtests *.o
