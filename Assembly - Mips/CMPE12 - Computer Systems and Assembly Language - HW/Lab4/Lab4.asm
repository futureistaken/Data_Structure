# Created by: Farahmand, Babak
# Bfarahma
# 18 Nov 2018
#
# Assignment: Lab 4: ASCII Decimal to 2SC
# CMPE 012, Computer Systems and Assembly Language
# UC Santa Cruz, Fall 2018
#
# Description: This program prints:
#1- Prints the inputted number
#2- The Sum of the Decimals	
#3- The sum in two’s complement binary 
#4- The Sum in the morse code
#
# Notes: This program is intended to be run from the MARS IDE.
####################################################################################

#--------------------------------------Pesudo Code--------------------------------------#
#-------------------------Functions
#Function toBinary(HexCode) -- Convert the Hex code into Binary // it's an easy steps, need to use switch case to match each hex entries and create a binary equivalent. which is done by jump and loop here.
#Function add(s1, s2) -- add these two numbers to Two's complement add them together and print the output
#Function isItInRange(s1, s2) -- check it the insterted number is in the range of [-64, 63]
#Function ConvertToDecimal (s1, s2) -- Conver s1 and s2 to Decimal add them together and print the output
#Function morseTable(s0) -- Print the result of the ConvertToDecimal in morsecode
#-------------------------
#-------------------------Program
#Fist number: s1
#Second number: s2



#isItInRange(s1, s2) ?  Continue : Breake' // check it the insterted number is in the range of [-64, 63] 



#t1 = toBinary(S1); // store the s1 binary value into a temprory variable t1
#t2 = toBinary(S2);// store the s2 binary value into a temprory variable t2
#------------------------- toBinary condtions
 #while (HexCode[i])
    #{
     #   switch (hexa[i])
     #  {
     #   case '0':
     #      printf("0000"); break;
     #  case '1':
     #     printf("0001"); break;
     # case '2':
     #     printf("0010"); break;
     # case '3':
     #     printf("0011"); break;
     #case '4':
     #    printf("0100"); break;
     # case '5':
     #     printf("0101"); break;
     # case '6':
     #      printf("0110"); break;
     #  case '7':
     #      printf("0111"); break;
     #  case '8':
     #      printf("1000"); break;
     #  case '9':
     #       printf("1001"); break;
     #  case 'A':
     #      printf("1010"); break;
     #  case 'B':
     #      printf("1011"); break;
     #  case 'C':
     #      printf("1100"); break;
     #  case 'D':
     #      printf("1101"); break;
     #  case 'E':
     #     printf("1110"); break;
     #case 'F':
     #  printf("1111"); break;
     # case 'a':
     #    printf("1010"); break;
     #case 'b':
     #     printf("1011"); break;
     #case 'c':
     #     printf("1100"); break;
     #case 'd':
     #   printf("1101"); break;
     #case 'e':
     #   printf("1110"); break;
     #case 'f':
     #   printf("1111"); break;
     #default:
     #   printf("\n Invalid hexCode digit %c ", HexCode[i]);
     #  return 0;
     #}
     #i++;
#Then t0 = t1 + t2;
#print t0 // it's the sum of the two's compliment in Binary



#ConvertToDecimal (s1, s2)
# s0 = s1 + s2
#Print s0 // it's the sum of the numbers in decimal
#Function morseTable(s0) // using morse codes to recode s1, s2 in morse.
#There are a lot of conditions that have to check.



#------------------------- Morse code conditions

#if s0 > 9 the morse code pattern is like " . - - - -  . - - - - " = 10 in morse code
#if s0 < 9 && s0 > -1 then the morse code pattern is lie " . - - - - "
#if s0 < 0 && s0 > -10 then the morse code pattern initiate with " - . . . . -  . - - - - "
#if s0 < -10 then the morse code pattern is "- . . . . -  . - - - -  . - - - - "


.data
# Morse Code Dictionary --------------------
zero: .asciiz "----- "
one: .asciiz ".---- "
two: .asciiz "..--- "
three: .asciiz "...-- "
four: .asciiz "....- "
five: .asciiz "..... "
six: .asciiz "-...."
seven: .asciiz "--..."
eight: .asciiz "---.."
nine: .asciiz "----. "
negative_Morse: .asciiz "-....- "
#-------------------------------------------

