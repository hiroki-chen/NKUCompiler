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
.globl N
N:
.word 0

.globl insert
.type insert, %function
insert:
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
.LBinsert:
	mov r9, r0
	mov r8, r1
	mov r7, #0
.LB_insert0_LOOP_BEGIN:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r9
	ldr r5, [r10, r5]
	cmp r8, r5
	mov r5, #0
	ble .LB_6_COND_END
	mov r10, #0
	mov32 r10, N
	ldr r10, [r10, #0]
	cmp r7, r10
	mov r10, #0
	movlt r10, #1
	mov r5, r10
.LB_6_COND_END:
	mov r10, #0
	cmp r5, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	add r5, r7, #1
	mov r7, r5
	b .LB_insert0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r5, #0
	mov32 r5, N
	ldr r5, [r5, #0]
	mov r6, r5
.LB_1_LOOP_BEGIN:
	cmp r6, r7
	mov r5, #0
	movgt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	sub r5, r6, #1
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, r9
	ldr r5, [r10, r5]
	mov r10, #4
	mov r10, r10
	mul r10, r6, r10
	mov r4, r9
	str r5, [r4, r10]
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r9
	str r8, [r10, r5]
	sub r5, r6, #1
	mov r6, r5
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
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
	mov r9, #0
	mov32 r9, N
	ldr r9, [r9, #0]
	mov r9, #10
	mov r8, #0
	mov32 r8, N
	str r9, [r8, #0]
	sub sp, sp, #44
	mov r9, #0
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #1
	str r7, [r8, r9]
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #3
	str r7, [r8, r9]
	mov r9, #2
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #4
	str r7, [r8, r9]
	mov r9, #3
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #7
	str r7, [r8, r9]
	mov r9, #4
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #8
	str r7, [r8, r9]
	mov r9, #5
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #11
	str r7, [r8, r9]
	mov r9, #6
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #13
	str r7, [r8, r9]
	mov r9, #7
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #18
	str r7, [r8, r9]
	mov r9, #8
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #56
	str r7, [r8, r9]
	mov r9, #9
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r7, #78
	str r7, [r8, r9]
	mov r8, #0
	bl getint
	mov r7, r0
	add sp, sp, #0
	mov r9, r7
	mov r1, r9
	add r9, sp, #0
	mov r0, r9
	bl insert
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
.LB_main2_LOOP_BEGIN:
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
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	mov r9, #10
	mov r0, r9
	bl putch
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_main2_LOOP_BEGIN
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007383"