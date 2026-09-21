*Este proyecto ha sido creado como parte del currículo de 42 por jocorral.*

# Libft

## Descripción

Libft es el primer proyecto en C del cursus de 42: consiste en reimplementar,
con el prefijo `ft_`, un conjunto de funciones estándar de la `libc` (parte 1),
añadir un conjunto de funciones propias muy útiles para proyectos posteriores
—manejo de cadenas dinámicas, conversión de números, funciones de orden
superior sobre strings, escritura en descriptores de archivo— (parte 2), y por
último implementar una pequeña librería de listas simplemente enlazadas
(parte 3, bonus).

El resultado es una librería estática (`libft.a`) que se reutiliza en
prácticamente todos los proyectos de C del cursus.

## Instrucciones

Compilar la librería (genera `libft.a` en la raíz):

```sh
make
```

Otras reglas del `Makefile`:

```sh
make clean   # elimina la carpeta obj/ (los .o)
make fclean  # elimina obj/ y libft.a
make re      # fclean + all
```

Para usarla en otro proyecto, basta con copiar `libft.h` y `libft.a` (o el
código fuente junto a su Makefile) e incluir la cabecera:

```c
#include "libft.h"
```

y enlazar con `-L. -lft` al compilar.

### Programa de pruebas

No hay un `main.c` único: cada archivo `ft_*.c` tiene, al final y comentado
(entre `/*` y `*/`, por lo que no cuenta para la Norma), un pequeño `main`
que prueba solo esa función. Para probar una función:

1. Abre su archivo y descomenta el bloque `/* ... */` del final.
2. Compila la librería si no lo has hecho ya (`make`).
3. Compila ese archivo enlazando contra la librería:

```sh
cc -Wall -Wextra -Werror ft_isalpha.c -L. -lft -o test && ./test
```

4. Vuelve a comentar el bloque antes de hacer commit (si tienes varios `main`
   descomentados a la vez, o si compilas todo el proyecto con `make`, dará
   error por redefinición de `main`).

Se puede además ejecutar bajo Valgrind para comprobar que no hay fugas de
memoria:

```sh
valgrind --leak-check=full ./test
```

## Descripción detallada de la librería

### Parte 1 — Funciones de `libc`

- **`ft_isalpha(int c)`** — clasifica letras.
  - Comprueba `(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')` y devuelve `1`/`0`.
- **`ft_isdigit(int c)`** — clasifica dígitos.
  - Comprueba `c >= '0' && c <= '9'`.
- **`ft_isalnum(int c)`** — clasifica alfanuméricos.
  - No repite lógica: `return (ft_isalpha(c) || ft_isdigit(c));`.
- **`ft_isascii(int c)`** — clasifica caracteres ASCII.
  - Comprueba `c >= 0 && c <= 127` (incluye el `127`/DEL, que es ASCII aunque no imprimible).
- **`ft_isprint(int c)`** — clasifica caracteres imprimibles.
  - Comprueba `c >= 32 && c <= 126`.
- **`ft_toupper(int c)`** — pasa a mayúscula.
  - Si `c` está en `97-122` (`'a'-'z'`) resta `32`; en cualquier otro caso devuelve `c` sin tocar.
- **`ft_tolower(int c)`** — pasa a minúscula.
  - Si `c` está en `65-90` (`'A'-'Z'`) suma `32`.
- **`ft_strlen(const char *s)`** — longitud de una cadena.
  - Contador `i` (`size_t`) a `0`, bucle `while (s[i] != '\0') i++;`, devuelve `i`.
- **`ft_memset(void *s, int c, size_t n)`** — rellena memoria.
  - Castea `s` a `unsigned char *str` y escribe `str[i] = (unsigned char)c` para `i` de `0` a `n-1`. Devuelve el puntero original `s` (no `str`).
- **`ft_bzero(void *s, size_t n)`** — pone a cero.
  - No repite bucle: llama a `ft_memset(s, '\0', n)`.
