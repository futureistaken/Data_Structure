####################################################################################
# Created by: Farahmand, Babak
# Bfarahma
# 7 Dec 2018
#
# Assignment: Lab 5: Subroutines
# CMPE 012, Computer Systems and Assembly Language
# UC Santa Cruz, Fall 2018
#
# Description of this program:
#1- shows a prompt
#2- asks from user to type the prompt within 10 second	
#3- user fails if can't type withing 10 seconds
#4- user fails if can't type the prompt correct 
#
# Notes: This program is intended to be run from the MARS IDE.
####################################################################################

.data
promptMsg: .asciiz "Type Prompt: "
input: .space 53
inputSize: .word 52


.text
#--------------------------------------------------------------------
# give_type_prompt
#
# input:  $a0 - address of type prompt to be printed to user
#
# output: $v0 - lower 32 bit of time prompt was given in milliseconds
#--------------------------------------------------------------------
give_type_prompt:
#------ Register Usage -----------------
# $t5 : a temp register to holds the promt's address register ($a0)
#--------------------------------------

move $t5 $a0                     # saving the input $a0 in order to print the prompt later

# telling user to type the promp
li $v0 4
la $a0 promptMsg
syscall

# print the prompt
li $v0 4
la $a0 ($t5) 
syscall 


# read the timer
li $v0 30
syscall
move $v0 $a0

jr $ra
#--------------------------------------------------------------------
# check_user_input_string
#
# input:  $a0 - address of type prompt printed to user
#         $a1 - time type prompt was given to user
#         $a2 - contains amount of time allowed for response
#
# output: $v0 - success or loss value (1 or 0)
#--------------------------------------------------------------------
check_user_input_string:

#------ Register Usage -----------------
# $sp : stack pointer  register - point to an address of a location in stack
# $ra : return address register - holdes the address of the program counter + 4
# $t5 : a temp register to holds the time that user saw the first prompmt
# $t6 : a temp register to holds the amount of time allowed for response
# $t7 : a temp register to holds the address of type prompt printed to user
# $t8 : a temp register to holds the address of user input
#--------------------------------------

# creating stack
addi $sp $sp -4                  # allocating space at stack to store the return address register
sw $ra 0($sp)

move $t7 $a0                     # address of type prompt printed to user


move $t6 $a2                     # amount of time allowed for response
move $t5 $a1                     # reading the time that user saw the first prompmt


# taking the input from user
li $v0, 8
la $a0  input
lw $a1  inputSize
syscall
move $t8 $a0

li $v0 30
syscall

sub $t5 $a0 $t5                  # the time that took user to input
sub $v0 $t6 $t5                  # the comulitive time that user have left at the end

bgt $v0 0 you_still_have_a_chance# user still have time left so it starts comparing the strings
ble $v0 0 no_time_left
no_time_left: nop
li $v0 0
lw $ra ($sp)
addi $sp $sp 4
jr $ra

you_still_have_a_chance:
move $a0 $t7                     # address of the prompt
move $a1 $t8                     # address of the user input
jal compare_strings              # jump to the compare_strings subroutine

lw $ra 0($sp)
addi $sp $sp 4
jr $ra
#--------------------------------------------------------------------
# compare_strings
#
# input:  $a0 - address of first string to compare
#         $a1 - address of second string to compare
#
# output: $v0 - comparison result (1 == strings the same, 0 == strings not the same)
#--------------------------------------------------------------------
compare_strings:
#------ Register Usage -----------------
# $sp : stack pointer  register - point to an address of a location in stack
# $ra : return address register - holdes the address of the program counter + 4
# $t5 : a temp register to holds the address of first string to compare
# $t6 : a temp register to holds the address of second string to compare
# $a0 : address of first string to compare
# $a1 : address of second string to compare
#--------------------------------------
addi $sp $sp -8
sw $ra 4($sp)

move $t5 $a0
move $t6 $a1

loop_string: nop