inputMsg: .asciiz "You entered the decimal numbers:\n"
SumD: .asciiz "\n\nThe sum in decimal is:\n"
Twos: .asciiz "\n\nThe sum in two’s complement binary is:\n"
Morse_Msg: .asciiz "\n\nThe sum in Morse code is:\n"
newL: .asciiz  "\n"
BI: .asciiz "Please make sure arguments are in a currect range of [-64 , 63]"
space_char: .ascii " "


.text
# FLAGS AND COUNTERS-------------#
li $t7 0                         # flag for negative number 
li $t5 0                         # flag for second negative number
li $t6 0                         # first number counter 
li $t4 0                         # second number counter 
#--------------------------------#


#####################
#### FIRST INPUT ####
#####################

#-------- initialization --------#
li $t0 0                         # point to the andress if the arguments
li $t1 0                         # first character from the first argument 
li $t2 0                         # seco character from the first argument
#--------------------------------#

# First argument counter inizilizatiion ---------
# It louds each argument and increase the count of the counter ($t6)
load_first_number:
lw  $t0 ($a1)
loop1: nop
lb  $t1 ($t0)
beq $t1 45 negative1             # check if the first chatacter is negative so i woun't increase the count
beq $t1 0 Store_first_number     # it check to see if all characters are being loaded from the number
addi $t6 $t6 1                   # increaces the first number counter by one each time it sees a number
addi $t0 $t0 1                   # increases the ofset of the character by one 
a_neg1:
bne $t1 0x00000000 loop1

Store_first_number: nop          # after counting the number of digits in the first argument it stores it into the S1

#----- understanding the second input ---------#
beq $t6 2 two_char1              # check if the first number is built by 2 digit number ex: 25
beq $t6 1 one_char1              # check if the first number is built by 1 digit number ex: 2
#----------------------------------------------#


# if the first arugment was 1 digit number -------------------#
one_char1:nop
beq $t7 1 Store_Negative1_1      # check to see if the first argyment is negative
lw $t0 ($a1)                     # point to the andress if the arguments
lb $t1 ($t0)                     # load the first char
sub $t1 $t1 48                   # converting the first char to integer
add $s1 $s1 $t1                  # initializing the S1 with the first integer 
j load_second_number

Store_Negative1_1:               # the number is negative!
lw $t0 ($a1)                     # point to the andress if the arguments
lb $t1 1($t0)                    # load the first char
sub $t1 $t1 48                   # converting the first char to integer
add $s1 $s1 $t1                  # initializing the S1 with the first integer 
j load_second_number             #Done with the first number!



# if the first arugment was 2 digit number -------------------#
two_char1: nop
beq $t7 1 Store_Negative1_2 # check to see if the first argyment is negative
lw $t0 ($a1)                     # point to the andress if the arguments
lb $t1 ($t0)                     # load the first char
lb $t2 1($t0)                    # load the second char
sub $t1 $t1 48                   # converting the first char to integer
sub $t2 $t2 48                   # converting the second char to integer
mul $s1 $t1 10                   # multiplying $t1 to 10 to make sure $t1 is the most significant digit
add $s1 $s1 $t2                  # initializing the S1 with the first number 
j load_second_number

Store_Negative1_2: nop # the number is negative!
lw $t0 ($a1)                     # point to the andress if the arguments
lb $t1 1($t0)                    # load the first char
lb $t2 2($t0)                    # load the second char
sub $t1 $t1 48                   # converting the first char to integer
sub $t2 $t2 48                   # converting the second char to integer
mul $s1 $t1 10                   # multiplying $t1 to 10 to make sure $t1 is the most significant digit
add $s1 $s1 $t2                  # initializing the S1 with the first number 
j load_second_number             # Done with the first number!

#####################
### SECOND INPUT ####
#####################
# Second argument counter inizilizatiion ---------
# It louds each argument and increase the count of the counter ($t4)
load_second_number: nop # 
#-------- initialization --------#
li $t0 0                         # point to the andress if the arguments
li $t1 0                         # first character from the first argument 
li $t2 0                         # seco character from the first argument
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

Store_second_number: nop # Stores the second number just like the first numbert, all the registers do the same.
#----- understanding the second input ---------#
beq $t4 2 two_char2 # check if the second number is built by 2 digit number ex: 25
beq $t4 1 one_char2 # check if the second number is built by 1 digit number ex: 2
#----------------------------------------------#

