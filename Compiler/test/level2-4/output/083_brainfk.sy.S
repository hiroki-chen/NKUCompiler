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
.globl TAPE_LEN
TAPE_LEN:
.word 65536

.globl BUFFER_LEN
BUFFER_LEN:
.word 32768

.globl tape
tape:
.space 262144

.globl program
program:
.space 131072

.globl ptr
ptr:
.word 0

.globl interpret
.type interpret, %function
interpret:
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
.LBinterpret:
	mov r9, r0
	mov r6, #0
.LB_interpret1_LOOP_BEGIN:
	mov r5, #4
	mul r5, r6, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r10, #0
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r5, #4
	mul r5, r6, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r8, r5
	mov r5, #62
	cmp r8, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
	mov r5, #0
	mov32 r5, ptr
	ldr r5, [r5, #0]
	add r5, r5, #1
	mov r10, #0
	mov32 r10, ptr
	ldr r10, [r10, #0]
	mov r10, #0
	mov32 r10, ptr
	str r5, [r10, #0]
	b .LBB_2_END_IF
.LBB_2_ELSE:
	mov r5, #60
	cmp r8, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	mov r5, #0
	mov32 r5, ptr
	ldr r5, [r5, #0]
	sub r5, r5, #1
	mov r10, #0
	mov32 r10, ptr
	ldr r10, [r10, #0]
	mov r10, #0
	mov32 r10, ptr
	str r5, [r10, #0]
	b .LBB_3_END_IF
.LBB_3_ELSE:
	mov r5, #43
	cmp r8, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_4_ELSE
	b .LBB_4_IF
.LBB_4_IF:
	mov r5, #0
	mov32 r5, ptr
	ldr r5, [r5, #0]
	mov r10, #4
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, tape
	ldr r5, [r10, r5]
	add r5, r5, #1
	mov r10, #0
	mov32 r10, ptr
	ldr r10, [r10, #0]
	mov r4, #4
	mul r10, r10, r4
	mov r4, #0
	mov32 r4, tape
	str r5, [r4, r10]
	b .LBB_4_END_IF
.LBB_4_ELSE:
	mov r5, #45
	cmp r8, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	mov r5, #0
	mov32 r5, ptr
	ldr r5, [r5, #0]
	mov r10, #4
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, tape
	ldr r5, [r10, r5]
	sub r5, r5, #1
	mov r10, #0
	mov32 r10, ptr
	ldr r10, [r10, #0]
	mov r4, #4
	mul r10, r10, r4
	mov r4, #0
	mov32 r4, tape
	str r5, [r4, r10]
	b .LBB_5_END_IF
.LBB_5_ELSE:
	mov r5, #46
	cmp r8, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_6_ELSE
	b .LBB_6_IF
.LBB_6_IF:
	mov r5, #0
	mov32 r5, ptr
	ldr r5, [r5, #0]
	mov r10, #4
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, tape
	ldr r5, [r10, r5]
	mov r0, r5
	bl putch
	mov r5, r0
	b .LBB_6_END_IF
.LBB_6_ELSE:
	mov r5, #44
	cmp r8, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_7_ELSE
	b .LBB_7_IF
.LBB_7_IF:
	bl getch
	mov r5, r0
	mov r10, #0
	mov32 r10, ptr
	ldr r10, [r10, #0]
	mov r4, #4
	mul r10, r10, r4
	mov r4, #0
	mov32 r4, tape
	str r5, [r4, r10]
	b .LBB_7_END_IF
.LBB_7_ELSE:
	mov r5, #93
	cmp r8, r5
	mov r5, #0
	bne .LB_42_COND_END
	mov r10, #0
	mov32 r10, ptr
	ldr r10, [r10, #0]
	mov r4, #4
	mul r10, r10, r4
	mov r4, #0
	mov32 r4, tape
	ldr r10, [r4, r10]
	mov r5, r10
.LB_42_COND_END:
	mov r10, #0
	cmp r5, r10
	beq .LBB_8_ELSE
	b .LBB_8_IF
.LBB_8_IF:
	mov r7, #1
.LB_9_LOOP_BEGIN:
	mov r5, #0
	cmp r7, r5
	mov r5, #0
	movgt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB9_LOOP_END
	b .LB9_LOOP_BODY
.LB9_LOOP_BODY:
	sub r5, r6, #1
	mov r6, r5
	mov r5, #4
	mul r5, r6, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r8, r5
	mov r5, #91
	cmp r8, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_10_ELSE
	b .LBB_10_IF
.LBB_10_IF:
	sub r5, r7, #1
	mov r7, r5
	b .LBB_10_END_IF
.LBB_10_ELSE:
	mov r5, #93
	cmp r8, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_11_ELSE
	b .LBB_11_IF
.LBB_11_IF:
	add r5, r7, #1
	mov r7, r5
.LBB_11_ELSE:
	b .LBB_10_END_IF
.LBB_10_END_IF:
	b .LB_9_LOOP_BEGIN
.LB9_LOOP_END:
.LBB_8_ELSE:
	b .LBB_7_END_IF
.LBB_7_END_IF:
	b .LBB_6_END_IF
.LBB_6_END_IF:
	b .LBB_5_END_IF
.LBB_5_END_IF:
	b .LBB_4_END_IF
.LBB_4_END_IF:
	b .LBB_3_END_IF
.LBB_3_END_IF:
	b .LBB_2_END_IF
.LBB_2_END_IF:
	add r5, r6, #1
	mov r6, r5
	b .LB_interpret1_LOOP_BEGIN
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
	bl read_program
	mov r9, r0
	mov r9, #0
	mov32 r9, program
	mov r0, r9
	bl interpret
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

.globl read_program
.type read_program, %function
read_program:
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
.LBread_program:
	mov r9, #0
	bl getint
	mov r7, r0
	mov r8, r7
.LB_read_program0_LOOP_BEGIN:
	cmp r9, r8
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	bl getch
	mov r7, r0
	mov r6, #4
	mul r6, r9, r6
	mov r5, #0
	mov32 r5, program
	str r7, [r5, r6]
	add r7, r9, #1
	mov r9, r7
	b .LB_read_program0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r8, #4
	mul r9, r9, r8
	mov r8, #0
	mov32 r8, program
	mov r7, #0
	str r7, [r8, r9]
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