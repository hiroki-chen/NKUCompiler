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
.word 65535

.globl e
e:
.space 1024

.globl book
book:
.space 64

.globl dis
dis:
.space 64

.globl n
n:
.word 0

.globl m
m:
.word 0

.globl v1
v1:
.word 0

.globl v2
v2:
.word 0

.globl w
w:
.word 0

.globl Dijkstra
.type Dijkstra, %function
Dijkstra:
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
	mov r8, #8
	sub sp, sp, r8
.LBDijkstra:
	mov r9, #1
.LB_Dijkstra0_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movle r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, #64
	mov r6, #1
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov32 r7, e
	ldr r8, [r7, r8]
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, #0
	mov32 r6, dis
	str r8, [r6, r7]
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, #0
	mov32 r7, book
	mov r6, #0
	str r6, [r7, r8]
	add r8, r9, #1
	mov r9, r8
	b .LB_Dijkstra0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #0
	mov32 r8, book
	mov r7, #1
	str r7, [r8, r9]
	mov r9, #1
	str r9, [fp, #-8]
.LB_1_LOOP_BEGIN:
	mov r9, #0
	mov32 r9, n
	ldr r9, [r9, #0]
	sub r9, r9, #1
	ldr r8, [fp, #-8]
	cmp r8, r9
	mov r9, #0
	movle r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r8, #0
	mov32 r8, INF
	ldr r8, [r8, #0]
	mov r9, r8
	mov r8, #0
	mov r7, #1
.LB_2_LOOP_BEGIN:
	mov r6, #0
	mov32 r6, n
	ldr r6, [r6, #0]
	cmp r7, r6
	mov r6, #0
	movle r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r6, #4
	mov r6, r6
	mul r6, r7, r6
	mov r5, #0
	mov32 r5, dis
	ldr r6, [r5, r6]
	cmp r9, r6
	mov r6, #0
	ble .LB_27_COND_END
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, #0
	mov32 r10, book
	ldr r5, [r10, r5]
	mov r10, #0
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r6, r5
.LB_27_COND_END:
	mov r5, #0
	cmp r6, r5
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	mov r6, #4
	mov r6, r6
	mul r6, r7, r6
	mov r5, #0
	mov32 r5, dis
	ldr r6, [r5, r6]
	mov r9, r6
	mov r8, r7
.LBB_3_ELSE:
	add r6, r7, #1
	mov r7, r6
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r9, #4
	mov r9, r9
	mul r9, r8, r9
	mov r7, #0
	mov32 r7, book
	mov r6, #1
	str r6, [r7, r9]
	mov r9, #1
.LB_4_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, n
	ldr r7, [r7, #0]
	cmp r9, r7
	mov r7, #0
	movle r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, #64
	mov r5, r8
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, e
	ldr r7, [r6, r7]
	mov r6, #0
	mov32 r6, INF
	ldr r6, [r6, #0]
	cmp r7, r6
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, #0
	mov32 r6, dis
	ldr r7, [r6, r7]
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, #0
	mov32 r5, dis
	ldr r6, [r5, r6]
	mov r5, #4
	mov r5, r5
	mul r5, r9, r5
	mov r10, #64
	mov r4, r8
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	mul r10, r10, r4
	mov r10, r10
	add r5, r5, r10
	mov r10, #0
	mov32 r10, e
	ldr r5, [r10, r5]
	mov r5, r5
	add r6, r6, r5
	cmp r7, r6
	mov r7, #0
	movgt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_6_ELSE
	b .LBB_6_IF
.LBB_6_IF:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, #0
	mov32 r6, dis
	ldr r7, [r6, r7]
	mov r6, #4
	mov r6, r6
	mul r6, r9, r6
	mov r5, #64
	mov r10, r8
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, #0
	mov32 r5, e
	ldr r6, [r5, r6]
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r6, r6
	mul r6, r9, r6
	mov r5, #0
	mov32 r5, dis
	str r7, [r5, r6]
.LBB_6_ELSE:
.LBB_5_ELSE:
	add r7, r9, #1
	mov r9, r7
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	ldr r9, [fp, #-8]
	add r9, r9, #1
	mov r9, r9
	str r9, [fp, #-8]
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
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
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	mov32 r7, n
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, n
	str r8, [r7, #0]
	bl getint
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	mov32 r7, m
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, m
	str r8, [r7, #0]
	mov r9, #1
.LB_main7_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movle r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB7_LOOP_END
	b .LB7_LOOP_BODY
.LB7_LOOP_BODY:
	mov r8, #1
.LB_8_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, n
	ldr r7, [r7, #0]
	cmp r8, r7
	mov r7, #0
	movle r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB8_LOOP_END
	b .LB8_LOOP_BODY
.LB8_LOOP_BODY:
	cmp r9, r8
	mov r7, #0
	moveq r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_9_ELSE
	b .LBB_9_IF
.LBB_9_IF:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, #64
	mov r5, r9
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, e
	mov r5, #0
	str r5, [r6, r7]
	b .LBB_9_END_IF
.LBB_9_ELSE:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, #64
	mov r5, r9
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, e
	mov r5, #0
	mov32 r5, INF
	ldr r5, [r5, #0]
	str r5, [r6, r7]
	b .LBB_9_END_IF
.LBB_9_END_IF:
	add r7, r8, #1
	mov r8, r7
	b .LB_8_LOOP_BEGIN
.LB8_LOOP_END:
	add r7, r9, #1
	mov r9, r7
	b .LB_main7_LOOP_BEGIN
.LB7_LOOP_END:
	mov r9, #1
.LB_10_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, m
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movle r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB10_LOOP_END
	b .LB10_LOOP_BODY
.LB10_LOOP_BODY:
	bl getint
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
	bl getint
	mov r6, r0
	add sp, sp, #0
	mov r7, r6
	bl getint
	mov r6, r0
	add sp, sp, #0
	mov r5, #4
	mov r5, r5
	mul r7, r7, r5
	mov r5, #64
	mov r8, r8
	mul r8, r5, r8
	mov r8, r8
	add r8, r7, r8
	mov r7, #0
	mov32 r7, e
	str r6, [r7, r8]
	add r8, r9, #1
	mov r9, r8
	b .LB_10_LOOP_BEGIN
.LB10_LOOP_END:
	bl Dijkstra
	mov r8, r0
	add sp, sp, #0
	mov r9, #1
.LB_11_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movle r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB11_LOOP_END
	b .LB11_LOOP_BODY
.LB11_LOOP_BODY:
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, #0
	mov32 r7, dis
	ldr r8, [r7, r8]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #32
	bl putch
	mov r8, r0
	add sp, sp, #0
	add r8, r9, #1
	mov r9, r8
	b .LB_11_LOOP_BEGIN
.LB11_LOOP_END:
	mov r0, #10
	bl putch
	mov r8, r0
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