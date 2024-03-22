## keywords
`signed` --> specifies a value should be signed



## stdio
### printf
prints out something
use: `printf("...", )` 


| placeholder | datatype |
| ---- | ---- |
| `%d`, `%i"` | integer |
| `%f` | float |
| `%lf` | double |
| `%c` | char |
| `%u` | unsigned integer |
| `%s` | string |
| `%x, %X` | hex-darstellung |
|  |  |
%20d --> _always_ prints out value with 20 bytes (uses _leading_ blanks)
%-20d --> same, but puts blanks on the right side
### scanf
**Achtung:** input buffer löschen:
```c
scanf("%i" &i);
fflush(stdin); // deletees input buffer
```
Address Operator:
`&i` - initializes variable `i` to input scanf
!! Variablen müssen deklariert sein 
![[Begriffe Programmieren#Deklaration / Definition]]

**DON'T USE & OPERATOR FOR ARRAYS ETC. THAT ARE POINTERS!!!!**
```c
float f1;
char c;

scanf("%f" &f1);
scanf("%c", &c);
scanf("%lf", &lf);
scanf("%s", text) // here no address operator, because already is a pointer
```


### gets
Alternative to [[#scanf]]
```c
char str[20];
gets(str);
```
==> stroresl input to `str`.


### clear terminal
```c
system("clear");
```


## Arrays
**You know what an array is, you're only here for the syntax**
### character array
**Strings need ending character** ==> `char[64]` can only hold 63 characters

Beispiel: Temperatur
- stets drei Messwerte pro Tag (mogen, mittag, abend)
```c
//one-dimensional
int temperature[3];
temperature[0] = 10;

//two-dimensional
int temperatureWeekly[7][3];
temperature[4][2] = 15;

//three-dimensional
int temperature_yearly[52][7][3];
temperature_yearly[48][3][1];
```

**Achtung** keine Exceptions
--> no `IndexOutOfBounds`
==> acesses something not part of the arrey:
1. allowed to access -> writes somewhere it shouldn't be
2. not allowed to access memory -> Acces Right Violation


## Operators
#### increments
###### post-increment
`i ++` -> the usual
###### pre-increment
`++i`

```c
int i = 7;
printf("%d", ++i) // ouptus 8

i = 7;
printf("%d", i++) // outputs 7

```


### bitwise operations

| operator | logical equivalent |
| -------- | ------------------ |
| ~     | $\lnot$            |
| \|       | $\lor$             |
| &        | $\land$            |
| ^        | $\oplus$           |



```c
char a = 7, b;
b = ~a; // b == -8
```

$7_{10} = 0000 0111_2$
$\lnot (0000 0111_2) = 1111 1000_2$ 
$1111 1000_{2}= -8_{10}$

#### shift operations
```c
int a = 7, b;
b = a << 3; // b = 7 * 2³

a = 27;
b >> 2; // b = 6 (27 / 4 = 6 (ignore rest))
```

$1)\;0000\,0111 \rightarrow 0011\,1000$ 
$2)\; 0001\,1011 \rightarrow 0000\,0110$ 

- moves every bit `n` spaces into a given direction
- `n` bits will be "removed" so-to-speak when shifting out of bounds of a variable



## Pointer / Address Operators

|  Pointer | Address Operator|
|---|---|
| \* | \&|
für Pointer bei Arrays:
	$* \equiv [ ]$

Since pointers are numbers, you can do fancy math with them.
```c
int p1 = some_value;
p1 = p1 + 3; // moves the memory byte the pointer points to 3 bytes to the right
```
Pointers are type-bound:
when running pointer arithmetic, pointer increases 
### Data types

|           |            |
| --------- | ---------- |
| character | 8 bits --> |
|           |            |

### jwd pointers
uninitialized pointer, that doesn't have a value yet

### Random

rand() ==> $0 ... 32565$

```c
srand(value); // set starting value of random generation
int randint = rand();

```

Zahlen folgen _immer_ gleichem System
==> 



## dimensions of a variable
###### data type
###### name
###### value
###### address


## Segmentation Fault
Occurs whenever program tries to write to memory it is not allowed to 
--> usually because something is too big (similar to `OutOfBoundsException` in Java)



## malloc
Manually allocates memory of a given byte size.
```c
uint64_t *temp =(uint64t *) malloc(sizeof(uint64_t));
```
Reserves 8 byte of memory. Returns the pointer _to_ that reserved memory.

> [!warningAlways cast to correct type!! Only this way, memory will behave as expected.