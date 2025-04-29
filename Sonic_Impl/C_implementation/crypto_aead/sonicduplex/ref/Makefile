CC = g++ -march=native -mtune=native -O3 -fomit-frame-pointer -fwrapv -fPIC -fPIE #clang -mcpu=native -O3 -fomit-frame-pointer -fwrapv -Qunused-arguments -fPIC -fPIE 
DEPS = round_procrastinate.h function.h struct.h sonicduplex.h aux_functions.h cpucyles.h

all: test_sonic_duplex getcycles genkat_aead

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
  

test_sonic_duplex: test_sonicduplex.o encrypt.o 
	$(CC) -o test_sonicduplex test_sonicduplex.o encrypt.o 

getcycles: getcycles.o encrypt.o
	$(CC) -o getcycles getcycles.o encrypt.o 
  
genkat_aead: genkat_aead.o encrypt.o
	$(CC) -o genkat_aead genkat_aead.o encrypt.o 

clean:
	rm -f *.o *.h.gch test_sonicduplex getcycles gencat_aead
