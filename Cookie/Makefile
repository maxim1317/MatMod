MAIN = src/cookie.cpp
HEADERS = src/headers
TMP = tmp
HEAD = $(HEADERS)/cookie.h
MISC = $(HEADERS)/misc.cpp

OBJS = $(TMP)/main.o $(TMP)/misc.o

CC = clang++
DEBUG = -g -Wall 
CFLAGS = -std=c++11 -c $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)

all: run
	@gnuplot --persist plot.gnu& 2>/dev/null

run: link
	@./cookie 

link: preps $(OBJS)
	@$(CC) $(LFLAGS) $(OBJS) -o cookie

preps: clean
	@mkdir -p $(TMP)/

$(TMP)/misc.o:  preps $(HEAD) $(MISC)
	@$(CC) $(CFLAGS) $(MISC) -o $(TMP)/misc.o

$(TMP)/main.o:  preps $(HEAD) $(MISC) $(MAIN)
	@$(CC) $(CFLAGS) $(MAIN) -o $(TMP)/main.o

clean:
	@gnuplot&
	@pkill -f gnuplot
	@rm -f cookie
	@rm -rf $(TMP)

erase: clean

gt: erase
	git add *
