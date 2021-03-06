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
.word -1

.globl b
b:
.word 1

.globl inc_a
.type inc_a, %function
inc_a:
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
.LBinc_a:
	mov r8, #0
	mov32 r8, a
	ldr r8, [r8, #0]
	mov r9, r8
	add r9, r9, #1
	mov r9, r9
	mov r8, #0
	mov32 r8, a
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, a
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a
	ldr r9, [r9, #0]
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
	mov r9, #5
.LB_main0_LOOP_BEGIN:
	mov r8, #0
	cmp r9, r8
	mov r8, #0
	movge r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	bl inc_a
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	beq .LB_6_COND_END
	bl inc_a
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
.LB_6_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	beq .LB_4_COND_END
	bl inc_a
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
.LB_4_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_1_ELSE
	b .LBB_1_IF
.LBB_1_IF:
	mov r8, #0
	mov32 r8, a
	ldr r8, [r8, #0]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #32
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r8, #0
	mov32 r8, b
	ldr r8, [r8, #0]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r8, r0
	add sp, sp, #0
.LBB_1_ELSE:
	bl inc_a
	mov r8, r0
	add sp, sp, #0
	mov r7, #14
	cmp r8, r7
	mov r8, #1
	blt .LB15_COND_END
	bl inc_a
	mov r7, r0
	add sp, sp, #0
	mov r6, #0
	cmp r7, r6
	mov r7, #0
	beq .LB_18_COND_END
	bl inc_a
	mov r6, r0
	add sp, sp, #0
	bl inc_a
	mov r5, r0
	add sp, sp, #0
	mov r5, r5
	sub r6, r6, r5
	add r6, r6, #1
	mov r7, r6
.LB_18_COND_END:
	mov r8, r7
.LB15_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
	mov r8, #0
	mov32 r8, a
	ldr r8, [r8, #0]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r8, #0
	mov32 r8, b
	ldr r8, [r8, #0]
	mov r7, #2
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, b
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, b
	str r8, [r7, #0]
	b .LBB_2_END_IF
.LBB_2_ELSE:
	bl inc_a
	mov r8, r0
	add sp, sp, #0
	b .LBB_2_END_IF
.LBB_2_END_IF:
	sub r8, r9, #1
	mov r9, r8
	b .LB_main0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r8, #0
	mov32 r8, a
	ldr r8, [r8, #0]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #32
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r8, #0
	mov32 r8, b
	ldr r8, [r8, #0]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r8, #0
	mov32 r8, a
	ldr r8, [r8, #0]
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007368"