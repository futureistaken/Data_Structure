#test


.data
inputMsg: .asciiz "You entered the decimal numbers:\n"
SumD: .asciiz "\n\nThe sum in decimal is:\n"
Twos: .asciiz "\n\nThe sum in two’s complement binary is:\n"
newL: .asciiz  "\n"
BI: .asciiz "Please make sure arguments are in a currect range of [-64 , 63]"

space_char: .ascii " "


.text
#------------ FLAGS AND COUNTER ----------------#
li $t7 0 # flag for negative number 
li $t5 0 # flag for second negative number
li $t6 0 # first number counter 
li $t4 0 # second number counter 
#--------------------------------#


#####################
#### FIRST INPUT ####
#####################

#-------- initialization ---------#
li $t0 0
li $t1 0
li $t2 0
#--------------------------------#
load_first_number:
lw  $t0 ($a1)
loop1: nop
lb  $t1 ($t0)
beq $t1 45 negative1
beq $t1 0 Store_first_number
addi $t6 $t6 1
addi $t0 $t0 1
a_neg1:
bne $t1 0x00000000 loop1

Store_first_number: nop ##

#----- understanding the second input ---------#
beq $t6 2 two_char1 # check if the second number is 2 character
beq $t6 1 one_char1 # check if the second number is 2 character
#----------------------------------------------#


#----- 1 character ---------#
one_char1:nop
beq $t7 1 Store_Negative1_1 
lw $t0 ($a1)
lb $t1 ($t0) # load the first char
sub $t1 $t1 48 # first char
add $s1 $s1 $t1
j load_second_number

Store_Negative1_1:
lw $t0 ($a1)
lb $t1 1($t0) # load the first char
sub $t1 $t1 48 # first char
add $s1 $s1 $t1
#sub $s1 $zero $s1
j load_second_number
#----- 2 character ---------#
two_char1: nop
beq $t7 1 Store_Negative1_2 #check if the number is negative
lw $t0 ($a1)
lb $t1 ($t0) # load the first char
lb $t2 1($t0) # load the second char
sub $t1 $t1 48 # first char
sub $t2 $t2 48 # second char
mul $s1 $t1 10
add $s1 $s1 $t2
j load_second_number

Store_Negative1_2: nop
lw $t0 ($a1)
lb $t1 1($t0) # load the first char
lb $t2 2($t0) # load the second char
sub $t1 $t1 48 # first char
sub $t2 $t2 48 # second char
mul $s1 $t1 10
add $s1 $s1 $t2
j load_second_number

#####################
### SECOND INPUT ####
#####################
load_second_number: nop
#-------- initialization ---------#
li $t0 0
li $t1 0
li $t2 0
#--------------------------------#
lw  $t0 4($a1)

loop2: nop
lb  $t1 ($t0)
beq $t1 45 negative2
beq $t1 0 Store_second_number
addi $t4 $t4 1
addi $t0 $t0 1
a_neg2: nop
bne $t1 0x00000000 loop2

Store_second_number: nop
#----- understanding the second input ---------#
beq $t4 2 two_char2 # check if the second number is 2 character
beq $t4 1 one_char2 # check if the second number is 2 character
#----------------------------------------------#
#----- 1 character ---------#
one_char2: nop
beq $t5 1 Store_Negative2_1 #check if the number is negative
lw $t0 4($a1)
lb $t1 ($t0) # load the first char
sub $t1 $t1 48 # first char
add $s2 $s2 $t1
j Both_numbers_are_stored

Store_Negative2_1:
lw $t0 4($a1)
lb $t1 1($t0) # load the first char
sub $t1 $t1 48 # first char
add $s2 $s2 $t1
#sub $s2 $zero $s2
j Both_numbers_are_stored

#----- 2 character ---------#
two_char2:
beq $t5 1 Store_Negative2_2 #check if the number is negative
lw $t0 4($a1)
lb $t1 ($t0) # load the first char
lb $t2 1($t0) # load the second char
sub $t1 $t1 48 # first char
sub $t2 $t2 48 # second char
mul $s2 $t1 10
add $s2 $s2 $t2
j Both_numbers_are_stored

Store_Negative2_2: nop
lw $t0 4($a1)
lb $t1 1($t0) # load the first char
lb $t2 2($t0) # load the second char
sub $t1 $t1 48 # first char
sub $t2 $t2 48 # second char
mul $s2 $t1 10
add $s2 $s2 $t2
#sub $s2 $zero $s2
j Both_numbers_are_stored






###############################################################################
Both_numbers_are_stored: nop # Both_numbers_are_stored_as_A_positive_int

beq $t7 1 first_number_negative
beq $t5 1 second_number_negative
beq $t7 0 pos_num

# if first number if negative
first_number_negative: nop 

beq $t5 1 both_negative
bge $s1 64 outOfRange
mul $t1 $s1 -1
add $s0 $t1 $s2
j first_N_input

# if second number is negative
second_number_negative: nop 
bge $s2 64 outOfRange
mul $t2 $s2 -1
add $s0 $s1 $t2
j first_N_input

# if both numbers are negative
both_negative: nop
bge $s2 64 outOfRange  # Check if Negative numbers are in range
bge $s1 64 outOfRange  # Check if Negative numbers are in range
mul $t1 $s1 -1
mul $t2 $s2 -1
add $s0 $t1 $t2
j first_N_input

