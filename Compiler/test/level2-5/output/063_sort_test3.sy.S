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

.globl QuickSort
.type QuickSort, %function
QuickSort:
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
	mov r8, #136
	sub sp, sp, r8
.LBQuickSort:
	mov r9, r0
	str r9, [fp, #-116]
	mov r9, r1
	str r9, [fp, #-136]
	mov r9, r2
	ldr r8, [fp, #-136]
	cmp r8, r9
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_QuickSort0_ELSE
	b .LBB_QuickSort0_IF
.LBB_QuickSort0_IF:
	ldr r7, [fp, #-136]
	mov r8, r7
	mov r7, r9
	mov r5, #4
	mov r5, r5
	ldr r10, [fp, #-136]
	mul r5, r10, r5
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r5, [r10, r5]
	mov r6, r5
.LB_1_LOOP_BEGIN:
	cmp r8, r7
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
.LB_2_LOOP_BEGIN:
	cmp r8, r7
	mov r5, #0
	bge .LB_16_COND_END
	mov r10, #4
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	mov r10, r10
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	mul r10, r7, r10
	str r10, [fp, #-20]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	ldr r4, [fp, #-20]
	str r4, [fp, #-120]
	ldr r4, [fp, #-120]
	ldr r10, [r10, r4]
	str r10, [fp, #-24]
	sub r10, r6, #1
	str r10, [fp, #-28]
	ldr r10, [fp, #-24]
	ldr r4, [fp, #-28]
	str r4, [fp, #-120]
	ldr r4, [fp, #-120]
	cmp r10, r4
	mov r10, #0
	movgt r10, #1
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	mov r5, r10
.LB_16_COND_END:
	mov r10, #0
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	cmp r5, r10
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	sub r5, r7, #1
	mov r7, r5
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	cmp r8, r7
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	cmp r5, r10
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	mov r10, r10
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	mul r10, r8, r10
	str r10, [fp, #-56]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-60]
	ldr r10, [fp, #-56]
	ldr r4, [fp, #-60]
	str r4, [fp, #-124]
	ldr r4, [fp, #-124]
	str r5, [r4, r10]
	add r5, r8, #1
	mov r8, r5
.LBB_3_ELSE:
.LB_4_LOOP_BEGIN:
	cmp r8, r7
	mov r5, #0
	bge .LB_32_COND_END
	mov r10, #4
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	mov r10, r10
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	mul r10, r8, r10
	str r10, [fp, #-72]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-76]
	ldr r10, [fp, #-72]
	ldr r4, [fp, #-76]
	str r4, [fp, #-128]
	ldr r4, [fp, #-128]
	ldr r10, [r4, r10]
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	cmp r10, r6
	mov r10, #0
	movlt r10, #1
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	mov r5, r10
.LB_32_COND_END:
	mov r10, #0
	str r10, [fp, #-88]
	ldr r10, [fp, #-88]
	cmp r5, r10
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	add r5, r8, #1
	mov r8, r5
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	cmp r8, r7
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	cmp r5, r10
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	mov r10, r10
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	mul r10, r7, r10
	str r10, [fp, #-108]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-112]
	ldr r10, [fp, #-108]
	ldr r4, [fp, #-112]
	str r4, [fp, #-132]
	ldr r4, [fp, #-132]
	str r5, [r4, r10]
	sub r5, r7, #1
	mov r7, r5
.LBB_5_ELSE:
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	ldr r5, [fp, #-116]
	mov r5, r5
	str r6, [r5, r7]
	sub r6, r8, #1
	mov r7, r6
	mov r2, r7
	ldr r7, [fp, #-136]
	mov r1, r7
	ldr r7, [fp, #-116]
	mov r0, r7
	bl QuickSort
	mov r7, r0
	add sp, sp, #0
	mov r7, r7
	add r8, r8, #1
	mov r7, r8
	mov r2, r9
	mov r1, r7
	ldr r8, [fp, #-116]
	mov r0, r8
	bl QuickSort
	mov r8, r0
	add sp, sp, #0
	mov r8, r8
.LBB_QuickSort0_ELSE:
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
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #4
	str r7, [r8, r9]
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #3
	str r7, [r8, r9]
	mov r9, #2
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #9
	str r7, [r8, r9]
	mov r9, #3
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #2
	str r7, [r8, r9]
	mov r9, #4
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #0
	str r7, [r8, r9]
	mov r9, #5
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #1
	str r7, [r8, r9]
	mov r9, #6
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #6
	str r7, [r8, r9]
	mov r9, #7
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #5
	str r7, [r8, r9]
	mov r9, #8
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #7
	str r7, [r8, r9]
	mov r9, #9
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #8
	str r7, [r8, r9]
	mov r9, #0
	mov r8, #9
	mov r2, r8
	mov r1, r9
	add r9, sp, #0
	mov r0, r9
	bl QuickSort
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
.LB_main6_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB6_LOOP_END
	b .LB6_LOOP_BODY
.LB6_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r8, r7
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r8, #10
	mov r0, r8
	bl putch
	mov r8, r0
	add sp, sp, #0
	add r8, r9, #1
	mov r9, r8
	b .LB_main6_LOOP_BEGIN
.LB6_LOOP_END:
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007223"