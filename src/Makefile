CC=gcc
CFlags= -o2 -lpthread -lX11
RESULTS=completesrc.c plain nodeadcode

all: $(RESULTS)

completesrc.c: test.c
	$(CC) $(CFLAGS) -E test.c > completesrc.c

plain: test.c
	$(CC) $(CFLAGS) -o plain test.c
nodeadcode: test.c
	$(CC) $(CFLAG) -0 -fdata-sections -ffunction-sections -o nodeadcode test.c -Wl,-dead-strip
	
clean:
	rm -rf *.dSYM $(RESULTS)
