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
.globl func1
.type func1, %function
func1:
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
.LBfunc1:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, #0
	cmp r7, r6
	mov r6, #0
	moveq r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_func10_ELSE
	b .LBB_func10_IF
.LBB_func10_IF:
	mov r6, r8
	mul r6, r9, r6
	mov r0, r6
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
.LBB_func10_ELSE:
	mov r7, r7
	sub r8, r8, r7
	mov r2, #0
	mov r1, r8
	mov r0, r9
	bl func1
	mov r9, r0
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

.globl func2
.type func2, %function
func2:
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
.LBfunc2:
	mov r9, r0
	mov r8, r1
	mov r7, #0
	cmp r8, r7
	beq .LBB_func21_ELSE
	b .LBB_func21_IF
.LBB_func21_IF:
	mov r7, r0
	mov r6, r1
	mov r0, r9
	mov r1, r8
	bl __aeabi_idivmod
	mov r5, r1
	mov r0, r7
	mov r1, r6
	mov r1, #0
	mov r0, r5
	bl func2
	mov r7, r0
	add sp, sp, #0
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
.LBB_func21_ELSE:
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

.globl func3
.type func3, %function
func3:
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
.LBfunc3:
	mov r9, r0
	mov r8, r1
	mov r7, #0
	cmp r8, r7
	mov r7, #0
	moveq r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LBB_func32_ELSE
	b .LBB_func32_IF
.LBB_func32_IF:
	add r7, r9, #1
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
.LBB_func32_ELSE:
	mov r8, r8
	add r9, r9, r8
	mov r1, #0
	mov r0, r9
	bl func3
	mov r9, r0
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

.globl func4
.type func4, %function
func4:
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
.LBfunc4:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, #0
	cmp r9, r6
	beq .LBB_func43_ELSE
	b .LBB_func43_IF
.LBB_func43_IF:
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
.LBB_func43_ELSE:
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

.globl func5
.type func5, %function
func5:
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
.LBfunc5:
	mov r9, r0
	mov r8, #0
	mov r9, r9
	sub r9, r8, r9
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

.globl func6
.type func6, %function
func6:
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
.LBfunc6:
	mov r9, r0
	mov r8, r1
	mov r7, #0
	cmp r9, r7
	mov r9, #0
	beq .LB_func64_COND_END
	mov r9, r8
.LB_func64_COND_END:
	mov r8, #0
	cmp r9, r8
	beq .LBB_func64_ELSE
	b .LBB_func64_IF
.LBB_func64_IF:
	mov r0, #1
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
.LBB_func64_ELSE:
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

.globl func7
.type func7, %function
func7:
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
.LBfunc7:
	mov r9, r0
	mov r8, #0
	cmp r8, r9
	mov r9, #0
	moveq r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_func75_ELSE
	b .LBB_func75_IF
.LBB_func75_IF:
	mov r0, #1
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
.LBB_func75_ELSE:
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
	mov r8, #360
	sub sp, sp, r8