lb $a0 ($t5)
#------------ Punctuation checker --------------
# source https://en.wikipedia.org/wiki/Punctuation
beq $a0 33 skip0                 # ascii code for !
beq $a0 34 skip0                 # ascii code for "
beq $a0 39 skip0                 # ascii code for '
beq $a0 40 skip0                 # ascii code for (
beq $a0 41 skip0                 # ascii code for )
beq $a0 44 skip0                 # ascii code for ,
beq $a0 45 skip0                 # ascii code for -
beq $a0 47 skip0                 # ascii code for /
beq $a0 58 skip0                 # ascii code for :
beq $a0 59 skip0                 # ascii code for ;
beq $a0 60 skip0                 # ascii code for <
beq $a0 62 skip0                 # ascii code for >
beq $a0 63 skip0                 # ascii code for ?
#-----------------------------------------------

lb $a1 ($t6)
#------------ Punctuation checker --------------
# source https://en.wikipedia.org/wiki/Punctuation
beq $a1 33 skip1                  # ascii code for !
beq $a1 34 skip1                  # ascii code for "
beq $a1 39 skip1                  # ascii code for '
beq $a1 40 skip1                  # ascii code for (
beq $a1 41 skip1                  # ascii code for )
beq $a1 44 skip1                  # ascii code for ,
beq $a1 45 skip1                  # ascii code for -
beq $a1 47 skip1                  # ascii code for /
beq $a1 58 skip1                  # ascii code for :
beq $a1 59 skip1                  # ascii code for ;
beq $a1 60 skip1                  # ascii code for <
beq $a1 62 skip1                  # ascii code for >
beq $a1 63 skip1                  # ascii code for ?
#-----------------------------------------------
beq $a0 10 input_done            # when hit's the new line it understands that the prompt is done, so it checks if user failed or not
jal compare_chars

beq $v0 1 loop_string            # check to see if the characters were matching to move to the next char


input_done:

bne $a1 10 lost                  # check to see if user inputs more charecter than the prompt given

beq $v0 1 won                    
beq $v0 0 lost

won: nop
li $v0 1
lw $ra 4($sp)                    # restore the old $ra address 
addi $sp $sp 8                   # Frees the stack location
jr $ra


lost: nop
li $v0 0
lw $ra 4($sp)
addi $sp $sp 8
jr $ra

# skips the Punctuation
skip0:
addi $t5 $t5 1
j loop_string
skip1:
addi $t6 $t6 1
j loop_string
#--------------------------------------------------------------------
# compare_chars
#
# input:  $a0 - first char to compare (contained in the least significant byte)
#         $a1 - second char to compare (contained in the least significant byte)
#
# output: $v0 - comparison result (1 == chars the same, 0 == chars not the same)
#
#--------------------------------------------------------------------
compare_chars:
#------ Register Usage -----------------
# $sp : stack pointer  register - point to an address of a location in stack
# $ra : return address register - holdes the address of the program counter + 4
# $t5 : a temp register to holds the address of first string to compare
# $t6 : a temp register to holds the address of second string to compare
# $a0 : first char to compare (contained in the least significant byte)
# $a1 : second char to compare (contained in the least significant byte)
# $v0 : comparison result (1 == chars the same, 0 == chars not the same)
#--------------------------------------
addi $sp $sp -12
sw $ra 8($sp)

addi $t5 $t5 1
addi $t6 $t6 1


#---- Capitalization checker ----
beq $a0 $a1 equal                # check if they are the same
addi $a1 $a1 32                  # add 32 to make it Capital
beq $a0 $a1 equal                # check to if after capitlization they are the same
sub $a1 $a1 64                   # make is lower case letter
beq $a0 $a1 equal                # check to see if the lower case letter matches
#--------------------------------
bne $a0 $a1 not_equal            # check if the characters are not the same


equal: nop
li $v0 1
lw $ra 8($sp)                    # restore the old $ra address 
addi $sp $sp 12                  # Frees the stack location
jr $ra


not_equal:nop
li $v0 0
lw $ra 8($sp)
addi $sp $sp 12
jr $ra
