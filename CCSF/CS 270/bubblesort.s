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
