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
.word 10000

.globl long_array
.type long_array, %function
long_array:
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
.LBlong_array:
	mov r9, r0
	str r9, [fp, #-8]
	mov r9, #40000
	sub sp, sp, r9
	mov r9, #40000
	sub sp, sp, r9
	mov r9, #40000
	sub sp, sp, r9
	mov r9, #0
.LB_long_array0_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, N
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r8, r9
	mul r8, r9, r8
	mov r7, r0
	mov r6, r1
	mov r0, r8
	mov r1, #10
	bl __aeabi_idivmod
	mov r8, r1
	mov r0, r7
	mov r1, r6
	mov r7, #4
	mul r7, r9, r7
	mov r6, sp
	ldr r5, =#80000
	add r6, r6, r5
	str r8, [r6, r7]
	add r8, r9, #1
	mov r9, r8
	b .LB_long_array0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r9, #0
.LB_1_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, N
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r8, #4
	mul r8, r9, r8
	mov r7, sp
	ldr r6, =#80000
	add r7, r7, r6
	ldr r8, [r7, r8]
	mov r7, #4
	mul r7, r9, r7
	mov r6, sp
	ldr r5, =#80000
	add r6, r6, r5
	ldr r7, [r6, r7]
	mul r8, r8, r7
	mov r7, r0
	mov r6, r1
	mov r0, r8
	mov r1, #10
	bl __aeabi_idivmod
	mov r8, r1
	mov r0, r7
	mov r1, r6
	mov r7, #4
	mul r7, r9, r7
	mov r6, sp
	mov r5, #40000
	add r6, r6, r5
	str r8, [r6, r7]
	add r8, r9, #1
	mov r9, r8
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	mov r9, #0
.LB_2_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, N
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r8, #4
	mul r8, r9, r8
	mov r7, sp
	mov r6, #40000
	add r7, r7, r6
	ldr r8, [r7, r8]
	mov r7, #4
	mul r7, r9, r7
	mov r6, sp
	mov r5, #40000
	add r6, r6, r5
	ldr r7, [r6, r7]
	mul r8, r8, r7
	mov r7, r0
	mov r6, r1
	mov r0, r8
	mov r1, #100
	bl __aeabi_idivmod
	mov r8, r1
	mov r0, r7
	mov r1, r6
	mov r7, #4
	mul r7, r9, r7
	mov r6, sp
	ldr r5, =#80000
	add r6, r6, r5
	ldr r7, [r6, r7]
	add r8, r8, r7
	mov r7, #4
	mul r7, r9, r7
	mov r6, sp
	str r8, [r6, r7]
	add r8, r9, #1
	mov r9, r8
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r9, #0
	mov r8, #0
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
	mov r7, #10
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_4_ELSE
	b .LBB_4_IF
.LBB_4_IF:
	mov r7, #4
	mul r7, r8, r7
	mov r6, sp
	ldr r7, [r6, r7]
	add r7, r9, r7
	mov r6, r0
	mov r5, r1
	mov r0, r7
	mov r1, #1333
	bl __aeabi_idivmod
	mov r7, r1
	mov r0, r6
	mov r1, r5
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	b .LBB_4_END_IF
.LBB_4_ELSE:
	mov r7, #20
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	mov r6, #0
	mov32 r6, N
	ldr r6, [r6, #0]
	mov r5, r0
	mov r10, r1
	mov r0, r6
	mov r1, #2
	bl __aeabi_idiv
	mov r6, r0
	mov r0, r5
	mov r1, r10
	mov r7, r6
.LB_6_LOOP_BEGIN:
	mov r6, #0
	mov32 r6, N
	ldr r6, [r6, #0]
	cmp r7, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB6_LOOP_END
	b .LB6_LOOP_BODY
.LB6_LOOP_BODY:
	mov r6, #4
	mul r6, r8, r6
	mov r5, sp
	ldr r6, [r5, r6]
	add r6, r9, r6
	mov r5, #4
	mul r5, r7, r5
	mov r10, sp
	ldr r4, =#80000
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	add r10, r10, r4
	ldr r5, [r10, r5]
	sub r6, r6, r5
	mov r9, r6
	add r6, r7, #1
	mov r7, r6
	b .LB_6_LOOP_BEGIN
.LB6_LOOP_END:
	mov r0, r9
	bl putint
	mov r7, r0
	b .LBB_5_END_IF
.LBB_5_ELSE:
	mov r7, #30
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_7_ELSE
	b .LBB_7_IF
.LBB_7_IF:
	mov r6, #0
	mov32 r6, N
	ldr r6, [r6, #0]
	mov r5, r0
	mov r10, r1
	mov r0, r6
	mov r1, #2
	bl __aeabi_idiv
	mov r6, r0
	mov r0, r5
	mov r1, r10
	mov r7, r6
.LB_8_LOOP_BEGIN:
	mov r6, #0
	mov32 r6, N
	ldr r6, [r6, #0]
	cmp r7, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB8_LOOP_END
	b .LB8_LOOP_BODY
.LB8_LOOP_BODY:
	mov r6, #2233
	cmp r7, r6
	mov r6, #0
	movgt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_9_ELSE
	b .LBB_9_IF
.LBB_9_IF:
	mov r6, #4
	mul r6, r8, r6
	mov r5, sp
	mov r10, #40000
	add r5, r5, r10
	ldr r6, [r5, r6]
	add r6, r9, r6
	mov r5, #4
	mul r5, r7, r5
	mov r10, sp
	ldr r4, =#80000
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	add r10, r10, r4
	ldr r5, [r10, r5]
	sub r6, r6, r5
	mov r9, r6
	add r6, r7, #1
	mov r7, r6
	b .LBB_9_END_IF
.LBB_9_ELSE:
	mov r6, #4
	mul r6, r8, r6
	mov r5, sp
	ldr r10, =#80000
	add r5, r5, r10
	ldr r6, [r5, r6]
	add r6, r9, r6
	mov r5, #4
	mul r5, r7, r5
	mov r10, sp
	ldr r5, [r10, r5]
	add r6, r6, r5
	mov r5, r0
	mov r10, r1
	mov r0, r6
	mov r1, #13333
	bl __aeabi_idivmod
	mov r6, r1
	mov r0, r5
	mov r1, r10
	mov r9, r6
	add r6, r7, #2
	mov r7, r6
	b .LBB_9_END_IF
.LBB_9_END_IF:
	b .LB_8_LOOP_BEGIN
.LB8_LOOP_END:
	mov r0, r9
	bl putint
	mov r6, r0
	b .LBB_7_END_IF
.LBB_7_ELSE:
	mov r7, #4
	mul r7, r8, r7
	mov r6, sp
	ldr r7, [r6, r7]
	ldr r6, [fp, #-8]
	mul r7, r7, r6
	add r7, r9, r7
	mov r6, r0
	mov r5, r1
	mov r0, r7
	ldr r1, =#99988
	bl __aeabi_idivmod
	mov r7, r1
	mov r0, r6
	mov r1, r5
	mov r9, r7
	b .LBB_7_END_IF
.LBB_7_END_IF:
	b .LBB_5_END_IF
.LBB_5_END_IF:
	b .LBB_4_END_IF
.LBB_4_END_IF:
	add r7, r8, #1
	mov r8, r7
	b .LB_3_LOOP_BEGIN
.LB3_LOOP_END:
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
	mov r0, #9
	bl long_array
	mov r9, r0
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640004947"