# if the second arugment was 1 digit number -------------------#
one_char2: nop
beq $t5 1 Store_Negative2_1      # check if the number is negative
lw $t0 4($a1)
lb $t1 ($t0)                     # load the first char
sub $t1 $t1 48                   # first char
add $s2 $s2 $t1
j Both_numbers_are_stored

Store_Negative2_1:
lw $t0 4($a1)
lb $t1 1($t0)                    # load the first char
sub $t1 $t1 48                   # first char
add $s2 $s2 $t1
j Both_numbers_are_stored

# if the second arugment was 2 digit number -------------------#
two_char2:
beq $t5 1 Store_Negative2_2      #check if the number is negative
lw $t0 4($a1)
lb $t1 ($t0)                     # load the first char
lb $t2 1($t0)                    # load the second char
sub $t1 $t1 48                   # first char
sub $t2 $t2 48                   # second char
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
j Both_numbers_are_stored
###############################################################################

Both_numbers_are_stored: nop 

beq $t7 1 first_number_negative  # if the first number is negative make it positive
beq $t5 1 second_number_negative # if the second number is negative make it positive 
beq $t7 0 pos_num                # if Both_numbers_are_stored_as_A_positive_int


first_number_negative: nop       # if first number if negative
beq $t5 1 both_negative
bge $s1 65 outOfRange
mul $t1 $s1 -1
add $s0 $t1 $s2
j first_N_input


second_number_negative: nop      # if second number is negative
bge $s2 65 outOfRange
mul $t2 $s2 -1
add $s0 $s1 $t2
j first_N_input


both_negative: nop               # if both numbers are negative
bge $s2 65 outOfRange            # Check if Negative numbers are in range
bge $s1 65 outOfRange            # Check if Negative numbers are in range
mul $t1 $s1 -1
mul $t2 $s2 -1
add $s0 $t1 $t2
j first_N_input


pos_num: 
bge $s1 64 outOfRange            # Check if positive numbers are in range
bge $s2 64 outOfRange            # Check if positive numbers are in range

add $s0 $s1 $s2

first_N_input: nop
li $v0 4
la $a0 inputMsg                  # You entered the decimal numbers:
syscall
# Converting to Ascii and Printing the first Number
#-------- initialization --------#
li $t0 0                         # to store the first decimal 
li $t1 0                         # to store the second decial 
#--------------------------------#
beq $t6 2 n1_2ch # if the number has 2 digit
beq $t6 1 n1_1ch # if the number has 1 digit

# chech if a two digit number is stored with negative sign
n1_2ch:
beq $t7 1 firstN_neg2 

c2d_1:
div $t0 $s1 10                   # first decimal 
rem $t1 $s1 10                   # second decial 
addi $t0 $t0 48                  # store the ascii of the first number into $t0
addi $t1 $t1 48                  # store the ascii of the first number into $t1
li $v0 11                        # prints the first ascii character
la $a0 ($t0)
syscall 
li $v0 11                        # prints the second ascii charater 
la $a0 ($t1)
syscall
j space

firstN_neg2:
li $v0 11
la $a0 45
syscall
j c2d_1                          # continue storing the first number with negative sign printed

n1_1ch:
beq $t7 1 firstN_neg1            # chech if a two digit number is stored with negative sign

c1d_n1:
addi $t0 $s1 48                  # int for the 1 digit numbers
li $v0 11
la $a0 ($t0)
syscall
j space

firstN_neg1:                     # prints the negative sign
li $v0 11
la $a0 45
syscall
j c1d_n1
#----------------------------
space:
li $v0 4
la $a0 space_char                # Printing the Space character
syscall 
#----------------------------
# Converting to Ascii and Printing the second Number
#-------- initialization --------#
li $t0 0                         # to store the first decimal 
li $t1 0                         # to store the second decial 
#--------------------------------#
beq $t5 1 secondN_neg2           # chech if a two digit number is stored with negative sign
beq $t5 0 c2_pos

secondN_neg2:                    # printing the negative sign
li $v0 11
la $a0 45
syscall

c2_pos:
beq $t4 2 c2d_2
beq $t4 1 c1d_n2

