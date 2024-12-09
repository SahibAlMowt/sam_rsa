# RSA

Первая функция *sam_input* считывает строку и записывает цифры из строки в вектор. 

Берутся два числа _p_,_q_. Можно взять из файла `input.txt`.

Вычисляется открытый ключ _n_ при помощи функции *sam_mp*:
    
  $$  n = p \cdot q $$

*sam_mp* это функция умножения.

Также будет вычисляться _φ_:

  $$  φ = (p - 1) \cdot (q - 1) $$

Вычисляем открытую экспоненту _e_. Числа _e_ и _φ_ должны быть взаимно простыми. Это проверяется в функции sam_gcd.

Вычисляем закрытую экспоненту _d_. 

   $$ d = \frac{(k \cdot φ + 1)} e $$

Для вычисления _d_ используется функция *sam_calculation_d*.

Вводим строку _m_, которую хотим зашифровать. Записывается с помощью функции *sam_input_char*.

**Важно!** Все целочисленные коды символов строки, если их соединить, **не должны быть больше переменной** _n_.

Начинается этап шифрования, вызывается функция *sam_encryption_char*.

  $$ c = m^e \pmod{n} $$


Далее полученный результат, расшифровываем, с помощью функции *sam_decryption_char*.

$$ m = c^d \pmod{n} $$

_m_ должен быть равен введенному сообщению.


## Инструкция для пользователя
1. Введите _p_, _q_ (большие, простые числа). 
2. Введите message. 

    Все целочисленные коды символов строки, если их соединить, **не должны быть больше переменной** _n_.