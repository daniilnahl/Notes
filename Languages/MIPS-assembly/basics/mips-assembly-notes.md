# MIPS 101
| mips registers | purpose |
|---|---|
|$t0-$t9   | temp registers for general use |
| $s0-$s7 | saved registers for data preserv. across functions |
| $a0-$a3 | argument regs for function parameters |
| $v0-$v1 | return val regs |

### VERY IMPORTANT IN MIPS (DIRECTIVES)
MIPS code almost always starts with these **directives**:
- **.data**: data segment, tells assembler that everything below it belongs in the data segment of memory. *Where you declare variables, constants, arrays, strings*.
- **.text**: text/code segment, tells assembler to start translating all the pseudo instruction into real instructions.
- **.globl**: global label, makes a *label* accesible to other files (like exporting in other programming).
- **.asciiz "[text]"**: tells assembler to store a string in memory and auto. append a null terminator. 
- **.word [var_name1],[var_name2]...**: tells assembler to allocate 4 bytes of space for each var/arr. 
- **.space n**: reserves n bytes of uninitialized memory. Used for buffers or large arrays where you don't know the values yet.
- **.align n**: aligns next data item on a boundary of 2^n bytes. Usually used to ensure integers are word-aligned.
- **.byte n**: allocates 1 byte of space for an 8-bit value. 


### How to make functions in MIPS?
**IMPORTANT: FUNCTIONS ARE NOT LABELS**, but all functions use labels. The difference is:
```
### Function
main:
    jal label
    
label:
    [code]
    jr $ra  #jump register, returns to the caller

### Label
main:
    j label

label:
    [code]  #whatever code is below this is proceeded to be executed
```

### How to print strings in MIPS?
```
.data
msg: .asciiz "Hello, MIPS!\n"
.text
.globl main
main:
    li $v0, 4   #system call for printing a string
    la $a0, msg #loads the addr of string into $a0
    syscall 
    li $v0, 10 #exit system call
    syscall
```