c2d_2:
div $t0 $s2 10                   # first decimal 
rem $t1 $s2 10                   # second decial 
addi $t0 $t0 48                  # first int 
addi $t1 $t1 48                  # second int 
li $v0 11
la $a0 ($t0)
syscall 
li $v0 11
la $a0 ($t1)
syscall
j sumDec

c1d_n2:
addi $t0 $s2 48                  # converting to ascii to print out the 1 digit
li $v0 11
la $a0 ($t0)
syscall
j sumDec

#----------------------------
#---- The sum in decimal ----
#----------------------------
sumDec:                          # this subroutin prints the sum of the decimal
li $v0 4
la $a0 SumD
syscall
#-------- initialization --------#
li $t0 0                         # holds Mask result / will holds the first number after masking
li $t1 0x80000000                # Mask
li $t2 0                         # holds the reminder
li $t3 0                         # negaitve Flag for the sum
#--------------------------------#
and $t0 $s0 $t1                  # Masking 
srl $t0 $t0 31                   # find out if sum is negative

beq $t0 1 convert_to_pos         # the sum is negative converting to positive for the print
beq $t0 0 number_is_Pos 

convert_to_pos:nop               # convert to positive and flag as negative!
li $v0 11
la $a0 45
syscall
mul $s0 $s0 -1                   # converting to positive for the print
add $t3 $t3 100                  # Flag as negative

number_is_Pos:nop
div $t0 $s0 10                   # calculate the most significant digit
beq $t0 0 S_1D                   # if dividing the MSB by 10 was 0 the number is less than 10 so it's one digit
bge $t0 10 three_D_N
rem $t1 $s0 10                   # reminder of the S0 (sum)
addi $t0 $t0 48                  # convert the first digit to ascii to make it prinable by syscall 11
addi $t1 $t1 48                  # convert the first digit to ascii to make it prinable by syscall 11
li $v0 11
la $a0 ($t0)
syscall 
li $v0 11
la $a0 ($t1)
syscall
beq $t3 100 conv_neg_back        # convert the flagged number back to negative
j twos_C

conv_neg_back:                   # convert the flagged number back to negative
mul $s0 $s0 -1
j twos_C

three_D_N:
li $t0 0
div $t0 $s0 100                  # calculating the most significant bit
div $t1 $s0 10                   # calculating the second most significant bit
rem $t1 $t1 10                   # calculating the second most significant bit
rem $t2 $s0 10                   # calculating the second least significant bit
addi $t0 $t0 48                  # convert the second most significant bit to ascii
addi $t1 $t1 48                  # convert the second second most significant bit to ascii
addi $t2 $t2 48                  # convert the second least significant bit to ascii
li $v0 11
la $a0 ($t0)
syscall 
li $v0 11
la $a0 ($t1)
syscall
li $v0 11
la $a0 ($t2)
syscall
beq $t3 100 conv_neg_back
j twos_C

S_1D:
addi $t0 $s0 48                  # prints the one digit sum
li $v0 11
la $a0 ($t0)
syscall
beq $t3 100 conv_neg_back
j twos_C

#----------------------------

# printing The sum in Tow's Compliment

twos_C:
li $v0 4
la $a0 Twos
syscall
#-------- initialization --------#
li $t0 0                         # Binary holder
li $t1 0x80000000                # mask
li $t2 0                         # counter - keeps track of 32 bits
#--------------------------------#
loop_bi: nop
and $t0 $s0 $t1
srl $t1 $t1 1                    # shifting the 1 to the right to mask and isolate the one digit at the time
beq $t0 0 Print_Zero             # prints 0 if the answer of the mask is 0
bge $t0 1 Print_one              # prints 1 if the answer of the mask is 1
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
beq $t2 32 Morse
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
syscall  

# Making everything back to their defualt sign


#################### EXTRA CREDIT MORSE ########################
Morse: nop
li $v0 4
la $a0 Morse_Msg
syscall 
#-------- initialization --------#
li $t0 0                         # Binary holder
li $t1 0x80000000                # mask
li $t2 0                         # counter - keeps track of 32 bits
li $t3 0                         # negative flag
#--------------------------------#
and $t0 $s0 $t1
srl $t0 $t0 31                   # find out if sum is negative by checking the MSB
beq $t0 1 Print_Neg
j positiv_S                      # sum is positive so deal with it like a positive number 

