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
.globl foo
.type foo, %function
foo:
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
	mov r8, #44
	sub sp, sp, r8
.LBfoo:
	sub sp, sp, #64
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #64
	bl memset
	mov r9, sp
	add r9, r9, #0
	mov r8, #0
	str r8, [r9, #0]
	mov r9, sp
	add r9, r9, #0
	mov r8, #1
	str r8, [r9, #4]
	mov r9, sp
	add r9, r9, #0
	mov r8, #2
	str r8, [r9, #8]
	mov r9, sp
	add r9, r9, #0
	mov r8, #3
	str r8, [r9, #12]
	mov r9, sp
	add r9, r9, #0
	mov r8, #0
	str r8, [r9, #16]
	mov r9, sp
	add r9, r9, #0
	mov r8, #1
	str r8, [r9, #20]
	mov r9, sp
	add r9, r9, #0
	mov r8, #2
	str r8, [r9, #24]
	mov r9, sp
	add r9, r9, #0
	mov r8, #3
	str r8, [r9, #28]
	mov r9, sp
	add r9, r9, #0
	mov r8, #0
	str r8, [r9, #32]
	mov r9, sp
	add r9, r9, #0
	mov r8, #1
	str r8, [r9, #36]
	mov r9, sp
	add r9, r9, #0
	mov r8, #2
	str r8, [r9, #40]
	mov r9, sp
	add r9, r9, #0
	mov r8, #3
	str r8, [r9, #44]
	mov r9, sp
	add r9, r9, #0
	mov r8, #0
	str r8, [r9, #48]
	mov r9, sp
	add r9, r9, #0
	mov r8, #1
	str r8, [r9, #52]
	mov r9, sp
	add r9, r9, #0
	mov r8, #2
	str r8, [r9, #56]
	mov r9, sp
	add r9, r9, #0
	mov r8, #3
	str r8, [r9, #60]
	str r9, [fp, #-44]
	mov r9, #3
	str r9, [fp, #-44]
	mov r9, #7
	mov r8, #5
	mov r7, #6
	mov r6, #1
	mov r5, #0
	mov r10, #3
	str r4, [fp, #-4]
	mov r4, #5
	str r4, [fp, #-4]
	str r4, [fp, #-12]
	mov r4, #4
	str r4, [fp, #-12]
	str r4, [fp, #-8]
	mov r4, #2
	str r4, [fp, #-8]
	str r4, [fp, #-16]
	mov r4, #7
	str r4, [fp, #-16]
	str r4, [fp, #-20]
	mov r4, #9
	str r4, [fp, #-20]
	str r4, [fp, #-24]
	mov r4, #8
	str r4, [fp, #-24]
	str r4, [fp, #-28]
	mov r4, #1
	str r4, [fp, #-28]
	str r4, [fp, #-32]
	mov r4, #4
	str r4, [fp, #-32]
	str r4, [fp, #-36]
	mov r4, #6
	str r4, [fp, #-36]
	str r4, [fp, #-40]
	mov r9, r9
	ldr r4, [fp, #-44]
	add r9, r4, r9
	mov r8, r8
	add r9, r9, r8
	mov r8, r7
	add r9, r9, r8
	mov r8, r6
	add r9, r9, r8
	mov r8, r5
	add r9, r9, r8
	mov r8, r10
	add r9, r9, r8
	ldr r8, [fp, #-4]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	str r9, [fp, #-40]
	ldr r8, [fp, #-8]
	mov r8, r8
	ldr r7, [fp, #-12]
	add r8, r7, r8
	ldr r7, [fp, #-16]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-20]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-24]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-28]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-32]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-36]
	mov r7, r7
	add r8, r8, r7
	mov r9, r8
	mov r9, r9
	ldr r8, [fp, #-40]
	add r9, r8, r9
	mov r8, #4
	mov r8, r8
	ldr r7, [fp, #-44]
	mul r8, r7, r8
	mov r7, sp
	add r7, r7, #0
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
	mov r8, #92
	sub sp, sp, r8
.LBmain:
	str r9, [fp, #-4]
	mov r9, #3
	str r9, [fp, #-4]
	mov r9, #7
	mov r8, #5
	mov r7, #6
	mov r6, #1
	mov r5, #0
	mov r10, #3
	str r4, [fp, #-8]
	mov r4, #5
	str r4, [fp, #-8]
	str r4, [fp, #-16]
	mov r4, #4
	str r4, [fp, #-16]
	str r4, [fp, #-24]
	mov r4, #2
	str r4, [fp, #-24]
	str r4, [fp, #-32]
	mov r4, #7
	str r4, [fp, #-32]
	str r4, [fp, #-40]
	mov r4, #9
	str r4, [fp, #-40]
	str r4, [fp, #-48]
	mov r4, #8
	str r4, [fp, #-48]
	str r4, [fp, #-56]
	mov r4, #1
	str r4, [fp, #-56]
	str r4, [fp, #-64]
	mov r4, #4
	str r4, [fp, #-64]
	str r4, [fp, #-72]
	mov r4, #6
	str r4, [fp, #-72]
	str r4, [fp, #-12]
	mov r9, r9
	ldr r4, [fp, #-4]
	add r9, r4, r9
	mov r8, r8
	add r9, r9, r8
	mov r8, r7
	add r9, r9, r8
	mov r8, r6
	add r9, r9, r8
	mov r8, r5
	add r9, r9, r8
	mov r8, r10
	add r9, r9, r8
	ldr r8, [fp, #-8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	str r9, [fp, #-12]
	ldr r8, [fp, #-24]
	mov r8, r8
	ldr r7, [fp, #-16]
	add r8, r7, r8
	ldr r7, [fp, #-32]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-40]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-48]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-56]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-64]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-72]
	mov r7, r7
	add r8, r8, r7
	mov r9, r8
	bl foo
	mov r8, r0
	add sp, sp, #0
	mov r8, r8
	ldr r7, [fp, #-12]
	add r8, r7, r8
	mov r8, r8
	str r8, [fp, #-88]
	mov r8, #4
	mov r7, #7
	mov r6, #2
	mov r5, #5
	mov r10, #8
	str r4, [fp, #-76]
	mov r4, #0
	str r4, [fp, #-76]
	str r4, [fp, #-80]
	mov r4, #6
	str r4, [fp, #-80]
	str r4, [fp, #-84]
	mov r4, #3
	str r4, [fp, #-84]
	bl foo
	mov r4, r0
	str r4, [fp, #-4]
	add sp, sp, #0
	ldr r4, [fp, #-4]
	mov r4, r4
	str r4, [fp, #-8]
	ldr r4, [fp, #-8]
	add r9, r9, r4
	mov r9, r9
	ldr r4, [fp, #-16]
	mov r4, r4
	str r4, [fp, #-12]
	ldr r4, [fp, #-24]
	mov r4, r4
	str r4, [fp, #-20]
	ldr r4, [fp, #-32]
	mov r4, r4
	str r4, [fp, #-28]
	ldr r4, [fp, #-40]
	mov r4, r4
	str r4, [fp, #-36]
	ldr r4, [fp, #-48]
	mov r4, r4
	str r4, [fp, #-44]
	ldr r4, [fp, #-56]
	mov r4, r4
	str r4, [fp, #-52]
	ldr r4, [fp, #-64]
	mov r4, r4
	str r4, [fp, #-60]
	ldr r4, [fp, #-72]
	mov r4, r4
	str r4, [fp, #-68]
	str r4, [fp, #-92]
	mov r7, r7
	add r8, r8, r7
	mov r7, r6
	add r8, r8, r7
	mov r7, r5
	add r8, r8, r7
	mov r7, r10
	add r8, r8, r7
	ldr r7, [fp, #-76]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-80]
	mov r7, r7
	add r8, r8, r7
	ldr r7, [fp, #-84]
	mov r7, r7
	add r8, r8, r7
	mov r8, r8
	str r8, [fp, #-92]
	mov r9, r9
	ldr r7, [fp, #-88]
	add r9, r7, r9
	ldr r7, [fp, #-92]
	mov r7, r7
	add r9, r9, r7
	mov r8, r9
	mov r0, r8
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007223"