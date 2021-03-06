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
.word 1

.globl b
b:
.word 0

.globl c
c:
.word 1

.globl d
d:
.word 2

.globl e
e:
.word 4

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
	mov r8, #0
	mov32 r8, a
	ldr r8, [r8, #0]
	mov r7, #0
	mov32 r7, b
	ldr r7, [r7, #0]
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, c
	ldr r7, [r7, #0]
	mov r6, r0
	mov r5, r1
	mov r0, r8
	mov r1, r7
	bl __aeabi_idiv
	mov r8, r0
	mov r0, r6
	mov r1, r5
	mov r7, #0
	mov32 r7, e
	ldr r7, [r7, #0]
	mov r6, #0
	mov32 r6, d
	ldr r6, [r6, #0]
	mov r6, r6
	add r7, r7, r6
	cmp r8, r7
	mov r8, #0
	bne .LB_main5_COND_END
	mov r7, #0
	mov32 r7, a
	ldr r7, [r7, #0]
	mov r6, #0
	mov32 r6, b
	ldr r6, [r6, #0]
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, a
	ldr r6, [r6, #0]
	mov r7, r7
	mul r7, r6, r7
	mov r6, #0
	mov32 r6, c
	ldr r6, [r6, #0]
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov32 r6, d
	ldr r6, [r6, #0]
	mov r5, #0
	mov32 r5, e
	ldr r5, [r5, #0]
	mov r5, r5
	add r6, r6, r5
	cmp r7, r6
	mov r7, #0
	movle r7, #1
	mov r8, r7
.LB_main5_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LBmain3_COND_END
	mov r7, #0
	mov32 r7, b
	ldr r7, [r7, #0]
	mov r6, #0
	mov32 r6, c
	ldr r6, [r6, #0]
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, a
	ldr r6, [r6, #0]
	mov r7, r7
	sub r7, r6, r7
	mov r6, #0
	mov32 r6, a
	ldr r6, [r6, #0]
	mov r5, #0
	mov32 r5, c
	ldr r5, [r5, #0]
	mov r10, r0
	mov r4, r1
	mov r0, r6
	mov r1, r5
	bl __aeabi_idiv
	mov r6, r0
	mov r0, r10
	mov r1, r4
	mov r5, #0
	mov32 r5, d
	ldr r5, [r5, #0]
	mov r6, r6
	sub r6, r5, r6
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LBmain3_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_main0_ELSE
	b .LBB_main0_IF
.LBB_main0_IF:
	mov r9, #1
.LBB_main0_ELSE:
	mov r0, r9
	bl putint
	mov r8, r0
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007387"