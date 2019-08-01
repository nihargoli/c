all: int_pointers char_pointers func_pointers pointer_to_pointer

int_pointers: int_pointers.c
	gcc -o $@ $^
char_pointers: char_pointers.c
	gcc -o $@ $^
func_poniters: func_pointers.c
	gcc -o $@ $^
pointer_to_pointer: pointer_to_pointer.c
	gcc -o $@ $^
clean:
	rm int_pointers char_pointers func_pointers pointer_to_pointer
