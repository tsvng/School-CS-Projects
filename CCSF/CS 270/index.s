#
# index.s - simple demonstration of an indexing operation
#   goal: add code to this file to do the calculation
#      Diff[i] = A[i] - B[i]   for any single value of i
#      where  0<=i<10  ( i in [0,10)  )
#   (i.e,, if you change the value of i below, the code should
#    calculate and set the correct Diff element. You can assume
#    i is always in the range given above)
#
    .data
i:  .word 0
A:  .word 2,0x14,0x23,0x36,0x49,0x52,0x61,0x75,0x87,0x98
B:  .word 1,4,3,6,9,2,1,5,7,8
Diff:   .space  40
    .text
__start:
	la $t0, A		#put address of A into $t0
	la $t1, B		#put address of B into $t1
	la $t2, Diff		#put address of Diff into $t2
	lw $t3, i		#put index i into $t3
	sll $t3, $t3, 2		#multiply index by 4
	add $t4, $t0, $t3	#combine two components of the address for A
	add $t5, $t1, $t3	#combine two components of the address for B
	add $t6, $t2, $t3	#combine two components of the address for Diff
	
	lw $t7, 0($t4)		#store value from A's array cell into $t7
	lw $t8, 0($t5)		#store value from B's array cell into $t8
	sub $t9, $t7, $t8	#$t9 = A[i] - B[i]
	sw $t9, 0($t6)		#Diff[i] = $t9 (A[i] - B[i])