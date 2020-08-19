# ft_printf

## Обзор проекта

![alt text](https://github.com/eldaroid/pictures/blob/master/printf_algo.png)

*ft_printf* - это первый алгоритмический проект в [школе программирования от Сбербанка](https://21-school.ru/). Целью *ft_printf* является написание аналога функции printf (библиотека <stdio.h>) с использованием функций из ранее написанной библиотеки [libft](https://github.com/eldaroid/libft-fgracefo). Этот проект был завершен 15го августа 2020 года и оценен на 98 баллов.

![alt text](https://github.com/eldaroid/pictures/blob/master/score_of_printf.png)

## Реализация функции printf на языке С

*ft_printf* получает строку, называемую форматом, которая может содержать ряд заполнителей представленных после символа % и тип преобразования данных (строка (str), символ (char), int в десятичное, int в шестнадцатеричное и т. д.) Между «%» и типом преобразования может находиться ряд параметров: ширина (<number> or *), модификаторы длинны (h, hh, l, ll, L), точность (<number> or *), флаги (#, 0, ' ', +, -).
![alt text](https://github.com/eldaroid/pictures/blob/master/structure_of_printf.png)
