## Code
[[segmented_sieve.c]]

### Runtime
**Time Complexity:** $O(n\;log(n))$ 
**Space Complexity:** $O(\sqrt{n})$

**Timed** (average-case):
	as _linux executable_: ~225 ms
	as _windows executable_ under `wine`: ~260 ms

### Comparison
This compares the _average case_ approximate runtime of the following entities:
- Segmented Sieve (with hardcoded values): [[segmented_sieve_hardcoded.c]]
- Segmented Sieve: [[segmented_sieve.c]]
	- under `wine`: Compiled to `exe`, then ran via the wine linux library. This serves to better compare the Benchmark, which is provided as a windows executable.
- Benchmark: https://elearning.dhbw-stuttgart.de/moodle/pluginfile.php/660507/mod_folder/content/0/PrimDynC.exe?forcedownload=1 --> [[PrimDynC.exe]]
	- This is the program that also allows for User Input. _PrimOpt2_, which does not do so, is faster, but is hardcoded to 10⁸.
#### 10⁸
|  | Segmented Sieve (with hardcoded values) | Segmented Sieve | Segmented Sieve (under `wine`) | Benchmark (under `wine`) | Benchmark (with hardcoded values) |
| ---- | ---- | ---- | ---- | ---- | ---- |
| battery power | 230 ms | 280 ms | 340 ms | 850 ms | 700 ms |
| performance mode | 225 ms | ?? ms | ?? ms | ?? ms | 340 ms |

--> As _space complexity_ is optimized, Segmented Sieve runs basically equally fast regardless of available resources
--> `wine` emulator adds 20% of runtime

#### 10⁹
|  | Segmented Sieve (with hardcoded values) | Segmented Sieve | Segmented Sieve (under `wine`) | Benchmark (under `wine`) |
| ---- | ---- | ---- | ---- | ---- |
| battery power | 2450 ms | 2900 ms | 3300 ms | 6900 ms |
#### 10¹⁰
Sadly, under `wine`, both programs don't run properly anymore, as theyre lacking storage space. This is a shame.

The regular [[segmented_sieve.c]], on my machine, needs ~35 seconds.


## Documentation
> since I need `stlib` for this and it redefines `timeval` from `linux/time.h`, I'm not working with the provided Nimmzeit module, instead using `clock()` to measure the time. A giant Fuck You to hoever wrote that stupid module.
> 
> Futhermore, since the evaluation happens _inside_ the sieving, it cannot be timed seperately. Of course one could time _each_ individual sub-evaluation, however that slows the program down by ~50 ms, which is about 20% of total runtime and thus not feasible.

### Storage of Sieving primes

#### Structure list_uint64
Roughly emulates a _list_ in python. 
```c
typedef struct
{
    uint64_t *data;
    uint64_t max_size;
    uint64_t length;
} list_uint64;

```
##### Attributes
-  _data_ -> Pointer to where the _actual data_ of the list lies. This can be used synonimously with an array using bracket syntax: `list.data[index]`.
- _max_size_ -> How much _memory_ has been allocated. Is used when creating the `multiples` list, to keep its size in sync with the `primes` list.
- _length_ -> equivalent to the return value of `len(list)` in python. Stores how many elements the list currently holds. Can be used to iterate over only the parts of the list that actually store values.

#### Initialization with default values
_Parameter_ size: The maximum size the List should be.
_Return value_: The newly created list. Since structs don't need explicit pointers to be passed around, the list instance can simply be returned.
```c
// creates a new list filled with default values
list_uint64 new_list(uint64_t size)
{
    list_uint64 list = {
        malloc(size * sizeof(uint64_t)),
        size,
        0 
    };

    return list;
}
```
- _data_: Manually allocates $size * sizeof(uint64\_t)$ of memory. This way there can be _size_ Elements of the type _uint64_t_ stored in the list.
- _max_length_: This is initialized to the given _size_ of the wanted list.
- _length_: Trivial - As there are no initial elements in the list, its size should be 0.
#### Appending
```c
// appends an item to given list. List is passed as reference.
void list_append(list_uint64 *list, uint64_t value) {
    list->data[list->length++] = value;
}
```

This is more or less a very fancy _array syntax_. It first accesses the data list via pointer operations (`list->data`), then stores the value at the end (`list->length`) and then increases the length attribute by one.


