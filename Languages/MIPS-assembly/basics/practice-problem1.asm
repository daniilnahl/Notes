#Program that repeatedly reads in integers and adds them into a running sum. Exits when user enters 0.

.text
.globl main
main:
	jal read_integer	#links the function output to $v0
	add $t1, $v0, $zero
	beq $t1, $zero, exit	#go to system exit if input is 0
	add $s0, $s0, $t1 	#$s0 is the sum register
	
	j main
	
exit:
	move $a0, $s0	#copy values of $s0 to $a0
	li $v0, 1	#load syscall for printing integer
	syscall
	li $v0, 10
	syscall

read_integer:
	li $v0, 5	#load syscall code 5 for reading integer into $v0
	syscall
	jr $ra
	
