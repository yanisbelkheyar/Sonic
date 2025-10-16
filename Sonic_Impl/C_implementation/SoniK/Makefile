CC = gcc -march=native -mtune=native -O3 -fomit-frame-pointer -fwrapv -fPIC -fPIE #clang -mcpu=native -O3 -fomit-frame-pointer -fwrapv -Qunused-arguments -fPIC -fPIE 
DEPS = Sonic256/constante.h Sonic256/function.h Sonic256/permutation_procratinate.h Sonic256/permutation.h Sonic256/struct.h

all: test_sonik

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_sonick: test_sonik.o 
	$(CC) -o test_sonik test_sonick.o 

clean:
	rm -f *.o *.h.gch test_sonik
