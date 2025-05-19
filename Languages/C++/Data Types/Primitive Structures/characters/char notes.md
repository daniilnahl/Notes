# Useful Commands for C-Style Strings

- `strlen(p)`  
  Returns the length of `p`, not counting the null terminator.

- `strcmp(p1, p2)`  
  Compares `p1` and `p2` for equality. Returns:  
  - `0` if `p1 == p2`  
  - A positive value if `p1 > p2`  
  - A negative value if `p1 < p2`

- `strcat(p1, p2)`  
  Appends `p2` to `p1`. Returns `p1`.

- `strcpy(p1, p2)`  
  Copies `p2` into `p1`. Returns `p1`.
