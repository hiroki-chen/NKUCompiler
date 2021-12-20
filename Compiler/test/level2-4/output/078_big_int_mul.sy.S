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
.globl len
len:
.word 20

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
	mov r8, #664
	sub sp, sp, r8
.LBmain:
	str r8, [fp, #-504]
	str r8, [fp, #-648]
	str r8, [fp, #-664]
	sub sp, sp, #80
	mov r7, sp
	add r7, r7, #0
	mov r0, r7
	mov r1, #0
	mov r2, #80
	bl memset
	mov r7, sp
	add r7, r7, #0
	mov r6, #1
	str r6, [r7, #0]
	mov r7, sp
	add r7, r7, #0
	mov r6, #2
	str r6, [r7, #4]
	mov r7, sp
	add r7, r7, #0
	mov r6, #3
	str r6, [r7, #8]
	mov r7, sp
	add r7, r7, #0
	mov r6, #4
	str r6, [r7, #12]
	mov r7, sp
	add r7, r7, #0
	mov r6, #5
	str r6, [r7, #16]
	mov r7, sp
	add r7, r7, #0
	mov r6, #6
	str r6, [r7, #20]
	mov r7, sp
	add r7, r7, #0
	mov r6, #7
	str r6, [r7, #24]
	mov r7, sp
	add r7, r7, #0
	mov r6, #8
	str r6, [r7, #28]
	mov r7, sp
	add r7, r7, #0
	mov r6, #9
	str r6, [r7, #32]
	mov r7, sp
	add r7, r7, #0
	mov r6, #0
	str r6, [r7, #36]
	mov r7, sp
	add r7, r7, #0
	mov r6, #1
	str r6, [r7, #40]
	mov r7, sp
	add r7, r7, #0
	mov r6, #2
	str r6, [r7, #44]
	mov r7, sp
	add r7, r7, #0
	mov r6, #3
	str r6, [r7, #48]
	mov r7, sp
	add r7, r7, #0
	mov r6, #4
	str r6, [r7, #52]
	mov r7, sp
	add r7, r7, #0
	mov r6, #5
	str r6, [r7, #56]
	mov r7, sp
	add r7, r7, #0
	mov r6, #6
	str r6, [r7, #60]
	mov r7, sp
	add r7, r7, #0
	mov r6, #7
	str r6, [r7, #64]
	mov r7, sp
	add r7, r7, #0
	mov r6, #8
	str r6, [r7, #68]
	mov r7, sp
	add r7, r7, #0
	mov r6, #9
	str r6, [r7, #72]
	mov r7, sp
	add r7, r7, #0
	mov r6, #0
	str r6, [r7, #76]
	sub sp, sp, #80
	mov r7, sp
	add r7, r7, #0
	mov r0, r7
	mov r1, #0
	mov r2, #80
	bl memset
	mov r7, sp
	add r7, r7, #0
	mov r6, #2
	str r6, [r7, #0]
	mov r7, sp
	add r7, r7, #0
	mov r6, #3
	str r6, [r7, #4]
	mov r7, sp
	add r7, r7, #0
	mov r6, #4
	str r6, [r7, #8]
	mov r7, sp
	add r7, r7, #0
	mov r6, #2
	str r6, [r7, #12]
	mov r7, sp
	add r7, r7, #0
	mov r6, #5
	str r6, [r7, #16]
	mov r7, sp
	add r7, r7, #0
	mov r6, #7
	str r6, [r7, #20]
	mov r7, sp
	add r7, r7, #0
	mov r6, #9
	str r6, [r7, #24]
	mov r7, sp
	add r7, r7, #0
	mov r6, #9
	str r6, [r7, #28]
	mov r7, sp
	add r7, r7, #0
	mov r6, #0
	str r6, [r7, #32]
	mov r7, sp
	add r7, r7, #0
	mov r6, #1
	str r6, [r7, #36]
	mov r7, sp
	add r7, r7, #0
	mov r6, #9
	str r6, [r7, #40]
	mov r7, sp
	add r7, r7, #0
	mov r6, #8
	str r6, [r7, #44]
	mov r7, sp
	add r7, r7, #0
	mov r6, #7
	str r6, [r7, #48]
	mov r7, sp
	add r7, r7, #0
	mov r6, #6
	str r6, [r7, #52]
	mov r7, sp
	add r7, r7, #0
	mov r6, #4
	str r6, [r7, #56]
	mov r7, sp
	add r7, r7, #0
	mov r6, #3
	str r6, [r7, #60]
	mov r7, sp
	add r7, r7, #0
	mov r6, #2
	str r6, [r7, #64]
	mov r7, sp
	add r7, r7, #0
	mov r6, #1
	str r6, [r7, #68]
	mov r7, sp
	add r7, r7, #0
	mov r6, #2
	str r6, [r7, #72]
	mov r7, sp
	add r7, r7, #0
	mov r6, #2
	str r6, [r7, #76]
	mov r6, #0
	mov32 r6, len
	ldr r6, [r6, #0]
	mov r7, r6
	mov r5, #0
	mov32 r5, len
	str r5, [fp, #-4]
	ldr r5, [fp, #-4]
	ldr r5, [r5, #0]
	str r5, [fp, #-4]
	ldr r5, [fp, #-4]
	mov r6, r5
	sub sp, sp, #100
	str r5, [fp, #-4]
	sub sp, sp, #100
	str r5, [fp, #-8]
	sub sp, sp, #160
	str r5, [fp, #-12]
	mov r5, sp
	str r5, [fp, #-16]
	ldr r5, [fp, #-16]
	add r5, r5, #0
	str r5, [fp, #-16]
	ldr r5, [fp, #-16]
	mov r0, r5
	mov r1, #0
	mov r2, #160
	bl memset
	mov r9, #0
.LB_main0_LOOP_BEGIN:
	cmp r9, r7
	mov r5, #0
	movlt r5, #1
	str r5, [fp, #-20]
	mov r5, #0
	str r5, [fp, #-24]
	ldr r5, [fp, #-20]
	ldr r10, [fp, #-24]
	str r10, [fp, #-508]
	ldr r10, [fp, #-508]
	cmp r5, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r5, #4
	str r5, [fp, #-28]
	ldr r5, [fp, #-28]
	mov r5, r5
	str r5, [fp, #-32]
	ldr r5, [fp, #-32]
	mul r5, r9, r5
	str r5, [fp, #-36]
	mov r5, sp
	str r5, [fp, #-40]
	ldr r5, [fp, #-40]
	add r5, r5, #440
	str r5, [fp, #-40]
	ldr r5, [fp, #-36]
	ldr r10, [fp, #-40]
	str r10, [fp, #-508]
	ldr r10, [fp, #-508]
	ldr r5, [r10, r5]
	str r5, [fp, #-52]
	mov r5, #4
	str r5, [fp, #-44]
	ldr r5, [fp, #-44]
	mov r5, r5
	str r5, [fp, #-48]
	ldr r5, [fp, #-48]
	mul r5, r9, r5
	str r5, [fp, #-56]
	mov r5, sp
	str r5, [fp, #-60]
	ldr r5, [fp, #-60]
	add r5, r5, #260
	str r5, [fp, #-60]
	ldr r5, [fp, #-52]
	ldr r10, [fp, #-56]
	str r10, [fp, #-512]
	ldr r10, [fp, #-60]
	str r10, [fp, #-516]
	ldr r10, [fp, #-512]
	ldr r4, [fp, #-516]
	str r4, [fp, #-652]
	ldr r4, [fp, #-652]
	str r5, [r4, r10]
	add r5, r9, #1
	str r5, [fp, #-64]
	ldr r5, [fp, #-64]
	mov r9, r5
	b .LB_main0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r9, #0
.LB_1_LOOP_BEGIN:
	cmp r9, r6
	mov r5, #0
	movlt r5, #1
	str r5, [fp, #-68]
	mov r5, #0
	str r5, [fp, #-72]
	ldr r5, [fp, #-68]
	ldr r10, [fp, #-72]
	str r10, [fp, #-520]
	ldr r10, [fp, #-520]
	cmp r5, r10
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r5, #4
	str r5, [fp, #-76]
	ldr r5, [fp, #-76]
	mov r5, r5
	str r5, [fp, #-80]
	ldr r5, [fp, #-80]
	mul r5, r9, r5
	str r5, [fp, #-84]
	mov r5, sp
	str r5, [fp, #-88]
	ldr r5, [fp, #-88]
	add r5, r5, #360
	str r5, [fp, #-88]
	ldr r5, [fp, #-84]
	ldr r10, [fp, #-88]
	str r10, [fp, #-524]
	ldr r10, [fp, #-524]
	ldr r5, [r10, r5]
	str r5, [fp, #-108]
	mov r5, #4
	str r5, [fp, #-92]
	ldr r5, [fp, #-92]
	mov r5, r5
	str r5, [fp, #-96]
	ldr r5, [fp, #-96]
	mul r5, r9, r5
	str r5, [fp, #-100]
	mov r5, sp
	str r5, [fp, #-104]
	ldr r5, [fp, #-104]
	add r5, r5, #160
	str r5, [fp, #-104]
	ldr r5, [fp, #-100]
	ldr r10, [fp, #-104]
	str r10, [fp, #-528]
	ldr r10, [fp, #-108]
	str r10, [fp, #-532]
	ldr r10, [fp, #-528]
	ldr r4, [fp, #-532]
	str r4, [fp, #-652]
	ldr r4, [fp, #-652]
	str r4, [r10, r5]
	add r5, r9, #1
	str r5, [fp, #-112]
	ldr r5, [fp, #-112]
	mov r9, r5
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	mov r9, r6
	add r9, r7, r9
	sub r9, r9, #1
	mov r9, r9
	str r9, [fp, #-664]
	mov r9, #0
.LB_2_LOOP_BEGIN:
	ldr r5, [fp, #-664]
	cmp r9, r5
	mov r5, #0
	movle r5, #1
	str r5, [fp, #-116]
	mov r5, #0
	str r5, [fp, #-120]
	ldr r5, [fp, #-116]
	ldr r10, [fp, #-120]
	str r10, [fp, #-536]
	ldr r10, [fp, #-536]
	cmp r5, r10
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r5, #4
	str r5, [fp, #-124]
	ldr r5, [fp, #-124]
	mov r5, r5
	str r5, [fp, #-128]
	ldr r5, [fp, #-128]
	mul r5, r9, r5
	str r5, [fp, #-140]
	mov r5, sp
	str r5, [fp, #-136]
	ldr r5, [fp, #-136]
	add r5, r5, #0
	str r5, [fp, #-136]
	mov r5, #0
	str r5, [fp, #-132]
	ldr r5, [fp, #-132]
	ldr r10, [fp, #-136]
	str r10, [fp, #-540]
	ldr r10, [fp, #-140]
	str r10, [fp, #-544]
	ldr r10, [fp, #-540]
	ldr r4, [fp, #-544]
	str r4, [fp, #-656]
	ldr r4, [fp, #-656]
	str r5, [r10, r4]
	add r5, r9, #1
	str r5, [fp, #-144]
	ldr r5, [fp, #-144]
	mov r9, r5
	b .LB_2_LOOP_BEGIN
.LB2_LOOP_END:
	mov r8, #0
	sub r9, r6, #1
	mov r9, r9
.LB_3_LOOP_BEGIN:
	mov r5, #0
	str r5, [fp, #-148]
	ldr r5, [fp, #-148]
	sub r5, r5, #1
	str r5, [fp, #-152]
	ldr r5, [fp, #-152]
	cmp r9, r5
	mov r5, #0
	movgt r5, #1
	str r5, [fp, #-160]
	mov r5, #0
	str r5, [fp, #-156]
	ldr r5, [fp, #-156]
	ldr r10, [fp, #-160]
	str r10, [fp, #-548]
	ldr r10, [fp, #-548]
	cmp r10, r5
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r5, #4
	str r5, [fp, #-164]
	ldr r5, [fp, #-164]
	mov r5, r5
	str r5, [fp, #-168]
	ldr r5, [fp, #-168]
	mul r5, r9, r5
	str r5, [fp, #-172]
	mov r5, sp
	str r5, [fp, #-176]
	ldr r5, [fp, #-176]
	add r5, r5, #160
	str r5, [fp, #-176]
	ldr r5, [fp, #-172]
	ldr r10, [fp, #-176]
	str r10, [fp, #-552]
	ldr r10, [fp, #-552]
	ldr r5, [r10, r5]
	str r5, [fp, #-180]
	ldr r5, [fp, #-180]
	mov r5, r5
	str r5, [fp, #-648]
	sub r5, r7, #1
	str r5, [fp, #-184]
	ldr r5, [fp, #-184]
	mov r5, r5
	str r5, [fp, #-504]
.LB_4_LOOP_BEGIN:
	mov r5, #0
	str r5, [fp, #-188]
	ldr r5, [fp, #-188]
	sub r5, r5, #1
	str r5, [fp, #-192]
	ldr r5, [fp, #-192]
	ldr r10, [fp, #-504]
	str r10, [fp, #-556]
	ldr r10, [fp, #-556]
	cmp r10, r5
	mov r5, #0
	movgt r5, #1
	str r5, [fp, #-196]
	mov r5, #0
	str r5, [fp, #-200]
	ldr r5, [fp, #-196]
	ldr r10, [fp, #-200]
	str r10, [fp, #-560]
	ldr r10, [fp, #-560]
	cmp r5, r10
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r5, #4
	str r5, [fp, #-204]
	ldr r5, [fp, #-204]
	mov r5, r5
	str r5, [fp, #-208]
	ldr r5, [fp, #-208]
	ldr r10, [fp, #-664]
	mul r5, r10, r5
	str r5, [fp, #-212]
	mov r5, sp
	str r5, [fp, #-216]
	ldr r5, [fp, #-216]
	add r5, r5, #0
	str r5, [fp, #-216]
	ldr r5, [fp, #-212]
	ldr r10, [fp, #-216]
	str r10, [fp, #-564]
	ldr r10, [fp, #-564]
	ldr r5, [r10, r5]
	str r5, [fp, #-248]
	mov r5, #4
	str r5, [fp, #-220]
	ldr r5, [fp, #-220]
	mov r5, r5
	str r5, [fp, #-224]
	ldr r5, [fp, #-224]
	ldr r10, [fp, #-504]
	str r10, [fp, #-568]
	ldr r10, [fp, #-568]
	mul r5, r10, r5
	str r5, [fp, #-228]
	mov r5, sp
	str r5, [fp, #-232]
	ldr r5, [fp, #-232]
	add r5, r5, #260
	str r5, [fp, #-232]
	ldr r5, [fp, #-228]
	ldr r10, [fp, #-232]
	str r10, [fp, #-572]
	ldr r10, [fp, #-572]
	ldr r5, [r10, r5]
	str r5, [fp, #-236]
	ldr r5, [fp, #-236]
	mov r5, r5
	str r5, [fp, #-240]
	ldr r5, [fp, #-240]
	ldr r10, [fp, #-648]
	mul r5, r10, r5
	str r5, [fp, #-244]
	ldr r5, [fp, #-244]
	mov r5, r5
	str r5, [fp, #-252]
	ldr r5, [fp, #-248]
	ldr r10, [fp, #-252]
	str r10, [fp, #-576]
	ldr r10, [fp, #-576]
	add r5, r5, r10
	str r5, [fp, #-256]
	ldr r5, [fp, #-256]
	mov r8, r5
	mov r5, #10
	str r5, [fp, #-260]
	ldr r5, [fp, #-260]
	cmp r8, r5
	mov r5, #0
	movge r5, #1
	str r5, [fp, #-264]
	mov r5, #0
	str r5, [fp, #-268]
	ldr r5, [fp, #-264]
	ldr r10, [fp, #-268]
	str r10, [fp, #-580]
	ldr r10, [fp, #-580]
	cmp r5, r10
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	mov r5, #4
	str r5, [fp, #-272]
	ldr r5, [fp, #-272]
	mov r5, r5
	str r5, [fp, #-276]
	ldr r5, [fp, #-276]
	ldr r10, [fp, #-664]
	mul r5, r10, r5
	str r5, [fp, #-280]
	mov r5, sp
	str r5, [fp, #-284]
	ldr r5, [fp, #-284]
	add r5, r5, #0
	str r5, [fp, #-284]
	ldr r5, [fp, #-280]
	ldr r10, [fp, #-284]
	str r10, [fp, #-584]
	ldr r10, [fp, #-584]
	str r8, [r10, r5]
	ldr r5, [fp, #-664]
	sub r5, r5, #1
	str r5, [fp, #-292]
	mov r5, #4
	str r5, [fp, #-288]
	ldr r5, [fp, #-288]
	mov r5, r5
	str r5, [fp, #-296]
	ldr r5, [fp, #-292]
	ldr r10, [fp, #-296]
	str r10, [fp, #-588]
	ldr r10, [fp, #-588]
	mul r5, r5, r10
	str r5, [fp, #-300]
	mov r5, sp
	str r5, [fp, #-304]
	ldr r5, [fp, #-304]
	add r5, r5, #0
	str r5, [fp, #-304]
	ldr r5, [fp, #-300]
	ldr r10, [fp, #-304]
	str r10, [fp, #-592]
	ldr r10, [fp, #-592]
	ldr r5, [r10, r5]
	str r5, [fp, #-320]
	mov r5, r0
	str r5, [fp, #-308]
	mov r5, r1
	str r5, [fp, #-312]
	mov r0, r8
	mov r1, #10
	bl __aeabi_idiv
	mov r5, r0
	str r5, [fp, #-316]
	ldr r5, [fp, #-308]
	mov r0, r5
	ldr r5, [fp, #-312]
	mov r1, r5
	ldr r5, [fp, #-316]
	mov r5, r5
	str r5, [fp, #-324]
	ldr r5, [fp, #-320]
	ldr r10, [fp, #-324]
	str r10, [fp, #-596]
	ldr r10, [fp, #-596]
	add r5, r5, r10
	str r5, [fp, #-348]
	ldr r5, [fp, #-664]
	sub r5, r5, #1
	str r5, [fp, #-332]
	mov r5, #4
	str r5, [fp, #-328]
	ldr r5, [fp, #-328]
	mov r5, r5
	str r5, [fp, #-336]
	ldr r5, [fp, #-332]
	ldr r10, [fp, #-336]
	str r10, [fp, #-600]
	ldr r10, [fp, #-600]
	mul r5, r5, r10
	str r5, [fp, #-340]
	mov r5, sp
	str r5, [fp, #-344]
	ldr r5, [fp, #-344]
	add r5, r5, #0
	str r5, [fp, #-344]
	ldr r5, [fp, #-340]
	ldr r10, [fp, #-344]
	str r10, [fp, #-604]
	ldr r10, [fp, #-348]
	str r10, [fp, #-608]
	ldr r10, [fp, #-604]
	ldr r4, [fp, #-608]
	str r4, [fp, #-660]
	ldr r4, [fp, #-660]
	str r4, [r10, r5]
	b .LBB_5_END_IF
.LBB_5_ELSE:
	mov r5, #4
	str r5, [fp, #-352]
	ldr r5, [fp, #-352]
	mov r5, r5
	str r5, [fp, #-356]
	ldr r5, [fp, #-356]
	ldr r10, [fp, #-664]
	mul r5, r10, r5
	str r5, [fp, #-360]
	mov r5, sp
	str r5, [fp, #-364]
	ldr r5, [fp, #-364]
	add r5, r5, #0
	str r5, [fp, #-364]
	ldr r5, [fp, #-360]
	ldr r10, [fp, #-364]
	str r10, [fp, #-612]
	ldr r10, [fp, #-612]
	str r8, [r10, r5]
	b .LBB_5_END_IF
.LBB_5_END_IF:
	ldr r5, [fp, #-504]
	sub r5, r5, #1
	str r5, [fp, #-368]
	ldr r5, [fp, #-368]
	mov r5, r5
	str r5, [fp, #-504]
	ldr r5, [fp, #-664]
	sub r5, r5, #1
	str r5, [fp, #-372]
	ldr r5, [fp, #-372]
	mov r5, r5
	str r5, [fp, #-664]
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	mov r5, r7
	str r5, [fp, #-376]
	ldr r5, [fp, #-376]
	ldr r10, [fp, #-664]
	add r5, r10, r5
	str r5, [fp, #-380]
	ldr r5, [fp, #-380]
	sub r5, r5, #1
	str r5, [fp, #-384]
	ldr r5, [fp, #-384]
	mov r5, r5
	str r5, [fp, #-664]
	sub r5, r9, #1
	str r5, [fp, #-388]
	ldr r5, [fp, #-388]
	mov r9, r5
	b .LB_3_LOOP_BEGIN
.LB3_LOOP_END:
	mov r5, #0
	str r5, [fp, #-396]
	mov r5, #4
	str r5, [fp, #-392]
	ldr r5, [fp, #-392]
	mov r5, r5
	str r5, [fp, #-400]
	ldr r5, [fp, #-396]
	ldr r10, [fp, #-400]
	str r10, [fp, #-616]
	ldr r10, [fp, #-616]
	mul r5, r5, r10
	str r5, [fp, #-404]
	mov r5, sp
	str r5, [fp, #-408]
	ldr r5, [fp, #-408]
	add r5, r5, #0
	str r5, [fp, #-408]
	ldr r5, [fp, #-404]
	ldr r10, [fp, #-408]
	str r10, [fp, #-620]
	ldr r10, [fp, #-620]
	ldr r5, [r10, r5]
	str r5, [fp, #-412]
	mov r5, #0
	str r5, [fp, #-416]
	ldr r5, [fp, #-412]
	ldr r10, [fp, #-416]
	str r10, [fp, #-624]
	ldr r10, [fp, #-624]
	cmp r5, r10
	mov r5, #0
	movne r5, #1
	str r5, [fp, #-420]
	mov r5, #0
	str r5, [fp, #-424]
	ldr r5, [fp, #-420]
	ldr r10, [fp, #-424]
	str r10, [fp, #-628]
	ldr r10, [fp, #-628]
	cmp r5, r10
	beq .LBB_6_ELSE
	b .LBB_6_IF
.LBB_6_IF:
	mov r5, #0
	str r5, [fp, #-432]
	mov r5, #4
	str r5, [fp, #-428]
	ldr r5, [fp, #-428]
	mov r5, r5
	str r5, [fp, #-436]
	ldr r5, [fp, #-432]
	ldr r10, [fp, #-436]
	str r10, [fp, #-632]
	ldr r10, [fp, #-632]
	mul r5, r5, r10
	str r5, [fp, #-440]
	mov r5, sp
	str r5, [fp, #-444]
	ldr r5, [fp, #-444]
	add r5, r5, #0
	str r5, [fp, #-444]
	ldr r5, [fp, #-440]
	ldr r10, [fp, #-444]
	str r10, [fp, #-636]
	ldr r10, [fp, #-636]
	ldr r5, [r10, r5]
	str r5, [fp, #-448]
	ldr r5, [fp, #-448]
	mov r0, r5
	bl putint
	mov r5, r0
	str r5, [fp, #-452]
	add sp, sp, #0
.LBB_6_ELSE:
	mov r9, #1
.LB_7_LOOP_BEGIN:
	mov r5, r6
	str r5, [fp, #-456]
	ldr r5, [fp, #-456]
	add r5, r7, r5
	str r5, [fp, #-460]
	ldr r5, [fp, #-460]
	sub r5, r5, #1
	str r5, [fp, #-464]
	ldr r5, [fp, #-464]
	cmp r9, r5
	mov r5, #0
	movle r5, #1
	str r5, [fp, #-468]
	mov r5, #0
	str r5, [fp, #-472]
	ldr r5, [fp, #-468]
	ldr r10, [fp, #-472]
	str r10, [fp, #-640]
	ldr r10, [fp, #-640]
	cmp r5, r10
	beq .LB7_LOOP_END
	b .LB7_LOOP_BODY
.LB7_LOOP_BODY:
	mov r5, #4
	str r5, [fp, #-476]
	ldr r5, [fp, #-476]
	mov r5, r5
	str r5, [fp, #-480]
	ldr r5, [fp, #-480]
	mul r5, r9, r5
	str r5, [fp, #-488]
	mov r5, sp
	str r5, [fp, #-484]
	ldr r5, [fp, #-484]
	add r5, r5, #0
	str r5, [fp, #-484]
	ldr r5, [fp, #-484]
	ldr r10, [fp, #-488]
	str r10, [fp, #-644]
	ldr r10, [fp, #-644]
	ldr r5, [r5, r10]
	str r5, [fp, #-492]
	ldr r5, [fp, #-492]
	mov r0, r5
	bl putint
	mov r5, r0
	str r5, [fp, #-496]
	add sp, sp, #0
	add r5, r9, #1
	str r5, [fp, #-500]
	ldr r5, [fp, #-500]
	mov r9, r5
	b .LB_7_LOOP_BEGIN
.LB7_LOOP_END:
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007222"