.data

notEqual: .asciiz " NOT EQUAL "
Equal: .asciiz " both input's are equal"
text: .asciiz "babak\n"

input: .space 53
inputSize: .word 52



.text
# string by string 

# + - 32 for the comparison whith no case sensitivity

# char by char test
li $v0, 8
la $a0  input
lw $a1  inputSize
syscall
la $t0 input
la $t1 text
#jal punch_killer # removes all the punchuation from the string
loop: nop
beq $t2 10 input_done
lb $t2 ($t0)
lb $t3 ($t1)
addi $t0 $t0 1
addi $t1 $t1 1
beq $t2 $t3 loop
bne $t2 $t3 not_equal

input_done:
beq $t3 10 equal
equal:
li $v0 4
la $a0 Equal
syscall
j Done
not_equal:
li $v0 4
la $a0 notEqual
syscall


Done:
li $v0 10
syscall




