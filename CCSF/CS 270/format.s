	.data
num: .word 42
msg0:	.asciiz "The value is 0x"
msg1: 	.asciiz "ENTER to accept or input new value: 0x"
empty:	.asciiz ""
	.text
	.globl main
main:
	addiu	$sp,$sp,-48
	sw		$ra,44($sp)
	sw		$s3,40($sp)
	sw		$s2,36($sp)
	sw		$s1,32($sp)
	sw		$s0,28($sp)
	# buf is at 16($sp)
	lw	$a0,num
	la	$a1,16($sp)
	jal	itoax
	# len1=strlen(msg0)
	la	$a0,msg0
	jal	strlen
	move	$s0,$v0
	# len1=strlen(buf)
	la	$a0,16($sp)
	jal	strlen
	move	$s1,$v0
	# len1=strlen(msg1)
	la	$a0,msg1
	jal	strlen
	move	$s2,$v0
	# ptr = malloc(len1+len2+len3+1)
	add	$a0,$s0,$s1
	add	$a0,$a0,$s2
	addi	$a0,$a0,1
	jal	malloc
	move $s3,$v0
	# strcp(ptr,msg0)
	la	$a1,msg0
	move	$a0,$s3
	jal	strcpy
	# strcpy(ptr+len1,buf)
	la	$a1,16($sp)
	add	$a0,$s3,$s0
	jal	strcpy
	#strcpy (ptr+len1+len2,msg1)
	la	$a1,msg1
	add	$a0,$s3,$s0
	add	$a0,$a0,$s1
	jal	strcpy
	#MessageDialogString("",ptr)
	la	$a0,empty
	move	$a1,$s3
	jal	MessageDialogString
	lw		$ra,44($sp)
	lw		$s3,40($sp)
	lw		$s2,36($sp)
	lw		$s1,32($sp)
	lw		$s0,28($sp)
	addiu	$sp,$sp,48
	jr	$ra
	
.include "util.s"	
#.include "/pub/cs/gboyd/cs270/util.s"	
