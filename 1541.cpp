#include <stdio.h>

int main() {
    char str[51];
    scanf("%s", str);

    int result = 0;
    int num = 0;
    int minus_flag = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0'); 
        } else if (str[i] == '+') {
            if (minus_flag)
                result -= num;
            else
                result += num;
            num = 0; 
        } else if (str[i] == '-') {
            if (minus_flag)
                result -= num;
            else
                result += num;
            num = 0;
            minus_flag = 1;
        }
    }

    if (minus_flag)
        result -= num;
    else
        result += num;

    printf("%d\n", result);
    return 0;
}