- **`ft_memcpy(void *dst, const void *src, size_t n)`** — copia memoria.
  - Castea a `char *`/`const char *` y copia byte a byte con un índice `i`. No comprueba solapamiento (igual que la `memcpy` real, es comportamiento indefinido si `dst` y `src` se solapan).
- **`ft_memmove(void *dst, const void *src, size_t len)`** — copia memoria con solape.
  - Primero descarta el caso trivial `dest == source || len == 0`.
  - Si `dest < source`, copia de izquierda a derecha (índices crecientes): es seguro porque siempre se lee más adelante de donde se escribe.
  - Si `dest > source`, delega en una función auxiliar `static ft_memmove_back_to_front` que copia de derecha a izquierda (`len - 1` hacia `0`), para no sobrescribir bytes de `src` que aún no se han leído.
- **`ft_strlcpy(char *dst, const char *src, size_t dstsize)`** — copia segura.
  - Si `dstsize == 0`, no escribe nada en `dst` (ni siquiera el `'\0'`).
  - Si no, copia como máximo `dstsize - 1` caracteres y siempre añade `'\0'` al final.
  - Devuelve `ft_strlen(src)`: la longitud que *habría* copiado si hubiese hueco, igual que la función real.
- **`ft_strlcat(char *dst, const char *src, size_t dstsize)`** — concatenación segura.
  - Guarda `dstlen = ft_strlen(dst)` **antes** de escribir nada (se necesita intacto para el valor de retorno).
  - Si `dstsize <= dstlen` no hay hueco: devuelve `dstsize + ft_strlen(src)` sin tocar `dst`.
  - Si no, copia caracteres de `src` a partir de `dst[dstlen]` mientras `i < dstsize - 1`, añade `'\0'` y devuelve `dstlen + ft_strlen(src)` (la longitud que intentó crear, no la truncada).
- **`ft_strchr(const char *s, int c)`** — busca desde el inicio.
  - Recorre `s` comparando `s[i] == (char)c`.
  - Si termina el bucle sin encontrarlo, comprueba si `c == '\0'`: en ese caso devuelve un puntero al propio terminador, igual que la función real.
- **`ft_strrchr(const char *s, int c)`** — busca desde el final.
  - Empieza en `i = ft_strlen(s)` (el índice del `'\0'`) y decrementa `i` hasta `0`, así encuentra la última aparición (y permite buscar `c == 0`).
- **`ft_strncmp(const char *s1, const char *s2, size_t n)`** — compara `n` caracteres.
  - Compara byte a byte como `unsigned char` hasta `n` o hasta que alguna cadena termine.
  - Ante la primera diferencia devuelve `1` o `-1` según cuál sea mayor (mismo signo que la real, aunque no la diferencia exacta).
- **`ft_memchr(const void *s, int c, size_t n)`** — busca un byte.
  - Castea a `const unsigned char *` y recorre `n` bytes comparando con `(unsigned char)c`; devuelve un puntero al byte o `NULL`.
- **`ft_memcmp(const void *s1, const void *s2, size_t n)`** — compara bloques.
  - Igual que `ft_strncmp` pero sin pararse en `'\0'`: compara exactamente `n` bytes como `unsigned char`.
- **`ft_strnstr(const char *big, const char *little, size_t len)`** — busca subcadena limitada.
  - Caso especial: si `little` es `""`, devuelve `big` directamente.
  - Bucle externo con índice `d` recorre `big` mientras `d < len`; bucle interno con índice `j` compara `little` contra `big + d`, respetando siempre el límite `d + j < len`.
  - Si `little[j] == '\0'` al salir del bucle interno, ha encontrado una coincidencia completa dentro del límite.
- **`ft_atoi(const char *nptr)`** — cadena a `int`.
  - Salta espacios y los caracteres de control `'\t'`-`'\r'` (equivalente a `isspace`).
  - Procesa un único signo opcional (`+`/`-`) guardado en `signo`.
  - Acumula dígitos con `ret = ret * 10 + (nptr[i] - '0')` mientras `ft_isdigit(nptr[i])`, y aplica el signo al final.
