Bisher alles _statisch_ gelöst -> Array, immer feste Länge
_dynamisch_: Elemente löschen, hinzufügen ändert Länge der Liste

## In memory
pointer gets initialized to 0 as default
Once a successor is created: Update after to pointer of new address

|  | 10 |
| ---- | ---- |
|  | Hannes |
| \*before | 0 |
| \*after | 20 |

new element:

|  | 20 |
| ---- | ---- |
|  | Eva |
| \*before | 10 |
| \*after | 0 |


## Implementation

[[d_linked_list_global.c]]

### Actual struct
Needs pointer to its own data type 
	--> give _struct_ also a [[Structs#use model with typedef|name]]
```c
typedef struct m_students
{
	struct m_students *before;
	struct m_students *after;
	char name[20 + 1];
	int age;
	// more attributes

} students;
```

### Unnecessary struct to read input
Attributtes are _exactly_ the same as in `student` struct, except without the references
```c
struct 
{
	char name[20 + 1];
	int age;
	// more attributes
} input_student;

//only use global variables for now
students *start = 0;
students *current = 0;
students *temp = 0;
```

`temp` always points to _last_ element??????????

### Everything is highly modulized
#### main
```c
int main() 
{
	for (int i= 0; i< 4; i++) {
		printf("enter %d name: ", i + 1);
		scanf("%s", &input_student.name);
		fflush(stdin);
		
		// accept more input
		
		list_add(); // will later be reworked to only use local variables
	}
}
```

#### Add element
uses [[C concepts#malloc|malloc]] to reserve memory.
```c
void list_add() 
{
	current = (students *) malloc(sizeof(students));
	struct_to_list(); // copies content of input-struct to a list element
	
}
```

#### convert input to list
```c
void struct_to_list() 
{
	strcpy(current->name, input_student.name);
	current->age = input_student.age; // idfk if that works lol
	current->before = temp;
	current->after = 0; // last element always points to 0

	if(!temp) start = current;
	else temp->after = current;

	temp = current;
	
	
}
```


#### output of list data
```c
// gib mer mal alles was du hasch aus
void up_hex() 
{
	current = start;
	int i;
	while (current) 
	{
		printf("\nelement %-3d: %20s %10x %10x %10x",
			i,
			current->name, 
			current, 
			current->before, 
			current->after
		);
		current = current->after;
		i ++;
	}
}
```

e.g:
```
Hannes 10  0 20
Evi    20 10 30
Lisa   30 20 40
Bernd  40 30 0
```


Pattern:
- $output[i][2] == output[i + 1][0]$
- $output[0][1] == output[last][2] == 0$
==> if everything is like this: _you did good_



## Implementation with local variables
[[Doubly Linked List]]

