#include <stdio.h>
#include <string.h>

char str[105];

char stack[105];

int main() {

    while (1) {

        fgets(str, 105, stdin);

        if (strcmp(str, ".\n") == 0) break;

        int top = 0, ok = 1;

        for (int i = 0; str[i]; i++) {

            if (str[i] == '(' || str[i] == '[')

                stack[top++] = str[i];

            else if (str[i] == ')') {

                if (top == 0 || stack[top - 1] != '(') {

                    ok = 0;

                    break;

                }

                top--;

            }

            else if (str[i] == ']') {

                if (top == 0 || stack[top - 1] != '[') {

                    ok = 0;

                    break;

                }

                top--;

            }

        }

        if (ok && top == 0)

            printf("yes\n");

        else

            printf("no\n");

    }

    return 0;

}

