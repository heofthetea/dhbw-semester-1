**Objects**, but in boring
_Collections_ of individual data

> Acts in memory like a simple data type!!

## 1. real existent
Actually gets _memory_ reserved in main memory.
--> corresponds to _singular_ Object in OOP languages

##### create a struct
```c
struct 
{
	char name[32];
	int age;
	float salary;
} student;
```

##### access a struct
```c
student.age = 18;
strcpy(dhstudent.name, "Emil");
```


Can be an array:
```c
struct 
{
	char name[32];
	int age;
	float salary;
} students[20];

//use
students[3].name[19];
```


## 2. Model
Much closer to _Classes_ and _Objects_ from OOP.

```c
struct m_student 
{
	char name[32];
	int age;
	float salary;
};

struct m_student hannes, TINF23B[28], *pointerStudent;
hannes.gehalt = 2.4;
strcpy(TINF23B[6].name, "Tim");

pointerStudent = &hannes;
```

When using structs in _header files_, defined structs **must** be a Model!


## 3. combined
Creates _one_ [[#1. real existent]] struct, but _also_ creates a [[#2. Model]]
```c 
struct m_student 
{
	char name[32];
	int age;
	float salary;
} dhbw_student;
```

## 4. custom data type
This, actually, resembles **objects/classes** in OOP. Only exceptionis, there is no methods.
DOESN'T need the`struct` keyword when instantiated
--> instead, the name given to the struct is used (`t_student` in this case)
```c
typedef struct 
{
	char name[32];
	int age;
	float salary;
} t_student;

t_student hannes, lisa; // etc
```

### use model with typedef:
```c
typedef struct m_student
{
	char name[32];
	int age;
	float salary;
	
	struct m_student
} t_student;

t_dhler hannes, lisa; // etc

```


## Size of a struct
In memory, the _size_ of a struct is the size of _all_ its attributes combined

```c
struct
{
	int i; // 4 byte
	float f; // 4 byte
	char c[4]; // 4 byte
} data;
```
==> Size: 4 + 4 + 4 byte = 12 byte



## Unions
Difference: Data gets _overwritten_
```c
union
{
	int i;
	float f;
	char c[4];
} data;
```
only 4 bytes reserved in total

## Traps
### size limit
A struct gets a certain amount of Memory reserved (~2 MB)
	--> If this limit is reached, the result is a [[Segmentation Fault]]
