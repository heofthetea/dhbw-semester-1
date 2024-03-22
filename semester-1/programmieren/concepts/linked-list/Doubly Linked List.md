[[d_linked_list_local.c]]

- Consists of individual [[Node|Nodes]], linked to each other
- The _List_ itself is instance of a _struct_, storing [[Head]], [[Tail]] and length of the list, as well as (optional) a [[Node]] `current`, in case observation to a specific Node in the list is needed when passing the list.
### 1. make typedef out of reading struct
Also move important pointers _into_ this struct
```c
typedef struct 
{
	char name[20 + 1];
	int age;
	// more attributes
	students *start;
	students *current;
	students *temp;
	
} input_student;

```

#### main
```c
int main() 
{
	input_student input;
	input_student *in = &input;


	in->start = 0;
	in->current = 0;
	in->temp = 0;
	
	for (int i= 0; i< 4; i++) {
		printf("enter %d name: ", i + 1);
		scanf("%s", in->name);
		fflush(stdin);
		
		// accept more input
		
		list_add(input); // pass input struct
	}
}
```

#### Convert input to list
```c
void struct_to_list(input_student *input) 
{
	strcpy(input->current->name, input->name);
	input->current->age = input_student.age; // idfk if that works lol
	input->current->before = temp;
	input->current->after = 0; // last element always points to 0

	if(!temp) input->start = input->current;
	else temp->after = input->current;

	input->temp = input->urrent;
}
```

#### Add element as parameter
```c
void list_add(input_student *input) 
{
	input->current = (students *) malloc(sizeof(students));
	struct_to_list(); // copies content of input-struct to a list element
}
```


#### Output node attributes
```c
// gib mer mal alles was du hasch aus
void up_hex(input_student *input) 
{
	input->current = input->start;
	int i;
	while (input->current) 
	{
		printf("\nelement %-3d: %20s %10x %10x %10x",
			i,
			input->current->name, 
			input->current, 
			input->current->before, 
			input->current->after
		);
		input->current = input->current->after;
		i ++;
	}
}
```

#### Delete Node
![[Delete Node]]