#include <stdlib.h>
#include <stdio.h>
#include "drivers/fun.h"

int main() {
    uint8_t argument = fun();
    printf("the value is %d\n", argument);
    return 0;
}
