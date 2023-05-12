# Target library
lib := libuthread.a
objs := queue.o

CC := gcc
CFLAGS := -Wall -Wextra -Werror


all: $(lib)

## TODO: Phase 1
libuthread.a: $(objs)
    ar rcs libuthread.a $@ $^ # Probably something wrong with this

test: queue_tester_example.o queue.o
    $(CC) $(CFLAGS) -o $@ $^

queue_tester_example: queue_tester_example.c queue.h
    $(CC) $(CFLAGS) -c -o $@ $^

queue.o: queue.c queue.h
    $(CC) $(CFLAGS) -c -o $@ $^


clean:
    rm -f $(lib) $(objs) queue_tester_example
