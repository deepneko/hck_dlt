CC=gcc
CFLAGS=
LIBS=
OBJECTS=parity.o util.o
COBJ=$(CC) -std=c99 $(CFLAGS) $(DEFINES) $(INCLUDEDIRS) -c
CAPP=$(CC) -std=c99 $(CFLAGS) $(DEFINES) $(INCLUDEDIRS) $(OBJECTS) $(LIBS)

all: hck_dlt

hck_dlt: Makefile $(OBJECTS)
	$(CAPP) -o hck_dlt

bit.o: Makefile parity.c
	$(COBJ) parity.c

util.o: Makefile util.c util.h
	$(COBJ) util.c

clean:
	rm -f *.o
	rm -f hck_dlt
