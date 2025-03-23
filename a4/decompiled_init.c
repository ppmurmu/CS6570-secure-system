#include "out.h"

int _init(EVP_PKEY_CTX *ctx)

{
    int iVar1;

    iVar1 = __gmon_start__();
    return iVar1;
}

void FUN_00101020(void)

{
    (*(code *)(undefined *)0x0)();
    return;
}

void FUN_001010b0(void)

{
    __cxa_finalize();
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)

{
    int iVar1;

    iVar1 = puts(__s);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char *__s)

{
    size_t sVar1;

    sVar1 = strlen(__s);
    return sVar1;
}

void __stack_chk_fail(void)

{
    // WARNING: Subroutine does not return
    __stack_chk_fail();
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format, ...)

{
    int iVar1;

    iVar1 = printf(__format);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

char *fgets(char *__s, int __n, FILE *__stream)

{
    char *pcVar1;

    pcVar1 = fgets(__s, __n, __stream);
    return pcVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int setvbuf(FILE *__stream, char *__buf, int __modes, size_t __n)

{
    int iVar1;

    iVar1 = setvbuf(__stream, __buf, __modes, __n);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

FILE *fopen(char *__filename, char *__modes)

{
    FILE *pFVar1;

    pFVar1 = fopen(__filename, __modes);
    return pFVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)

{
    // WARNING: Subroutine does not return
    exit(__status);
}

void processEntry _start(undefined8 param_1, undefined8 param_2)

{
    undefined1 auStack_8[8];

    __libc_start_main(main, param_2, &stack0x00000008, __libc_csu_init, __libc_csu_fini, param_1, auStack_8);
    do
    {
        // WARNING: Do nothing block with infinite loop
    } while (true);
}

// WARNING: Removing unreachable block (ram,0x00101183)
// WARNING: Removing unreachable block (ram,0x0010118f)

void deregister_tm_clones(void)

{
    return;
}

// WARNING: Removing unreachable block (ram,0x001011c4)
// WARNING: Removing unreachable block (ram,0x001011d0)

void register_tm_clones(void)

{
    return;
}

void __do_global_dtors_aux(void)

{
    if (completed_8055 != '\0')
    {
        return;
    }
    FUN_001010b0(__dso_handle);
    deregister_tm_clones();
    completed_8055 = 1;
    return;
}

void frame_dummy(void)

{
    register_tm_clones();
    return;
}

bool main(void)

{
    int extraout_EAX;
    int __edflag;
    long in_FS_OFFSET;
    char local_38[40];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    setvbuf(stdout, (char *)0x0, 2, 0);
    puts("Give me a key!");
    __edflag = 0x1e;
    fgets(local_38, 0x1e, stdin);
    encrypt(local_38, __edflag);
    if (extraout_EAX == 0)
    {
        puts("That\'s not it!");
    }
    else
    {
        print_flag();
    }
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28))
    {
        // WARNING: Subroutine does not return
        __stack_chk_fail();
    }
    return extraout_EAX == 0;
}

void encrypt(char *__block, int __edflag)

{
    size_t sVar1;
    int local_20;

    local_20 = 0;
    while ((sVar1 = strlen(secret), (ulong)(long)local_20 < sVar1 &&
                                        ((__block[local_20] * 8 + 0x13) % 0x3d + 0x41 == (int)(char)secret[local_20])))
    {
        local_20 = local_20 + 1;
    }
    return;
}

void print_flag(void)

{
    FILE *__stream;
    long in_FS_OFFSET;
    char local_118[264];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    __stream = fopen("flag.txt", "r");
    if (__stream == (FILE *)0x0)
    {
        puts("Too bad you can only run this exploit on the server...");
        // WARNING: Subroutine does not return
        exit(0);
    }
    fgets(local_118, 0x100, __stream);
    printf("%s", local_118);
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28))
    {
        // WARNING: Subroutine does not return
        __stack_chk_fail();
    }
    return;
}

void __libc_csu_init(EVP_PKEY_CTX *param_1, undefined8 param_2, undefined8 param_3)

{
    long lVar1;

    _init(param_1);
    lVar1 = 0;
    do
    {
        (*(code *)(&__frame_dummy_init_array_entry)[lVar1])((ulong)param_1 & 0xffffffff, param_2, param_3);
        lVar1 = lVar1 + 1;
    } while (lVar1 != 1);
    return;
}

void __libc_csu_fini(void)

{
    return;
}

void _fini(void)

{
    return;
}
