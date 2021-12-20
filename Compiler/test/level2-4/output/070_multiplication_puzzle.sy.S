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
.globl a
a:
.word 10
.word 1
.word 50
.word 50
.word 20
.word 5

.globl dp
dp:
.space 400

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
	mov r8, #308
	sub sp, sp, r8
.LBmain:
	str r9, [fp, #-252]
	mov r9, #6
	str r9, [fp, #-252]
	str r9, [fp, #-308]
	mov r5, #3
	str r5, [fp, #-308]
.LB_main0_LOOP_BEGIN:
	ldr r5, [fp, #-252]
	ldr r10, [fp, #-308]
	cmp r10, r5
	mov r5, #0
	movle r5, #1
	mov r10, #0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	cmp r5, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r9, #0
.LB_1_LOOP_BEGIN:
	ldr r5, [fp, #-308]
	mov r5, r5
	ldr r10, [fp, #-252]
	sub r5, r10, r5
	add r5, r5, #1
	cmp r9, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	ldr r5, [fp, #-308]
	mov r5, r5
	add r5, r9, r5
	sub r5, r5, #1
	mov r7, r5
	add r5, r9, #1
	mov r8, r5
.LB_2_LOOP_BEGIN:
	cmp r8, r7
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	cmp r5, r10
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	mov r10, #40
	str r10, [fp, #-16]
	mov r10, r9
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	ldr r4, [fp, #-16]
	str r4, [fp, #-256]
	ldr r4, [fp, #-256]
	mul r10, r4, r10
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	mov r10, r10
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, dp
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	mov r10, r10
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	mul r10, r7, r10
	str r10, [fp, #-56]
	mov r10, #40
	str r10, [fp, #-40]
	mov r10, r8
	str r10, [fp, #-44]
	ldr r10, [fp, #-40]
	ldr r4, [fp, #-44]
	str r4, [fp, #-256]
	ldr r4, [fp, #-256]
	mul r10, r10, r4
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	mov r10, r10
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	ldr r4, [fp, #-56]
	str r4, [fp, #-260]
	ldr r4, [fp, #-260]
	add r10, r4, r10
	str r10, [fp, #-60]
	mov r10, #0
	mov32 r10, dp
	str r10, [fp, #-64]
	ldr r10, [fp, #-60]
	ldr r4, [fp, #-64]
	str r4, [fp, #-264]
	ldr r4, [fp, #-264]
	ldr r10, [r4, r10]
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	mov r10, r10
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	add r5, r5, r10
	mov r10, #4
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	mov r10, r10
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	mul r10, r9, r10
	str r10, [fp, #-84]
	mov r10, #0
	mov32 r10, a
	str r10, [fp, #-88]
	ldr r10, [fp, #-84]
	ldr r4, [fp, #-88]
	str r4, [fp, #-268]
	ldr r4, [fp, #-268]
	ldr r10, [r4, r10]
	str r10, [fp, #-116]
	mov r10, #4
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	mov r10, r10
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	mul r10, r8, r10
	str r10, [fp, #-100]
	mov r10, #0
	mov32 r10, a
	str r10, [fp, #-104]
	ldr r10, [fp, #-100]
	ldr r4, [fp, #-104]
	str r4, [fp, #-272]
	ldr r4, [fp, #-272]
	ldr r10, [r4, r10]
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	mov r10, r10
	str r10, [fp, #-112]
	ldr r10, [fp, #-112]
	ldr r4, [fp, #-116]
	str r4, [fp, #-276]
	ldr r4, [fp, #-276]
	mul r10, r4, r10
	str r10, [fp, #-144]
	mov r10, #4
	str r10, [fp, #-120]
	ldr r10, [fp, #-120]
	mov r10, r10
	str r10, [fp, #-124]
	ldr r10, [fp, #-124]
	mul r10, r7, r10
	str r10, [fp, #-128]
	mov r10, #0
	mov32 r10, a
	str r10, [fp, #-132]
	ldr r10, [fp, #-128]
	ldr r4, [fp, #-132]
	str r4, [fp, #-280]
	ldr r4, [fp, #-280]
	ldr r10, [r4, r10]
	str r10, [fp, #-136]
	ldr r10, [fp, #-136]
	mov r10, r10
	str r10, [fp, #-140]
	ldr r10, [fp, #-140]
	ldr r4, [fp, #-144]
	str r4, [fp, #-284]
	ldr r4, [fp, #-284]
	mul r10, r4, r10
	str r10, [fp, #-148]
	ldr r10, [fp, #-148]
	mov r10, r10
	str r10, [fp, #-152]
	ldr r10, [fp, #-152]
	add r5, r5, r10
	mov r6, r5
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, #40
	str r10, [fp, #-156]
	mov r10, r9
	str r10, [fp, #-160]
	ldr r10, [fp, #-156]
	ldr r4, [fp, #-160]
	str r4, [fp, #-288]
	ldr r4, [fp, #-288]
	mul r10, r10, r4
	str r10, [fp, #-164]
	ldr r10, [fp, #-164]
	mov r10, r10
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, dp
	str r10, [fp, #-172]
	ldr r10, [fp, #-172]
	ldr r5, [r10, r5]
	mov r10, #0
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	cmp r10, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	str r10, [fp, #-180]
	ldr r10, [fp, #-180]
	cmp r5, r10
	mov r5, #1
	bne .LB41_COND_END
	mov r10, #4
	str r10, [fp, #-184]
	ldr r10, [fp, #-184]
	mov r10, r10
	str r10, [fp, #-188]
	ldr r10, [fp, #-188]
	mul r10, r7, r10
	str r10, [fp, #-204]
	mov r10, #40
	str r10, [fp, #-192]
	mov r10, r9
	str r10, [fp, #-196]
	ldr r10, [fp, #-192]
	ldr r4, [fp, #-196]
	str r4, [fp, #-292]
	ldr r4, [fp, #-292]
	mul r10, r10, r4
	str r10, [fp, #-200]
	ldr r10, [fp, #-200]
	mov r10, r10
	str r10, [fp, #-208]
	ldr r10, [fp, #-204]
	ldr r4, [fp, #-208]
	str r4, [fp, #-296]
	ldr r4, [fp, #-296]
	add r10, r10, r4
	str r10, [fp, #-212]
	mov r10, #0
	mov32 r10, dp
	str r10, [fp, #-216]
	ldr r10, [fp, #-212]
	ldr r4, [fp, #-216]
	str r4, [fp, #-300]
	ldr r4, [fp, #-300]
	ldr r10, [r4, r10]
	str r10, [fp, #-220]
	ldr r10, [fp, #-220]
	cmp r6, r10
	mov r10, #0
	movlt r10, #1
	str r10, [fp, #-224]
	ldr r10, [fp, #-224]
	mov r5, r10
.LB41_COND_END:
	mov r10, #0
	str r10, [fp, #-228]
	ldr r10, [fp, #-228]
	cmp r5, r10
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, #40
	str r10, [fp, #-232]
	mov r10, r9
	str r10, [fp, #-236]
	ldr r10, [fp, #-232]
	ldr r4, [fp, #-236]
	str r4, [fp, #-304]
	ldr r4, [fp, #-304]
	mul r10, r10, r4
	str r10, [fp, #-240]
	ldr r10, [fp, #-240]
	mov r10, r10
	str r10, [fp, #-244]
	ldr r10, [fp, #-244]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, dp
	str r10, [fp, #-248]
	ldr r10, [fp, #-248]
	str r6, [r10, r5]
.LBB_3_ELSE:
	add r5, r8, #1
	mov r8, r5
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	add r5, r9, #1
	mov r9, r5
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	ldr r5, [fp, #-308]
	add r5, r5, #1
	mov r5, r5
	str r5, [fp, #-308]
	b .LB_main0_LOOP_BEGIN
.LB0_LOOP_END:
	ldr r9, [fp, #-252]
	sub r9, r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #40
	mov r7, #0
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, #0
	mov32 r8, dp
	ldr r9, [r8, r9]
	mov r0, r9
	bl putint
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007222"