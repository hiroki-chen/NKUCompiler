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
	sub sp, sp, #32
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #32
	bl memset
	sub sp, sp, #32
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #32
	bl memset
	mov r9, sp
	add r9, r9, #0
	mov r8, #1
	str r8, [r9, #0]
	mov r9, sp
	add r9, r9, #0
	mov r8, #2
	str r8, [r9, #4]
	mov r9, sp
	add r9, r9, #0
	mov r8, #3
	str r8, [r9, #8]
	mov r9, sp
	add r9, r9, #0
	mov r8, #4
	str r8, [r9, #12]
	mov r9, sp
	add r9, r9, #0
	mov r8, #5
	str r8, [r9, #16]
	mov r9, sp
	add r9, r9, #0
	mov r8, #6
	str r8, [r9, #20]
	mov r9, sp
	add r9, r9, #0
	mov r8, #7
	str r8, [r9, #24]
	mov r9, sp
	add r9, r9, #0
	mov r8, #8
	str r8, [r9, #28]
	sub sp, sp, #32
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #32
	bl memset
	mov r9, sp
	add r9, r9, #0
	mov r8, #1
	str r8, [r9, #0]
	mov r9, sp
	add r9, r9, #0
	mov r8, #2
	str r8, [r9, #4]
	mov r9, sp
	add r9, r9, #0
	mov r8, #3
	str r8, [r9, #8]
	mov r9, sp
	add r9, r9, #0
	mov r8, #4
	str r8, [r9, #12]
	mov r9, sp
	add r9, r9, #0
	mov r8, #5
	str r8, [r9, #16]
	mov r9, sp
	add r9, r9, #0
	mov r8, #6
	str r8, [r9, #20]
	mov r9, sp
	add r9, r9, #0
	mov r8, #7
	str r8, [r9, #24]
	mov r9, sp
	add r9, r9, #0
	mov r8, #8
	str r8, [r9, #28]
	sub sp, sp, #32
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #32
	bl memset
	mov r9, sp
	add r9, r9, #0
	mov r8, #1
	str r8, [r9, #0]
	mov r9, sp
	add r9, r9, #0
	mov r8, #2
	str r8, [r9, #4]
	mov r9, sp
	add r9, r9, #0
	mov r8, #3
	str r8, [r9, #8]
	mov r9, sp
	add r9, r9, #0
	mov r8, #5
	str r8, [r9, #16]
	mov r9, sp
	add r9, r9, #0
	mov r8, #7
	str r8, [r9, #24]
	mov r9, sp
	add r9, r9, #0
	mov r8, #8
	str r8, [r9, #28]
	sub sp, sp, #32
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #32
	bl memset
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #8
	mov r7, #2
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #32
	ldr r9, [r8, r9]
	mov r8, sp
	add r8, r8, #0
	str r9, [r8, #0]
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #8
	mov r7, #2
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #64
	ldr r9, [r8, r9]
	mov r8, sp
	add r8, r8, #0
	str r9, [r8, #4]
	mov r9, sp
	add r9, r9, #0
	mov r8, #3
	str r8, [r9, #8]
	mov r9, sp
	add r9, r9, #0
	mov r8, #4
	str r8, [r9, #12]
	mov r9, sp
	add r9, r9, #0
	mov r8, #5
	str r8, [r9, #16]
	mov r9, sp
	add r9, r9, #0
	mov r8, #6
	str r8, [r9, #20]
	mov r9, sp
	add r9, r9, #0
	mov r8, #7
	str r8, [r9, #24]
	mov r9, sp
	add r9, r9, #0
	mov r8, #8
	str r8, [r9, #28]
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #8
	mov r7, #3
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	ldr r9, [r8, r9]
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #8
	mov r6, #0
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, sp
	add r7, r7, #0
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #8
	mov r6, #0
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, sp
	add r7, r7, #0
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #8
	mov r6, #2
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, sp
	add r7, r7, #128
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007383"