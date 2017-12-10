MAIN = src/fluid.cpp
HEADERS = src/headers
TMP = tmp
FIELD = $(HEADERS)/Field_export.cpp $(HEADERS)/Field_main.cpp $(HEADERS)/Fields.cpp
MISC = $(HEADERS)/misc.cpp
ODE = $(HEADERS)/Logic.cpp
HEAD = $(HEADERS)/fluid.h

OBJS = $(TMP)/main.o $(TMP)/misc.o $(TMP)/field.o $(TMP)/ode.o

CC = clang++
DEBUG = -g -Wall 
CFLAGS = -std=c++11 -c $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)


all: run
	@gnuplot --persist plots/accur.gnu& 2>/dev/null
	@gnuplot --persist plots/approx.gnu& 2>/dev/null

run: link
	@./fluid $(OPT)

link: preps $(OBJS)
	@$(CC) $(LFLAGS) $(OBJS) -o fluid

preps: clean
	@mkdir -p plots/
	@mkdir -p $(TMP)/

$(TMP)/misc.o:  preps $(HEAD) $(MISC)
	@$(CC) $(CFLAGS) $(MISC) -o $(TMP)/misc.o

$(TMP)/ode.o:  preps $(HEAD) $(MISC) $(ODE)
	@$(CC) $(CFLAGS) $(ODE) -o $(TMP)/ode.o	

$(TMP)/field.o: preps $(HEAD) $(MISC) $(FIELD)
	@$(CC) $(CFLAGS) $(HEADERS)/Fields.cpp -o $(TMP)/field.o

$(TMP)/main.o:  preps $(HEAD) $(MISC) $(MAIN)
	@$(CC) $(CFLAGS) $(MAIN) -o $(TMP)/main.o

# all: compile
# 	./fluid

clean:
	@gnuplot&
	@pkill -f gnuplot
	@rm -f fluid
	@rm -rf $(TMP)

erase: clean
	@rm -rf plots


gt: erase
	git add *
