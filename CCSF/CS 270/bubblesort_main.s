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

.include "/pub/cs/gboyd/cs270/util.s"

