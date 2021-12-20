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
.globl INF
INF:
.word 1879048192

.globl size
size:
.space 40

.globl to
to:
.space 400

.globl cap
cap:
.space 400

.globl rev
rev:
.space 400

.globl used
used:
.space 40

.globl add_node
.type add_node, %function
add_node:
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
.LBadd_node:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, #4
	mov r6, r6
	mul r6, r9, r6
	mov r5, #0
	mov32 r5, size
	ldr r6, [r5, r6]
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #40
	mov r10, r9
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, #0
	mov32 r5, to
	str r8, [r5, r6]
	mov r6, #4
	mov r6, r6
	mul r6, r9, r6
	mov r5, #0
	mov32 r5, size
	ldr r6, [r5, r6]
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #40
	mov r10, r9
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, #0
	mov32 r5, cap
	str r7, [r5, r6]
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, #0
	mov32 r6, size
	ldr r7, [r6, r7]
	mov r6, #4
	mov r6, r6
	mul r6, r9, r6
	mov r5, #0
	mov32 r5, size
	ldr r6, [r5, r6]
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #40
	mov r10, r9
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, #0
	mov32 r5, rev
	str r7, [r5, r6]
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, #0
	mov32 r6, size
	ldr r7, [r6, r7]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #40
	mov r5, r8
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, to
	str r9, [r6, r7]
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, #0
	mov32 r6, size
	ldr r7, [r6, r7]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #40
	mov r5, r8
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, cap
	mov r5, #0
	str r5, [r6, r7]
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, #0
	mov32 r6, size
	ldr r7, [r6, r7]
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, #0
	mov32 r5, size
	ldr r6, [r5, r6]
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #40
	mov r10, r8
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, #0
	mov32 r5, rev
	str r7, [r5, r6]
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, #0
	mov32 r6, size
	ldr r7, [r6, r7]
	add r7, r7, #1
	mov r6, #4
	mov r6, r6
	mul r9, r9, r6
	mov r6, #0
	mov32 r6, size
	str r7, [r6, r9]
	mov r9, #4
	mov r9, r9
	mul r9, r8, r9
	mov r7, #0
	mov32 r7, size
	ldr r9, [r7, r9]
	add r9, r9, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, size
	str r9, [r7, r8]
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

.globl dfs
.type dfs, %function
dfs:
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
	mov r8, #380
	sub sp, sp, r8
