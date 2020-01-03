#
# strdup.s - copy a string and output the new string
#   the new string is dynamically-allocated.
#   the original string is in a buffer on the stack
#
#  contains the user-implemented function 
#    char * strdup (char * str);
#
# NEEDS to .include util.s
#
    .data
ipprompt:   .asciiz "Enter the string to copy (max 100 chars):"
ipprompt2:  .asciiz "Here's the original:"
opprompt:   .asciiz "Here's the copy:"
ipstring:   .space 100
ipstringend:
    .align 2
ipstringmax:   .word 0
    .text
    .globl main
main:
    # I have done the stack for you. You have room for
    # -- four arg regs
    # -- 100 byte character buffer (at 16($sp))
    # -- one s-register (for pointer to new string returned from strdup)
    # -- $ra (at 120($sp))
    addiu   	$sp,$sp,-124
    sw  	$ra,120($sp)
    # there is room on the stack to save an s-reg. Save it at 116($sp)
    sw 		$s0,116($sp)	# $s0 = retval
    sw		$a3,12($sp)		# $a3
    sw		$a2,8($sp)		# $a2
    sw		$a1,4($sp)		# $a1
    sw		$a0,0($sp)		# $a0
    
     

    # your s-reg will be used to hold newstr (the string returned from strdup)
Lnextstr:
    # retval = InputDialogString(ipprompt,buffer,100)
    la		$a0,ipprompt
    add		$a1,$sp,100
    li		$a2,100
    jal 	InputDialogString
    move	$s0,$v0		



    # if (retval <= 0) goto Ldone;
    blez	$s0,Ldone



    # char *newstr = strdup(buffer);
    add		$a0,$sp,100
    jal 	strdup		# $v0 holds strdup(buffer)
    
    


    # save newstr in your s-reg
    move 	$s0,$v0		# $s0 = $v0

    # report original string again
    # MessageDialogString(ipprompt2,buffer)
    la 		$a0,ipprompt2
    add		$a1,$sp,100
    jal 	MessageDialogString
    



    # now resport result string
    # MessageDialogString(opprompt,newstr)
    la	 	$a0,opprompt
    move	$a1,$s0
    jal 	MessageDialogString



    # and go around the loop again
    b   	Lnextstr
Ldone:
    lw 		 $ra,120($sp)
    # insert code to restore your s-reg here
    lw 		$s0,116($sp)
    lw		$a3,12($sp)		
    lw		$a2,8($sp)		
    lw		$a1,4($sp)		
    lw		$a0,0($sp)		
    addiu  	$sp,$sp,124
    jr  	$ra


    # this stub for strdup will just return the same string
    # (i.e., not copy it). It can be used to check that your 
    # main program is working
    .globl strdup
strdup:
    move 	$v0,$a0
    jr  	$ra

#.include "util.s"		#for home use
.include "/pub/cs/gboyd/cs270/util.s"

