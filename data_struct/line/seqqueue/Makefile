CC = gcc
CFLAGS = -Wall -g -o0 -o

OBJS = seqqueue_test
SRC = seqqueue.c seqqueue_test.c

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) $@ $^

.PHONY:clean
clean:
	$(RM) $(OBJS) .*.sw?
