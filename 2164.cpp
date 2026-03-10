#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int power = 1;
    while (power * 2 <= n) power *= 2;

    if (n == power) printf("%d\n", n);
    else printf("%d\n", 2 * (n - power));

    return 0;
}
