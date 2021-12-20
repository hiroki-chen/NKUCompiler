.macro mov32, reg, val
 	movw \reg, #:lower16:\val
 	movt \reg, #:upper16:\val
.endm
.macro cpu_id, rd
 	mrc	p15, 0, \rd, c0, c0, 5
 	and	\rd, \rd, #0xF
.endm
.text
.syntax unified

.data
.globl TOKEN_NUM
TOKEN_NUM:
.word 0

.globl TOKEN_OTHER
TOKEN_OTHER:
.word 1

.globl last_char
last_char:
.word 32

.globl num
num:
.word 0

.globl other
other:
.word 0

.globl cur_token
cur_token:
.word 0

.globl eval
.type eval, %function
eval:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBeval:
	sub sp, sp, #1024
	mov r9, sp
	mov r0, r9
	mov r1, #0
	mov r2, #1024
	bl memset
	sub sp, sp, #1024
	mov r9, sp
	mov r0, r9
	mov r1, #0
	mov r2, #1024
	bl memset
	mov r9, #0
	mov32 r9, cur_token
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, TOKEN_NUM
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r9, #0
	movne r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_eval12_ELSE
	b .LBB_eval12_IF
.LBB_eval12_IF:
	bl panic
	mov r9, r0
	mov r0, r9
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_eval12_ELSE:
	mov r9, #0
	mov32 r9, num
	ldr r9, [r9, #0]
	mov r1, r9
	add r9, sp, #1024
	mov r0, r9
	bl stack_push
	mov r9, r0
	bl next_token
	mov r9, r0
.LB_eval13_LOOP_BEGIN:
	mov r9, #0
	mov32 r9, cur_token
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, TOKEN_OTHER
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r9, #0
	moveq r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LB13_LOOP_END
	b .LB13_LOOP_BODY
.LB13_LOOP_BODY:
	mov r8, #0
	mov32 r8, other
	ldr r8, [r8, #0]
	mov r9, r8
	mov r0, r9
	bl get_op_prec
	mov r8, r0
	mov r7, #0
	cmp r7, r8
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_14_ELSE
	b .LBB_14_IF
.LBB_14_IF:
	b .LB13_LOOP_END
.LBB_14_ELSE:
	bl next_token
	mov r8, r0
.LB_15_LOOP_BEGIN:
	mov r0, r8
	bl stack_size
	mov r8, r0
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	beq .LB_13_COND_END
	mov r0, r7
	bl stack_peek
	mov r7, r0
	mov r0, r7
	bl get_op_prec
	mov r7, r0
	mov r0, r9
	bl get_op_prec
	mov r6, r0
	cmp r7, r6
	mov r7, #0
	movge r7, #1
	mov r8, r7
.LB_13_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LB15_LOOP_END
	b .LB15_LOOP_BODY
.LB15_LOOP_BODY:
	mov r0, r7
	bl stack_pop
	mov r7, r0
	mov r8, r7
	add r6, sp, #1024
	mov r0, r6
	bl stack_pop
	mov r6, r0
	mov r7, r6
	add r5, sp, #1024
	mov r0, r5
	bl stack_pop
	mov r5, r0
	mov r6, r5
	mov r2, r7
	mov r1, r6
	mov r0, r8
	bl eval_op
	mov r8, r0
	mov r1, r8
	add r8, sp, #1024
	mov r0, r8
	bl stack_push
	mov r8, r0
	b .LB_15_LOOP_BEGIN
.LB15_LOOP_END:
	mov r1, r9
	mov r0, r9
	bl stack_push
	mov r9, r0
	mov r9, #0
	mov32 r9, cur_token
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, TOKEN_NUM
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r9, #0
	movne r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_16_ELSE
	b .LBB_16_IF
.LBB_16_IF:
	bl panic
	mov r9, r0
	mov r0, r9
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_16_ELSE:
	mov r9, #0
	mov32 r9, num
	ldr r9, [r9, #0]
	mov r1, r9
	add r9, sp, #1024
	mov r0, r9
	bl stack_push
	mov r9, r0
	bl next_token
	mov r9, r0
	b .LB_eval13_LOOP_BEGIN
.LB13_LOOP_END:
	bl next_token
	mov r9, r0
.LB_17_LOOP_BEGIN:
	mov r0, r9
	bl stack_size
	mov r9, r0
	mov r8, #0
	cmp r9, r8
	beq .LB17_LOOP_END
	b .LB17_LOOP_BODY
.LB17_LOOP_BODY:
	mov r0, r8
	bl stack_pop
	mov r8, r0
	mov r9, r8
	add r7, sp, #1024
	mov r0, r7
	bl stack_pop
	mov r7, r0
	mov r8, r7
	add r6, sp, #1024
	mov r0, r6
	bl stack_pop
	mov r6, r0
	mov r7, r6
	mov r2, r8
	mov r1, r7
	mov r0, r9
	bl eval_op
	mov r9, r0
	mov r1, r9
	add r9, sp, #1024
	mov r0, r9
	bl stack_push
	mov r9, r0
	b .LB_17_LOOP_BEGIN
.LB17_LOOP_END:
	add r9, sp, #1024
	mov r0, r9
	bl stack_peek
	mov r9, r0
	mov r0, r9
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl eval_op
.type eval_op, %function
eval_op:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBeval_op:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, #43
	cmp r9, r6
	mov r6, #0
	moveq r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_eval_op7_ELSE
	b .LBB_eval_op7_IF
.LBB_eval_op7_IF:
	mov r6, r7
	add r6, r8, r6
	mov r0, r6
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_eval_op7_ELSE:
	mov r6, #45
	cmp r9, r6
	mov r6, #0
	moveq r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_eval_op8_ELSE
	b .LBB_eval_op8_IF
.LBB_eval_op8_IF:
	mov r6, r7
	sub r6, r8, r6
	mov r0, r6
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_eval_op8_ELSE:
	mov r6, #42
	cmp r9, r6
	mov r6, #0
	moveq r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_eval_op9_ELSE
	b .LBB_eval_op9_IF
.LBB_eval_op9_IF:
	mov r6, r7
	mul r6, r8, r6
	mov r0, r6
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_eval_op9_ELSE:
	mov r6, #47
	cmp r9, r6
	mov r6, #0
	moveq r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_eval_op10_ELSE
	b .LBB_eval_op10_IF
.LBB_eval_op10_IF:
	mov r6, r0
	mov r5, r1
	mov r0, r8
	mov r1, r7
	bl __aeabi_idiv
	mov r10, r0
	mov r0, r6
	mov r1, r5
	mov r0, r10
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_eval_op10_ELSE:
	mov r6, #37
	cmp r9, r6
	mov r9, #0
	moveq r9, #1
	mov r6, #0
	cmp r9, r6
	beq .LBB_eval_op11_ELSE
	b .LBB_eval_op11_IF
.LBB_eval_op11_IF:
	mov r9, r0
	mov r6, r1
	mov r0, r8
	mov r1, r7
	bl __aeabi_idivmod
	mov r5, r1
	mov r0, r9
	mov r1, r6
	mov r0, r5
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_eval_op11_ELSE:
	mov r0, #0
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl get_op_prec
.type get_op_prec, %function
get_op_prec:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBget_op_prec:
	mov r9, r0
	mov r8, #43
	cmp r9, r8
	mov r8, #1
	beq .LBget_op_prec3_COND_END
	mov r7, #45
	cmp r9, r7
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LBget_op_prec3_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_get_op_prec5_ELSE
	b .LBB_get_op_prec5_IF
.LBB_get_op_prec5_IF:
	mov r0, #10
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_get_op_prec5_ELSE:
	mov r8, #42
	cmp r9, r8
	mov r8, #1
	beq .LBget_op_prec8_COND_END
	mov r7, #47
	cmp r9, r7
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LBget_op_prec8_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LBget_op_prec6_COND_END
	mov r7, #37
	cmp r9, r7
	mov r9, #0
	moveq r9, #1
	mov r8, r9
.LBget_op_prec6_COND_END:
	mov r9, #0
	cmp r8, r9
	beq .LBB_get_op_prec6_ELSE
	b .LBB_get_op_prec6_IF
.LBB_get_op_prec6_IF:
	mov r0, #20
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_get_op_prec6_ELSE:
	mov r0, #0
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl is_num
.type is_num, %function
is_num:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBis_num:
	mov r9, r0
	mov r8, #48
	cmp r9, r8
	mov r8, #0
	blt .LB_is_num3_COND_END
	mov r7, #57
	cmp r9, r7
	mov r9, #0
	movle r9, #1
	mov r8, r9
.LB_is_num3_COND_END:
	mov r9, #0
	cmp r8, r9
	beq .LBB_is_num1_ELSE
	b .LBB_is_num1_IF
.LBB_is_num1_IF:
	mov r0, #1
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_is_num1_ELSE:
	mov r0, #0
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl is_space
.type is_space, %function
is_space:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBis_space:
	mov r9, r0
	mov r8, #32
	cmp r9, r8
	mov r8, #1
	beq .LBis_space3_COND_END
	mov r7, #10
	cmp r9, r7
	mov r9, #0
	moveq r9, #1
	mov r8, r9
.LBis_space3_COND_END:
	mov r9, #0
	cmp r8, r9
	beq .LBB_is_space0_ELSE
	b .LBB_is_space0_IF
.LBB_is_space0_IF:
	mov r0, #1
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14
.LBB_is_space0_ELSE:
	mov r0, #0
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl main
.type main, %function
main:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBmain:
	bl getint
	mov r8, r0
	mov r9, r8
	bl getch
	mov r8, r0
	bl next_token
	mov r8, r0
.LB_main18_LOOP_BEGIN:
	mov r8, #0
	cmp r9, r8
	beq .LB18_LOOP_END
	b .LB18_LOOP_BODY
.LB18_LOOP_BODY:
	bl eval
	mov r8, r0
	mov r0, r8
	bl putint
	mov r8, r0
	mov r0, #10
	bl putch
	mov r8, r0
	sub r8, r9, #1
	mov r9, r8
	b .LB_main18_LOOP_BEGIN
.LB18_LOOP_END:
	mov r0, #0
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl next_char
.type next_char, %function
next_char:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBnext_char:
	bl getch
	mov r9, r0
	mov r8, #0
	mov32 r8, last_char
	ldr r8, [r8, #0]
	mov r8, #0
	mov32 r8, last_char
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, last_char
	ldr r9, [r9, #0]
	mov r0, r9
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl next_token
.type next_token, %function
next_token:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBnext_token:
.LB_next_token2_LOOP_BEGIN:
	mov r9, #0
	mov32 r9, last_char
	ldr r9, [r9, #0]
	mov r0, r9
	bl is_space
	mov r9, r0
	mov r8, #0
	cmp r9, r8
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	bl next_char
	mov r9, r0
	b .LB_next_token2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r9, #0
	mov32 r9, last_char
	ldr r9, [r9, #0]
	mov r0, r9
	bl is_num
	mov r9, r0
	mov r8, #0
	cmp r9, r8
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	mov r9, #0
	mov32 r9, last_char
	ldr r9, [r9, #0]
	sub r9, r9, #48
	mov r8, #0
	mov32 r8, num
	ldr r8, [r8, #0]
	mov r8, #0
	mov32 r8, num
	str r9, [r8, #0]
.LB_4_LOOP_BEGIN:
	bl next_char
	mov r9, r0
	mov r0, r9
	bl is_num
	mov r9, r0
	mov r8, #0
	cmp r9, r8
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r9, #0
	mov32 r9, num
	ldr r9, [r9, #0]
	mov r8, #10
	mul r9, r9, r8
	mov r8, #0
	mov32 r8, last_char
	ldr r8, [r8, #0]
	add r9, r9, r8
	sub r9, r9, #48
	mov r8, #0
	mov32 r8, num
	ldr r8, [r8, #0]
	mov r8, #0
	mov32 r8, num
	str r9, [r8, #0]
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	mov r9, #0
	mov32 r9, TOKEN_NUM
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, cur_token
	ldr r8, [r8, #0]
	mov r8, #0
	mov32 r8, cur_token
	str r9, [r8, #0]
	b .LBB_3_END_IF
.LBB_3_ELSE:
	mov r9, #0
	mov32 r9, last_char
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, other
	ldr r8, [r8, #0]
	mov r8, #0
	mov32 r8, other
	str r9, [r8, #0]
	bl next_char
	mov r9, r0
	mov r9, #0
	mov32 r9, TOKEN_OTHER
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, cur_token
	ldr r8, [r8, #0]
	mov r8, #0
	mov32 r8, cur_token
	str r9, [r8, #0]
	b .LBB_3_END_IF
.LBB_3_END_IF:
	mov r9, #0
	mov32 r9, cur_token
	ldr r9, [r9, #0]
	mov r0, r9
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl panic
.type panic, %function
panic:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBpanic:
	mov r0, #112
	bl putch
	mov r9, r0
	mov r0, #97
	bl putch
	mov r9, r0
	mov r0, #110
	bl putch
	mov r9, r0
	mov r0, #105
	bl putch
	mov r9, r0
	mov r0, #99
	bl putch
	mov r9, r0
	mov r0, #33
	bl putch
	mov r9, r0
	mov r0, #10
	bl putch
	mov r9, r0
	mov r9, #0
	sub r9, r9, #1
	mov r0, r9
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl stack_peek
.type stack_peek, %function
stack_peek:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBstack_peek:
	mov r9, r0
	mov r8, #0
	mov r7, #4
	mul r8, r8, r7
	mov r7, r9
	ldr r8, [r7, r8]
	mov r7, #4
	mul r8, r8, r7
	ldr r9, [r9, r8]
	mov r0, r9
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl stack_pop
.type stack_pop, %function
stack_pop:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBstack_pop:
	mov r9, r0
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #4
	mul r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	sub r7, r7, #1
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	str r7, [r9, r6]
	mov r0, r8
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl stack_push
.type stack_push, %function
stack_push:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBstack_push:
	mov r9, r0
	mov r8, r1
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	add r7, r7, #1
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, r9
	str r7, [r5, r6]
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #4
	mul r7, r7, r6
	str r8, [r9, r7]
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.globl stack_size
.type stack_size, %function
stack_size:
	push {r14}
	push {r10}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r4}
	push {fp}
	mov fp, sp
	mov r8, #0
	sub sp, sp, r8
.LBstack_size:
	mov r9, r0
	mov r8, #0
	mov r7, #4
	mul r8, r8, r7
	ldr r9, [r9, r8]
	mov r0, r9
	mov sp, fp
	pop {fp}
	pop {r4}
	pop {r5}
	pop {r6}
	pop {r7}
	pop {r8}
	pop {r9}
	pop {r10}
	pop {r14}
	mov pc, r14

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640004947"