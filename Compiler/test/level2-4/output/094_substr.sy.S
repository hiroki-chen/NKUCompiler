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
.globl MAX
.type MAX, %function
MAX:
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
.LBMAX:
	mov r9, r0
	mov r8, r1
	cmp r9, r8
	mov r7, #0
	moveq r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_MAX0_ELSE
	b .LBB_MAX0_IF
.LBB_MAX0_IF:
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
.LBB_MAX0_ELSE:
	cmp r9, r8
	mov r7, #0
	movgt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_1_ELSE
	b .LBB_1_IF
.LBB_1_IF:
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
.LBB_1_ELSE:
	mov r0, r8
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

.globl longest_common_subseq
.type longest_common_subseq, %function
longest_common_subseq:
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
	mov r8, #300
	sub sp, sp, r8
.LBlongest_common_subseq:
	mov r9, r0
	str r9, [fp, #-240]
	mov r9, r1
	str r9, [fp, #-300]
	mov r9, r2
	mov r8, r3
	sub sp, sp, #1024
	mov r7, sp
	mov r0, r7
	mov r1, #0
	mov r2, #1024
	bl memset
	mov r7, #1
.LB_longest_common_subseq3_LOOP_BEGIN:
	ldr r5, [fp, #-300]
	cmp r7, r5
	mov r5, #0
	movle r5, #1
	mov r10, #0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	cmp r5, r10
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r6, #1
.LB_4_LOOP_BEGIN:
	cmp r6, r8
	mov r5, #0
	movle r5, #1
	mov r10, #0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	cmp r5, r10
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	sub r5, r7, #1
	mov r10, #4
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	mul r5, r5, r10
	ldr r10, [fp, #-240]
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	ldr r5, [r10, r5]
	sub r10, r6, #1
	str r10, [fp, #-28]
	mov r10, #4
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	ldr r4, [fp, #-28]
	str r4, [fp, #-244]
	ldr r4, [fp, #-244]
	mul r10, r4, r10
	str r10, [fp, #-36]
	mov r10, r9
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	ldr r4, [fp, #-36]
	str r4, [fp, #-244]
	ldr r4, [fp, #-244]
	ldr r10, [r10, r4]
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	cmp r5, r10
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	sub r5, r6, #1
	mov r10, #4
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	mul r5, r5, r10
	mov r10, #64
	str r10, [fp, #-60]
	sub r10, r7, #1
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	str r10, [fp, #-64]
	ldr r10, [fp, #-60]
	ldr r4, [fp, #-64]
	str r4, [fp, #-248]
	ldr r4, [fp, #-248]
	mul r10, r10, r4
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	add r5, r5, r10
	mov r10, sp
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	ldr r5, [r10, r5]
	add r5, r5, #1
	mov r10, #4
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	mul r10, r6, r10
	str r10, [fp, #-104]
	mov r10, #64
	str r10, [fp, #-88]
	mov r10, r7
	str r10, [fp, #-92]
	ldr r10, [fp, #-88]
	ldr r4, [fp, #-92]
	str r4, [fp, #-252]
	ldr r4, [fp, #-252]
	mul r10, r10, r4
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	ldr r4, [fp, #-104]
	str r4, [fp, #-256]
	ldr r4, [fp, #-256]
	add r10, r4, r10
	str r10, [fp, #-108]
	mov r10, sp
	str r10, [fp, #-112]
	ldr r10, [fp, #-112]
	str r10, [fp, #-112]
	ldr r10, [fp, #-108]
	ldr r4, [fp, #-112]
	str r4, [fp, #-260]
	ldr r4, [fp, #-260]
	str r5, [r4, r10]
	b .LBB_5_END_IF
.LBB_5_ELSE:
	mov r5, #4
	mul r5, r6, r5
	mov r10, #64
	str r10, [fp, #-120]
	sub r10, r7, #1
	str r10, [fp, #-116]
	ldr r10, [fp, #-116]
	str r10, [fp, #-124]
	ldr r10, [fp, #-120]
	ldr r4, [fp, #-124]
	str r4, [fp, #-264]
	ldr r4, [fp, #-264]
	mul r10, r10, r4
	str r10, [fp, #-128]
	ldr r10, [fp, #-128]
	str r10, [fp, #-132]
	ldr r10, [fp, #-132]
	add r5, r5, r10
	mov r10, sp
	str r10, [fp, #-136]
	ldr r10, [fp, #-136]
	str r10, [fp, #-136]
	ldr r10, [fp, #-136]
	ldr r5, [r10, r5]
	sub r10, r6, #1
	str r10, [fp, #-144]
	mov r10, #4
	str r10, [fp, #-140]
	ldr r10, [fp, #-140]
	str r10, [fp, #-148]
	ldr r10, [fp, #-144]
	ldr r4, [fp, #-148]
	str r4, [fp, #-268]
	ldr r4, [fp, #-268]
	mul r10, r10, r4
	str r10, [fp, #-168]
	mov r10, #64
	str r10, [fp, #-152]
	mov r10, r7
	str r10, [fp, #-156]
	ldr r10, [fp, #-152]
	ldr r4, [fp, #-156]
	str r4, [fp, #-272]
	ldr r4, [fp, #-272]
	mul r10, r10, r4
	str r10, [fp, #-160]
	ldr r10, [fp, #-160]
	str r10, [fp, #-164]
	ldr r10, [fp, #-164]
	ldr r4, [fp, #-168]
	str r4, [fp, #-276]
	ldr r4, [fp, #-276]
	add r10, r4, r10
	str r10, [fp, #-172]
	mov r10, sp
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	str r10, [fp, #-176]
	ldr r10, [fp, #-172]
	ldr r4, [fp, #-176]
	str r4, [fp, #-280]
	ldr r4, [fp, #-280]
	ldr r10, [r4, r10]
	str r10, [fp, #-180]
	ldr r10, [fp, #-180]
	mov r1, r10
	mov r0, r5
	bl MAX
	mov r5, r0
	mov r10, #4
	str r10, [fp, #-184]
	ldr r10, [fp, #-184]
	str r10, [fp, #-188]
	ldr r10, [fp, #-188]
	mul r10, r6, r10
	str r10, [fp, #-204]
	mov r10, #64
	str r10, [fp, #-192]
	mov r10, r7
	str r10, [fp, #-196]
	ldr r10, [fp, #-192]
	ldr r4, [fp, #-196]
	str r4, [fp, #-284]
	ldr r4, [fp, #-284]
	mul r10, r10, r4
	str r10, [fp, #-200]
	ldr r10, [fp, #-200]
	str r10, [fp, #-208]
	ldr r10, [fp, #-204]
	ldr r4, [fp, #-208]
	str r4, [fp, #-288]
	ldr r4, [fp, #-288]
	add r10, r10, r4
	str r10, [fp, #-212]
	mov r10, sp
	str r10, [fp, #-216]
	ldr r10, [fp, #-216]
	str r10, [fp, #-216]
	ldr r10, [fp, #-212]
	ldr r4, [fp, #-216]
	str r4, [fp, #-292]
	ldr r4, [fp, #-292]
	str r5, [r4, r10]
	b .LBB_5_END_IF
.LBB_5_END_IF:
	add r5, r6, #1
	mov r6, r5
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	add r5, r7, #1
	mov r7, r5
	b .LB_longest_common_subseq3_LOOP_BEGIN
.LB3_LOOP_END:
	mov r5, #4
	mul r5, r8, r5
	mov r10, #64
	str r10, [fp, #-220]
	ldr r10, [fp, #-300]
	str r10, [fp, #-224]
	ldr r10, [fp, #-220]
	ldr r4, [fp, #-224]
	str r4, [fp, #-296]
	ldr r4, [fp, #-296]
	mul r10, r10, r4
	str r10, [fp, #-228]
	ldr r10, [fp, #-228]
	str r10, [fp, #-232]
	ldr r10, [fp, #-232]
	add r5, r5, r10
	mov r10, sp
	str r10, [fp, #-236]
	ldr r10, [fp, #-236]
	str r10, [fp, #-236]
	ldr r10, [fp, #-236]
	ldr r5, [r10, r5]
	mov r0, r5
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
	sub sp, sp, #60
	mov r9, sp
	mov r0, r9
	mov r1, #0
	mov r2, #60
	bl memset
	mov r9, sp
	mov r8, #8
	str r8, [r9, #0]
	mov r9, sp
	mov r8, #7
	str r8, [r9, #4]
	mov r9, sp
	mov r8, #4
	str r8, [r9, #8]
	mov r9, sp
	mov r8, #1
	str r8, [r9, #12]
	mov r9, sp
	mov r8, #2
	str r8, [r9, #16]
	mov r9, sp
	mov r8, #7
	str r8, [r9, #20]
	mov r9, sp
	mov r8, #0
	str r8, [r9, #24]
	mov r9, sp
	mov r8, #1
	str r8, [r9, #28]
	mov r9, sp
	mov r8, #9
	str r8, [r9, #32]
	mov r9, sp
	mov r8, #3
	str r8, [r9, #36]
	mov r9, sp
	mov r8, #4
	str r8, [r9, #40]
	mov r9, sp
	mov r8, #8
	str r8, [r9, #44]
	mov r9, sp
	mov r8, #3
	str r8, [r9, #48]
	mov r9, sp
	mov r8, #7
	str r8, [r9, #52]
	mov r9, sp
	mov r8, #0
	str r8, [r9, #56]
	sub sp, sp, #52
	mov r9, sp
	mov r0, r9
	mov r1, #0
	mov r2, #52
	bl memset
	mov r9, sp
	mov r8, #3
	str r8, [r9, #0]
	mov r9, sp
	mov r8, #9
	str r8, [r9, #4]
	mov r9, sp
	mov r8, #7
	str r8, [r9, #8]
	mov r9, sp
	mov r8, #1
	str r8, [r9, #12]
	mov r9, sp
	mov r8, #4
	str r8, [r9, #16]
	mov r9, sp
	mov r8, #2
	str r8, [r9, #20]
	mov r9, sp
	mov r8, #4
	str r8, [r9, #24]
	mov r9, sp
	mov r8, #3
	str r8, [r9, #28]
	mov r9, sp
	mov r8, #6
	str r8, [r9, #32]
	mov r9, sp
	mov r8, #8
	str r8, [r9, #36]
	mov r9, sp
	mov r8, #0
	str r8, [r9, #40]
	mov r9, sp
	mov r8, #1
	str r8, [r9, #44]
	mov r9, sp
	mov r8, #5
	str r8, [r9, #48]
	mov r1, #15
	add r9, sp, #52
	mov r0, r9
	bl max_sum_nonadjacent
	mov r9, r0
	mov r0, r9
	bl putint
	mov r9, r0
	mov r0, #10
	bl putch
	mov r9, r0
	mov r3, #13
	mov r2, r9
	mov r1, #15
	add r9, sp, #52
	mov r0, r9
	bl longest_common_subseq
	mov r9, r0
	mov r0, r9
	bl putint
	mov r9, r0
	mov r0, #10
	bl putch
	mov r9, r0
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

.globl max_sum_nonadjacent
.type max_sum_nonadjacent, %function
max_sum_nonadjacent:
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
.LBmax_sum_nonadjacent:
	mov r9, r0
	mov r8, r1
	sub sp, sp, #64
	mov r7, sp
	mov r0, r7
	mov r1, #0
	mov r2, #64
	bl memset
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, sp
	str r7, [r5, r6]
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r1, r6
	mov r0, r7
	bl MAX
	mov r7, r0
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, sp
	str r7, [r5, r6]
	mov r7, #2
.LB_max_sum_nonadjacent2_LOOP_BEGIN:
	cmp r7, r8
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	sub r6, r7, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, sp
	ldr r6, [r5, r6]
	mov r5, #4
	mul r5, r7, r5
	mov r10, r9
	ldr r5, [r10, r5]
	add r6, r6, r5
	sub r5, r7, #1
	mov r10, #4
	mul r5, r5, r10
	mov r10, sp
	ldr r5, [r10, r5]
	mov r1, r5
	mov r0, r6
	bl MAX
	mov r6, r0
	mov r5, #4
	mul r5, r7, r5
	mov r10, sp
	str r6, [r10, r5]
	add r6, r7, #1
	mov r7, r6
	b .LB_max_sum_nonadjacent2_LOOP_BEGIN
.LB2_LOOP_END:
	sub r9, r8, #1
	mov r8, #4
	mul r9, r9, r8
	mov r8, sp
	ldr r9, [r8, r9]
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640004946"