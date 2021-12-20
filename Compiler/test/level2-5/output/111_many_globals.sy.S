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
.globl a0
a0:
.word 0

.globl a1
a1:
.word 0

.globl a2
a2:
.word 0

.globl a3
a3:
.word 0

.globl a4
a4:
.word 0

.globl a5
a5:
.word 0

.globl a6
a6:
.word 0

.globl a7
a7:
.word 0

.globl a8
a8:
.word 0

.globl a9
a9:
.word 0

.globl a10
a10:
.word 0

.globl a11
a11:
.word 0

.globl a12
a12:
.word 0

.globl a13
a13:
.word 0

.globl a14
a14:
.word 0

.globl a15
a15:
.word 0

.globl a16
a16:
.word 0

.globl a17
a17:
.word 0

.globl a18
a18:
.word 0

.globl a19
a19:
.word 0

.globl a20
a20:
.word 0

.globl a21
a21:
.word 0

.globl a22
a22:
.word 0

.globl a23
a23:
.word 0

.globl a24
a24:
.word 0

.globl a25
a25:
.word 0

.globl a26
a26:
.word 0

.globl a27
a27:
.word 0

.globl a28
a28:
.word 0

.globl a29
a29:
.word 0

.globl a30
a30:
.word 0

.globl a31
a31:
.word 0

.globl a32
a32:
.word 0

.globl a33
a33:
.word 0

.globl a34
a34:
.word 0

.globl a35
a35:
.word 0

.globl a36
a36:
.word 0

.globl a37
a37:
.word 0

.globl a38
a38:
.word 0

.globl a39
a39:
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
	mov r8, #140
	sub sp, sp, r8
