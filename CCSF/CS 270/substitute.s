#
# substitute.s - substitute one character for another in a string
#
    .data
string: .space 80
orig:   .space 1
new:    .space 1
sprompt: .asciiz    "Enter string:"
oprompt: .asciiz    "Enter character you want to replace:"
nprompt: .asciiz    "Enter replacement character:"
resultmsg:  .asciiz "Resulting string:\n"
nsubsmsg:   .asciiz "Number of substitutions: "
    .text
    .globl  main
main:
    # get string
    la      $a0,sprompt
    la      $a1,string
    li      $a2,80
    li      $v0,54
    syscall
    # get original character
    # since there is no 'inputdialogchar' syscall, use an inputdialogstring
    # syscall. This will read a string but we will just use the first character
    la      $a0,oprompt
    la      $a1,orig
    li      $a2,4
    li      $v0,54
    syscall
    la      $a0,nprompt
    la      $a1,new
    li      $a2,4
    li      $v0,54
    syscall
#
# now we are ready to do the real work of substituting every instance of
# 'old' with 'new' in 'string'
# HINT: before you start, initialize the following registers:
# a0 = address of the string
# a1 = char to look for
# a2 = char to replace with
# Have fun!
#
#
#    int i,count=0;
#    for (i=0;string[i]!=0;i++) 
#        if (string[i] == orig) { 
#            string[i]=new;
#            count++;
#        }
#
# last, output string and count 
#~~~~~~~~~~~~~~~~~~~~~~~~~
# real code

	li	$t0,0			# t0 = 0, i = 0
	li 	$v0,0			# v0 = 0, count = 0
	la 	$a0,string		# a0 = address of the string
	lb 	$a1,orig		# a1 = char to look for
	lb 	$a2,new			# a2 = char to replace with
		
 .Lloop:
   	add 	$t2,$t0,$a0		# combine two components of the address for string
	lb 	$t3,0($t2)		# $t3 = string[i]
	
  	beq 	$t3,0,.Ldone		# loop: if(string[i] == 0) goto Ldone;
	bne 	$t3,$a1,.Lincr		# if(string[i] != orig) goto Lincr;
	sb 	$a2,0($t2)		# string[i] = new
	addi 	$v0,$v0,1		# count++
 .Lincr: 
  	addi 	$t0,$t0,1 		# incr: i++
	b 	.Lloop			# goto Lloop;
 .Ldone:				# Ldone:
	
    	
    	move    $a1,$v0         # number of substitutions in $t0
    	la      $a0,nsubsmsg
   	li      $v0,56
    	syscall
    	la      $a0,resultmsg
   	la      $a1,string
   	li      $v0,59
    	syscall

    	jr  $ra #return to main
	


