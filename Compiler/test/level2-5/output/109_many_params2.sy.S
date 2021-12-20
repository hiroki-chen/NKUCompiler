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
.globl func
.type func, %function
func:
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
	mov r8, #104
	sub sp, sp, r8
.LBfunc:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, r3
	add r5, fp, #36
	ldr r5, [r5]
	str r5, [fp, #-80]
	add r5, fp, #40
	ldr r5, [r5]
	str r5, [fp, #-104]
	add r5, fp, #44
	ldr r5, [r5]
	add r10, fp, #48
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r10, [r10]
	str r10, [fp, #-76]
	add r10, fp, #52
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r10, [r10]
	str r10, [fp, #-72]
	str r10, [fp, #-68]
	mov r10, #0
	str r10, [fp, #-68]
.LB_func0_LOOP_BEGIN:
	mov r10, #10
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	ldr r4, [fp, #-68]
	str r4, [fp, #-84]
	ldr r4, [fp, #-84]
	cmp r4, r10
	mov r10, #0
	movlt r10, #1
	str r10, [fp, #-16]
	mov r10, #0
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	ldr r4, [fp, #-16]
	str r4, [fp, #-84]
	ldr r4, [fp, #-84]
	cmp r4, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r10, #4
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	mov r10, r10
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	ldr r4, [fp, #-68]
	str r4, [fp, #-88]
	ldr r4, [fp, #-88]
	mul r10, r4, r10
	str r10, [fp, #-40]
	mov r10, #236
	str r10, [fp, #-28]
	mov r10, r9
	str r10, [fp, #-32]
	ldr r10, [fp, #-28]
	ldr r4, [fp, #-32]
	str r4, [fp, #-92]
	ldr r4, [fp, #-92]
	mul r10, r10, r4
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	mov r10, r10
	str r10, [fp, #-44]
	ldr r10, [fp, #-40]
	ldr r4, [fp, #-44]
	str r4, [fp, #-96]
	ldr r4, [fp, #-96]
	add r10, r10, r4
	str r10, [fp, #-48]
	mov r10, r8
	str r10, [fp, #-52]
	ldr r10, [fp, #-48]
	ldr r4, [fp, #-52]
	str r4, [fp, #-100]
	ldr r4, [fp, #-100]
	ldr r10, [r4, r10]
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	mov r0, r10
	bl putint
	mov r10, r0
	str r10, [fp, #-60]
	add sp, sp, #0
	ldr r10, [fp, #-68]
	add r10, r10, #1
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	mov r10, r10
	str r10, [fp, #-68]
	b .LB_func0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r0, #10
	bl putch
	mov r9, r0
	add sp, sp, #0
	mov r9, #4
	mov r9, r9
	mul r9, r7, r9
	mov r8, r6
	ldr r9, [r8, r9]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r9, r0
	add sp, sp, #0
.LB_1_LOOP_BEGIN:
	mov r9, #10
	ldr r8, [fp, #-72]
	cmp r8, r9
	mov r9, #0
	movlt r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	ldr r9, =#128875
	mov r9, r9
	ldr r8, [fp, #-76]
	mul r9, r8, r9
	mov r8, r0
	mov r7, r1
	mov r0, r9
	mov r1, #3724
	bl __aeabi_idivmod
	mov r9, r1
	mov r0, r8
	mov r1, r7
	mov r8, #4
	mov r8, r8
	ldr r7, [fp, #-72]
	mul r8, r7, r8
	mov r7, r5
	str r9, [r7, r8]
	ldr r9, [fp, #-72]
	add r9, r9, #1
	mov r9, r9
	str r9, [fp, #-72]
	ldr r9, [fp, #-76]
	add r9, r9, #7
	mov r9, r9
	str r9, [fp, #-76]
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	ldr r9, [fp, #-104]
	mov r9, r9
	ldr r8, [fp, #-80]
	add r9, r8, r9
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
	mov r8, #144
	sub sp, sp, r8
.LBmain:
	mov r9, #16348
	sub sp, sp, r9
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #16348
	bl memset
	mov r9, #12508
	sub sp, sp, r9
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #12508
	bl memset
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #268
	mov r7, #17
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	mov r7, #12508
	add r8, r8, r7
	mov r7, #6
	str r7, [r8, r9]
	mov r9, #3
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #268
	mov r7, #17
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	mov r7, #12508
	add r8, r8, r7
	mov r7, #7
	str r7, [r8, r9]
	mov r9, #4
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #268
	mov r7, #17
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	mov r7, #12508
	add r8, r8, r7
	mov r7, #4
	str r7, [r8, r9]
	mov r9, #7
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #268
	mov r7, #17
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	mov r7, #12508
	add r8, r8, r7
	mov r7, #9
	str r7, [r8, r9]
	mov r9, #11
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #268
	mov r7, #17
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	mov r7, #12508
	add r8, r8, r7
	mov r7, #11
	str r7, [r8, r9]
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #236
	mov r7, #6
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #1
	str r7, [r8, r9]
	mov r9, #2
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #236
	mov r7, #6
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #2
	str r7, [r8, r9]
	mov r9, #3
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #236
	mov r7, #6
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #3
	str r7, [r8, r9]
	mov r9, #9
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #236
	mov r7, #6
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #9
	str r7, [r8, r9]
	str r9, [fp, #-120]
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #268
	mov r7, #17
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	mov r7, #12508
	add r8, r8, r7
	ldr r9, [r8, r9]
	str r9, [fp, #-144]
	mov r9, #3
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #268
	mov r7, #17
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	mov r7, #12508
	add r8, r8, r7
	ldr r9, [r8, r9]
	mov r8, #0
	mov r7, #67
	mov r6, #17
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, sp
	mov r6, #12508
	add r7, r7, r6
	mov r7, r7
	mov r6, #4
	mov r8, r8
	mul r8, r6, r8
	mov r8, r8
	add r7, r7, r8
	mov r8, #3
	mov r6, #4
	mov r6, r6
	mul r8, r8, r6
	mov r6, #236
	mov r5, #6
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r8, r8, r6
	mov r6, sp
	add r6, r6, #0
	ldr r8, [r6, r8]
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #236
	mov r10, #6
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mov r10, r10
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, sp
	add r5, r5, #0
	ldr r6, [r5, r6]
	mov r5, #0
	mov r10, #59
	str r10, [fp, #-12]
	mov r10, #6
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	mov r10, r10
	str r10, [fp, #-16]
	ldr r10, [fp, #-12]
	ldr r4, [fp, #-16]
	str r4, [fp, #-124]
	ldr r4, [fp, #-124]
	mul r10, r10, r4
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	mov r10, r10
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	add r5, r5, r10
	mov r10, sp
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	add r10, r10, #0
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	mov r10, r10
	str r10, [fp, #-116]
	mov r10, #4
	str r10, [fp, #-32]
	mov r5, r5
	ldr r10, [fp, #-32]
	mul r5, r10, r5
	mov r5, r5
	ldr r10, [fp, #-116]
	add r5, r10, r5
	str r5, [fp, #-116]
	mov r5, #4
	mov r10, #4
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	mov r10, r10
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	mul r5, r5, r10
	mov r10, #236
	str r10, [fp, #-52]
	mov r10, #34
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	mov r10, r10
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	ldr r4, [fp, #-52]
	str r4, [fp, #-124]
	ldr r4, [fp, #-124]
	mul r10, r4, r10
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	mov r10, r10
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	add r5, r5, r10
	mov r10, sp
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	add r10, r10, #0
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	ldr r5, [r10, r5]
	mov r10, #18
	str r10, [fp, #-76]
	mov r10, #4
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	mov r10, r10
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	ldr r4, [fp, #-76]
	str r4, [fp, #-128]
	ldr r4, [fp, #-128]
	mul r10, r4, r10
	str r10, [fp, #-96]
	mov r10, #236
	str r10, [fp, #-88]
	mov r10, #51
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	mov r10, r10
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	ldr r4, [fp, #-88]
	str r4, [fp, #-132]
	ldr r4, [fp, #-132]
	mul r10, r4, r10
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	mov r10, r10
	str r10, [fp, #-100]
	ldr r10, [fp, #-96]
	ldr r4, [fp, #-100]
	str r4, [fp, #-136]
	ldr r4, [fp, #-136]
	add r10, r10, r4
	str r10, [fp, #-104]
	mov r10, sp
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	add r10, r10, #0
	str r10, [fp, #-108]
	ldr r10, [fp, #-104]
	ldr r4, [fp, #-108]
	str r4, [fp, #-140]
	ldr r4, [fp, #-140]
	ldr r10, [r4, r10]
	str r10, [fp, #-112]
	mov r3, r7
	mov r2, r9
	add r9, sp, #0
	mov r1, r9
	ldr r9, [fp, #-144]
	mov r0, r9
	ldr r9, [fp, #-112]
	push {r9}
	push {r5}
	ldr r9, [fp, #-116]
	push {r9}
	push {r6}
	push {r8}
	bl func
	mov r9, r0
	add sp, sp, #20
	mov r8, #3
	mov r8, r8
	mul r9, r9, r8
	mov r9, r9
	str r9, [fp, #-120]
.LB_main2_LOOP_BEGIN:
	mov r9, #0
	ldr r8, [fp, #-120]
	cmp r8, r9
	mov r9, #0
	movge r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r9, #4
	mov r9, r9
	ldr r8, [fp, #-120]
	mul r9, r8, r9
	mov r8, #236
	mov r7, #6
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	ldr r9, [r8, r9]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, #32
	bl putch
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-120]
	sub r9, r9, #1
	mov r9, r9
	str r9, [fp, #-120]
	b .LB_main2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r0, #10
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007223"