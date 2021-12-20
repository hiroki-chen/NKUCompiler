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
	add sp, sp, #0
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
	add sp, sp, #0
	mov r5, #4
	mov r5, r5
	mul r5, r7, r5
	mov r10, #20
	mov r4, r8
	mul r10, r10, r4
	mov r10, r10
	add r5, r5, r10
	mov r10, sp
	add r10, r10, #0
	str r6, [r10, r5]
	add r6, r7, #1
	mov r7, r6
	b .LB_5_LOOP_BEGIN
.LB5_LOOP_END:
	add r7, r8, #1
	mov r8, r7
	b .LB_4_LOOP_BEGIN
.LB4_LOOP_END:
	add r8, sp, #0
	mov r0, r8
	bl model
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	cmp r8, r7
	beq .LBB_6_ELSE
	b .LBB_6_IF
.LBB_6_IF:
	mov r0, #99
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r0, #97
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r0, #116
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r8, r0
	add sp, sp, #0
	b .LBB_6_END_IF
.LBB_6_ELSE:
	mov r0, #100
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r0, #111
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r0, #103
	bl putch
	mov r8, r0
	add sp, sp, #0
	mov r0, #10
	bl putch
	mov r8, r0
	add sp, sp, #0
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
	mov r7, r7
	mul r8, r8, r7
	mov r7, #20
	mov r6, #0
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, r9
	ldr r8, [r7, r8]
	mov r7, #85
	mov r7, r7
	mul r8, r8, r7
	mov r7, #1
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #23
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #82
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #103
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #123
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #64
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #1
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #120
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #50
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #59
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #1
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #47
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #111
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #1
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #67
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #106
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #75
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #2
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #102
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #34
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #1
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #39
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #65
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #47
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #3
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #113
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #110
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #1
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #47
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #2
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #3
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #80
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #4
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #46
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r0, r8
	bl relu_reg
	mov r8, r0
	add sp, sp, #0
	mov r7, #39
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #106
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #126
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #18
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #31
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #8
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #47
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #67
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #94
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #121
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #7
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #21
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #60
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #43
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #105
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #42
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #87
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #29
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #106
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #31
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #110
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #100
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #22
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #75
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #125
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	add sp, sp, #0
	mov r6, #77
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #26
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #76
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #70
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #29
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #95
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #96
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #52
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #68
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #5
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #34
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #34
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #102
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #6
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #38
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #27
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #110
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #116
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #39
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #63
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #99
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #65
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #120
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #39
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #6
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #94
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	add sp, sp, #0
	mov r6, #127
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #23
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #63
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #49
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #50
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #72
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #85
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #30
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #12
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #125
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #117
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #65
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #67
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #125
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #110
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #31
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #123
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #83
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #122
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #11
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #23
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #47
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #32
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #117
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #95
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #118
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	add sp, sp, #0
	mov r6, #0
	sub r6, r6, #106
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #8
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #82
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #104
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #101
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #116
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #63
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #16
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #70
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #125
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #75
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #66
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #96
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #101
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #114
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #59
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #12
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #5
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #95
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #116
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #93
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #15
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #79
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #3
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #49
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #124
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	add sp, sp, #0
	mov r6, #0
	sub r6, r6, #3
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #81
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #68
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #102
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #74
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #121
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #15
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #55
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #101
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #13
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #62
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #64
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #114
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #38
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #21
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #112
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #114
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #112
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #10
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #16
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #50
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #112
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #116
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #54
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #82
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #72
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	add sp, sp, #0
	mov r6, #32
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #15
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #77
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #66
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #90
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #6
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #30
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #8
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #81
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #2
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #110
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #95
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #59
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #52
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #15
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #55
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #33
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #14
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #58
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #67
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #86
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #79
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #48
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #13
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #15
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #66
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	add sp, sp, #0
	mov r6, #0
	sub r6, r6, #95
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #33
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #82
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #67
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #30
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #2
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #65
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #120
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #13
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #18
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #5
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #104
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #119
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #7
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #71
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #107
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #24
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #82
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #96
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #104
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #121
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #65
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #97
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #83
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #46
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #84
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	add sp, sp, #0
	mov r6, #0
	sub r6, r6, #50
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #0
	sub r6, r6, #29
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #7
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #70
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #38
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #90
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #15
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #32
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #37
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #36
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #62
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #125
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #46
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #70
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #37
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #73
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #34
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #87
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #75
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #71
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #77
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #53
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #37
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #103
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #13
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #114
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r0, r7
	bl relu_reg
	mov r7, r0
	add sp, sp, #0
	mov r6, #0
	sub r6, r6, #23
	mov r6, r6
	mul r7, r7, r6
	mov r7, r7
	add r8, r8, r7
	mov r7, #0
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #20
	mov r5, #0
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, r9
	ldr r7, [r6, r7]
	mov r6, #67
	mov r6, r6
	mul r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #42
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #41
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #123
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #0
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #92
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #10
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #77
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #75
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #96
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #1
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #51
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #109
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #74
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #7
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #122
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #2
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #67
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #47
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #22
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #68
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #38
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #3
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #29
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #0
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #115
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #1
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #121
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #2
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #36
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #3
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r5, r9
	ldr r6, [r5, r6]
	mov r5, #0
	sub r5, r5, #49
	mov r5, r5
	mul r6, r6, r5
	mov r6, r6
	add r7, r7, r6
	mov r6, #4
	mov r5, #4
	mov r5, r5
	mul r6, r6, r5
	mov r5, #20
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r5, r5
	add r6, r6, r5
	mov r9, r9
	ldr r9, [r9, r6]
	mov r6, #85
	mov r6, r6
	mul r9, r9, r6
	mov r9, r9
	add r9, r7, r9
	mov r0, r9
	bl relu_reg
	mov r9, r0
	add sp, sp, #0
	mov r7, #46
	mov r7, r7
	mul r9, r9, r7
	mov r9, r9
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007383"