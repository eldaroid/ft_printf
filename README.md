# ft_printf

## Обзор проекта

![alt text](https://github.com/eldaroid/pictures/blob/master/printf_algo.png)

*ft_printf* - это первый алгоритмический проект в [школе программирования от Сбербанка](https://21-school.ru/). Целью *ft_printf* является написание аналога функции printf (библиотека <stdio.h>) с использованием функций из ранее написанной библиотеки [libft](https://github.com/eldaroid/libft-fgracefo). Этот проект был завершен 15го августа 2020 года и оценен на 98 баллов.

![alt text](https://github.com/eldaroid/pictures/blob/master/score_of_printf.png)

## Реализация функции printf на языке С

*ft_printf* получает строку, называемую форматом, которая может содержать ряд заполнителей представленных после символа % и тип преобразования данных (строка (str), символ (char), int в десятичное, int в шестнадцатеричное и т. д.) Синтаксис: %[flags][width][.precision][length]type
  
![alt text](https://github.com/eldaroid/pictures/blob/master/structure_of_printf.png)

Краткое изложение различных типов:

|   Тип формата   |   Тип аргумента   |   Результат   |
|:----------:|:----------------:|:------:|
|      d / i |   int  | Печатает int в десятичной форме |
|   o   |   unsigned int   | Печатает int в восьмеричной форме |
|   u   |   unsigned int   | Печатает unsigned int в десятичной форме |
|   x   |   unsigned int   | Печатает int в шестнадцатеричной форме (в нижнем регистре)  |
|   X   |   unsigned int   | Печатает int в шестнадцатеричной форме (в верхнем регистре) |
|   c   |   char   | Печатает символ |
|   s   |   char *   | Печатает строку |
|   p   |   void *   | Печатает адрес указателя |
|   f   |   double   | Печатает число с плавающей запятой (точность по умолчанию - 6) |

Между «%» и типом преобразования может находиться ряд параметров: ширина (число или *), модификаторы длинны (h, hh, l, ll, L), точность (число или *), флаги (#, 0, ' ', +, -).

*Ширина поля* - это минимальная длина строки, полученная в результате преобразования, и указывается в виде числа. По умолчанию, если пpеобpазованное значение имеет меньшее количество знаков, чем шиpина поля, то оно слева дополняется пpобелами (или спpава, если указан флаг левого пpеобpазования). заполнения дополнительных символов слева. Небольшая ширина не делает результат преобразования усеченным - если pезультат пpеобpазования больше шиpины поля, то поле pасшиpяется, чтобы вместить в себя пpеобpазованное значение.

*Точность* - это десятичное число, перед которым стоит точка. Для типов diouxX точность - это минимальная длина строки, дополненная слева 0, если результат преобразования короче, чем точность. Для преобразования f точность указывает количество цифр до которых необходимо округлить число. Для преобразований s точность дает максимальное количество символов, которые должны быть напечатано из аргумента.

| Flag | Effect |
|:----:|:------:|
| - | Left-justify within the field width |
| + | Forces positive numbers to be preceded with a '+' sign |
| ' ' (space) | If no sign is going to be written, a blank space is inserted before the value |
| # | o, x and X conversions are preceded with 0, 0x or 0X respectively |
| 0 | Pads with zeros instead of the default spaces |

| Modifiers | Effect |
|:---------:|:------:|
| hh | di accept a signed char, ouxX an unsigned char |
| h | di accept a short int, ouxX an unsigned short int |
| l | di accept a long int, ouxX an unsigned long int, c a wint_t and s a wchar_t* |
| ll | di accept a long long int, ouxX an unsigned long long int |
| j | di accept an intmax_t, uoxX an uintmax_t |
