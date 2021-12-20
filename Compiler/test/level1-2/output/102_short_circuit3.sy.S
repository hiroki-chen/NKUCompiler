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
.word 0

.globl b
b:
.word 0

.globl d
d:
.word 0

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
	mov32 r9, a
	ldr r9, [r9, #0]
	mov r9, #2
	mov r8, #0
	mov32 r8, a
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, b
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, b
	str r9, [r8, #0]
	mov r0, #0
	bl set_a
	mov r9, r0
	add sp, sp, #0
	mov r8, #0
	cmp r9, r8
	mov r9, #0
	beq .LB_main2_COND_END
	mov r0, #1
	bl set_b
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
.LB_main2_COND_END:
	mov r8, #0
	cmp r9, r8
	beq .LBB_main0_ELSE
	b .LBB_main0_IF
.LBB_main0_IF:
.LBB_main0_ELSE:
	mov r9, #0
	mov32 r9, a
	ldr r9, [r9, #0]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, #32
	bl putch
	mov r9, r0
	add sp, sp, #0
	mov r9, #0
	mov32 r9, b
	ldr r9, [r9, #0]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, #32
	bl putch
	mov r9, r0
	add sp, sp, #0
	mov r9, #0
	mov32 r9, a
	ldr r9, [r9, #0]
	mov r9, #2
	mov r8, #0
	mov32 r8, a
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, b
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, b
	str r9, [r8, #0]
	mov r0, #0
	bl set_a
	mov r9, r0
	add sp, sp, #0
	mov r8, #0
	cmp r9, r8
	mov r9, #0
	beq .LB_main10_COND_END
	mov r0, #1
	bl set_b
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
.LB_main10_COND_END:
	mov r8, #0
	cmp r9, r8
	beq .LBB_main1_ELSE
	b .LBB_main1_IF
.LBB_main1_IF:
.LBB_main1_ELSE:
	mov r9, #0
	mov32 r9, a
	ldr r9, [r9, #0]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, #32
	bl putch
	mov r9, r0
	add sp, sp, #0
	mov r9, #0
	mov32 r9, b
	ldr r9, [r9, #0]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r9, r0
	add sp, sp, #0
	mov r9, #1
	mov r8, #0
	mov32 r8, d
	ldr r8, [r8, #0]
	mov r8, #2
	mov r7, #0
	mov32 r7, d
	str r8, [r7, #0]
	mov r8, #1
	cmp r9, r8
	mov r8, #0
	blt .LB_main19_COND_END
	mov r0, #3
	bl set_d
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
.LB_main19_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_main2_ELSE
	b .LBB_main2_IF
.LBB_main2_IF:
.LBB_main2_ELSE:
	mov r8, #0
	mov32 r8, d
	ldr r8, [r8, #0]
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #32
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r8, #1
	cmp r9, r8
	mov r9, #1
	ble .LBmain24_COND_END
	mov r0, #4
	bl set_d
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
.LBmain24_COND_END:
	mov r8, #0
	cmp r9, r8
	beq .LBB_main3_ELSE
	b .LBB_main3_IF
.LBB_main3_IF:
.LBB_main3_ELSE:
	mov r9, #0
	mov32 r9, d
	ldr r9, [r9, #0]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r9, r0
	add sp, sp, #0
	mov r9, #2
	add r9, r9, #1
	mov r8, #3
	mov r9, r9
	sub r9, r8, r9
	mov r8, #16
	cmp r8, r9
	mov r9, #0
	movge r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_main4_ELSE
	b .LBB_main4_IF
.LBB_main4_IF:
	mov r0, #65
	bl putch
	mov r9, r0
	add sp, sp, #0
.LBB_main4_ELSE:
	mov r9, #25
	sub r9, r9, #7
	mov r8, #6
	mov r7, #3
	mov r7, r7
	mul r8, r8, r7
	mov r7, #36
	mov r8, r8
	sub r8, r7, r8
	cmp r9, r8
	mov r9, #0
	movne r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_main5_ELSE
	b .LBB_main5_IF
.LBB_main5_IF:
	mov r0, #66
	bl putch
	mov r9, r0
	add sp, sp, #0
.LBB_main5_ELSE:
	mov r9, #1
	cmp r9, #8
	mov r9, #0
	movlt r9, #1
	mov r8, #7
	mov r7, r0
	mov r6, r1
	mov r0, r8
	mov r1, #2
	bl __aeabi_idivmod
	mov r8, r1
	mov r0, r7
	mov r1, r6
	cmp r9, r8
	mov r9, #0
	movne r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_main6_ELSE
	b .LBB_main6_IF
.LBB_main6_IF:
	mov r0, #67
	bl putch
	mov r9, r0
	add sp, sp, #0
.LBB_main6_ELSE:
	mov r9, #3
	cmp r9, #4
	mov r9, #0
	movgt r9, #1
	mov r8, #0
	cmp r9, r8
	mov r9, #0
	moveq r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_main7_ELSE
	b .LBB_main7_IF
.LBB_main7_IF:
	mov r0, #68
	bl putch
	mov r9, r0
	add sp, sp, #0
.LBB_main7_ELSE:
	mov r9, #102
	cmp r9, #63
	mov r9, #0
	movle r9, #1
	mov r8, #1
	cmp r8, r9
	mov r9, #0
	moveq r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_main8_ELSE
	b .LBB_main8_IF
.LBB_main8_IF:
	mov r0, #69
	bl putch
	mov r9, r0
	add sp, sp, #0
.LBB_main8_ELSE:
	mov r9, #5
	sub r9, r9, #6
	mov r8, #0
	cmp r8, #0
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	mov r8, r8
	sub r8, r7, r8
	cmp r9, r8
	mov r9, #0
	moveq r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_main9_ELSE
	b .LBB_main9_IF
.LBB_main9_IF:
	mov r0, #70
	bl putch
	mov r9, r0
	add sp, sp, #0
.LBB_main9_ELSE:
	mov r0, #10
	bl putch
	mov r9, r0
	add sp, sp, #0
	mov r9, #0
	mov r8, #1
	mov r7, #2
	mov r6, #3
	mov r5, #4
.LB_main10_LOOP_BEGIN:
	mov r10, #0
	cmp r9, r10
	mov r10, #0
	beq .LB_59_COND_END
	mov r10, r8
.LB_59_COND_END:
	mov r4, #0
	cmp r10, r4
	beq .LB10_LOOP_END
	b .LB10_LOOP_BODY
.LB10_LOOP_BODY:
	mov r0, #32
	bl putch
	mov r10, r0
	add sp, sp, #0
	b .LB_main10_LOOP_BEGIN
.LB10_LOOP_END:
	mov r10, #0
	cmp r9, r10
	mov r10, #1
	bne .LB62_COND_END
	mov r10, r8
.LB62_COND_END:
	mov r4, #0
	cmp r10, r4
	beq .LBB_11_ELSE
	b .LBB_11_IF
.LBB_11_IF:
	mov r0, #67
	bl putch
	mov r10, r0
	add sp, sp, #0
.LBB_11_ELSE:
	cmp r9, r8
	mov r10, #1
	bge .LB65_COND_END
	cmp r8, r9
	mov r4, #0
	movle r4, #1
	mov r10, r4
.LB65_COND_END:
	mov r4, #0
	cmp r10, r4
	beq .LBB_12_ELSE
	b .LBB_12_IF
.LBB_12_IF:
	mov r0, #72
	bl putch
	mov r10, r0
	add sp, sp, #0
.LBB_12_ELSE:
	cmp r7, r8
	mov r7, #0
	blt .LB_69_COND_END
	cmp r5, r6
	mov r10, #0
	movne r10, #1
	mov r7, r10
.LB_69_COND_END:
	mov r10, #0
	cmp r7, r10
	beq .LBB_13_ELSE
	b .LBB_13_IF
.LBB_13_IF:
	mov r0, #73
	bl putch
	mov r7, r0
	add sp, sp, #0
.LBB_13_ELSE:
	mov r7, #0
	cmp r7, r8
	mov r7, #0
	moveq r7, #1
	cmp r9, r7
	mov r7, #0
	bne .LB_75_COND_END
	cmp r6, r6
	mov r10, #0
	movlt r10, #1
	mov r7, r10
.LB_75_COND_END:
	mov r10, #0
	cmp r7, r10
	mov r7, #1
	bne .LB73_COND_END
	cmp r5, r5
	mov r10, #0
	movge r10, #1
	mov r7, r10
.LB73_COND_END:
	mov r10, #0
	cmp r7, r10
	beq .LBB_14_ELSE
	b .LBB_14_IF
.LBB_14_IF:
	mov r0, #74
	bl putch
	mov r7, r0
	add sp, sp, #0
.LBB_14_ELSE:
	mov r7, #0
	cmp r7, r8
	mov r8, #0
	moveq r8, #1
	cmp r9, r8
	mov r9, #1
	beq .LB81_COND_END
	cmp r6, r6
	mov r8, #0
	bge .LB_84_COND_END
	cmp r5, r5
	mov r7, #0
	movge r7, #1
	mov r8, r7
.LB_84_COND_END:
	mov r9, r8
.LB81_COND_END:
	mov r8, #0
	cmp r9, r8
	beq .LBB_15_ELSE
	b .LBB_15_IF
.LBB_15_IF:
	mov r0, #75
	bl putch
	mov r9, r0
	add sp, sp, #0
.LBB_15_ELSE:
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

.globl set_a
.type set_a, %function
set_a:
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
.LBset_a:
	mov r9, r0
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

.globl set_b
.type set_b, %function
set_b:
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
.LBset_b:
	mov r9, r0
	mov r8, #0
	mov32 r8, b
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, b
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, b
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

.globl set_d
.type set_d, %function
set_d:
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
.LBset_d:
	mov r9, r0
	mov r8, #0
	mov32 r8, d
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, d
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, d
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007397"