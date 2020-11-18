  # lab_4_cpp 3530904/00001 Осипов Александр вариант №8

## Описание программы:
Данная программа проверяет строки на дубликаты символов, используя char и string
### вход: длина строк и их содержимое (файл data.txt)
### выход: тип строки (char/string): результат (True/False)
  
 ### тестовые данные для файла data.txt:
 * Вход:
 ```
6
qwerty
-4
qwertyu
e
qwertyui
9
qweqweqwe
```
- Выход:
```
char: False

 Ошибка при чтении файла, данные некорректны!
```
* Вход:
```
6
qwerty
7
qwertyu
8
qwertyui
9
qweqweqwe
10
qwert yuio
11
qwert yuioq
```
- Выход:
```
char: False
char: False
char: False
char: True
char: False
char: True
string: False
string: False
string: False
string: True
string: False
string: True
```

