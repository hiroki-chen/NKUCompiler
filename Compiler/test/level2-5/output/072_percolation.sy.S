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
.globl array
array:
.space 440

.globl n
n:
.word 0

.globl findfa
.type findfa, %function
findfa:
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
.LBfindfa:
	mov r9, r0
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, #0
	mov32 r7, array
	ldr r8, [r7, r8]
	cmp r8, r9
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_findfa1_ELSE
	b .LBB_findfa1_IF
.LBB_findfa1_IF:
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
.LBB_findfa1_ELSE:
	mov r8, #4
	mov r8, r8
	mul r8, r9, r8
	mov r7, #0
	mov32 r7, array
	ldr r8, [r7, r8]
	mov r0, r8
	bl findfa
	mov r8, r0
	add sp, sp, #0
	mov r7, #4
	mov r7, r7
	mul r7, r9, r7
	mov r6, #0
	mov32 r6, array
	str r8, [r6, r7]
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #0
	mov32 r8, array
	ldr r9, [r8, r9]
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

.globl init
.type init, %function
init:
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
.LBinit:
	mov r9, r0
	mov r8, #1
.LB_init0_LOOP_BEGIN:
	mov r7, r9
	mul r7, r9, r7
	add r7, r7, #1
	cmp r8, r7
	mov r7, #0
	movle r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r7, #0
	sub r7, r7, #1
	mov r6, #4
	mov r6, r6
	mul r6, r8, r6
	mov r5, #0
	mov32 r5, array
	str r7, [r5, r6]
	add r7, r8, #1
	mov r8, r7
	b .LB_init0_LOOP_BEGIN
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
	mov r8, #708
	sub sp, sp, r8
