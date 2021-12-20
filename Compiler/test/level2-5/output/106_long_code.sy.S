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
.globl n
n:
.word 0

.globl QuickSort
.type QuickSort, %function
QuickSort:
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
	mov r8, #136
	sub sp, sp, r8
.LBQuickSort:
	mov r9, r0
	str r9, [fp, #-116]
	mov r9, r1
	str r9, [fp, #-136]
	mov r9, r2
	ldr r8, [fp, #-136]
	cmp r8, r9
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_QuickSort5_ELSE
	b .LBB_QuickSort5_IF
.LBB_QuickSort5_IF:
	ldr r7, [fp, #-136]
	mov r8, r7
	mov r7, r9
	mov r5, #4
	mov r5, r5
	ldr r10, [fp, #-136]
	mul r5, r10, r5
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r5, [r10, r5]
	mov r6, r5
.LB_6_LOOP_BEGIN:
	cmp r8, r7
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	cmp r5, r10
	beq .LB6_LOOP_END
	b .LB6_LOOP_BODY
.LB6_LOOP_BODY:
.LB_7_LOOP_BEGIN:
	cmp r8, r7
	mov r5, #0
	bge .LB_16_COND_END
	mov r10, #4
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	mov r10, r10
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	mul r10, r7, r10
	str r10, [fp, #-20]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	ldr r4, [fp, #-20]
	str r4, [fp, #-120]
	ldr r4, [fp, #-120]
	ldr r10, [r10, r4]
	str r10, [fp, #-24]
	sub r10, r6, #1
	str r10, [fp, #-28]
	ldr r10, [fp, #-24]
	ldr r4, [fp, #-28]
	str r4, [fp, #-120]
	ldr r4, [fp, #-120]
	cmp r10, r4
	mov r10, #0
	movgt r10, #1
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	mov r5, r10
.LB_16_COND_END:
	mov r10, #0
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	cmp r5, r10
	beq .LB7_LOOP_END
	b .LB7_LOOP_BODY
.LB7_LOOP_BODY:
	sub r5, r7, #1
	mov r7, r5
	b .LB_7_LOOP_BEGIN
.LB7_LOOP_END:
	cmp r8, r7
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	cmp r5, r10
	beq .LBB_8_ELSE
	b .LBB_8_IF
.LBB_8_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	mov r10, r10
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	mul r10, r8, r10
	str r10, [fp, #-56]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-60]
	ldr r10, [fp, #-56]
	ldr r4, [fp, #-60]
	str r4, [fp, #-124]
	ldr r4, [fp, #-124]
	str r5, [r4, r10]
	add r5, r8, #1
	mov r8, r5
.LBB_8_ELSE:
.LB_9_LOOP_BEGIN:
	cmp r8, r7
	mov r5, #0
	bge .LB_32_COND_END
	mov r10, #4
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	mov r10, r10
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	mul r10, r8, r10
	str r10, [fp, #-72]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-76]
	ldr r10, [fp, #-72]
	ldr r4, [fp, #-76]
	str r4, [fp, #-128]
	ldr r4, [fp, #-128]
	ldr r10, [r4, r10]
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	cmp r10, r6
	mov r10, #0
	movlt r10, #1
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	mov r5, r10
.LB_32_COND_END:
	mov r10, #0
	str r10, [fp, #-88]
	ldr r10, [fp, #-88]
	cmp r5, r10
	beq .LB9_LOOP_END
	b .LB9_LOOP_BODY
.LB9_LOOP_BODY:
	add r5, r8, #1
	mov r8, r5
	b .LB_9_LOOP_BEGIN
.LB9_LOOP_END:
	cmp r8, r7
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	cmp r5, r10
	beq .LBB_10_ELSE
	b .LBB_10_IF
.LBB_10_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	mov r10, r10
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	mul r10, r7, r10
	str r10, [fp, #-108]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-112]
	ldr r10, [fp, #-108]
	ldr r4, [fp, #-112]
	str r4, [fp, #-132]
	ldr r4, [fp, #-132]
	str r5, [r4, r10]
	sub r5, r7, #1
	mov r7, r5
.LBB_10_ELSE:
	b .LB_6_LOOP_BEGIN
.LB6_LOOP_END:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	ldr r5, [fp, #-116]
	mov r5, r5
	str r6, [r5, r7]
	sub r6, r8, #1
	mov r7, r6
	mov r2, r7
	ldr r7, [fp, #-136]
	mov r1, r7
	ldr r7, [fp, #-116]
	mov r0, r7
	bl QuickSort
	mov r7, r0
	add sp, sp, #0
	mov r7, r7
	add r8, r8, #1
	mov r7, r8
	mov r2, r9
	mov r1, r7
	ldr r8, [fp, #-116]
	mov r0, r8
	bl QuickSort
	mov r8, r0
	add sp, sp, #0
	mov r8, r8
.LBB_QuickSort5_ELSE:
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

.globl arrCopy
.type arrCopy, %function
arrCopy:
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
.LBarrCopy:
	mov r9, r0
	mov r8, r1
	mov r7, #0
.LB_arrCopy16_LOOP_BEGIN:
	mov r6, #0
	mov32 r6, n
	ldr r6, [r6, #0]
	cmp r7, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB16_LOOP_END
	b .LB16_LOOP_BODY
.LB16_LOOP_BODY:
	mov r6, #4
	mov r6, r6
	mul r6, r7, r6
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r8
	str r6, [r10, r5]
	add r6, r7, #1
	mov r7, r6
	b .LB_arrCopy16_LOOP_BEGIN
.LB16_LOOP_END:
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

.globl avgPooling
.type avgPooling, %function
avgPooling:
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
	mov r8, #12
	sub sp, sp, r8
.LBavgPooling:
	mov r9, r0
	str r9, [fp, #-12]
	mov r9, r1
	mov r7, #0
	mov r8, #0
.LB_avgPooling19_LOOP_BEGIN:
	mov r5, #0
	mov32 r5, n
	ldr r5, [r5, #0]
	cmp r7, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB19_LOOP_END
	b .LB19_LOOP_BODY
.LB19_LOOP_BODY:
	sub r5, r9, #1
	cmp r7, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_20_ELSE
	b .LBB_20_IF
.LBB_20_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	ldr r10, [fp, #-12]
	mov r10, r10
	ldr r5, [r10, r5]
	mov r5, r5
	add r5, r8, r5
	mov r8, r5
	b .LBB_20_END_IF
.LBB_20_ELSE:
	sub r5, r9, #1
	cmp r7, r5
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_21_ELSE
	b .LBB_21_IF
.LBB_21_IF:
	mov r5, #0
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	ldr r10, [fp, #-12]
	mov r10, r10
	ldr r5, [r10, r5]
	mov r6, r5
	mov r5, r0
	mov r10, r1
	mov r0, r8
	mov r1, r9
	bl __aeabi_idiv
	mov r4, r0
	str r4, [fp, #-4]
	mov r0, r5
	mov r1, r10
	mov r5, #0
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	ldr r10, [fp, #-12]
	mov r10, r10
	ldr r4, [fp, #-4]
	str r4, [r10, r5]
	b .LBB_21_END_IF
.LBB_21_ELSE:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	ldr r10, [fp, #-12]
	mov r10, r10
	ldr r5, [r10, r5]
	mov r5, r5
	add r5, r8, r5
	mov r10, r6
	sub r5, r5, r10
	mov r8, r5
	mov r5, r9
	sub r5, r7, r5
	add r5, r5, #1
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	ldr r10, [fp, #-12]
	mov r10, r10
	ldr r5, [r10, r5]
	mov r6, r5
	mov r5, r0
	mov r10, r1
	mov r0, r8
	mov r1, r9
	bl __aeabi_idiv
	mov r4, r0
	str r4, [fp, #-4]
	mov r0, r5
	mov r1, r10
	mov r5, r9
	sub r5, r7, r5
	add r5, r5, #1
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	ldr r10, [fp, #-12]
	mov r10, r10
	ldr r4, [fp, #-4]
	str r4, [r10, r5]
	b .LBB_21_END_IF
.LBB_21_END_IF:
	b .LBB_20_END_IF
.LBB_20_END_IF:
	add r5, r7, #1
	mov r7, r5
	b .LB_avgPooling19_LOOP_BEGIN
.LB19_LOOP_END:
	mov r5, #0
	mov32 r5, n
	ldr r5, [r5, #0]
	mov r10, r9
	sub r5, r5, r10
	add r5, r5, #1
	mov r7, r5
.LB_22_LOOP_BEGIN:
	mov r5, #0
	mov32 r5, n
	ldr r5, [r5, #0]
	cmp r7, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB22_LOOP_END
	b .LB22_LOOP_BODY
.LB22_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	ldr r10, [fp, #-12]
	mov r10, r10
	mov r4, #0
	str r4, [fp, #-8]
	ldr r4, [fp, #-8]
	str r4, [r10, r5]
	add r5, r7, #1
	mov r7, r5
	b .LB_22_LOOP_BEGIN
.LB22_LOOP_END:
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

.globl bubblesort
.type bubblesort, %function
bubblesort:
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
.LBbubblesort:
	mov r9, r0
	mov r8, #0
.LB_bubblesort0_LOOP_BEGIN:
	mov r6, #0
	mov32 r6, n
	ldr r6, [r6, #0]
	sub r6, r6, #1
	cmp r8, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r7, #0
.LB_1_LOOP_BEGIN:
	mov r6, #0
	mov32 r6, n
	ldr r6, [r6, #0]
	mov r5, r8
	sub r6, r6, r5
	sub r6, r6, #1
	cmp r7, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r6, #4
	mov r6, r6
	mul r6, r7, r6
	mov r5, r9
	ldr r6, [r5, r6]
	add r5, r7, #1
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, r9
	ldr r5, [r10, r5]
	cmp r6, r5
	mov r6, #0
	movgt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
	add r5, r7, #1
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, r9
	ldr r5, [r10, r5]
	mov r6, r5
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r9
	ldr r5, [r10, r5]
	add r10, r7, #1
	mov r4, #4
	mov r4, r4
	mul r10, r10, r4
	mov r4, r9
	str r5, [r4, r10]
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r9
	str r6, [r10, r5]
.LBB_2_ELSE:
	add r6, r7, #1
	mov r7, r6
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	add r6, r8, #1
	mov r8, r6
	b .LB_bubblesort0_LOOP_BEGIN
.LB0_LOOP_END:
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

.globl calSum
.type calSum, %function
calSum:
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
.LBcalSum:
	mov r9, r0
	mov r8, r1
	mov r7, #0
	mov r6, #0
.LB_calSum17_LOOP_BEGIN:
	mov r5, #0
	mov32 r5, n
	ldr r5, [r5, #0]
	cmp r6, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB17_LOOP_END
	b .LB17_LOOP_BODY
.LB17_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r5, r5
	add r5, r7, r5
	mov r7, r5
	mov r5, r0
	mov r10, r1
	mov r0, r6
	mov r1, r8
	bl __aeabi_idivmod
	mov r4, r1
	mov r0, r5
	mov r1, r10
	sub r5, r8, #1
	cmp r4, r5
	mov r5, #0
	movne r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_18_ELSE
	b .LBB_18_IF
.LBB_18_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, r9
	mov r4, #0
	str r4, [r10, r5]
	b .LBB_18_END_IF
.LBB_18_ELSE:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, r9
	str r7, [r10, r5]
	mov r7, #0
	b .LBB_18_END_IF
.LBB_18_END_IF:
	add r5, r6, #1
	mov r6, r5
	b .LB_calSum17_LOOP_BEGIN
.LB17_LOOP_END:
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

.globl getMid
.type getMid, %function
getMid:
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
.LBgetMid:
	mov r9, r0
	mov r7, #0
	mov32 r7, n
	ldr r7, [r7, #0]
	mov r6, r0
	mov r5, r1
	mov r0, r7
	mov r1, #2
	bl __aeabi_idivmod
	mov r7, r1
	mov r0, r6
	mov r1, r5
	mov r6, #0
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_getMid11_ELSE
	b .LBB_getMid11_IF
.LBB_getMid11_IF:
	mov r7, #0
	mov32 r7, n
	ldr r7, [r7, #0]
	mov r6, r0
	mov r5, r1
	mov r0, r7
	mov r1, #2
	bl __aeabi_idiv
	mov r7, r0
	mov r0, r6
	mov r1, r5
	mov r8, r7
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, r9
	ldr r7, [r6, r7]
	sub r6, r8, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r6, r6
	add r7, r7, r6
	mov r6, r0
	mov r5, r1
	mov r0, r7
	mov r1, #2
	bl __aeabi_idiv
	mov r7, r0
	mov r0, r6
	mov r1, r5
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
.LBB_getMid11_ELSE:
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	mov r7, r0
	mov r6, r1
	mov r0, r8
	mov r1, #2
	bl __aeabi_idiv
	mov r8, r0
	mov r0, r7
	mov r1, r6
	mov r8, r8
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r9, r9
	ldr r9, [r9, r8]
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

.globl getMost
.type getMost, %function
getMost:
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
.LBgetMost:
	mov r9, r0
	str r9, [fp, #-8]
	sub sp, sp, #4000
	mov r9, #0
.LB_getMost12_LOOP_BEGIN:
	mov r8, #1000
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB12_LOOP_END
	b .LB12_LOOP_BODY
.LB12_LOOP_BODY:
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #0
	mov r6, #0
	str r6, [r7, r8]
	add r8, r9, #1
	mov r9, r8
	b .LB_getMost12_LOOP_BEGIN
.LB12_LOOP_END:
	mov r9, #0
	mov r8, #0
.LB_13_LOOP_BEGIN:
	mov r6, #0
	mov32 r6, n
	ldr r6, [r6, #0]
	cmp r9, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB13_LOOP_END
	b .LB13_LOOP_BODY
.LB13_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r9, r5
	ldr r10, [fp, #-8]
	mov r10, r10
	ldr r5, [r10, r5]
	mov r6, r5
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, sp
	add r10, r10, #0
	ldr r5, [r10, r5]
	add r5, r5, #1
	mov r10, #4
	mov r10, r10
	mul r10, r6, r10
	mov r4, sp
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	add r4, r4, #0
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	str r5, [r4, r10]
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, sp
	add r10, r10, #0
	ldr r5, [r10, r5]
	cmp r5, r8
	mov r5, #0
	movgt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_14_ELSE
	b .LBB_14_IF
.LBB_14_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, sp
	add r10, r10, #0
	ldr r5, [r10, r5]
	mov r8, r5
	mov r7, r6
.LBB_14_ELSE:
	add r6, r9, #1
	mov r9, r6
	b .LB_13_LOOP_BEGIN
.LB13_LOOP_END:
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

.globl insertsort
.type insertsort, %function
insertsort:
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
.LBinsertsort:
	mov r9, r0
	mov r8, #1
.LB_insertsort3_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, n
	ldr r7, [r7, #0]
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, r9
	ldr r6, [r5, r6]
	mov r7, r6
	sub r5, r8, #1
	mov r6, r5
.LB_4_LOOP_BEGIN:
	mov r5, #0
	sub r5, r5, #1
	cmp r6, r5
	mov r5, #0
	ble .LB_11_COND_END
	mov r10, #4
	mov r10, r10
	mul r10, r6, r10
	mov r4, r9
	ldr r10, [r4, r10]
	cmp r7, r10
	mov r10, #0
	movlt r10, #1
	mov r5, r10
.LB_11_COND_END:
	mov r10, #0
	cmp r5, r10
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, r9
	ldr r5, [r10, r5]
	add r10, r6, #1
	mov r4, #4
	mov r4, r4
	mul r10, r10, r4
	mov r4, r9
	str r5, [r4, r10]
	sub r5, r6, #1
	mov r6, r5
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	add r6, r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, r9
	str r7, [r5, r6]
	add r7, r8, #1
	mov r8, r7
	b .LB_insertsort3_LOOP_BEGIN
.LB3_LOOP_END:
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
	mov32 r9, n
	ldr r9, [r9, #0]
	mov r9, #32
	mov r8, #0
	mov32 r8, n
	str r9, [r8, #0]
	sub sp, sp, #128
	sub sp, sp, #128
	mov r9, #0
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #7
	str r7, [r8, r9]
	mov r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #23
	str r7, [r8, r9]
	mov r9, #2
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #89
	str r7, [r8, r9]
	mov r9, #3
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #26
	str r7, [r8, r9]
	mov r9, #4
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #282
	str r7, [r8, r9]
	mov r9, #5
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #254
	str r7, [r8, r9]
	mov r9, #6
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #27
	str r7, [r8, r9]
	mov r9, #7
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #5
	str r7, [r8, r9]
	mov r9, #8
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #83
	str r7, [r8, r9]
	mov r9, #9
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #273
	str r7, [r8, r9]
	mov r9, #10
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #574
	str r7, [r8, r9]
	mov r9, #11
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #905
	str r7, [r8, r9]
	mov r9, #12
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #354
	str r7, [r8, r9]
	mov r9, #13
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #657
	str r7, [r8, r9]
	mov r9, #14
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #935
	str r7, [r8, r9]
	mov r9, #15
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #264
	str r7, [r8, r9]
	mov r9, #16
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #639
	str r7, [r8, r9]
	mov r9, #17
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #459
	str r7, [r8, r9]
	mov r9, #18
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #29
	str r7, [r8, r9]
	mov r9, #19
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #68
	str r7, [r8, r9]
	mov r9, #20
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #929
	str r7, [r8, r9]
	mov r9, #21
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #756
	str r7, [r8, r9]
	mov r9, #22
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #452
	str r7, [r8, r9]
	mov r9, #23
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #279
	str r7, [r8, r9]
	mov r9, #24
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #58
	str r7, [r8, r9]
	mov r9, #25
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #87
	str r7, [r8, r9]
	mov r9, #26
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #96
	str r7, [r8, r9]
	mov r9, #27
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #36
	str r7, [r8, r9]
	mov r9, #28
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #39
	str r7, [r8, r9]
	mov r9, #29
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #28
	str r7, [r8, r9]
	mov r9, #30
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #1
	str r7, [r8, r9]
	mov r9, #31
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, sp
	add r8, r8, #128
	mov r7, #290
	str r7, [r8, r9]
	add r8, sp, #0
	mov r1, r8
	add r8, sp, #128
	mov r0, r8
	bl arrCopy
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	add r8, sp, #0
	mov r0, r8
	bl revert
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #0
.LB_main23_LOOP_BEGIN:
	mov r7, #32
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB23_LOOP_END
	b .LB23_LOOP_BODY
.LB23_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_main23_LOOP_BEGIN
.LB23_LOOP_END:
	add r9, sp, #0
	mov r0, r9
	bl bubblesort
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r8, #0
.LB_24_LOOP_BEGIN:
	mov r7, #32
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB24_LOOP_END
	b .LB24_LOOP_BODY
.LB24_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_24_LOOP_BEGIN
.LB24_LOOP_END:
	add r9, sp, #0
	mov r0, r9
	bl getMid
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	add r9, sp, #0
	mov r0, r9
	bl getMost
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r0, r9
	bl putint
	mov r9, r0
	add sp, sp, #0
	add r9, sp, #0
	mov r1, r9
	add r9, sp, #128
	mov r0, r9
	bl arrCopy
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	add r8, sp, #0
	mov r0, r8
	bl bubblesort
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #0
.LB_25_LOOP_BEGIN:
	mov r7, #32
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB25_LOOP_END
	b .LB25_LOOP_BODY
.LB25_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_25_LOOP_BEGIN
.LB25_LOOP_END:
	add r9, sp, #0
	mov r1, r9
	add r9, sp, #128
	mov r0, r9
	bl arrCopy
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	add r8, sp, #0
	mov r0, r8
	bl insertsort
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #0
.LB_26_LOOP_BEGIN:
	mov r7, #32
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB26_LOOP_END
	b .LB26_LOOP_BODY
.LB26_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_26_LOOP_BEGIN
.LB26_LOOP_END:
	add r9, sp, #0
	mov r1, r9
	add r9, sp, #128
	mov r0, r9
	bl arrCopy
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r8, #0
	mov r9, #31
	mov r2, r9
	mov r1, r8
	add r9, sp, #0
	mov r0, r9
	bl QuickSort
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
.LB_27_LOOP_BEGIN:
	mov r7, #32
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB27_LOOP_END
	b .LB27_LOOP_BODY
.LB27_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_27_LOOP_BEGIN
.LB27_LOOP_END:
	add r9, sp, #0
	mov r1, r9
	add r9, sp, #128
	mov r0, r9
	bl arrCopy
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r1, #4
	add r8, sp, #0
	mov r0, r8
	bl calSum
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #0
.LB_28_LOOP_BEGIN:
	mov r7, #32
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB28_LOOP_END
	b .LB28_LOOP_BODY
.LB28_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_28_LOOP_BEGIN
.LB28_LOOP_END:
	add r9, sp, #0
	mov r1, r9
	add r9, sp, #128
	mov r0, r9
	bl arrCopy
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	mov r1, #3
	add r8, sp, #0
	mov r0, r8
	bl avgPooling
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	mov r8, #0
.LB_29_LOOP_BEGIN:
	mov r7, #32
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB29_LOOP_END
	b .LB29_LOOP_BODY
.LB29_LOOP_BODY:
	mov r7, #4
	mov r7, r7
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add sp, sp, #0
	add r7, r8, #1
	mov r8, r7
	b .LB_29_LOOP_BEGIN
.LB29_LOOP_END:
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

.globl revert
.type revert, %function
revert:
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
.LBrevert:
	mov r9, r0
	mov r7, #0
	mov r6, #0
.LB_revert15_LOOP_BEGIN:
	cmp r7, r6
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB15_LOOP_END
	b .LB15_LOOP_BODY
.LB15_LOOP_BODY:
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r8, r5
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, r9
	ldr r5, [r10, r5]
	mov r10, #4
	mov r10, r10
	mul r10, r7, r10
	mov r4, r9
	str r5, [r4, r10]
	mov r5, #4
	mov r5, r5
	mul r5, r6, r5
	mov r10, r9
	str r8, [r10, r5]
	add r5, r7, #1
	mov r7, r5
	sub r5, r6, #1
	mov r6, r5
	b .LB_revert15_LOOP_BEGIN
.LB15_LOOP_END:
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