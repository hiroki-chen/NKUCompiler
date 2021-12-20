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
.globl M
M:
.word 0

.globl L
L:
.word 0

.globl N
N:
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
	mov r8, #0
	sub sp, sp, r8
.LBmain:
	mov r9, #0
	mov32 r9, N
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, N
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, M
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, M
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, L
	ldr r9, [r9, #0]
	mov r9, #3
	mov r8, #0
	mov32 r8, L
	str r9, [r8, #0]
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #12
	sub sp, sp, #24
	sub sp, sp, #12
	sub sp, sp, #12
	mov r9, #0
.LB_main0_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, M
	ldr r8, [r8, #0]
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r8, #4
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #108
	str r9, [r7, r8]
	mov r8, #4
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #96
	str r9, [r7, r8]
	mov r8, #4
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #84
	str r9, [r7, r8]
	mov r8, #4
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #72
	str r9, [r7, r8]
	mov r8, #4
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #60
	str r9, [r7, r8]
	mov r8, #4
	mul r8, r9, r8
	mov r7, sp
	add r7, r7, #48
	str r9, [r7, r8]
	add r8, r9, #1
	mov r9, r8
	b .LB_main0_LOOP_BEGIN
.LB0_LOOP_END:
	add r8, sp, #12
	add r7, sp, #24
	add r6, sp, #48
	add r5, sp, #60
	add r10, sp, #72
	mov r3, r10
	add r10, sp, #84
	mov r2, r10
	add r10, sp, #96
	mov r1, r10
	add r10, sp, #108
	mov r0, r10
	push {r9}
	push {r8}
	push {r7}
	push {r6}
	push {r5}
	bl mul
	mov r9, r0
	add sp, sp, #20
.LB_1_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, N
	ldr r7, [r7, #0]
	cmp r9, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r7, #4
	mul r7, r9, r7
	mov r6, sp
	add r6, r6, #24
	ldr r7, [r6, r7]
	mov r8, r7
	mov r0, r8
	bl putint
	mov r7, r0
	add r7, r9, #1
	mov r9, r7
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	mov r9, #10
	mov r8, #0
	mov r0, r9
	bl putch
	mov r7, r0
.LB_2_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, N
	ldr r7, [r7, #0]
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r7, #4
	mul r7, r8, r7
	mov r6, sp
	add r6, r6, #12
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add r7, r8, #1
	mov r8, r7
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r9, #10
	mov r8, #0
	mov r0, r9
	bl putch
	mov r7, r0
.LB_3_LOOP_BEGIN:
	mov r7, #0
	mov32 r7, N
	ldr r7, [r7, #0]
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r7, #4
	mul r7, r8, r7
	mov r6, sp
	ldr r7, [r6, r7]
	mov r9, r7
	mov r0, r9
	bl putint
	mov r7, r0
	add r7, r8, #1
	mov r8, r7
	b .LB_3_LOOP_BEGIN
.LB3_LOOP_END:
	mov r9, #10
	mov r0, r9
	bl putch
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

.globl mul
.type mul, %function
mul:
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
	mov r8, #1204
	sub sp, sp, r8
.LBmul:
	mov r9, r0
	mov r8, r1
	mov r7, r2
	str r7, [fp, #-1196]
	mov r7, r3
	add r6, fp, #36
	ldr r6, [r6]
	str r6, [fp, #-1204]
	add r6, fp, #40
	ldr r6, [r6]
	str r6, [fp, #-932]
	add r6, fp, #44
	ldr r6, [r6]
	add r5, fp, #48
	str r5, [fp, #-4]
	ldr r5, [fp, #-4]
	ldr r5, [r5]
	str r5, [fp, #-880]
	add r5, fp, #52
	str r5, [fp, #-4]
	ldr r5, [fp, #-4]
	ldr r5, [r5]
	str r5, [fp, #-936]
	str r5, [fp, #-8]
	mov r5, #0
	str r5, [fp, #-8]
	mov r5, #0
	str r5, [fp, #-20]
	mov r5, #4
	str r5, [fp, #-12]
	ldr r5, [fp, #-12]
	str r5, [fp, #-16]
	ldr r5, [fp, #-16]
	ldr r10, [fp, #-20]
	str r10, [fp, #-940]
	ldr r10, [fp, #-940]
	mul r5, r10, r5
	str r5, [fp, #-28]
	mov r5, r9
	str r5, [fp, #-24]
	ldr r5, [fp, #-24]
	ldr r10, [fp, #-28]
	str r10, [fp, #-940]
	ldr r10, [fp, #-940]
	ldr r5, [r5, r10]
	str r5, [fp, #-60]
	mov r5, #0
	str r5, [fp, #-40]
	mov r5, #4
	str r5, [fp, #-32]
	ldr r5, [fp, #-32]
	str r5, [fp, #-36]
	ldr r5, [fp, #-36]
	ldr r10, [fp, #-40]
	str r10, [fp, #-944]
	ldr r10, [fp, #-944]
	mul r5, r10, r5
	str r5, [fp, #-44]
	mov r5, r7
	str r5, [fp, #-48]
	ldr r5, [fp, #-44]
	ldr r10, [fp, #-48]
	str r10, [fp, #-948]
	ldr r10, [fp, #-948]
	ldr r5, [r10, r5]
	str r5, [fp, #-52]
	ldr r5, [fp, #-52]
	str r5, [fp, #-56]
	ldr r5, [fp, #-56]
	ldr r10, [fp, #-60]
	str r10, [fp, #-952]
	ldr r10, [fp, #-952]
	mul r5, r10, r5
	str r5, [fp, #-120]
	mov r5, #1
	str r5, [fp, #-68]
	mov r5, #4
	str r5, [fp, #-64]
	ldr r5, [fp, #-64]
	str r5, [fp, #-72]
	ldr r5, [fp, #-68]
	ldr r10, [fp, #-72]
	str r10, [fp, #-956]
	ldr r10, [fp, #-956]
	mul r5, r5, r10
	str r5, [fp, #-76]
	mov r5, r9
	str r5, [fp, #-80]
	ldr r5, [fp, #-76]
	ldr r10, [fp, #-80]
	str r10, [fp, #-960]
	ldr r10, [fp, #-960]
	ldr r5, [r10, r5]
	str r5, [fp, #-112]
	mov r5, #0
	str r5, [fp, #-92]
	mov r5, #4
	str r5, [fp, #-84]
	ldr r5, [fp, #-84]
	str r5, [fp, #-88]
	ldr r5, [fp, #-88]
	ldr r10, [fp, #-92]
	str r10, [fp, #-964]
	ldr r10, [fp, #-964]
	mul r5, r10, r5
	str r5, [fp, #-96]
	ldr r5, [fp, #-1204]
	str r5, [fp, #-100]
	ldr r5, [fp, #-96]
	ldr r10, [fp, #-100]
	str r10, [fp, #-968]
	ldr r10, [fp, #-968]
	ldr r5, [r10, r5]
	str r5, [fp, #-104]
	ldr r5, [fp, #-104]
	str r5, [fp, #-108]
	ldr r5, [fp, #-108]
	ldr r10, [fp, #-112]
	str r10, [fp, #-972]
	ldr r10, [fp, #-972]
	mul r5, r10, r5
	str r5, [fp, #-116]
	ldr r5, [fp, #-116]
	str r5, [fp, #-124]
	ldr r5, [fp, #-120]
	ldr r10, [fp, #-124]
	str r10, [fp, #-976]
	ldr r10, [fp, #-976]
	add r5, r5, r10
	str r5, [fp, #-184]
	mov r5, #2
	str r5, [fp, #-132]
	mov r5, #4
	str r5, [fp, #-128]
	ldr r5, [fp, #-128]
	str r5, [fp, #-136]
	ldr r5, [fp, #-132]
	ldr r10, [fp, #-136]
	str r10, [fp, #-980]
	ldr r10, [fp, #-980]
	mul r5, r5, r10
	str r5, [fp, #-140]
	mov r5, r9
	str r5, [fp, #-144]
	ldr r5, [fp, #-140]
	ldr r10, [fp, #-144]
	str r10, [fp, #-984]
	ldr r10, [fp, #-984]
	ldr r5, [r10, r5]
	str r5, [fp, #-176]
	mov r5, #0
	str r5, [fp, #-152]
	mov r5, #4
	str r5, [fp, #-148]
	ldr r5, [fp, #-148]
	str r5, [fp, #-156]
	ldr r5, [fp, #-152]
	ldr r10, [fp, #-156]
	str r10, [fp, #-988]
	ldr r10, [fp, #-988]
	mul r5, r5, r10
	str r5, [fp, #-160]
	ldr r5, [fp, #-932]
	str r5, [fp, #-164]
	ldr r5, [fp, #-160]
	ldr r10, [fp, #-164]
	str r10, [fp, #-992]
	ldr r10, [fp, #-992]
	ldr r5, [r10, r5]
	str r5, [fp, #-168]
	ldr r5, [fp, #-168]
	str r5, [fp, #-172]
	ldr r5, [fp, #-172]
	ldr r10, [fp, #-176]
	str r10, [fp, #-996]
	ldr r10, [fp, #-996]
	mul r5, r10, r5
	str r5, [fp, #-180]
	ldr r5, [fp, #-180]
	str r5, [fp, #-188]
	ldr r5, [fp, #-184]
	ldr r10, [fp, #-188]
	str r10, [fp, #-1000]
	ldr r10, [fp, #-1000]
	add r5, r5, r10
	str r5, [fp, #-204]
	mov r5, #0
	str r5, [fp, #-196]
	mov r5, #4
	str r5, [fp, #-192]
	ldr r5, [fp, #-192]
	str r5, [fp, #-200]
	ldr r5, [fp, #-196]
	ldr r10, [fp, #-200]
	str r10, [fp, #-1004]
	ldr r10, [fp, #-1004]
	mul r5, r5, r10
	str r5, [fp, #-208]
	mov r5, r6
	str r5, [fp, #-212]
	ldr r5, [fp, #-204]
	ldr r10, [fp, #-208]
	str r10, [fp, #-1008]
	ldr r10, [fp, #-212]
	str r10, [fp, #-1012]
	ldr r10, [fp, #-1008]
	ldr r4, [fp, #-1012]
	str r4, [fp, #-1200]
	ldr r4, [fp, #-1200]
	str r5, [r4, r10]
	mov r5, #0
	str r5, [fp, #-220]
	mov r5, #4
	str r5, [fp, #-216]
	ldr r5, [fp, #-216]
	str r5, [fp, #-224]
	ldr r5, [fp, #-220]
	ldr r10, [fp, #-224]
	str r10, [fp, #-1016]
	ldr r10, [fp, #-1016]
	mul r5, r5, r10
	str r5, [fp, #-228]
	mov r5, r9
	str r5, [fp, #-232]
	ldr r5, [fp, #-228]
	ldr r10, [fp, #-232]
	str r10, [fp, #-1020]
	ldr r10, [fp, #-1020]
	ldr r5, [r10, r5]
	str r5, [fp, #-264]
	mov r5, #1
	str r5, [fp, #-240]
	mov r5, #4
	str r5, [fp, #-236]
	ldr r5, [fp, #-236]
	str r5, [fp, #-244]
	ldr r5, [fp, #-240]
	ldr r10, [fp, #-244]
	str r10, [fp, #-1024]
	ldr r10, [fp, #-1024]
	mul r5, r5, r10
	str r5, [fp, #-248]
	mov r5, r7
	str r5, [fp, #-252]
	ldr r5, [fp, #-248]
	ldr r10, [fp, #-252]
	str r10, [fp, #-1028]
	ldr r10, [fp, #-1028]
	ldr r5, [r10, r5]
	str r5, [fp, #-256]
	ldr r5, [fp, #-256]
	str r5, [fp, #-260]
	ldr r5, [fp, #-260]
	ldr r10, [fp, #-264]
	str r10, [fp, #-1032]
	ldr r10, [fp, #-1032]
	mul r5, r10, r5
	str r5, [fp, #-328]
	mov r5, #1
	str r5, [fp, #-272]
	mov r5, #4
	str r5, [fp, #-268]
	ldr r5, [fp, #-268]
	str r5, [fp, #-276]
	ldr r5, [fp, #-272]
	ldr r10, [fp, #-276]
	str r10, [fp, #-1036]
	ldr r10, [fp, #-1036]
	mul r5, r5, r10
	str r5, [fp, #-280]
	mov r5, r9
	str r5, [fp, #-284]
	ldr r5, [fp, #-280]
	ldr r10, [fp, #-284]
	str r10, [fp, #-1040]
	ldr r10, [fp, #-1040]
	ldr r5, [r10, r5]
	str r5, [fp, #-312]
	mov r5, #1
	str r5, [fp, #-292]
	mov r5, #4
	str r5, [fp, #-288]
	ldr r5, [fp, #-288]
	str r5, [fp, #-296]
	ldr r5, [fp, #-292]
	ldr r10, [fp, #-296]
	str r10, [fp, #-1044]
	ldr r10, [fp, #-1044]
	mul r5, r5, r10
	str r5, [fp, #-300]
	ldr r5, [fp, #-1204]
	str r5, [fp, #-304]
	ldr r5, [fp, #-300]
	ldr r10, [fp, #-304]
	str r10, [fp, #-1048]
	ldr r10, [fp, #-1048]
	ldr r5, [r10, r5]
	str r5, [fp, #-308]
	ldr r5, [fp, #-308]
	str r5, [fp, #-316]
	ldr r5, [fp, #-312]
	ldr r10, [fp, #-316]
	str r10, [fp, #-1052]
	ldr r10, [fp, #-1052]
	mul r5, r5, r10
	str r5, [fp, #-320]
	ldr r5, [fp, #-320]
	str r5, [fp, #-324]
	ldr r5, [fp, #-324]
	ldr r10, [fp, #-328]
	str r10, [fp, #-1056]
	ldr r10, [fp, #-1056]
	add r5, r10, r5
	str r5, [fp, #-388]
	mov r5, #2
	str r5, [fp, #-336]
	mov r5, #4
	str r5, [fp, #-332]
	ldr r5, [fp, #-332]
	str r5, [fp, #-340]
	ldr r5, [fp, #-336]
	ldr r10, [fp, #-340]
	str r10, [fp, #-1060]
	ldr r10, [fp, #-1060]
	mul r5, r5, r10
	str r5, [fp, #-344]
	mov r5, r9
	str r5, [fp, #-348]
	ldr r5, [fp, #-344]
	ldr r10, [fp, #-348]
	str r10, [fp, #-1064]
	ldr r10, [fp, #-1064]
	ldr r5, [r10, r5]
	str r5, [fp, #-376]
	mov r5, #1
	str r5, [fp, #-356]
	mov r5, #4
	str r5, [fp, #-352]
	ldr r5, [fp, #-352]
	str r5, [fp, #-360]
	ldr r5, [fp, #-356]
	ldr r10, [fp, #-360]
	str r10, [fp, #-1068]
	ldr r10, [fp, #-1068]
	mul r5, r5, r10
	str r5, [fp, #-364]
	ldr r5, [fp, #-932]
	str r5, [fp, #-368]
	ldr r5, [fp, #-364]
	ldr r10, [fp, #-368]
	str r10, [fp, #-1072]
	ldr r10, [fp, #-1072]
	ldr r5, [r10, r5]
	str r5, [fp, #-372]
	ldr r5, [fp, #-372]
	str r5, [fp, #-380]
	ldr r5, [fp, #-376]
	ldr r10, [fp, #-380]
	str r10, [fp, #-1076]
	ldr r10, [fp, #-1076]
	mul r5, r5, r10
	str r5, [fp, #-384]
	ldr r5, [fp, #-384]
	str r5, [fp, #-392]
	ldr r5, [fp, #-388]
	ldr r10, [fp, #-392]
	str r10, [fp, #-1080]
	ldr r10, [fp, #-1080]
	add r5, r5, r10
	str r5, [fp, #-408]
	mov r5, #1
	str r5, [fp, #-400]
	mov r5, #4
	str r5, [fp, #-396]
	ldr r5, [fp, #-396]
	str r5, [fp, #-404]
	ldr r5, [fp, #-400]
	ldr r10, [fp, #-404]
	str r10, [fp, #-1084]
	ldr r10, [fp, #-1084]
	mul r5, r5, r10
	str r5, [fp, #-412]
	mov r5, r6
	str r5, [fp, #-416]
	ldr r5, [fp, #-408]
	ldr r10, [fp, #-412]
	str r10, [fp, #-1088]
	ldr r10, [fp, #-416]
	str r10, [fp, #-1092]
	ldr r10, [fp, #-1088]
	ldr r4, [fp, #-1092]
	str r4, [fp, #-1200]
	ldr r4, [fp, #-1200]
	str r5, [r4, r10]
	mov r5, #0
	str r5, [fp, #-424]
	mov r5, #4
	str r5, [fp, #-420]
	ldr r5, [fp, #-420]
	str r5, [fp, #-428]
	ldr r5, [fp, #-424]
	ldr r10, [fp, #-428]
	str r10, [fp, #-1096]
	ldr r10, [fp, #-1096]
	mul r5, r5, r10
	str r5, [fp, #-432]
	mov r5, r9
	str r5, [fp, #-436]
	ldr r5, [fp, #-432]
	ldr r10, [fp, #-436]
	str r10, [fp, #-1100]
	ldr r10, [fp, #-1100]
	ldr r5, [r10, r5]
	str r5, [fp, #-464]
	mov r5, #2
	str r5, [fp, #-444]
	mov r5, #4
	str r5, [fp, #-440]
	ldr r5, [fp, #-440]
	str r5, [fp, #-448]
	ldr r5, [fp, #-444]
	ldr r10, [fp, #-448]
	str r10, [fp, #-1104]
	ldr r10, [fp, #-1104]
	mul r5, r5, r10
	str r5, [fp, #-452]
	mov r5, r7
	str r5, [fp, #-456]
	ldr r5, [fp, #-452]
	ldr r10, [fp, #-456]
	str r10, [fp, #-1108]
	ldr r10, [fp, #-1108]
	ldr r5, [r10, r5]
	str r5, [fp, #-460]
	ldr r5, [fp, #-460]
	str r5, [fp, #-468]
	ldr r5, [fp, #-464]
	ldr r10, [fp, #-468]
	str r10, [fp, #-1112]
	ldr r10, [fp, #-1112]
	mul r5, r5, r10
	str r5, [fp, #-528]
	mov r5, #1
	str r5, [fp, #-476]
	mov r5, #4
	str r5, [fp, #-472]
	ldr r5, [fp, #-472]
	str r5, [fp, #-480]
	ldr r5, [fp, #-476]
	ldr r10, [fp, #-480]
	str r10, [fp, #-1116]
	ldr r10, [fp, #-1116]
	mul r5, r5, r10
	str r5, [fp, #-484]
	mov r5, r9
	str r5, [fp, #-488]
	ldr r5, [fp, #-484]
	ldr r10, [fp, #-488]
	str r10, [fp, #-1120]
	ldr r10, [fp, #-1120]
	ldr r5, [r10, r5]
	str r5, [fp, #-520]
	mov r5, #2
	str r5, [fp, #-496]
	mov r5, #4
	str r5, [fp, #-492]
	ldr r5, [fp, #-492]
	str r5, [fp, #-500]
	ldr r5, [fp, #-496]
	ldr r10, [fp, #-500]
	str r10, [fp, #-1124]
	ldr r10, [fp, #-1124]
	mul r5, r5, r10
	str r5, [fp, #-504]
	ldr r5, [fp, #-1204]
	str r5, [fp, #-508]
	ldr r5, [fp, #-504]
	ldr r10, [fp, #-508]
	str r10, [fp, #-1128]
	ldr r10, [fp, #-1128]
	ldr r5, [r10, r5]
	str r5, [fp, #-512]
	ldr r5, [fp, #-512]
	str r5, [fp, #-516]
	ldr r5, [fp, #-516]
	ldr r10, [fp, #-520]
	str r10, [fp, #-1132]
	ldr r10, [fp, #-1132]
	mul r5, r10, r5
	str r5, [fp, #-524]
	ldr r5, [fp, #-524]
	str r5, [fp, #-532]
	ldr r5, [fp, #-528]
	ldr r10, [fp, #-532]
	str r10, [fp, #-1136]
	ldr r10, [fp, #-1136]
	add r5, r5, r10
	str r5, [fp, #-580]
	mov r5, #2
	str r5, [fp, #-540]
	mov r5, #4
	str r5, [fp, #-536]
	ldr r5, [fp, #-536]
	str r5, [fp, #-544]
	ldr r5, [fp, #-540]
	ldr r10, [fp, #-544]
	str r10, [fp, #-1140]
	ldr r10, [fp, #-1140]
	mul r5, r5, r10
	str r5, [fp, #-548]
	ldr r5, [fp, #-548]
	ldr r9, [r9, r5]
	mov r5, #2
	str r5, [fp, #-556]
	mov r5, #4
	str r5, [fp, #-552]
	ldr r5, [fp, #-552]
	str r5, [fp, #-560]
	ldr r5, [fp, #-556]
	ldr r10, [fp, #-560]
	str r10, [fp, #-1144]
	ldr r10, [fp, #-1144]
	mul r5, r5, r10
	str r5, [fp, #-568]
	ldr r5, [fp, #-932]
	str r5, [fp, #-564]
	ldr r5, [fp, #-564]
	ldr r10, [fp, #-568]
	str r10, [fp, #-1148]
	ldr r10, [fp, #-1148]
	ldr r5, [r5, r10]
	str r5, [fp, #-572]
	ldr r5, [fp, #-572]
	str r5, [fp, #-576]
	ldr r5, [fp, #-576]
	mul r9, r9, r5
	ldr r5, [fp, #-580]
	add r9, r5, r9
	mov r5, #2
	str r5, [fp, #-592]
	mov r5, #4
	str r5, [fp, #-584]
	ldr r5, [fp, #-584]
	str r5, [fp, #-588]
	ldr r5, [fp, #-588]
	ldr r10, [fp, #-592]
	str r10, [fp, #-1152]
	ldr r10, [fp, #-1152]
	mul r5, r10, r5
	str r5, [fp, #-596]
	ldr r5, [fp, #-596]
	str r9, [r6, r5]
	mov r9, #0
	mov r6, #4
	mul r9, r9, r6
	mov r6, r8
	ldr r9, [r6, r9]
	mov r6, #0
	mov r5, #4
	str r5, [fp, #-600]
	ldr r5, [fp, #-600]
	str r5, [fp, #-604]
	ldr r5, [fp, #-604]
	mul r6, r6, r5
	mov r5, r7
	str r5, [fp, #-608]
	ldr r5, [fp, #-608]
	ldr r6, [r5, r6]
	mul r9, r9, r6
	mov r6, #1
	mov r5, #4
	str r5, [fp, #-612]
	ldr r5, [fp, #-612]
	str r5, [fp, #-616]
	ldr r5, [fp, #-616]
	mul r6, r6, r5
	mov r5, r8
	str r5, [fp, #-620]
	ldr r5, [fp, #-620]
	ldr r6, [r5, r6]
	mov r5, #0
	str r5, [fp, #-628]
	mov r5, #4
	str r5, [fp, #-624]
	ldr r5, [fp, #-624]
	str r5, [fp, #-632]
	ldr r5, [fp, #-628]
	ldr r10, [fp, #-632]
	str r10, [fp, #-1156]
	ldr r10, [fp, #-1156]
	mul r5, r5, r10
	str r5, [fp, #-636]
	ldr r5, [fp, #-1204]
	str r5, [fp, #-640]
	ldr r5, [fp, #-636]
	ldr r10, [fp, #-640]
	str r10, [fp, #-1160]
	ldr r10, [fp, #-1160]
	ldr r5, [r10, r5]
	str r5, [fp, #-644]
	ldr r5, [fp, #-644]
	str r5, [fp, #-648]
	ldr r5, [fp, #-648]
	mul r6, r6, r5
	add r9, r9, r6
	mov r6, #2
	mov r5, #4
	str r5, [fp, #-652]
	ldr r5, [fp, #-652]
	str r5, [fp, #-656]
	ldr r5, [fp, #-656]
	mul r6, r6, r5
	mov r5, r8
	str r5, [fp, #-660]
	ldr r5, [fp, #-660]
	ldr r6, [r5, r6]
	mov r5, #0
	str r5, [fp, #-672]
	mov r5, #4
	str r5, [fp, #-664]
	ldr r5, [fp, #-664]
	str r5, [fp, #-668]
	ldr r5, [fp, #-668]
	ldr r10, [fp, #-672]
	str r10, [fp, #-1164]
	ldr r10, [fp, #-1164]
	mul r5, r10, r5
	str r5, [fp, #-676]
	ldr r5, [fp, #-932]
	str r5, [fp, #-680]
	ldr r5, [fp, #-676]
	ldr r10, [fp, #-680]
	str r10, [fp, #-1168]
	ldr r10, [fp, #-1168]
	ldr r5, [r10, r5]
	str r5, [fp, #-684]
	ldr r5, [fp, #-684]
	str r5, [fp, #-688]
	ldr r5, [fp, #-688]
	mul r6, r6, r5
	add r9, r9, r6
	mov r6, #0
	mov r5, #4
	str r5, [fp, #-692]
	ldr r5, [fp, #-692]
	str r5, [fp, #-696]
	ldr r5, [fp, #-696]
	mul r6, r6, r5
	ldr r5, [fp, #-880]
	str r5, [fp, #-700]
	ldr r5, [fp, #-700]
	str r9, [r5, r6]
	mov r9, #0
	mov r6, #4
	mul r9, r9, r6
	mov r6, r8
	ldr r9, [r6, r9]
	mov r6, #1
	mov r5, #4
	str r5, [fp, #-704]
	ldr r5, [fp, #-704]
	str r5, [fp, #-708]
	ldr r5, [fp, #-708]
	mul r6, r6, r5
	mov r5, r7
	str r5, [fp, #-712]
	ldr r5, [fp, #-712]
	ldr r6, [r5, r6]
	mul r9, r9, r6
	mov r6, #1
	mov r5, #4
	str r5, [fp, #-716]
	ldr r5, [fp, #-716]
	str r5, [fp, #-720]
	ldr r5, [fp, #-720]
	mul r6, r6, r5
	mov r5, r8
	str r5, [fp, #-724]
	ldr r5, [fp, #-724]
	ldr r6, [r5, r6]
	mov r5, #1
	str r5, [fp, #-732]
	mov r5, #4
	str r5, [fp, #-728]
	ldr r5, [fp, #-728]
	str r5, [fp, #-736]
	ldr r5, [fp, #-732]
	ldr r10, [fp, #-736]
	str r10, [fp, #-1172]
	ldr r10, [fp, #-1172]
	mul r5, r5, r10
	str r5, [fp, #-740]
	ldr r5, [fp, #-1204]
	str r5, [fp, #-744]
	ldr r5, [fp, #-740]
	ldr r10, [fp, #-744]
	str r10, [fp, #-1176]
	ldr r10, [fp, #-1176]
	ldr r5, [r10, r5]
	str r5, [fp, #-748]
	ldr r5, [fp, #-748]
	str r5, [fp, #-752]
	ldr r5, [fp, #-752]
	mul r6, r6, r5
	add r9, r9, r6
	mov r6, #2
	mov r5, #4
	str r5, [fp, #-756]
	ldr r5, [fp, #-756]
	str r5, [fp, #-760]
	ldr r5, [fp, #-760]
	mul r6, r6, r5
	mov r5, r8
	str r5, [fp, #-764]
	ldr r5, [fp, #-764]
	ldr r6, [r5, r6]
	mov r5, #1
	str r5, [fp, #-772]
	mov r5, #4
	str r5, [fp, #-768]
	ldr r5, [fp, #-768]
	str r5, [fp, #-776]
	ldr r5, [fp, #-772]
	ldr r10, [fp, #-776]
	str r10, [fp, #-1180]
	ldr r10, [fp, #-1180]
	mul r5, r5, r10
	str r5, [fp, #-780]
	ldr r5, [fp, #-932]
	str r5, [fp, #-784]
	ldr r5, [fp, #-780]
	ldr r10, [fp, #-784]
	str r10, [fp, #-1184]
	ldr r10, [fp, #-1184]
	ldr r5, [r10, r5]
	str r5, [fp, #-788]
	ldr r5, [fp, #-788]
	str r5, [fp, #-792]
	ldr r5, [fp, #-792]
	mul r6, r6, r5
	add r9, r9, r6
	mov r6, #1
	mov r5, #4
	str r5, [fp, #-796]
	ldr r5, [fp, #-796]
	str r5, [fp, #-800]
	ldr r5, [fp, #-800]
	mul r6, r6, r5
	ldr r5, [fp, #-880]
	str r5, [fp, #-804]
	ldr r5, [fp, #-804]
	str r9, [r5, r6]
	mov r9, #0
	mov r6, #4
	mul r9, r9, r6
	mov r6, r8
	ldr r9, [r6, r9]
	mov r6, #2
	mov r5, #4
	str r5, [fp, #-808]
	ldr r5, [fp, #-808]
	str r5, [fp, #-812]
	ldr r5, [fp, #-812]
	mul r6, r6, r5
	mov r5, r7
	str r5, [fp, #-816]
	ldr r5, [fp, #-816]
	ldr r6, [r5, r6]
	mul r9, r9, r6
	mov r6, #1
	mov r5, #4
	str r5, [fp, #-820]
	ldr r5, [fp, #-820]
	str r5, [fp, #-824]
	ldr r5, [fp, #-824]
	mul r6, r6, r5
	mov r5, r8
	str r5, [fp, #-828]
	ldr r5, [fp, #-828]
	ldr r6, [r5, r6]
	mov r5, #2
	str r5, [fp, #-836]
	mov r5, #4
	str r5, [fp, #-832]
	ldr r5, [fp, #-832]
	str r5, [fp, #-840]
	ldr r5, [fp, #-836]
	ldr r10, [fp, #-840]
	str r10, [fp, #-1188]
	ldr r10, [fp, #-1188]
	mul r5, r5, r10
	str r5, [fp, #-844]
	ldr r5, [fp, #-1204]
	str r5, [fp, #-848]
	ldr r5, [fp, #-844]
	ldr r10, [fp, #-848]
	str r10, [fp, #-1192]
	ldr r10, [fp, #-1192]
	ldr r5, [r10, r5]
	str r5, [fp, #-852]
	ldr r5, [fp, #-852]
	str r5, [fp, #-856]
	ldr r5, [fp, #-856]
	mul r6, r6, r5
	add r9, r9, r6
	mov r6, #2
	mov r5, #4
	str r5, [fp, #-860]
	ldr r5, [fp, #-860]
	str r5, [fp, #-864]
	ldr r5, [fp, #-864]
	mul r6, r6, r5
	ldr r8, [r8, r6]
	mov r6, #2
	mov r5, #4
	str r5, [fp, #-868]
	ldr r5, [fp, #-868]
	str r5, [fp, #-872]
	ldr r5, [fp, #-872]
	mul r6, r6, r5
	ldr r5, [fp, #-932]
	str r5, [fp, #-876]
	ldr r5, [fp, #-876]
	ldr r6, [r5, r6]
	mul r8, r8, r6
	add r9, r9, r8
	mov r8, #2
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-880]
	str r9, [r6, r8]
	mov r9, #0
	mov r8, #4
	mul r9, r9, r8
	ldr r8, [fp, #-1196]
	ldr r9, [r8, r9]
	mov r8, #0
	mov r6, #4
	mul r8, r8, r6
	mov r6, r7
	ldr r8, [r6, r8]
	mul r9, r9, r8
	mov r8, #1
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-1196]
	ldr r8, [r6, r8]
	mov r6, #0
	mov r5, #4
	str r5, [fp, #-884]
	ldr r5, [fp, #-884]
	str r5, [fp, #-888]
	ldr r5, [fp, #-888]
	mul r6, r6, r5
	ldr r5, [fp, #-1204]
	str r5, [fp, #-892]
	ldr r5, [fp, #-892]
	ldr r6, [r5, r6]
	mul r8, r8, r6
	add r9, r9, r8
	mov r8, #2
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-1196]
	ldr r8, [r6, r8]
	mov r6, #0
	mov r5, #4
	str r5, [fp, #-896]
	ldr r5, [fp, #-896]
	str r5, [fp, #-900]
	ldr r5, [fp, #-900]
	mul r6, r6, r5
	ldr r5, [fp, #-932]
	str r5, [fp, #-904]
	ldr r5, [fp, #-904]
	ldr r6, [r5, r6]
	mul r8, r8, r6
	add r9, r9, r8
	mov r8, #0
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-936]
	str r9, [r6, r8]
	mov r9, #0
	mov r8, #4
	mul r9, r9, r8
	ldr r8, [fp, #-1196]
	ldr r9, [r8, r9]
	mov r8, #1
	mov r6, #4
	mul r8, r8, r6
	mov r6, r7
	ldr r8, [r6, r8]
	mul r9, r9, r8
	mov r8, #1
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-1196]
	ldr r8, [r6, r8]
	mov r6, #1
	mov r5, #4
	str r5, [fp, #-908]
	ldr r5, [fp, #-908]
	str r5, [fp, #-912]
	ldr r5, [fp, #-912]
	mul r6, r6, r5
	ldr r5, [fp, #-1204]
	str r5, [fp, #-916]
	ldr r5, [fp, #-916]
	ldr r6, [r5, r6]
	mul r8, r8, r6
	add r9, r9, r8
	mov r8, #2
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-1196]
	ldr r8, [r6, r8]
	mov r6, #1
	mov r5, #4
	str r5, [fp, #-920]
	ldr r5, [fp, #-920]
	str r5, [fp, #-924]
	ldr r5, [fp, #-924]
	mul r6, r6, r5
	ldr r5, [fp, #-932]
	str r5, [fp, #-928]
	ldr r5, [fp, #-928]
	ldr r6, [r5, r6]
	mul r8, r8, r6
	add r9, r9, r8
	mov r8, #1
	mov r6, #4
	mul r8, r8, r6
	ldr r6, [fp, #-936]
	str r9, [r6, r8]
	mov r9, #0
	mov r8, #4
	mul r9, r9, r8
	ldr r8, [fp, #-1196]
	ldr r9, [r8, r9]
	mov r8, #2
	mov r6, #4
	mul r8, r8, r6
	ldr r8, [r7, r8]
	mul r9, r9, r8
	mov r8, #1
	mov r7, #4
	mul r8, r8, r7
	ldr r7, [fp, #-1196]
	ldr r8, [r7, r8]
	mov r7, #2
	mov r6, #4
	mul r7, r7, r6
	ldr r6, [fp, #-1204]
	ldr r7, [r6, r7]
	mul r8, r8, r7
	add r9, r9, r8
	mov r8, #2
	mov r7, #4
	mul r8, r8, r7
	ldr r7, [fp, #-1196]
	ldr r8, [r7, r8]
	mov r7, #2
	mov r6, #4
	mul r7, r7, r6
	ldr r6, [fp, #-932]
	ldr r7, [r6, r7]
	mul r8, r8, r7
	add r9, r9, r8
	mov r8, #2
	mov r7, #4
	mul r8, r8, r7
	ldr r7, [fp, #-936]
	str r9, [r7, r8]
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640004946"