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


all: link
	@./cookie

link: preps $(OBJS)
	@$(CC) $(LFLAGS) $(OBJS) -o cookie

preps: clean
	@mkdir -p $(TMP)/

$(TMP)/misc.o:  preps $(HEAD) $(MISC)
	@$(CC) $(CFLAGS) $(MISC) -o $(TMP)/misc.o

$(TMP)/main.o:  preps $(HEAD) $(MISC) $(MAIN)
	@$(CC) $(CFLAGS) $(MAIN) -o $(TMP)/main.o

# all: compile
# 	./cookie

clean:
	@rm -f cookie
	@rm -rf $(TMP)

erase: clean

gt: erase
	git add *