.LBdfs:
	mov r9, r0
	str r9, [fp, #-300]
	mov r9, r1
	str r9, [fp, #-380]
	mov r9, r2
	ldr r8, [fp, #-300]
	ldr r7, [fp, #-380]
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_dfs1_ELSE
	b .LBB_dfs1_IF
.LBB_dfs1_IF:
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
.LBB_dfs1_ELSE:
	mov r8, #4
	mov r8, r8
	ldr r7, [fp, #-300]
	mul r8, r7, r8
	mov r7, #0
	mov32 r7, used
	mov r6, #1
	str r6, [r7, r8]
	mov r8, #0
.LB_dfs2_LOOP_BEGIN:
	mov r7, #4
	mov r7, r7
	ldr r6, [fp, #-300]
	mul r7, r6, r7
	mov r6, #0
	mov32 r6, size
	ldr r7, [r6, r7]
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
	mov r6, #40
	ldr r5, [fp, #-300]
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, to
	ldr r7, [r6, r7]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, used
	ldr r7, [r6, r7]
	mov r6, #0
	cmp r7, r6
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	add r7, r8, #1
	mov r8, r7
	b .LB2_LOOP_CONTINUE
.LBB_3_ELSE:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, #40
	ldr r5, [fp, #-300]
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, cap
	ldr r7, [r6, r7]
	mov r6, #0
	cmp r7, r6
	mov r7, #0
	movle r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_4_ELSE
	b .LBB_4_IF
.LBB_4_IF:
	add r7, r8, #1
	mov r8, r7
	b .LB2_LOOP_CONTINUE
.LBB_4_ELSE:
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, #40
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, #0
	mov32 r5, cap
	ldr r6, [r5, r6]
	cmp r9, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	mov r7, r9
	b .LBB_5_END_IF
.LBB_5_ELSE:
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, #40
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, #0
	mov32 r5, cap
	ldr r6, [r5, r6]
	mov r7, r6
	b .LBB_5_END_IF
.LBB_5_END_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	mov r10, #40
	str r10, [fp, #-8]
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-12]
	ldr r10, [fp, #-8]
	ldr r4, [fp, #-12]
	str r4, [fp, #-304]
	ldr r4, [fp, #-304]
	mul r10, r10, r4
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	mov r10, r10
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, to
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	ldr r5, [r10, r5]
	mov r2, r7
	ldr r10, [fp, #-380]
	mov r1, r10
	mov r0, r5
	bl dfs
	mov r5, r0
	add sp, sp, #0
	mov r6, r5
	mov r5, #0
	cmp r6, r5
	mov r5, #0
	movgt r5, #1
	mov r10, #0
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	cmp r5, r10
	beq .LBB_6_ELSE
	b .LBB_6_IF
.LBB_6_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	mov r10, #40
	str r10, [fp, #-32]
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-36]
	ldr r10, [fp, #-32]
	ldr r4, [fp, #-36]
	str r4, [fp, #-304]
	ldr r4, [fp, #-304]
	mul r10, r10, r4
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	mov r10, r10
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, cap
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	ldr r5, [r10, r5]
	mov r10, r6
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	sub r5, r5, r10
	mov r10, #4
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	mov r10, r10
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	mul r10, r8, r10
	str r10, [fp, #-76]
	mov r10, #40
	str r10, [fp, #-64]
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-68]
	ldr r10, [fp, #-64]
	ldr r4, [fp, #-68]
	str r4, [fp, #-308]
	ldr r4, [fp, #-308]
	mul r10, r10, r4
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	mov r10, r10
	str r10, [fp, #-80]
	ldr r10, [fp, #-76]
	ldr r4, [fp, #-80]
	str r4, [fp, #-312]
	ldr r4, [fp, #-312]
	add r10, r10, r4
	str r10, [fp, #-84]
	mov r10, #0
	mov32 r10, cap
	str r10, [fp, #-88]
	ldr r10, [fp, #-84]
	ldr r4, [fp, #-88]
	str r4, [fp, #-316]
	ldr r4, [fp, #-316]
	str r5, [r4, r10]
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	mov r10, #40
	str r10, [fp, #-92]
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-96]
	ldr r10, [fp, #-92]
	ldr r4, [fp, #-96]
	str r4, [fp, #-320]
	ldr r4, [fp, #-320]
	mul r10, r10, r4
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	mov r10, r10
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, rev
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-112]
	ldr r10, [fp, #-112]
	mov r10, r10
	str r10, [fp, #-116]
	ldr r10, [fp, #-116]
	mul r5, r5, r10
	mov r10, #40
	str r10, [fp, #-160]
	mov r10, #4
	str r10, [fp, #-120]
	ldr r10, [fp, #-120]
	mov r10, r10
	str r10, [fp, #-124]
	ldr r10, [fp, #-124]
	mul r10, r8, r10
	str r10, [fp, #-144]
	mov r10, #40
	str r10, [fp, #-128]
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-132]
	ldr r10, [fp, #-128]
	ldr r4, [fp, #-132]
	str r4, [fp, #-324]
	ldr r4, [fp, #-324]
	mul r10, r10, r4
	str r10, [fp, #-136]
	ldr r10, [fp, #-136]
	mov r10, r10
	str r10, [fp, #-140]
	ldr r10, [fp, #-140]
	ldr r4, [fp, #-144]
	str r4, [fp, #-328]
	ldr r4, [fp, #-328]
	add r10, r4, r10
	str r10, [fp, #-148]
	mov r10, #0
	mov32 r10, to
	str r10, [fp, #-152]
	ldr r10, [fp, #-148]
	ldr r4, [fp, #-152]
	str r4, [fp, #-332]
	ldr r4, [fp, #-332]
	ldr r10, [r4, r10]
	str r10, [fp, #-156]
	ldr r10, [fp, #-156]
	mov r10, r10
	str r10, [fp, #-164]
	ldr r10, [fp, #-160]
	ldr r4, [fp, #-164]
	str r4, [fp, #-336]
	ldr r4, [fp, #-336]
	mul r10, r10, r4
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	mov r10, r10
	str r10, [fp, #-172]
	ldr r10, [fp, #-172]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, cap
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	ldr r5, [r10, r5]
	mov r10, r6
	str r10, [fp, #-180]
	ldr r10, [fp, #-180]
	add r5, r5, r10
	mov r10, #4
	str r10, [fp, #-184]
	ldr r10, [fp, #-184]
	mov r10, r10
	str r10, [fp, #-188]
	ldr r10, [fp, #-188]
	mul r10, r8, r10
	str r10, [fp, #-204]
	mov r10, #40
	str r10, [fp, #-192]
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-196]
	ldr r10, [fp, #-192]
	ldr r4, [fp, #-196]
	str r4, [fp, #-340]
	ldr r4, [fp, #-340]
	mul r10, r10, r4
	str r10, [fp, #-200]
	ldr r10, [fp, #-200]
	mov r10, r10
	str r10, [fp, #-208]
	ldr r10, [fp, #-204]
	ldr r4, [fp, #-208]
	str r4, [fp, #-344]
	ldr r4, [fp, #-344]
	add r10, r10, r4
	str r10, [fp, #-212]
	mov r10, #0
	mov32 r10, rev
	str r10, [fp, #-216]
	ldr r10, [fp, #-212]
	ldr r4, [fp, #-216]
	str r4, [fp, #-348]
	ldr r4, [fp, #-348]
	ldr r10, [r4, r10]
	str r10, [fp, #-224]
	mov r10, #4
	str r10, [fp, #-220]
	ldr r10, [fp, #-220]
	mov r10, r10
	str r10, [fp, #-228]
	ldr r10, [fp, #-224]
	ldr r4, [fp, #-228]
	str r4, [fp, #-352]
	ldr r4, [fp, #-352]
	mul r10, r10, r4
	str r10, [fp, #-284]
	mov r10, #40
	str r10, [fp, #-276]
	mov r10, #4
	str r10, [fp, #-232]
	ldr r10, [fp, #-232]
	mov r10, r10
	str r10, [fp, #-236]
	ldr r10, [fp, #-236]
	mul r10, r8, r10
	str r10, [fp, #-256]
	mov r10, #40
	str r10, [fp, #-244]
	ldr r10, [fp, #-300]
	mov r10, r10
	str r10, [fp, #-240]
	ldr r10, [fp, #-240]
	ldr r4, [fp, #-244]
	str r4, [fp, #-356]
	ldr r4, [fp, #-356]
	mul r10, r4, r10
	str r10, [fp, #-248]
	ldr r10, [fp, #-248]
	mov r10, r10
	str r10, [fp, #-252]
	ldr r10, [fp, #-252]
	ldr r4, [fp, #-256]
	str r4, [fp, #-360]
	ldr r4, [fp, #-360]
	add r10, r4, r10
	str r10, [fp, #-260]
	mov r10, #0
	mov32 r10, to
	str r10, [fp, #-264]
	ldr r10, [fp, #-260]
	ldr r4, [fp, #-264]
	str r4, [fp, #-364]
	ldr r4, [fp, #-364]
	ldr r10, [r4, r10]
	str r10, [fp, #-268]
	ldr r10, [fp, #-268]
	mov r10, r10
	str r10, [fp, #-272]
	ldr r10, [fp, #-272]
	ldr r4, [fp, #-276]
	str r4, [fp, #-368]
	ldr r4, [fp, #-368]
	mul r10, r4, r10
	str r10, [fp, #-280]
	ldr r10, [fp, #-280]
	mov r10, r10
	str r10, [fp, #-288]
	ldr r10, [fp, #-284]
	ldr r4, [fp, #-288]
	str r4, [fp, #-372]
	ldr r4, [fp, #-372]
	add r10, r10, r4
	str r10, [fp, #-292]
	mov r10, #0
	mov32 r10, cap
	str r10, [fp, #-296]
	ldr r10, [fp, #-292]
	ldr r4, [fp, #-296]
	str r4, [fp, #-376]
	ldr r4, [fp, #-376]
	str r5, [r4, r10]
	mov r0, r6
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
.LBB_6_ELSE:
	add r6, r8, #1
	mov r8, r6
.LB2_LOOP_CONTINUE:
	b .LB_dfs2_LOOP_BEGIN
.LB2_LOOP_END:
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
	bl getint
	mov r7, r0
	add sp, sp, #0
	mov r9, r7
	bl getint
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
	mov r2, #10
	mov r1, #0
	mov r7, #0
	mov32 r7, size
	mov r0, r7
	bl my_memset
	mov r7, r0
	add sp, sp, #0
.LB_main9_LOOP_BEGIN:
	mov r7, #0
	cmp r8, r7
	mov r7, #0
	movgt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB9_LOOP_END
	b .LB9_LOOP_BODY
.LB9_LOOP_BODY:
	bl getint
	mov r5, r0
	add sp, sp, #0
	mov r7, r5
	bl getint
	mov r5, r0
	add sp, sp, #0
	mov r6, r5
	bl getint
	mov r10, r0
	add sp, sp, #0
	mov r5, r10
	mov r2, r5
	mov r1, r6
	mov r0, r7
	bl add_node
	mov r7, r0
	add sp, sp, #0
	sub r7, r8, #1
	mov r8, r7
	b .LB_main9_LOOP_BEGIN
.LB9_LOOP_END:
	mov r1, r9
	mov r0, #1
	bl max_flow
	mov r9, r0
	add sp, sp, #0
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
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

.globl max_flow
.type max_flow, %function
max_flow:
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
.LBmax_flow:
	mov r9, r0
	mov r8, r1
	mov r7, #0
.LB_max_flow7_LOOP_BEGIN:
	mov r6, #1
	cmp r6, #0
	beq .LB7_LOOP_END
	b .LB7_LOOP_BODY
.LB7_LOOP_BODY:
	mov r2, #10
	mov r1, #0
	mov r6, #0
	mov32 r6, used
	mov r0, r6
	bl my_memset
	mov r6, r0
	add sp, sp, #0
	mov r5, #0
	mov32 r5, INF
	ldr r5, [r5, #0]
	mov r2, r5
	mov r1, r8
	mov r0, r9
	bl dfs
	mov r5, r0
	add sp, sp, #0
	mov r6, r5
	mov r5, #0
	cmp r6, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_8_ELSE
	b .LBB_8_IF
.LBB_8_IF:
	mov r0, r7
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
.LBB_8_ELSE:
	mov r6, r6
	add r6, r7, r6
	mov r7, r6
	b .LB_max_flow7_LOOP_BEGIN
.LB7_LOOP_END:
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

.globl my_memset
.type my_memset, %function
my_memset:
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
.LBmy_memset:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, #0
.LB_my_memset0_LOOP_BEGIN:
	cmp r6, r7
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
	str r8, [r10, r5]
	add r5, r6, #1
	mov r6, r5
	b .LB_my_memset0_LOOP_BEGIN
.LB0_LOOP_END:
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