runner: signals.o
	@gcc signals.o -o runner

signal.o: signals.c
	@gcc -c signals.c

run: runner
	@./runner
clean:
	@rm *.o