### Setup
1) create `is_prime` array to later run a regular sieve on
2) fill this array with one's --> leave indexes for 0 and 1 out, because those aren't primes
3) run a regular [[Sieve of Erathostenes#C implementation]] on the `is_prime` array
	--> places all indexes of primes until $\sqrt{n}$ with 1, else 0
	--> using `is_prime[index]` will return whether *index* is _prime_
4) create a `list_uint64` instance to later store the sieving primes in
	- The size of the array is approximated: [[#Approximation of Primes]]
```c
bool is_prime[(size_t)sqrt(upper_limit)];
memset(is_prime + 2, true, sizeof(is_prime) - 2);
sieve(is_prime, sizeof(is_prime));

list_uint64 primes = new_list(PRIMES_UNTIL_SQRT);
```

#### Approximation of Primes
> The [prime number theorem](https://en.wikipedia.org/wiki/Prime_number_theorem) suggests that $\lim_{x\to\infty}x\ log_{10}(x) = \pi(x)$ 

Since $x\ log(x)$ generally falls short of the actual number of primes, however we want to rather _overshoot_ than _underestimate_, The result has to be increased by some amount.

Let $A_{x} = \frac{\pi(x)}{x\log_{10}(x)}$

| x | $\pi(x)$ | $A_{x}$ |
| ---- | ---- | ---- |
| 10 | 4 | 0.921 |
| 10² | 25 | 1.151 |
| 10³ | 168 | 1.161 |
| 10⁴ | 1229 | 1.132 |
| 10⁵ | 9592 | 1.104 |
| 10⁶ | 78498 | 1.084 |
| 10⁷ | 664579 | 1.071 |
| 10⁸ | 5761455 | 1.061 |
| 10⁹ | 50847534 | 1.054 |
| 10¹⁰ | 455052511 | 1.048 |

In this table can be seen, that $\forall_{x} A_{x} \leq 1.152$. So, to get a number a bit larger than the actual number of primes until a parameter _n_, this code can be used:

```c
int n;
(n / (uint64_t)log10(n)) * 1.152
```

### Algorithm
#### 1. Initialization of relevant variables
##### Scope of function
> Variables that will be used over and over again and incremented in each segment
```c
uint64_t low, high;
uint64_t num_primes = 1; 
uint64_t sieving_prime_candidate = 3; 
uint64_t prime_counter = 3;
list_uint64 multiples = new_list(sieving_primes.max_size);

bool segment[segment_size];
```
- _low, high_: control boundaries of each segment
- _num_primes_: serves as counter for the total number of primes
	- each segment adds the number of primes it contains to this variable
	- variable is initialized to _1_ because the entire code ignores multiples of 2
- _sieving_prime_candidate_: bit of a chunky name, but tells exactly what the variable is for
	- value will increase with each segment
	- this variable will get checked against `is_prime` to see if its value is prime
- _prime_counter_: used at the end of each segment to iterate through the `segment` array to find all primes
	- not to be confused with _num_primes_
- _multiples_: stores the first multiple of a prime that is _outside_ the current segment, so the next segment will know where to start eliminating for the prime
	- since there is exactly _one_ "next multiple" for every sieving prime, the lists have the same size, and `multiples.data[i]` will always correspond to `sieving_primes.data[i]`
- _segment_: the good old essential Sieve of Eratosthenes array for a given segment.
	- will be reused for different segments
		--> data of one segment _does not persist_
	- attention: since the entire program _ignores even numbers_, every even index will also be marked as _true_, just not evaluated.
##### Scope of outer loop
> Sets environment for the current segment.
```c
for (low = 0; low <= upper_limit; low += segment_size)
    {
        memset(segment, true, sizeof(segment));
        high = low + segment_size - 1; 
        if (high > upper_limit)
            high = upper_limit;
```
- Loop condition is trivial
- sets _every_ element of the `segment` array to _true_
- high is either set to _one less_ than the low of the next segment or the upper limit (trivial)
#### 2. Filtering of Sieving Primes
> _Sieving Prime_: A prime $p$ that is used to cross of multiples $a*p$ within a segment $[l, n]$. Sieving Primes only need to be smaller than $\sqrt{n}$.

```c
for (; sieving_prime_canidate * sieving_prime_canidate <= high; sieving_prime_canidate += 2)
{
	if (is_prime[sieving_prime_canidate])
	{
		list_append(&sieving_primes, sieving_prime_canidate);  
		list_append(
			&multiples, 
			(sieving_prime_canidate * sieving_prime_canidate) - low
		); 
	}
}
```
- sieving prime candidates always get increased by 2
	--> since `sieving_prime_candidate` is initialized to 3, this ignores _all even numbers_
- If a candidate is in fact a prime, it is appended to the _list_ `sieving_primes`
	- also, a corresponding entry is appended to the `multiples` list to be able to be used _later on_
	- The default value for the new `multiples` entry can be derived from the common standard sieve optimization, to start eliminating from $p*p$ instead of $p$
#### 3. Eliminating multiples
```c
for (uint64_t i = 0; i < sieving_primes.length; i++)
{
	uint64_t j = multiples.data[i];
	for (; j < segment_size; j += sieving_primes.data[i] * 2)
	{
		segment[j] = false;
	}
	multiples.data[i] = j - segment_size;
}
```
- Iterator variable $j$ is assigned the corresponding `multiples` entry
	--> if the sieving prime $p$ has been used in the segment before, this will be the first multiple of $p$ in the current segment
- Since all even indexes get ignored, we can only check every _other_ multiple of $p$
	-   $2 \not\mid p \rightarrow 2\not\mid (2a+1)p \land 2 \mid 2a*p$, therefore $2a*p \not\in \mathbb{P}$
- Finally, the `multiples` entry is updated to store the _next_ multiple, that doesn't lie in the current segment
	- this usage of $j$ is why $j$ needed to be declared _before_ the for loop

#### 4. Evaluation 
> Since data of an individual segment doesn't persist, the evaluation needs to take place inside of a segment.
```c
for (; prime_counter <= high; prime_counter += 2)
{
	if (segment[prime_counter - low])
	{
		num_primes++;
	}
}
```
- Works the same way as the evaluation of a regular Sieve of Eratosthenes.

---

## Idea
![[Segmented Sieve]]

### Reference
[[segmented_sieve_stolen.c]]
explanation of algorithm: https://github.com/kimwalisch/primesieve/wiki/Segmented-sieve-of-Eratosthenes