Print_Neg: nop
li $v0 4
la $a0 negative_Morse            # print the Moste negative sign
add $t3 $t3 100
mul $s0 $s0 -1
syscall
positiv_S: nop
#-------- initialization --------#
li $t0 0                         # first decimal
li $t1 0                         # second decimal 
li $t2 0                         # counter - keep tracks of the digit postion
li $t4 0                         # second significant digit if the sum is more than 100
li $t6 0                         # least significant digit if the sum is more than 100
#--------------------------------#
beqz $s0 zero_morse
j pass_zero
zero_morse:
li $v0 4
la $a0 zero
syscall
j End_P
pass_zero:
bge $s0 100 Morse_D3             # check if it's more than 100 
bge $s0 10 Morse_D2              # check if it's more than 10 less than 100
ble $s0 9 Morse_D1               # che if it's more than 0 less than 10

Morse_D3:
li $v0 4
la $a0 one
syscall
rem $t0 $s0 100                  # calculated the reminder of the sum to return the second and least significant digits
j Morse_D3_first

Morse_D3_first: nop
div $t4 $t0 10                   # second significant digit if the sum is more than 100
beq $t4 0 print_zero
beq $t4 1 print_Morse_one
beq $t4 2 print_two
beq $t4 3 print_three
beq $t4 4 print_four
beq $t4 5 print_five
beq $t4 6 print_six
beq $t4 7 print_seven
beq $t4 8 print_eight
beq $t4 9 print_nine

Morse_D3_second: nop
rem $t6 $t0 10                   # least significant digit if the sum is more than 100
beq $t6 2 print_zero
beq $t6 1 print_Morse_one
beq $t6 2 print_two
beq $t6 3 print_three
beq $t6 4 print_four
beq $t6 5 print_five
beq $t6 6 print_six
beq $t6 7 print_seven
beq $t6 8 print_eight
beq $t6 9 print_nine
#---------------------------------
Morse_D2: nop
div $t0 $s0 10                   # second significant digit if the sum is more than 10
beq $t0 0 print_zero
beq $t0 1 print_Morse_one
beq $t0 2 print_two
beq $t0 3 print_three
beq $t0 4 print_four
beq $t0 5 print_five
beq $t0 6 print_six
beq $t0 7 print_seven
beq $t0 8 print_eight
beq $t0 9 print_nine

Morse_second: nop
rem $t1 $s0 10                   # second significant digit if the sum is more than 10
beq $t1 0 print_zero
beq $t1 1 print_Morse_one
beq $t1 2 print_two
beq $t1 3 print_three
beq $t1 4 print_four
beq $t1 5 print_five
beq $t1 6 print_six
beq $t1 7 print_seven
beq $t1 8 print_eight
beq $t1 9 print_nine

Morse_D1: nop                   # most significant digit if the sum is less than 10 bigger than 0
beq $s0 0 print_zero
beq $s0 1 print_Morse_one
beq $s0 2 print_two
beq $s0 3 print_three
beq $s0 4 print_four
beq $s0 5 print_five
beq $s0 6 print_six
beq $s0 7 print_seven
beq $s0 8 print_eight
beq $s0 9 print_nine
################ Morse Print ##################

# ------------------------- ZERO IN MORSE


                                 # all the comments for the printing numbers and register usages is all the same

print_zero:
bge $s0 100 three_digit_zero     # check if the number is more than 100
bge $s0 10 read_second_zero      # check if the number is more than 10 less than
ble $s0 9 zero_D                 # check if the number is more than 10 more than 0
zero_D:
li $v0 4
la $a0 zero                      # prints the number in binary
syscall
j End_F
read_second_zero:
li $v0 4
la $a0 zero
syscall
beq $t2 1 End_F
addi $t2 $t2 1                   # increament the counter to print the second integer
j Morse_second
three_digit_zero:
li $v0 4
la $a0 zero
syscall
beq $t2 1 End_F
addi $t2 $t2 1                   # increament the counter to print the second integer
j Morse_D3_second
# ------------------------- ONE IN MORSE
print_Morse_one:
bge $s0 100 three_digit_one
bge $s0 10 read_second_one
ble $s0 9 one_D
one_D:
li $v0 4
la $a0 one
syscall
j End_F
read_second_one:
li $v0 4
la $a0 one
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second
three_digit_one:
li $v0 4
la $a0 one
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

