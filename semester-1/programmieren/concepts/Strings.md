### string termination
A string is terminated by a `\0` (hex. 0) in memory.
This termination character is looked for by most string operations.
#### strcpy and strncpy
`strcpy` --> prototype: `char* strcpy(char*, char*)
`strncpy` --> prototype: `char* strncpy(char*, char*, int);`
	Übernimmt keine `\0` --> String terminiert nicht!!!

usage: 
```c
char* strcpy(char*, char*); // copies string from second param to first
char* strncpy(char*, char*, int); // copies spedific number of characters from second string to first

//usage
char t1[20 + 1], t2[20 + 1];
strcpy(t1, "Hannes")

strncpy(t2, t1, 3) // -> in t2 steht jetzt "Han"
``` 

#### strcat
von: "concatinate" ==> anhängen
sucht so lange, bis er einen _Terminator_ findet - hier wird angehängt, nicht "ans Ende"!!
```c
strcpy(t2, t1);
strcat(t2, " ist schlau"); // hier steht jetzt "Hannes ist schlau \0"
```

#### strncat
DOESN'T search for terminating nul!!
but stops concatinating at the first nul it reaches.

usage: 
```c
strncat(to, from, from_index)
```


#### strlen
get length of the input string. _DOESN'T INCLUDE TERMINATING NUL!!_ 

#### strrev
reverses string
"Hannes" --> "sennaH"


#### strchr
searches for a character in a string.
```c
//prototype
char* strchr(char*, char)
```
returns **pointer**  to _first_ occurance of given character, or `0` (null-pointer) if not found.

#### strstr
searches for substring in a string.
returns **pointer** to _start_ of first occurance of substring,  or `0` (null-pointer) if not found.


#### strcmp
compares 2 strings for equality.
```c
//prototype
int strcmp(char*, char*)
```

works by _subtracting_ the 2 strings from one another, character by character 
	--> as soon as the result is not equal to 0, function terminates and returns difference of characters at position

$A - A = 0$ ==> match
$A - B = -1$ ==> do not match, B is larger
$A - a = -32$ ==> do not match; `return -32`
$a - A = 32$ ==> do not match, `return 32`

outputs:
	$0$ --> strings match
	$\not= 0$--> strings do not match



#### atoi
= anything to int


#### puts
Prints out a string without all that formatting bullshit of printf