.LBmain:
	str r9, [fp, #-288]
	bl getint
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	str r9, [fp, #-288]
	bl getint
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	bl getint
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
	bl getint
	mov r6, r0
	add sp, sp, #0
	mov r7, r6
	sub sp, sp, #40
	mov r6, #0
.LB_main6_LOOP_BEGIN:
	mov r5, #10
	cmp r6, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LB6_LOOP_END
	b .LB6_LOOP_BODY
.LB6_LOOP_BODY:
	bl getint
	mov r5, r0
	add sp, sp, #0
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
	add r5, r6, #1
	mov r6, r5
	b .LB_main6_LOOP_BEGIN
.LB6_LOOP_END:
	str r6, [fp, #-360]
	ldr r6, [fp, #-288]
	mov r0, r6
	bl func7
	mov r6, r0
	add sp, sp, #0
	mov r0, r9
	bl func5
	mov r5, r0
	add sp, sp, #0
	mov r1, r5
	mov r0, r6
	bl func6
	mov r6, r0
	add sp, sp, #0
	mov r1, r8
	mov r0, r6
	bl func2
	mov r6, r0
	add sp, sp, #0
	mov r1, r7
	mov r0, r6
	bl func3
	mov r6, r0
	add sp, sp, #0
	mov r0, r6
	bl func5
	mov r6, r0
	add sp, sp, #0
	mov r5, #0
	mov r10, #4
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mov r10, r10
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	mul r5, r5, r10
	mov r10, sp
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	add r10, r10, #0
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	ldr r5, [r10, r5]
	mov r10, #1
	str r10, [fp, #-20]
	mov r10, #4
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	mov r10, r10
	str r10, [fp, #-24]
	ldr r10, [fp, #-20]
	ldr r4, [fp, #-24]
	str r4, [fp, #-292]
	ldr r4, [fp, #-292]
	mul r10, r10, r4
	str r10, [fp, #-32]
	mov r10, sp
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	add r10, r10, #0
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	ldr r4, [fp, #-32]
	str r4, [fp, #-292]
	ldr r4, [fp, #-292]
	ldr r10, [r10, r4]
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	mov r0, r10
	bl func5
	mov r10, r0
	str r10, [fp, #-152]
	add sp, sp, #0
	mov r10, #2
	str r10, [fp, #-44]
	mov r10, #4
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	mov r10, r10
	str r10, [fp, #-48]
	ldr r10, [fp, #-44]
	ldr r4, [fp, #-48]
	str r4, [fp, #-296]
	ldr r4, [fp, #-296]
	mul r10, r10, r4
	str r10, [fp, #-56]
	mov r10, sp
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	add r10, r10, #0
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	ldr r4, [fp, #-56]
	str r4, [fp, #-300]
	ldr r4, [fp, #-300]
	ldr r10, [r10, r4]
	str r10, [fp, #-88]
	mov r10, #3
	str r10, [fp, #-68]
	mov r10, #4
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	mov r10, r10
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	ldr r4, [fp, #-68]
	str r4, [fp, #-304]
	ldr r4, [fp, #-304]
	mul r10, r4, r10
	str r10, [fp, #-76]
	mov r10, sp
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	add r10, r10, #0
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	ldr r4, [fp, #-76]
	str r4, [fp, #-308]
	ldr r4, [fp, #-308]
	ldr r10, [r10, r4]
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	mov r0, r10
	bl func7
	mov r10, r0
	str r10, [fp, #-84]
	add sp, sp, #0
	ldr r10, [fp, #-84]
	mov r1, r10
	ldr r10, [fp, #-88]
	mov r0, r10
	bl func6
	mov r10, r0
	str r10, [fp, #-148]
	add sp, sp, #0
	mov r10, #4
	str r10, [fp, #-96]
	mov r10, #4
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	mov r10, r10
	str r10, [fp, #-100]
	ldr r10, [fp, #-96]
	ldr r4, [fp, #-100]
	str r4, [fp, #-312]
	ldr r4, [fp, #-312]
	mul r10, r10, r4
	str r10, [fp, #-104]
	mov r10, sp
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	add r10, r10, #0
	str r10, [fp, #-108]
	ldr r10, [fp, #-104]
	ldr r4, [fp, #-108]
	str r4, [fp, #-316]
	ldr r4, [fp, #-316]
	ldr r10, [r4, r10]
	str r10, [fp, #-140]
	mov r10, #5
	str r10, [fp, #-116]
	mov r10, #4
	str r10, [fp, #-112]
	ldr r10, [fp, #-112]
	mov r10, r10
	str r10, [fp, #-120]
	ldr r10, [fp, #-116]
	ldr r4, [fp, #-120]
	str r4, [fp, #-320]
	ldr r4, [fp, #-320]
	mul r10, r10, r4
	str r10, [fp, #-124]
	mov r10, sp
	str r10, [fp, #-128]
	ldr r10, [fp, #-128]
	add r10, r10, #0
	str r10, [fp, #-128]
	ldr r10, [fp, #-124]
	ldr r4, [fp, #-128]
	str r4, [fp, #-324]
	ldr r4, [fp, #-324]
	ldr r10, [r4, r10]
	str r10, [fp, #-132]
	ldr r10, [fp, #-132]
	mov r0, r10
	bl func7
	mov r10, r0
	str r10, [fp, #-136]
	add sp, sp, #0
	ldr r10, [fp, #-136]
	mov r1, r10
	ldr r10, [fp, #-140]
	mov r0, r10
	bl func2
	mov r10, r0
	str r10, [fp, #-144]
	add sp, sp, #0
	ldr r10, [fp, #-144]
	mov r2, r10
	ldr r10, [fp, #-148]
	mov r1, r10
	ldr r10, [fp, #-152]
	mov r0, r10
	bl func4
	mov r10, r0
	str r10, [fp, #-180]
	add sp, sp, #0
	mov r10, #6
	str r10, [fp, #-160]
	mov r10, #4
	str r10, [fp, #-156]
	ldr r10, [fp, #-156]
	mov r10, r10
	str r10, [fp, #-164]
	ldr r10, [fp, #-160]
	ldr r4, [fp, #-164]
	str r4, [fp, #-328]
	ldr r4, [fp, #-328]
	mul r10, r10, r4
	str r10, [fp, #-168]
	mov r10, sp
	str r10, [fp, #-172]
	ldr r10, [fp, #-172]
	add r10, r10, #0
	str r10, [fp, #-172]
	ldr r10, [fp, #-168]
	ldr r4, [fp, #-172]
	str r4, [fp, #-332]
	ldr r4, [fp, #-332]
	ldr r10, [r4, r10]
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	mov r1, r10
	ldr r10, [fp, #-180]
	mov r0, r10
	bl func3
	mov r10, r0
	str r10, [fp, #-208]
	add sp, sp, #0
	mov r10, #7
	str r10, [fp, #-188]
	mov r10, #4
	str r10, [fp, #-184]
	ldr r10, [fp, #-184]
	mov r10, r10
	str r10, [fp, #-192]
	ldr r10, [fp, #-188]
	ldr r4, [fp, #-192]
	str r4, [fp, #-336]
	ldr r4, [fp, #-336]
	mul r10, r10, r4
	str r10, [fp, #-196]
	mov r10, sp
	str r10, [fp, #-200]
	ldr r10, [fp, #-200]
	add r10, r10, #0
	str r10, [fp, #-200]
	ldr r10, [fp, #-196]
	ldr r4, [fp, #-200]
	str r4, [fp, #-340]
	ldr r4, [fp, #-340]
	ldr r10, [r4, r10]
	str r10, [fp, #-204]
	ldr r10, [fp, #-204]
	mov r1, r10
	ldr r10, [fp, #-208]
	mov r0, r10
	bl func2
	mov r10, r0
	str r10, [fp, #-268]
	add sp, sp, #0
	mov r10, #8
	str r10, [fp, #-216]
	mov r10, #4
	str r10, [fp, #-212]
	ldr r10, [fp, #-212]
	mov r10, r10
	str r10, [fp, #-220]
	ldr r10, [fp, #-216]
	ldr r4, [fp, #-220]
	str r4, [fp, #-344]
	ldr r4, [fp, #-344]
	mul r10, r10, r4
	str r10, [fp, #-224]
	mov r10, sp
	str r10, [fp, #-228]
	ldr r10, [fp, #-228]
	add r10, r10, #0
	str r10, [fp, #-228]
	ldr r10, [fp, #-224]
	ldr r4, [fp, #-228]
	str r4, [fp, #-348]
	ldr r4, [fp, #-348]
	ldr r10, [r4, r10]
	str r10, [fp, #-260]
	mov r10, #9
	str r10, [fp, #-236]
	mov r10, #4
	str r10, [fp, #-232]
	ldr r10, [fp, #-232]
	mov r10, r10
	str r10, [fp, #-240]
	ldr r10, [fp, #-236]
	ldr r4, [fp, #-240]
	str r4, [fp, #-352]
	ldr r4, [fp, #-352]
	mul r10, r10, r4
	str r10, [fp, #-248]
	mov r10, sp
	str r10, [fp, #-244]
	ldr r10, [fp, #-244]
	add r10, r10, #0
	str r10, [fp, #-244]
	ldr r10, [fp, #-244]
	ldr r4, [fp, #-248]
	str r4, [fp, #-356]
	ldr r4, [fp, #-356]
	ldr r10, [r10, r4]
	str r10, [fp, #-252]
	ldr r10, [fp, #-252]
	mov r0, r10
	bl func7
	mov r10, r0
	str r10, [fp, #-256]
	add sp, sp, #0
	ldr r10, [fp, #-256]
	mov r1, r10
	ldr r10, [fp, #-260]
	mov r0, r10
	bl func3
	mov r10, r0
	str r10, [fp, #-264]
	add sp, sp, #0
	ldr r10, [fp, #-288]
	mov r2, r10
	ldr r10, [fp, #-264]
	mov r1, r10
	ldr r10, [fp, #-268]
	mov r0, r10
	bl func1
	mov r10, r0
	str r10, [fp, #-272]
	add sp, sp, #0
	ldr r10, [fp, #-272]
	mov r2, r10
	mov r1, r5
	mov r0, r6
	bl func4
	mov r6, r0
	add sp, sp, #0
	mov r0, r8
	bl func7
	mov r8, r0
	add sp, sp, #0
	mov r1, r7
	mov r0, r8
	bl func3
	mov r8, r0
	add sp, sp, #0
	mov r1, r8
	mov r0, r9
	bl func2
	mov r9, r0
	add sp, sp, #0
	mov r1, r9
	mov r0, r6
	bl func3
	mov r9, r0
	add sp, sp, #0
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, sp
	add r7, r7, #0
	ldr r8, [r7, r8]
	mov r7, #1
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r2, r7
	mov r1, r8
	mov r0, r9
	bl func1
	mov r9, r0
	add sp, sp, #0
	mov r8, #2
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, sp
	add r7, r7, #0
	ldr r8, [r7, r8]
	mov r1, r8
	mov r0, r9
	bl func2
	mov r9, r0
	add sp, sp, #0
	mov r8, #3
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, sp
	add r7, r7, #0
	ldr r8, [r7, r8]
	mov r7, #4
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, sp
	add r6, r6, #0
	ldr r7, [r6, r7]
	mov r6, #5
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, sp
	add r5, r5, #0
	ldr r6, [r5, r6]
	mov r0, r6
	bl func5
	mov r6, r0
	add sp, sp, #0
	mov r1, r6
	mov r0, r7
	bl func3
	mov r7, r0
	add sp, sp, #0
	mov r6, #6
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, sp
	add r5, r5, #0
	ldr r6, [r5, r6]
	mov r0, r6
	bl func5
	mov r6, r0
	add sp, sp, #0
	mov r1, r6
	mov r0, r7
	bl func2
	mov r7, r0
	add sp, sp, #0
	mov r6, #7
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, sp
	add r5, r5, #0
	ldr r6, [r5, r6]
	mov r5, #8
	mov r10, #4
	str r10, [fp, #-276]
	ldr r10, [fp, #-276]
	mov r10, r10
	str r10, [fp, #-280]
	ldr r10, [fp, #-280]
	mul r5, r5, r10
	mov r10, sp
	str r10, [fp, #-284]
	ldr r10, [fp, #-284]
	add r10, r10, #0
	str r10, [fp, #-284]
	ldr r10, [fp, #-284]
	ldr r5, [r10, r5]
	mov r0, r5
	bl func7
	mov r5, r0
	add sp, sp, #0
	mov r2, r5
	mov r1, r6
	mov r0, r7
	bl func1
	mov r7, r0
	add sp, sp, #0
	mov r6, #9
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, sp
	add r5, r5, #0
	ldr r6, [r5, r6]
	mov r0, r6
	bl func5
	mov r6, r0
	add sp, sp, #0
	mov r1, r6
	mov r0, r7
	bl func2
	mov r7, r0
	add sp, sp, #0
	ldr r6, [fp, #-288]
	mov r1, r6
	mov r0, r7
	bl func3
	mov r7, r0
	add sp, sp, #0
	mov r2, r7
	mov r1, r8
	mov r0, r9
	bl func1
	mov r9, r0
	add sp, sp, #0
	mov r9, r9
	str r9, [fp, #-360]
	ldr r9, [fp, #-360]
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007223"