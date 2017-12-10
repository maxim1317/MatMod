all: t1 t2 t3

t1:
	@DontAsk/cookie.sh
	@make -C Cookie/ --no-print-directory
	@echo ""
t2:
	@DontAsk/fluid.sh
	@make -C Fluid/	--no-print-directory
	@echo ""
t3:
	@DontAsk/randcheck.sh
	@make -C RandCheck/ --no-print-directory
	@echo ""

gt: gt1 gt2 gt3
	git add *
gt1:
	@make gt -C Cookie/ --no-print-directory
gt2:
	@make gt -C Fluid/ --no-print-directory
gt3:
	@make gt -C RandCheck/ --no-print-directory

erase: erase1 erase2 erase3

erase1:
	@make erase -C Cookie/ --no-print-directory
erase2:
	@make erase -C Fluid/ --no-print-directory
erase3:
	@make erase -C RandCheck/ --no-print-directory
