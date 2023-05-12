# Target library
lib := libuthread.a
objs := queue.o

CC := gcc
CFLAGS := -Wall -Wextra -Werror


all: $(lib) queue.o

## TODO: Phase 1
libuthread.a: $(objs)
    ar rcs libuthread.a queue.o

queue.o: queue.c queue.h
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f $(lib) $(objs)
