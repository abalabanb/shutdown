# makefile for GNU make (automatically generated by makemake)
# NOTE: indent with TAB in GNU makefiles!

# paths are relative to the project directory (current directory during make)

EXE    = bin/gcc-amigaos4-latest/Shutdown
OBJDIR = o/gcc-amigaos4-latest/

# compiler and linker

CC = gcc
LD = gcc

# target 'all' (default target)

all : $(EXE)

$(OBJDIR)Shutdown.o : Shutdown.c
	$(CC) $(shell gccprefs) -c -o $(OBJDIR)Shutdown.o Shutdown.c

OBJS = $(OBJDIR)Shutdown.o

$(EXE) : $(OBJS)
	$(LD) $(OBJS) $(shell gccprefs) -o $(EXE)

# target 'strip'

strip:
	strip --remove-section=.comment $(EXE)

# target 'clean'

clean:
	-delete $(EXE)
	-delete $(OBJDIR)\*.o
