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
	mov r8, #0
	sub sp, sp, r8
.LBmain:
	bl getint
	mov r8, r0
	mov r9, r8
	sub sp, sp, #100
.LB_main3_LOOP_BEGIN:
	mov r8, #0
	cmp r9, r8
	mov r8, #0
	movgt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB3_LOOP_END
	b .LB3_LOOP_BODY
.LB3_LOOP_BODY:
	mov r8, #0
.LB_4_LOOP_BEGIN:
	mov r7, #5
	cmp r8, r7
	mov r7, #0
	movlt r7, #1
	mov r6, #0
	cmp r7, r6
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r7, #0
.LB_5_LOOP_BEGIN:
	mov r6, #5
	cmp r7, r6
	mov r6, #0
	movlt r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB5_LOOP_END
	b .LB5_LOOP_BODY
.LB5_LOOP_BODY:
	bl getint
	mov r6, r0
	mov r5, #4
	mul r5, r7, r5
	mov r10, #20
	mov r4, r8
	mul r10, r10, r4
	add r5, r5, r10
	mov r10, sp
	str r6, [r10, r5]
	add r6, r7, #1
	mov r7, r6
	b .LB_5_LOOP_BEGIN
.LB5_LOOP_END:
	add r7, r8, #1
	mov r8, r7
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	mov r0, r8
	bl model
	mov r8, r0
	mov r7, #0
	cmp r8, r7
	beq .LBB_6_ELSE
	b .LBB_6_IF
.LBB_6_IF:
	mov r0, #99
	bl putch
	mov r8, r0
	mov r0, #97
	bl putch
	mov r8, r0
	mov r0, #116
	bl putch
	mov r8, r0
	mov r0, #10
	bl putch
	mov r8, r0
	b .LBB_6_END_IF
.LBB_6_ELSE:
	mov r0, #100
	bl putch
	mov r8, r0
	mov r0, #111
	bl putch
	mov r8, r0
	mov r0, #103
	bl putch
	mov r8, r0
	mov r0, #10
	bl putch
	mov r8, r0
	b .LBB_6_END_IF
.LBB_6_END_IF:
	sub r8, r9, #1
	mov r9, r8
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

.globl model
.type model, %function
model:
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
.LBmodel:
	mov r9, r0
	mov r8, #0
	mov r7, #4
	mul r8, r8, r7
	mov r7, #20
	mov r6, #0
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, r9
	ldr r8, [r7, r8]
	mov r7, #85
	mul r8, r8, r7
	mov r7, #1
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #23
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #82
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #103
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #123
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #64
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #1
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #120
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #50
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #59
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #47
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #111
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #1
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #67
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #106
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #75
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #102
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #34
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #1
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #39
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #65
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #47
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #113
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #110
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #1
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #47
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #4
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #80
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #46
	mul r7, r7, r6
	add r8, r8, r7
	mov r0, r8
	bl relu_reg
	mov r8, r0
	mov r7, #39
	mul r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #106
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #126
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #18
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #31
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #8
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #47
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #4
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #67
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #94
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #121
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #7
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #21
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #60
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #43
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #105
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #42
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #87
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #29
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #106
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #31
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #110
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #100
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #22
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #75
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #125
	mul r6, r6, r5
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	mov r6, #77
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #26
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #76
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #70
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #29
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #95
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #96
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #52
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #68
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #5
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #34
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #34
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #102
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #6
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #38
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #27
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #110
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #116
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #39
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #63
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #99
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #65
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #120
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #39
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #6
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #94
	mul r6, r6, r5
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	mov r6, #127
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #23
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #63
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #49
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #50
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #72
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #85
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #30
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #12
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #125
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #117
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #65
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #67
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #125
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #110
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #31
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #123
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #83
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #122
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #11
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #23
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #47
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #32
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #117
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #95
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #118
	mul r6, r6, r5
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	mov r6, #0
	sub r6, r6, #106
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #8
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #82
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #104
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #101
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #116
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #63
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #16
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #70
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #125
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #75
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #66
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #96
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #101
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #114
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #59
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #12
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #5
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #95
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #116
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #93
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #15
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #79
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #3
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #49
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #124
	mul r6, r6, r5
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	mov r6, #0
	sub r6, r6, #3
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #81
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #68
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #102
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #74
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #121
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #15
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #55
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #101
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #13
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #62
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #64
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #114
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #38
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #21
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #112
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #114
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #112
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #10
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #16
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #50
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #112
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #116
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #54
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #82
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #72
	mul r6, r6, r5
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	mov r6, #32
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #15
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #77
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #66
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #90
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #6
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #30
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #8
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #81
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #2
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #110
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #95
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #59
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #52
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #15
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #55
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #33
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #14
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #58
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #67
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #86
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #79
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #48
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #13
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #15
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #66
	mul r6, r6, r5
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	mov r6, #0
	sub r6, r6, #95
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #33
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #82
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #67
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #30
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #2
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #65
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #120
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #13
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #18
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #5
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #104
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #119
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #7
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #71
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #107
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #24
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #82
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #96
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #104
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #121
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #65
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #97
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #83
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #46
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #84
	mul r6, r6, r5
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	mov r6, #0
	sub r6, r6, #50
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #29
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #7
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #70
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #38
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #90
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #15
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #32
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #37
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #36
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #62
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #125
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #46
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #70
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #37
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #73
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #34
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #87
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #75
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #71
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #77
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #53
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #37
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #103
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #13
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #114
	mul r6, r6, r5
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	mov r6, #0
	sub r6, r6, #23
	mul r7, r7, r6
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #67
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #42
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #41
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #123
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #92
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #10
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #77
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #75
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #96
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #51
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #109
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #74
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #7
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #122
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #67
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #47
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #22
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #68
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #38
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #29
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #115
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #121
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #36
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #49
	mul r6, r6, r5
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mul r5, r5, r10
	add r6, r6, r5
	ldr r9, [r9, r6]
	mov r6, #85
	mul r9, r9, r6
	add r9, r7, r9
	mov r0, r9
	bl relu_reg
	mov r9, r0
	mov r7, #46
	mul r9, r9, r7
	add r9, r8, r9
	mov r8, #0
	cmp r9, r8
	mov r9, #0
	movgt r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_model2_ELSE
	b .LBB_model2_IF
.LBB_model2_IF:
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
.LBB_model2_ELSE:
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

.globl relu_reg
.type relu_reg, %function
relu_reg:
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
.LBrelu_reg:
	mov r9, r0
	mov r8, #127
	cmp r9, r8
	mov r8, #0
	movgt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_relu_reg0_ELSE
	b .LBB_relu_reg0_IF
.LBB_relu_reg0_IF:
	mov r0, #127
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
.LBB_relu_reg0_ELSE:
	mov r8, #0
	cmp r9, r8
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_relu_reg1_ELSE
	b .LBB_relu_reg1_IF
.LBB_relu_reg1_IF:
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
.LBB_relu_reg1_ELSE:
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640004946"