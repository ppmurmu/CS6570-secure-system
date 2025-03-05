#include "out.h"

void processEntry _start(undefined4 param_1, undefined4 param_2)

{
    undefined auStack_4[4];

    __libc_start_main(main, param_2, &stack0x00000004, __libc_csu_init, __libc_csu_fini, param_1, auStack_4);
    do
    {
        // WARNING: Do nothing block with infinite loop
    } while (true);
}

// WARNING: This is an inlined function

void __x86_get_pc_thunk_bx(void)

{
    return;
}

// WARNING: Removing unreachable block (ram,0x0040fe9f)
// WARNING: Removing unreachable block (ram,0x0040fea8)

void deregister_tm_clones(void)

{
    return;
}

// WARNING: Removing unreachable block (ram,0x0040fed8)
// WARNING: Removing unreachable block (ram,0x0040fee1)

void register_tm_clones(void)

{
    return;
}

void __do_global_dtors_aux(void)

{
    if (completed_7209 == '\0')
    {
        deregister_tm_clones();
        completed_7209 = '\x01';
    }
    return;
}

// WARNING: Removing unreachable block (ram,0x0040ff39)
// WARNING: Removing unreachable block (ram,0x0040ff30)

void frame_dummy(void)

{
    register_tm_clones();
    return;
}

// WARNING: Unknown calling convention

void kill_on_timeout(int sig)

{
    if (sig == 0xe)
    {
        printf("[!] Anti DoS Signal.");
        // WARNING: Subroutine does not return
        exit(0);
    }
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

void ignore_me_init_signal(void)

{
    signal(0xe, kill_on_timeout);
    alarm(0xb4);
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

void ignore_me_init_buffering(void)

{
    setvbuf(stdout, (char *)0x0, 2, 0);
    setvbuf(stdin, (char *)0x0, 2, 0);
    setvbuf(stderr, (char *)0x0, 2, 0);
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

void banner(void)

{
    char *BANNER;

    printf("\x1b[1;32m%s\n\n\x1b[0m", &DAT_00410240);
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

void command(void)

{
    undefined4 uVar1;
    char buf[32];
    void *printf_fp;
    link_map *lm;

    uVar1 = dlopen("libc.so.6", 2);
    uVar1 = dlsym(uVar1, "printf");
    printf("Printf address: %p\n", uVar1);
    printf("Which spell do you want to cast: ");
    __isoc99_scanf(&DAT_004106a6, buf);
    printf("(Also there is something useful here)%s ", shell);
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

void start(void)

{
    char username[32];

    printf("What is your name? ");
    __isoc99_scanf(&DAT_004106a6, username);
    printf("Welcome to Hogwarts %32s\n", username);
    if (root == 0)
    {
        puts("Slytherrin wins the House cup.");
    }
    else
    {
        puts("Welcome Dumbledore...");
        puts("Wait, you don\'t look like Dumbledore.");
        puts("But since you reached here, you might be him.");
        puts("God know what kind of spells exist these days.");
        puts("So for the House cup this year, Slytherrin is 1st with 480 points.");
        printf("and Gryffindor is 4th with 380 points.");
        puts("You can award some points to Gryffindor ");
        puts("Here are 5 points");
        command();
    }
    return;
}

// WARNING: Unknown calling convention

int main(int argc, char **argv)

{
    ignore_me_init_buffering();
    ignore_me_init_signal();
    banner();
    start();
    return 0;
}

// WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx

void __libc_csu_init(undefined4 param_1, undefined4 param_2, undefined4 param_3)

{
    int iVar1;
    EVP_PKEY_CTX *in_stack_ffffffe4;

    _init(in_stack_ffffffe4);
    iVar1 = 0;
    do
    {
        (*(code *)(&__frame_dummy_init_array_entry)[iVar1])(param_1, param_2, param_3);
        iVar1 = iVar1 + 1;
    } while (iVar1 != 1);
    return;
}

void __libc_csu_fini(void)

{
    return;
}

// WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx

void _fini(void)

{
    return;
}

// WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx

int _init(EVP_PKEY_CTX *ctx)

{
    int iVar1;

    iVar1 = __gmon_start__();
    return iVar1;
}

void FUN_08048550(void)

{
    (*(code *)(undefined *)0x0)();
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format, ...)

{
    int iVar1;

    iVar1 = printf(__format);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

__sighandler_t signal(int __sig, __sighandler_t __handler)

{
    __sighandler_t p_Var1;

    p_Var1 = signal(__sig, __handler);
    return p_Var1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

uint alarm(uint __seconds)

{
    uint uVar1;

    uVar1 = alarm(__seconds);
    return uVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)

{
    int iVar1;

    iVar1 = puts(__s);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)

{
    // WARNING: Subroutine does not return
    exit(__status);
}

void __libc_start_main(void)

{
    __libc_start_main();
    return;
}

void dlsym(void)

{
    dlsym();
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int setvbuf(FILE *__stream, char *__buf, int __modes, size_t __n)

{
    int iVar1;

    iVar1 = setvbuf(__stream, __buf, __modes, __n);
    return iVar1;
}

void __isoc99_scanf(void)

{
    __isoc99_scanf();
    return;
}

void dlopen(void)

{
    dlopen();
    return;
}

void __gmon_start__(void)

{
    __gmon_start__();
    return;
}
