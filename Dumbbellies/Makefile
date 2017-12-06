MAIN = src/dumbbellies.cpp
HEADERS = src/headers
TMP = tmp
FIELD = $(HEADERS)/Field_export.cpp $(HEADERS)/Field_main.cpp $(HEADERS)/Fields.cpp
POINT = $(HEADERS)/Point_main.cpp
MISC = $(HEADERS)/misc.cpp
ODE = $(HEADERS)/ODEs.cpp
HEAD = $(HEADERS)/dumbbellies.h

OBJS = $(TMP)/main.o $(TMP)/misc.o $(TMP)/point.o $(TMP)/field.o $(TMP)/ode.o

CC = clang++
DEBUG = -g -Wall 
CFLAGS = -std=c++11 -c $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)


all: link
	@./dumbbellies $(OPT)

link: preps $(OBJS)
	@$(CC) $(LFLAGS) $(OBJS) -o dumbbellies

preps: clean
	@mkdir -p Output/
	@mkdir -p $(TMP)/

$(TMP)/misc.o:  preps $(HEAD) $(MISC)
	@$(CC) $(CFLAGS) $(MISC) -o $(TMP)/misc.o

$(TMP)/ode.o:  preps $(HEAD) $(MISC) $(ODE)
	@$(CC) $(CFLAGS) $(ODE) -o $(TMP)/ode.o	

$(TMP)/point.o:  preps $(HEAD) $(MISC) $(POINT)
	@$(CC) $(CFLAGS) $(HEADERS)/Point_main.cpp -o $(TMP)/point.o

$(TMP)/field.o: preps $(HEAD) $(MISC) $(FIELD)
	@$(CC) $(CFLAGS) $(HEADERS)/Fields.cpp -o $(TMP)/field.o

$(TMP)/main.o:  preps $(HEAD) $(MISC) $(MAIN)
	@$(CC) $(CFLAGS) $(MAIN) -o $(TMP)/main.o

# all: compile
# 	./dumbbellies

clean:
	@rm -f dumbbellies
	@rm -rf $(TMP)

erase: clean
	@rm -rf Output

gt: erase
	git add *
