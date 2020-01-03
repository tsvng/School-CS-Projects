        .data
        .text
        .globl compare_larger
        #int compare_larger(int *one, int *two){
        #return (one>two)
        #}
compare_larger:
	lw	$t0,0($a0)	# $t0 = one
	lw	$t1,0($a1)	# $t1 = two
	
        bgt     $t0,$t1,returnOneLarge
        move    $v0,$zero
        jr      $ra
returnOneLarge:
        li      $v0,1
        jr      $ra



        .globl compare_smaller
        #int compare_smaller(int *one, int *two){
        #return (one<two)
        #}
compare_smaller:
	lw	$t0,0($a0)	# $t0 = one
	lw	$t1,0($a1)	# $t1 = two
	
        blt     $t0,$t1,returnOneSmall
        move    $v0,$zero
        jr      $ra
returnOneSmall:
        li      $v0,1
        jr      $ra



        .globl swap
        #void swap(int *one, int *two){
        #int temp = one;
        #one = two;
        #two = temp;}
swap:
	lw	$t0,0($a0)	# $t0 = one
	lw	$t1,0($a1)	# $t1 = two
	
	sw	$t1,0($a0)	# one = two
	sw	$t0,0($a1)	# two = temp
        jr      $ra

#
#
# bubblesort.s -
#  this really ugly code (it took long enough to translate it)
#  does the guts of the bubblesort algorithm. You must provide two 
# functions:
#
# void swap(int *a, int *b) ;
#   to swap two data values given their pointers
#
# int compare_larger (int *first, int *second) ;
#   which returns 1 if *first > *second. 0 otherwise
#
# int compare_smaller (int *first, int *second) ;
#   which returns 1 if *first < *second. 0 otherwise
#
# I suggest you put them in a file named swap.s
#
    .data
# here is the integer array that will be sorted.
# your last task is to modify the bubblesort algorithm
# so that the array size is dynamically calculated.
# instead of using the fixed size of N below
#   (the easiest way is just to calculate the value
#    that should be in N and store it in it before N is used)
#
# int A[10] = {5,3,-3,54,2,-56,7,9,11,11};
# int N=10;
    .data
A:  
# comment out one of these next two lines
#    .include "bubblesort.data"
    .word  5,3,-3,54,2,-56,7,9,11,11
Aend: # use this label to dynamically calculate the size of the array later
#  instead of using N
N:  .word 10
nlstr: .asciiz "\n"
    .align 2
# here is the data word reserved for the function pointer
funcptr: .word 0
    .text


# main() {
    .globl main
main:
    # need room for args, $ra, one s-reg (for index)
    addiu   $sp,$sp,-24
    sw      $ra,20($sp)
    sw      $s0,16($sp)
    # int i; (we will just use a $t register for this)
    la      $a0,A
    lw      $a1,N
    la      $a2,compare_larger
    # bubblesort(A,N,compare_larger);
    jal     bubblesort
    # for (i=0;i<N;i++) printf("%d ",A[i]);
    move    $s0,$zero   # i
Lresult:
    lw      $t1,N
    bge     $s0,$t1,Lmaindone
    sll     $t0,$s0,2
    la      $t2,A
    add     $t2,$t0,$t2
    lw      $a0,0($t2)
    jal     PrintInteger
    addi    $s0,$s0,1
    # putchar ('\n');
    la      $a0,nlstr
    jal     PrintString
    b       Lresult
Lmaindone:
    lw      $ra,20($sp)
    lw      $s0,16($sp)
    addiu   $sp,$sp,24
    jr      $ra

# you could include swap() and compare_larger() here 

#.include "/pub/cs/gboyd/cs270/util.s"
.include "./util.s"

    .text
    .globl bubblesort
#bubblesort (int *A, int nelems, int (*compar)(int *, int *)) {
bubblesort:
    # this procedure uses temps instead of s-register. It could be
    #  significantly optimized if it used s-registers instead.
    #  There is a version (bubblesort_sregs.s) that does that.
    # need $ra, 4 temps (plus one extra), plus std arg space.
    addiu   $sp,$sp,-40
    # last is 20($sp)   (also reg $t2)
    # temp is 24($sp)
    # inner is 28($sp)  (also reg $t1)
    # outer is 32($sp) (also reg $t0)
    # $ra is 36($sp)
    sw  $ra,36($sp)
    # $a0 is 40($sp)
    sw  $a0,40($sp)
    # $a1 is 44($sp)
    sw  $a1,44($sp)
    # $a2 is 48($sp)
    sw  $a2,48($sp)

    # int *outer,*inner,temp;
    # int *last=&A[nelems];
    sll     $t0,$a1,2   # nelems * 4
    add     $t2,$a0,$t0 # & A[nelems]
    sw      $t2,20($sp)  # $t2 is last

    # for (outer=A; outer<last; outer++) {
    # outer=A;
    sw      $a0,32($sp)
    move    $t0,$a0     # $t0 is outer register
Louter:
    # if (outer >= last) goto Louterdone;
    bge     $t0,$t2,Louterdone
    # for (inner=(outer+1);inner<last; inner++) {
    # inner=(outer+1);
    addi    $t1,$t0,4   # $t1 is inner reg
Linner:
    # if (inner >= last) goto Linnerdone;
    bge     $t1,$t2,Linnerdone
    # if ( ((*compar) (inner, outer)) > 0) {
    # if ( ((*compar) (inner,outer)) <= 0) goto Linnerskip;
    # home $t0, $t1, $t3
    sw  $t0,32($sp)
    sw  $t1,28($sp)
    sw  $t2,20($sp)
    # load arguments for (*compar)
    move    $a0,$t1
    move    $a1,$t0
    jalr    $a2
    ble     $v0,$zero,Linnerskip
    # swap(outer,inner);
    lw      $a0,32($sp)
    lw      $a1,28($sp)
    jal     swap
    # }
Linnerskip:
    # reload $t0 and $t1 after the function calls.
    lw      $t0,32($sp)
    lw      $t1,28($sp)
    lw  	$t2,20($sp)
    # }
    # inner++;
    addi    $t1,$t1,4
    #sw      $t1,28($sp)
    # goto Linner;
    b       Linner
Linnerdone:
    # }
    # outer++;
    lw      $t0,32($sp)
    addi    $t0,$t0,4
    sw      $t0,32($sp)
    # goto Louter;
    b       Louter
Louterdone: 
    lw      $ra,36($sp)
    addiu   $sp,$sp,40
    jr      $ra
#}
