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
.globl a1
a1:
.word 1

.globl a2
a2:
.word 2

.globl a3
a3:
.word 3

.globl a4
a4:
.word 4

.globl a5
a5:
.word 5

.globl a6
a6:
.word 6

.globl a7
a7:
.word 7

.globl a8
a8:
.word 8

.globl a9
a9:
.word 9

.globl a10
a10:
.word 10

.globl a11
a11:
.word 11

.globl a12
a12:
.word 12

.globl a13
a13:
.word 13

.globl a14
a14:
.word 14

.globl a15
a15:
.word 15

.globl a16
a16:
.word 16

.globl a17
a17:
.word 1

.globl a18
a18:
.word 2

.globl a19
a19:
.word 3

.globl a20
a20:
.word 4

.globl a21
a21:
.word 5

.globl a22
a22:
.word 6

.globl a23
a23:
.word 7

.globl a24
a24:
.word 8

.globl a25
a25:
.word 9

.globl a26
a26:
.word 10

.globl a27
a27:
.word 11

.globl a28
a28:
.word 12

.globl a29
a29:
.word 13

.globl a30
a30:
.word 14

.globl a31
a31:
.word 15

.globl a32
a32:
.word 16

.globl func
.type func, %function
func:
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
	mov r8, #2244
	sub sp, sp, r8
