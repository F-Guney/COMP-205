reverse: c_shell.o reverse_order.o
		gcc -lreadline -o c_shell.o reverse_order.o
c_shell.o: c_shell.c reverse_order.h
		cc -lreadline -c c_shell.c reverse_order.h
reverse_order.o: reverse_order.c reverse_order.h
		cc -c reverse_order.c
clean: 
	rm -f reverse_order.o c_shell.o

	
	
