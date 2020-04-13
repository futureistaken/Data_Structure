.data
lable0: .asciiz "\n"
lable1: .ascii "I <3"
lable2: .ascii "CE12"
labe3: .byte 0x20 0x21 0x21 0x00 0x41

.text
li $v0 4
la $a0 lable1
syscall

la $a0 lable0
syscall

li $v0 34
la $a0 lable0
syscall

li $v0 4
la $a0 lable0
syscall

li $v0 11
la $t0 lable2
lb $a0 0($t0)
syscall 
lb $a0 1($t0)
syscall
syscall 