.LBmain:
	mov r9, #0
	mov32 r9, a0
	ldr r9, [r9, #0]
	mov r9, #0
	mov r8, #0
	mov32 r8, a0
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a1
	ldr r9, [r9, #0]
	mov r9, #1
	mov r8, #0
	mov32 r8, a1
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a2
	ldr r9, [r9, #0]
	mov r9, #2
	mov r8, #0
	mov32 r8, a2
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a3
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, a3
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a4
	ldr r9, [r9, #0]
	mov r9, #4
	mov r8, #0
	mov32 r8, a4
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a5
	ldr r9, [r9, #0]
	mov r9, #5
	mov r8, #0
	mov32 r8, a5
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a6
	ldr r9, [r9, #0]
	mov r9, #6
	mov r8, #0
	mov32 r8, a6
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a7
	ldr r9, [r9, #0]
	mov r9, #7
	mov r8, #0
	mov32 r8, a7
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a8
	ldr r9, [r9, #0]
	mov r9, #8
	mov r8, #0
	mov32 r8, a8
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a9
	ldr r9, [r9, #0]
	mov r9, #9
	mov r8, #0
	mov32 r8, a9
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a10
	ldr r9, [r9, #0]
	mov r9, #0
	mov r8, #0
	mov32 r8, a10
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a11
	ldr r9, [r9, #0]
	mov r9, #1
	mov r8, #0
	mov32 r8, a11
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a12
	ldr r9, [r9, #0]
	mov r9, #2
	mov r8, #0
	mov32 r8, a12
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a13
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, a13
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a14
	ldr r9, [r9, #0]
	mov r9, #4
	mov r8, #0
	mov32 r8, a14
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a15
	ldr r9, [r9, #0]
	mov r9, #5
	mov r8, #0
	mov32 r8, a15
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a16
	ldr r9, [r9, #0]
	mov r9, #6
	mov r8, #0
	mov32 r8, a16
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a17
	ldr r9, [r9, #0]
	mov r9, #7
	mov r8, #0
	mov32 r8, a17
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a18
	ldr r9, [r9, #0]
	mov r9, #8
	mov r8, #0
	mov32 r8, a18
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a19
	ldr r9, [r9, #0]
	mov r9, #9
	mov r8, #0
	mov32 r8, a19
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a20
	ldr r9, [r9, #0]
	mov r9, #0
	mov r8, #0
	mov32 r8, a20
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a21
	ldr r9, [r9, #0]
	mov r9, #1
	mov r8, #0
	mov32 r8, a21
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a22
	ldr r9, [r9, #0]
	mov r9, #2
	mov r8, #0
	mov32 r8, a22
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a23
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, a23
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a24
	ldr r9, [r9, #0]
	mov r9, #4
	mov r8, #0
	mov32 r8, a24
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a25
	ldr r9, [r9, #0]
	mov r9, #5
	mov r8, #0
	mov32 r8, a25
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a26
	ldr r9, [r9, #0]
	mov r9, #6
	mov r8, #0
	mov32 r8, a26
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a27
	ldr r9, [r9, #0]
	mov r9, #7
	mov r8, #0
	mov32 r8, a27
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a28
	ldr r9, [r9, #0]
	mov r9, #8
	mov r8, #0
	mov32 r8, a28
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a29
	ldr r9, [r9, #0]
	mov r9, #9
	mov r8, #0
	mov32 r8, a29
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a30
	ldr r9, [r9, #0]
	mov r9, #0
	mov r8, #0
	mov32 r8, a30
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a31
	ldr r9, [r9, #0]
	mov r9, #1
	mov r8, #0
	mov32 r8, a31
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a32
	ldr r9, [r9, #0]
	mov r9, #4
	mov r8, #0
	mov32 r8, a32
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a33
	ldr r9, [r9, #0]
	mov r9, #5
	mov r8, #0
	mov32 r8, a33
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a34
	ldr r9, [r9, #0]
	mov r9, #6
	mov r8, #0
	mov32 r8, a34
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a35
	ldr r9, [r9, #0]
	mov r9, #7
	mov r8, #0
	mov32 r8, a35
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a36
	ldr r9, [r9, #0]
	mov r9, #8
	mov r8, #0
	mov32 r8, a36
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a37
	ldr r9, [r9, #0]
	mov r9, #9
	mov r8, #0
	mov32 r8, a37
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a38
	ldr r9, [r9, #0]
	mov r9, #0
	mov r8, #0
	mov32 r8, a38
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a39
	ldr r9, [r9, #0]
	mov r9, #1
	mov r8, #0
	mov32 r8, a39
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a7
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, a6
	ldr r8, [r8, #0]
	mov r7, #0
	mov32 r7, a5
	ldr r7, [r7, #0]
	mov r6, #0
	mov32 r6, a4
	ldr r6, [r6, #0]
	mov r5, #0
	mov32 r5, a3
	ldr r5, [r5, #0]
	mov r3, r5
	mov r5, #0
	mov32 r5, a2
	ldr r5, [r5, #0]
	mov r2, r5
	mov r5, #0
	mov32 r5, a1
	ldr r5, [r5, #0]
	mov r1, r5
	mov r5, #0
	mov32 r5, a0
	ldr r5, [r5, #0]
	mov r0, r5
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	bl testParam8
	mov r9, r0
	add sp, sp, #16
	mov r8, #0
	mov32 r8, a0
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, a0
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a0
	ldr r9, [r9, #0]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r9, #0
	mov32 r9, a15
	str r9, [fp, #-16]
	ldr r9, [fp, #-16]
	ldr r9, [r9, #0]
	str r9, [fp, #-16]
	mov r9, #0
	mov32 r9, a14
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, a13
	ldr r8, [r8, #0]
	mov r7, #0
	mov32 r7, a12
	ldr r7, [r7, #0]
	mov r6, #0
	mov32 r6, a11
	ldr r6, [r6, #0]
	mov r5, #0
	mov32 r5, a10
	ldr r5, [r5, #0]
	mov r10, #0
	mov32 r10, a9
	ldr r10, [r10, #0]
	mov r4, #0
	mov32 r4, a8
	str r4, [fp, #-20]
	ldr r4, [fp, #-20]
	ldr r4, [r4, #0]
	str r4, [fp, #-20]
	mov r4, #0
	mov32 r4, a39
	str r4, [fp, #-24]
	ldr r4, [fp, #-24]
	ldr r4, [r4, #0]
	str r4, [fp, #-24]
	mov r4, #0
	mov32 r4, a38
	str r4, [fp, #-28]
	ldr r4, [fp, #-28]
	ldr r4, [r4, #0]
	str r4, [fp, #-28]
	mov r4, #0
	mov32 r4, a37
	str r4, [fp, #-32]
	ldr r4, [fp, #-32]
	ldr r4, [r4, #0]
	str r4, [fp, #-32]
	mov r4, #0
	mov32 r4, a36
	str r4, [fp, #-36]
	ldr r4, [fp, #-36]
	ldr r4, [r4, #0]
	str r4, [fp, #-36]
	mov r4, #0
	mov32 r4, a35
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	ldr r4, [r4, #0]
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	mov r3, r4
	mov r4, #0
	mov32 r4, a34
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	ldr r4, [r4, #0]
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	mov r2, r4
	mov r4, #0
	mov32 r4, a33
	str r4, [fp, #-8]
	ldr r4, [fp, #-8]
	ldr r4, [r4, #0]
	str r4, [fp, #-8]
	ldr r4, [fp, #-8]
	mov r1, r4
	mov r4, #0
	mov32 r4, a32
	str r4, [fp, #-12]
	ldr r4, [fp, #-12]
	ldr r4, [r4, #0]
	str r4, [fp, #-12]
	ldr r4, [fp, #-12]
	mov r0, r4
	ldr r4, [fp, #-16]
	push {r4}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r10}
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
	bl testParam16
	mov r9, r0
	add sp, sp, #48
	mov r8, #0
	mov32 r8, a0
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, a0
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a0
	ldr r9, [r9, #0]
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	mov r9, #0
	mov32 r9, a31
	str r9, [fp, #-56]
	ldr r9, [fp, #-56]
	ldr r9, [r9, #0]
	str r9, [fp, #-56]
	mov r9, #0
	mov32 r9, a30
	ldr r9, [r9, #0]
	mov r8, #0
	mov32 r8, a29
	ldr r8, [r8, #0]
	mov r7, #0
	mov32 r7, a28
	ldr r7, [r7, #0]
	mov r6, #0
	mov32 r6, a27
	ldr r6, [r6, #0]
	mov r5, #0
	mov32 r5, a26
	ldr r5, [r5, #0]
	mov r10, #0
	mov32 r10, a25
	ldr r10, [r10, #0]
	mov r4, #0
	mov32 r4, a24
	str r4, [fp, #-60]
	ldr r4, [fp, #-60]
	ldr r4, [r4, #0]
	str r4, [fp, #-60]
	mov r4, #0
	mov32 r4, a23
	str r4, [fp, #-64]
	ldr r4, [fp, #-64]
	ldr r4, [r4, #0]
	str r4, [fp, #-64]
	mov r4, #0
	mov32 r4, a22
	str r4, [fp, #-68]
	ldr r4, [fp, #-68]
	ldr r4, [r4, #0]
	str r4, [fp, #-68]
	mov r4, #0
	mov32 r4, a21
	str r4, [fp, #-72]
	ldr r4, [fp, #-72]
	ldr r4, [r4, #0]
	str r4, [fp, #-72]
	mov r4, #0
	mov32 r4, a20
	str r4, [fp, #-76]
	ldr r4, [fp, #-76]
	ldr r4, [r4, #0]
	str r4, [fp, #-76]
	mov r4, #0
	mov32 r4, a19
	str r4, [fp, #-80]
	ldr r4, [fp, #-80]
	ldr r4, [r4, #0]
	str r4, [fp, #-80]
	mov r4, #0
	mov32 r4, a18
	str r4, [fp, #-84]
	ldr r4, [fp, #-84]
	ldr r4, [r4, #0]
	str r4, [fp, #-84]
	mov r4, #0
	mov32 r4, a17
	str r4, [fp, #-88]
	ldr r4, [fp, #-88]
	ldr r4, [r4, #0]
	str r4, [fp, #-88]
	mov r4, #0
	mov32 r4, a16
	str r4, [fp, #-92]
	ldr r4, [fp, #-92]
	ldr r4, [r4, #0]
	str r4, [fp, #-92]
	mov r4, #0
	mov32 r4, a15
	str r4, [fp, #-96]
	ldr r4, [fp, #-96]
	ldr r4, [r4, #0]
	str r4, [fp, #-96]
	mov r4, #0
	mov32 r4, a14
	str r4, [fp, #-100]
	ldr r4, [fp, #-100]
	ldr r4, [r4, #0]
	str r4, [fp, #-100]
	mov r4, #0
	mov32 r4, a13
	str r4, [fp, #-104]
	ldr r4, [fp, #-104]
	ldr r4, [r4, #0]
	str r4, [fp, #-104]
	mov r4, #0
	mov32 r4, a12
	str r4, [fp, #-108]
	ldr r4, [fp, #-108]
	ldr r4, [r4, #0]
	str r4, [fp, #-108]
	mov r4, #0
	mov32 r4, a11
	str r4, [fp, #-112]
	ldr r4, [fp, #-112]
	ldr r4, [r4, #0]
	str r4, [fp, #-112]
	mov r4, #0
	mov32 r4, a10
	str r4, [fp, #-116]
	ldr r4, [fp, #-116]
	ldr r4, [r4, #0]
	str r4, [fp, #-116]
	mov r4, #0
	mov32 r4, a9
	str r4, [fp, #-120]
	ldr r4, [fp, #-120]
	ldr r4, [r4, #0]
	str r4, [fp, #-120]
	mov r4, #0
	mov32 r4, a8
	str r4, [fp, #-124]
	ldr r4, [fp, #-124]
	ldr r4, [r4, #0]
	str r4, [fp, #-124]
	mov r4, #0
	mov32 r4, a7
	str r4, [fp, #-128]
	ldr r4, [fp, #-128]
	ldr r4, [r4, #0]
	str r4, [fp, #-128]
	mov r4, #0
	mov32 r4, a6
	str r4, [fp, #-132]
	ldr r4, [fp, #-132]
	ldr r4, [r4, #0]
	str r4, [fp, #-132]
	mov r4, #0
	mov32 r4, a5
	str r4, [fp, #-136]
	ldr r4, [fp, #-136]
	ldr r4, [r4, #0]
	str r4, [fp, #-136]
	mov r4, #0
	mov32 r4, a4
	str r4, [fp, #-140]
	ldr r4, [fp, #-140]
	ldr r4, [r4, #0]
	str r4, [fp, #-140]
	mov r4, #0
	mov32 r4, a3
	str r4, [fp, #-40]
	ldr r4, [fp, #-40]
	ldr r4, [r4, #0]
	str r4, [fp, #-40]
	ldr r4, [fp, #-40]
	mov r3, r4
	mov r4, #0
	mov32 r4, a2
	str r4, [fp, #-44]
	ldr r4, [fp, #-44]
	ldr r4, [r4, #0]
	str r4, [fp, #-44]
	ldr r4, [fp, #-44]
	mov r2, r4
	mov r4, #0
	mov32 r4, a1
	str r4, [fp, #-48]
	ldr r4, [fp, #-48]
	ldr r4, [r4, #0]
	str r4, [fp, #-48]
	ldr r4, [fp, #-48]
	mov r1, r4
	mov r4, #0
	mov32 r4, a0
	str r4, [fp, #-52]
	ldr r4, [fp, #-52]
	ldr r4, [r4, #0]
	str r4, [fp, #-52]
	ldr r4, [fp, #-52]
	mov r0, r4
	ldr r4, [fp, #-56]
	push {r4}
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	push {r10}
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
	ldr r9, [fp, #-104]
	push {r9}
	ldr r9, [fp, #-108]
	push {r9}
	ldr r9, [fp, #-112]
	push {r9}
	ldr r9, [fp, #-116]
	push {r9}
	ldr r9, [fp, #-120]
	push {r9}
	ldr r9, [fp, #-124]
	push {r9}
	ldr r9, [fp, #-128]
	push {r9}
	ldr r9, [fp, #-132]
	push {r9}
	ldr r9, [fp, #-136]
	push {r9}
	ldr r9, [fp, #-140]
	push {r9}
	bl testParam32
	mov r9, r0
	add sp, sp, #112
	mov r8, #0
	mov32 r8, a0
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, a0
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, a0
	ldr r9, [r9, #0]
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
	sub r9, r9, r8
	mov r8, r6
	sub r9, r9, r8
	mov r8, r5
	sub r9, r9, r8
	mov r8, r10
	sub r9, r9, r8
	ldr r8, [fp, #-40]
	mov r8, r8
	sub r9, r9, r8
	ldr r8, [fp, #-44]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-48]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-52]
	mov r8, r8
	add r9, r9, r8
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
	mov r9, r9
	ldr r4, [fp, #-100]
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
	add r9, r9, r8
	ldr r8, [fp, #-128]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-132]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-136]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-140]
	mov r8, r8
	add r9, r9, r8
	ldr r8, [fp, #-144]
	mov r8, r8
	add r9, r9, r8
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
	sub r9, r9, r8
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