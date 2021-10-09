.arch armv7-a
.arm

.global main
.type main, %function
.text
main:
    push {fp, lr}
    ldr r0, =format
    sub sp, sp, #4
    mov r1, sp
    bl  scanf
    ldr r3, [sp, #0]
    add sp, sp, #4

    sub r3, r3, #2
    mov r0, #1
    mov r1, #1
    mov r2, #1

LOOP:
    cmp r3 , #0
    ble END

    mov r0, r1
    mov r1, r2
    add r2, r0, r1
    
    sub r3, r3, #1
    b    LOOP
END:
    ldr r0, =output
    mov r1, r2
    bl  printf
    pop {fp, lr}
    bx lr
    

.data
format:
    .asciz "%d"

output:
    .asciz "result: %d \n"