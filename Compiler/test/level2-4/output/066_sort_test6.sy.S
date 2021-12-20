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
.globl n
n:
.word 0

.globl counting_sort
.type counting_sort, %function
counting_sort:
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
	mov r8, #52
	sub sp, sp, r8
.LBcounting_sort:
	mov r9, r0
	str r9, [fp, #-44]
	mov r9, r1
	str r9, [fp, #-52]
	mov r9, r2
	sub sp, sp, #40
	mov r6, #0
	mov r8, #0
	mov r7, #0
.LB_counting_sort0_LOOP_BEGIN:
	mov r5, #10
	cmp r6, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	cmp r5, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r5, #4
	mul r5, r6, r5
	mov r10, sp
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	str r10, [fp, #-4]
	mov r10, #0
	str r10, [fp, #-8]
	ldr r10, [fp, #-4]
	ldr r4, [fp, #-8]
	str r4, [fp, #-48]
	ldr r4, [fp, #-48]
	str r4, [r10, r5]
	add r5, r6, #1
	mov r6, r5
	b .LB_counting_sort0_LOOP_BEGIN
.LB0_LOOP_END:
.LB_1_LOOP_BEGIN:
	cmp r8, r9
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r6, #4
	mul r6, r8, r6
	ldr r5, [fp, #-44]
	ldr r6, [r5, r6]
	mov r5, #4
	mul r6, r6, r5
	mov r5, sp
	ldr r6, [r5, r6]
	add r6, r6, #1
	mov r5, #4
	mul r5, r8, r5
	ldr r10, [fp, #-44]
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	mul r5, r5, r10
	mov r10, sp
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	str r6, [r10, r5]
	add r6, r8, #1
	mov r8, r6
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	mov r8, #1
.LB_2_LOOP_BEGIN:
	mov r6, #10
	cmp r8, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r6, #4
	mul r6, r8, r6
	mov r5, sp
	ldr r6, [r5, r6]
	sub r5, r8, #1
	mov r10, #4
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	mul r5, r5, r10
	mov r10, sp
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	ldr r5, [r10, r5]
	add r6, r6, r5
	mov r5, #4
	mul r5, r8, r5
	mov r10, sp
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	str r6, [r10, r5]
	add r6, r8, #1
	mov r8, r6
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r7, r9
.LB_3_LOOP_BEGIN:
	mov r9, #0
	cmp r7, r9
	mov r9, #0
	movgt r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	sub r9, r7, #1
	mov r8, #4
	mul r9, r9, r8
	ldr r8, [fp, #-44]
	ldr r9, [r8, r9]
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	ldr r9, [r8, r9]
	sub r9, r9, #1
	sub r8, r7, #1
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-44]
	ldr r8, [r6, r8]
	mov r6, #4
	mul r8, r8, r6
	mov r6, sp
	str r9, [r6, r8]
	sub r9, r7, #1
	mov r8, #4
	mul r9, r9, r8
	ldr r8, [fp, #-44]
	ldr r9, [r8, r9]
	sub r8, r7, #1
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-44]
	ldr r8, [r6, r8]
	mov r6, #4
	mul r8, r8, r6
	mov r6, sp
	ldr r8, [r6, r8]
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-52]
	str r9, [r6, r8]
	sub r9, r7, #1
	mov r7, r9
	b .LB_3_LOOP_BEGIN
.LB3_LOOP_END:
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
	mov r9, #0
	mov32 r9, n
	ldr r9, [r9, #0]
	mov r9, #10
	mov r8, #0
	mov32 r8, n
	str r9, [r8, #0]
	sub sp, sp, #40
	mov r9, #0
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #4
	str r7, [r8, r9]
	mov r9, #1
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #3
	str r7, [r8, r9]
	mov r9, #2
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #9
	str r7, [r8, r9]
	mov r9, #3
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #2
	str r7, [r8, r9]
	mov r9, #4
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #0
	str r7, [r8, r9]
	mov r9, #5
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #1
	str r7, [r8, r9]
	mov r9, #6
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #6
	str r7, [r8, r9]
	mov r9, #7
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #5
	str r7, [r8, r9]
	mov r9, #8
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #7
	str r7, [r8, r9]
	mov r9, #9
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	mov r7, #8
	str r7, [r8, r9]
	mov r9, #0
	sub sp, sp, #40
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	mov r2, r8
	mov r1, r8
	add r8, sp, #40
	mov r0, r8
	bl counting_sort
	mov r8, r0
	mov r9, r8
.LB_main4_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r7, #4
	mul r7, r9, r7
	mov r6, sp
	ldr r7, [r6, r7]
	mov r8, r7
	mov r0, r8
	bl putint
	mov r8, r0
	mov r8, #10
	mov r0, r8
	bl putch
	mov r8, r0
	add r8, r9, #1
	mov r9, r8
	b .LB_main4_LOOP_BEGIN
.LB4_LOOP_END:
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640004946"