
make: diffusion_exe.c test_super_sonic.c
	gcc -c diffusion_test.c diffusion_test.h
	gcc -o diffusion_sonic -fopenmp diffusion_exe.c diffusion_test.o -lm

clean:
	rm -r *.o diffusion_sonic diffusion_super_sonic
