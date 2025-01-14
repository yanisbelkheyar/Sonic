CC = gcc
DEPS = sonic.h round.h constante.h sonic_procrastinate.h round_procrastinate.h function.h struct.h mode_sonic.h

all: test/test_sonic test/test_sonic_procrastinate test/test_mode #test/test_DP test/test_LP

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test/test_sonic: test/test_sonic.o sonic.o
	$(CC) -o test/test_sonic test/test_sonic.o sonic.o

test/test_sonic_procrastinate: test/test_sonic_procrastinate.o sonic_procrastinate.o
	$(CC) -o test/test_sonic_procrastinate test/test_sonic_procrastinate.o sonic_procrastinate.o

test/test_DP: test/test_DP.o sonic.o
	$(CC) -o test/test_DP test/test_DP.o sonic.o

test/test_LP: test/test_LP.o sonic.o 
	$(CC) -o test/test_LP test/test_LP.o sonic.o

test/test_mode: test/test_mode.o mode_sonic.o sonic.o
	$(CC) -o test/test_mode test/test_mode.o mode_sonic.o sonic.o

clean:
	rm -f *.o test/test_sonic test/test_DP test/test_sonic_procrastinate test/test_LP *.h.gch test/test_mode