- **`ft_calloc(size_t nmemb, size_t size)`** — reserva memoria a cero.
  - Comprueba overflow **antes** de multiplicar: `nmemb != 0 && size > (size_t)-1 / nmemb`.
  - Reserva con `malloc(nmemb * size)` y limpia con `ft_memset(puntero, 0, nmemb * size)` (reutiliza la función ya implementada en vez de un bucle propio).
- **`ft_strdup(const char *s)`** — duplica una cadena.
  - Reserva `ft_strlen(s) + 1` bytes y copia con `ft_strlcpy(ret, s, len + 1)` en vez de un bucle manual.

### Parte 2 — Funciones adicionales

- **`ft_substr(char const *s, unsigned int start, size_t len)`** — extrae una subcadena.
  - Calcula `s_len = ft_strlen(s)`.
  - Si `start >= s_len`, `len` pasa a `0` (fuera de rango → cadena vacía).
  - Si no, recorta `len` cuando se pasaría del final: `if (len > s_len - start) len = s_len - start;`.
  - Reserva `len + 1`, copia `s[start .. start+len)` y añade `'\0'`.
- **`ft_strjoin(char const *s1, char const *s2)`** — concatena en una cadena nueva.
  - Función auxiliar `static ft_strjoin_copy(dst, src, start)` copia una cadena a partir de una posición y devuelve la posición siguiente libre.
  - La función principal reserva `strlen(s1) + strlen(s2) + 1` y llama dos veces a esa auxiliar: una para `s1` desde `0`, otra para `s2` desde donde acabó la primera. El `'\0'` se escribe en la posición final que devuelve la segunda llamada.
- **`ft_strtrim(char const *s1, char const *set)`** — recorta caracteres de un set.
  - Tres funciones `static`: `is_in_set` (¿pertenece un carácter a `set`?), `devolver_pos_ini` (primer índice que NO está en `set`) y `devolver_pos_final` (último índice que NO está en `set`, recorriendo desde `ft_strlen(s1) - 1` hacia atrás).
  - Si `posfinal < posini` (toda la cadena está en `set`, o está vacía), `len = 0`.
  - Copia el rango `[posini, posfinal]` y añade `'\0'`.
- **`ft_split(char const *s, char c)`** — divide por un delimitador.
  - Dos funciones `static`: `ft_count_splitter` (cuenta apariciones de `c`, para saber cuántos huecos reservar) y `len_until_next_char` (longitud de un trozo hasta el siguiente delimitador o el final).
  - Reserva el array de punteros con `ft_count_splitter(s, c) + 2` posiciones (trozos + `NULL` final, con margen).
  - Recorre `s` saltando delimitadores repetidos (`while (s[j] == c) j++;`) y usa `ft_substr` para copiar cada trozo.
  - Termina el array con `ret[i] = NULL`.
- **`ft_itoa(int n)`** — entero a cadena.
  - Función auxiliar `static ft_intlen` calcula el número de dígitos, trabajando con `long` para poder negar `INT_MIN` sin desbordar.
  - Si `n` es negativo, se suma `1` al tamaño reservado para el signo.
  - Función auxiliar `static ft_itoa_fill` rellena de derecha a izquierda con `num % 10 + '0'` y `num /= 10`.
  - Si es negativo, se escribe `'-'` en la posición `0` antes de rellenar el resto de dígitos.
- **`ft_strmapi(char const *s, char (*f)(unsigned int, char))`** — mapea a una cadena nueva.
  - Reserva `strlen(s) + 1`.
  - Recorre `s` guardando en cada posición el resultado de `f(i, s[i])` (índice + carácter original).
  - Añade `'\0'` al final antes de devolver.
- **`ft_striteri(char *s, void (*f)(unsigned int, char *))`** — modifica in-place.
  - Recorre `s` llamando a `f(i, &s[i])`, pasando la **dirección** del carácter para que `f` pueda modificarlo directamente. No reserva memoria.
