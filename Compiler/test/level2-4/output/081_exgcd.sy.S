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
.globl exgcd
.type exgcd, %function
exgcd:
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
	mov r8, #52
	sub sp, sp, r8
.LBexgcd:
	mov r9, r0
	str r9, [fp, #-52]
	mov r9, r1
	mov r8, r2
	mov r7, r3
	str r7, [fp, #-44]
	mov r7, #0
	cmp r9, r7
	mov r7, #0
	moveq r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_exgcd0_ELSE
	b .LBB_exgcd0_IF
.LBB_exgcd0_IF:
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, r8
	mov r5, #1
	str r5, [r6, r7]
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	ldr r6, [fp, #-44]
	mov r6, r6
	mov r5, #0
	str r5, [r6, r7]
	ldr r7, [fp, #-52]
	mov r0, r7
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
.LBB_exgcd0_ELSE:
	mov r6, r0
	mov r5, r1
	ldr r10, [fp, #-52]
	mov r0, r10
	mov r1, r9
	bl __aeabi_idivmod
	mov r10, r1
	str r10, [fp, #-4]
	mov r0, r6
	mov r1, r5
	ldr r6, [fp, #-44]
	mov r3, r6
	mov r2, r8
	ldr r6, [fp, #-4]
	mov r1, r6
	mov r0, r9
	bl exgcd
	mov r6, r0
	add sp, sp, #0
	mov r7, r6
	mov r5, #0
	mov r10, #4
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mov r10, r10
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	mul r5, r5, r10
	mov r10, r8
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	ldr r5, [r10, r5]
	mov r6, r5
	mov r5, #0
	mov r10, #4
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	mov r10, r10
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	mul r5, r5, r10
	ldr r10, [fp, #-44]
	mov r10, r10
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	ldr r5, [r10, r5]
	mov r10, #0
	str r10, [fp, #-36]
	mov r10, #4
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	mov r10, r10
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	ldr r4, [fp, #-36]
	str r4, [fp, #-48]
	ldr r4, [fp, #-48]
	mul r10, r4, r10
	str r10, [fp, #-40]
	mov r8, r8
	ldr r10, [fp, #-40]
	str r5, [r8, r10]
	mov r8, r0
	mov r5, r1
	ldr r10, [fp, #-52]
	mov r0, r10
	mov r1, r9
	bl __aeabi_idiv
	mov r9, r0
	mov r0, r8
	mov r1, r5
	mov r8, #0
	mov r5, #4
	mov r5, r5
	mul r8, r8, r5
	ldr r5, [fp, #-44]
	mov r5, r5
	ldr r8, [r5, r8]
	mov r8, r8
	mul r9, r9, r8
	mov r9, r9
	sub r9, r6, r9
	mov r8, #0
	mov r6, #4
	mov r6, r6
	mul r8, r8, r6
	ldr r6, [fp, #-44]
	mov r6, r6
	str r9, [r6, r8]
	mov r0, r7
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
	mov r9, #7
	mov r8, #15
	sub sp, sp, #4
	mov r7, sp
	add r7, r7, #0
	mov r0, r7
	mov r1, #0
	mov r2, #4
	bl memset
	mov r7, sp
	add r7, r7, #0
	mov r6, #1
	str r6, [r7, #0]
	sub sp, sp, #4
	mov r7, sp
	add r7, r7, #0
	mov r0, r7
	mov r1, #0
	mov r2, #4
	bl memset
	mov r7, sp
	add r7, r7, #0
	mov r6, #1
	str r6, [r7, #0]
	add r7, sp, #0
	mov r3, r7
	add r7, sp, #4
	mov r2, r7
	mov r1, r8
	mov r0, r9
	bl exgcd
	mov r9, r0
	add sp, sp, #0
	mov r9, #0
	mov r7, #4
	mov r7, r7
	mul r9, r9, r7
	mov r7, sp
	add r7, r7, #4
	ldr r9, [r7, r9]
	mov r7, r0
	mov r6, r1
	mov r0, r9
	mov r1, r8
	bl __aeabi_idivmod
	mov r9, r1
	mov r0, r7
	mov r1, r6
	mov r7, r8
	add r9, r9, r7
	mov r7, r0
	mov r6, r1
	mov r0, r9
	mov r1, r8
	bl __aeabi_idivmod
	mov r9, r1
	mov r0, r7
	mov r1, r6
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, sp
	add r7, r7, #4
	str r9, [r7, r8]
	mov r9, #0
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #4
	ldr r9, [r8, r9]
	mov r0, r9
	bl putint
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007383"