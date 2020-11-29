CC=c++
CFlags= -o2 -lvulkan -lpthread -lGL -lX11
RESULTS=completesrc.c plain nodeadcode

# While yes, you can change the comiler, GCC is reccomended

all: $(RESULTS)

completesrc.c: test.c
	$(CC) $(CFLAGS) -E test.c > completesrc.c

plain: test.c
	$(CC) $(CFLAGS) -o plain test.c
nodeadcode: test.c
	$(CC) $(CFLAG) -0 -fdata-sections -ffunction-sections -o nodeadcode test.c -Wl,-dead-strip

cppmk: test.cpp
	$(CC) $(CFLAG) -0 -fdata-sections -ffunction-sections -o test.c -Wl,-dead-strip

clean:
	rm -rf *.dSYM $(RESULTS)
