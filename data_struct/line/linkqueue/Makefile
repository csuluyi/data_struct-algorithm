CC = gcc
CFLAGS = -Wall -g -o0 -o

OBJS = linkqueue_test
SRC = linkqueue.c linkqueue_test.c

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) $@ $^

.PHONY:clean
clean:
	$(RM) $(OBJS) .*.sw?
