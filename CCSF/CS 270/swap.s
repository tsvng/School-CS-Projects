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
