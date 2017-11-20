compile: clean
	@mkdir -p rands/
	@clang++ --std=c++11 src/randcheck.cpp -o randcheck
	@./randcheck 

# all: compile
# 	./randcheck

clean:
	@rm -f randcheck