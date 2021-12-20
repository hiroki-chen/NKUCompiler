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
	mov r8, #244
	sub sp, sp, r8
.LBmain:
	str r10, [fp, #-244]
	str r10, [fp, #-140]
	str r10, [fp, #-144]
	str r10, [fp, #-148]
	str r10, [fp, #-152]
	str r10, [fp, #-156]
	str r10, [fp, #-160]
	str r10, [fp, #-164]
	str r10, [fp, #-168]
	str r10, [fp, #-172]
	str r10, [fp, #-176]
	str r10, [fp, #-180]
	str r10, [fp, #-184]
	str r10, [fp, #-188]
	str r10, [fp, #-192]
	str r10, [fp, #-196]
	str r10, [fp, #-200]
	str r10, [fp, #-204]
	str r10, [fp, #-208]
	str r10, [fp, #-212]
	str r10, [fp, #-236]
	str r10, [fp, #-216]
	str r10, [fp, #-220]
	str r10, [fp, #-224]
	str r10, [fp, #-228]
	str r10, [fp, #-232]
	bl getint
	mov r10, r0
	str r10, [fp, #-4]
	add sp, sp, #0
	ldr r10, [fp, #-4]
	mov r10, r10
	str r10, [fp, #-232]
.LB_main0_LOOP_BEGIN:
	mov r10, #5
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r4, [fp, #-232]
	str r4, [fp, #-240]
	ldr r4, [fp, #-240]
	cmp r4, r10
	mov r10, #0
	moveq r10, #1
	str r10, [fp, #-12]
	mov r10, #0
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	ldr r4, [fp, #-12]
	str r4, [fp, #-240]
	ldr r4, [fp, #-240]
	cmp r4, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	ldr r10, [fp, #-232]
	add r10, r10, #1
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	mov r10, r10
	str r10, [fp, #-232]
	b .LB_main0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r9, #0
	add r10, r9, #1
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	mov r8, r10
	add r10, r8, #1
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	mov r7, r10
	add r10, r7, #1
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	mov r6, r10
	add r10, r6, #1
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	mov r5, r10
	add r10, r5, #1
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	mov r10, r10
	str r10, [fp, #-244]
	ldr r10, [fp, #-244]
	add r10, r10, #1
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	mov r10, r10
	str r10, [fp, #-140]
	ldr r10, [fp, #-140]
	add r10, r10, #1
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	mov r10, r10
	str r10, [fp, #-144]
	ldr r10, [fp, #-144]
	add r10, r10, #1
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	mov r10, r10
	str r10, [fp, #-148]
	ldr r10, [fp, #-148]
	add r10, r10, #1
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	mov r10, r10
	str r10, [fp, #-152]
	ldr r10, [fp, #-152]
	add r10, r10, #1
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	mov r10, r10
	str r10, [fp, #-156]
	ldr r10, [fp, #-156]
	add r10, r10, #1
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	mov r10, r10
	str r10, [fp, #-160]
	ldr r10, [fp, #-160]
	add r10, r10, #1
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	mov r10, r10
	str r10, [fp, #-164]
	ldr r10, [fp, #-164]
	add r10, r10, #1
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	mov r10, r10
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	add r10, r10, #1
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	mov r10, r10
	str r10, [fp, #-172]
	ldr r10, [fp, #-172]
	add r10, r10, #1
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	mov r10, r10
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	add r10, r10, #1
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	mov r10, r10
	str r10, [fp, #-180]
	ldr r10, [fp, #-180]
	add r10, r10, #1
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	mov r10, r10
	str r10, [fp, #-184]
	ldr r10, [fp, #-184]
	add r10, r10, #1
	str r10, [fp, #-88]
	ldr r10, [fp, #-88]
	mov r10, r10
	str r10, [fp, #-188]
	ldr r10, [fp, #-188]
	add r10, r10, #1
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	mov r10, r10
	str r10, [fp, #-192]
	ldr r10, [fp, #-192]
	add r10, r10, #1
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	mov r10, r10
	str r10, [fp, #-196]
	ldr r10, [fp, #-196]
	add r10, r10, #1
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	mov r10, r10
	str r10, [fp, #-200]
	ldr r10, [fp, #-200]
	add r10, r10, #1
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	mov r10, r10
	str r10, [fp, #-204]
	ldr r10, [fp, #-204]
	add r10, r10, #1
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	mov r10, r10
	str r10, [fp, #-208]
	ldr r10, [fp, #-208]
	add r10, r10, #1
	str r10, [fp, #-112]
	ldr r10, [fp, #-112]
	mov r10, r10
	str r10, [fp, #-212]
	ldr r10, [fp, #-212]
	add r10, r10, #1
	str r10, [fp, #-116]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-236]
	ldr r10, [fp, #-236]
	add r10, r10, #1
	str r10, [fp, #-120]
	ldr r10, [fp, #-120]
	mov r10, r10
	str r10, [fp, #-216]
	ldr r10, [fp, #-216]
	add r10, r10, #1
	str r10, [fp, #-124]
	ldr r10, [fp, #-124]
	mov r10, r10
	str r10, [fp, #-220]
	ldr r10, [fp, #-220]
	add r10, r10, #1
	str r10, [fp, #-128]
	ldr r10, [fp, #-128]
	mov r10, r10
	str r10, [fp, #-224]
	ldr r10, [fp, #-224]
	add r10, r10, #1
	str r10, [fp, #-132]
	ldr r10, [fp, #-132]
	mov r10, r10
	str r10, [fp, #-228]
	str r10, [fp, #-136]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, r8
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, r7
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, r6
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, r5
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-244]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-140]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-144]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-148]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-152]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-156]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-160]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-164]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-168]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-172]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-176]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-180]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-184]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-188]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-192]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-196]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-200]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-204]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-208]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-212]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-236]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-216]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-220]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-224]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-228]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r9, #10
	mov r0, r9
	bl putch
	mov r8, r0
	add sp, sp, #0
	ldr r8, [fp, #-232]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, r9
	bl putch
	mov r9, r0
	add sp, sp, #0
	ldr r9, [fp, #-236]
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007223"