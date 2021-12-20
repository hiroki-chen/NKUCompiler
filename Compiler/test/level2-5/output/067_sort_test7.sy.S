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
.globl buf
buf:
.space 800

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
	mov r8, #0
	mov r7, #100
	mov r6, #0
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov32 r7, buf
	mov r6, #4
	mul r8, r6, r8
	add r7, r7, r8
	mov r0, r7
	bl getarray
	mov r8, r0
	mov r9, r8
	mov r1, r9
	mov r0, #0
	bl merge_sort
	mov r8, r0
	mov r8, #0
	mov r7, #100
	mov r6, #0
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov32 r7, buf
	mov r6, #4
	mul r8, r6, r8
	add r7, r7, r8
	mov r1, r7
	mov r0, r9
	bl putarray
	mov r9, r0
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

.globl merge_sort
.type merge_sort, %function
merge_sort:
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
	mov r8, #512
	sub sp, sp, r8
.LBmerge_sort:
	mov r9, r0
	str r9, [fp, #-412]
	mov r9, r1
	str r9, [fp, #-512]
	ldr r9, [fp, #-412]
	add r9, r9, #1
	ldr r8, [fp, #-512]
	cmp r9, r8
	mov r9, #0
	movge r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_merge_sort0_ELSE
	b .LBB_merge_sort0_IF
.LBB_merge_sort0_IF:
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
.LBB_merge_sort0_ELSE:
	ldr r8, [fp, #-512]
	ldr r7, [fp, #-412]
	add r8, r7, r8
	mov r7, r0
	mov r6, r1
	mov r0, r8
	mov r1, #2
	bl __aeabi_idiv
	mov r8, r0
	mov r0, r7
	mov r1, r6
	mov r9, r8
	mov r1, r9
	ldr r8, [fp, #-412]
	mov r0, r8
	bl merge_sort
	mov r8, r0
	ldr r8, [fp, #-512]
	mov r1, r8
	mov r0, r9
	bl merge_sort
	mov r8, r0
	ldr r7, [fp, #-412]
	mov r8, r7
	mov r7, r9
	ldr r5, [fp, #-412]
	mov r6, r5
.LB_merge_sort1_LOOP_BEGIN:
	cmp r8, r9
	mov r5, #0
	bge .LB_18_COND_END
	ldr r10, [fp, #-512]
	cmp r7, r10
	mov r10, #0
	movlt r10, #1
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mov r5, r10
.LB_18_COND_END:
	mov r10, #0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r5, #4
	mul r5, r8, r5
	mov r10, #400
	str r10, [fp, #-12]
	mov r10, #0
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	str r10, [fp, #-16]
	ldr r10, [fp, #-12]
	ldr r4, [fp, #-16]
	str r4, [fp, #-416]
	ldr r4, [fp, #-416]
	mul r10, r10, r4
	str r10, [fp, #-20]
	ldr r10, [fp, #-20]
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-28]
	ldr r10, [fp, #-28]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-32]
	ldr r10, [fp, #-32]
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	mul r10, r7, r10
	str r10, [fp, #-56]
	mov r10, #400
	str r10, [fp, #-44]
	mov r10, #0
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	str r10, [fp, #-48]
	ldr r10, [fp, #-44]
	ldr r4, [fp, #-48]
	str r4, [fp, #-416]
	ldr r4, [fp, #-416]
	mul r10, r10, r4
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	str r10, [fp, #-60]
	ldr r10, [fp, #-56]
	ldr r4, [fp, #-60]
	str r4, [fp, #-420]
	ldr r4, [fp, #-420]
	add r10, r10, r4
	str r10, [fp, #-64]
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-68]
	ldr r10, [fp, #-64]
	ldr r4, [fp, #-68]
	str r4, [fp, #-424]
	ldr r4, [fp, #-424]
	ldr r10, [r4, r10]
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	cmp r5, r10
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-76]
	ldr r10, [fp, #-76]
	cmp r5, r10
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
	mov r5, #4
	mul r5, r8, r5
	mov r10, #400
	str r10, [fp, #-84]
	mov r10, #0
	str r10, [fp, #-80]
	ldr r10, [fp, #-80]
	str r10, [fp, #-88]
	ldr r10, [fp, #-84]
	ldr r4, [fp, #-88]
	str r4, [fp, #-428]
	ldr r4, [fp, #-428]
	mul r10, r10, r4
	str r10, [fp, #-92]
	ldr r10, [fp, #-92]
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-100]
	ldr r10, [fp, #-100]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-104]
	ldr r10, [fp, #-104]
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	mul r10, r6, r10
	str r10, [fp, #-128]
	mov r10, #400
	str r10, [fp, #-116]
	mov r10, #1
	str r10, [fp, #-112]
	ldr r10, [fp, #-112]
	str r10, [fp, #-120]
	ldr r10, [fp, #-116]
	ldr r4, [fp, #-120]
	str r4, [fp, #-432]
	ldr r4, [fp, #-432]
	mul r10, r10, r4
	str r10, [fp, #-124]
	ldr r10, [fp, #-124]
	str r10, [fp, #-132]
	ldr r10, [fp, #-128]
	ldr r4, [fp, #-132]
	str r4, [fp, #-436]
	ldr r4, [fp, #-436]
	add r10, r10, r4
	str r10, [fp, #-136]
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-140]
	ldr r10, [fp, #-136]
	ldr r4, [fp, #-140]
	str r4, [fp, #-440]
	ldr r4, [fp, #-440]
	str r5, [r4, r10]
	add r5, r8, #1
	mov r8, r5
	b .LBB_2_END_IF
.LBB_2_ELSE:
	mov r5, #4
	mul r5, r7, r5
	mov r10, #400
	str r10, [fp, #-152]
	mov r10, #0
	str r10, [fp, #-144]
	ldr r10, [fp, #-144]
	str r10, [fp, #-148]
	ldr r10, [fp, #-148]
	ldr r4, [fp, #-152]
	str r4, [fp, #-444]
	ldr r4, [fp, #-444]
	mul r10, r4, r10
	str r10, [fp, #-156]
	ldr r10, [fp, #-156]
	str r10, [fp, #-160]
	ldr r10, [fp, #-160]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-164]
	ldr r10, [fp, #-164]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	str r10, [fp, #-172]
	ldr r10, [fp, #-172]
	mul r10, r6, r10
	str r10, [fp, #-192]
	mov r10, #400
	str r10, [fp, #-180]
	mov r10, #1
	str r10, [fp, #-176]
	ldr r10, [fp, #-176]
	str r10, [fp, #-184]
	ldr r10, [fp, #-180]
	ldr r4, [fp, #-184]
	str r4, [fp, #-448]
	ldr r4, [fp, #-448]
	mul r10, r10, r4
	str r10, [fp, #-188]
	ldr r10, [fp, #-188]
	str r10, [fp, #-196]
	ldr r10, [fp, #-192]
	ldr r4, [fp, #-196]
	str r4, [fp, #-452]
	ldr r4, [fp, #-452]
	add r10, r10, r4
	str r10, [fp, #-200]
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-204]
	ldr r10, [fp, #-200]
	ldr r4, [fp, #-204]
	str r4, [fp, #-456]
	ldr r4, [fp, #-456]
	str r5, [r4, r10]
	add r5, r7, #1
	mov r7, r5
	b .LBB_2_END_IF
.LBB_2_END_IF:
	add r5, r6, #1
	mov r6, r5
	b .LB_merge_sort1_LOOP_BEGIN
.LB1_LOOP_END:
.LB_3_LOOP_BEGIN:
	cmp r8, r9
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-208]
	ldr r10, [fp, #-208]
	cmp r5, r10
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r5, #4
	mul r5, r8, r5
	mov r10, #400
	str r10, [fp, #-216]
	mov r10, #0
	str r10, [fp, #-212]
	ldr r10, [fp, #-212]
	str r10, [fp, #-220]
	ldr r10, [fp, #-216]
	ldr r4, [fp, #-220]
	str r4, [fp, #-460]
	ldr r4, [fp, #-460]
	mul r10, r10, r4
	str r10, [fp, #-224]
	ldr r10, [fp, #-224]
	str r10, [fp, #-228]
	ldr r10, [fp, #-228]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-232]
	ldr r10, [fp, #-232]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-236]
	ldr r10, [fp, #-236]
	str r10, [fp, #-240]
	ldr r10, [fp, #-240]
	mul r10, r6, r10
	str r10, [fp, #-264]
	mov r10, #400
	str r10, [fp, #-252]
	mov r10, #1
	str r10, [fp, #-244]
	ldr r10, [fp, #-244]
	str r10, [fp, #-248]
	ldr r10, [fp, #-248]
	ldr r4, [fp, #-252]
	str r4, [fp, #-464]
	ldr r4, [fp, #-464]
	mul r10, r4, r10
	str r10, [fp, #-256]
	ldr r10, [fp, #-256]
	str r10, [fp, #-260]
	ldr r10, [fp, #-260]
	ldr r4, [fp, #-264]
	str r4, [fp, #-468]
	ldr r4, [fp, #-468]
	add r10, r4, r10
	str r10, [fp, #-268]
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-272]
	ldr r10, [fp, #-268]
	ldr r4, [fp, #-272]
	str r4, [fp, #-472]
	ldr r4, [fp, #-472]
	str r5, [r4, r10]
	add r5, r8, #1
	mov r8, r5
	add r5, r6, #1
	mov r6, r5
	b .LB_3_LOOP_BEGIN
.LB3_LOOP_END:
.LB_4_LOOP_BEGIN:
	ldr r5, [fp, #-512]
	cmp r7, r5
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-276]
	ldr r10, [fp, #-276]
	cmp r5, r10
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r5, #4
	mul r5, r7, r5
	mov r10, #400
	str r10, [fp, #-288]
	mov r10, #0
	str r10, [fp, #-280]
	ldr r10, [fp, #-280]
	str r10, [fp, #-284]
	ldr r10, [fp, #-284]
	ldr r4, [fp, #-288]
	str r4, [fp, #-476]
	ldr r4, [fp, #-476]
	mul r10, r4, r10
	str r10, [fp, #-292]
	ldr r10, [fp, #-292]
	str r10, [fp, #-296]
	ldr r10, [fp, #-296]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-300]
	ldr r10, [fp, #-300]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-304]
	ldr r10, [fp, #-304]
	str r10, [fp, #-308]
	ldr r10, [fp, #-308]
	mul r10, r6, r10
	str r10, [fp, #-328]
	mov r10, #400
	str r10, [fp, #-316]
	mov r10, #1
	str r10, [fp, #-312]
	ldr r10, [fp, #-312]
	str r10, [fp, #-320]
	ldr r10, [fp, #-316]
	ldr r4, [fp, #-320]
	str r4, [fp, #-480]
	ldr r4, [fp, #-480]
	mul r10, r10, r4
	str r10, [fp, #-324]
	ldr r10, [fp, #-324]
	str r10, [fp, #-332]
	ldr r10, [fp, #-328]
	ldr r4, [fp, #-332]
	str r4, [fp, #-484]
	ldr r4, [fp, #-484]
	add r10, r10, r4
	str r10, [fp, #-336]
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-340]
	ldr r10, [fp, #-336]
	ldr r4, [fp, #-340]
	str r4, [fp, #-488]
	ldr r4, [fp, #-488]
	str r5, [r4, r10]
	add r5, r7, #1
	mov r7, r5
	add r5, r6, #1
	mov r6, r5
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
.LB_5_LOOP_BEGIN:
	ldr r5, [fp, #-412]
	ldr r10, [fp, #-512]
	cmp r5, r10
	mov r5, #0
	movlt r5, #1
	mov r10, #0
	str r10, [fp, #-344]
	ldr r10, [fp, #-344]
	cmp r5, r10
	beq .LB5_LOOP_END
	b .LB5_LOOP_BODY
.LB5_LOOP_BODY:
	mov r5, #4
	ldr r10, [fp, #-412]
	mul r5, r10, r5
	mov r10, #400
	str r10, [fp, #-352]
	mov r10, #1
	str r10, [fp, #-348]
	ldr r10, [fp, #-348]
	str r10, [fp, #-356]
	ldr r10, [fp, #-352]
	ldr r4, [fp, #-356]
	str r4, [fp, #-492]
	ldr r4, [fp, #-492]
	mul r10, r10, r4
	str r10, [fp, #-360]
	ldr r10, [fp, #-360]
	str r10, [fp, #-364]
	ldr r10, [fp, #-364]
	add r5, r5, r10
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-368]
	ldr r10, [fp, #-368]
	ldr r5, [r10, r5]
	mov r10, #4
	str r10, [fp, #-372]
	ldr r10, [fp, #-372]
	str r10, [fp, #-376]
	ldr r10, [fp, #-376]
	ldr r4, [fp, #-412]
	str r4, [fp, #-496]
	ldr r4, [fp, #-496]
	mul r10, r4, r10
	str r10, [fp, #-400]
	mov r10, #400
	str r10, [fp, #-388]
	mov r10, #0
	str r10, [fp, #-380]
	ldr r10, [fp, #-380]
	str r10, [fp, #-384]
	ldr r10, [fp, #-384]
	ldr r4, [fp, #-388]
	str r4, [fp, #-500]
	ldr r4, [fp, #-500]
	mul r10, r4, r10
	str r10, [fp, #-392]
	ldr r10, [fp, #-392]
	str r10, [fp, #-396]
	ldr r10, [fp, #-396]
	ldr r4, [fp, #-400]
	str r4, [fp, #-504]
	ldr r4, [fp, #-504]
	add r10, r4, r10
	str r10, [fp, #-404]
	mov r10, #0
	mov32 r10, buf
	str r10, [fp, #-408]
	ldr r10, [fp, #-404]
	ldr r4, [fp, #-408]
	str r4, [fp, #-508]
	ldr r4, [fp, #-508]
	str r5, [r4, r10]
	ldr r5, [fp, #-412]
	add r5, r5, #1
	str r5, [fp, #-412]
	b .LB_5_LOOP_BEGIN
.LB5_LOOP_END:
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640004947"