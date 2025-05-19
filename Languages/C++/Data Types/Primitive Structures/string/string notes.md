# Strings in C++

## 1. What is a String in C++?  
A string is a sequence of characters.

---

## 2. String Operations  
- `os << s`  
  Writes `s` onto output stream `os`. Returns `os`.  
- `is >> s`  
  Reads a whitespace-separated string from `is` into `s`. Returns `is`.  
- `getline(is, s)`  
  Reads a line of input from `is` into `s`. Returns `is`.  
- `s.empty()`  
  Returns `true` if `s` is empty; otherwise returns `false`.  
- `s.size()`  
  Returns the number of characters in `s`.  
- `s[n]`  
  Returns a reference to the char at position `n` in `s`; positions start at 0.  
- `s1 + s2`  
  Returns a string that is the concatenation of `s1` and `s2`.  
- `s1 = s2`  
  Replaces characters in `s1` with a copy of `s2`.  
- `s1 == s2`, `s1 != s2`  
  Strings are equal if they contain the same characters. Equality is case-sensitive.  
- `<, <=, >, >=`  
  Comparisons are case-sensitive and use dictionary ordering.

---

## 3. Helpful Built-in Character Functions  
- `isalnum(c)`  
  True if `c` is a letter or a digit.  
- `isalpha(c)`  
  True if `c` is a letter.  
- `iscntrl(c)`  
  True if `c` is a control character.  
- `isdigit(c)`  
  True if `c` is a digit.  
- `isgraph(c)`  
  True if `c` is not a space but is printable.  
- `islower(c)`  
  True if `c` is a lowercase letter.  
- `isprint(c)`  
  True if `c` is a printable character (space or visible representation).  
- `ispunct(c)`  
  True if `c` is a punctuation character (not control, digit, letter, or printable whitespace).  
- `isspace(c)`  
  True if `c` is whitespace (space, tab, vertical tab, return, newline, or formfeed).  
- `isupper(c)`  
  True if `c` is an uppercase letter.  
- `isxdigit(c)`  
  True if `c` is a hexadecimal digit.  
- `tolower(c)`  
  If `c` is uppercase, returns its lowercase equivalent; otherwise returns `c` unchanged.  
- `toupper(c)`  
  If `c` is lowercase, returns its uppercase equivalent; otherwise returns `c` unchanged.  
