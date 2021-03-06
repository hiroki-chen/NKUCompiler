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
.globl KMP
.type KMP, %function
KMP:
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
.LBKMP:
	mov r9, r0
	mov r8, r1
	mov r7, #16384
	sub sp, sp, r7
	add r7, sp, #0
	mov r1, r7
	mov r0, r9
	bl get_next
	mov r7, r0
	add sp, sp, #0
	mov r7, #0
	mov r6, #0
.LB_KMP2_LOOP_BEGIN:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, r8
	ldr r5, [r10, r5]
	mov r10, #0
	cmp r5, r10
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r10, #4
	mov r10, r10
	mul r10, r6, r10
	mov r4, r8
	ldr r10, [r4, r10]
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	add r5, r7, #1
	mov r7, r5
	add r5, r6, #1
	mov r6, r5
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r10, #0
	cmp r10, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_4_ELSE
	b .LBB_4_IF
.LBB_4_IF:
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
.LBB_4_ELSE:
	b .LBB_3_END_IF
.LBB_3_ELSE:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, sp
	add r10, r10, #0
	ldr r5, [r10, r5]
	mov r7, r5
	mov r5, #0
	sub r5, r5, #1
	cmp r7, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	add r5, r7, #1
	mov r7, r5
	add r5, r6, #1
	mov r6, r5
.LBB_5_ELSE:
	b .LBB_3_END_IF
.LBB_3_END_IF:
	b .LB_KMP2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r5, #0
	sub r5, r5, #1
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

.globl get_next
.type get_next, %function
get_next:
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
.LBget_next:
	mov r9, r0
	str r9, [fp, #-8]
	mov r9, r1
	mov r8, #0
	sub r8, r8, #1
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, r9
	str r8, [r6, r7]
	mov r8, #0
	mov r6, #0
	sub r6, r6, #1
	mov r7, r6
.LB_get_next0_LOOP_BEGIN:
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	ldr r5, [fp, #-8]
	mov r5, r5
	ldr r6, [r5, r6]
	mov r5, #0
	cmp r6, r5
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r6, #0
	sub r6, r6, #1
	cmp r7, r6
	mov r6, #1
	beq .LB15_COND_END
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	ldr r10, [fp, #-8]
	mov r10, r10
	ldr r5, [r10, r5]
	mov r10, #4
	mov r10, r10
	mul r10, r7, r10
	ldr r4, [fp, #-8]
	mov r4, r4
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	ldr r10, [r4, r10]
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r6, r5
.LB15_COND_END:
	mov r5, #0
	cmp r6, r5
	beq .LBB_1_ELSE
	b .LBB_1_IF
.LBB_1_IF:
	add r6, r7, #1
	mov r7, r6
	add r6, r8, #1
	mov r8, r6
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, r9
	str r7, [r5, r6]
	b .LBB_1_END_IF
.LBB_1_ELSE:
	mov r6, #4
	mov r6, r6
	mul r6, r7, r6
	mov r5, r9
	ldr r6, [r5, r6]
	mov r7, r6
	b .LBB_1_END_IF
.LBB_1_END_IF:
	b .LB_get_next0_LOOP_BEGIN
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
	mov r9, #16384
	sub sp, sp, r9
	mov r9, #16384
	sub sp, sp, r9
	mov r9, #16384
	add r9, sp, r9
	mov r0, r9
	bl read_str
	mov r9, r0
	add sp, sp, #0
	add r9, sp, #0
	mov r0, r9
	bl read_str
	mov r9, r0
	add sp, sp, #0
	add r9, sp, #0
	mov r1, r9
	mov r9, #16384
	add r9, sp, r9
	mov r0, r9
	bl KMP
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

.globl read_str
.type read_str, %function
read_str:
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
.LBread_str:
	mov r9, r0
	mov r8, #0
.LB_read_str6_LOOP_BEGIN:
	mov r7, #1
	cmp r7, #0
	beq .LB6_LOOP_END
	b .LB6_LOOP_BODY
.LB6_LOOP_BODY:
	bl getch
	mov r7, r0
	add sp, sp, #0
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, r9
	str r7, [r5, r6]
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #10
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_7_ELSE
	b .LBB_7_IF
.LBB_7_IF:
	b .LB6_LOOP_END
.LBB_7_ELSE:
	add r7, r8, #1
	mov r8, r7
	b .LB_read_str6_LOOP_BEGIN
.LB6_LOOP_END:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r9, r9
	mov r6, #0
	str r6, [r9, r7]
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007383"