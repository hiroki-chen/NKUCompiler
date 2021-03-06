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

.globl func
.type func, %function
func:
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
.LBfunc:
	mov r9, r0
	mov r8, #0
	mov32 r8, g
	ldr r8, [r8, #0]
	mov r9, r9
	add r9, r8, r9
	mov r8, #0
	mov32 r8, g
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, g
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, g
	ldr r9, [r9, #0]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r9, #0
	mov32 r9, g
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
	bl getint
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #10
	cmp r9, r8
	mov r8, #0
	ble .LB_main5_COND_END
	mov r0, r9
	bl func
	mov r9, r0
	add sp, sp, #0
	mov r8, r9
.LB_main5_COND_END:
	mov r9, #0
	cmp r8, r9
	beq .LBB_main0_ELSE
	b .LBB_main0_IF
.LBB_main0_IF:
	mov r9, #1
	b .LBB_main0_END_IF
.LBB_main0_ELSE:
	mov r9, #0
	b .LBB_main0_END_IF
.LBB_main0_END_IF:
	bl getint
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #11
	cmp r9, r8
	mov r8, #0
	ble .LB_main10_COND_END
	mov r0, r9
	bl func
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
.LB_main10_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_main1_ELSE
	b .LBB_main1_IF
.LBB_main1_IF:
	mov r9, #1
	b .LBB_main1_END_IF
.LBB_main1_ELSE:
	mov r9, #0
	b .LBB_main1_END_IF
.LBB_main1_END_IF:
	bl getint
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #99
	cmp r9, r8
	mov r8, #1
	ble .LBmain15_COND_END
	mov r0, r9
	bl func
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
.LBmain15_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_main2_ELSE
	b .LBB_main2_IF
.LBB_main2_IF:
	mov r9, #1
	b .LBB_main2_END_IF
.LBB_main2_ELSE:
	mov r9, #0
	b .LBB_main2_END_IF
.LBB_main2_END_IF:
	bl getint
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #100
	cmp r9, r8
	mov r8, #1
	ble .LBmain20_COND_END
	mov r0, r9
	bl func
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
.LBmain20_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_main3_ELSE
	b .LBB_main3_IF
.LBB_main3_IF:
	mov r9, #1
	b .LBB_main3_END_IF
.LBB_main3_ELSE:
	mov r9, #0
	b .LBB_main3_END_IF
.LBB_main3_END_IF:
	mov r0, #99
	bl func
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	cmp r7, r8
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	beq .LB_main23_COND_END
	mov r0, #100
	bl func
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
.LB_main23_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_main4_ELSE
	b .LBB_main4_IF
.LBB_main4_IF:
	mov r9, #1
	b .LBB_main4_END_IF
.LBB_main4_ELSE:
	mov r9, #0
	b .LBB_main4_END_IF
.LBB_main4_END_IF:
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007385"