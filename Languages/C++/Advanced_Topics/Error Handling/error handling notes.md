# Exceptions

An exception is a runtime error that exists outside the normal functioning of a program.

## What's in `<stdexcept>`  
- `exception`  
  The most general kind of problem. Provides no additional information.  
- `runtime_error`  
  Problem that can be detected only at run time.  
- `range_error`  
  Run-time error: result generated outside the range of values that are meaningful.  
- `overflow_error`  
  Run-time error: computation that overflowed.  
- `underflow_error`  
  Run-time error: computation that underflowed.  
- `logic_error`  
  Error in the logic of the program.  
- `domain_error`  
  Logic error: argument for which no result exists.  
- `invalid_argument`  
  Logic error: inappropriate argument.  
- `length_error`  
  Logic error: attempt to create an object larger than the maximum size for that type.  
- `out_of_range`  
  Logic error: used a value outside the valid range.  
