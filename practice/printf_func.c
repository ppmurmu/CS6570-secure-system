#include <stdio.h>
#include <string.h>

static char s[1024] = "THIS IS A TOP SECRET MESSAGE!!!";

void main()
{
    char user_string[100];
    // printf("%08x\n", s);

    // memset(user_string, 0, sizeof(user_string));
    // /* user_string can be filled by other means as well such
    //    as by a network packet or a scanf */
    strcpy(user_string, "\x00\x10\x02\x0f %x %x %x %x %x %x %s");
    printf(user_string);
}
