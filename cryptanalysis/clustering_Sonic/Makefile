CC=gcc -Wall -fopenmp
DEPS = check_compatibility.h

all: cluster_sonic cluster_simon test_DP_simon

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cluster_sonic: generate_trail.o check_compatibility.o
	$(CC) -o cluster_sonic generate_trail.o check_compatibility.o

cluster_simon: generate_trail_simon.o check_compatibility.o
	$(CC) -o cluster_simon generate_trail_simon.o check_compatibility.o

test_DP_simon: test_DP.o
	$(CC) -o test_DP_simon test_DP.o

clean:
	rm -f *.o cluster_sonic cluster_simon test_DP_simon
