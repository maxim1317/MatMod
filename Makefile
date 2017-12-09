all: t1 t2 ьфлуt3

t1:
	@make -C Cookie/
t2:
	@make -C Fluid/	
t3:
	@make -C RandCheck/
	
gt: gt1 gt2 gt3
	git add *
gt1:
	@make gt -C Cookie/
gt2:
	@make gt -C Fluid/
gt3:
	@make gt -C RandCheck/

erase: erase1 erase2 erase3

erase1:
	@make erase -C Cookie/
erase2:
	@make erase -C Fluid/
erase3:
	@make erase -C RandCheck/
