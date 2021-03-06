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
	sub sp, sp, #40
	mov r8, #0
	mov r9, #0
.LB_main0_LOOP_BEGIN:
	mov r8, #10
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	add r8, r9, #1
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, sp
	add r6, r6, #0
	str r8, [r6, r7]
	add r8, r9, #1
	mov r9, r8
	b .LB_main0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r6, #10
	bl getint
	mov r5, r0
	add sp, sp, #0
	mov r9, r5
	sub r6, r6, #1
	mov r8, r6
	mov r7, #0
	mov r7, r7
	add r8, r8, r7
	mov r7, r0
	mov r6, r1
	mov r0, r8
	mov r1, #2
	bl __aeabi_idiv
	mov r8, r0
	mov r0, r7
	mov r1, r6
	mov r6, r8
	mov r8, #0
	mov r7, #0
	mov r6, #0
.LB_1_LOOP_BEGIN:
	mov r5, #10
	cmp r7, r5
	mov r5, #0
	bge .LB_25_COND_END
	mov r10, #0
	cmp r8, r10
	mov r10, #0
	moveq r10, #1
	mov r5, r10
.LB_25_COND_END:
	mov r10, #0
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, sp
	add r10, r10, #0
	ldr r5, [r10, r5]
	cmp r5, r9
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
	mov r8, #1
	mov r6, r7
.LBB_2_ELSE:
	add r5, r7, #1
	mov r7, r5
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	mov r9, #1
	cmp r8, r9
	mov r9, #0
	moveq r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	mov r0, r6
	bl putint
	mov r9, r0
	add sp, sp, #0
	b .LBB_3_END_IF
.LBB_3_ELSE:
	mov r9, #0
	mov r0, r9
	bl putint
	mov r8, r0
	add sp, sp, #0
	b .LBB_3_END_IF
.LBB_3_END_IF:
	mov r9, #10
	mov r0, r9
	bl putch
	mov r8, r0
	add sp, sp, #0
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007383"