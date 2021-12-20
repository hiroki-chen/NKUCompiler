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
	mov r8, #952
	sub sp, sp, r8
.LBmain:
	sub sp, sp, #256
	mov r9, sp
	add r9, r9, #0
	mov r0, r9
	mov r1, #0
	mov r2, #256
	bl memset
	bl getint
	mov r9, r0
	str r9, [fp, #-4]
	add sp, sp, #0
	bl getint
	mov r9, r0
	add sp, sp, #0
	bl getint
	mov r8, r0
	add sp, sp, #0
	bl getint
	mov r7, r0
	add sp, sp, #0
	bl getint
	mov r6, r0
	add sp, sp, #0
	bl getint
	mov r5, r0
	add sp, sp, #0
	bl getint
	mov r10, r0
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-40]
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-36]
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-32]
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-28]
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-24]
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-20]
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-16]
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-12]
	add sp, sp, #0
	bl getint
	mov r4, r0
	str r4, [fp, #-8]
	add sp, sp, #0
	mov r3, r7
	mov r2, r8
	mov r1, r9
	ldr r9, [fp, #-4]
	mov r0, r9
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
	push {r10}
	push {r5}
	push {r6}
	bl param16
	mov r9, r0
	add sp, sp, #48
	mov r8, sp
	add r8, r8, #0
	str r9, [r8, #0]
	mov r9, sp
	add r9, r9, #0
	mov r8, #8848
	str r8, [r9, #4]
	mov r9, #1
.LB_main4_LOOP_BEGIN:
	mov r8, #32
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #8
	sub r6, r9, #1
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, sp
	add r7, r7, #0
	ldr r8, [r7, r8]
	sub r8, r8, #1
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #8
	mov r5, r9
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, sp
	add r6, r6, #0
	str r8, [r6, r7]
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #8
	sub r6, r9, #1
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, sp
	add r7, r7, #0
	ldr r8, [r7, r8]
	sub r8, r8, #2
	mov r7, #1
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #8
	mov r5, r9
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, sp
	add r6, r6, #0
	str r8, [r6, r7]
	add r8, r9, #1
	mov r9, r8
	b .LB_main4_LOOP_BEGIN
.LB4_LOOP_END:
	mov r9, #0
	mov r8, #2
	mov r7, #0
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r8, r8
	str r8, [fp, #-744]
	mov r8, #4
	mov r9, r9
	mul r9, r8, r9
	mov r9, r9
	ldr r8, [fp, #-744]
	add r9, r8, r9
	str r9, [fp, #-744]
	mov r9, #0
	mov r8, #2
	mov r7, #1
	mov r7, r7
	mul r8, r8, r7
	mov r8, r8
	add r9, r9, r8
	mov r8, sp
	add r8, r8, #0
	mov r8, r8
	mov r7, #4
	mov r9, r9
	mul r9, r7, r9
	mov r9, r9
	add r8, r8, r9
	mov r9, #0
	mov r7, #2
	mov r6, #2
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r9, r9, r7
	mov r7, sp
	add r7, r7, #0
	mov r7, r7
	mov r6, #4
	mov r9, r9
	mul r9, r6, r9
	mov r9, r9
	add r7, r7, r9
	mov r9, #0
	mov r6, #2
	mov r5, #3
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r9, r9, r6
	mov r6, sp
	add r6, r6, #0
	mov r6, r6
	mov r5, #4
	mov r9, r9
	mul r9, r5, r9
	mov r9, r9
	add r6, r6, r9
	mov r9, #0
	mov r5, #2
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r9, r9, r5
	mov r5, sp
	add r5, r5, #0
	mov r5, r5
	str r5, [fp, #-952]
	mov r5, #4
	mov r9, r9
	mul r9, r5, r9
	mov r9, r9
	ldr r5, [fp, #-952]
	add r9, r5, r9
	str r9, [fp, #-952]
	mov r9, #0
	mov r5, #2
	mov r10, #5
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mov r10, r10
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	mul r5, r5, r10
	mov r5, r5
	add r9, r9, r5
	mov r5, sp
	add r5, r5, #0
	mov r5, r5
	mov r10, #4
	str r10, [fp, #-12]
	mov r9, r9
	ldr r10, [fp, #-12]
	mul r9, r10, r9
	mov r9, r9
	add r5, r5, r9
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-20]
	mov r10, #6
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	mov r10, r10
	str r10, [fp, #-24]
	ldr r10, [fp, #-20]
	ldr r4, [fp, #-24]
	str r4, [fp, #-852]
	ldr r4, [fp, #-852]
	mul r10, r10, r4
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	mov r10, r10
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	add r10, r10, #0
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	mov r10, r10
	str r10, [fp, #-848]
	mov r10, #4
	str r10, [fp, #-40]
	mov r9, r9
	ldr r10, [fp, #-40]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-848]
	add r9, r10, r9
	str r9, [fp, #-848]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-48]
	mov r10, #7
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	mov r10, r10
	str r10, [fp, #-52]
	ldr r10, [fp, #-48]
	ldr r4, [fp, #-52]
	str r4, [fp, #-852]
	ldr r4, [fp, #-852]
	mul r10, r10, r4
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	mov r10, r10
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	add r10, r10, #0
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	mov r10, r10
	str r10, [fp, #-844]
	mov r10, #4
	str r10, [fp, #-68]
	mov r9, r9
	ldr r10, [fp, #-68]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-844]
	add r9, r10, r9
	str r9, [fp, #-844]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-76]
	mov r10, #8
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	mov r10, r10
	str r10, [fp, #-80]
	ldr r10, [fp, #-76]
	ldr r4, [fp, #-80]
	str r4, [fp, #-856]
	ldr r4, [fp, #-856]
	mul r10, r10, r4
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	mov r10, r10
	str r10, [fp, #-88]
	ldr r10, [fp, #-88]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	add r10, r10, #0
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	mov r10, r10
	str r10, [fp, #-840]
	mov r10, #4
	str r10, [fp, #-96]
	mov r9, r9
	ldr r10, [fp, #-96]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-840]
	add r9, r10, r9
	str r9, [fp, #-840]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-108]
	mov r10, #9
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	mov r10, r10
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	ldr r4, [fp, #-108]
	str r4, [fp, #-860]
	ldr r4, [fp, #-860]
	mul r10, r4, r10
	str r10, [fp, #-112]
	ldr r10, [fp, #-112]
	mov r10, r10
	str r10, [fp, #-116]
	ldr r10, [fp, #-116]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-120]
	ldr r10, [fp, #-120]
	add r10, r10, #0
	str r10, [fp, #-120]
	ldr r10, [fp, #-120]
	mov r10, r10
	str r10, [fp, #-836]
	mov r10, #4
	str r10, [fp, #-124]
	mov r9, r9
	ldr r10, [fp, #-124]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-836]
	add r9, r10, r9
	str r9, [fp, #-836]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-136]
	mov r10, #10
	str r10, [fp, #-128]
	ldr r10, [fp, #-128]
	mov r10, r10
	str r10, [fp, #-132]
	ldr r10, [fp, #-132]
	ldr r4, [fp, #-136]
	str r4, [fp, #-864]
	ldr r4, [fp, #-864]
	mul r10, r4, r10
	str r10, [fp, #-140]
	ldr r10, [fp, #-140]
	mov r10, r10
	str r10, [fp, #-144]
	ldr r10, [fp, #-144]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-148]
	ldr r10, [fp, #-148]
	add r10, r10, #0
	str r10, [fp, #-148]
	ldr r10, [fp, #-148]
	mov r10, r10
	str r10, [fp, #-832]
	mov r10, #4
	str r10, [fp, #-152]
	mov r9, r9
	ldr r10, [fp, #-152]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-832]
	add r9, r10, r9
	str r9, [fp, #-832]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-160]
	mov r10, #11
	str r10, [fp, #-156]
	ldr r10, [fp, #-156]
	mov r10, r10
	str r10, [fp, #-164]
	ldr r10, [fp, #-160]
	ldr r4, [fp, #-164]
	str r4, [fp, #-868]
	ldr r4, [fp, #-868]
	mul r10, r10, r4
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	mov r10, r10
	str r10, [fp, #-172]
	ldr r10, [fp, #-172]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	add r10, r10, #0
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	mov r10, r10
	str r10, [fp, #-828]
	mov r10, #4
	str r10, [fp, #-180]
	mov r9, r9
	ldr r10, [fp, #-180]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-828]
	add r9, r10, r9
	str r9, [fp, #-828]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-188]
	mov r10, #12
	str r10, [fp, #-184]
	ldr r10, [fp, #-184]
	mov r10, r10
	str r10, [fp, #-192]
	ldr r10, [fp, #-188]
	ldr r4, [fp, #-192]
	str r4, [fp, #-872]
	ldr r4, [fp, #-872]
	mul r10, r10, r4
	str r10, [fp, #-196]
	ldr r10, [fp, #-196]
	mov r10, r10
	str r10, [fp, #-200]
	ldr r10, [fp, #-200]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-204]
	ldr r10, [fp, #-204]
	add r10, r10, #0
	str r10, [fp, #-204]
	ldr r10, [fp, #-204]
	mov r10, r10
	str r10, [fp, #-824]
	mov r10, #4
	str r10, [fp, #-208]
	mov r9, r9
	ldr r10, [fp, #-208]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-824]
	add r9, r10, r9
	str r9, [fp, #-824]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-220]
	mov r10, #13
	str r10, [fp, #-212]
	ldr r10, [fp, #-212]
	mov r10, r10
	str r10, [fp, #-216]
	ldr r10, [fp, #-216]
	ldr r4, [fp, #-220]
	str r4, [fp, #-876]
	ldr r4, [fp, #-876]
	mul r10, r4, r10
	str r10, [fp, #-224]
	ldr r10, [fp, #-224]
	mov r10, r10
	str r10, [fp, #-228]
	ldr r10, [fp, #-228]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-232]
	ldr r10, [fp, #-232]
	add r10, r10, #0
	str r10, [fp, #-232]
	ldr r10, [fp, #-232]
	mov r10, r10
	str r10, [fp, #-820]
	mov r10, #4
	str r10, [fp, #-236]
	mov r9, r9
	ldr r10, [fp, #-236]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-820]
	add r9, r10, r9
	str r9, [fp, #-820]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-244]
	mov r10, #14
	str r10, [fp, #-240]
	ldr r10, [fp, #-240]
	mov r10, r10
	str r10, [fp, #-248]
	ldr r10, [fp, #-244]
	ldr r4, [fp, #-248]
	str r4, [fp, #-880]
	ldr r4, [fp, #-880]
	mul r10, r10, r4
	str r10, [fp, #-252]
	ldr r10, [fp, #-252]
	mov r10, r10
	str r10, [fp, #-256]
	ldr r10, [fp, #-256]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-260]
	ldr r10, [fp, #-260]
	add r10, r10, #0
	str r10, [fp, #-260]
	ldr r10, [fp, #-260]
	mov r10, r10
	str r10, [fp, #-816]
	mov r10, #4
	str r10, [fp, #-264]
	mov r9, r9
	ldr r10, [fp, #-264]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-816]
	add r9, r10, r9
	str r9, [fp, #-816]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-272]
	mov r10, #15
	str r10, [fp, #-268]
	ldr r10, [fp, #-268]
	mov r10, r10
	str r10, [fp, #-276]
	ldr r10, [fp, #-272]
	ldr r4, [fp, #-276]
	str r4, [fp, #-884]
	ldr r4, [fp, #-884]
	mul r10, r10, r4
	str r10, [fp, #-280]
	ldr r10, [fp, #-280]
	mov r10, r10
	str r10, [fp, #-284]
	ldr r10, [fp, #-284]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-288]
	ldr r10, [fp, #-288]
	add r10, r10, #0
	str r10, [fp, #-288]
	ldr r10, [fp, #-288]
	mov r10, r10
	str r10, [fp, #-812]
	mov r10, #4
	str r10, [fp, #-292]
	mov r9, r9
	ldr r10, [fp, #-292]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-812]
	add r9, r10, r9
	str r9, [fp, #-812]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-300]
	mov r10, #16
	str r10, [fp, #-296]
	ldr r10, [fp, #-296]
	mov r10, r10
	str r10, [fp, #-304]
	ldr r10, [fp, #-300]
	ldr r4, [fp, #-304]
	str r4, [fp, #-888]
	ldr r4, [fp, #-888]
	mul r10, r10, r4
	str r10, [fp, #-308]
	ldr r10, [fp, #-308]
	mov r10, r10
	str r10, [fp, #-312]
	ldr r10, [fp, #-312]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-316]
	ldr r10, [fp, #-316]
	add r10, r10, #0
	str r10, [fp, #-316]
	ldr r10, [fp, #-316]
	mov r10, r10
	str r10, [fp, #-808]
	mov r10, #4
	str r10, [fp, #-320]
	mov r9, r9
	ldr r10, [fp, #-320]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-808]
	add r9, r10, r9
	str r9, [fp, #-808]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-328]
	mov r10, #17
	str r10, [fp, #-324]
	ldr r10, [fp, #-324]
	mov r10, r10
	str r10, [fp, #-332]
	ldr r10, [fp, #-328]
	ldr r4, [fp, #-332]
	str r4, [fp, #-892]
	ldr r4, [fp, #-892]
	mul r10, r10, r4
	str r10, [fp, #-336]
	ldr r10, [fp, #-336]
	mov r10, r10
	str r10, [fp, #-340]
	ldr r10, [fp, #-340]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-344]
	ldr r10, [fp, #-344]
	add r10, r10, #0
	str r10, [fp, #-344]
	ldr r10, [fp, #-344]
	mov r10, r10
	str r10, [fp, #-804]
	mov r10, #4
	str r10, [fp, #-348]
	mov r9, r9
	ldr r10, [fp, #-348]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-804]
	add r9, r10, r9
	str r9, [fp, #-804]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-356]
	mov r10, #18
	str r10, [fp, #-352]
	ldr r10, [fp, #-352]
	mov r10, r10
	str r10, [fp, #-360]
	ldr r10, [fp, #-356]
	ldr r4, [fp, #-360]
	str r4, [fp, #-896]
	ldr r4, [fp, #-896]
	mul r10, r10, r4
	str r10, [fp, #-364]
	ldr r10, [fp, #-364]
	mov r10, r10
	str r10, [fp, #-368]
	ldr r10, [fp, #-368]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-372]
	ldr r10, [fp, #-372]
	add r10, r10, #0
	str r10, [fp, #-372]
	ldr r10, [fp, #-372]
	mov r10, r10
	str r10, [fp, #-800]
	mov r10, #4
	str r10, [fp, #-376]
	mov r9, r9
	ldr r10, [fp, #-376]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-800]
	add r9, r10, r9
	str r9, [fp, #-800]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-384]
	mov r10, #19
	str r10, [fp, #-380]
	ldr r10, [fp, #-380]
	mov r10, r10
	str r10, [fp, #-388]
	ldr r10, [fp, #-384]
	ldr r4, [fp, #-388]
	str r4, [fp, #-900]
	ldr r4, [fp, #-900]
	mul r10, r10, r4
	str r10, [fp, #-392]
	ldr r10, [fp, #-392]
	mov r10, r10
	str r10, [fp, #-396]
	ldr r10, [fp, #-396]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-400]
	ldr r10, [fp, #-400]
	add r10, r10, #0
	str r10, [fp, #-400]
	ldr r10, [fp, #-400]
	mov r10, r10
	str r10, [fp, #-796]
	mov r10, #4
	str r10, [fp, #-404]
	mov r9, r9
	ldr r10, [fp, #-404]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-796]
	add r9, r10, r9
	str r9, [fp, #-796]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-412]
	mov r10, #20
	str r10, [fp, #-408]
	ldr r10, [fp, #-408]
	mov r10, r10
	str r10, [fp, #-416]
	ldr r10, [fp, #-412]
	ldr r4, [fp, #-416]
	str r4, [fp, #-904]
	ldr r4, [fp, #-904]
	mul r10, r10, r4
	str r10, [fp, #-420]
	ldr r10, [fp, #-420]
	mov r10, r10
	str r10, [fp, #-424]
	ldr r10, [fp, #-424]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-428]
	ldr r10, [fp, #-428]
	add r10, r10, #0
	str r10, [fp, #-428]
	ldr r10, [fp, #-428]
	mov r10, r10
	str r10, [fp, #-792]
	mov r10, #4
	str r10, [fp, #-432]
	mov r9, r9
	ldr r10, [fp, #-432]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-792]
	add r9, r10, r9
	str r9, [fp, #-792]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-440]
	mov r10, #21
	str r10, [fp, #-436]
	ldr r10, [fp, #-436]
	mov r10, r10
	str r10, [fp, #-444]
	ldr r10, [fp, #-440]
	ldr r4, [fp, #-444]
	str r4, [fp, #-908]
	ldr r4, [fp, #-908]
	mul r10, r10, r4
	str r10, [fp, #-448]
	ldr r10, [fp, #-448]
	mov r10, r10
	str r10, [fp, #-452]
	ldr r10, [fp, #-452]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-456]
	ldr r10, [fp, #-456]
	add r10, r10, #0
	str r10, [fp, #-456]
	ldr r10, [fp, #-456]
	mov r10, r10
	str r10, [fp, #-788]
	mov r10, #4
	str r10, [fp, #-460]
	mov r9, r9
	ldr r10, [fp, #-460]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-788]
	add r9, r10, r9
	str r9, [fp, #-788]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-468]
	mov r10, #22
	str r10, [fp, #-464]
	ldr r10, [fp, #-464]
	mov r10, r10
	str r10, [fp, #-472]
	ldr r10, [fp, #-468]
	ldr r4, [fp, #-472]
	str r4, [fp, #-912]
	ldr r4, [fp, #-912]
	mul r10, r10, r4
	str r10, [fp, #-476]
	ldr r10, [fp, #-476]
	mov r10, r10
	str r10, [fp, #-480]
	ldr r10, [fp, #-480]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-484]
	ldr r10, [fp, #-484]
	add r10, r10, #0
	str r10, [fp, #-484]
	ldr r10, [fp, #-484]
	mov r10, r10
	str r10, [fp, #-784]
	mov r10, #4
	str r10, [fp, #-488]
	mov r9, r9
	ldr r10, [fp, #-488]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-784]
	add r9, r10, r9
	str r9, [fp, #-784]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-496]
	mov r10, #23
	str r10, [fp, #-492]
	ldr r10, [fp, #-492]
	mov r10, r10
	str r10, [fp, #-500]
	ldr r10, [fp, #-496]
	ldr r4, [fp, #-500]
	str r4, [fp, #-916]
	ldr r4, [fp, #-916]
	mul r10, r10, r4
	str r10, [fp, #-504]
	ldr r10, [fp, #-504]
	mov r10, r10
	str r10, [fp, #-508]
	ldr r10, [fp, #-508]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-512]
	ldr r10, [fp, #-512]
	add r10, r10, #0
	str r10, [fp, #-512]
	ldr r10, [fp, #-512]
	mov r10, r10
	str r10, [fp, #-780]
	mov r10, #4
	str r10, [fp, #-516]
	mov r9, r9
	ldr r10, [fp, #-516]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-780]
	add r9, r10, r9
	str r9, [fp, #-780]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-528]
	mov r10, #24
	str r10, [fp, #-520]
	ldr r10, [fp, #-520]
	mov r10, r10
	str r10, [fp, #-524]
	ldr r10, [fp, #-524]
	ldr r4, [fp, #-528]
	str r4, [fp, #-920]
	ldr r4, [fp, #-920]
	mul r10, r4, r10
	str r10, [fp, #-532]
	ldr r10, [fp, #-532]
	mov r10, r10
	str r10, [fp, #-536]
	ldr r10, [fp, #-536]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-540]
	ldr r10, [fp, #-540]
	add r10, r10, #0
	str r10, [fp, #-540]
	ldr r10, [fp, #-540]
	mov r10, r10
	str r10, [fp, #-776]
	mov r10, #4
	str r10, [fp, #-544]
	mov r9, r9
	ldr r10, [fp, #-544]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-776]
	add r9, r10, r9
	str r9, [fp, #-776]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-552]
	mov r10, #25
	str r10, [fp, #-548]
	ldr r10, [fp, #-548]
	mov r10, r10
	str r10, [fp, #-556]
	ldr r10, [fp, #-552]
	ldr r4, [fp, #-556]
	str r4, [fp, #-924]
	ldr r4, [fp, #-924]
	mul r10, r10, r4
	str r10, [fp, #-560]
	ldr r10, [fp, #-560]
	mov r10, r10
	str r10, [fp, #-564]
	ldr r10, [fp, #-564]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-568]
	ldr r10, [fp, #-568]
	add r10, r10, #0
	str r10, [fp, #-568]
	ldr r10, [fp, #-568]
	mov r10, r10
	str r10, [fp, #-772]
	mov r10, #4
	str r10, [fp, #-572]
	mov r9, r9
	ldr r10, [fp, #-572]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-772]
	add r9, r10, r9
	str r9, [fp, #-772]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-580]
	mov r10, #26
	str r10, [fp, #-576]
	ldr r10, [fp, #-576]
	mov r10, r10
	str r10, [fp, #-584]
	ldr r10, [fp, #-580]
	ldr r4, [fp, #-584]
	str r4, [fp, #-928]
	ldr r4, [fp, #-928]
	mul r10, r10, r4
	str r10, [fp, #-588]
	ldr r10, [fp, #-588]
	mov r10, r10
	str r10, [fp, #-592]
	ldr r10, [fp, #-592]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-596]
	ldr r10, [fp, #-596]
	add r10, r10, #0
	str r10, [fp, #-596]
	ldr r10, [fp, #-596]
	mov r10, r10
	str r10, [fp, #-768]
	mov r10, #4
	str r10, [fp, #-600]
	mov r9, r9
	ldr r10, [fp, #-600]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-768]
	add r9, r10, r9
	str r9, [fp, #-768]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-608]
	mov r10, #27
	str r10, [fp, #-604]
	ldr r10, [fp, #-604]
	mov r10, r10
	str r10, [fp, #-612]
	ldr r10, [fp, #-608]
	ldr r4, [fp, #-612]
	str r4, [fp, #-932]
	ldr r4, [fp, #-932]
	mul r10, r10, r4
	str r10, [fp, #-616]
	ldr r10, [fp, #-616]
	mov r10, r10
	str r10, [fp, #-620]
	ldr r10, [fp, #-620]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-624]
	ldr r10, [fp, #-624]
	add r10, r10, #0
	str r10, [fp, #-624]
	ldr r10, [fp, #-624]
	mov r10, r10
	str r10, [fp, #-764]
	mov r10, #4
	str r10, [fp, #-628]
	mov r9, r9
	ldr r10, [fp, #-628]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-764]
	add r9, r10, r9
	str r9, [fp, #-764]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-636]
	mov r10, #28
	str r10, [fp, #-632]
	ldr r10, [fp, #-632]
	mov r10, r10
	str r10, [fp, #-640]
	ldr r10, [fp, #-636]
	ldr r4, [fp, #-640]
	str r4, [fp, #-936]
	ldr r4, [fp, #-936]
	mul r10, r10, r4
	str r10, [fp, #-644]
	ldr r10, [fp, #-644]
	mov r10, r10
	str r10, [fp, #-648]
	ldr r10, [fp, #-648]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-652]
	ldr r10, [fp, #-652]
	add r10, r10, #0
	str r10, [fp, #-652]
	ldr r10, [fp, #-652]
	mov r10, r10
	str r10, [fp, #-760]
	mov r10, #4
	str r10, [fp, #-656]
	mov r9, r9
	ldr r10, [fp, #-656]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-760]
	add r9, r10, r9
	str r9, [fp, #-760]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-664]
	mov r10, #29
	str r10, [fp, #-660]
	ldr r10, [fp, #-660]
	mov r10, r10
	str r10, [fp, #-668]
	ldr r10, [fp, #-664]
	ldr r4, [fp, #-668]
	str r4, [fp, #-940]
	ldr r4, [fp, #-940]
	mul r10, r10, r4
	str r10, [fp, #-672]
	ldr r10, [fp, #-672]
	mov r10, r10
	str r10, [fp, #-676]
	ldr r10, [fp, #-676]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-680]
	ldr r10, [fp, #-680]
	add r10, r10, #0
	str r10, [fp, #-680]
	ldr r10, [fp, #-680]
	mov r10, r10
	str r10, [fp, #-756]
	mov r10, #4
	str r10, [fp, #-684]
	mov r9, r9
	ldr r10, [fp, #-684]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-756]
	add r9, r10, r9
	str r9, [fp, #-756]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-692]
	mov r10, #30
	str r10, [fp, #-688]
	ldr r10, [fp, #-688]
	mov r10, r10
	str r10, [fp, #-696]
	ldr r10, [fp, #-692]
	ldr r4, [fp, #-696]
	str r4, [fp, #-944]
	ldr r4, [fp, #-944]
	mul r10, r10, r4
	str r10, [fp, #-700]
	ldr r10, [fp, #-700]
	mov r10, r10
	str r10, [fp, #-704]
	ldr r10, [fp, #-704]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-708]
	ldr r10, [fp, #-708]
	add r10, r10, #0
	str r10, [fp, #-708]
	ldr r10, [fp, #-708]
	mov r10, r10
	str r10, [fp, #-752]
	mov r10, #4
	str r10, [fp, #-712]
	mov r9, r9
	ldr r10, [fp, #-712]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-752]
	add r9, r10, r9
	str r9, [fp, #-752]
	mov r9, #0
	mov r10, #2
	str r10, [fp, #-720]
	mov r10, #31
	str r10, [fp, #-716]
	ldr r10, [fp, #-716]
	mov r10, r10
	str r10, [fp, #-724]
	ldr r10, [fp, #-720]
	ldr r4, [fp, #-724]
	str r4, [fp, #-948]
	ldr r4, [fp, #-948]
	mul r10, r10, r4
	str r10, [fp, #-728]
	ldr r10, [fp, #-728]
	mov r10, r10
	str r10, [fp, #-732]
	ldr r10, [fp, #-732]
	add r9, r9, r10
	mov r10, sp
	str r10, [fp, #-736]
	ldr r10, [fp, #-736]
	add r10, r10, #0
	str r10, [fp, #-736]
	ldr r10, [fp, #-736]
	mov r10, r10
	str r10, [fp, #-748]
	mov r10, #4
	str r10, [fp, #-740]
	mov r9, r9
	ldr r10, [fp, #-740]
	mul r9, r10, r9
	mov r9, r9
	ldr r10, [fp, #-748]
	add r9, r10, r9
	str r9, [fp, #-748]
	mov r3, r6
	mov r2, r7
	mov r1, r8
	ldr r9, [fp, #-744]
	mov r0, r9
	ldr r9, [fp, #-748]
	push {r9}
	ldr r9, [fp, #-752]
	push {r9}
	ldr r9, [fp, #-756]
	push {r9}
	ldr r9, [fp, #-760]
	push {r9}
	ldr r9, [fp, #-764]
	push {r9}
	ldr r9, [fp, #-768]
	push {r9}
	ldr r9, [fp, #-772]
	push {r9}
	ldr r9, [fp, #-776]
	push {r9}
	ldr r9, [fp, #-780]
	push {r9}
	ldr r9, [fp, #-784]
	push {r9}
	ldr r9, [fp, #-788]
	push {r9}
	ldr r9, [fp, #-792]
	push {r9}
	ldr r9, [fp, #-796]
	push {r9}
	ldr r9, [fp, #-800]
	push {r9}
	ldr r9, [fp, #-804]
	push {r9}
	ldr r9, [fp, #-808]
	push {r9}
	ldr r9, [fp, #-812]
	push {r9}
	ldr r9, [fp, #-816]
	push {r9}
	ldr r9, [fp, #-820]
	push {r9}
	ldr r9, [fp, #-824]
	push {r9}
	ldr r9, [fp, #-828]
	push {r9}
	ldr r9, [fp, #-832]
	push {r9}
	ldr r9, [fp, #-836]
	push {r9}
	ldr r9, [fp, #-840]
	push {r9}
	ldr r9, [fp, #-844]
	push {r9}
	ldr r9, [fp, #-848]
	push {r9}
	push {r5}
	ldr r9, [fp, #-952]
	push {r9}
	bl param32_arr
	mov r9, r0
	add sp, sp, #112
	mov r0, r9
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

.globl param16
.type param16, %function
param16:
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
	mov r8, #704
	sub sp, sp, r8
.LBparam16:
	mov r9, r0
	str r9, [fp, #-488]
	mov r9, r1
	str r9, [fp, #-704]
	mov r9, r2
	mov r8, r3
	add r7, fp, #36
	ldr r7, [r7]
	add r6, fp, #40
	ldr r6, [r6]
	add r5, fp, #44
	ldr r5, [r5]
	add r10, fp, #48
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r10, [r10]
	str r10, [fp, #-484]
	add r10, fp, #52
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r10, [r10]
	str r10, [fp, #-480]
	add r10, fp, #56
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	ldr r10, [r10]
	str r10, [fp, #-476]
	add r10, fp, #60
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	ldr r10, [r10]
	str r10, [fp, #-472]
	add r10, fp, #64
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	ldr r10, [r10]
	str r10, [fp, #-468]
	add r10, fp, #68
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	ldr r10, [r10]
	str r10, [fp, #-464]
	add r10, fp, #72
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	ldr r10, [r10]
	str r10, [fp, #-460]
	add r10, fp, #76
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	ldr r10, [r10]
	str r10, [fp, #-456]
	add r10, fp, #80
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	ldr r10, [r10]
	str r10, [fp, #-452]
	sub sp, sp, #64
	str r10, [fp, #-36]
	mov r10, sp
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	add r10, r10, #0
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	mov r0, r10
	mov r1, #0
	mov r2, #64
	bl memset
	mov r10, sp
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	add r10, r10, #0
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	ldr r4, [fp, #-488]
	str r4, [fp, #-540]
	ldr r4, [fp, #-540]
	str r4, [r10, #0]
	mov r10, sp
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	add r10, r10, #0
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	ldr r4, [fp, #-704]
	str r4, [r10, #4]
	mov r10, sp
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	add r10, r10, #0
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	str r9, [r10, #8]
	mov r10, sp
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	add r10, r10, #0
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	str r8, [r10, #12]
	mov r10, sp
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	add r10, r10, #0
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	str r7, [r10, #16]
	mov r10, sp
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	add r10, r10, #0
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	str r6, [r10, #20]
	mov r10, sp
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	add r10, r10, #0
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	str r5, [r10, #24]
	mov r10, sp
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	add r10, r10, #0
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	ldr r4, [fp, #-484]
	str r4, [fp, #-540]
	ldr r4, [fp, #-540]
	str r4, [r10, #28]
	mov r10, sp
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	add r10, r10, #0
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	ldr r4, [fp, #-480]
	str r4, [fp, #-544]
	ldr r4, [fp, #-544]
	str r4, [r10, #32]
	mov r10, sp
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	add r10, r10, #0
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	ldr r4, [fp, #-476]
	str r4, [fp, #-548]
	ldr r4, [fp, #-548]
	str r4, [r10, #36]
	mov r10, sp
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	add r10, r10, #0
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	ldr r4, [fp, #-472]
	str r4, [fp, #-552]
	ldr r4, [fp, #-552]
	str r4, [r10, #40]
	mov r10, sp
	str r10, [fp, #-88]
	ldr r10, [fp, #-88]
	add r10, r10, #0
	str r10, [fp, #-88]
	ldr r10, [fp, #-88]
	ldr r4, [fp, #-468]
	str r4, [fp, #-556]
	ldr r4, [fp, #-556]
	str r4, [r10, #44]
	mov r10, sp
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	add r10, r10, #0
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	ldr r4, [fp, #-464]
	str r4, [fp, #-560]
	ldr r4, [fp, #-560]
	str r4, [r10, #48]
	mov r10, sp
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	add r10, r10, #0
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	ldr r4, [fp, #-460]
	str r4, [fp, #-564]
	ldr r4, [fp, #-564]
	str r4, [r10, #52]
	mov r10, sp
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	add r10, r10, #0
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	ldr r4, [fp, #-456]
	str r4, [fp, #-568]
	ldr r4, [fp, #-568]
	str r4, [r10, #56]
	mov r10, sp
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	add r10, r10, #0
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	ldr r4, [fp, #-452]
	str r4, [fp, #-572]
	ldr r4, [fp, #-572]
	str r4, [r10, #60]
	mov r1, #16
	add r10, sp, #0
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	mov r0, r10
	bl sort
	mov r10, r0
	str r10, [fp, #-112]
	add sp, sp, #0
	mov r10, #0
	str r10, [fp, #-120]
	mov r10, #4
	str r10, [fp, #-116]
	ldr r10, [fp, #-116]
	mov r10, r10
	str r10, [fp, #-124]
	ldr r10, [fp, #-120]
	ldr r4, [fp, #-124]
	str r4, [fp, #-576]
	ldr r4, [fp, #-576]
	mul r10, r10, r4
	str r10, [fp, #-128]
	mov r10, sp
	str r10, [fp, #-132]
	ldr r10, [fp, #-132]
	add r10, r10, #0
	str r10, [fp, #-132]
	ldr r10, [fp, #-128]
	ldr r4, [fp, #-132]
	str r4, [fp, #-580]
	ldr r4, [fp, #-580]
	ldr r10, [r4, r10]
	str r10, [fp, #-448]
	mov r10, #1
	str r10, [fp, #-140]
	mov r10, #4
	str r10, [fp, #-136]
	ldr r10, [fp, #-136]
	mov r10, r10
	str r10, [fp, #-144]
	ldr r10, [fp, #-140]
	ldr r4, [fp, #-144]
	str r4, [fp, #-584]
	ldr r4, [fp, #-584]
	mul r10, r10, r4
	str r10, [fp, #-148]
	mov r10, sp
	str r10, [fp, #-152]
	ldr r10, [fp, #-152]
	add r10, r10, #0
	str r10, [fp, #-152]
	ldr r10, [fp, #-148]
	ldr r4, [fp, #-152]
	str r4, [fp, #-588]
	ldr r4, [fp, #-588]
	ldr r10, [r4, r10]
	str r10, [fp, #-444]
	mov r10, #2
	str r10, [fp, #-160]
	mov r10, #4
	str r10, [fp, #-156]
	ldr r10, [fp, #-156]
	mov r10, r10
	str r10, [fp, #-164]
	ldr r10, [fp, #-160]
	ldr r4, [fp, #-164]
	str r4, [fp, #-592]
	ldr r4, [fp, #-592]
	mul r10, r10, r4
	str r10, [fp, #-172]
	mov r10, sp
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	add r10, r10, #0
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	ldr r4, [fp, #-172]
	str r4, [fp, #-596]
	ldr r4, [fp, #-596]
	ldr r10, [r10, r4]
	str r10, [fp, #-440]
	mov r10, #3
	str r10, [fp, #-180]
	mov r10, #4
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	mov r10, r10
	str r10, [fp, #-184]
	ldr r10, [fp, #-180]
	ldr r4, [fp, #-184]
	str r4, [fp, #-600]
	ldr r4, [fp, #-600]
	mul r10, r10, r4
	str r10, [fp, #-188]
	mov r10, sp
	str r10, [fp, #-192]
	ldr r10, [fp, #-192]
	add r10, r10, #0
	str r10, [fp, #-192]
	ldr r10, [fp, #-188]
	ldr r4, [fp, #-192]
	str r4, [fp, #-604]
	ldr r4, [fp, #-604]
	ldr r10, [r4, r10]
	str r10, [fp, #-436]
	mov r10, #4
	str r10, [fp, #-200]
	mov r10, #4
	str r10, [fp, #-196]
	ldr r10, [fp, #-196]
	mov r10, r10
	str r10, [fp, #-204]
	ldr r10, [fp, #-200]
	ldr r4, [fp, #-204]
	str r4, [fp, #-608]
	ldr r4, [fp, #-608]
	mul r10, r10, r4
	str r10, [fp, #-212]
	mov r10, sp
	str r10, [fp, #-208]
	ldr r10, [fp, #-208]
	add r10, r10, #0
	str r10, [fp, #-208]
	ldr r10, [fp, #-208]
	ldr r4, [fp, #-212]
	str r4, [fp, #-612]
	ldr r4, [fp, #-612]
	ldr r10, [r10, r4]
	str r10, [fp, #-536]
	mov r10, #5
	str r10, [fp, #-220]
	mov r10, #4
	str r10, [fp, #-216]
	ldr r10, [fp, #-216]
	mov r10, r10
	str r10, [fp, #-224]
	ldr r10, [fp, #-220]
	ldr r4, [fp, #-224]
	str r4, [fp, #-616]
	ldr r4, [fp, #-616]
	mul r10, r10, r4
	str r10, [fp, #-228]
	mov r10, sp
	str r10, [fp, #-232]
	ldr r10, [fp, #-232]
	add r10, r10, #0
	str r10, [fp, #-232]
	ldr r10, [fp, #-228]
	ldr r4, [fp, #-232]
	str r4, [fp, #-620]
	ldr r4, [fp, #-620]
	ldr r10, [r4, r10]
	str r10, [fp, #-532]
	mov r10, #6
	str r10, [fp, #-240]
	mov r10, #4
	str r10, [fp, #-236]
	ldr r10, [fp, #-236]
	mov r10, r10
	str r10, [fp, #-244]
	ldr r10, [fp, #-240]
	ldr r4, [fp, #-244]
	str r4, [fp, #-624]
	ldr r4, [fp, #-624]
	mul r10, r10, r4
	str r10, [fp, #-248]
	mov r10, sp
	str r10, [fp, #-252]
	ldr r10, [fp, #-252]
	add r10, r10, #0
	str r10, [fp, #-252]
	ldr r10, [fp, #-248]
	ldr r4, [fp, #-252]
	str r4, [fp, #-628]
	ldr r4, [fp, #-628]
	ldr r10, [r4, r10]
	str r10, [fp, #-528]
	mov r10, #7
	str r10, [fp, #-260]
	mov r10, #4
	str r10, [fp, #-256]
	ldr r10, [fp, #-256]
	mov r10, r10
	str r10, [fp, #-264]
	ldr r10, [fp, #-260]
	ldr r4, [fp, #-264]
	str r4, [fp, #-632]
	ldr r4, [fp, #-632]
	mul r10, r10, r4
	str r10, [fp, #-268]
	mov r10, sp
	str r10, [fp, #-272]
	ldr r10, [fp, #-272]
	add r10, r10, #0
	str r10, [fp, #-272]
	ldr r10, [fp, #-268]
	ldr r4, [fp, #-272]
	str r4, [fp, #-636]
	ldr r4, [fp, #-636]
	ldr r10, [r4, r10]
	str r10, [fp, #-524]
	mov r10, #8
	str r10, [fp, #-280]
	mov r10, #4
	str r10, [fp, #-276]
	ldr r10, [fp, #-276]
	mov r10, r10
	str r10, [fp, #-284]
	ldr r10, [fp, #-280]
	ldr r4, [fp, #-284]
	str r4, [fp, #-640]
	ldr r4, [fp, #-640]
	mul r10, r10, r4
	str r10, [fp, #-288]
	mov r10, sp
	str r10, [fp, #-292]
	ldr r10, [fp, #-292]
	add r10, r10, #0
	str r10, [fp, #-292]
	ldr r10, [fp, #-288]
	ldr r4, [fp, #-292]
	str r4, [fp, #-644]
	ldr r4, [fp, #-644]
	ldr r10, [r4, r10]
	str r10, [fp, #-520]
	mov r10, #9
	str r10, [fp, #-300]
	mov r10, #4
	str r10, [fp, #-296]
	ldr r10, [fp, #-296]
	mov r10, r10
	str r10, [fp, #-304]
	ldr r10, [fp, #-300]
	ldr r4, [fp, #-304]
	str r4, [fp, #-648]
	ldr r4, [fp, #-648]
	mul r10, r10, r4
	str r10, [fp, #-308]
	mov r10, sp
	str r10, [fp, #-312]
	ldr r10, [fp, #-312]
	add r10, r10, #0
	str r10, [fp, #-312]
	ldr r10, [fp, #-308]
	ldr r4, [fp, #-312]
	str r4, [fp, #-652]
	ldr r4, [fp, #-652]
	ldr r10, [r4, r10]
	str r10, [fp, #-516]
	mov r10, #10
	str r10, [fp, #-320]
	mov r10, #4
	str r10, [fp, #-316]
	ldr r10, [fp, #-316]
	mov r10, r10
	str r10, [fp, #-324]
	ldr r10, [fp, #-320]
	ldr r4, [fp, #-324]
	str r4, [fp, #-656]
	ldr r4, [fp, #-656]
	mul r10, r10, r4
	str r10, [fp, #-328]
	mov r10, sp
	str r10, [fp, #-332]
	ldr r10, [fp, #-332]
	add r10, r10, #0
	str r10, [fp, #-332]
	ldr r10, [fp, #-328]
	ldr r4, [fp, #-332]
	str r4, [fp, #-660]
	ldr r4, [fp, #-660]
	ldr r10, [r4, r10]
	str r10, [fp, #-512]
	mov r10, #11
	str r10, [fp, #-340]
	mov r10, #4
	str r10, [fp, #-336]
	ldr r10, [fp, #-336]
	mov r10, r10
	str r10, [fp, #-344]
	ldr r10, [fp, #-340]
	ldr r4, [fp, #-344]
	str r4, [fp, #-664]
	ldr r4, [fp, #-664]
	mul r10, r10, r4
	str r10, [fp, #-352]
	mov r10, sp
	str r10, [fp, #-348]
	ldr r10, [fp, #-348]
	add r10, r10, #0
	str r10, [fp, #-348]
	ldr r10, [fp, #-348]
	ldr r4, [fp, #-352]
	str r4, [fp, #-668]
	ldr r4, [fp, #-668]
	ldr r10, [r10, r4]
	str r10, [fp, #-508]
	mov r10, #12
	str r10, [fp, #-360]
	mov r10, #4
	str r10, [fp, #-356]
	ldr r10, [fp, #-356]
	mov r10, r10
	str r10, [fp, #-364]
	ldr r10, [fp, #-360]
	ldr r4, [fp, #-364]
	str r4, [fp, #-672]
	ldr r4, [fp, #-672]
	mul r10, r10, r4
	str r10, [fp, #-368]
	mov r10, sp
	str r10, [fp, #-372]
	ldr r10, [fp, #-372]
	add r10, r10, #0
	str r10, [fp, #-372]
	ldr r10, [fp, #-368]
	ldr r4, [fp, #-372]
	str r4, [fp, #-676]
	ldr r4, [fp, #-676]
	ldr r10, [r4, r10]
	str r10, [fp, #-504]
	mov r10, #13
	str r10, [fp, #-384]
	mov r10, #4
	str r10, [fp, #-376]
	ldr r10, [fp, #-376]
	mov r10, r10
	str r10, [fp, #-380]
	ldr r10, [fp, #-380]
	ldr r4, [fp, #-384]
	str r4, [fp, #-680]
	ldr r4, [fp, #-680]
	mul r10, r4, r10
	str r10, [fp, #-392]
	mov r10, sp
	str r10, [fp, #-388]
	ldr r10, [fp, #-388]
	add r10, r10, #0
	str r10, [fp, #-388]
	ldr r10, [fp, #-388]
	ldr r4, [fp, #-392]
	str r4, [fp, #-684]
	ldr r4, [fp, #-684]
	ldr r10, [r10, r4]
	str r10, [fp, #-500]
	mov r10, #14
	str r10, [fp, #-404]
	mov r10, #4
	str r10, [fp, #-396]
	ldr r10, [fp, #-396]
	mov r10, r10
	str r10, [fp, #-400]
	ldr r10, [fp, #-400]
	ldr r4, [fp, #-404]
	str r4, [fp, #-688]
	ldr r4, [fp, #-688]
	mul r10, r4, r10
	str r10, [fp, #-412]
	mov r10, sp
	str r10, [fp, #-408]
	ldr r10, [fp, #-408]
	add r10, r10, #0
	str r10, [fp, #-408]
	ldr r10, [fp, #-408]
	ldr r4, [fp, #-412]
	str r4, [fp, #-692]
	ldr r4, [fp, #-692]
	ldr r10, [r10, r4]
	str r10, [fp, #-496]
	mov r10, #15
	str r10, [fp, #-424]
	mov r10, #4
	str r10, [fp, #-416]
	ldr r10, [fp, #-416]
	mov r10, r10
	str r10, [fp, #-420]
	ldr r10, [fp, #-420]
	ldr r4, [fp, #-424]
	str r4, [fp, #-696]
	ldr r4, [fp, #-696]
	mul r10, r4, r10
	str r10, [fp, #-432]
	mov r10, sp
	str r10, [fp, #-428]
	ldr r10, [fp, #-428]
	add r10, r10, #0
	str r10, [fp, #-428]
	ldr r10, [fp, #-428]
	ldr r4, [fp, #-432]
	str r4, [fp, #-700]
	ldr r4, [fp, #-700]
	ldr r10, [r10, r4]
	str r10, [fp, #-492]
	ldr r10, [fp, #-436]
	mov r3, r10
	ldr r10, [fp, #-440]
	mov r2, r10
	ldr r10, [fp, #-444]
	mov r1, r10
	ldr r10, [fp, #-448]
	mov r0, r10
	ldr r10, [fp, #-452]
	push {r10}
	ldr r10, [fp, #-456]
	push {r10}
	ldr r10, [fp, #-460]
	push {r10}
	ldr r10, [fp, #-464]
	push {r10}
	ldr r10, [fp, #-468]
	push {r10}
	ldr r10, [fp, #-472]
	push {r10}
	ldr r10, [fp, #-476]
	push {r10}
	ldr r10, [fp, #-480]
	push {r10}
	ldr r10, [fp, #-484]
	push {r10}
	push {r5}
	push {r6}
	push {r7}
	push {r8}
	push {r9}
	ldr r9, [fp, #-704]
	push {r9}
	ldr r9, [fp, #-488]
	push {r9}
	ldr r9, [fp, #-492]
	push {r9}
	ldr r9, [fp, #-496]
	push {r9}
	ldr r9, [fp, #-500]
	push {r9}
	ldr r9, [fp, #-504]
	push {r9}
	ldr r9, [fp, #-508]
	push {r9}
	ldr r9, [fp, #-512]
	push {r9}
	ldr r9, [fp, #-516]
	push {r9}
	ldr r9, [fp, #-520]
	push {r9}
	ldr r9, [fp, #-524]
	push {r9}
	ldr r9, [fp, #-528]
	push {r9}
	ldr r9, [fp, #-532]
	push {r9}
	ldr r9, [fp, #-536]
	push {r9}
	bl param32_rec
	mov r9, r0
	add sp, sp, #112
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

.globl param32_arr
.type param32_arr, %function
param32_arr:
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
	mov r8, #308
	sub sp, sp, r8
.LBparam32_arr:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, r3
	add r5, fp, #36
	ldr r5, [r5]
	add r10, fp, #40
	ldr r10, [r10]
	str r10, [fp, #-308]
	add r10, fp, #44
	ldr r10, [r10]
	str r10, [fp, #-192]
	add r10, fp, #48
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r10, [r10]
	str r10, [fp, #-196]
	add r10, fp, #52
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r10, [r10]
	str r10, [fp, #-200]
	add r10, fp, #56
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	ldr r10, [r10]
	str r10, [fp, #-204]
	add r10, fp, #60
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	ldr r10, [r10]
	str r10, [fp, #-208]
	add r10, fp, #64
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	ldr r10, [r10]
	str r10, [fp, #-212]
	add r10, fp, #68
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	ldr r10, [r10]
	str r10, [fp, #-216]
	add r10, fp, #72
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	ldr r10, [r10]
	str r10, [fp, #-220]
	add r10, fp, #76
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	ldr r10, [r10]
	str r10, [fp, #-224]
	add r10, fp, #80
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	ldr r10, [r10]
	str r10, [fp, #-228]
	add r10, fp, #84
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	ldr r10, [r10]
	str r10, [fp, #-232]
	add r10, fp, #88
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	ldr r10, [r10]
	str r10, [fp, #-236]
	add r10, fp, #92
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	ldr r10, [r10]
	str r10, [fp, #-240]
	add r10, fp, #96
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	ldr r10, [r10]
	str r10, [fp, #-244]
	add r10, fp, #100
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	ldr r10, [r10]
	str r10, [fp, #-248]
	add r10, fp, #104
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	ldr r10, [r10]
	str r10, [fp, #-252]
	add r10, fp, #108
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	ldr r10, [r10]
	str r10, [fp, #-256]
	add r10, fp, #112
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	ldr r10, [r10]
	str r10, [fp, #-260]
	add r10, fp, #116
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	ldr r10, [r10]
	str r10, [fp, #-264]
	add r10, fp, #120
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	ldr r10, [r10]
	str r10, [fp, #-268]
	add r10, fp, #124
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	ldr r10, [r10]
	str r10, [fp, #-272]
	add r10, fp, #128
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	ldr r10, [r10]
	str r10, [fp, #-276]
	add r10, fp, #132
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	ldr r10, [r10]
	str r10, [fp, #-280]
	add r10, fp, #136
	str r10, [fp, #-88]
	ldr r10, [fp, #-88]
	ldr r10, [r10]
	str r10, [fp, #-284]
	add r10, fp, #140
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	ldr r10, [r10]
	str r10, [fp, #-288]
	add r10, fp, #144
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	ldr r10, [r10]
	str r10, [fp, #-292]
	str r10, [fp, #-152]
	mov r10, #0
	str r10, [fp, #-104]
	mov r10, #4
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	mov r10, r10
	str r10, [fp, #-108]
	ldr r10, [fp, #-104]
	ldr r4, [fp, #-108]
	str r4, [fp, #-296]
	ldr r4, [fp, #-296]
	mul r10, r10, r4
	str r10, [fp, #-112]
	mov r10, r9
	str r10, [fp, #-116]
	ldr r10, [fp, #-112]
	ldr r4, [fp, #-116]
	str r4, [fp, #-296]
	ldr r4, [fp, #-296]
	ldr r10, [r4, r10]
	str r10, [fp, #-136]
	mov r10, #1
	str r10, [fp, #-124]
	mov r10, #4
	str r10, [fp, #-120]
	ldr r10, [fp, #-120]
	mov r10, r10
	str r10, [fp, #-128]
	ldr r10, [fp, #-124]
	ldr r4, [fp, #-128]
	str r4, [fp, #-300]
	ldr r4, [fp, #-300]
	mul r10, r10, r4
	str r10, [fp, #-132]
	mov r9, r9
	ldr r10, [fp, #-132]
	ldr r9, [r9, r10]
	mov r9, r9
	ldr r10, [fp, #-136]
	add r9, r10, r9
	mov r9, r9
	str r9, [fp, #-152]
	mov r9, #0
	mov r10, #4
	str r10, [fp, #-140]
	ldr r10, [fp, #-140]
	mov r10, r10
	str r10, [fp, #-144]
	ldr r10, [fp, #-144]
	mul r9, r9, r10
	mov r10, r8
	str r10, [fp, #-148]
	ldr r10, [fp, #-148]
	ldr r9, [r10, r9]
	mov r9, r9
	ldr r10, [fp, #-152]
	add r9, r10, r9
	mov r10, #1
	str r10, [fp, #-160]
	mov r10, #4
	str r10, [fp, #-156]
	ldr r10, [fp, #-156]
	mov r10, r10
	str r10, [fp, #-164]
	ldr r10, [fp, #-160]
	ldr r4, [fp, #-164]
	str r4, [fp, #-304]
	ldr r4, [fp, #-304]
	mul r10, r10, r4
	str r10, [fp, #-168]
	mov r8, r8
	ldr r10, [fp, #-168]
	ldr r8, [r8, r10]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r10, #4
	str r10, [fp, #-172]
	ldr r10, [fp, #-172]
	mov r10, r10
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	mul r8, r8, r10
	mov r10, r7
	str r10, [fp, #-180]
	ldr r10, [fp, #-180]
	ldr r8, [r10, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r10, #4
	str r10, [fp, #-184]
	ldr r10, [fp, #-184]
	mov r10, r10
	str r10, [fp, #-188]
	ldr r10, [fp, #-188]
	mul r8, r8, r10
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, r6
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, r6
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, r5
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, r5
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-308]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-308]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-192]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-192]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-196]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-196]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-200]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-200]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-204]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-204]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-208]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-208]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-212]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-212]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-216]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-216]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-220]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-220]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-224]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-224]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-228]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-228]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-232]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-232]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-236]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-236]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-240]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-240]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-244]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-244]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-248]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-248]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-252]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-252]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-256]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-256]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-260]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-260]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-264]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-264]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-268]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-268]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-272]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-272]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-276]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-276]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-280]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-280]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-284]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-284]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-288]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-288]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
	mov r8, #0
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-292]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	ldr r7, [fp, #-292]
	mov r7, r7
	ldr r8, [r7, r8]
	mov r8, r8
	add r9, r9, r8
	mov r9, r9
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

.globl param32_rec
.type param32_rec, %function
param32_rec:
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
	mov r8, #224
	sub sp, sp, r8
.LBparam32_rec:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	mov r6, r3
	add r5, fp, #36
	ldr r5, [r5]
	add r10, fp, #40
	ldr r10, [r10]
	str r10, [fp, #-216]
	add r10, fp, #44
	ldr r10, [r10]
	str r10, [fp, #-224]
	add r10, fp, #48
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r10, [r10]
	str r10, [fp, #-212]
	add r10, fp, #52
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	ldr r10, [r10]
	str r10, [fp, #-208]
	add r10, fp, #56
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	ldr r10, [r10]
	str r10, [fp, #-204]
	add r10, fp, #60
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	ldr r10, [r10]
	str r10, [fp, #-200]
	add r10, fp, #64
	str r10, [fp, #-16]
	ldr r10, [fp, #-16]
	ldr r10, [r10]
	str r10, [fp, #-196]
	add r10, fp, #68
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	ldr r10, [r10]
	str r10, [fp, #-192]
	add r10, fp, #72
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	ldr r10, [r10]
	str r10, [fp, #-188]
	add r10, fp, #76
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	ldr r10, [r10]
	str r10, [fp, #-184]
	add r10, fp, #80
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	ldr r10, [r10]
	str r10, [fp, #-180]
	add r10, fp, #84
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	ldr r10, [r10]
	str r10, [fp, #-176]
	add r10, fp, #88
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	ldr r10, [r10]
	str r10, [fp, #-172]
	add r10, fp, #92
	str r10, [fp, #-44]
	ldr r10, [fp, #-44]
	ldr r10, [r10]
	str r10, [fp, #-168]
	add r10, fp, #96
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	ldr r10, [r10]
	str r10, [fp, #-164]
	add r10, fp, #100
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	ldr r10, [r10]
	str r10, [fp, #-160]
	add r10, fp, #104
	str r10, [fp, #-56]
	ldr r10, [fp, #-56]
	ldr r10, [r10]
	str r10, [fp, #-156]
	add r10, fp, #108
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	ldr r10, [r10]
	str r10, [fp, #-152]
	add r10, fp, #112
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	ldr r10, [r10]
	str r10, [fp, #-148]
	add r10, fp, #116
	str r10, [fp, #-68]
	ldr r10, [fp, #-68]
	ldr r10, [r10]
	str r10, [fp, #-144]
	add r10, fp, #120
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	ldr r10, [r10]
	str r10, [fp, #-140]
	add r10, fp, #124
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	ldr r10, [r10]
	str r10, [fp, #-136]
	add r10, fp, #128
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	ldr r10, [r10]
	str r10, [fp, #-132]
	add r10, fp, #132
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	ldr r10, [r10]
	str r10, [fp, #-128]
	add r10, fp, #136
	str r10, [fp, #-88]
	ldr r10, [fp, #-88]
	ldr r10, [r10]
	str r10, [fp, #-124]
	add r10, fp, #140
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	ldr r10, [r10]
	str r10, [fp, #-120]
	add r10, fp, #144
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	ldr r10, [r10]
	str r10, [fp, #-116]
	mov r10, #0
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	cmp r9, r10
	mov r10, #0
	moveq r10, #1
	str r10, [fp, #-104]
	mov r10, #0
	str r10, [fp, #-108]
	ldr r10, [fp, #-104]
	ldr r4, [fp, #-108]
	str r4, [fp, #-220]
	ldr r4, [fp, #-220]
	cmp r10, r4
	beq .LBB_param32_rec3_ELSE
	b .LBB_param32_rec3_IF
.LBB_param32_rec3_IF:
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
.LBB_param32_rec3_ELSE:
	sub r9, r9, #1
	mov r7, r7
	add r8, r8, r7
	mov r7, r0
	mov r10, r1
	str r10, [fp, #-112]
	mov r0, r8
	ldr r1, =#998244353
	bl __aeabi_idivmod
	mov r8, r1
	mov r0, r7
	ldr r7, [fp, #-112]
	mov r1, r7
	mov r7, #0
	mov r3, r5
	mov r2, r6
	mov r1, r8
	mov r0, r9
	push {r7}
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
	ldr r9, [fp, #-144]
	push {r9}
	ldr r9, [fp, #-148]
	push {r9}
	ldr r9, [fp, #-152]
	push {r9}
	ldr r9, [fp, #-156]
	push {r9}
	ldr r9, [fp, #-160]
	push {r9}
	ldr r9, [fp, #-164]
	push {r9}
	ldr r9, [fp, #-168]
	push {r9}
	ldr r9, [fp, #-172]
	push {r9}
	ldr r9, [fp, #-176]
	push {r9}
	ldr r9, [fp, #-180]
	push {r9}
	ldr r9, [fp, #-184]
	push {r9}
	ldr r9, [fp, #-188]
	push {r9}
	ldr r9, [fp, #-192]
	push {r9}
	ldr r9, [fp, #-196]
	push {r9}
	ldr r9, [fp, #-200]
	push {r9}
	ldr r9, [fp, #-204]
	push {r9}
	ldr r9, [fp, #-208]
	push {r9}
	ldr r9, [fp, #-212]
	push {r9}
	ldr r9, [fp, #-224]
	push {r9}
	ldr r9, [fp, #-216]
	push {r9}
	bl param32_rec
	mov r9, r0
	add sp, sp, #112
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

.globl sort
.type sort, %function
sort:
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
.LBsort:
	mov r9, r0
	str r9, [fp, #-8]
	mov r9, r1
	mov r8, #0
.LB_sort0_LOOP_BEGIN:
	sub r7, r9, #1
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	add r6, r8, #1
	mov r7, r6
.LB_1_LOOP_BEGIN:
	cmp r7, r9
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	ldr r5, [fp, #-8]
	mov r5, r5
	ldr r6, [r5, r6]
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	ldr r10, [fp, #-8]
	mov r10, r10
	ldr r5, [r10, r5]
	cmp r6, r5
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
	mov r5, #4
	mov r5, r5
	mul r5, r8, r5
	ldr r10, [fp, #-8]
	mov r10, r10
	ldr r5, [r10, r5]
	mov r6, r5
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	ldr r10, [fp, #-8]
	mov r10, r10
	ldr r5, [r10, r5]
	mov r10, #4
	mov r10, r10
	mul r10, r8, r10
	ldr r4, [fp, #-8]
	mov r4, r4
	str r4, [fp, #-4]
	ldr r4, [fp, #-4]
	str r5, [r4, r10]
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	ldr r10, [fp, #-8]
	mov r10, r10
	str r6, [r10, r5]
.LBB_2_ELSE:
	add r6, r7, #1
	mov r7, r6
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	add r7, r8, #1
	mov r8, r7
	b .LB_sort0_LOOP_BEGIN
.LB0_LOOP_END:
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