# ------------------------- TWO IN MORSE
print_two:
bge $s0 100 three_digit_two
bge $s0 10 read_second_two
ble $s0 9 two_D

neg_two:
li $v0 4
la $a0 two
syscall
j End_F
two_D:
li $v0 4
la $a0 two
syscall
j End_F
read_second_two:
li $v0 4
la $a0 two
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second
three_digit_two:
li $v0 4
la $a0 two
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

# ------------------------- THREE IN MORSE
print_three:
bge $s0 100 three_digit_three
bge $s0 10 read_second_three
ble $s0 9 three_D

neg_three:
li $v0 4
la $a0 three
syscall
j End_F
three_D:
li $v0 4
la $a0 three
syscall
j End_F
read_second_three:
li $v0 4
la $a0 three
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second
three_digit_three:
li $v0 4
la $a0 three
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

# ------------------------- FOUR IN MORSE 
print_four:
bge $s0 100 three_digit_four
bge $s0 10 read_second_four
ble $s0 9 four_D

neg_four:
li $v0 4
la $a0 four
syscall
j End_F
four_D:
li $v0 4
la $a0 four
syscall
j End_F
read_second_four:
li $v0 4
la $a0 four
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second
three_digit_four:
li $v0 4
la $a0 four
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

# ------------------------- FIVE IN MORSE
print_five:
bge $s0 100 three_digit_five
bge $s0 10 read_second_five
ble $s0 9 five_D

neg_five:
li $v0 4
la $a0 five
syscall
j End_F
five_D:
li $v0 4
la $a0 five
syscall
j End_F
read_second_five:
li $v0 4
la $a0 five
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second
three_digit_five:
li $v0 4
la $a0 five
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

# ------------------------- SIX IN MORSE
print_six:
bge $s0 100 three_digit_six
bge $s0 10 read_second_six
ble $s0 9 six_D

neg_six:
li $v0 4
la $a0 six
syscall
j End_F
six_D:
li $v0 4
la $a0 six
syscall
j End_F
read_second_six:
li $v0 4
la $a0 six
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second
three_digit_six:
li $v0 4
la $a0 six
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

# ------------------------- SEVEN IN MORSE
print_seven:
bge $s0 100 three_digit_seven
bge $s0 10 read_second_seven
ble $s0 9 seven_D

neg_seven:
li $v0 4
la $a0 seven
syscall
j End_F
seven_D:
li $v0 4
la $a0 seven
syscall
j End_F
read_second_seven:
li $v0 4
la $a0 seven
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second
three_digit_seven:
li $v0 4
la $a0 seven
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

# ------------------------- EIGHT IN MORSE
print_eight:
bge $s0 100 three_digit_eight
bge $s0 10 read_second_eight
ble $s0 9 eight_D

neg_eight:
li $v0 4
la $a0 eight
syscall
j End_F
eight_D:
li $v0 4
la $a0 eight
syscall
j End_F
read_second_eight:
li $v0 4
la $a0 eight
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second
three_digit_eight:
li $v0 4
la $a0 eight
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

# ------------------------- NINE IN MORSE
print_nine:
bge $s0 100 three_digit_nine
bge $s0 10 read_second_nine
ble $s0 9 nine_D

neg_nine:
li $v0 4
la $a0 nine
syscall
j End_F

nine_D:
li $v0 4
la $a0 nine
syscall
j End_F

read_second_nine:
li $v0 4
la $a0 nine
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_second

three_digit_nine:
li $v0 4
la $a0 nine
syscall
beq $t2 1 End_F
addi $t2 $t2 1
j Morse_D3_second

#-----------------------------------------------

End_F:                           # return the S1 and S2 intor their currect state
beq $t3 100 return_back_to_initial_sign
j S1_S2_sign_back
return_back_to_initial_sign:
mul $s0 $s0 -1                   # turning the number to it's own initial sign ( - ) OR ( + )

S1_S2_sign_back:
beq $t7 1 reNeg1

secon_N_check:
beq $t5 1 reNeg2
j End_P

reNeg1: nop
mul $s1 $s1 -1                   # turning the number to it's own initial sign ( - ) OR ( + )
j secon_N_check

reNeg2:
mul $s2 $s2 -1                   # turning the number to it's own initial sign ( - ) OR ( + )
j End_P

# end of the program
End_P:
li $v0 10 
syscall 
