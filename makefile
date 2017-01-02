GCC = gcc

make all:
	make run
	make clean
	clear
stattest: stat.c
	$(GCC) stat.c -o stattest

run: stattest
	make stattest
	./stattest

clean:
	rm stattest
	rm *.out
	rm *.o
	rm *~
