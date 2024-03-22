## Own Header File
include with _""_
`include "ownheader.h"`.
- all needed includes
- all prototypes
- all structs
- all defines

### Global Variables
- global variables can only exist _once_ in the entire project - don't have the same variable in different files
#### Keyword extern
`extern int var;` 
- This variable has been initialized in _another file_