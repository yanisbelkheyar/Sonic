
make: diffusion_exe.c test_super_sonic.c
	gcc -c ./usefull/pool.c ./usefull/pool.h ./usefull/function_binary.h
	gcc -c ./usefull/tree.c ./usefull/tree.h ./usefull/function_binary.h
	gcc -c ./usefull/function_binary.c ./usefull/function_binary.h
	gcc -c diffusion_test.c diffusion_test.h
	gcc -o diffusion_sonic -fopenmp diffusion_exe.c diffusion_test.o -lm
	#gcc -o diffusion_super_sonic test_super_sonic.c diffusion_test.o -lm 	

clean:
	rm -r *.o 
