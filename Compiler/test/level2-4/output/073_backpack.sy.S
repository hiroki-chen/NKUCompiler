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
.globl V
V:
.space 160000

.globl KnapSack
.type KnapSack, %function
KnapSack:
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
	mov r8, #792
	sub sp, sp, r8
.LBKnapSack:
	mov r9, r0
	str r9, [fp, #-580]
	mov r9, r1
	str r9, [fp, #-772]
	mov r9, r2
	str r9, [fp, #-792]
	mov r9, r3
	add r8, fp, #36
	ldr r8, [r8]
	mov r7, #1
.LB_KnapSack0_LOOP_BEGIN:
	ldr r5, [fp, #-580]
	cmp r7, r5
	mov r5, #0
	movle r5, #1
	str r5, [fp, #-4]
	mov r5, #0
	str r5, [fp, #-8]
	ldr r5, [fp, #-4]
	ldr r10, [fp, #-8]
	str r10, [fp, #-584]
	ldr r10, [fp, #-584]
	cmp r5, r10
	beq .LB0_LOOP_END
	b .LB0_LOOP_BODY
.LB0_LOOP_BODY:
	mov r6, #0
.LB_1_LOOP_BEGIN:
	add r5, r8, #1
	str r5, [fp, #-4]
	ldr r5, [fp, #-4]
	cmp r6, r5
	mov r5, #0
	movlt r5, #1
	str r5, [fp, #-12]
	mov r5, #0
	str r5, [fp, #-8]
	ldr r5, [fp, #-8]
	ldr r10, [fp, #-12]
	str r10, [fp, #-584]
	ldr r10, [fp, #-584]
	cmp r10, r5
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r5, #4
	str r5, [fp, #-16]
	ldr r5, [fp, #-16]
	mov r5, r5
	str r5, [fp, #-20]
	ldr r5, [fp, #-20]
	mul r5, r7, r5
	str r5, [fp, #-28]
	ldr r5, [fp, #-772]
	mov r5, r5
	str r5, [fp, #-24]
	ldr r5, [fp, #-24]
	ldr r10, [fp, #-28]
	str r10, [fp, #-588]
	ldr r10, [fp, #-588]
	ldr r5, [r5, r10]
	str r5, [fp, #-32]
	ldr r5, [fp, #-32]
	cmp r6, r5
	mov r5, #0
	movlt r5, #1
	str r5, [fp, #-40]
	mov r5, #0
	str r5, [fp, #-36]
	ldr r5, [fp, #-36]
	ldr r10, [fp, #-40]
	str r10, [fp, #-592]
	ldr r10, [fp, #-592]
	cmp r10, r5
	beq .LBB_2_ELSE
	b .LBB_2_IF
.LBB_2_IF:
	mov r5, #4
	str r5, [fp, #-44]
	ldr r5, [fp, #-44]
	mov r5, r5
	str r5, [fp, #-48]
	ldr r5, [fp, #-48]
	mul r5, r6, r5
	str r5, [fp, #-68]
	mov r5, #800
	str r5, [fp, #-56]
	sub r5, r7, #1
	str r5, [fp, #-52]
	ldr r5, [fp, #-52]
	mov r5, r5
	str r5, [fp, #-60]
	ldr r5, [fp, #-56]
	ldr r10, [fp, #-60]
	str r10, [fp, #-596]
	ldr r10, [fp, #-596]
	mul r5, r5, r10
	str r5, [fp, #-64]
	ldr r5, [fp, #-64]
	mov r5, r5
	str r5, [fp, #-72]
	ldr r5, [fp, #-68]
	ldr r10, [fp, #-72]
	str r10, [fp, #-600]
	ldr r10, [fp, #-600]
	add r5, r5, r10
	str r5, [fp, #-76]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-80]
	ldr r5, [fp, #-76]
	ldr r10, [fp, #-80]
	str r10, [fp, #-604]
	ldr r10, [fp, #-604]
	ldr r5, [r10, r5]
	str r5, [fp, #-120]
	mov r5, #4
	str r5, [fp, #-84]
	ldr r5, [fp, #-84]
	mov r5, r5
	str r5, [fp, #-88]
	ldr r5, [fp, #-88]
	mul r5, r6, r5
	str r5, [fp, #-104]
	mov r5, #800
	str r5, [fp, #-92]
	mov r5, r7
	str r5, [fp, #-96]
	ldr r5, [fp, #-92]
	ldr r10, [fp, #-96]
	str r10, [fp, #-608]
	ldr r10, [fp, #-608]
	mul r5, r5, r10
	str r5, [fp, #-100]
	ldr r5, [fp, #-100]
	mov r5, r5
	str r5, [fp, #-108]
	ldr r5, [fp, #-104]
	ldr r10, [fp, #-108]
	str r10, [fp, #-612]
	ldr r10, [fp, #-612]
	add r5, r5, r10
	str r5, [fp, #-112]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-116]
	ldr r5, [fp, #-112]
	ldr r10, [fp, #-116]
	str r10, [fp, #-620]
	ldr r10, [fp, #-120]
	str r10, [fp, #-616]
	ldr r10, [fp, #-616]
	ldr r4, [fp, #-620]
	str r4, [fp, #-776]
	ldr r4, [fp, #-776]
	str r10, [r4, r5]
	b .LBB_2_END_IF
.LBB_2_ELSE:
	str r5, [fp, #-312]
	mov r5, #4
	str r5, [fp, #-124]
	ldr r5, [fp, #-124]
	mov r5, r5
	str r5, [fp, #-128]
	ldr r5, [fp, #-128]
	mul r5, r6, r5
	str r5, [fp, #-152]
	mov r5, #800
	str r5, [fp, #-136]
	sub r5, r7, #1
	str r5, [fp, #-132]
	ldr r5, [fp, #-132]
	mov r5, r5
	str r5, [fp, #-140]
	ldr r5, [fp, #-136]
	ldr r10, [fp, #-140]
	str r10, [fp, #-624]
	ldr r10, [fp, #-624]
	mul r5, r5, r10
	str r5, [fp, #-144]
	ldr r5, [fp, #-144]
	mov r5, r5
	str r5, [fp, #-148]
	ldr r5, [fp, #-148]
	ldr r10, [fp, #-152]
	str r10, [fp, #-628]
	ldr r10, [fp, #-628]
	add r5, r10, r5
	str r5, [fp, #-156]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-160]
	ldr r5, [fp, #-156]
	ldr r10, [fp, #-160]
	str r10, [fp, #-632]
	ldr r10, [fp, #-632]
	ldr r5, [r10, r5]
	str r5, [fp, #-164]
	ldr r5, [fp, #-164]
	mov r5, r5
	str r5, [fp, #-312]
	str r5, [fp, #-344]
	mov r5, #4
	str r5, [fp, #-168]
	ldr r5, [fp, #-168]
	mov r5, r5
	str r5, [fp, #-172]
	ldr r5, [fp, #-172]
	mul r5, r7, r5
	str r5, [fp, #-176]
	ldr r5, [fp, #-772]
	mov r5, r5
	str r5, [fp, #-180]
	ldr r5, [fp, #-176]
	ldr r10, [fp, #-180]
	str r10, [fp, #-636]
	ldr r10, [fp, #-636]
	ldr r5, [r10, r5]
	str r5, [fp, #-184]
	ldr r5, [fp, #-184]
	mov r5, r5
	str r5, [fp, #-188]
	ldr r5, [fp, #-188]
	sub r5, r6, r5
	str r5, [fp, #-196]
	mov r5, #4
	str r5, [fp, #-192]
	ldr r5, [fp, #-192]
	mov r5, r5
	str r5, [fp, #-200]
	ldr r5, [fp, #-196]
	ldr r10, [fp, #-200]
	str r10, [fp, #-640]
	ldr r10, [fp, #-640]
	mul r5, r5, r10
	str r5, [fp, #-224]
	mov r5, #800
	str r5, [fp, #-208]
	sub r5, r7, #1
	str r5, [fp, #-204]
	ldr r5, [fp, #-204]
	mov r5, r5
	str r5, [fp, #-212]
	ldr r5, [fp, #-208]
	ldr r10, [fp, #-212]
	str r10, [fp, #-644]
	ldr r10, [fp, #-644]
	mul r5, r5, r10
	str r5, [fp, #-216]
	ldr r5, [fp, #-216]
	mov r5, r5
	str r5, [fp, #-220]
	ldr r5, [fp, #-220]
	ldr r10, [fp, #-224]
	str r10, [fp, #-648]
	ldr r10, [fp, #-648]
	add r5, r10, r5
	str r5, [fp, #-228]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-232]
	ldr r5, [fp, #-228]
	ldr r10, [fp, #-232]
	str r10, [fp, #-652]
	ldr r10, [fp, #-652]
	ldr r5, [r10, r5]
	str r5, [fp, #-260]
	mov r5, #4
	str r5, [fp, #-236]
	ldr r5, [fp, #-236]
	mov r5, r5
	str r5, [fp, #-240]
	ldr r5, [fp, #-240]
	mul r5, r7, r5
	str r5, [fp, #-244]
	ldr r5, [fp, #-792]
	mov r5, r5
	str r5, [fp, #-248]
	ldr r5, [fp, #-244]
	ldr r10, [fp, #-248]
	str r10, [fp, #-656]
	ldr r10, [fp, #-656]
	ldr r5, [r10, r5]
	str r5, [fp, #-252]
	ldr r5, [fp, #-252]
	mov r5, r5
	str r5, [fp, #-256]
	ldr r5, [fp, #-256]
	ldr r10, [fp, #-260]
	str r10, [fp, #-660]
	ldr r10, [fp, #-660]
	add r5, r10, r5
	str r5, [fp, #-264]
	ldr r5, [fp, #-264]
	mov r5, r5
	str r5, [fp, #-344]
	ldr r5, [fp, #-312]
	ldr r10, [fp, #-344]
	str r10, [fp, #-664]
	ldr r10, [fp, #-664]
	cmp r5, r10
	mov r5, #0
	movgt r5, #1
	str r5, [fp, #-268]
	mov r5, #0
	str r5, [fp, #-272]
	ldr r5, [fp, #-268]
	ldr r10, [fp, #-272]
	str r10, [fp, #-668]
	ldr r10, [fp, #-668]
	cmp r5, r10
	beq .LBB_3_ELSE
	b .LBB_3_IF
.LBB_3_IF:
	mov r5, #4
	str r5, [fp, #-276]
	ldr r5, [fp, #-276]
	mov r5, r5
	str r5, [fp, #-280]
	ldr r5, [fp, #-280]
	mul r5, r6, r5
	str r5, [fp, #-300]
	mov r5, #800
	str r5, [fp, #-284]
	mov r5, r7
	str r5, [fp, #-288]
	ldr r5, [fp, #-284]
	ldr r10, [fp, #-288]
	str r10, [fp, #-672]
	ldr r10, [fp, #-672]
	mul r5, r5, r10
	str r5, [fp, #-292]
	ldr r5, [fp, #-292]
	mov r5, r5
	str r5, [fp, #-296]
	ldr r5, [fp, #-296]
	ldr r10, [fp, #-300]
	str r10, [fp, #-676]
	ldr r10, [fp, #-676]
	add r5, r10, r5
	str r5, [fp, #-304]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-308]
	ldr r5, [fp, #-304]
	ldr r10, [fp, #-308]
	str r10, [fp, #-684]
	ldr r10, [fp, #-312]
	str r10, [fp, #-680]
	ldr r10, [fp, #-680]
	ldr r4, [fp, #-684]
	str r4, [fp, #-776]
	ldr r4, [fp, #-776]
	str r10, [r4, r5]
	b .LBB_3_END_IF
.LBB_3_ELSE:
	mov r5, #4
	str r5, [fp, #-316]
	ldr r5, [fp, #-316]
	mov r5, r5
	str r5, [fp, #-320]
	ldr r5, [fp, #-320]
	mul r5, r6, r5
	str r5, [fp, #-340]
	mov r5, #800
	str r5, [fp, #-324]
	mov r5, r7
	str r5, [fp, #-328]
	ldr r5, [fp, #-324]
	ldr r10, [fp, #-328]
	str r10, [fp, #-688]
	ldr r10, [fp, #-688]
	mul r5, r5, r10
	str r5, [fp, #-332]
	ldr r5, [fp, #-332]
	mov r5, r5
	str r5, [fp, #-336]
	ldr r5, [fp, #-336]
	ldr r10, [fp, #-340]
	str r10, [fp, #-692]
	ldr r10, [fp, #-692]
	add r5, r10, r5
	str r5, [fp, #-348]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-352]
	ldr r5, [fp, #-344]
	ldr r10, [fp, #-348]
	str r10, [fp, #-696]
	ldr r10, [fp, #-352]
	str r10, [fp, #-700]
	ldr r10, [fp, #-696]
	ldr r4, [fp, #-700]
	str r4, [fp, #-780]
	ldr r4, [fp, #-780]
	str r5, [r4, r10]
	b .LBB_3_END_IF
.LBB_3_END_IF:
	b .LBB_2_END_IF
.LBB_2_END_IF:
	add r5, r6, #1
	str r5, [fp, #-356]
	ldr r5, [fp, #-356]
	mov r6, r5
	b .LB_1_LOOP_BEGIN
.LB1_LOOP_END:
	add r5, r7, #1
	str r5, [fp, #-360]
	ldr r5, [fp, #-360]
	mov r7, r5
	b .LB_KnapSack0_LOOP_BEGIN
.LB0_LOOP_END:
	mov r6, r8
	ldr r5, [fp, #-580]
	mov r7, r5
.LB_4_LOOP_BEGIN:
	mov r5, #1
	str r5, [fp, #-364]
	ldr r5, [fp, #-364]
	cmp r7, r5
	mov r5, #0
	movge r5, #1
	str r5, [fp, #-368]
	mov r5, #0
	str r5, [fp, #-372]
	ldr r5, [fp, #-368]
	ldr r10, [fp, #-372]
	str r10, [fp, #-704]
	ldr r10, [fp, #-704]
	cmp r5, r10
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r5, #4
	str r5, [fp, #-376]
	ldr r5, [fp, #-376]
	mov r5, r5
	str r5, [fp, #-380]
	ldr r5, [fp, #-380]
	mul r5, r6, r5
	str r5, [fp, #-396]
	mov r5, #800
	str r5, [fp, #-384]
	mov r5, r7
	str r5, [fp, #-388]
	ldr r5, [fp, #-384]
	ldr r10, [fp, #-388]
	str r10, [fp, #-708]
	ldr r10, [fp, #-708]
	mul r5, r5, r10
	str r5, [fp, #-392]
	ldr r5, [fp, #-392]
	mov r5, r5
	str r5, [fp, #-400]
	ldr r5, [fp, #-396]
	ldr r10, [fp, #-400]
	str r10, [fp, #-712]
	ldr r10, [fp, #-712]
	add r5, r5, r10
	str r5, [fp, #-404]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-408]
	ldr r5, [fp, #-404]
	ldr r10, [fp, #-408]
	str r10, [fp, #-716]
	ldr r10, [fp, #-716]
	ldr r5, [r10, r5]
	str r5, [fp, #-452]
	mov r5, #4
	str r5, [fp, #-412]
	ldr r5, [fp, #-412]
	mov r5, r5
	str r5, [fp, #-416]
	ldr r5, [fp, #-416]
	mul r5, r6, r5
	str r5, [fp, #-436]
	mov r5, #800
	str r5, [fp, #-424]
	sub r5, r7, #1
	str r5, [fp, #-420]
	ldr r5, [fp, #-420]
	mov r5, r5
	str r5, [fp, #-428]
	ldr r5, [fp, #-424]
	ldr r10, [fp, #-428]
	str r10, [fp, #-720]
	ldr r10, [fp, #-720]
	mul r5, r5, r10
	str r5, [fp, #-432]
	ldr r5, [fp, #-432]
	mov r5, r5
	str r5, [fp, #-440]
	ldr r5, [fp, #-436]
	ldr r10, [fp, #-440]
	str r10, [fp, #-724]
	ldr r10, [fp, #-724]
	add r5, r5, r10
	str r5, [fp, #-444]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-448]
	ldr r5, [fp, #-444]
	ldr r10, [fp, #-448]
	str r10, [fp, #-728]
	ldr r10, [fp, #-728]
	ldr r5, [r10, r5]
	str r5, [fp, #-456]
	ldr r5, [fp, #-452]
	ldr r10, [fp, #-456]
	str r10, [fp, #-732]
	ldr r10, [fp, #-732]
	cmp r5, r10
	mov r5, #0
	movgt r5, #1
	str r5, [fp, #-460]
	mov r5, #0
	str r5, [fp, #-464]
	ldr r5, [fp, #-460]
	ldr r10, [fp, #-464]
	str r10, [fp, #-736]
	ldr r10, [fp, #-736]
	cmp r5, r10
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	mov r5, #4
	str r5, [fp, #-468]
	ldr r5, [fp, #-468]
	mov r5, r5
	str r5, [fp, #-472]
	ldr r5, [fp, #-472]
	mul r5, r7, r5
	str r5, [fp, #-476]
	mov r5, r9
	str r5, [fp, #-480]
	mov r5, #1
	str r5, [fp, #-484]
	ldr r5, [fp, #-476]
	ldr r10, [fp, #-480]
	str r10, [fp, #-740]
	ldr r10, [fp, #-484]
	str r10, [fp, #-744]
	ldr r10, [fp, #-740]
	ldr r4, [fp, #-744]
	str r4, [fp, #-784]
	ldr r4, [fp, #-784]
	str r4, [r10, r5]
	mov r5, #4
	str r5, [fp, #-488]
	ldr r5, [fp, #-488]
	mov r5, r5
	str r5, [fp, #-492]
	ldr r5, [fp, #-492]
	mul r5, r7, r5
	str r5, [fp, #-496]
	ldr r5, [fp, #-772]
	mov r5, r5
	str r5, [fp, #-500]
	ldr r5, [fp, #-496]
	ldr r10, [fp, #-500]
	str r10, [fp, #-748]
	ldr r10, [fp, #-748]
	ldr r5, [r10, r5]
	str r5, [fp, #-504]
	ldr r5, [fp, #-504]
	mov r5, r5
	str r5, [fp, #-508]
	ldr r5, [fp, #-508]
	sub r5, r6, r5
	str r5, [fp, #-512]
	ldr r5, [fp, #-512]
	mov r6, r5
	b .LBB_5_END_IF
.LBB_5_ELSE:
	mov r5, #4
	str r5, [fp, #-516]
	ldr r5, [fp, #-516]
	mov r5, r5
	str r5, [fp, #-520]
	ldr r5, [fp, #-520]
	mul r5, r7, r5
	str r5, [fp, #-524]
	mov r5, r9
	str r5, [fp, #-528]
	mov r5, #0
	str r5, [fp, #-532]
	ldr r5, [fp, #-524]
	ldr r10, [fp, #-528]
	str r10, [fp, #-752]
	ldr r10, [fp, #-532]
	str r10, [fp, #-756]
	ldr r10, [fp, #-752]
	ldr r4, [fp, #-756]
	str r4, [fp, #-788]
	ldr r4, [fp, #-788]
	str r4, [r10, r5]
	b .LBB_5_END_IF
.LBB_5_END_IF:
	sub r5, r7, #1
	str r5, [fp, #-536]
	ldr r5, [fp, #-536]
	mov r7, r5
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	mov r5, #4
	str r5, [fp, #-540]
	ldr r5, [fp, #-540]
	mov r5, r5
	str r5, [fp, #-544]
	ldr r5, [fp, #-544]
	mul r5, r8, r5
	str r5, [fp, #-560]
	mov r5, #800
	str r5, [fp, #-548]
	ldr r5, [fp, #-580]
	mov r5, r5
	str r5, [fp, #-552]
	ldr r5, [fp, #-548]
	ldr r10, [fp, #-552]
	str r10, [fp, #-760]
	ldr r10, [fp, #-760]
	mul r5, r5, r10
	str r5, [fp, #-556]
	ldr r5, [fp, #-556]
	mov r5, r5
	str r5, [fp, #-564]
	ldr r5, [fp, #-560]
	ldr r10, [fp, #-564]
	str r10, [fp, #-764]
	ldr r10, [fp, #-764]
	add r5, r5, r10
	str r5, [fp, #-568]
	mov r5, #0
	mov32 r5, V
	str r5, [fp, #-572]
	ldr r5, [fp, #-568]
	ldr r10, [fp, #-572]
	str r10, [fp, #-768]
	ldr r10, [fp, #-768]
	ldr r5, [r10, r5]
	str r5, [fp, #-576]
	ldr r5, [fp, #-576]
	mov r0, r5
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
	sub sp, sp, #24
	mov r8, sp
	add r8, r8, #0
	mov r0, r8
	mov r1, #0
	mov r2, #24
	bl memset
	mov r8, sp
	add r8, r8, #0
	mov r7, #0
	str r7, [r8, #0]
	mov r8, sp
	add r8, r8, #0
	mov r7, #2
	str r7, [r8, #4]
	mov r8, sp
	add r8, r8, #0
	mov r7, #2
	str r7, [r8, #8]
	mov r8, sp
	add r8, r8, #0
	mov r7, #6
	str r7, [r8, #12]
	mov r8, sp
	add r8, r8, #0
	mov r7, #5
	str r7, [r8, #16]
	mov r8, sp
	add r8, r8, #0
	mov r7, #4
	str r7, [r8, #20]
	sub sp, sp, #24
	mov r8, sp
	add r8, r8, #0
	mov r0, r8
	mov r1, #0
	mov r2, #24
	bl memset
	mov r8, sp
	add r8, r8, #0
	mov r7, #0
	str r7, [r8, #0]
	mov r8, sp
	add r8, r8, #0
	mov r7, #6
	str r7, [r8, #4]
	mov r8, sp
	add r8, r8, #0
	mov r7, #3
	str r7, [r8, #8]
	mov r8, sp
	add r8, r8, #0
	mov r7, #5
	str r7, [r8, #12]
	mov r8, sp
	add r8, r8, #0
	mov r7, #4
	str r7, [r8, #16]
	mov r8, sp
	add r8, r8, #0
	mov r7, #6
	str r7, [r8, #20]
	sub sp, sp, #24
	mov r8, #5
	mov r7, #10
	add r6, sp, #0
	mov r3, r6
	add r6, sp, #24
	mov r2, r6
	add r6, sp, #48
	mov r1, r6
	mov r0, r8
	push {r7}
	bl KnapSack
	mov r8, r0
	add sp, sp, #4
	mov r9, r8
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007222"