# Check if positive numbers are in range
pos_num: 
bge $s1 63 outOfRange
bge $s2 63 outOfRange

add $s0 $s1 $s2

first_N_input: nop
li $t1 0
li $t2 0

li $v0 4
la $a0 inputMsg # You entered the decimal numbers:
syscall
#----------- Converting to Ascii and Printing the first Number
#-------- initialization ---------#
li $t0 0
li $t1 0
li $t2 0
#--------------------------------#
beq $t6 2 n1_2ch
beq $t6 1 n1_1ch

# chech if a two digit number is stored with negative sign
n1_2ch:
beq $t7 1 firstN_neg2 

c2d_1:
div $t0 $s1 10  # first decimal #
rem $t1 $s1 10  # second decial #
addi $t0 $t0 48 # first int #
addi $t1 $t1 48 # second int #
li $v0 11
la $a0 ($t0)
syscall 
li $v0 11
la $a0 ($t1)
syscall
j space

firstN_neg2:
li $v0 11
la $a0 45
syscall
j c2d_1 # continue storing the first number with negative sign printed

n1_1ch:
beq $t7 1 firstN_neg1 # chech if a two digit number is stored with negative sign

c1d_n1:
addi $t0 $s1 48 # int for the 1 digit numbers
li $v0 11
la $a0 ($t0)
syscall
j space

firstN_neg1: # 
li $v0 11
la $a0 45
syscall
j c1d_n1



#----------------------------
space:
li $v0 4
la $a0 space_char # Space
syscall 
#----------------------------
#----------- Converting to Ascii and Printing the second Number
#-------- initialization ---------#
li $t0 0
li $t1 0
li $t2 0
#--------------------------------#
beq $t5 1 secondN_neg2 # chech if a two digit number is stored with negative sign
beq $t5 0 c2_pos

secondN_neg2:
li $v0 11
la $a0 45
syscall

c2_pos:
beq $t4 2 c2d_2
beq $t4 1 c1d_n2

c2d_2:
div $t0 $s2 10  # first decimal #
rem $t1 $s2 10  # second decial #
addi $t0 $t0 48 # first int #
addi $t1 $t1 48 # second int #
li $v0 11
la $a0 ($t0)
syscall 
li $v0 11
la $a0 ($t1)
syscall
j sumDec

c1d_n2:
addi $t0 $s2 48 # int for the 1 digit numbers
li $v0 11
la $a0 ($t0)
syscall
j sumDec
#----------------------------
#---- The sum in decimal ----
#----------------------------
sumDec:
li $v0 4
la $a0 SumD
syscall
#-------- initialization ----#
li $t0 0
li $t1 0x80000000
li $t2 0
#----------------------------#
and $t0 $s0 $t1
srl $t0 $t0 31 # find out if sum is negative

beq $t0 1 convert_to_pos
beq $t0 0 number_is_Pos 

convert_to_pos:nop # convert to positive and flag as negative!
li $v0 11
la $a0 45
syscall
mul $s0 $s0 -1
add $t2 $t2 100

number_is_Pos:nop
div $t0 $s0 10  # 1
beq $t0 0 S_1D
bge $t0 10 three_D_N
rem $t1 $s0 10  # 3
addi $t0 $t0 48 # 1
addi $t1 $t1 48 # 3
li $v0 11
la $a0 ($t0)
syscall 
li $v0 11
la $a0 ($t1)
syscall
beq $t2 100 conv_neg_back
j twos_C

conv_neg_back:
mul $s0 $s0 -1
j twos_C

three_D_N:
li $t0 0
div $t0 $s0 100 # 1
div $t1 $s0 10
rem $t1 $t1 10 #2
rem $t2 $s0 10 # 4
addi $t0 $t0 48 # 1
addi $t1 $t1 48 # 2
addi $t2 $t2 48 # 4
li $v0 11
la $a0 ($t0)
syscall 
li $v0 11
la $a0 ($t1)
syscall
li $v0 11
la $a0 ($t2)
syscall
beq $t2 100 conv_neg_back
j twos_C

S_1D:
addi $t0 $s0 48 # int for the 1 digit numbers
li $v0 11
la $a0 ($t0)
syscall
beq $t2 100 conv_neg_back
j twos_C

#----------------------------

#------The sum in Tow's Compliment

twos_C:
li $v0 4
la $a0 Twos
syscall
#-------- initialization ----#
li $t0 0 # Binary holder
li $t1 0x80000000 # mask
li $t2 0 # counter 
#----------------------------#
loop_bi: nop
and $t0 $s0 $t1
srl $t1 $t1 1 # moving the 1
beq $t0 0 Print_Zero
bge $t0 1 Print_one
Print_one:
li $v0 11
la $a0 49 
syscall
j Next_Bi
Print_Zero:
li $v0 11
la $a0 48 
syscall
Next_Bi: nop
add $t2 $t2 1 # counter increament
beq $t2 32 End
j loop_bi

###############################################################################
# flag if first number is negative
negative1: nop
addi $t0 $t0 1
addi $t7 $t7 1
j a_neg1

# flag if second number is negative
negative2: nop
addi $t0 $t0 1
addi $t5 $t5 1
j a_neg2

# Flag if number is not in range of [-64 , 63]
outOfRange:
li $v0 4
la $a0 BI
Syscall  

End:
# end of the program
li $v0 10 
syscall 
