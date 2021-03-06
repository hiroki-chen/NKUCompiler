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
.globl concat
.type concat, %function
concat:
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
.LBconcat:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, #0
.LB_concat0_LOOP_BEGIN:
	mov r5, #3
	cmp r6, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r10, #4
	mov r10, r10
	mul r10, r6, r10
	mov r4, r7
	str r5, [r4, r10]
	add r5, r6, #1
	mov r6, r5
	b .LB_concat0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r9, #0
.LB_1_LOOP_BEGIN:
	mov r5, #3
	cmp r9, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r9, r5
	mov r10, r8
	ldr r5, [r10, r5]
	mov r10, #4
	mov r10, r10
	mul r10, r6, r10
	mov r4, r7
	str r5, [r4, r10]
	add r5, r6, #1
	mov r6, r5
	add r5, r9, #1
	mov r9, r5
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
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
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #24
	sub sp, sp, #12
	sub sp, sp, #12
	mov r9, #0
.LB_main2_LOOP_BEGIN:
	mov r8, #3
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #108
	str r9, [r7, r8]
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #96
	str r9, [r7, r8]
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #84
	str r9, [r7, r8]
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #72
	str r9, [r7, r8]
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #60
	str r9, [r7, r8]
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #48
	str r9, [r7, r8]
	add r8, r9, #1
	mov r9, r8
	b .LB_main2_LOOP_BEGIN
.LB2_LOOP_END:
	add r9, sp, #24
	mov r2, r9
	add r9, sp, #72
	mov r1, r9
	add r9, sp, #108
	mov r0, r9
	bl concat
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
.LB_3_LOOP_BEGIN:
	mov r7, #6
	cmp r9, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, sp
	add r6, r6, #24
	ldr r7, [r6, r7]
	mov r8, r7
	mov r0, r8
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r9, #1
	mov r9, r7
	b .LB_3_LOOP_BEGIN
.LB3_LOOP_END:
	mov r9, #10
	mov r0, r9
	bl putch
	mov r9, r0
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