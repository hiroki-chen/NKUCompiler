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
.globl g
g:
.word 0

.globl h
h:
.word 0

.globl f
f:
.word 0

.globl e
e:
.word 0

.globl EightWhile
.type EightWhile, %function
EightWhile:
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
.LBEightWhile:
	mov r9, #5
	mov r8, #6
	mov r7, #7
	mov r6, #10
.LB_EightWhile0_LOOP_BEGIN:
	mov r5, #20
	cmp r9, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	add r5, r9, #3
	mov r9, r5
.LB_1_LOOP_BEGIN:
	mov r5, #10
	cmp r8, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	add r5, r8, #1
	mov r8, r5
.LB_2_LOOP_BEGIN:
	mov r5, #7
	cmp r7, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	sub r5, r7, #1
	mov r7, r5
.LB_3_LOOP_BEGIN:
	mov r5, #20
	cmp r6, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	add r5, r6, #3
	mov r6, r5
.LB_4_LOOP_BEGIN:
	mov r5, #0
	mov32 r5, e
	ldr r5, [r5, #0]
	mov r10, #1
	cmp r5, r10
	mov r5, #0
	movgt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r5, #0
	mov32 r5, e
	ldr r5, [r5, #0]
	sub r5, r5, #1
	mov r10, #0
	mov32 r10, e
	ldr r10, [r10, #0]
	mov r5, r5
	mov r10, #0
	mov32 r10, e
	str r5, [r10, #0]
.LB_5_LOOP_BEGIN:
	mov r5, #0
	mov32 r5, f
	ldr r5, [r5, #0]
	mov r10, #2
	cmp r5, r10
	mov r5, #0
	movgt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB5_LOOP_END
	b .LB5_LOOP_BODY
.LB5_LOOP_BODY:
	mov r5, #0
	mov32 r5, f
	ldr r5, [r5, #0]
	sub r5, r5, #2
	mov r10, #0
	mov32 r10, f
	ldr r10, [r10, #0]
	mov r5, r5
	mov r10, #0
	mov32 r10, f
	str r5, [r10, #0]
.LB_6_LOOP_BEGIN:
	mov r5, #0
	mov32 r5, g
	ldr r5, [r5, #0]
	mov r10, #3
	cmp r5, r10
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB6_LOOP_END
	b .LB6_LOOP_BODY
.LB6_LOOP_BODY:
	mov r5, #0
	mov32 r5, g
	ldr r5, [r5, #0]
	add r5, r5, #10
	mov r10, #0
	mov32 r10, g
	ldr r10, [r10, #0]
	mov r5, r5
	mov r10, #0
	mov32 r10, g
	str r5, [r10, #0]
.LB_7_LOOP_BEGIN:
	mov r5, #0
	mov32 r5, h
	ldr r5, [r5, #0]
	mov r10, #10
	cmp r5, r10
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB7_LOOP_END
	b .LB7_LOOP_BODY
.LB7_LOOP_BODY:
	mov r5, #0
	mov32 r5, h
	ldr r5, [r5, #0]
	add r5, r5, #8
	mov r10, #0
	mov32 r10, h
	ldr r10, [r10, #0]
	mov r5, r5
	mov r10, #0
	mov32 r10, h
	str r5, [r10, #0]
	b .LB_7_LOOP_BEGIN
.LB7_LOOP_END:
	mov r5, #0
	mov32 r5, h
	ldr r5, [r5, #0]
	sub r5, r5, #1
	mov r10, #0
	mov32 r10, h
	ldr r10, [r10, #0]
	mov r5, r5
	mov r10, #0
	mov32 r10, h
	str r5, [r10, #0]
	b .LB_6_LOOP_BEGIN
.LB6_LOOP_END:
	mov r5, #0
	mov32 r5, g
	ldr r5, [r5, #0]
	sub r5, r5, #8
	mov r10, #0
	mov32 r10, g
	ldr r10, [r10, #0]
	mov r5, r5
	mov r10, #0
	mov32 r10, g
	str r5, [r10, #0]
	b .LB_5_LOOP_BEGIN
.LB5_LOOP_END:
	mov r5, #0
	mov32 r5, f
	ldr r5, [r5, #0]
	add r5, r5, #1
	mov r10, #0
	mov32 r10, f
	ldr r10, [r10, #0]
	mov r5, r5
	mov r10, #0
	mov32 r10, f
	str r5, [r10, #0]
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	mov r5, #0
	mov32 r5, e
	ldr r5, [r5, #0]
	add r5, r5, #1
	mov r10, #0
	mov32 r10, e
	ldr r10, [r10, #0]
	mov r5, r5
	mov r10, #0
	mov32 r10, e
	str r5, [r10, #0]
	b .LB_3_LOOP_BEGIN
.LB3_LOOP_END:
	sub r5, r6, #1
	mov r6, r5
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	add r5, r7, #1
	mov r7, r5
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	sub r5, r8, #2
	mov r8, r5
	b .LB_EightWhile0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r5, r6
	add r8, r8, r5
	mov r8, r8
	add r9, r9, r8
	mov r8, r7
	add r9, r9, r8
	mov r8, #0
	mov32 r8, e
	ldr r8, [r8, #0]
	mov r7, r6
	add r8, r8, r7
	mov r7, #0
	mov32 r7, g
	ldr r7, [r7, #0]
	mov r7, r7
	sub r8, r8, r7
	mov r7, #0
	mov32 r7, h
	ldr r7, [r7, #0]
	mov r7, r7
	add r8, r8, r7
	mov r8, r8
	sub r9, r9, r8
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
	mov r8, #0
	sub sp, sp, r8
.LBmain:
	mov r9, #0
	mov32 r9, g
	ldr r9, [r9, #0]
	mov r9, #1
	mov r8, #0
	mov32 r8, g
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, h
	ldr r9, [r9, #0]
	mov r9, #2
	mov r8, #0
	mov32 r8, h
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, e
	ldr r9, [r9, #0]
	mov r9, #4
	mov r8, #0
	mov32 r8, e
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, f
	ldr r9, [r9, #0]
	mov r9, #6
	mov r8, #0
	mov32 r8, f
	str r9, [r8, #0]
	bl EightWhile
	mov r9, r0
	add sp, sp, #0
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