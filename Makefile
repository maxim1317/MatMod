all: compile
	@./randcheck 

compile: clean
	@mkdir -p rands/
	@clang++ --std=c++11 src/randcheck.cpp -o randcheck

# all: compile
# 	./randcheck

clean:
	@rm -f randcheck

gen: compile
	@./randcheck -n

erase: clean
	@rm -rf rands

gt: erase
	git add *