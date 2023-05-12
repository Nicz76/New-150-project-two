# Target library
lib := libuthread.a
objs := queue.o

CC := gcc
CFLAGS := -Wall -Wextra -Werror


all: $(lib)

## TODO: Phase 1
libuthread.a: $(objs) queue_tester_example.o
    ar rcs libuthread.a -o $@ $^ # Probably something wrong with this

all: queue_tester_example.o queue.o test

queue_tester_example.o: queue_tester_example.c queue.h
    $(CC) $(CFLAGS) -c -o $@ $<

queue.o: queue.c queue.h
    $(CC) $(CFLAGS) -c -o $@ $<

test: queue_tester_example.o queue.o
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f $(lib) $(objs) queue_tester_example.o
