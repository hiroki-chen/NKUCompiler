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

.globl heap_ajust
.type heap_ajust, %function
heap_ajust:
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
	mov r8, #12
	sub sp, sp, r8
.LBheap_ajust:
	mov r9, r0
	str r9, [fp, #-12]
	mov r9, r1
	mov r8, r2
	mov r7, r9
	mov r6, #2
	mov r6, r6
	mul r6, r7, r6
	add r6, r6, #1
	mov r9, r6
.LB_heap_ajust0_LOOP_BEGIN:
	add r6, r8, #1
	cmp r9, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	cmp r9, r8
	mov r6, #0
	bge .LB_13_COND_END
	mov r5, #4
	mov r5, r5
	mul r5, r9, r5
	ldr r10, [fp, #-12]
	mov r10, r10
	ldr r5, [r10, r5]
	add r10, r9, #1
	mov r4, #4
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	mov r4, r4
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	mul r10, r10, r4
	ldr r4, [fp, #-12]
	mov r4, r4
	str r4, [fp, #-8]
	ldr r4, [fp, #-8]
	ldr r10, [r4, r10]
	cmp r5, r10
	mov r5, #0
	movlt r5, #1
	mov r6, r5
.LB_13_COND_END:
	mov r5, #0
	cmp r6, r5
	beq .LBB_1_ELSE
	b .LBB_1_IF
.LBB_1_IF:
	add r6, r9, #1
	mov r9, r6
.LBB_1_ELSE:
	mov r6, #4
	mov r6, r6
	mul r6, r7, r6
	ldr r5, [fp, #-12]
	mov r5, r5
	ldr r6, [r5, r6]
	mov r5, #4
	mov r5, r5
	mul r5, r9, r5
	ldr r10, [fp, #-12]
	mov r10, r10
	ldr r5, [r10, r5]
	cmp r6, r5
	mov r6, #0
	movgt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
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
.LBB_2_ELSE:
	mov r2, r9
	mov r1, r7
	ldr r6, [fp, #-12]
	mov r0, r6
	bl swap
	mov r6, r0
	add sp, sp, #0
	mov r7, r6
	mov r7, r9
	mov r6, #2
	mov r6, r6
	mul r6, r7, r6
	add r6, r6, #1
	mov r9, r6
	b .LB_heap_ajust0_LOOP_BEGIN
.LB0_LOOP_END:
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

.globl heap_sort
.type heap_sort, %function
heap_sort:
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
.LBheap_sort:
	mov r9, r0
	mov r8, r1
	mov r5, r0
	mov r10, r1
	mov r0, r8
	mov r1, #2
	bl __aeabi_idiv
	mov r4, r0
	mov r0, r5
	mov r1, r10
	sub r5, r4, #1
	mov r7, r5
.LB_heap_sort3_LOOP_BEGIN:
	mov r5, #0
	sub r5, r5, #1
	cmp r7, r5
	mov r5, #0
	movgt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	sub r5, r8, #1
	mov r6, r5
	mov r2, r6
	mov r1, r7
	mov r0, r9
	bl heap_ajust
	mov r5, r0
	add sp, sp, #0
	mov r6, r5
	sub r5, r7, #1
	mov r7, r5
	b .LB_heap_sort3_LOOP_BEGIN
.LB3_LOOP_END:
	sub r8, r8, #1
	mov r8, r8
.LB_4_LOOP_BEGIN:
	mov r7, #0
	cmp r8, r7
	mov r7, #0
	movgt r7, #1
	mov r5, #0
	cmp r7, r5
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r7, #0
	mov r2, r8
	mov r1, r7
	mov r0, r9
	bl swap
	mov r5, r0
	add sp, sp, #0
	mov r6, r5
	sub r5, r8, #1
	mov r6, r5
	mov r2, r6
	mov r1, r7
	mov r0, r9
	bl heap_ajust
	mov r7, r0
	add sp, sp, #0
	mov r6, r7
	sub r7, r8, #1
	mov r8, r7
	b .LB_4_LOOP_BEGIN
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
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	mov r1, r8
	add r8, sp, #0
	mov r0, r8
	bl heap_sort
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
.LB_main5_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB5_LOOP_END
	b .LB5_LOOP_BODY
.LB5_LOOP_BODY:
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
	b .LB_main5_LOOP_BEGIN
.LB5_LOOP_END:
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

.globl swap
.type swap, %function
swap:
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
.LBswap:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r6, r5
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r10, #4
	mov r10, r10
	mul r8, r8, r10
	mov r10, r9
	str r5, [r10, r8]
	mov r8, #4
	mov r8, r8
	mul r8, r7, r8
	mov r9, r9
	str r6, [r9, r8]
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