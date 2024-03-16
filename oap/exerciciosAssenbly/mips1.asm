.text

.global main

main:
	li $v0, 5
	Syscall 
	move $s0, $v0 
	li, $v0, 5
	Syscall
	move $s1, $v0 
	add $s2,$s0,$s1
	move $a0, $s2
	li $v0, 5
	Syscall 
	move $s2, $v0 
	add $a0,$s2,$a0

	