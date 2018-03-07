all: clean start_music t1 t2 t3
	@killall play
t1:
	@DontAsk/cookie.sh
	@make -C Cookie/ --no-print-directory
	@echo ""
	@sleep 3
t2:
	@DontAsk/fluid.sh
	@make -C Fluid/	--no-print-directory
	@echo ""
	@sleep 3

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

erase: clean erase1 erase2 erase3

erase1:
	@make erase -C Cookie/ --no-print-directory
erase2:
	@make erase -C Fluid/ --no-print-directory
erase3:
	@make erase -C RandCheck/ --no-print-directory

clean:
	@gnuplot&
	@pkill -f gnuplot

count: erase
	@find . -name "*.cpp" -o -name "*.h" -o -name "Makefile" -o -name "*.gnu" -o -name "*.sh" | xargs wc -l

start_music: init_music
	@(play -q DontAsk/tmp.mp3) > /dev/null 2>&1 &
init_music:
	@sox DontAsk/bg.mp3 DontAsk/tmp.mp3 trim 53.3 > /dev/null 2>&1 