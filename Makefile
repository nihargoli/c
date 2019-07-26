int_pointers: int_pointers.c
	gcc -o $@ $^
clean:
	rm int_pointers
