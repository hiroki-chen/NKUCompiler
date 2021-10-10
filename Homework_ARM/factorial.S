@ 定义目标架构为 ARM 平台
.arch armv7-a
.arm

.text
@ 定义字段对齐长度为1
.align 1

@ 定义一个全局名称（函数名）
.global factorial
@ factorial是一个函数类型，而非变量
.type factorial %function
@ 文件名为factorial
.file "factorial.sy"

.syntax unified

.fpu vfpv3-d16

factorial:
    @ 函数原型是 int factorial(int number)
    @ 递归函数入口 factorial
    @ 需要利用寄存器 sp 和 bp 为函数开辟栈上空间，用来存一些临时变量等。
    @ ---------
    @ arg0      <----- fp - 8
    @ ---------
    @ ret地址
    @ --------- 
    @ XXXX      <--- fp
    @ --------- 

    @ 备份上一个函数的栈帧情况，并保存返回地址到栈上
    push { fp, lr }
    
    @ 因为push过一次，sp多减了一个，所以本函数的栈帧指针寄存器fp = sp + 4
    add fp, sp, #4
    @ 开辟两个变量的空间作返回值。
    sub sp, sp, #8
    
    @ 保存参数number，后续可能会修改，需要从栈上去取
    str r0, [fp, #-8]

    @ if else语句
    ldr r3, [fp, #-8]
    cmp r3, #1
    beq branch1
    ldr r3, [fp, #-8]
    cmp r3, #0
    bne branch2

@ branch1 对应的是number == 1 || number == 0 
@ -> return 1 (r3)
@ factorial不允许随便跳转到branch1 :))
branch1:
    mov r3, #1
    b end

@ branch2 对应
branch2:
    ldr r3, [fp, #-8]
    sub r3, r3, #1
    
    @ 改变一下arg0并递归调用
    mov r0, r3
    bl factorial

    @ 计算上一个factorial返回的值和当前值的成绩，然后保存
    mov r8, r0
    ldr r3, [fp, #-8] @ 上个函数已经修改了 :)
    mul r3, r8, r3 @ r3将在end处使用到

@ 函数返回
end:
    mov r0, r3
    sub sp, fp, #4
    pop { fp, lr }
    bx lr
    .size	factorial, .-factorial
