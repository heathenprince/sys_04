GCC = gcc

stattest: stat.c
	$(GCC) stat.c -o stattest

run: stattest
	./stattest

clean:
	rm stattest
	rm *.out
	rm *.o
	rm *~
