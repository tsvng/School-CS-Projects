#int min=0;
	.data
min:	.word	42
#int max=100;
max:		.word  165
LbeforeMin:	.asciiz	"Enter a hexadecimal number between 0x"
LbetweenMinMax: .asciiz " and 0x"
LafterMax:	.asciiz "\nEnter your guess:"
Lmessage:	.asciiz "The result question is:\n"
		.align 2
		.text
		.globl main
main:
	addiu	$sp,$sp,-24
	sw		$ra,20($sp)
#
#main() {
#
#    char *beforeMin = "Enter a hexadecimal number between 0x";
#    char *betweenMinMax = " and 0x";
#    char *afterMax = "\nEnter your guess:";
#    char *question;
#
#    question = createQuestion(beforeMin, min, betweenMinmax, max, afterMax);
	 la		$a0,LbeforeMin
	 lw		$a1,min
	 la		$a2,LbetweenMinMax
	 lw		$a3,max
	 la		$t0,LafterMax
	 sw		$t0,16($sp)
	 jal		createQuestion
#
#    MessageDialogString("The result question is:\n",question);
	 la		$a0,Lmessage
	 move	$a1,$v0
	 jal	MessageDialogString
	 lw		$ra,20($sp)
	 addiu	$sp,$sp,24
	 jr		$ra

#.include "/pub/cs/gboyd/cs270/util.s"
.include "./util.s"
.include "./createQuestion.s"
#
#}
