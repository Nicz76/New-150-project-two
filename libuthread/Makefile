# Target library
lib := libuthread.a
objs := queue.o

CC := gcc
CFLAGS := -Wall -Wextra -Werror


all: $(lib)

## TODO: Phase 1
libuthread.a: $(objs)
    ar rcs libuthread.a $@ $^ # Probably something wrong with this

%.o: %.c queue.h
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f $(lib) $(objs)
