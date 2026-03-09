#include <stdio.h>
#include <string.h>

int main() {
    int M, x;
    char cmd[10];
    int bit = 0;  

    scanf("%d", &M);

    while (M--) {
        scanf("%s", cmd);

        if (!strcmp(cmd, "add")) {
            scanf("%d", &x);
            bit |= (1 << (x - 1));
        }
        else if (!strcmp(cmd, "remove")) {
            scanf("%d", &x);
            bit &= ~(1 << (x - 1));
        }
        else if (!strcmp(cmd, "check")) {
            scanf("%d", &x);
            printf("%d\n", (bit & (1 << (x - 1))) ? 1 : 0);
        }
        else if (!strcmp(cmd, "toggle")) {
            scanf("%d", &x);
            bit ^= (1 << (x - 1));
        }
        else if (!strcmp(cmd, "all")) {
            bit = (1 << 20) - 1;  
        }
        else if (!strcmp(cmd, "empty")) {
            bit = 0;
        }
    }

    return 0;
}
