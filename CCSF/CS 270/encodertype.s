#
# encodertype.s: this program has variables for the
# fields of an R-type instruction (op, rs, rt, rd, shamt, funct)
# that the user sets for whatever R-type instrucion she wants to 
# encode. The main program them calls the function encodertype:
#
#    unsigned encodertype(unsigned opc, unsigned rs, unsigned rt, 
#        unsigned rd, unsigned shamt, unsigned funct);
#
# which encodes the R-type instruction, returning the instruction.
#
# The main program then decodes the instruction and outputs the value of
# each field for checking.
#
# The function interface and main program are written for you! All you have
# to do is to fill in the missing code in the function to actually do 
# the encoding, following the instructions. SEE THE END OF THIS FILE.
#
# This program should be run with the exception handler.
#
    .data
# alter these values for the instruction you want to encode
# the default encoded one is for srl $a0,$sp,21
opc:    .word 0
rs:     .word 0
rt:     .word 29
rd:     .word 4
shamt:  .word 21
funct:  .word 2
opcstring: .asciiz "\nThe encoded opc is:"
rsstring: .asciiz "\nThe encoded rs is:"
rtstring: .asciiz "\nThe encoded rt is:"
rdstring: .asciiz "\nThe encoded rd is:"
shamtstring: .asciiz "\nThe encoded shamt is:"
functstring: .asciiz "\nThe encoded funct is:"

    .text
    .globl main
main:
    addiu   $sp,$sp,-28
    sw      $ra,24($sp)
    # prepare for the call to encodertype
    lw      $a0,opc
    lw      $a1,rs
    lw      $a2,rt
    lw      $a3,rd
    lw      $t0,shamt
    sw      $t0,16($sp)
    lw      $t0,funct
    sw      $t0,20($sp)
    jal     encodertype
    # result in $v0
    # move the result to $t9 since we need $v0 for syscalls
    move    $t9,$v0
    # print opc result
    la      $a0,opcstring
    li      $v0,4
    syscall
    srl     $a0,$t9,26
    li      $v0,1
    syscall
    # print rs result
    la      $a0,rsstring
    li      $v0,4
    syscall
    srl     $a0,$t9,21
    andi    $a0,$a0,0x1f
    li      $v0,1
    syscall
    # print rt result
    la      $a0,rtstring
    li      $v0,4
    syscall
    srl     $a0,$t9,16
    andi    $a0,$a0,0x1f
    li      $v0,1
    syscall
    # print rd result
    la      $a0,rdstring
    li      $v0,4
    syscall
    srl     $a0,$t9,11
    andi    $a0,$a0,0x1f
    li      $v0,1
    syscall
    # print shamt result
    la      $a0,shamtstring
    li      $v0,4
    syscall
    srl     $a0,$t9,6
    andi    $a0,$a0,0x1f
    li      $v0,1
    syscall
    # print funct result
    la      $a0,functstring
    li      $v0,4
    syscall
    andi    $a0,$t9,0x3f
    li      $v0,1
    syscall

# return from main
    lw      $ra,24($sp)
    addiu   $sp,$sp,28
    jr      $ra

    .globl encodertype
encodertype:
    # this is a leaf function so we dont create a stack frame
    # the first four arguments are in $a0, $a1, $a2, $a3
    # we need to load the last two (shamt and funct) from the stack.
    # We will place them in $t0 (shamt) and $t1 (funct) for you:
    lw      $t0,16($sp) #shamt
    lw      $t1,20($sp) #funct
#####################
#  INSERT YOUR CODE IN THE SPACE BELOW TO TAKE THE
#  ARGUMENTS FROM $a0..$a3, $t0, $t1
#  AND encode the R-type instruction, placing the result in $v0
#
#  You can use any t-registers you like, and you can modify the a-regs
#  if you like. DO NOT USE OTHER REGISTERS!
#####################
	
    li  $t2,0       	# store result in $t2 (zero out $t2)
    and $a0,0x3f 	# mask opc with 6 bits, 0x3f = 0011 1111 which is 6 bits
    add $t2,$a0,$zero   # $t2 = opc -> holds opcode in 6 bits

    sll $t2,$t2,5  	# shift to rs' spot
    and $a1,0x1f    	# mask rs with 5 bits, 0x1f = 0001 1111 which is 5 bits
    or  $t2,$t2,$a1	# or in the masked rs -> $t2 holds opc and rs in 11 bits

    sll $t2,$t2,5   	# shift to rt's slot
    and $a2,0x1f   	# mask rt with 5 bits (0x1f = 0001 1111)
    or  $t2,$t2,$a2 	# or in masked rt -> $t2 holds opc, rs, rt in 16 bits

    sll $t2,$t2,5   	# shift to rd's slot
    and $a3,0x1f   	# mask rd with 5 bits (0x1f = 0001 1111)
    or  $t2,$t2,$a3 	# or in masked rd -> $t2 holds opc, rs, rt, rd in 21 bits

    sll $t2,$t2,5  	# shift to shamt's slot
    and $t0,0x1f    	# mask shamt with 5 bits (0x1f = 0001 1111)
    or  $t2,$t2,$t0 	# or in masked shamt -> $t2 holds opc, rs, rt, rd, shamt in 26 bits

    sll $t2,$t2,6 	# shift to funct's slot
    and $t1,0x3f    	# mask funct with 6 bits (0x3f = 0011 1111)
    or  $t2,$t2,$t1 	# or in masked funct -> $t2 holds opc, rs, rt, rd, shamt, funct in its 32 bits
 
    move $v0,$t2    	# ensure the result is in $v0
    jr      $ra	    	# this returns to main
