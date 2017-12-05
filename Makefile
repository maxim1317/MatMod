all:
	@make -C Cookie/
	@make -C RandCheck/
gt:
	@make gt -C RandCheck/
	@make gt -C Cookie/
	git add *
