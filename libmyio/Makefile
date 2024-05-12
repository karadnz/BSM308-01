CFLAGS = -O3 -Iinclude

all: lib/libmyio.a 

OBJS = obj/myio.o 

lib/libmyio.a: $(OBJS)
	ar ru lib/libmyio.a $(OBJS)
	ranlib lib/libmyio.a 

clean:
	rm -f obj/* lib/*

obj/myio.o: src/myio.c include/myio.h
	gcc $(CFLAGS) -c -o obj/myio.o src/myio.c

