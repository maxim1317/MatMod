all: t1 t3

t1:
	@make -C Cookie/
t3:
	@make -C RandCheck/
gt: gt1 gt3
	git add *

gt1:
	@make gt -C Cookie/
gt3:
	@make gt -C RandCheck/
