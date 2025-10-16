CC = gcc -march=native -mtune=native -O3 -fomit-frame-pointer -fwrapv -fPIC -fPIE #clang -mcpu=native -O3 -fomit-frame-pointer -fwrapv -Qunused-arguments -fPIC -fPIE 
DEPS = ../Sonic512/constante.h ../Sonic512/function.h ../Sonic512/permutation_procratinate.h ../Sonic512/permutation.h ../Sonic512/struct.h

all: test_sonicduplex 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_sonicboom: test_sonicduplex.o 
	$(CC) -o test_sonicduplex  test_sonicduplex.o 

clean:
	rm -f *.o *.h.gch test_sonicduplex 
