ifeq ("$(wildcard rands/*.rand)","")
	OPT = "-n"	
else
	OPT = 
endif

MAIN = src/randcheck.cpp
HEADERS = src/headers
TMP = tmp
CRITS = $(HEADERS)/crit_freq.cpp $(HEADERS)/crit_pair.cpp $(HEADERS)/crit_series.cpp $(HEADERS)/crit_poker.cpp
GENS = $(HEADERS)/randgen.cpp $(HEADERS)/chigen.cpp
MISC = $(HEADERS)/misc.cpp
HEAD = $(HEADERS)/randcheck.h

OBJS = $(TMP)/main.o $(TMP)/misc.o $(TMP)/gens.o $(TMP)/crits.o

CC = clang++
DEBUG = -g -Wall -O0
CFLAGS = -std=c++11 -c $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)


all: link
	@./randcheck $(OPT)

link: preps $(OBJS)
	@$(CC) $(LFLAGS) $(OBJS) -o randcheck

preps: clean
	@mkdir -p rands/
	@mkdir -p $(TMP)/

$(TMP)/misc.o:  preps $(HEAD) $(MISC)
	@$(CC) $(CFLAGS) $(MISC) -o $(TMP)/misc.o

$(TMP)/gens.o:  preps $(HEAD) $(MISC) $(GENS)
	@$(CC) $(CFLAGS) $(HEADERS)/gens.cpp -o $(TMP)/gens.o

$(TMP)/crits.o: preps $(HEAD) $(MISC) $(CRITS)
	@$(CC) $(CFLAGS) $(HEADERS)/crits.cpp -o $(TMP)/crits.o

$(TMP)/main.o:  preps $(HEAD) $(MISC) $(MAIN)
	@$(CC) $(CFLAGS) $(MAIN) -o $(TMP)/main.o

# all: compile
# 	./randcheck

clean:
	@rm -f randcheck
	@rm -rf $(TMP)

erase: clean
	@rm -rf rands

gt: erase
	git add *
