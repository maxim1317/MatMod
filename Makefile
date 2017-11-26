ifeq ("$(wildcard rands/*.rand)","")
	OPT = "-n"	
else
	OPT = 
endif

all: compile
	@./randcheck $(OPT)

compile: clean
	@mkdir -p rands/
	@clang++ --std=c++11 src/randcheck.cpp -o randcheck

# all: compile
# 	./randcheck

clean:
	@rm -f randcheck

erase: clean
	@rm -rf rands

gt: erase
	git add *
