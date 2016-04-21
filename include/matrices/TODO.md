## Things to be done/changed

#### Minimal
1. Add density ranking

#### Low
1. Added square checking for matrix types that should be square  
Have output be something along the lines of
```cpp
std::cerr << "Warning: Forcing square dimensions for [MATRIX_FORM]!\n";
```
#### High
1. Everything with Dense matrix multiplication implementation must
be fixed. Currently change N() to M()!! (Tridiag, Dense)


### Dense
#### Low
1. Find additional optimizations
2. Add template specializations

### Diagonal
#### Low
1. Find additional places to optimize performance.
* Template specializations for math ops. with different forms.

### TriDiagonal
#### Low
1. Set the default -, + operators to be operable on TriDiagonal matrices.  
 * Make template specializations for -, +, \*, etc.
* Optimize \* for Vectors and Matrix (currently a copy of dense multiplication).


#### Medium
1. Typetraits
 * isTriDiag([type])

### Upper  
#### Medium
1. Optimizations for Upper


### Lower
#### Medium
1. Optimizations for Lower

### Symmetric
#### High
1. **Implementation**
