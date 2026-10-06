CC      = gcc
CFLAGS  = -Wall -Wextra
LDLIBS  = -lpthread

PROGRAMAS = calc_pthreads calc_openmp

all: $(PROGRAMAS)

calc_pthreads: calc_pthreads.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

calc_openmp: calc_openmp.c
	$(CC) $(CFLAGS) -fopenmp -o $@ $<

clean:
	rm -f $(PROGRAMAS)

.PHONY: all clean
