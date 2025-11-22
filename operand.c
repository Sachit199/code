#include <stdio.h>

int main() {
    int a = 0;

    if (!a) {
        printf("Condition yielded True\n");
    } else {
        printf("Condition yielded False\n");
    }

    a = 1;
    if (!a) {
        printf("Condition yielded True\n");
    } else {
        printf("Condition yielded False\n");
    }

    return 0;
}
