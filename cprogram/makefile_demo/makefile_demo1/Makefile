OBJS=f1.o f2.o
OBJS+=main.o
CFLAGS=-c -Wall
test:$(OBJS)
	gcc $(OBJS) -o test
f2.o:$<
	gcc -c -Wall f2.c -o $@
f1.o:f1.c
	gcc $(CFLAGS) f1.c -o $@
main.o:main.c
	gcc -c -Wall main.c -o main.o
.PHONY:clean
clean:
	rm *.o test