.LBmain:
	str r9, [fp, #-532]
	str r9, [fp, #-700]
	str r9, [fp, #-708]
	mov r8, #1
	str r8, [fp, #-532]
.LB_main3_LOOP_BEGIN:
	mov r8, #0
	ldr r7, [fp, #-532]
	cmp r7, r8
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	ldr r8, [fp, #-532]
	sub r8, r8, #1
	mov r8, r8
	str r8, [fp, #-532]
	mov r8, #0
	mov32 r8, n
	ldr r8, [r8, #0]
	mov r8, #4
	mov r7, #0
	mov32 r7, n
	str r8, [r7, #0]
	mov r8, #10
	str r8, [fp, #-700]
	mov r8, #0
	mov r7, #0
	mov r6, #0
	mov32 r6, n
	ldr r6, [r6, #0]
	mov r0, r6
	bl init
	mov r6, r0
	add sp, sp, #0
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-8]
	ldr r5, [fp, #-8]
	ldr r5, [r5, #0]
	str r5, [fp, #-8]
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-4]
	ldr r5, [fp, #-4]
	ldr r5, [r5, #0]
	str r5, [fp, #-4]
	ldr r5, [fp, #-4]
	mov r5, r5
	str r5, [fp, #-4]
	ldr r5, [fp, #-4]
	ldr r10, [fp, #-8]
	str r10, [fp, #-536]
	ldr r10, [fp, #-536]
	mul r5, r10, r5
	str r5, [fp, #-12]
	ldr r5, [fp, #-12]
	add r5, r5, #1
	str r5, [fp, #-16]
	ldr r5, [fp, #-16]
	mov r6, r5
.LB_4_LOOP_BEGIN:
	ldr r5, [fp, #-700]
	cmp r8, r5
	mov r5, #0
	movlt r5, #1
	str r5, [fp, #-20]
	mov r5, #0
	str r5, [fp, #-24]
	ldr r5, [fp, #-20]
	ldr r10, [fp, #-24]
	str r10, [fp, #-536]
	ldr r10, [fp, #-536]
	cmp r5, r10
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	bl getint
	mov r5, r0
	str r5, [fp, #-28]
	add sp, sp, #0
	ldr r5, [fp, #-28]
	mov r5, r5
	str r5, [fp, #-708]
	bl getint
	mov r5, r0
	str r5, [fp, #-32]
	add sp, sp, #0
	ldr r5, [fp, #-32]
	mov r9, r5
	mov r5, #0
	str r5, [fp, #-36]
	ldr r5, [fp, #-36]
	cmp r5, r7
	mov r5, #0
	moveq r5, #1
	str r5, [fp, #-40]
	mov r5, #0
	str r5, [fp, #-44]
	ldr r5, [fp, #-40]
	ldr r10, [fp, #-44]
	str r10, [fp, #-540]
	ldr r10, [fp, #-540]
	cmp r5, r10
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	str r5, [fp, #-416]
	ldr r5, [fp, #-708]
	sub r5, r5, #1
	str r5, [fp, #-48]
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-52]
	ldr r5, [fp, #-52]
	ldr r5, [r5, #0]
	str r5, [fp, #-52]
	ldr r5, [fp, #-48]
	mov r5, r5
	str r5, [fp, #-56]
	ldr r5, [fp, #-52]
	ldr r10, [fp, #-56]
	str r10, [fp, #-544]
	ldr r10, [fp, #-544]
	mul r5, r5, r10
	str r5, [fp, #-64]
	mov r5, r9
	str r5, [fp, #-60]
	ldr r5, [fp, #-60]
	ldr r10, [fp, #-64]
	str r10, [fp, #-548]
	ldr r10, [fp, #-548]
	add r5, r10, r5
	str r5, [fp, #-68]
	ldr r5, [fp, #-68]
	mov r5, r5
	str r5, [fp, #-416]
	mov r5, #4
	str r5, [fp, #-72]
	ldr r5, [fp, #-72]
	mov r5, r5
	str r5, [fp, #-76]
	ldr r5, [fp, #-76]
	ldr r10, [fp, #-416]
	str r10, [fp, #-552]
	ldr r10, [fp, #-552]
	mul r5, r10, r5
	str r5, [fp, #-84]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-80]
	ldr r5, [fp, #-80]
	ldr r10, [fp, #-84]
	str r10, [fp, #-556]
	ldr r10, [fp, #-416]
	str r10, [fp, #-560]
	ldr r10, [fp, #-556]
	ldr r4, [fp, #-560]
	str r4, [fp, #-704]
	ldr r4, [fp, #-704]
	str r4, [r5, r10]
	mov r5, #1
	str r5, [fp, #-88]
	ldr r5, [fp, #-88]
	ldr r10, [fp, #-708]
	cmp r10, r5
	mov r5, #0
	moveq r5, #1
	str r5, [fp, #-92]
	mov r5, #0
	str r5, [fp, #-96]
	ldr r5, [fp, #-92]
	ldr r10, [fp, #-96]
	str r10, [fp, #-564]
	ldr r10, [fp, #-564]
	cmp r5, r10
	beq .LBB_6_ELSE
	b .LBB_6_IF
.LBB_6_IF:
	mov r5, #0
	str r5, [fp, #-104]
	mov r5, #4
	str r5, [fp, #-100]
	ldr r5, [fp, #-100]
	mov r5, r5
	str r5, [fp, #-108]
	ldr r5, [fp, #-104]
	ldr r10, [fp, #-108]
	str r10, [fp, #-568]
	ldr r10, [fp, #-568]
	mul r5, r5, r10
	str r5, [fp, #-112]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-116]
	mov r5, #0
	str r5, [fp, #-120]
	ldr r5, [fp, #-112]
	ldr r10, [fp, #-116]
	str r10, [fp, #-576]
	ldr r10, [fp, #-120]
	str r10, [fp, #-572]
	ldr r10, [fp, #-572]
	ldr r4, [fp, #-576]
	str r4, [fp, #-704]
	ldr r4, [fp, #-704]
	str r10, [r4, r5]
	mov r1, #0
	ldr r5, [fp, #-416]
	mov r0, r5
	bl mmerge
	mov r5, r0
	str r5, [fp, #-124]
	add sp, sp, #0
.LBB_6_ELSE:
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-128]
	ldr r5, [fp, #-128]
	ldr r5, [r5, #0]
	str r5, [fp, #-128]
	ldr r5, [fp, #-128]
	ldr r10, [fp, #-708]
	cmp r10, r5
	mov r5, #0
	moveq r5, #1
	str r5, [fp, #-132]
	mov r5, #0
	str r5, [fp, #-136]
	ldr r5, [fp, #-132]
	ldr r10, [fp, #-136]
	str r10, [fp, #-580]
	ldr r10, [fp, #-580]
	cmp r5, r10
	beq .LBB_7_ELSE
	b .LBB_7_IF
.LBB_7_IF:
	mov r5, #4
	str r5, [fp, #-140]
	ldr r5, [fp, #-140]
	mov r5, r5
	str r5, [fp, #-144]
	ldr r5, [fp, #-144]
	mul r5, r6, r5
	str r5, [fp, #-148]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-152]
	ldr r5, [fp, #-148]
	ldr r10, [fp, #-152]
	str r10, [fp, #-584]
	ldr r10, [fp, #-584]
	str r6, [r10, r5]
	mov r1, r6
	ldr r5, [fp, #-416]
	mov r0, r5
	bl mmerge
	mov r5, r0
	str r5, [fp, #-156]
	add sp, sp, #0
.LBB_7_ELSE:
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-160]
	ldr r5, [fp, #-160]
	ldr r5, [r5, #0]
	str r5, [fp, #-160]
	ldr r5, [fp, #-160]
	cmp r9, r5
	mov r5, #0
	str r5, [fp, #-200]
	bge .LB_34_COND_END
	ldr r5, [fp, #-416]
	add r5, r5, #1
	str r5, [fp, #-168]
	mov r5, #4
	str r5, [fp, #-164]
	ldr r5, [fp, #-164]
	mov r5, r5
	str r5, [fp, #-172]
	ldr r5, [fp, #-168]
	ldr r10, [fp, #-172]
	str r10, [fp, #-588]
	ldr r10, [fp, #-588]
	mul r5, r5, r10
	str r5, [fp, #-176]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-180]
	ldr r5, [fp, #-176]
	ldr r10, [fp, #-180]
	str r10, [fp, #-592]
	ldr r10, [fp, #-592]
	ldr r5, [r10, r5]
	str r5, [fp, #-188]
	mov r5, #0
	str r5, [fp, #-184]
	ldr r5, [fp, #-184]
	sub r5, r5, #1
	str r5, [fp, #-192]
	ldr r5, [fp, #-188]
	ldr r10, [fp, #-192]
	str r10, [fp, #-596]
	ldr r10, [fp, #-596]
	cmp r5, r10
	mov r5, #0
	movne r5, #1
	str r5, [fp, #-196]
	ldr r5, [fp, #-196]
	mov r5, r5
	str r5, [fp, #-200]
.LB_34_COND_END:
	mov r5, #0
	str r5, [fp, #-204]
	ldr r5, [fp, #-200]
	ldr r10, [fp, #-204]
	str r10, [fp, #-600]
	ldr r10, [fp, #-600]
	cmp r5, r10
	beq .LBB_8_ELSE
	b .LBB_8_IF
.LBB_8_IF:
	ldr r5, [fp, #-416]
	add r5, r5, #1
	str r5, [fp, #-208]
	ldr r5, [fp, #-208]
	mov r1, r5
	ldr r5, [fp, #-416]
	mov r0, r5
	bl mmerge
	mov r5, r0
	str r5, [fp, #-212]
	add sp, sp, #0
.LBB_8_ELSE:
	mov r5, #1
	str r5, [fp, #-216]
	ldr r5, [fp, #-216]
	cmp r9, r5
	mov r5, #0
	str r5, [fp, #-256]
	ble .LB_44_COND_END
	ldr r5, [fp, #-416]
	sub r5, r5, #1
	str r5, [fp, #-224]
	mov r5, #4
	str r5, [fp, #-220]
	ldr r5, [fp, #-220]
	mov r5, r5
	str r5, [fp, #-228]
	ldr r5, [fp, #-224]
	ldr r10, [fp, #-228]
	str r10, [fp, #-604]
	ldr r10, [fp, #-604]
	mul r5, r5, r10
	str r5, [fp, #-232]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-236]
	ldr r5, [fp, #-232]
	ldr r10, [fp, #-236]
	str r10, [fp, #-608]
	ldr r10, [fp, #-608]
	ldr r5, [r10, r5]
	str r5, [fp, #-244]
	mov r5, #0
	str r5, [fp, #-240]
	ldr r5, [fp, #-240]
	sub r5, r5, #1
	str r5, [fp, #-248]
	ldr r5, [fp, #-244]
	ldr r10, [fp, #-248]
	str r10, [fp, #-612]
	ldr r10, [fp, #-612]
	cmp r5, r10
	mov r5, #0
	movne r5, #1
	str r5, [fp, #-252]
	ldr r5, [fp, #-252]
	mov r5, r5
	str r5, [fp, #-256]
.LB_44_COND_END:
	mov r5, #0
	str r5, [fp, #-260]
	ldr r5, [fp, #-256]
	ldr r10, [fp, #-260]
	str r10, [fp, #-616]
	ldr r10, [fp, #-616]
	cmp r5, r10
	beq .LBB_9_ELSE
	b .LBB_9_IF
.LBB_9_IF:
	ldr r5, [fp, #-416]
	sub r5, r5, #1
	str r5, [fp, #-264]
	ldr r5, [fp, #-264]
	mov r1, r5
	ldr r5, [fp, #-416]
	mov r0, r5
	bl mmerge
	mov r5, r0
	str r5, [fp, #-268]
	add sp, sp, #0
.LBB_9_ELSE:
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-272]
	ldr r5, [fp, #-272]
	ldr r5, [r5, #0]
	str r5, [fp, #-272]
	ldr r5, [fp, #-272]
	ldr r10, [fp, #-708]
	cmp r10, r5
	mov r5, #0
	str r5, [fp, #-320]
	bge .LB_54_COND_END
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-276]
	ldr r5, [fp, #-276]
	ldr r5, [r5, #0]
	str r5, [fp, #-276]
	ldr r5, [fp, #-276]
	mov r5, r5
	str r5, [fp, #-280]
	ldr r5, [fp, #-280]
	ldr r10, [fp, #-416]
	str r10, [fp, #-620]
	ldr r10, [fp, #-620]
	add r5, r10, r5
	str r5, [fp, #-288]
	mov r5, #4
	str r5, [fp, #-284]
	ldr r5, [fp, #-284]
	mov r5, r5
	str r5, [fp, #-292]
	ldr r5, [fp, #-288]
	ldr r10, [fp, #-292]
	str r10, [fp, #-624]
	ldr r10, [fp, #-624]
	mul r5, r5, r10
	str r5, [fp, #-296]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-300]
	ldr r5, [fp, #-296]
	ldr r10, [fp, #-300]
	str r10, [fp, #-628]
	ldr r10, [fp, #-628]
	ldr r5, [r10, r5]
	str r5, [fp, #-308]
	mov r5, #0
	str r5, [fp, #-304]
	ldr r5, [fp, #-304]
	sub r5, r5, #1
	str r5, [fp, #-312]
	ldr r5, [fp, #-308]
	ldr r10, [fp, #-312]
	str r10, [fp, #-632]
	ldr r10, [fp, #-632]
	cmp r5, r10
	mov r5, #0
	movne r5, #1
	str r5, [fp, #-316]
	ldr r5, [fp, #-316]
	mov r5, r5
	str r5, [fp, #-320]
.LB_54_COND_END:
	mov r5, #0
	str r5, [fp, #-324]
	ldr r5, [fp, #-320]
	ldr r10, [fp, #-324]
	str r10, [fp, #-636]
	ldr r10, [fp, #-636]
	cmp r5, r10
	beq .LBB_10_ELSE
	b .LBB_10_IF
.LBB_10_IF:
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-328]
	ldr r5, [fp, #-328]
	ldr r5, [r5, #0]
	str r5, [fp, #-328]
	ldr r5, [fp, #-328]
	mov r5, r5
	str r5, [fp, #-332]
	ldr r5, [fp, #-332]
	ldr r10, [fp, #-416]
	str r10, [fp, #-640]
	ldr r10, [fp, #-640]
	add r5, r10, r5
	str r5, [fp, #-336]
	ldr r5, [fp, #-336]
	mov r1, r5
	ldr r5, [fp, #-416]
	mov r0, r5
	bl mmerge
	mov r5, r0
	str r5, [fp, #-340]
	add sp, sp, #0
.LBB_10_ELSE:
	mov r5, #1
	str r5, [fp, #-344]
	ldr r5, [fp, #-344]
	ldr r10, [fp, #-708]
	cmp r10, r5
	mov r5, #0
	str r5, [fp, #-392]
	ble .LB_64_COND_END
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-348]
	ldr r5, [fp, #-348]
	ldr r5, [r5, #0]
	str r5, [fp, #-348]
	ldr r5, [fp, #-348]
	mov r5, r5
	str r5, [fp, #-352]
	ldr r5, [fp, #-352]
	ldr r10, [fp, #-416]
	str r10, [fp, #-644]
	ldr r10, [fp, #-644]
	sub r5, r10, r5
	str r5, [fp, #-360]
	mov r5, #4
	str r5, [fp, #-356]
	ldr r5, [fp, #-356]
	mov r5, r5
	str r5, [fp, #-364]
	ldr r5, [fp, #-360]
	ldr r10, [fp, #-364]
	str r10, [fp, #-648]
	ldr r10, [fp, #-648]
	mul r5, r5, r10
	str r5, [fp, #-368]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-372]
	ldr r5, [fp, #-368]
	ldr r10, [fp, #-372]
	str r10, [fp, #-652]
	ldr r10, [fp, #-652]
	ldr r5, [r10, r5]
	str r5, [fp, #-380]
	mov r5, #0
	str r5, [fp, #-376]
	ldr r5, [fp, #-376]
	sub r5, r5, #1
	str r5, [fp, #-384]
	ldr r5, [fp, #-380]
	ldr r10, [fp, #-384]
	str r10, [fp, #-656]
	ldr r10, [fp, #-656]
	cmp r5, r10
	mov r5, #0
	movne r5, #1
	str r5, [fp, #-388]
	ldr r5, [fp, #-388]
	mov r5, r5
	str r5, [fp, #-392]
.LB_64_COND_END:
	mov r5, #0
	str r5, [fp, #-396]
	ldr r5, [fp, #-392]
	ldr r10, [fp, #-396]
	str r10, [fp, #-660]
	ldr r10, [fp, #-660]
	cmp r5, r10
	beq .LBB_11_ELSE
	b .LBB_11_IF
.LBB_11_IF:
	mov r5, #0
	mov32 r5, n
	str r5, [fp, #-400]
	ldr r5, [fp, #-400]
	ldr r5, [r5, #0]
	str r5, [fp, #-400]
	ldr r5, [fp, #-400]
	mov r5, r5
	str r5, [fp, #-404]
	ldr r5, [fp, #-404]
	ldr r10, [fp, #-416]
	str r10, [fp, #-664]
	ldr r10, [fp, #-664]
	sub r5, r10, r5
	str r5, [fp, #-408]
	ldr r5, [fp, #-408]
	mov r1, r5
	ldr r5, [fp, #-416]
	mov r0, r5
	bl mmerge
	mov r5, r0
	str r5, [fp, #-412]
	add sp, sp, #0
.LBB_11_ELSE:
	mov r5, #0
	str r5, [fp, #-424]
	mov r5, #4
	str r5, [fp, #-420]
	ldr r5, [fp, #-420]
	mov r5, r5
	str r5, [fp, #-428]
	ldr r5, [fp, #-424]
	ldr r10, [fp, #-428]
	str r10, [fp, #-668]
	ldr r10, [fp, #-668]
	mul r5, r5, r10
	str r5, [fp, #-432]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-436]
	ldr r5, [fp, #-432]
	ldr r10, [fp, #-436]
	str r10, [fp, #-672]
	ldr r10, [fp, #-672]
	ldr r5, [r10, r5]
	str r5, [fp, #-444]
	mov r5, #0
	str r5, [fp, #-440]
	ldr r5, [fp, #-440]
	sub r5, r5, #1
	str r5, [fp, #-448]
	ldr r5, [fp, #-444]
	ldr r10, [fp, #-448]
	str r10, [fp, #-676]
	ldr r10, [fp, #-676]
	cmp r5, r10
	mov r5, #0
	str r5, [fp, #-484]
	beq .LB_76_COND_END
	mov r5, #4
	str r5, [fp, #-452]
	ldr r5, [fp, #-452]
	mov r5, r5
	str r5, [fp, #-456]
	ldr r5, [fp, #-456]
	mul r5, r6, r5
	str r5, [fp, #-460]
	mov r5, #0
	mov32 r5, array
	str r5, [fp, #-464]
	ldr r5, [fp, #-460]
	ldr r10, [fp, #-464]
	str r10, [fp, #-680]
	ldr r10, [fp, #-680]
	ldr r5, [r10, r5]
	str r5, [fp, #-472]
	mov r5, #0
	str r5, [fp, #-468]
	ldr r5, [fp, #-468]
	sub r5, r5, #1
	str r5, [fp, #-476]
	ldr r5, [fp, #-472]
	ldr r10, [fp, #-476]
	str r10, [fp, #-684]
	ldr r10, [fp, #-684]
	cmp r5, r10
	mov r5, #0
	movne r5, #1
	str r5, [fp, #-480]
	ldr r5, [fp, #-480]
	mov r5, r5
	str r5, [fp, #-484]
.LB_76_COND_END:
	mov r5, #0
	str r5, [fp, #-488]
	ldr r5, [fp, #-484]
	ldr r10, [fp, #-488]
	str r10, [fp, #-688]
	ldr r10, [fp, #-688]
	cmp r5, r10
	mov r5, #0
	str r5, [fp, #-508]
	beq .LB_74_COND_END
	mov r0, #0
	bl findfa
	mov r5, r0
	str r5, [fp, #-492]
	add sp, sp, #0
	mov r0, r6
	bl findfa
	mov r5, r0
	str r5, [fp, #-496]
	add sp, sp, #0
	ldr r5, [fp, #-492]
	ldr r10, [fp, #-496]
	str r10, [fp, #-692]
	ldr r10, [fp, #-692]
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	str r5, [fp, #-500]
	ldr r5, [fp, #-500]
	mov r5, r5
	str r5, [fp, #-508]
.LB_74_COND_END:
	mov r5, #0
	str r5, [fp, #-504]
	ldr r5, [fp, #-504]
	ldr r10, [fp, #-508]
	str r10, [fp, #-696]
	ldr r10, [fp, #-696]
	cmp r10, r5
	beq .LBB_12_ELSE
	b .LBB_12_IF
.LBB_12_IF:
	mov r7, #1
	str r5, [fp, #-516]
	add r5, r8, #1
	str r5, [fp, #-512]
	ldr r5, [fp, #-512]
	mov r5, r5
	str r5, [fp, #-516]
	ldr r5, [fp, #-516]
	mov r0, r5
	bl putint
	mov r5, r0
	str r5, [fp, #-520]
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r5, r0
	str r5, [fp, #-524]
	add sp, sp, #0
.LBB_12_ELSE:
.LBB_5_ELSE:
	add r5, r8, #1
	str r5, [fp, #-528]
	ldr r5, [fp, #-528]
	mov r8, r5
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	mov r8, #0
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_13_ELSE
	b .LBB_13_IF
.LBB_13_IF:
	mov r8, #0
	sub r8, r8, #1
	mov r0, r8
	bl putint
	mov r8, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r8, r0
	add sp, sp, #0
.LBB_13_ELSE:
	b .LB_main3_LOOP_BEGIN
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

.globl mmerge
.type mmerge, %function
mmerge:
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
.LBmmerge:
	mov r9, r0
	mov r8, r1
	mov r0, r9
	bl findfa
	mov r9, r0
	add sp, sp, #0
	mov r7, r9
	mov r0, r8
	bl findfa
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
	cmp r7, r9
	mov r8, #0
	movne r8, #1
	mov r6, #0
	cmp r8, r6
	beq .LBB_mmerge2_ELSE
	b .LBB_mmerge2_IF
.LBB_mmerge2_IF:
	mov r8, #4
	mov r8, r8
	mul r8, r7, r8
	mov r6, #0
	mov32 r6, array
	str r9, [r6, r8]
.LBB_mmerge2_ELSE:
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