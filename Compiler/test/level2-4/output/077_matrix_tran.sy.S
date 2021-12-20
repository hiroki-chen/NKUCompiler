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
.globl M
M:
.word 0

.globl L
L:
.word 0

.globl N
N:
.word 0

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
	mov32 r9, N
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, N
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, M
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, M
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, L
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, L
	str r9, [r8, #0]
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
.LB_main0_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, M
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
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
	b .LB_main0_LOOP_BEGIN
.LB0_LOOP_END:
	add r9, sp, #0
	add r8, sp, #12
	add r7, sp, #24
	add r6, sp, #48
	add r5, sp, #60
	add r10, sp, #72
	mov r3, r10
	add r10, sp, #84
	mov r2, r10
	add r10, sp, #96
	mov r1, r10
	add r10, sp, #108
	mov r0, r10
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	bl tran
	mov r9, r0
	add sp, sp, #20
	mov r9, r9
.LB_1_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, N
	ldr r7, [r7, #0]
	cmp r9, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
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
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	mov r9, #10
	mov r0, r9
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r8, #0
.LB_2_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, N
	ldr r7, [r7, #0]
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #12
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r9, #10
	mov r8, #0
	mov r0, r9
	bl putch
	mov r7, r0
	add sp, sp, #0
.LB_3_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, N
	ldr r7, [r7, #0]
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
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

.globl tran
.type tran, %function
tran:
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
	mov r8, #256
	sub sp, sp, r8
.LBtran:
	mov r9, r0
	str r9, [fp, #-208]
	mov r9, r1
	mov r8, r2
	mov r7, r3
	add r7, fp, #36
	ldr r7, [r7]
	add r7, fp, #40
	ldr r7, [r7]
	add r7, fp, #44
	ldr r7, [r7]
	str r7, [fp, #-256]
	add r7, fp, #48
	ldr r7, [r7]
	add r6, fp, #52
	ldr r6, [r6]
	mov r5, #0
	mov r5, #1
	mov r10, #4
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mov r10, r10
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mul r5, r5, r10
	mov r10, r8
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	ldr r5, [r10, r5]
	mov r10, #2
	str r10, [fp, #-16]
	mov r10, #4
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	mov r10, r10
	str r10, [fp, #-20]
	ldr r10, [fp, #-16]
	ldr r4, [fp, #-20]
	str r4, [fp, #-212]
	ldr r4, [fp, #-212]
	mul r10, r10, r4
	str r10, [fp, #-24]
	mov r10, r7
	str r10, [fp, #-28]
	ldr r10, [fp, #-24]
	ldr r4, [fp, #-28]
	str r4, [fp, #-212]
	ldr r4, [fp, #-212]
	str r5, [r4, r10]
	mov r5, #2
	mov r10, #4
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	mov r10, r10
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	mul r5, r5, r10
	mov r10, r9
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	ldr r5, [r10, r5]
	mov r10, #1
	str r10, [fp, #-48]
	mov r10, #4
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	mov r10, r10
	str r10, [fp, #-52]
	ldr r10, [fp, #-48]
	ldr r4, [fp, #-52]
	str r4, [fp, #-216]
	ldr r4, [fp, #-216]
	mul r10, r10, r4
	str r10, [fp, #-56]
	mov r10, r6
	str r10, [fp, #-60]
	ldr r10, [fp, #-56]
	ldr r4, [fp, #-60]
	str r4, [fp, #-220]
	ldr r4, [fp, #-220]
	str r5, [r4, r10]
	mov r5, #0
	mov r10, #4
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	mov r10, r10
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	mul r5, r5, r10
	mov r10, r9
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	ldr r5, [r10, r5]
	mov r10, #1
	str r10, [fp, #-80]
	mov r10, #4
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	mov r10, r10
	str r10, [fp, #-84]
	ldr r10, [fp, #-80]
	ldr r4, [fp, #-84]
	str r4, [fp, #-224]
	ldr r4, [fp, #-224]
	mul r10, r10, r4
	str r10, [fp, #-88]
	ldr r10, [fp, #-256]
	mov r10, r10
	str r10, [fp, #-92]
	ldr r10, [fp, #-88]
	ldr r4, [fp, #-92]
	str r4, [fp, #-228]
	ldr r4, [fp, #-228]
	str r5, [r4, r10]
	mov r5, #0
	mov r10, #4
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	mov r10, r10
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	mul r5, r5, r10
	mov r10, r8
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	ldr r5, [r10, r5]
	mov r10, #2
	str r10, [fp, #-116]
	mov r10, #4
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	mov r10, r10
	str r10, [fp, #-112]
	ldr r10, [fp, #-112]
	ldr r4, [fp, #-116]
	str r4, [fp, #-232]
	ldr r4, [fp, #-232]
	mul r10, r4, r10
	str r10, [fp, #-120]
	ldr r10, [fp, #-256]
	mov r10, r10
	str r10, [fp, #-124]
	ldr r10, [fp, #-120]
	ldr r4, [fp, #-124]
	str r4, [fp, #-236]
	ldr r4, [fp, #-236]
	str r5, [r4, r10]
	mov r5, #1
	mov r10, #4
	str r10, [fp, #-128]
	ldr r10, [fp, #-128]
	mov r10, r10
	str r10, [fp, #-132]
	ldr r10, [fp, #-132]
	mul r5, r5, r10
	ldr r10, [fp, #-208]
	mov r10, r10
	str r10, [fp, #-136]
	ldr r10, [fp, #-136]
	ldr r5, [r10, r5]
	mov r10, #0
	str r10, [fp, #-144]
	mov r10, #4
	str r10, [fp, #-140]
	ldr r10, [fp, #-140]
	mov r10, r10
	str r10, [fp, #-148]
	ldr r10, [fp, #-144]
	ldr r4, [fp, #-148]
	str r4, [fp, #-240]
	ldr r4, [fp, #-240]
	mul r10, r10, r4
	str r10, [fp, #-152]
	mov r10, r7
	str r10, [fp, #-156]
	ldr r10, [fp, #-152]
	ldr r4, [fp, #-156]
	str r4, [fp, #-244]
	ldr r4, [fp, #-244]
	str r5, [r4, r10]
	mov r5, #2
	mov r10, #4
	str r10, [fp, #-160]
	ldr r10, [fp, #-160]
	mov r10, r10
	str r10, [fp, #-164]
	ldr r10, [fp, #-164]
	mul r5, r5, r10
	ldr r10, [fp, #-208]
	mov r10, r10
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	ldr r5, [r10, r5]
	mov r10, #0
	str r10, [fp, #-176]
	mov r10, #4
	str r10, [fp, #-172]
	ldr r10, [fp, #-172]
	mov r10, r10
	str r10, [fp, #-180]
	ldr r10, [fp, #-176]
	ldr r4, [fp, #-180]
	str r4, [fp, #-248]
	ldr r4, [fp, #-248]
	mul r10, r10, r4
	str r10, [fp, #-184]
	mov r10, r6
	str r10, [fp, #-188]
	ldr r10, [fp, #-184]
	ldr r4, [fp, #-188]
	str r4, [fp, #-252]
	ldr r4, [fp, #-252]
	str r5, [r4, r10]
	mov r5, #1
	mov r10, #4
	str r10, [fp, #-192]
	ldr r10, [fp, #-192]
	mov r10, r10
	str r10, [fp, #-196]
	ldr r10, [fp, #-196]
	mul r5, r5, r10
	mov r9, r9
	ldr r9, [r9, r5]
	mov r5, #1
	mov r10, #4
	str r10, [fp, #-200]
	ldr r10, [fp, #-200]
	mov r10, r10
	str r10, [fp, #-204]
	ldr r10, [fp, #-204]
	mul r5, r5, r10
	mov r7, r7
	str r9, [r7, r5]
	mov r9, #2
	mov r7, #4
	mov r7, r7
	mul r9, r9, r7
	mov r8, r8
	ldr r9, [r8, r9]
	mov r8, #2
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, r6
	str r9, [r7, r8]
	mov r9, #0
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	ldr r8, [fp, #-208]
	mov r8, r8
	ldr r9, [r8, r9]
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-256]
	mov r7, r7
	str r9, [r7, r8]
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007222"