#
# mymul_main.s - a partial implementation of the mymul program
#  the user enters a multiplier and multiplicand the the
#  program computes multiplier * multiplicand using 
#  a recursive function mymul (see below)

# /* product = multiplier * multiplicand */
#
# the function int mymul(int left, int right); is supplied by the user
# the support functions and main program follow:
    .data
banner:  .asciiz "Welcome to multiply. Enter the integers to multiply together"
multiplier_prompt:  .asciiz "Enter the multiplier (first number):"
multiplicand_prompt:  .asciiz "Enter the multiplicand (second number):"
result_banner:  .asciiz "Result="

    .text
    .globl main
# main() {
main:
    # main needs standard argument stack space, to save $ra 
    # and it needs three words of stack space for 
    # multiplier, multiplicand and product
    addiu   $sp,$sp,-32
    sw      $ra,28($sp)
    # 24($sp) is product
    # 20($sp) is multiplicand
    # 16($sp) is multiplier
    #    puts("Welcome to multiply. Enter the integers to multiply together");
    li      $a1,1
    la      $a0,banner
    jal     MessageDialog
    #
    #    multiplier = get_int("Enter the multiplier (first number):");
    la      $a0,multiplier_prompt
    jal     get_int
    sw      $v0,16($sp)

    #    multiplicand = get_int("Enter the multiplicand (second number):");
    la      $a0,multiplicand_prompt
    jal     get_int
    sw      $v0,20($sp)

    #    product=mymul(multiplier,multiplicand);
    lw      $a0,16($sp)
    lw      $a1,20($sp)
    jal     mymul
    sw      $v0,24($sp)

    #    printf("Result=%d\n",product);
    la      $a0,result_banner
    lw      $a1,24($sp)
    jal     MessageDialogInt

    lw      $ra,28($sp)
    addiu   $sp,$sp,32
    jr      $ra
#}

    .data
notpositive:  .asciiz "you must enter a positive integer"
    .text
.globl get_int
get_int:
    # stack frame needed 
    addiu   $sp,$sp,-24
    # one temp space needed for integer result from InputDialogInt
    # at 16($sp)
    sw      $ra,20($sp)
    # $a0 must be homed!
    # home $a0
    sw      $a0,24($sp)
Lloop:
    # move original a0 (prompt) back from home location
    # (in case this isn't the first time around the loop)
    lw      $a0,24($sp)
    # create the address of the temporary integer
    add     $a1,$sp,16  
    jal     InputDialogInt
    # did InputDialogInt return an error?
    beq     $v0,$zero,Lbadint
    # get the number stored by InputDialogInt
    lw      $v0,16($sp)
    # if the number was interpreted as a positive integer, we're done
    bgt     $v0,$zero,Lret1

    # if not, complain about the integer and try again
Lbadint:

    # output a message that the integer must be positive
    la      $a0,notpositive
    li      $a1,2
    jal     MessageDialog

    # get another integer
    b       Lloop

Lret1:

    # result is in $v0 already.
    # just unwind the stack and return
    lw      $ra,20($sp)
    addiu   $sp,$sp,24
    jr      $ra


    .globl checkregs
checkregs:    
    # this function just destroys all volatile registers
    # and writes over its argument area
    sw      $t0,0($sp)
    sw      $t0,4($sp)
    jr      $ra

.include "./util.s"
#.include "/pub/cs/gboyd/cs270/util.s"

# void checkregs(void); // contained in mymul_main.s
#
# int mymul(int left, int right){
#    int retval;
#    // the function checkregs must be called here
#    // it ensures you are following the calling convention.
#    checkregs();
#    // here is the code for mymul that you must write
#    if (left == 1) retval=right;
#    else retval=(right+mymul(left-1,right));
#    return(retval);
#}
# NOTE: this version has some redundant stores, and translates the
# problem literally, saving the return address as a local variable. 
# Some of this is redundant
#
    .text 0x00401000
    .globl mymul

mymul:  
    # your code goes here
        # to be explicit, we will save $a0 and $a1 as well as $ra
        # we also need four bytes of temp space (retval)
        addiu   $sp,$sp,-24
        sw      $a0,24($sp)
        sw      $a1,28($sp)
        sw      $ra,20($sp)

        # checkregs();
        jal     checkregs
        lw      $a0,24($sp)
        lw      $a1,28($sp)
        # int retval;
        # retval is at 16($sp)

        # if (left != 1) goto notone;
        addi    $t0,$zero,1
        bne     $a0,$t0,Lnotone

        # retval=right; 
        sw      $a1,16($sp)

        # goto ret;
        b       Lret
#notone:
Lnotone:
        
        # retval=(right+mymul(left-1,right)); 
        # home a0/a1
        sw      $a1,28($sp)
        sw      $a0,24($sp)
        # set up arguments for recursive call
        addiu   $a0,$a0,-1
        jal     mymul
        lw      $a0,24($sp)
        lw      $a1,28($sp)
        add     $t0,$v0,$a1
        sw      $t0,16($sp)

#ret:
Lret:

        # return(retval);
        lw      $v0,16($sp)
        lw      $ra,20($sp)
        addiu   $sp,$sp,24
        jr      $ra
#} 
