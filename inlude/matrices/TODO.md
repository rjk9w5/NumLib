## Things to be done/changed

#### Priority Minimal
1. Add density ranking


### Dense
#### Priority Low
1. Find additional optimizations
2. Add template specializations

### Diagonal
#### Priority Low
1. Find additional places to optimize performance.
* Template specializations for math ops. with different forms.

### TriDiagonal
#### Priority Low
1. Set the default -, + operators to be operable on TriDiagonal matrices.  
 * Make template specializations for -, +, \*, etc.
* Optimize \* for Vectors and Matrix (currently a copy of dense multiplication).  

#### Priority Medium
1. Typetraits
 * isTriDiag([type])

### Upper  
#### High Priority
1. Implementation


### Lower
#### High Priority
1. Implementation

### Symmetric
#### High Priority
1. Implementation
