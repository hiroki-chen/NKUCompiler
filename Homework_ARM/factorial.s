	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"factorial.c"
	.text
	.align	2
	.global	factorial
	.arch armv4t
	.syntax unified
	.arm
	.fpu softvfp
	.type	factorial, %function
factorial:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #1
	beq	.L2
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L3
.L2:
	mov	r3, #1
	b	.L4
.L3:
	ldr	r3, [fp, #-8]
	sub	r3, r3, #1
	mov	r0, r3
	bl	factorial
	mov	r2, r0
	ldr	r3, [fp, #-8]
	mul	r3, r2, r3
.L4:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
	.size	factorial, .-factorial
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.07) 10.3.1 20210621 (release)"
