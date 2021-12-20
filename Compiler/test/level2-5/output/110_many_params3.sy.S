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
	mov r8, #104
	sub sp, sp, r8
.LBmain:
	str r5, [fp, #-104]
	str r4, [fp, #-100]
	str r4, [fp, #-96]
	str r4, [fp, #-92]
	str r4, [fp, #-88]
	str r4, [fp, #-84]
	str r4, [fp, #-80]
	str r4, [fp, #-76]
	str r4, [fp, #-72]
	str r4, [fp, #-68]
	str r4, [fp, #-64]
	str r4, [fp, #-60]
	str r4, [fp, #-56]
	str r4, [fp, #-52]
	str r4, [fp, #-48]
	str r4, [fp, #-44]
	str r4, [fp, #-40]
	str r4, [fp, #-36]
	str r4, [fp, #-32]
	str r4, [fp, #-28]
	str r4, [fp, #-24]
	str r4, [fp, #-20]
	str r4, [fp, #-16]
	str r4, [fp, #-12]
	str r4, [fp, #-8]
	str r4, [fp, #-4]
	mov r9, #0
	mov r8, #1
	mov r7, #2
	mov r6, #3
	mov r4, #4
	str r4, [fp, #-104]
	mov r5, #5
	mov r10, #6
	mov r4, #7
	str r4, [fp, #-100]
	mov r4, #8
	str r4, [fp, #-96]
	mov r4, #9
	str r4, [fp, #-92]
	mov r4, #0
	str r4, [fp, #-88]
	mov r4, #1
	str r4, [fp, #-84]
	mov r4, #2
	str r4, [fp, #-80]
	mov r4, #3
	str r4, [fp, #-76]
	mov r4, #4
	str r4, [fp, #-72]
	mov r4, #5
	str r4, [fp, #-68]
	mov r4, #6
	str r4, [fp, #-64]
	mov r4, #7
	str r4, [fp, #-60]
	mov r4, #8
	str r4, [fp, #-56]
	mov r4, #9
	str r4, [fp, #-52]
	mov r4, #0
	str r4, [fp, #-48]
	mov r4, #1
	str r4, [fp, #-44]
	mov r4, #2
	str r4, [fp, #-40]
	mov r4, #3
	str r4, [fp, #-36]
	mov r4, #4
	str r4, [fp, #-32]
	mov r4, #5
	str r4, [fp, #-28]
	mov r4, #6
	str r4, [fp, #-24]
	mov r4, #7
	str r4, [fp, #-20]
	mov r4, #8
	str r4, [fp, #-16]
	mov r4, #9
	str r4, [fp, #-12]
	mov r4, #0
	str r4, [fp, #-8]
	mov r4, #1
	str r4, [fp, #-4]
	mov r3, r6
	mov r2, r7
	mov r1, r8
	mov r0, r9
	ldr r9, [fp, #-100]
	push {r9}
	push {r10}
	push {r5}
	ldr r9, [fp, #-104]
	push {r9}
	bl testParam8
	mov r9, r0
	add sp, sp, #16
	mov r3, r6
	mov r2, r7
	mov r1, r8
	mov r0, r9
	ldr r9, [fp, #-68]
	push {r9}
	ldr r9, [fp, #-72]
	push {r9}
	ldr r9, [fp, #-76]
	push {r9}
	ldr r9, [fp, #-80]
	push {r9}
	ldr r9, [fp, #-84]
	push {r9}
	ldr r9, [fp, #-88]
	push {r9}
	ldr r9, [fp, #-92]
	push {r9}
	ldr r9, [fp, #-96]
	push {r9}
	ldr r9, [fp, #-100]
	push {r9}
	push {r10}
	push {r5}
	ldr r9, [fp, #-104]
	push {r9}
	bl testParam16
	mov r9, r0
	add sp, sp, #48
	mov r3, r6
	mov r2, r7
	mov r1, r8
	mov r0, r9
	ldr r9, [fp, #-4]
	push {r9}
	ldr r9, [fp, #-8]
	push {r9}
	ldr r9, [fp, #-12]
	push {r9}
	ldr r9, [fp, #-16]
	push {r9}
	ldr r9, [fp, #-20]
	push {r9}
	ldr r9, [fp, #-24]
	push {r9}
	ldr r9, [fp, #-28]
	push {r9}
	ldr r9, [fp, #-32]
	push {r9}
	ldr r9, [fp, #-36]
	push {r9}
	ldr r9, [fp, #-40]
	push {r9}
	ldr r9, [fp, #-44]
	push {r9}
	ldr r9, [fp, #-48]
	push {r9}
	ldr r9, [fp, #-52]
	push {r9}
	ldr r9, [fp, #-56]
	push {r9}
	ldr r9, [fp, #-60]
	push {r9}
	ldr r9, [fp, #-64]
	push {r9}
	ldr r9, [fp, #-68]
	push {r9}
	ldr r9, [fp, #-72]
	push {r9}
	ldr r9, [fp, #-76]
	push {r9}
	ldr r9, [fp, #-80]
	push {r9}
	ldr r9, [fp, #-84]
	push {r9}
	ldr r9, [fp, #-88]
	push {r9}
	ldr r9, [fp, #-92]
	push {r9}
	ldr r9, [fp, #-96]
	push {r9}
	ldr r9, [fp, #-100]
	push {r9}
	push {r10}
	push {r5}
	ldr r9, [fp, #-104]
	push {r9}
	bl testParam32
	mov r9, r0
	add sp, sp, #112
	mov r9, r9
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

.globl testParam16
.type testParam16, %function
testParam16:
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
	mov r8, #72
	sub sp, sp, r8
.LBtestParam16:
	mov r9, r0
	str r9, [fp, #-36]
	mov r9, r1
	mov r8, r2
	mov r7, r3
	add r6, fp, #36
	ldr r6, [r6]
	add r5, fp, #40
	ldr r5, [r5]
	add r10, fp, #44
	ldr r10, [r10]
	add r4, fp, #48
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	ldr r4, [r4]
	str r4, [fp, #-40]
	add r4, fp, #52
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	ldr r4, [r4]
	str r4, [fp, #-44]
	add r4, fp, #56
	str r4, [fp, #-8]
	ldr r4, [fp, #-8]
	ldr r4, [r4]
	str r4, [fp, #-48]
	add r4, fp, #60
	str r4, [fp, #-12]
	ldr r4, [fp, #-12]
	ldr r4, [r4]
	str r4, [fp, #-52]
	add r4, fp, #64
	str r4, [fp, #-16]
	ldr r4, [fp, #-16]
	ldr r4, [r4]
	str r4, [fp, #-56]
	add r4, fp, #68
	str r4, [fp, #-20]
	ldr r4, [fp, #-20]
	ldr r4, [r4]
	str r4, [fp, #-60]
	add r4, fp, #72
	str r4, [fp, #-24]
	ldr r4, [fp, #-24]
	ldr r4, [r4]
	str r4, [fp, #-64]
	add r4, fp, #76
	str r4, [fp, #-28]
	ldr r4, [fp, #-28]
	ldr r4, [r4]
	str r4, [fp, #-68]
	add r4, fp, #80
	str r4, [fp, #-32]
	ldr r4, [fp, #-32]
	ldr r4, [r4]
	str r4, [fp, #-72]
	mov r9, r9
	ldr r4, [fp, #-36]
	add r9, r4, r9
	mov r8, r8
	add r9, r9, r8
	mov r8, r7
	add r9, r9, r8
	mov r8, r6
	sub r9, r9, r8
	mov r8, r5
	add r9, r9, r8
	mov r8, r10
	add r9, r9, r8
	ldr r8, [fp, #-40]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-44]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-48]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-52]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-56]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-60]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-64]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-68]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-72]
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

.globl testParam32
.type testParam32, %function
testParam32:
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
	mov r8, #200
	sub sp, sp, r8
.LBtestParam32:
	mov r9, r0
	str r9, [fp, #-100]
	mov r9, r1
	mov r8, r2
	mov r7, r3
	add r6, fp, #36
	ldr r6, [r6]
	add r5, fp, #40
	ldr r5, [r5]
	add r10, fp, #44
	ldr r10, [r10]
	add r4, fp, #48
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	ldr r4, [r4]
	str r4, [fp, #-104]
	add r4, fp, #52
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	ldr r4, [r4]
	str r4, [fp, #-108]
	add r4, fp, #56
	str r4, [fp, #-8]
	ldr r4, [fp, #-8]
	ldr r4, [r4]
	str r4, [fp, #-112]
	add r4, fp, #60
	str r4, [fp, #-12]
	ldr r4, [fp, #-12]
	ldr r4, [r4]
	str r4, [fp, #-116]
	add r4, fp, #64
	str r4, [fp, #-16]
	ldr r4, [fp, #-16]
	ldr r4, [r4]
	str r4, [fp, #-120]
	add r4, fp, #68
	str r4, [fp, #-20]
	ldr r4, [fp, #-20]
	ldr r4, [r4]
	str r4, [fp, #-124]
	add r4, fp, #72
	str r4, [fp, #-24]
	ldr r4, [fp, #-24]
	ldr r4, [r4]
	str r4, [fp, #-128]
	add r4, fp, #76
	str r4, [fp, #-28]
	ldr r4, [fp, #-28]
	ldr r4, [r4]
	str r4, [fp, #-132]
	add r4, fp, #80
	str r4, [fp, #-32]
	ldr r4, [fp, #-32]
	ldr r4, [r4]
	str r4, [fp, #-136]
	add r4, fp, #84
	str r4, [fp, #-36]
	ldr r4, [fp, #-36]
	ldr r4, [r4]
	str r4, [fp, #-140]
	add r4, fp, #88
	str r4, [fp, #-40]
	ldr r4, [fp, #-40]
	ldr r4, [r4]
	str r4, [fp, #-144]
	add r4, fp, #92
	str r4, [fp, #-44]
	ldr r4, [fp, #-44]
	ldr r4, [r4]
	str r4, [fp, #-148]
	add r4, fp, #96
	str r4, [fp, #-48]
	ldr r4, [fp, #-48]
	ldr r4, [r4]
	str r4, [fp, #-152]
	add r4, fp, #100
	str r4, [fp, #-52]
	ldr r4, [fp, #-52]
	ldr r4, [r4]
	str r4, [fp, #-156]
	add r4, fp, #104
	str r4, [fp, #-56]
	ldr r4, [fp, #-56]
	ldr r4, [r4]
	str r4, [fp, #-160]
	add r4, fp, #108
	str r4, [fp, #-60]
	ldr r4, [fp, #-60]
	ldr r4, [r4]
	str r4, [fp, #-164]
	add r4, fp, #112
	str r4, [fp, #-64]
	ldr r4, [fp, #-64]
	ldr r4, [r4]
	str r4, [fp, #-168]
	add r4, fp, #116
	str r4, [fp, #-68]
	ldr r4, [fp, #-68]
	ldr r4, [r4]
	str r4, [fp, #-172]
	add r4, fp, #120
	str r4, [fp, #-72]
	ldr r4, [fp, #-72]
	ldr r4, [r4]
	str r4, [fp, #-176]
	add r4, fp, #124
	str r4, [fp, #-76]
	ldr r4, [fp, #-76]
	ldr r4, [r4]
	str r4, [fp, #-180]
	add r4, fp, #128
	str r4, [fp, #-80]
	ldr r4, [fp, #-80]
	ldr r4, [r4]
	str r4, [fp, #-184]
	add r4, fp, #132
	str r4, [fp, #-84]
	ldr r4, [fp, #-84]
	ldr r4, [r4]
	str r4, [fp, #-188]
	add r4, fp, #136
	str r4, [fp, #-88]
	ldr r4, [fp, #-88]
	ldr r4, [r4]
	str r4, [fp, #-192]
	add r4, fp, #140
	str r4, [fp, #-92]
	ldr r4, [fp, #-92]
	ldr r4, [r4]
	str r4, [fp, #-196]
	add r4, fp, #144
	str r4, [fp, #-96]
	ldr r4, [fp, #-96]
	ldr r4, [r4]
	str r4, [fp, #-200]
	mov r8, r8
	mul r9, r9, r8
	mov r9, r9
	ldr r8, [fp, #-100]
	add r9, r8, r9
	mov r8, r7
	add r9, r9, r8
	mov r8, r6
	add r9, r9, r8
	mov r8, r5
	add r9, r9, r8
	mov r8, r10
	add r9, r9, r8
	ldr r8, [fp, #-104]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-108]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-112]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-116]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-120]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-124]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-128]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-132]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-136]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-140]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-144]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-148]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-152]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-156]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-160]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-164]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-168]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-172]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-176]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-180]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-184]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-188]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-192]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-196]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-200]
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

.globl testParam8
.type testParam8, %function
testParam8:
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
.LBtestParam8:
	mov r9, r0
	str r9, [fp, #-8]
	mov r9, r1
	mov r8, r2
	mov r7, r3
	add r6, fp, #36
	ldr r6, [r6]
	add r5, fp, #40
	ldr r5, [r5]
	add r10, fp, #44
	ldr r10, [r10]
	add r4, fp, #48
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	ldr r4, [r4]
	str r4, [fp, #-4]
	mov r9, r9
	ldr r4, [fp, #-8]
	sub r9, r4, r9
	mov r8, r8
	add r9, r9, r8
	mov r8, r7
	sub r9, r9, r8
	mov r8, r6
	sub r9, r9, r8
	mov r8, r5
	sub r9, r9, r8
	mov r8, r10
	add r9, r9, r8
	ldr r8, [fp, #-4]
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007385"