- **`ft_putchar_fd(char c, int fd)`** — escribe un carácter.
  - Una única llamada: `write(fd, &c, 1)`.
- **`ft_putstr_fd(char *s, int fd)`** — escribe una cadena.
  - Recorre la cadena escribiendo un carácter a la vez con `write(fd, &s[i], 1)`.
- **`ft_putendl_fd(char *s, int fd)`** — escribe una cadena con salto de línea.
  - Igual que `ft_putstr_fd` y, al terminar, un `write(fd, "\n", 1)` adicional.
- **`ft_putnbr_fd(int n, int fd)`** — escribe un entero.
  - Convierte `n` a texto con `ft_itoa` (reutiliza esa función en vez de reimplementar la conversión).
  - Si `ft_itoa` devuelve `NULL` (fallo de `malloc`), no hace nada.
  - Si no, lo escribe con `ft_putstr_fd` y libera la cadena temporal con `free(num)`.

### Parte 3 — Listas enlazadas (`t_list`)

- **`ft_lstnew(void *content)`** — crea un nodo.
  - `malloc(sizeof(t_list))`; si falla, devuelve `NULL`.
  - `new->content = content` (guarda el puntero tal cual, no copia el dato apuntado).
  - `new->next = NULL`.
- **`ft_lstadd_front(t_list **lst, t_list *new)`** — añade al principio.
  - No reserva memoria: `new` ya existe (normalmente creado antes con `ft_lstnew`).
  - `new->next = *lst;` engancha la lista antigua detrás; `*lst = new;` lo convierte en la nueva cabeza.
- **`unsigned int ft_lstsize(t_list *lst)`** — cuenta nodos.
  - Contador `i` (`unsigned int`, como exige el prototipo del enunciado) a `0`, avanza con `lst = lst->next` hasta `NULL`.
- **`ft_lstlast(t_list *lst)`** — último nodo.
  - Si `lst` es `NULL`, devuelve `NULL` (lista vacía). Si no, avanza mientras `lst->next` no sea `NULL`.
- **`ft_lstadd_back(t_list **lst, t_list *new)`** — añade al final.
  - Si `*lst` es `NULL` (lista vacía), `new` pasa a ser la cabeza directamente.
  - Si no, reutiliza `ft_lstlast(*lst)` para localizar el último nodo y le engancha `new` en `->next`.
- **`ft_lstdelone(t_list *lst, void (*del)(void *))`** — libera un nodo.
  - Llama a `del(lst->content)` para liberar el contenido (la función no conoce su tipo, por eso recibe `del` como parámetro) y después `free(lst)` para el nodo.
  - No toca `lst->next`: no es su responsabilidad, la gestiona quien la llama (ver `ft_lstclear`).
- **`ft_lstclear(t_list **lst, void (*del)(void *))`** — libera toda la lista.
  - Bucle `while (*lst)` que guarda `next = (*lst)->next` **antes** de llamar a `ft_lstdelone`, porque esa función hace `free()` del nodo y se perdería el puntero al siguiente si no se guardara antes.
  - Al terminar, `*lst` queda en `NULL`.
- **`ft_lstiter(t_list *lst, void (*f)(void *))`** — aplica `f` a cada contenido.
  - Recorre la lista llamando a `f(lst->content)`, sin crear ni destruir nada.
- **`ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`** — mapea a una lista nueva.
  - Por cada nodo de `lst`, aplica `f` a su contenido.
  - Si `f` devuelve `NULL` (fallo), libera con `ft_lstclear` todo lo creado hasta ese punto y devuelve `NULL`.
  - Si no, crea un nodo con `ft_lstnew(content)` y lo añade al final de la lista nueva con `ft_lstadd_back`.
  - Si `ft_lstnew` falla, libera también ese `content` recién creado con `del` antes de limpiar y devolver `NULL`.

---

## TODO — Ejercicios a repasar

