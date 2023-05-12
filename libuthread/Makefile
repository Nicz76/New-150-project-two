# Target library
lib := libuthread.a
objs := *.o *.d *.x

CC := gcc
CFLAGS := -Wall -Wextra -Werror


all: $(lib)

## TODO: Phase 1
libuthread.a: $(objs)
    ar rcs libuthread.a $@ $^ 

%.o: %.c queue.h
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f $(lib) $(objs)