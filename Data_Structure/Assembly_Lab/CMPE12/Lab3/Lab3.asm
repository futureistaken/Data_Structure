####################################################################################
# Created by: Farahmand, Babak
# Bfarahma
# 2 Nov 2018
#
# Assignment: Lab 3: Flux Bunny
# CMPE 012, Computer Systems and Assembly Language
# UC Santa Cruz, Fall 2018
#
# Description: This program prints:
#1- ‘Flux Bunny’ If number is divisible by both 5 and 7
#2- ‘Flux’ If number is divisible by both 5
#3- ‘Bunny’ If number is divisible by 7
#4- Number by itself If number is NOT divisible by both 5 and 7
#
# Notes: This program is intended to be run from the MARS IDE.
####################################################################################
.data
m57: .asciiz "Flux Bunny"
m5: .asciiz "Flux"
m7: .asciiz "Bunny"
inputMessage: .asciiz "Please input a positive integer: "
newLine: .asciiz "\n"

.text 
main:
li  $t5,0                # Initializing a temp register with 0
li $t7,0                 # Initializing a temp register with 0
li $t1, 0                # Initializing a temp (counter) register with 0

#--------------------------------------#
li $v0,4
la $a0,inputMessage      # print the input message
syscall 
li $v0,5                 # gets the user input
syscall 
#--------------------------------------#

move $t0,$v0             # Set temp register $t1 to wahtever user input number is

                        
Loop: #loop begins

#reminder calculation
rem $t5,$t1,5            # storing the reminder of devision by 5 inside t5 
rem $t7,$t1,7            # storing the reminder of devision by 7 inside t7 
#---------conditions-------------------#
beqz $t1,firsNumber      # First number is 0
beqz $t5,DivBy5          # If number IS Divisiable with 5
beqz $t7,DivBy7          # If number Is Divisiable with 5
bne $0,$t5,number        # If number is NOT Divisiable with 5
bne $0,$t7,number        # If number is NOT Divisiable with 7
#--------------------------------------#
ExitCondition:                       # jumpig back from the condition statment messeges
li $v0,4
la $a0,newLine           # Print New Line for a better look on output
syscall
ble  $t0,$t1, end_loop   # Loop Condition
addi $t1, $t1, 1         # Loop incrementation

j Loop                   # Loop repeater

#-------------#Conditional statement messages#------------#
DivBy5:
beqz $t7,DivBy57         # AND Implementation -- If number Divisiable with 5 and 7
li	$v0,4
la	$a0,m5
syscall
j ExitCondition
#-------------
DivBy7:
beqz $t5,DivBy57         # AND Implementation -- If number Divisiable with 5 and 7
li	$v0,4
la	$a0,m7
syscall
j ExitCondition
#-------------
DivBy57:
li	$v0,4
la	$a0,m57
syscall
j ExitCondition
#-------------
firsNumber:
li	$v0,4
la	$a0,m57
 syscall
j ExitCondition
#-------------
number:                  # Printing Numbers that are not devisiable by 5 and 7
li $v0,1
la $a0,($t1)
syscall
j ExitCondition
#---------------------------------------
end_loop:                # ENDING the loop and stop the program!
syscall
