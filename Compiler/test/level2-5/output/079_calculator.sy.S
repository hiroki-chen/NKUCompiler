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
.globl ints
ints:
.space 40000

.globl intt
intt:
.word 0

.globl chas
chas:
.space 40000

.globl chat
chat:
.word 0

.globl i
i:
.word 0

.globl ii
ii:
.word 1

.globl c
c:
.word 0

.globl get
get:
.space 40000

.globl get2
get2:
.space 40000

.globl chapop
.type chapop, %function
chapop:
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
.LBchapop:
	mov r9, #0
	mov32 r9, chat
	ldr r9, [r9, #0]
	sub r9, r9, #1
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, chat
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, chat
	ldr r9, [r9, #0]
	add r9, r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #0
	mov32 r8, chas
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

.globl chapush
.type chapush, %function
chapush:
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
.LBchapush:
	mov r9, r0
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	add r8, r8, #1
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, chat
	str r8, [r7, #0]
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, chas
	str r9, [r7, r8]
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

.globl find
.type find, %function
find:
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
.LBfind:
	bl chapop
	mov r9, r0
	add sp, sp, #0
	mov r8, #0
	mov32 r8, c
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, c
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, ii
	ldr r9, [r9, #0]
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #0
	mov32 r8, get2
	mov r7, #32
	str r7, [r8, r9]
	mov r9, #0
	mov32 r9, ii
	ldr r9, [r9, #0]
	add r9, r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #0
	mov32 r8, get2
	mov r7, #0
	mov32 r7, c
	ldr r7, [r7, #0]
	str r7, [r8, r9]
	mov r9, #0
	mov32 r9, ii
	ldr r9, [r9, #0]
	add r9, r9, #2
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, ii
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, chat
	ldr r9, [r9, #0]
	mov r8, #0
	cmp r9, r8
	mov r9, #0
	moveq r9, #1
	mov r8, #0
	cmp r9, r8
	beq .LBB_find3_ELSE
	b .LBB_find3_IF
.LBB_find3_IF:
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
.LBB_find3_ELSE:
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

.globl getstr
.type getstr, %function
getstr:
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
.LBgetstr:
	mov r9, r0
	bl getch
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
	mov r7, #0
.LB_getstr2_LOOP_BEGIN:
	mov r6, #13
	cmp r8, r6
	mov r6, #0
	beq .LB_7_COND_END
	mov r5, #10
	cmp r8, r5
	mov r5, #0
	movne r5, #1
	mov r6, r5
.LB_7_COND_END:
	mov r5, #0
	cmp r6, r5
	beq .LB2_LOOP_END
	b .LB2_LOOP_BODY
.LB2_LOOP_BODY:
	mov r6, #4
	mov r6, r6
	mul r6, r7, r6
	mov r5, r9
	str r8, [r5, r6]
	add r6, r7, #1
	mov r7, r6
	bl getch
	mov r6, r0
	add sp, sp, #0
	mov r8, r6
	b .LB_getstr2_LOOP_BEGIN
.LB2_LOOP_END:
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

.globl intadd
.type intadd, %function
intadd:
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
.LBintadd:
	mov r9, r0
	mov r8, #0
	mov32 r8, intt
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, ints
	ldr r8, [r7, r8]
	mov r7, #10
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, intt
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, ints
	str r8, [r6, r7]
	mov r8, #0
	mov32 r8, intt
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, ints
	ldr r8, [r7, r8]
	mov r9, r9
	add r9, r8, r9
	mov r8, #0
	mov32 r8, intt
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, ints
	str r9, [r7, r8]
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

.globl intpop
.type intpop, %function
intpop:
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
.LBintpop:
	mov r9, #0
	mov32 r9, intt
	ldr r9, [r9, #0]
	sub r9, r9, #1
	mov r8, #0
	mov32 r8, intt
	ldr r8, [r8, #0]
	mov r9, r9
	mov r8, #0
	mov32 r8, intt
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, intt
	ldr r9, [r9, #0]
	add r9, r9, #1
	mov r8, #4
	mov r8, r8
	mul r9, r9, r8
	mov r8, #0
	mov32 r8, ints
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

.globl intpush
.type intpush, %function
intpush:
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
.LBintpush:
	mov r9, r0
	mov r8, #0
	mov32 r8, intt
	ldr r8, [r8, #0]
	add r8, r8, #1
	mov r7, #0
	mov32 r7, intt
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, intt
	str r8, [r7, #0]
	mov r8, #0
	mov32 r8, intt
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, ints
	str r9, [r7, r8]
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

.globl isdigit
.type isdigit, %function
isdigit:
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
.LBisdigit:
	mov r9, r0
	mov r8, #48
	cmp r9, r8
	mov r8, #0
	blt .LB_isdigit3_COND_END
	mov r7, #57
	cmp r9, r7
	mov r9, #0
	movle r9, #1
	mov r8, r9
.LB_isdigit3_COND_END:
	mov r9, #0
	cmp r8, r9
	beq .LBB_isdigit0_ELSE
	b .LBB_isdigit0_IF
.LBB_isdigit0_IF:
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
.LBB_isdigit0_ELSE:
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
	mov r8, #0
	sub sp, sp, r8
.LBmain:
	mov r9, #0
	mov32 r9, intt
	ldr r9, [r9, #0]
	mov r9, #0
	mov r8, #0
	mov32 r8, intt
	str r9, [r8, #0]
	mov r9, #0
	mov32 r9, chat
	ldr r9, [r9, #0]
	mov r9, #0
	mov r8, #0
	mov32 r8, chat
	str r9, [r8, #0]
	mov r8, #0
	mov32 r8, get
	mov r0, r8
	bl getstr
	mov r8, r0
	add sp, sp, #0
	mov r9, r8
.LB_main4_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	cmp r8, r9
	mov r8, #0
	movlt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB4_LOOP_END
	b .LB4_LOOP_BODY
.LB4_LOOP_BODY:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r0, r8
	bl isdigit
	mov r8, r0
	add sp, sp, #0
	mov r7, #1
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_5_ELSE
	b .LBB_5_IF
.LBB_5_IF:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, get2
	str r8, [r6, r7]
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	add r8, r8, #1
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, ii
	str r8, [r7, #0]
	b .LBB_5_END_IF
.LBB_5_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #40
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_6_ELSE
	b .LBB_6_IF
.LBB_6_IF:
	mov r0, #40
	bl chapush
	mov r8, r0
	add sp, sp, #0
.LBB_6_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #94
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_7_ELSE
	b .LBB_7_IF
.LBB_7_IF:
	mov r0, #94
	bl chapush
	mov r8, r0
	add sp, sp, #0
.LBB_7_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #41
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_8_ELSE
	b .LBB_8_IF
.LBB_8_IF:
	bl chapop
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	mov32 r7, c
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, c
	str r8, [r7, #0]
.LB_9_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, c
	ldr r8, [r8, #0]
	mov r7, #40
	cmp r8, r7
	mov r8, #0
	movne r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB9_LOOP_END
	b .LB9_LOOP_BODY
.LB9_LOOP_BODY:
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	mov r6, #32
	str r6, [r7, r8]
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	add r8, r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	mov r6, #0
	mov32 r6, c
	ldr r6, [r6, #0]
	str r6, [r7, r8]
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	add r8, r8, #2
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, ii
	str r8, [r7, #0]
	bl chapop
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	mov32 r7, c
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, c
	str r8, [r7, #0]
	b .LB_9_LOOP_BEGIN
.LB9_LOOP_END:
.LBB_8_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #43
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_10_ELSE
	b .LBB_10_IF
.LBB_10_IF:
.LB_11_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, chas
	ldr r8, [r7, r8]
	mov r7, #43
	cmp r8, r7
	mov r8, #1
	beq .LB55_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #45
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB55_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB53_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #42
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB53_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB51_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #47
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB51_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB49_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #37
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB49_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB47_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #94
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB47_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LB11_LOOP_END
	b .LB11_LOOP_BODY
.LB11_LOOP_BODY:
	bl find
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_12_ELSE
	b .LBB_12_IF
.LBB_12_IF:
	b .LB11_LOOP_END
.LBB_12_ELSE:
	b .LB_11_LOOP_BEGIN
.LB11_LOOP_END:
	mov r0, #43
	bl chapush
	mov r8, r0
	add sp, sp, #0
.LBB_10_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #45
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_13_ELSE
	b .LBB_13_IF
.LBB_13_IF:
.LB_14_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, chas
	ldr r8, [r7, r8]
	mov r7, #43
	cmp r8, r7
	mov r8, #1
	beq .LB95_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #45
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB95_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB93_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #42
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB93_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB91_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #47
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB91_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB89_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #37
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB89_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB87_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #94
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB87_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LB14_LOOP_END
	b .LB14_LOOP_BODY
.LB14_LOOP_BODY:
	bl find
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_15_ELSE
	b .LBB_15_IF
.LBB_15_IF:
	b .LB14_LOOP_END
.LBB_15_ELSE:
	b .LB_14_LOOP_BEGIN
.LB14_LOOP_END:
	mov r0, #45
	bl chapush
	mov r8, r0
	add sp, sp, #0
.LBB_13_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #42
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_16_ELSE
	b .LBB_16_IF
.LBB_16_IF:
.LB_17_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, chas
	ldr r8, [r7, r8]
	mov r7, #42
	cmp r8, r7
	mov r8, #1
	beq .LB131_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #47
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB131_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB129_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #37
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB129_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB127_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #94
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB127_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LB17_LOOP_END
	b .LB17_LOOP_BODY
.LB17_LOOP_BODY:
	bl find
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_18_ELSE
	b .LBB_18_IF
.LBB_18_IF:
	b .LB17_LOOP_END
.LBB_18_ELSE:
	b .LB_17_LOOP_BEGIN
.LB17_LOOP_END:
	mov r0, #42
	bl chapush
	mov r8, r0
	add sp, sp, #0
.LBB_16_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #47
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_19_ELSE
	b .LBB_19_IF
.LBB_19_IF:
.LB_20_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, chas
	ldr r8, [r7, r8]
	mov r7, #42
	cmp r8, r7
	mov r8, #1
	beq .LB159_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #47
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB159_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB157_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #37
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB157_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB155_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #94
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB155_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LB20_LOOP_END
	b .LB20_LOOP_BODY
.LB20_LOOP_BODY:
	bl find
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_21_ELSE
	b .LBB_21_IF
.LBB_21_IF:
	b .LB20_LOOP_END
.LBB_21_ELSE:
	b .LB_20_LOOP_BEGIN
.LB20_LOOP_END:
	mov r0, #47
	bl chapush
	mov r8, r0
	add sp, sp, #0
.LBB_19_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get
	ldr r8, [r7, r8]
	mov r7, #37
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_22_ELSE
	b .LBB_22_IF
.LBB_22_IF:
.LB_23_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, chas
	ldr r8, [r7, r8]
	mov r7, #42
	cmp r8, r7
	mov r8, #1
	beq .LB187_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #47
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB187_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB185_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #37
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB185_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB183_COND_END
	mov r7, #0
	mov32 r7, chat
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, chas
	ldr r7, [r6, r7]
	mov r6, #94
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB183_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LB23_LOOP_END
	b .LB23_LOOP_BODY
.LB23_LOOP_BODY:
	bl find
	mov r8, r0
	add sp, sp, #0
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	moveq r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_24_ELSE
	b .LBB_24_IF
.LBB_24_IF:
	b .LB23_LOOP_END
.LBB_24_ELSE:
	b .LB_23_LOOP_BEGIN
.LB23_LOOP_END:
	mov r0, #37
	bl chapush
	mov r8, r0
	add sp, sp, #0
.LBB_22_ELSE:
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	mov r6, #32
	str r6, [r7, r8]
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	add r8, r8, #1
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, ii
	str r8, [r7, #0]
	b .LBB_5_END_IF
.LBB_5_END_IF:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	add r8, r8, #1
	mov r7, #0
	mov32 r7, i
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, i
	str r8, [r7, #0]
	b .LB_main4_LOOP_BEGIN
.LB4_LOOP_END:
.LB_25_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, chat
	ldr r8, [r8, #0]
	mov r7, #0
	cmp r8, r7
	mov r8, #0
	movgt r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB25_LOOP_END
	b .LB25_LOOP_BODY
.LB25_LOOP_BODY:
	bl chapop
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, get2
	mov r5, #32
	str r5, [r6, r7]
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	add r7, r7, #1
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, get2
	str r8, [r6, r7]
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	add r8, r8, #2
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, ii
	str r8, [r7, #0]
	b .LB_25_LOOP_BEGIN
.LB25_LOOP_END:
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	mov r6, #64
	str r6, [r7, r8]
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r8, #1
	mov r7, #0
	mov32 r7, i
	str r8, [r7, #0]
.LB_26_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	ldr r8, [r7, r8]
	mov r7, #64
	cmp r8, r7
	mov r8, #0
	movne r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB26_LOOP_END
	b .LB26_LOOP_BODY
.LB26_LOOP_BODY:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	ldr r8, [r7, r8]
	mov r7, #43
	cmp r8, r7
	mov r8, #1
	beq .LB238_COND_END
	mov r7, #0
	mov32 r7, i
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, get2
	ldr r7, [r6, r7]
	mov r6, #45
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB238_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB236_COND_END
	mov r7, #0
	mov32 r7, i
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, get2
	ldr r7, [r6, r7]
	mov r6, #42
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB236_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB234_COND_END
	mov r7, #0
	mov32 r7, i
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, get2
	ldr r7, [r6, r7]
	mov r6, #47
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB234_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB232_COND_END
	mov r7, #0
	mov32 r7, i
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, get2
	ldr r7, [r6, r7]
	mov r6, #37
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB232_COND_END:
	mov r7, #0
	cmp r8, r7
	mov r8, #1
	bne .LB230_COND_END
	mov r7, #0
	mov32 r7, i
	ldr r7, [r7, #0]
	mov r6, #4
	mov r6, r6
	mul r7, r7, r6
	mov r6, #0
	mov32 r6, get2
	ldr r7, [r6, r7]
	mov r6, #94
	cmp r7, r6
	mov r7, #0
	moveq r7, #1
	mov r8, r7
.LB230_COND_END:
	mov r7, #0
	cmp r8, r7
	beq .LBB_27_ELSE
	b .LBB_27_IF
.LBB_27_IF:
	bl intpop
	mov r7, r0
	add sp, sp, #0
	mov r8, r7
	bl intpop
	mov r6, r0
	add sp, sp, #0
	mov r7, r6
	mov r5, #0
	mov32 r5, i
	ldr r5, [r5, #0]
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, get2
	ldr r5, [r10, r5]
	mov r10, #43
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_28_ELSE
	b .LBB_28_IF
.LBB_28_IF:
	mov r5, r7
	add r5, r8, r5
	mov r6, r5
.LBB_28_ELSE:
	mov r5, #0
	mov32 r5, i
	ldr r5, [r5, #0]
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, get2
	ldr r5, [r10, r5]
	mov r10, #45
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_29_ELSE
	b .LBB_29_IF
.LBB_29_IF:
	mov r5, r8
	sub r5, r7, r5
	mov r6, r5
.LBB_29_ELSE:
	mov r5, #0
	mov32 r5, i
	ldr r5, [r5, #0]
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, get2
	ldr r5, [r10, r5]
	mov r10, #42
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_30_ELSE
	b .LBB_30_IF
.LBB_30_IF:
	mov r5, r7
	mul r5, r8, r5
	mov r6, r5
.LBB_30_ELSE:
	mov r5, #0
	mov32 r5, i
	ldr r5, [r5, #0]
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, get2
	ldr r5, [r10, r5]
	mov r10, #47
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_31_ELSE
	b .LBB_31_IF
.LBB_31_IF:
	mov r5, r0
	mov r10, r1
	mov r0, r7
	mov r1, r8
	bl __aeabi_idiv
	mov r4, r0
	mov r0, r5
	mov r1, r10
	mov r6, r4
.LBB_31_ELSE:
	mov r5, #0
	mov32 r5, i
	ldr r5, [r5, #0]
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, get2
	ldr r5, [r10, r5]
	mov r10, #37
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_32_ELSE
	b .LBB_32_IF
.LBB_32_IF:
	mov r5, r0
	mov r10, r1
	mov r0, r7
	mov r1, r8
	bl __aeabi_idivmod
	mov r4, r1
	mov r0, r5
	mov r1, r10
	mov r6, r4
.LBB_32_ELSE:
	mov r5, #0
	mov32 r5, i
	ldr r5, [r5, #0]
	mov r10, #4
	mov r10, r10
	mul r5, r5, r10
	mov r10, #0
	mov32 r10, get2
	ldr r5, [r10, r5]
	mov r10, #94
	cmp r5, r10
	mov r5, #0
	moveq r5, #1
	mov r10, #0
	cmp r5, r10
	beq .LBB_33_ELSE
	b .LBB_33_IF
.LBB_33_IF:
	mov r1, r8
	mov r0, r7
	bl power
	mov r5, r0
	add sp, sp, #0
	mov r6, r5
.LBB_33_ELSE:
	mov r0, r6
	bl intpush
	mov r8, r0
	add sp, sp, #0
	b .LBB_27_END_IF
.LBB_27_ELSE:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	ldr r8, [r7, r8]
	mov r7, #32
	cmp r8, r7
	mov r8, #0
	movne r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LBB_34_ELSE
	b .LBB_34_IF
.LBB_34_IF:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	ldr r8, [r7, r8]
	sub r8, r8, #48
	mov r0, r8
	bl intpush
	mov r8, r0
	add sp, sp, #0
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	mov r8, #1
	mov r7, #0
	mov32 r7, ii
	str r8, [r7, #0]
.LB_35_LOOP_BEGIN:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r7, r7
	add r8, r8, r7
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	ldr r8, [r7, r8]
	mov r7, #32
	cmp r8, r7
	mov r8, #0
	movne r8, #1
	mov r7, #0
	cmp r8, r7
	beq .LB35_LOOP_END
	b .LB35_LOOP_BODY
.LB35_LOOP_BODY:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r7, r7
	add r8, r8, r7
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, get2
	ldr r8, [r7, r8]
	sub r8, r8, #48
	mov r0, r8
	bl intadd
	mov r8, r0
	add sp, sp, #0
	mov r8, #0
	mov32 r8, ii
	ldr r8, [r8, #0]
	add r8, r8, #1
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, ii
	str r8, [r7, #0]
	b .LB_35_LOOP_BEGIN
.LB35_LOOP_END:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	mov r7, #0
	mov32 r7, ii
	ldr r7, [r7, #0]
	mov r7, r7
	add r8, r8, r7
	sub r8, r8, #1
	mov r7, #0
	mov32 r7, i
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, i
	str r8, [r7, #0]
.LBB_34_ELSE:
	b .LBB_27_END_IF
.LBB_27_END_IF:
	mov r8, #0
	mov32 r8, i
	ldr r8, [r8, #0]
	add r8, r8, #1
	mov r7, #0
	mov32 r7, i
	ldr r7, [r7, #0]
	mov r8, r8
	mov r7, #0
	mov32 r7, i
	str r8, [r7, #0]
	b .LB_26_LOOP_BEGIN
.LB26_LOOP_END:
	mov r8, #1
	mov r7, #4
	mov r7, r7
	mul r8, r8, r7
	mov r7, #0
	mov32 r7, ints
	ldr r8, [r7, r8]
	mov r0, r8
	bl putint
	mov r8, r0
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

.globl power
.type power, %function
power:
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
.LBpower:
	mov r9, r0
	mov r8, r1
	mov r7, #1
.LB_power1_LOOP_BEGIN:
	mov r6, #0
	cmp r8, r6
	mov r6, #0
	movne r6, #1
	mov r5, #0
	cmp r6, r5
	beq .LB1_LOOP_END
	b .LB1_LOOP_BODY
.LB1_LOOP_BODY:
	mov r6, r9
	mul r6, r7, r6
	mov r7, r6
	sub r6, r8, #1
	mov r8, r6
	b .LB_power1_LOOP_BEGIN
.LB1_LOOP_END:
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

.ident "@ Generated by Takanashi Compiler © Haobin Chen & Jiawei Xu 1640007223"