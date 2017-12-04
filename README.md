# MatMod

Программа для тестирования LCG на рандомность по четырем критериям. 
Сначала идёт генерация файлов со случайными числами(если они еще не были сгенерированы) из отрезка [0, 1].
Затем идёт само тестирование.

## Сборка

Сборка выполняетсяв коммандной строке Linix систем командой ***make***, которая выполняет сразу сборку и выполнение программы.

## Иерархия файлов

### /

* [Makefile](https://github.com/maxim1317/MatMod/blob/Makefile) - собственно, Makefile, описывающий правила сборки.

### /src

* [randcheck.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/randcheck.cpp) - main(). В нем задается количество рассматриваемых элементов.
* [/src/headers](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/) - директория с описанием всех используемых функкций
  * [randcheck.h](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/randcheck.h) - главный заголовочный файл с прототипами функций
  * Генераторы:
    * [chigen.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/chigen.cpp) - генератор таблицы  χ2
    * [randgen.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/randgen.cpp) - генератор случайных чисел по заданным параметрам
    * [randlist.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/randlist.cpp) - список параметров разных генераторов
    * [gens.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/gens.cpp) - вспомогательный файл для сборки
  * Тесты:
    * [crit_all.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/crit_all.cpp) - вызывает все четыре проверки
    * [crit_freq.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/crit_freq.cpp) - частотный критерий
    * [crit_pair.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/crit_pair.cpp) - критерий пар
    * [crit_series.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/crit_series.cpp) - критерий серий
    * [crit_poker.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/crit_poker.cpp) - покер-критерий
    * [crits.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/crits.cpp) - вспомогательный файл для сборки
  * [misc.cpp](https://github.com/maxim1317/MatMod/blob/master/RandCheck/src/headers/misc.cpp) - вспомогательные функции для разукраски терминала и выуживания опций из аргументов программы
