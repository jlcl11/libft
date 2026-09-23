*Este proyecto ha sido creado como parte del currículo de 42 por jocorral.*

# Libft

## Descripción

Libft es el primer proyecto en C del cursus de 42. El objetivo es reimplementar con el prefijo `ft_` un conjunto de funciones de la `libc` (memoria, cadenas...), añadir un segundo bloque de funciones adicionales que hacen falta en casi todos los proyectos siguientes (split, join, trim, itoa, escritura a un
file descriptor...) y, por último listas enlazadas (`t_list`).

## Instrucciones

Compilar (genera `libft.a` en la raíz del repo):

```sh
make
```

Otras reglas del `Makefile`:

```sh
make clean    # borra obj/
make fclean   # borra obj/ y libft.a
make re       # fclean + all
```


### Probar una función suelta

No hay un `main.c` en el repo — cada `ft_*.c` tiene al final, dentro de un comentario `/* ... */` (así no cuenta para la Norma), un `main` pequeño que prueba
solo esa función.

1. Descomenta el bloque del archivo que quieras probar.
2. `make`, si aún no está compilada la librería.
3. `cc -Wall -Wextra -Werror ft_isalpha.c && ./a.out`
4. Vuelve a comentar el bloque antes de hacer commit.

Y para comprobar que no queda ningún leak:

```sh
valgrind --leak-check=full ./a.out
```

### Testear con libftTester

Para una batería de tests más completa (todas las funciones obligatorias, con comprobación de leaks vía `valgrind` en Linux) se usa el tester de
[Tripouille](https://github.com/Tripouille/libftTester), clonado dentro del propio repo en `libftTester/` (carpeta ignorada por git, cada uno la clona en su
copia local):

```sh
git clone https://github.com/Tripouille/libftTester.git
```

El `Makefile` del tester deduce la ruta a la libft a partir del directorio padre (`dirname $(pwd)`), por eso tiene que vivir *dentro* de este repo
(`libft/libftTester/`) y no al lado.

Comandos principales (ejecutar desde `libftTester/`):

```sh
make m                  # lanza todos los tests obligatorios
make atoi                # lanza solo el test de una función, ej. ft_atoi
make docker atoi         # igual, pero dentro de un contenedor Linux (para probar valgrind desde mac)
make vs atoi              # abre en VSCode el .cpp del test de esa función
```


## Recursos

Documentación consultada al escribir las funciones, más que nada para comparar el comportamiento exacto (casos límite, valor de retorno) con el de la función
original:

- Páginas de manual de la `libc`: `man 3 memcpy`, `man 3 memmove`, `man 3 strlcpy`, `man 3 strlcat`, `man 3 strchr`, `man 3 strnstr`, `man 3 calloc`.
- [cppreference.com](https://en.cppreference.com/) para consultar los prototipos y el comportamiento indefinido de `<string.h>`/`<stdlib.h>`.
- La Norma de 42 (documento del cursus), para las reglas de estilo (funciones auxiliares `static`, límite de líneas, etc.).

## La librería

### Parte 1 — Funciones de `libc`

`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`,
`ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`,
`ft_strdup`.

Lo más delicado de este bloque:

- `ft_memmove` tiene que distinguir si `dst` está antes o después de `src` en memoria. Si `dst > src`, copiar de izquierda a derecha pisaría bytes de `src`
  que todavía no se han leído, así que en ese caso copia de derecha a izquierda (de `len - 1` hacia `0`) con una función auxiliar.
- `ft_atoi` acumula en `long`, no en `int`.
- `ft_calloc` comprueba el overflow de `nmemb * size` *antes* de multiplicar (`size > (size_t)-1 / nmemb`), no después de que ya se haya desbordado.

### Parte 2 — Funciones adicionales

`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`,
`ft_putnbr_fd`.

`ft_strtrim` comprueba si la cadena de entrada está vacía antes de restar 1 a `ft_strlen(s1)` (si no, esa resta se hace sobre un `size_t` en `0` y el
resultado sale mal). `ft_split` cuenta primero cuántas palabras hay (bloques separados por el delimitador, ignorando delimitadores repetidos o en los
extremos) para reservar el array de punteros con el tamaño exacto. `ft_putnbr_fd` no usa `ft_itoa` (eso habría metido un `malloc` donde el enunciado solo
autoriza `write`): escribe dígito a dígito de forma recursiva, acumulando en `long` para poder negar `INT_MIN` sin desbordar.

### Part 3 — Listas enlazadas (`t_list`)

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

Lo esperable de una lista enlazada simple. Dos detalles que vale la pena mirar: `ft_lstclear` guarda `next` del nodo *antes* de llamar a `ft_lstdelone`,
porque esa función libera el nodo y si no se guarda antes se pierde el puntero al siguiente. Y en `ft_lstmap`, si `f()` devuelve `NULL` para algún contenido,
se trata como un fallo — se libera con `ft_lstclear` todo lo creado hasta ese momento y se devuelve `NULL` (el enunciado solo lo exige cuando falla el
`malloc`, pero he aplicado el mismo criterio para un `f` que devuelve `NULL`).

## Estructura

```
libft.h        cabecera con los prototipos y t_list
Makefile       all / clean / fclean / re
ft_*.c         una función (o función + estáticas auxiliares) por archivo
obj/           .o generados por make (no se sube)
libft.a        librería final (no se sube)
```
