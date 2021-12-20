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
.globl s
s:
.word 0

.globl get_ans
.type get_ans, %function
get_ans:
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
.LBget_ans:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, #0
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_get_ans1_ELSE
	b .LBB_get_ans1_IF
.LBB_get_ans1_IF:
	mov r6, #1
.LBB_get_ans1_ELSE:
	mov r8, #2
	mov r8, r8
	mul r9, r9, r8
	mov r9, r9
	mov r8, r6
	add r9, r9, r8
	mov r9, r9
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

.globl get_ans_se
.type get_ans_se, %function
get_ans_se:
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
.LBget_ans_se:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, #0
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_get_ans_se0_ELSE
	b .LBB_get_ans_se0_IF
.LBB_get_ans_se0_IF:
	mov r6, #1
.LBB_get_ans_se0_ELSE:
	mov r8, #2
	mov r8, r8
	mul r9, r9, r8
	mov r9, r9
	mov r8, r6
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov32 r8, s
	ldr r8, [r8, #0]
	mov r7, r9
	add r8, r8, r7
	mov r7, #0
	mov32 r7, s
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, s
	str r8, [r7, #0]
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
	mov r8, #248
	sub sp, sp, r8
.LBmain:
	str r9, [fp, #-248]
	mov r9, #0
	ldr r8, =#-2147483648
	sub r9, r9, r8
	mov r9, r9
	str r9, [fp, #-248]
	str r9, [fp, #-228]
	ldr r9, =#-2147483648
	str r9, [fp, #-228]
	ldr r8, =#-2147483648
	add r8, r8, #1
	mov r9, r8
	ldr r8, =#2147483647
	ldr r6, =#2147483647
	sub r6, r6, #1
	mov r7, r6
	ldr r6, [fp, #-248]
	mov r0, r6
	bl putint
	mov r6, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r6, r0
	add sp, sp, #0
	ldr r6, [fp, #-228]
	mov r0, r6
	bl putint
	mov r6, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r6, r0
	add sp, sp, #0
	mov r0, r9
	bl putint
	mov r6, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r6, r0
	add sp, sp, #0
	mov r0, r8
	bl putint
	mov r6, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r6, r0
	add sp, sp, #0
	mov r0, r7
	bl putint
	mov r6, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r6, r0
	add sp, sp, #0
	str r10, [fp, #-108]
	str r10, [fp, #-224]
	ldr r10, [fp, #-228]
	mov r2, r10
	ldr r10, [fp, #-248]
	mov r1, r10
	mov r0, #0
	bl get_ans
	mov r10, r0
	str r10, [fp, #-4]
	add sp, sp, #0
	ldr r10, [fp, #-4]
	mov r6, r10
	ldr r10, [fp, #-248]
	add r10, r10, #1
	str r10, [fp, #-4]
	mov r2, r9
	ldr r10, [fp, #-4]
	mov r1, r10
	mov r0, r6
	bl get_ans
	mov r6, r0
	add sp, sp, #0
	mov r6, r6
	mov r10, #0
	str r10, [fp, #-8]
	mov r10, r8
	str r10, [fp, #-12]
	ldr r10, [fp, #-8]
	ldr r4, [fp, #-12]
	str r4, [fp, #-236]
	ldr r4, [fp, #-236]
	sub r10, r10, r4
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	sub r10, r10, #1
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	mov r2, r10
	ldr r10, [fp, #-248]
	mov r1, r10
	mov r0, r6
	bl get_ans
	mov r6, r0
	add sp, sp, #0
	mov r6, r6
	add r10, r7, #1
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	mov r2, r10
	ldr r10, [fp, #-248]
	mov r1, r10
	mov r0, r6
	bl get_ans
	mov r6, r0
	add sp, sp, #0
	mov r6, r6
	mov r10, r0
	str r10, [fp, #-28]
	mov r10, r1
	str r10, [fp, #-32]
	ldr r10, [fp, #-228]
	mov r0, r10
	mov r1, #2
	bl __aeabi_idiv
	mov r10, r0
	str r10, [fp, #-48]
	ldr r10, [fp, #-28]
	mov r0, r10
	ldr r10, [fp, #-32]
	mov r1, r10
	mov r10, r0
	str r10, [fp, #-36]
	mov r10, r1
	str r10, [fp, #-40]
	mov r0, r9
	mov r1, #2
	bl __aeabi_idiv
	mov r10, r0
	str r10, [fp, #-44]
	ldr r10, [fp, #-36]
	mov r0, r10
	ldr r10, [fp, #-40]
	mov r1, r10
	ldr r10, [fp, #-44]
	mov r2, r10
	ldr r10, [fp, #-48]
	mov r1, r10
	mov r0, r6
	bl get_ans
	mov r6, r0
	add sp, sp, #0
	mov r6, r6
	mov r10, #0
	str r10, [fp, #-52]
	mov r10, r8
	str r10, [fp, #-56]
	ldr r10, [fp, #-52]
	ldr r4, [fp, #-56]
	str r4, [fp, #-236]
	ldr r4, [fp, #-236]
	sub r10, r10, r4
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	sub r10, r10, #1
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	mov r2, r10
	ldr r10, [fp, #-228]
	mov r1, r10
	mov r0, r6
	bl get_ans
	mov r6, r0
	add sp, sp, #0
	mov r6, r6
	add r10, r7, #1
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	mov r2, r10
	ldr r10, [fp, #-228]
	mov r1, r10
	mov r0, r6
	bl get_ans
	mov r6, r0
	add sp, sp, #0
	mov r6, r6
	mov r2, r8
	mov r1, r9
	mov r0, #0
	bl get_ans
	mov r10, r0
	str r10, [fp, #-72]
	add sp, sp, #0
	ldr r10, [fp, #-72]
	mov r5, r10
	mov r2, r7
	mov r1, r9
	mov r0, r5
	bl get_ans
	mov r5, r0
	add sp, sp, #0
	mov r5, r5
	mov r2, r7
	mov r1, r8
	mov r0, r5
	bl get_ans
	mov r5, r0
	add sp, sp, #0
	mov r5, r5
	mov r10, r0
	str r10, [fp, #-76]
	mov r10, r1
	str r10, [fp, #-80]
	ldr r10, [fp, #-248]
	mov r0, r10
	mov r1, #2
	bl __aeabi_idiv
	mov r10, r0
	str r10, [fp, #-96]
	ldr r10, [fp, #-76]
	mov r0, r10
	ldr r10, [fp, #-80]
	mov r1, r10
	mov r10, r0
	str r10, [fp, #-84]
	mov r10, r1
	str r10, [fp, #-88]
	ldr r10, [fp, #-228]
	mov r0, r10
	mov r1, #2
	bl __aeabi_idiv
	mov r10, r0
	str r10, [fp, #-92]
	ldr r10, [fp, #-84]
	mov r0, r10
	ldr r10, [fp, #-88]
	mov r1, r10
	ldr r10, [fp, #-92]
	mov r2, r10
	ldr r10, [fp, #-96]
	mov r1, r10
	mov r0, r5
	bl get_ans
	mov r5, r0
	add sp, sp, #0
	mov r5, r5
	ldr r10, [fp, #-228]
	mov r2, r10
	ldr r10, [fp, #-248]
	mov r1, r10
	mov r0, #0
	bl get_ans_se
	mov r10, r0
	str r10, [fp, #-100]
	add sp, sp, #0
	ldr r10, [fp, #-100]
	mov r10, r10
	str r10, [fp, #-108]
	ldr r10, [fp, #-248]
	add r10, r10, #1
	str r10, [fp, #-104]
	mov r2, r9
	ldr r10, [fp, #-104]
	mov r1, r10
	ldr r10, [fp, #-108]
	mov r0, r10
	bl get_ans_se
	mov r10, r0
	str r10, [fp, #-112]
	add sp, sp, #0
	ldr r10, [fp, #-112]
	mov r10, r10
	str r10, [fp, #-132]
	mov r10, #0
	str r10, [fp, #-116]
	mov r10, r8
	str r10, [fp, #-120]
	ldr r10, [fp, #-116]
	ldr r4, [fp, #-120]
	str r4, [fp, #-240]
	ldr r4, [fp, #-240]
	sub r10, r10, r4
	str r10, [fp, #-124]
	ldr r10, [fp, #-124]
	sub r10, r10, #1
	str r10, [fp, #-128]
	ldr r10, [fp, #-128]
	mov r2, r10
	ldr r10, [fp, #-248]
	mov r1, r10
	ldr r10, [fp, #-132]
	mov r0, r10
	bl get_ans_se
	mov r10, r0
	str r10, [fp, #-136]
	add sp, sp, #0
	ldr r10, [fp, #-136]
	mov r10, r10
	str r10, [fp, #-144]
	add r10, r7, #1
	str r10, [fp, #-140]
	ldr r10, [fp, #-140]
	mov r2, r10
	ldr r10, [fp, #-248]
	mov r1, r10
	ldr r10, [fp, #-144]
	mov r0, r10
	bl get_ans_se
	mov r10, r0
	str r10, [fp, #-148]
	add sp, sp, #0
	ldr r10, [fp, #-148]
	mov r10, r10
	str r10, [fp, #-176]
	mov r10, r0
	str r10, [fp, #-152]
	mov r10, r1
	str r10, [fp, #-156]
	ldr r10, [fp, #-228]
	mov r0, r10
	mov r1, #2
	bl __aeabi_idiv
	mov r10, r0
	str r10, [fp, #-172]
	ldr r10, [fp, #-152]
	mov r0, r10
	ldr r10, [fp, #-156]
	mov r1, r10
	mov r10, r0
	str r10, [fp, #-160]
	mov r10, r1
	str r10, [fp, #-164]
	mov r0, r9
	mov r1, #2
	bl __aeabi_idiv
	mov r10, r0
	str r10, [fp, #-168]
	ldr r10, [fp, #-160]
	mov r0, r10
	ldr r10, [fp, #-164]
	mov r1, r10
	ldr r10, [fp, #-168]
	mov r2, r10
	ldr r10, [fp, #-172]
	mov r1, r10
	ldr r10, [fp, #-176]
	mov r0, r10
	bl get_ans_se
	mov r10, r0
	str r10, [fp, #-180]
	add sp, sp, #0
	ldr r10, [fp, #-180]
	mov r10, r10
	str r10, [fp, #-200]
	mov r10, #0
	str r10, [fp, #-188]
	mov r10, r8
	str r10, [fp, #-184]
	ldr r10, [fp, #-184]
	ldr r4, [fp, #-188]
	str r4, [fp, #-244]
	ldr r4, [fp, #-244]
	sub r10, r4, r10
	str r10, [fp, #-192]
	ldr r10, [fp, #-192]
	sub r10, r10, #1
	str r10, [fp, #-196]
	ldr r10, [fp, #-196]
	mov r2, r10
	ldr r10, [fp, #-228]
	mov r1, r10
	ldr r10, [fp, #-200]
	mov r0, r10
	bl get_ans_se
	mov r10, r0
	str r10, [fp, #-204]
	add sp, sp, #0
	ldr r10, [fp, #-204]
	mov r10, r10
	str r10, [fp, #-212]
	add r10, r7, #1
	str r10, [fp, #-208]
	ldr r10, [fp, #-208]
	mov r2, r10
	ldr r10, [fp, #-228]
	mov r1, r10
	ldr r10, [fp, #-212]
	mov r0, r10
	bl get_ans_se
	mov r10, r0
	str r10, [fp, #-216]
	add sp, sp, #0
	ldr r10, [fp, #-216]
	mov r10, r10
	str r10, [fp, #-232]
	mov r2, r8
	mov r1, r9
	mov r0, #0
	bl get_ans_se
	mov r10, r0
	str r10, [fp, #-220]
	add sp, sp, #0
	ldr r10, [fp, #-220]
	mov r10, r10
	str r10, [fp, #-224]
	mov r2, r7
	mov r1, r9
	ldr r9, [fp, #-224]
	mov r0, r9
	bl get_ans_se
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r2, r7
	mov r1, r8
	mov r0, r9
	bl get_ans_se
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r8, r0
	mov r7, r1
	ldr r10, [fp, #-248]
	mov r0, r10
	mov r1, #2
	bl __aeabi_idiv
	mov r10, r0
	mov r0, r8
	mov r1, r7
	mov r8, r0
	mov r7, r1
	ldr r4, [fp, #-228]
	mov r0, r4
	mov r1, #2
	bl __aeabi_idiv
	mov r4, r0
	mov r0, r8
	mov r1, r7
	mov r2, r4
	mov r1, r10
	mov r0, r9
	bl get_ans_se
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r8, r5
	add r8, r6, r8
	ldr r7, [fp, #-232]
	mov r7, r7
	add r8, r8, r7
	mov r9, r9
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007397"