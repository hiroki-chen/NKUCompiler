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
.globl map
map:
.space 400

.globl indegree
indegree:
.space 40

.globl queue
queue:
.space 40

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
	mov r7, #1
	mov r9, #5
.LB_main6_LOOP_BEGIN:
	cmp r7, r9
	mov r6, #0
	movle r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB6_LOOP_END
	b .LB6_LOOP_BODY
.LB6_LOOP_BODY:
	bl getint
	mov r6, r0
	add sp, sp, #0
	mov r8, r6
.LB_7_LOOP_BEGIN:
	mov r6, #0
	cmp r8, r6
	mov r6, #0
	movne r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB7_LOOP_END
	b .LB7_LOOP_BODY
.LB7_LOOP_BODY:
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, #40
	mov r10, r7
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, #0
	mov32 r5, map
	mov r10, #1
	str r10, [r5, r6]
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, #0
	mov32 r5, indegree
	ldr r6, [r5, r6]
	add r6, r6, #1
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	mov r10, #0
	mov32 r10, indegree
	str r6, [r10, r5]
	bl getint
	mov r6, r0
	add sp, sp, #0
	mov r8, r6
	b .LB_7_LOOP_BEGIN
.LB7_LOOP_END:
	add r6, r7, #1
	mov r7, r6
	b .LB_main6_LOOP_BEGIN
.LB6_LOOP_END:
	mov r0, r9
	bl topo
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

.globl topo
.type topo, %function
topo:
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
.LBtopo:
	mov r9, r0
	str r9, [fp, #-12]
	mov r9, #0
	mov r8, #0
	mov r7, #1
	mov r6, #1
.LB_topo0_LOOP_BEGIN:
	ldr r5, [fp, #-12]
	cmp r7, r5
	mov r5, #0
	movle r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r6, #1
.LB_1_LOOP_BEGIN:
	ldr r5, [fp, #-12]
	cmp r6, r5
	mov r5, #0
	movle r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, #0
	mov32 r10, indegree
	ldr r5, [r10, r5]
	mov r10, #0
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
	mov r9, r6
	b .LB1_LOOP_END
.LBB_2_ELSE:
	add r5, r6, #1
	mov r6, r5
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	mov r10, #0
	mov32 r10, queue
	str r9, [r10, r5]
	add r5, r8, #1
	mov r8, r5
	mov r5, #0
	sub r5, r5, #1
	mov r10, #4
	mov r10, r10
	mul r10, r9, r10
	mov r4, #0
	mov32 r4, indegree
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	str r5, [r4, r10]
	mov r6, #1
.LB_3_LOOP_BEGIN:
	ldr r5, [fp, #-12]
	cmp r6, r5
	mov r5, #0
	movle r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, #40
	mov r4, r9
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	mul r10, r10, r4
	mov r10, r10
	add r5, r5, r10
	mov r10, #0
	mov32 r10, map
	ldr r5, [r10, r5]
	mov r10, #0
	cmp r5, r10
	beq .LBB_4_ELSE
	b .LBB_4_IF
.LBB_4_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, #0
	mov32 r10, indegree
	ldr r5, [r10, r5]
	sub r5, r5, #1
	mov r10, #4
	mov r10, r10
	mul r10, r6, r10
	mov r4, #0
	mov32 r4, indegree
	str r4, [fp, #-8]
	ldr r4, [fp, #-8]
	str r5, [r4, r10]
.LBB_4_ELSE:
	add r5, r6, #1
	mov r6, r5
	b .LB_3_LOOP_BEGIN
.LB3_LOOP_END:
	add r5, r7, #1
	mov r7, r5
	b .LB_topo0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r9, #0
.LB_5_LOOP_BEGIN:
	ldr r8, [fp, #-12]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB5_LOOP_END
	b .LB5_LOOP_BODY
.LB5_LOOP_BODY:
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, #0
	mov32 r7, queue
	ldr r8, [r7, r8]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r8, r0
	add sp, sp, #0
	add r8, r9, #1
	mov r9, r8
	b .LB_5_LOOP_BEGIN
.LB5_LOOP_END:
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