all: int_pointers char_pointers func_pointers

int_pointers: int_pointers.c
	gcc -o $@ $^
char_pointers: char_pointers.c
	gcc -o $@ $^
func_poniters: func_pointers.c
	gcc -o $@ $^
clean:
	rm int_pointers char_pointers func_pointers
