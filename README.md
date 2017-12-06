# Лабораторные работы по МатМоду

Тут собраны все выполненные мной лаборатоки по матмоду, включая:
* [Модель печеньки](#cookie)
* [Проверка рандомов на рандомность](#randcheck)

## Сборка

Сборка выполняется в коммандной строке Linix систем командой ***make***, которая выполняет сразу сборку и выполнение программ.

## Иерархия файлов

### /

* [Makefile](Makefile) - глобальный Makefile, умеющий собирать все вложенные проекты, а также подготавливать их к коммиту
* [Readme.md](Readme.md) - что тут сказать, вы его читаете

#### Cookie/

Программа, считающая изменение температуры печенья, погруженного в горячий чай.

* [Makefile](Cookie/Makefile) - собственно, Makefile, описывающий правила сборки Cookie.
* [params.txt](Cookie/params.txt) - входные параметры в формате "<начальная_температура_печенья> <температура_чая> <коэффициент> <время_реакции>"

#### Cookie/src/

* [cookie.cpp](Cookie/src/cookie.cpp) - main(). В принципе, вся логика тут пока
* [headers/](Cookie/src/headers/) - директория с описанием всех используемых функкций
  * [randcheck.h](Cookie/src/headers/cookie.h) - главный заголовочный файл с прототипами функций
  * [misc.cpp](Cookie/src/headers/misc.cpp) - вспомогательные функции для вывода в терминал


#### RandCheck/

Программа для тестирования LCG на рандомность по четырем критериям. 
Сначала идёт генерация файлов со случайными числами(если они еще не были сгенерированы) из отрезка [0, 1].
Затем идёт само тестирование.

* [Makefile](RandCheck/Makefile) - собственно, Makefile, описывающий правила сборки RandCheck.

#### RandCheck/src/

* [randcheck.cpp](RandCheck/src/randcheck.cpp) - main(). В нем задается количество рассматриваемых элементов
* [headers/](RandCheck/src/headers/) - директория с описанием всех используемых функций
  * [randcheck.h](RandCheck/src/headers/randcheck.h) - главный заголовочный файл с прототипами функций
  * Генераторы:
    * [chigen.cpp](RandCheck/src/headers/chigen.cpp) - генератор таблицы  χ2
    * [randgen.cpp](RandCheck/src/headers/randgen.cpp) - генератор случайных чисел по заданным параметрам
    * [randlist.cpp](RandCheck/src/headers/randlist.cpp) - список параметров разных генераторов
    * [gens.cpp](RandCheck/src/headers/gens.cpp) - вспомогательный файл для сборки
  * Тесты:
    * [crit_all.cpp](RandCheck/src/headers/crit_all.cpp) - вызывает все четыре проверки
    * [crit_freq.cpp](RandCheck/src/headers/crit_freq.cpp) - частотный критерий
    * [crit_pair.cpp](RandCheck/src/headers/crit_pair.cpp) - критерий пар
    * [crit_series.cpp](RandCheck/src/headers/crit_series.cpp) - критерий серий
    * [crit_poker.cpp](RandCheck/src/headers/crit_poker.cpp) - покер-критерий
    * [crits.cpp](RandCheck/src/headers/crits.cpp) - вспомогательный файл для сборки
  * [misc.cpp](RandCheck/src/headers/misc.cpp) - вспомогательные функции для разукраски терминала и выуживания опций из аргументов программы