Lista de todo lo que se ha corregido durante esta sesión de trabajo, para
volver sobre ello y asegurarme de que lo entiendo bien.

### Bugs corregidos (repasar por qué fallaban y cómo se detectaron)

- [ ] `ft_putstr_fd.c` — `write(fd, s[i], 1)` pasaba el **valor** del char en
      vez de su dirección (`&s[i]`); no llegaba a compilar con
      `-Wall -Wextra -Werror`.
- [ ] `ft_putnbr_fd.c` — la variable `num` estaba declarada `char` en vez de
      `char *` (no compilaba), y además no se liberaba la memoria reservada
      por `ft_itoa` (memory leak).
- [ ] `ft_strjoin.c` — `s1len = ft_strlen(s1) - 1` provocaba un desbordamiento
      de `size_t` cuando `s1` es `""` (bucle casi infinito / crash), y el
      `malloc` reservaba 2 bytes menos de los necesarios (heap overflow al
      escribir el `\0` final).
- [ ] `ft_strmapi.c` — el `malloc` no reservaba espacio para el `\0` final y
      la cadena resultante no se terminaba en `\0`.
- [ ] `ft_strlcat.c` — el valor de retorno se calculaba con la longitud de
      `dst` **después** de concatenar en vez de antes, devolviendo un
      resultado incorrecto cuando la cadena se trunca (devolvía `10` en vez
      de `8` en el test manual).
- [ ] `ft_strtrim.c` — las funciones auxiliares (`is_in_set`,
      `devolver_pos_ini`, `devolver_pos_final`) no eran `static`, requisito
      obligatorio del enunciado para funciones auxiliares.
- [ ] `ft_substr.c` — sin bug, pero repasarla junto a las anteriores porque
      comparte la misma lógica delicada de ajustar índices/longitudes antes
      de reservar memoria (`start`, `len`, `s_len`).
- [ ] `ft_lstsize.c` / `libft.h` — el prototipo usaba `int` en vez de
      `unsigned int`, que es lo que pide literalmente el enunciado (pág. 16:
      `unsigned int ft_lstsize(t_list *lst);`). No era un bug de comportamiento
      (con listas normales daba el mismo resultado), pero Moulinette compara
      el prototipo exacto, así que se corrigió el tipo de retorno y el de la
      variable contadora `i`.

### Norma (norminette) — repasar por qué fallaban

El proyecto pasa `norminette` en todos los archivos (`.c` y `.h`). Lo que
hubo que corregir para conseguirlo:

- [ ] `libft.h` — los prototipos no estaban alineados con la Norma (cada
      grupo de declaraciones debe alinearse a la misma columna, usando
      tabulaciones, según el tipo más largo del bloque).
- [ ] `ft_lstadd_front.c`, `ft_lstadd_back.c`, `ft_lstclear.c`,
      `ft_lstdelone.c`, `ft_lstiter.c`, `ft_lstlast.c`, `ft_lstmap.c` —
      tenían comentarios `//` dentro del cuerpo de la función; la Norma no
      permite comentarios dentro de una función, solo fuera de ella.
- [ ] `ft_memmove.c` y `ft_strjoin.c` — la función principal superaba las
      25 líneas; se extrajo una función auxiliar `static` para bajar de
      ese límite.
- [ ] `main.c` (eliminado) — tenía un `typedef` dentro de un `.c` (prohibido
      por la Norma), demasiadas funciones en un mismo archivo y variables
      mal indentadas. Sustituido por un `main()` de prueba comentado al
      final de cada `ft_*.c` (ver sección "Programa de pruebas" más arriba).

### Listas enlazadas (repasar implementación y comentarios)

- [ ] `ft_lstnew`
- [ ] `ft_lstadd_front`
- [ ] `ft_lstsize`
- [ ] `ft_lstlast`
- [ ] `ft_lstadd_back`
- [ ] `ft_lstdelone`
- [ ] `ft_lstclear`
- [ ] `ft_lstiter`
- [ ] `ft_lstmap`