.LBfunc:
	mov r9, r0
	mov r8, r1
	str r7, [fp, #-1628]
	mov r7, r8
	add r7, r9, r7
	str r7, [fp, #-1628]
	str r10, [fp, #-2244]
	str r10, [fp, #-1324]
	str r10, [fp, #-1352]
	str r10, [fp, #-1380]
	str r10, [fp, #-1408]
	str r10, [fp, #-1212]
	str r10, [fp, #-1240]
	str r10, [fp, #-1268]
	str r10, [fp, #-1296]
	str r10, [fp, #-1100]
	str r10, [fp, #-1128]
	str r10, [fp, #-1156]
	str r10, [fp, #-1184]
	str r10, [fp, #-988]
	str r10, [fp, #-1016]
	str r10, [fp, #-1044]
	str r10, [fp, #-1072]
	str r10, [fp, #-876]
	str r10, [fp, #-904]
	str r10, [fp, #-932]
	str r10, [fp, #-960]
	str r10, [fp, #-800]
	str r10, [fp, #-804]
	str r10, [fp, #-820]
	str r10, [fp, #-848]
	str r10, [fp, #-784]
	str r10, [fp, #-788]
	str r10, [fp, #-792]
	str r10, [fp, #-796]
	str r10, [fp, #-1736]
	str r10, [fp, #-1740]
	str r10, [fp, #-1744]
	str r10, [fp, #-1748]
	bl getint
	mov r10, r0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mov r7, r10
	bl getint
	mov r10, r0
	str r10, [fp, #-4]
	ldr r10, [fp, #-4]
	mov r6, r10
	bl getint
	mov r10, r0
	str r10, [fp, #-8]
	ldr r10, [fp, #-8]
	mov r5, r10
	bl getint
	mov r10, r0
	str r10, [fp, #-12]
	ldr r10, [fp, #-12]
	str r10, [fp, #-2244]
	mov r10, #1
	str r10, [fp, #-16]
	mov r10, r7
	str r10, [fp, #-20]
	ldr r10, [fp, #-16]
	ldr r4, [fp, #-20]
	str r4, [fp, #-1752]
	ldr r4, [fp, #-1752]
	add r10, r10, r4
	str r10, [fp, #-28]
	mov r10, #0
	mov32 r10, a1
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	ldr r10, [r10, #0]
	str r10, [fp, #-24]
	ldr r10, [fp, #-24]
	str r10, [fp, #-32]
	ldr r10, [fp, #-28]
	ldr r4, [fp, #-32]
	str r4, [fp, #-1752]
	ldr r4, [fp, #-1752]
	add r10, r10, r4
	str r10, [fp, #-36]
	ldr r10, [fp, #-36]
	str r10, [fp, #-1324]
	mov r10, #2
	str r10, [fp, #-44]
	mov r10, r6
	str r10, [fp, #-40]
	ldr r10, [fp, #-40]
	ldr r4, [fp, #-44]
	str r4, [fp, #-1756]
	ldr r4, [fp, #-1756]
	add r10, r4, r10
	str r10, [fp, #-56]
	mov r10, #0
	mov32 r10, a2
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	ldr r10, [r10, #0]
	str r10, [fp, #-48]
	ldr r10, [fp, #-48]
	str r10, [fp, #-52]
	ldr r10, [fp, #-52]
	ldr r4, [fp, #-56]
	str r4, [fp, #-1760]
	ldr r4, [fp, #-1760]
	add r10, r4, r10
	str r10, [fp, #-60]
	ldr r10, [fp, #-60]
	str r10, [fp, #-1352]
	mov r10, #3
	str r10, [fp, #-68]
	mov r10, r5
	str r10, [fp, #-64]
	ldr r10, [fp, #-64]
	ldr r4, [fp, #-68]
	str r4, [fp, #-1764]
	ldr r4, [fp, #-1764]
	add r10, r4, r10
	str r10, [fp, #-76]
	mov r10, #0
	mov32 r10, a3
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	ldr r10, [r10, #0]
	str r10, [fp, #-72]
	ldr r10, [fp, #-72]
	str r10, [fp, #-80]
	ldr r10, [fp, #-76]
	ldr r4, [fp, #-80]
	str r4, [fp, #-1768]
	ldr r4, [fp, #-1768]
	add r10, r10, r4
	str r10, [fp, #-84]
	ldr r10, [fp, #-84]
	str r10, [fp, #-1380]
	mov r10, #4
	str r10, [fp, #-88]
	ldr r10, [fp, #-2244]
	str r10, [fp, #-92]
	ldr r10, [fp, #-88]
	ldr r4, [fp, #-92]
	str r4, [fp, #-1772]
	ldr r4, [fp, #-1772]
	add r10, r10, r4
	str r10, [fp, #-100]
	mov r10, #0
	mov32 r10, a4
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	ldr r10, [r10, #0]
	str r10, [fp, #-96]
	ldr r10, [fp, #-96]
	str r10, [fp, #-104]
	ldr r10, [fp, #-100]
	ldr r4, [fp, #-104]
	str r4, [fp, #-1776]
	ldr r4, [fp, #-1776]
	add r10, r10, r4
	str r10, [fp, #-108]
	ldr r10, [fp, #-108]
	str r10, [fp, #-1408]
	mov r10, #1
	str r10, [fp, #-112]
	ldr r10, [fp, #-1324]
	str r10, [fp, #-116]
	ldr r10, [fp, #-112]
	ldr r4, [fp, #-116]
	str r4, [fp, #-1780]
	ldr r4, [fp, #-1780]
	add r10, r10, r4
	str r10, [fp, #-124]
	mov r10, #0
	mov32 r10, a5
	str r10, [fp, #-120]
	ldr r10, [fp, #-120]
	ldr r10, [r10, #0]
	str r10, [fp, #-120]
	ldr r10, [fp, #-120]
	str r10, [fp, #-128]
	ldr r10, [fp, #-124]
	ldr r4, [fp, #-128]
	str r4, [fp, #-1784]
	ldr r4, [fp, #-1784]
	add r10, r10, r4
	str r10, [fp, #-132]
	ldr r10, [fp, #-132]
	str r10, [fp, #-1212]
	mov r10, #2
	str r10, [fp, #-136]
	ldr r10, [fp, #-1352]
	str r10, [fp, #-140]
	ldr r10, [fp, #-136]
	ldr r4, [fp, #-140]
	str r4, [fp, #-1788]
	ldr r4, [fp, #-1788]
	add r10, r10, r4
	str r10, [fp, #-148]
	mov r10, #0
	mov32 r10, a6
	str r10, [fp, #-144]
	ldr r10, [fp, #-144]
	ldr r10, [r10, #0]
	str r10, [fp, #-144]
	ldr r10, [fp, #-144]
	str r10, [fp, #-152]
	ldr r10, [fp, #-148]
	ldr r4, [fp, #-152]
	str r4, [fp, #-1792]
	ldr r4, [fp, #-1792]
	add r10, r10, r4
	str r10, [fp, #-156]
	ldr r10, [fp, #-156]
	str r10, [fp, #-1240]
	mov r10, #3
	str r10, [fp, #-164]
	ldr r10, [fp, #-1380]
	str r10, [fp, #-160]
	ldr r10, [fp, #-160]
	ldr r4, [fp, #-164]
	str r4, [fp, #-1796]
	ldr r4, [fp, #-1796]
	add r10, r4, r10
	str r10, [fp, #-172]
	mov r10, #0
	mov32 r10, a7
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	ldr r10, [r10, #0]
	str r10, [fp, #-168]
	ldr r10, [fp, #-168]
	str r10, [fp, #-176]
	ldr r10, [fp, #-172]
	ldr r4, [fp, #-176]
	str r4, [fp, #-1800]
	ldr r4, [fp, #-1800]
	add r10, r10, r4
	str r10, [fp, #-180]
	ldr r10, [fp, #-180]
	str r10, [fp, #-1268]
	mov r10, #4
	str r10, [fp, #-184]
	ldr r10, [fp, #-1408]
	str r10, [fp, #-188]
	ldr r10, [fp, #-184]
	ldr r4, [fp, #-188]
	str r4, [fp, #-1804]
	ldr r4, [fp, #-1804]
	add r10, r10, r4
	str r10, [fp, #-196]
	mov r10, #0
	mov32 r10, a8
	str r10, [fp, #-192]
	ldr r10, [fp, #-192]
	ldr r10, [r10, #0]
	str r10, [fp, #-192]
	ldr r10, [fp, #-192]
	str r10, [fp, #-200]
	ldr r10, [fp, #-196]
	ldr r4, [fp, #-200]
	str r4, [fp, #-1808]
	ldr r4, [fp, #-1808]
	add r10, r10, r4
	str r10, [fp, #-204]
	ldr r10, [fp, #-204]
	str r10, [fp, #-1296]
	mov r10, #1
	str r10, [fp, #-208]
	ldr r10, [fp, #-1212]
	str r10, [fp, #-212]
	ldr r10, [fp, #-208]
	ldr r4, [fp, #-212]
	str r4, [fp, #-1812]
	ldr r4, [fp, #-1812]
	add r10, r10, r4
	str r10, [fp, #-220]
	mov r10, #0
	mov32 r10, a9
	str r10, [fp, #-216]
	ldr r10, [fp, #-216]
	ldr r10, [r10, #0]
	str r10, [fp, #-216]
	ldr r10, [fp, #-216]
	str r10, [fp, #-224]
	ldr r10, [fp, #-220]
	ldr r4, [fp, #-224]
	str r4, [fp, #-1816]
	ldr r4, [fp, #-1816]
	add r10, r10, r4
	str r10, [fp, #-228]
	ldr r10, [fp, #-228]
	str r10, [fp, #-1100]
	mov r10, #2
	str r10, [fp, #-232]
	ldr r10, [fp, #-1240]
	str r10, [fp, #-236]
	ldr r10, [fp, #-232]
	ldr r4, [fp, #-236]
	str r4, [fp, #-1820]
	ldr r4, [fp, #-1820]
	add r10, r10, r4
	str r10, [fp, #-244]
	mov r10, #0
	mov32 r10, a10
	str r10, [fp, #-240]
	ldr r10, [fp, #-240]
	ldr r10, [r10, #0]
	str r10, [fp, #-240]
	ldr r10, [fp, #-240]
	str r10, [fp, #-248]
	ldr r10, [fp, #-244]
	ldr r4, [fp, #-248]
	str r4, [fp, #-1824]
	ldr r4, [fp, #-1824]
	add r10, r10, r4
	str r10, [fp, #-252]
	ldr r10, [fp, #-252]
	str r10, [fp, #-1128]
	mov r10, #3
	str r10, [fp, #-256]
	ldr r10, [fp, #-1268]
	str r10, [fp, #-260]
	ldr r10, [fp, #-256]
	ldr r4, [fp, #-260]
	str r4, [fp, #-1828]
	ldr r4, [fp, #-1828]
	add r10, r10, r4
	str r10, [fp, #-268]
	mov r10, #0
	mov32 r10, a11
	str r10, [fp, #-264]
	ldr r10, [fp, #-264]
	ldr r10, [r10, #0]
	str r10, [fp, #-264]
	ldr r10, [fp, #-264]
	str r10, [fp, #-272]
	ldr r10, [fp, #-268]
	ldr r4, [fp, #-272]
	str r4, [fp, #-1832]
	ldr r4, [fp, #-1832]
	add r10, r10, r4
	str r10, [fp, #-276]
	ldr r10, [fp, #-276]
	str r10, [fp, #-1156]
	mov r10, #4
	str r10, [fp, #-280]
	ldr r10, [fp, #-1296]
	str r10, [fp, #-284]
	ldr r10, [fp, #-280]
	ldr r4, [fp, #-284]
	str r4, [fp, #-1836]
	ldr r4, [fp, #-1836]
	add r10, r10, r4
	str r10, [fp, #-292]
	mov r10, #0
	mov32 r10, a12
	str r10, [fp, #-288]
	ldr r10, [fp, #-288]
	ldr r10, [r10, #0]
	str r10, [fp, #-288]
	ldr r10, [fp, #-288]
	str r10, [fp, #-296]
	ldr r10, [fp, #-292]
	ldr r4, [fp, #-296]
	str r4, [fp, #-1840]
	ldr r4, [fp, #-1840]
	add r10, r10, r4
	str r10, [fp, #-300]
	ldr r10, [fp, #-300]
	str r10, [fp, #-1184]
	mov r10, #1
	str r10, [fp, #-304]
	ldr r10, [fp, #-1100]
	str r10, [fp, #-308]
	ldr r10, [fp, #-304]
	ldr r4, [fp, #-308]
	str r4, [fp, #-1844]
	ldr r4, [fp, #-1844]
	add r10, r10, r4
	str r10, [fp, #-316]
	mov r10, #0
	mov32 r10, a13
	str r10, [fp, #-312]
	ldr r10, [fp, #-312]
	ldr r10, [r10, #0]
	str r10, [fp, #-312]
	ldr r10, [fp, #-312]
	str r10, [fp, #-320]
	ldr r10, [fp, #-316]
	ldr r4, [fp, #-320]
	str r4, [fp, #-1848]
	ldr r4, [fp, #-1848]
	add r10, r10, r4
	str r10, [fp, #-324]
	ldr r10, [fp, #-324]
	str r10, [fp, #-988]
	mov r10, #2
	str r10, [fp, #-332]
	ldr r10, [fp, #-1128]
	str r10, [fp, #-328]
	ldr r10, [fp, #-328]
	ldr r4, [fp, #-332]
	str r4, [fp, #-1852]
	ldr r4, [fp, #-1852]
	add r10, r4, r10
	str r10, [fp, #-340]
	mov r10, #0
	mov32 r10, a14
	str r10, [fp, #-336]
	ldr r10, [fp, #-336]
	ldr r10, [r10, #0]
	str r10, [fp, #-336]
	ldr r10, [fp, #-336]
	str r10, [fp, #-344]
	ldr r10, [fp, #-340]
	ldr r4, [fp, #-344]
	str r4, [fp, #-1856]
	ldr r4, [fp, #-1856]
	add r10, r10, r4
	str r10, [fp, #-348]
	ldr r10, [fp, #-348]
	str r10, [fp, #-1016]
	mov r10, #3
	str r10, [fp, #-352]
	ldr r10, [fp, #-1156]
	str r10, [fp, #-356]
	ldr r10, [fp, #-352]
	ldr r4, [fp, #-356]
	str r4, [fp, #-1860]
	ldr r4, [fp, #-1860]
	add r10, r10, r4
	str r10, [fp, #-368]
	mov r10, #0
	mov32 r10, a15
	str r10, [fp, #-360]
	ldr r10, [fp, #-360]
	ldr r10, [r10, #0]
	str r10, [fp, #-360]
	ldr r10, [fp, #-360]
	str r10, [fp, #-364]
	ldr r10, [fp, #-364]
	ldr r4, [fp, #-368]
	str r4, [fp, #-1864]
	ldr r4, [fp, #-1864]
	add r10, r4, r10
	str r10, [fp, #-372]
	ldr r10, [fp, #-372]
	str r10, [fp, #-1044]
	mov r10, #4
	str r10, [fp, #-376]
	ldr r10, [fp, #-1184]
	str r10, [fp, #-380]
	ldr r10, [fp, #-376]
	ldr r4, [fp, #-380]
	str r4, [fp, #-1868]
	ldr r4, [fp, #-1868]
	add r10, r10, r4
	str r10, [fp, #-388]
	mov r10, #0
	mov32 r10, a16
	str r10, [fp, #-384]
	ldr r10, [fp, #-384]
	ldr r10, [r10, #0]
	str r10, [fp, #-384]
	ldr r10, [fp, #-384]
	str r10, [fp, #-392]
	ldr r10, [fp, #-388]
	ldr r4, [fp, #-392]
	str r4, [fp, #-1872]
	ldr r4, [fp, #-1872]
	add r10, r10, r4
	str r10, [fp, #-396]
	ldr r10, [fp, #-396]
	str r10, [fp, #-1072]
	mov r10, #1
	str r10, [fp, #-400]
	ldr r10, [fp, #-988]
	str r10, [fp, #-404]
	ldr r10, [fp, #-400]
	ldr r4, [fp, #-404]
	str r4, [fp, #-1876]
	ldr r4, [fp, #-1876]
	add r10, r10, r4
	str r10, [fp, #-412]
	mov r10, #0
	mov32 r10, a17
	str r10, [fp, #-408]
	ldr r10, [fp, #-408]
	ldr r10, [r10, #0]
	str r10, [fp, #-408]
	ldr r10, [fp, #-408]
	str r10, [fp, #-416]
	ldr r10, [fp, #-412]
	ldr r4, [fp, #-416]
	str r4, [fp, #-1880]
	ldr r4, [fp, #-1880]
	add r10, r10, r4
	str r10, [fp, #-420]
	ldr r10, [fp, #-420]
	str r10, [fp, #-876]
	mov r10, #2
	str r10, [fp, #-428]
	ldr r10, [fp, #-1016]
	str r10, [fp, #-424]
	ldr r10, [fp, #-424]
	ldr r4, [fp, #-428]
	str r4, [fp, #-1884]
	ldr r4, [fp, #-1884]
	add r10, r4, r10
	str r10, [fp, #-436]
	mov r10, #0
	mov32 r10, a18
	str r10, [fp, #-432]
	ldr r10, [fp, #-432]
	ldr r10, [r10, #0]
	str r10, [fp, #-432]
	ldr r10, [fp, #-432]
	str r10, [fp, #-440]
	ldr r10, [fp, #-436]
	ldr r4, [fp, #-440]
	str r4, [fp, #-1888]
	ldr r4, [fp, #-1888]
	add r10, r10, r4
	str r10, [fp, #-444]
	ldr r10, [fp, #-444]
	str r10, [fp, #-904]
	mov r10, #3
	str r10, [fp, #-448]
	ldr r10, [fp, #-1044]
	str r10, [fp, #-452]
	ldr r10, [fp, #-448]
	ldr r4, [fp, #-452]
	str r4, [fp, #-1892]
	ldr r4, [fp, #-1892]
	add r10, r10, r4
	str r10, [fp, #-460]
	mov r10, #0
	mov32 r10, a19
	str r10, [fp, #-456]
	ldr r10, [fp, #-456]
	ldr r10, [r10, #0]
	str r10, [fp, #-456]
	ldr r10, [fp, #-456]
	str r10, [fp, #-464]
	ldr r10, [fp, #-460]
	ldr r4, [fp, #-464]
	str r4, [fp, #-1896]
	ldr r4, [fp, #-1896]
	add r10, r10, r4
	str r10, [fp, #-468]
	ldr r10, [fp, #-468]
	str r10, [fp, #-932]
	mov r10, #4
	str r10, [fp, #-472]
	ldr r10, [fp, #-1072]
	str r10, [fp, #-476]
	ldr r10, [fp, #-472]
	ldr r4, [fp, #-476]
	str r4, [fp, #-1900]
	ldr r4, [fp, #-1900]
	add r10, r10, r4
	str r10, [fp, #-484]
	mov r10, #0
	mov32 r10, a20
	str r10, [fp, #-480]
	ldr r10, [fp, #-480]
	ldr r10, [r10, #0]
	str r10, [fp, #-480]
	ldr r10, [fp, #-480]
	str r10, [fp, #-488]
	ldr r10, [fp, #-484]
	ldr r4, [fp, #-488]
	str r4, [fp, #-1904]
	ldr r4, [fp, #-1904]
	add r10, r10, r4
	str r10, [fp, #-492]
	ldr r10, [fp, #-492]
	str r10, [fp, #-960]
	mov r10, #1
	str r10, [fp, #-500]
	ldr r10, [fp, #-876]
	str r10, [fp, #-496]
	ldr r10, [fp, #-496]
	ldr r4, [fp, #-500]
	str r4, [fp, #-1908]
	ldr r4, [fp, #-1908]
	add r10, r4, r10
	str r10, [fp, #-508]
	mov r10, #0
	mov32 r10, a21
	str r10, [fp, #-504]
	ldr r10, [fp, #-504]
	ldr r10, [r10, #0]
	str r10, [fp, #-504]
	ldr r10, [fp, #-504]
	str r10, [fp, #-512]
	ldr r10, [fp, #-508]
	ldr r4, [fp, #-512]
	str r4, [fp, #-1912]
	ldr r4, [fp, #-1912]
	add r10, r10, r4
	str r10, [fp, #-516]
	ldr r10, [fp, #-516]
	str r10, [fp, #-800]
	mov r10, #2
	str r10, [fp, #-520]
	ldr r10, [fp, #-904]
	str r10, [fp, #-524]
	ldr r10, [fp, #-520]
	ldr r4, [fp, #-524]
	str r4, [fp, #-1916]
	ldr r4, [fp, #-1916]
	add r10, r10, r4
	str r10, [fp, #-532]
	mov r10, #0
	mov32 r10, a22
	str r10, [fp, #-528]
	ldr r10, [fp, #-528]
	ldr r10, [r10, #0]
	str r10, [fp, #-528]
	ldr r10, [fp, #-528]
	str r10, [fp, #-536]
	ldr r10, [fp, #-532]
	ldr r4, [fp, #-536]
	str r4, [fp, #-1920]
	ldr r4, [fp, #-1920]
	add r10, r10, r4
	str r10, [fp, #-540]
	ldr r10, [fp, #-540]
	str r10, [fp, #-804]
	mov r10, #3
	str r10, [fp, #-544]
	ldr r10, [fp, #-932]
	str r10, [fp, #-548]
	ldr r10, [fp, #-544]
	ldr r4, [fp, #-548]
	str r4, [fp, #-1924]
	ldr r4, [fp, #-1924]
	add r10, r10, r4
	str r10, [fp, #-556]
	mov r10, #0
	mov32 r10, a23
	str r10, [fp, #-552]
	ldr r10, [fp, #-552]
	ldr r10, [r10, #0]
	str r10, [fp, #-552]
	ldr r10, [fp, #-552]
	str r10, [fp, #-560]
	ldr r10, [fp, #-556]
	ldr r4, [fp, #-560]
	str r4, [fp, #-1928]
	ldr r4, [fp, #-1928]
	add r10, r10, r4
	str r10, [fp, #-564]
	ldr r10, [fp, #-564]
	str r10, [fp, #-820]
	mov r10, #4
	str r10, [fp, #-572]
	ldr r10, [fp, #-960]
	str r10, [fp, #-568]
	ldr r10, [fp, #-568]
	ldr r4, [fp, #-572]
	str r4, [fp, #-1932]
	ldr r4, [fp, #-1932]
	add r10, r4, r10
	str r10, [fp, #-584]
	mov r10, #0
	mov32 r10, a24
	str r10, [fp, #-576]
	ldr r10, [fp, #-576]
	ldr r10, [r10, #0]
	str r10, [fp, #-576]
	ldr r10, [fp, #-576]
	str r10, [fp, #-580]
	ldr r10, [fp, #-580]
	ldr r4, [fp, #-584]
	str r4, [fp, #-1936]
	ldr r4, [fp, #-1936]
	add r10, r4, r10
	str r10, [fp, #-588]
	ldr r10, [fp, #-588]
	str r10, [fp, #-848]
	mov r10, #1
	str r10, [fp, #-592]
	ldr r10, [fp, #-800]
	str r10, [fp, #-596]
	ldr r10, [fp, #-592]
	ldr r4, [fp, #-596]
	str r4, [fp, #-1940]
	ldr r4, [fp, #-1940]
	add r10, r10, r4
	str r10, [fp, #-608]
	mov r10, #0
	mov32 r10, a25
	str r10, [fp, #-600]
	ldr r10, [fp, #-600]
	ldr r10, [r10, #0]
	str r10, [fp, #-600]
	ldr r10, [fp, #-600]
	str r10, [fp, #-604]
	ldr r10, [fp, #-604]
	ldr r4, [fp, #-608]
	str r4, [fp, #-1944]
	ldr r4, [fp, #-1944]
	add r10, r4, r10
	str r10, [fp, #-612]
	ldr r10, [fp, #-612]
	str r10, [fp, #-784]
	mov r10, #2
	str r10, [fp, #-616]
	ldr r10, [fp, #-804]
	str r10, [fp, #-620]
	ldr r10, [fp, #-616]
	ldr r4, [fp, #-620]
	str r4, [fp, #-1948]
	ldr r4, [fp, #-1948]
	add r10, r10, r4
	str r10, [fp, #-628]
	mov r10, #0
	mov32 r10, a26
	str r10, [fp, #-624]
	ldr r10, [fp, #-624]
	ldr r10, [r10, #0]
	str r10, [fp, #-624]
	ldr r10, [fp, #-624]
	str r10, [fp, #-632]
	ldr r10, [fp, #-628]
	ldr r4, [fp, #-632]
	str r4, [fp, #-1952]
	ldr r4, [fp, #-1952]
	add r10, r10, r4
	str r10, [fp, #-636]
	ldr r10, [fp, #-636]
	str r10, [fp, #-788]
	mov r10, #3
	str r10, [fp, #-644]
	ldr r10, [fp, #-820]
	str r10, [fp, #-640]
	ldr r10, [fp, #-640]
	ldr r4, [fp, #-644]
	str r4, [fp, #-1956]
	ldr r4, [fp, #-1956]
	add r10, r4, r10
	str r10, [fp, #-652]
	mov r10, #0
	mov32 r10, a27
	str r10, [fp, #-648]
	ldr r10, [fp, #-648]
	ldr r10, [r10, #0]
	str r10, [fp, #-648]
	ldr r10, [fp, #-648]
	str r10, [fp, #-656]
	ldr r10, [fp, #-652]
	ldr r4, [fp, #-656]
	str r4, [fp, #-1960]
	ldr r4, [fp, #-1960]
	add r10, r10, r4
	str r10, [fp, #-660]
	ldr r10, [fp, #-660]
	str r10, [fp, #-792]
	mov r10, #4
	str r10, [fp, #-664]
	ldr r10, [fp, #-848]
	str r10, [fp, #-668]
	ldr r10, [fp, #-664]
	ldr r4, [fp, #-668]
	str r4, [fp, #-1964]
	ldr r4, [fp, #-1964]
	add r10, r10, r4
	str r10, [fp, #-676]
	mov r10, #0
	mov32 r10, a28
	str r10, [fp, #-672]
	ldr r10, [fp, #-672]
	ldr r10, [r10, #0]
	str r10, [fp, #-672]
	ldr r10, [fp, #-672]
	str r10, [fp, #-680]
	ldr r10, [fp, #-676]
	ldr r4, [fp, #-680]
	str r4, [fp, #-1968]
	ldr r4, [fp, #-1968]
	add r10, r10, r4
	str r10, [fp, #-684]
	ldr r10, [fp, #-684]
	str r10, [fp, #-796]
	mov r10, #1
	str r10, [fp, #-688]
	ldr r10, [fp, #-784]
	str r10, [fp, #-692]
	ldr r10, [fp, #-688]
	ldr r4, [fp, #-692]
	str r4, [fp, #-1972]
	ldr r4, [fp, #-1972]
	add r10, r10, r4
	str r10, [fp, #-700]
	mov r10, #0
	mov32 r10, a29
	str r10, [fp, #-696]
	ldr r10, [fp, #-696]
	ldr r10, [r10, #0]
	str r10, [fp, #-696]
	ldr r10, [fp, #-696]
	str r10, [fp, #-704]
	ldr r10, [fp, #-700]
	ldr r4, [fp, #-704]
	str r4, [fp, #-1976]
	ldr r4, [fp, #-1976]
	add r10, r10, r4
	str r10, [fp, #-708]
	ldr r10, [fp, #-708]
	str r10, [fp, #-1736]
	mov r10, #2
	str r10, [fp, #-712]
	ldr r10, [fp, #-788]
	str r10, [fp, #-716]
	ldr r10, [fp, #-712]
	ldr r4, [fp, #-716]
	str r4, [fp, #-1980]
	ldr r4, [fp, #-1980]
	add r10, r10, r4
	str r10, [fp, #-724]
	mov r10, #0
	mov32 r10, a30
	str r10, [fp, #-720]
	ldr r10, [fp, #-720]
	ldr r10, [r10, #0]
	str r10, [fp, #-720]
	ldr r10, [fp, #-720]
	str r10, [fp, #-728]
	ldr r10, [fp, #-724]
	ldr r4, [fp, #-728]
	str r4, [fp, #-1984]
	ldr r4, [fp, #-1984]
	add r10, r10, r4
	str r10, [fp, #-732]
	ldr r10, [fp, #-732]
	str r10, [fp, #-1740]
	mov r10, #3
	str r10, [fp, #-736]
	ldr r10, [fp, #-792]
	str r10, [fp, #-740]
	ldr r10, [fp, #-736]
	ldr r4, [fp, #-740]
	str r4, [fp, #-1988]
	ldr r4, [fp, #-1988]
	add r10, r10, r4
	str r10, [fp, #-748]
	mov r10, #0
	mov32 r10, a31
	str r10, [fp, #-744]
	ldr r10, [fp, #-744]
	ldr r10, [r10, #0]
	str r10, [fp, #-744]
	ldr r10, [fp, #-744]
	str r10, [fp, #-752]
	ldr r10, [fp, #-748]
	ldr r4, [fp, #-752]
	str r4, [fp, #-1992]
	ldr r4, [fp, #-1992]
	add r10, r10, r4
	str r10, [fp, #-756]
	ldr r10, [fp, #-756]
	str r10, [fp, #-1744]
	mov r10, #4
	str r10, [fp, #-760]
	ldr r10, [fp, #-796]
	str r10, [fp, #-764]
	ldr r10, [fp, #-760]
	ldr r4, [fp, #-764]
	str r4, [fp, #-1996]
	ldr r4, [fp, #-1996]
	add r10, r10, r4
	str r10, [fp, #-772]
	mov r10, #0
	mov32 r10, a32
	str r10, [fp, #-768]
	ldr r10, [fp, #-768]
	ldr r10, [r10, #0]
	str r10, [fp, #-768]
	ldr r10, [fp, #-768]
	str r10, [fp, #-776]
	ldr r10, [fp, #-772]
	ldr r4, [fp, #-776]
	str r4, [fp, #-2000]
	ldr r4, [fp, #-2000]
	add r10, r10, r4
	str r10, [fp, #-780]
	ldr r10, [fp, #-780]
	str r10, [fp, #-1748]
	sub r9, r9, r8
	add r9, r9, #10
	str r9, [fp, #-1628]
	mov r9, #1
	ldr r8, [fp, #-784]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a29
	ldr r8, [r8, #0]
	add r9, r9, r8
	str r9, [fp, #-1736]
	mov r9, #2
	ldr r8, [fp, #-788]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a30
	ldr r8, [r8, #0]
	add r9, r9, r8
	str r9, [fp, #-1740]
	mov r9, #3
	ldr r8, [fp, #-792]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a31
	ldr r8, [r8, #0]
	add r9, r9, r8
	str r9, [fp, #-1744]
	mov r9, #4
	ldr r8, [fp, #-796]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a32
	ldr r8, [r8, #0]
	add r9, r9, r8
	str r9, [fp, #-1748]
	mov r9, #1
	ldr r8, [fp, #-800]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a25
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #2
	ldr r10, [fp, #-804]
	str r10, [fp, #-808]
	ldr r10, [fp, #-808]
	add r8, r8, r10
	mov r10, #0
	mov32 r10, a26
	str r10, [fp, #-812]
	ldr r10, [fp, #-812]
	ldr r10, [r10, #0]
	str r10, [fp, #-812]
	ldr r10, [fp, #-812]
	str r10, [fp, #-816]
	ldr r10, [fp, #-816]
	add r8, r8, r10
	mov r10, #3
	str r10, [fp, #-824]
	ldr r10, [fp, #-820]
	str r10, [fp, #-828]
	ldr r10, [fp, #-824]
	ldr r4, [fp, #-828]
	str r4, [fp, #-2004]
	ldr r4, [fp, #-2004]
	add r10, r10, r4
	str r10, [fp, #-836]
	mov r10, #0
	mov32 r10, a27
	str r10, [fp, #-832]
	ldr r10, [fp, #-832]
	ldr r10, [r10, #0]
	str r10, [fp, #-832]
	ldr r10, [fp, #-832]
	str r10, [fp, #-840]
	ldr r10, [fp, #-836]
	ldr r4, [fp, #-840]
	str r4, [fp, #-2008]
	ldr r4, [fp, #-2008]
	add r10, r10, r4
	str r10, [fp, #-844]
	ldr r10, [fp, #-844]
	str r10, [fp, #-1728]
	mov r10, #4
	str r10, [fp, #-856]
	ldr r10, [fp, #-848]
	str r10, [fp, #-852]
	ldr r10, [fp, #-852]
	ldr r4, [fp, #-856]
	str r4, [fp, #-2012]
	ldr r4, [fp, #-2012]
	add r10, r4, r10
	str r10, [fp, #-864]
	mov r10, #0
	mov32 r10, a28
	str r10, [fp, #-860]
	ldr r10, [fp, #-860]
	ldr r10, [r10, #0]
	str r10, [fp, #-860]
	ldr r10, [fp, #-860]
	str r10, [fp, #-868]
	ldr r10, [fp, #-864]
	ldr r4, [fp, #-868]
	str r4, [fp, #-2016]
	ldr r4, [fp, #-2016]
	add r10, r10, r4
	str r10, [fp, #-872]
	ldr r10, [fp, #-872]
	str r10, [fp, #-1732]
	mov r10, #1
	str r10, [fp, #-880]
	ldr r10, [fp, #-876]
	str r10, [fp, #-884]
	ldr r10, [fp, #-880]
	ldr r4, [fp, #-884]
	str r4, [fp, #-2020]
	ldr r4, [fp, #-2020]
	add r10, r10, r4
	str r10, [fp, #-896]
	mov r10, #0
	mov32 r10, a21
	str r10, [fp, #-888]
	ldr r10, [fp, #-888]
	ldr r10, [r10, #0]
	str r10, [fp, #-888]
	ldr r10, [fp, #-888]
	str r10, [fp, #-892]
	ldr r10, [fp, #-892]
	ldr r4, [fp, #-896]
	str r4, [fp, #-2024]
	ldr r4, [fp, #-2024]
	add r10, r4, r10
	str r10, [fp, #-900]
	ldr r10, [fp, #-900]
	str r10, [fp, #-1712]
	mov r10, #2
	str r10, [fp, #-908]
	ldr r10, [fp, #-904]
	str r10, [fp, #-912]
	ldr r10, [fp, #-908]
	ldr r4, [fp, #-912]
	str r4, [fp, #-2028]
	ldr r4, [fp, #-2028]
	add r10, r10, r4
	str r10, [fp, #-920]
	mov r10, #0
	mov32 r10, a22
	str r10, [fp, #-916]
	ldr r10, [fp, #-916]
	ldr r10, [r10, #0]
	str r10, [fp, #-916]
	ldr r10, [fp, #-916]
	str r10, [fp, #-924]
	ldr r10, [fp, #-920]
	ldr r4, [fp, #-924]
	str r4, [fp, #-2032]
	ldr r4, [fp, #-2032]
	add r10, r10, r4
	str r10, [fp, #-928]
	ldr r10, [fp, #-928]
	str r10, [fp, #-1716]
	mov r10, #3
	str r10, [fp, #-940]
	ldr r10, [fp, #-932]
	str r10, [fp, #-936]
	ldr r10, [fp, #-936]
	ldr r4, [fp, #-940]
	str r4, [fp, #-2036]
	ldr r4, [fp, #-2036]
	add r10, r4, r10
	str r10, [fp, #-948]
	mov r10, #0
	mov32 r10, a23
	str r10, [fp, #-944]
	ldr r10, [fp, #-944]
	ldr r10, [r10, #0]
	str r10, [fp, #-944]
	ldr r10, [fp, #-944]
	str r10, [fp, #-952]
	ldr r10, [fp, #-948]
	ldr r4, [fp, #-952]
	str r4, [fp, #-2040]
	ldr r4, [fp, #-2040]
	add r10, r10, r4
	str r10, [fp, #-956]
	ldr r10, [fp, #-956]
	str r10, [fp, #-1720]
	mov r10, #4
	str r10, [fp, #-964]
	ldr r10, [fp, #-960]
	str r10, [fp, #-968]
	ldr r10, [fp, #-964]
	ldr r4, [fp, #-968]
	str r4, [fp, #-2044]
	ldr r4, [fp, #-2044]
	add r10, r10, r4
	str r10, [fp, #-976]
	mov r10, #0
	mov32 r10, a24
	str r10, [fp, #-972]
	ldr r10, [fp, #-972]
	ldr r10, [r10, #0]
	str r10, [fp, #-972]
	ldr r10, [fp, #-972]
	str r10, [fp, #-980]
	ldr r10, [fp, #-976]
	ldr r4, [fp, #-980]
	str r4, [fp, #-2048]
	ldr r4, [fp, #-2048]
	add r10, r10, r4
	str r10, [fp, #-984]
	ldr r10, [fp, #-984]
	str r10, [fp, #-1724]
	mov r10, #1
	str r10, [fp, #-992]
	ldr r10, [fp, #-988]
	str r10, [fp, #-996]
	ldr r10, [fp, #-992]
	ldr r4, [fp, #-996]
	str r4, [fp, #-2052]
	ldr r4, [fp, #-2052]
	add r10, r10, r4
	str r10, [fp, #-1008]
	mov r10, #0
	mov32 r10, a17
	str r10, [fp, #-1000]
	ldr r10, [fp, #-1000]
	ldr r10, [r10, #0]
	str r10, [fp, #-1000]
	ldr r10, [fp, #-1000]
	str r10, [fp, #-1004]
	ldr r10, [fp, #-1004]
	ldr r4, [fp, #-1008]
	str r4, [fp, #-2056]
	ldr r4, [fp, #-2056]
	add r10, r4, r10
	str r10, [fp, #-1012]
	ldr r10, [fp, #-1012]
	str r10, [fp, #-1696]
	mov r10, #2
	str r10, [fp, #-1020]
	ldr r10, [fp, #-1016]
	str r10, [fp, #-1024]
	ldr r10, [fp, #-1020]
	ldr r4, [fp, #-1024]
	str r4, [fp, #-2060]
	ldr r4, [fp, #-2060]
	add r10, r10, r4
	str r10, [fp, #-1036]
	mov r10, #0
	mov32 r10, a18
	str r10, [fp, #-1028]
	ldr r10, [fp, #-1028]
	ldr r10, [r10, #0]
	str r10, [fp, #-1028]
	ldr r10, [fp, #-1028]
	str r10, [fp, #-1032]
	ldr r10, [fp, #-1032]
	ldr r4, [fp, #-1036]
	str r4, [fp, #-2064]
	ldr r4, [fp, #-2064]
	add r10, r4, r10
	str r10, [fp, #-1040]
	ldr r10, [fp, #-1040]
	str r10, [fp, #-1700]
	mov r10, #3
	str r10, [fp, #-1048]
	ldr r10, [fp, #-1044]
	str r10, [fp, #-1052]
	ldr r10, [fp, #-1048]
	ldr r4, [fp, #-1052]
	str r4, [fp, #-2068]
	ldr r4, [fp, #-2068]
	add r10, r10, r4
	str r10, [fp, #-1064]
	mov r10, #0
	mov32 r10, a19
	str r10, [fp, #-1056]
	ldr r10, [fp, #-1056]
	ldr r10, [r10, #0]
	str r10, [fp, #-1056]
	ldr r10, [fp, #-1056]
	str r10, [fp, #-1060]
	ldr r10, [fp, #-1060]
	ldr r4, [fp, #-1064]
	str r4, [fp, #-2072]
	ldr r4, [fp, #-2072]
	add r10, r4, r10
	str r10, [fp, #-1068]
	ldr r10, [fp, #-1068]
	str r10, [fp, #-1704]
	mov r10, #4
	str r10, [fp, #-1076]
	ldr r10, [fp, #-1072]
	str r10, [fp, #-1080]
	ldr r10, [fp, #-1076]
	ldr r4, [fp, #-1080]
	str r4, [fp, #-2076]
	ldr r4, [fp, #-2076]
	add r10, r10, r4
	str r10, [fp, #-1088]
	mov r10, #0
	mov32 r10, a20
	str r10, [fp, #-1084]
	ldr r10, [fp, #-1084]
	ldr r10, [r10, #0]
	str r10, [fp, #-1084]
	ldr r10, [fp, #-1084]
	str r10, [fp, #-1092]
	ldr r10, [fp, #-1088]
	ldr r4, [fp, #-1092]
	str r4, [fp, #-2080]
	ldr r4, [fp, #-2080]
	add r10, r10, r4
	str r10, [fp, #-1096]
	ldr r10, [fp, #-1096]
	str r10, [fp, #-1708]
	mov r10, #1
	str r10, [fp, #-1104]
	ldr r10, [fp, #-1100]
	str r10, [fp, #-1108]
	ldr r10, [fp, #-1104]
	ldr r4, [fp, #-1108]
	str r4, [fp, #-2084]
	ldr r4, [fp, #-2084]
	add r10, r10, r4
	str r10, [fp, #-1116]
	mov r10, #0
	mov32 r10, a13
	str r10, [fp, #-1112]
	ldr r10, [fp, #-1112]
	ldr r10, [r10, #0]
	str r10, [fp, #-1112]
	ldr r10, [fp, #-1112]
	str r10, [fp, #-1120]
	ldr r10, [fp, #-1116]
	ldr r4, [fp, #-1120]
	str r4, [fp, #-2088]
	ldr r4, [fp, #-2088]
	add r10, r10, r4
	str r10, [fp, #-1124]
	ldr r10, [fp, #-1124]
	str r10, [fp, #-1680]
	mov r10, #2
	str r10, [fp, #-1132]
	ldr r10, [fp, #-1128]
	str r10, [fp, #-1136]
	ldr r10, [fp, #-1132]
	ldr r4, [fp, #-1136]
	str r4, [fp, #-2092]
	ldr r4, [fp, #-2092]
	add r10, r10, r4
	str r10, [fp, #-1144]
	mov r10, #0
	mov32 r10, a14
	str r10, [fp, #-1140]
	ldr r10, [fp, #-1140]
	ldr r10, [r10, #0]
	str r10, [fp, #-1140]
	ldr r10, [fp, #-1140]
	str r10, [fp, #-1148]
	ldr r10, [fp, #-1144]
	ldr r4, [fp, #-1148]
	str r4, [fp, #-2096]
	ldr r4, [fp, #-2096]
	add r10, r10, r4
	str r10, [fp, #-1152]
	ldr r10, [fp, #-1152]
	str r10, [fp, #-1684]
	mov r10, #3
	str r10, [fp, #-1160]
	ldr r10, [fp, #-1156]
	str r10, [fp, #-1164]
	ldr r10, [fp, #-1160]
	ldr r4, [fp, #-1164]
	str r4, [fp, #-2100]
	ldr r4, [fp, #-2100]
	add r10, r10, r4
	str r10, [fp, #-1172]
	mov r10, #0
	mov32 r10, a15
	str r10, [fp, #-1168]
	ldr r10, [fp, #-1168]
	ldr r10, [r10, #0]
	str r10, [fp, #-1168]
	ldr r10, [fp, #-1168]
	str r10, [fp, #-1176]
	ldr r10, [fp, #-1172]
	ldr r4, [fp, #-1176]
	str r4, [fp, #-2104]
	ldr r4, [fp, #-2104]
	add r10, r10, r4
	str r10, [fp, #-1180]
	ldr r10, [fp, #-1180]
	str r10, [fp, #-1688]
	mov r10, #4
	str r10, [fp, #-1188]
	ldr r10, [fp, #-1184]
	str r10, [fp, #-1192]
	ldr r10, [fp, #-1188]
	ldr r4, [fp, #-1192]
	str r4, [fp, #-2108]
	ldr r4, [fp, #-2108]
	add r10, r10, r4
	str r10, [fp, #-1204]
	mov r10, #0
	mov32 r10, a16
	str r10, [fp, #-1196]
	ldr r10, [fp, #-1196]
	ldr r10, [r10, #0]
	str r10, [fp, #-1196]
	ldr r10, [fp, #-1196]
	str r10, [fp, #-1200]
	ldr r10, [fp, #-1200]
	ldr r4, [fp, #-1204]
	str r4, [fp, #-2112]
	ldr r4, [fp, #-2112]
	add r10, r4, r10
	str r10, [fp, #-1208]
	ldr r10, [fp, #-1208]
	str r10, [fp, #-1692]
	mov r10, #1
	str r10, [fp, #-1220]
	ldr r10, [fp, #-1212]
	str r10, [fp, #-1216]
	ldr r10, [fp, #-1216]
	ldr r4, [fp, #-1220]
	str r4, [fp, #-2116]
	ldr r4, [fp, #-2116]
	add r10, r4, r10
	str r10, [fp, #-1228]
	mov r10, #0
	mov32 r10, a9
	str r10, [fp, #-1224]
	ldr r10, [fp, #-1224]
	ldr r10, [r10, #0]
	str r10, [fp, #-1224]
	ldr r10, [fp, #-1224]
	str r10, [fp, #-1232]
	ldr r10, [fp, #-1228]
	ldr r4, [fp, #-1232]
	str r4, [fp, #-2120]
	ldr r4, [fp, #-2120]
	add r10, r10, r4
	str r10, [fp, #-1236]
	ldr r10, [fp, #-1236]
	str r10, [fp, #-1664]
	mov r10, #2
	str r10, [fp, #-1244]
	ldr r10, [fp, #-1240]
	str r10, [fp, #-1248]
	ldr r10, [fp, #-1244]
	ldr r4, [fp, #-1248]
	str r4, [fp, #-2124]
	ldr r4, [fp, #-2124]
	add r10, r10, r4
	str r10, [fp, #-1256]
	mov r10, #0
	mov32 r10, a10
	str r10, [fp, #-1252]
	ldr r10, [fp, #-1252]
	ldr r10, [r10, #0]
	str r10, [fp, #-1252]
	ldr r10, [fp, #-1252]
	str r10, [fp, #-1260]
	ldr r10, [fp, #-1256]
	ldr r4, [fp, #-1260]
	str r4, [fp, #-2128]
	ldr r4, [fp, #-2128]
	add r10, r10, r4
	str r10, [fp, #-1264]
	ldr r10, [fp, #-1264]
	str r10, [fp, #-1668]
	mov r10, #3
	str r10, [fp, #-1272]
	ldr r10, [fp, #-1268]
	str r10, [fp, #-1276]
	ldr r10, [fp, #-1272]
	ldr r4, [fp, #-1276]
	str r4, [fp, #-2132]
	ldr r4, [fp, #-2132]
	add r10, r10, r4
	str r10, [fp, #-1284]
	mov r10, #0
	mov32 r10, a11
	str r10, [fp, #-1280]
	ldr r10, [fp, #-1280]
	ldr r10, [r10, #0]
	str r10, [fp, #-1280]
	ldr r10, [fp, #-1280]
	str r10, [fp, #-1288]
	ldr r10, [fp, #-1284]
	ldr r4, [fp, #-1288]
	str r4, [fp, #-2136]
	ldr r4, [fp, #-2136]
	add r10, r10, r4
	str r10, [fp, #-1292]
	ldr r10, [fp, #-1292]
	str r10, [fp, #-1672]
	mov r10, #4
	str r10, [fp, #-1300]
	ldr r10, [fp, #-1296]
	str r10, [fp, #-1304]
	ldr r10, [fp, #-1300]
	ldr r4, [fp, #-1304]
	str r4, [fp, #-2140]
	ldr r4, [fp, #-2140]
	add r10, r10, r4
	str r10, [fp, #-1316]
	mov r10, #0
	mov32 r10, a12
	str r10, [fp, #-1308]
	ldr r10, [fp, #-1308]
	ldr r10, [r10, #0]
	str r10, [fp, #-1308]
	ldr r10, [fp, #-1308]
	str r10, [fp, #-1312]
	ldr r10, [fp, #-1312]
	ldr r4, [fp, #-1316]
	str r4, [fp, #-2144]
	ldr r4, [fp, #-2144]
	add r10, r4, r10
	str r10, [fp, #-1320]
	ldr r10, [fp, #-1320]
	str r10, [fp, #-1676]
	mov r10, #1
	str r10, [fp, #-1332]
	ldr r10, [fp, #-1324]
	str r10, [fp, #-1328]
	ldr r10, [fp, #-1328]
	ldr r4, [fp, #-1332]
	str r4, [fp, #-2148]
	ldr r4, [fp, #-2148]
	add r10, r4, r10
	str r10, [fp, #-1344]
	mov r10, #0
	mov32 r10, a5
	str r10, [fp, #-1336]
	ldr r10, [fp, #-1336]
	ldr r10, [r10, #0]
	str r10, [fp, #-1336]
	ldr r10, [fp, #-1336]
	str r10, [fp, #-1340]
	ldr r10, [fp, #-1340]
	ldr r4, [fp, #-1344]
	str r4, [fp, #-2152]
	ldr r4, [fp, #-2152]
	add r10, r4, r10
	str r10, [fp, #-1348]
	ldr r10, [fp, #-1348]
	str r10, [fp, #-1648]
	mov r10, #2
	str r10, [fp, #-1356]
	ldr r10, [fp, #-1352]
	str r10, [fp, #-1360]
	ldr r10, [fp, #-1356]
	ldr r4, [fp, #-1360]
	str r4, [fp, #-2156]
	ldr r4, [fp, #-2156]
	add r10, r10, r4
	str r10, [fp, #-1368]
	mov r10, #0
	mov32 r10, a6
	str r10, [fp, #-1364]
	ldr r10, [fp, #-1364]
	ldr r10, [r10, #0]
	str r10, [fp, #-1364]
	ldr r10, [fp, #-1364]
	str r10, [fp, #-1372]
	ldr r10, [fp, #-1368]
	ldr r4, [fp, #-1372]
	str r4, [fp, #-2160]
	ldr r4, [fp, #-2160]
	add r10, r10, r4
	str r10, [fp, #-1376]
	ldr r10, [fp, #-1376]
	str r10, [fp, #-1652]
	mov r10, #3
	str r10, [fp, #-1388]
	ldr r10, [fp, #-1380]
	str r10, [fp, #-1384]
	ldr r10, [fp, #-1384]
	ldr r4, [fp, #-1388]
	str r4, [fp, #-2164]
	ldr r4, [fp, #-2164]
	add r10, r4, r10
	str r10, [fp, #-1396]
	mov r10, #0
	mov32 r10, a7
	str r10, [fp, #-1392]
	ldr r10, [fp, #-1392]
	ldr r10, [r10, #0]
	str r10, [fp, #-1392]
	ldr r10, [fp, #-1392]
	str r10, [fp, #-1400]
	ldr r10, [fp, #-1396]
	ldr r4, [fp, #-1400]
	str r4, [fp, #-2168]
	ldr r4, [fp, #-2168]
	add r10, r10, r4
	str r10, [fp, #-1404]
	ldr r10, [fp, #-1404]
	str r10, [fp, #-1656]
	mov r10, #4
	str r10, [fp, #-1416]
	ldr r10, [fp, #-1408]
	str r10, [fp, #-1412]
	ldr r10, [fp, #-1412]
	ldr r4, [fp, #-1416]
	str r4, [fp, #-2172]
	ldr r4, [fp, #-2172]
	add r10, r4, r10
	str r10, [fp, #-1428]
	mov r10, #0
	mov32 r10, a8
	str r10, [fp, #-1420]
	ldr r10, [fp, #-1420]
	ldr r10, [r10, #0]
	str r10, [fp, #-1420]
	ldr r10, [fp, #-1420]
	str r10, [fp, #-1424]
	ldr r10, [fp, #-1424]
	ldr r4, [fp, #-1428]
	str r4, [fp, #-2176]
	ldr r4, [fp, #-2176]
	add r10, r4, r10
	str r10, [fp, #-1432]
	ldr r10, [fp, #-1432]
	str r10, [fp, #-1660]
	mov r10, #1
	str r10, [fp, #-1436]
	mov r10, r7
	str r10, [fp, #-1440]
	ldr r10, [fp, #-1436]
	ldr r4, [fp, #-1440]
	str r4, [fp, #-2180]
	ldr r4, [fp, #-2180]
	add r10, r10, r4
	str r10, [fp, #-1448]
	mov r10, #0
	mov32 r10, a1
	str r10, [fp, #-1444]
	ldr r10, [fp, #-1444]
	ldr r10, [r10, #0]
	str r10, [fp, #-1444]
	ldr r10, [fp, #-1444]
	str r10, [fp, #-1452]
	ldr r10, [fp, #-1448]
	ldr r4, [fp, #-1452]
	str r4, [fp, #-2184]
	ldr r4, [fp, #-2184]
	add r10, r10, r4
	str r10, [fp, #-1456]
	ldr r10, [fp, #-1456]
	str r10, [fp, #-1632]
	mov r10, #2
	str r10, [fp, #-1460]
	mov r10, r6
	str r10, [fp, #-1464]
	ldr r10, [fp, #-1460]
	ldr r4, [fp, #-1464]
	str r4, [fp, #-2188]
	ldr r4, [fp, #-2188]
	add r10, r10, r4
	str r10, [fp, #-1472]
	mov r10, #0
	mov32 r10, a2
	str r10, [fp, #-1468]
	ldr r10, [fp, #-1468]
	ldr r10, [r10, #0]
	str r10, [fp, #-1468]
	ldr r10, [fp, #-1468]
	str r10, [fp, #-1476]
	ldr r10, [fp, #-1472]
	ldr r4, [fp, #-1476]
	str r4, [fp, #-2192]
	ldr r4, [fp, #-2192]
	add r10, r10, r4
	str r10, [fp, #-1480]
	ldr r10, [fp, #-1480]
	str r10, [fp, #-1636]
	mov r10, #3
	str r10, [fp, #-1484]
	mov r10, r5
	str r10, [fp, #-1488]
	ldr r10, [fp, #-1484]
	ldr r4, [fp, #-1488]
	str r4, [fp, #-2196]
	ldr r4, [fp, #-2196]
	add r10, r10, r4
	str r10, [fp, #-1496]
	mov r10, #0
	mov32 r10, a3
	str r10, [fp, #-1492]
	ldr r10, [fp, #-1492]
	ldr r10, [r10, #0]
	str r10, [fp, #-1492]
	ldr r10, [fp, #-1492]
	str r10, [fp, #-1500]
	ldr r10, [fp, #-1496]
	ldr r4, [fp, #-1500]
	str r4, [fp, #-2200]
	ldr r4, [fp, #-2200]
	add r10, r10, r4
	str r10, [fp, #-1504]
	ldr r10, [fp, #-1504]
	str r10, [fp, #-1640]
	mov r10, #4
	str r10, [fp, #-1508]
	ldr r10, [fp, #-2244]
	str r10, [fp, #-1512]
	ldr r10, [fp, #-1508]
	ldr r4, [fp, #-1512]
	str r4, [fp, #-2204]
	ldr r4, [fp, #-2204]
	add r10, r10, r4
	str r10, [fp, #-1520]
	mov r10, #0
	mov32 r10, a4
	str r10, [fp, #-1516]
	ldr r10, [fp, #-1516]
	ldr r10, [r10, #0]
	str r10, [fp, #-1516]
	ldr r10, [fp, #-1516]
	str r10, [fp, #-1524]
	ldr r10, [fp, #-1520]
	ldr r4, [fp, #-1524]
	str r4, [fp, #-2208]
	ldr r4, [fp, #-2208]
	add r10, r10, r4
	str r10, [fp, #-1528]
	ldr r10, [fp, #-1528]
	str r10, [fp, #-1644]
	mov r10, #1
	str r10, [fp, #-1536]
	mov r10, r7
	str r10, [fp, #-1532]
	ldr r10, [fp, #-1532]
	ldr r4, [fp, #-1536]
	str r4, [fp, #-2212]
	ldr r4, [fp, #-2212]
	add r10, r4, r10
	str r10, [fp, #-1544]
	mov r10, #0
	mov32 r10, a1
	str r10, [fp, #-1540]
	ldr r10, [fp, #-1540]
	ldr r10, [r10, #0]
	str r10, [fp, #-1540]
	ldr r10, [fp, #-1540]
	str r10, [fp, #-1548]
	ldr r10, [fp, #-1544]
	ldr r4, [fp, #-1548]
	str r4, [fp, #-2216]
	ldr r4, [fp, #-2216]
	add r10, r10, r4
	str r10, [fp, #-1552]
	ldr r10, [fp, #-1552]
	str r10, [fp, #-1632]
	mov r10, #2
	str r10, [fp, #-1556]
	mov r10, r6
	str r10, [fp, #-1560]
	ldr r10, [fp, #-1556]
	ldr r4, [fp, #-1560]
	str r4, [fp, #-2220]
	ldr r4, [fp, #-2220]
	add r10, r10, r4
	str r10, [fp, #-1568]
	mov r10, #0
	mov32 r10, a2
	str r10, [fp, #-1564]
	ldr r10, [fp, #-1564]
	ldr r10, [r10, #0]
	str r10, [fp, #-1564]
	ldr r10, [fp, #-1564]
	str r10, [fp, #-1572]
	ldr r10, [fp, #-1568]
	ldr r4, [fp, #-1572]
	str r4, [fp, #-2224]
	ldr r4, [fp, #-2224]
	add r10, r10, r4
	str r10, [fp, #-1576]
	ldr r10, [fp, #-1576]
	str r10, [fp, #-1636]
	mov r10, #3
	str r10, [fp, #-1584]
	mov r10, r5
	str r10, [fp, #-1580]
	ldr r10, [fp, #-1580]
	ldr r4, [fp, #-1584]
	str r4, [fp, #-2228]
	ldr r4, [fp, #-2228]
	add r10, r4, r10
	str r10, [fp, #-1592]
	mov r10, #0
	mov32 r10, a3
	str r10, [fp, #-1588]
	ldr r10, [fp, #-1588]
	ldr r10, [r10, #0]
	str r10, [fp, #-1588]
	ldr r10, [fp, #-1588]
	str r10, [fp, #-1596]
	ldr r10, [fp, #-1592]
	ldr r4, [fp, #-1596]
	str r4, [fp, #-2232]
	ldr r4, [fp, #-2232]
	add r10, r10, r4
	str r10, [fp, #-1600]
	ldr r10, [fp, #-1600]
	str r10, [fp, #-1640]
	mov r10, #4
	str r10, [fp, #-1604]
	ldr r10, [fp, #-2244]
	str r10, [fp, #-1608]
	ldr r10, [fp, #-1604]
	ldr r4, [fp, #-1608]
	str r4, [fp, #-2236]
	ldr r4, [fp, #-2236]
	add r10, r10, r4
	str r10, [fp, #-1620]
	mov r10, #0
	mov32 r10, a4
	str r10, [fp, #-1612]
	ldr r10, [fp, #-1612]
	ldr r10, [r10, #0]
	str r10, [fp, #-1612]
	ldr r10, [fp, #-1612]
	str r10, [fp, #-1616]
	ldr r10, [fp, #-1616]
	ldr r4, [fp, #-1620]
	str r4, [fp, #-2240]
	ldr r4, [fp, #-2240]
	add r10, r4, r10
	str r10, [fp, #-1624]
	ldr r10, [fp, #-1624]
	str r10, [fp, #-1644]
	ldr r10, [fp, #-1628]
	add r7, r10, r7
	add r7, r7, r6
	mov r6, r5
	add r7, r7, r6
	ldr r6, [fp, #-2244]
	add r7, r7, r6
	ldr r6, [fp, #-1632]
	sub r7, r7, r6
	ldr r6, [fp, #-1636]
	sub r7, r7, r6
	ldr r6, [fp, #-1640]
	sub r7, r7, r6
	ldr r6, [fp, #-1644]
	sub r7, r7, r6
	ldr r6, [fp, #-1648]
	add r7, r7, r6
	ldr r6, [fp, #-1652]
	add r7, r7, r6
	ldr r6, [fp, #-1656]
	add r7, r7, r6
	ldr r6, [fp, #-1660]
	add r7, r7, r6
	ldr r6, [fp, #-1664]
	sub r7, r7, r6
	ldr r6, [fp, #-1668]
	sub r7, r7, r6
	ldr r6, [fp, #-1672]
	sub r7, r7, r6
	ldr r6, [fp, #-1676]
	sub r7, r7, r6
	ldr r6, [fp, #-1680]
	add r7, r7, r6
	ldr r6, [fp, #-1684]
	add r7, r7, r6
	ldr r6, [fp, #-1688]
	add r7, r7, r6
	ldr r6, [fp, #-1692]
	add r7, r7, r6
	ldr r6, [fp, #-1696]
	sub r7, r7, r6
	ldr r6, [fp, #-1700]
	sub r7, r7, r6
	ldr r6, [fp, #-1704]
	sub r7, r7, r6
	ldr r6, [fp, #-1708]
	sub r7, r7, r6
	ldr r6, [fp, #-1712]
	add r7, r7, r6
	ldr r6, [fp, #-1716]
	add r7, r7, r6
	ldr r6, [fp, #-1720]
	add r7, r7, r6
	ldr r6, [fp, #-1724]
	add r7, r7, r6
	sub r9, r7, r9
	sub r9, r9, r8
	ldr r8, [fp, #-1728]
	sub r9, r9, r8
	ldr r8, [fp, #-1732]
	sub r9, r9, r8
	ldr r8, [fp, #-1736]
	add r9, r9, r8
	ldr r8, [fp, #-1740]
	add r9, r9, r8
	ldr r8, [fp, #-1744]
	add r9, r9, r8
	ldr r8, [fp, #-1748]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a1
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a2
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a3
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a4
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a5
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a6
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a7
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a8
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a9
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a10
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a11
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a12
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a13
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a14
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a15
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a16
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a17
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a18
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a19
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a20
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a21
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a22
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a23
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a24
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a25
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a26
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a27
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a28
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a29
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a30
	ldr r8, [r8, #0]
	sub r9, r9, r8
	mov r8, #0
	mov32 r8, a31
	ldr r8, [r8, #0]
	add r9, r9, r8
	mov r8, #0
	mov32 r8, a32
	ldr r8, [r8, #0]
	sub r9, r9, r8
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
	bl getint
	mov r7, r0
	mov r9, r7
	mov r7, #2
	mov r6, #9
	mul r7, r7, r6
	add r7, r9, r7
	mov r8, r7
	mov r1, r8
	mov r0, r9
	bl func
	mov r9, r0
	mov r0, r9
	bl putint
	mov r8, r0
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640004948"