#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main() {
    uint8_t command = 129;
    uint8_t argument = (int)(command & 0x1f);

    // std::string str = std::to_string(argument);
    // std::cout << "Hello World!\n\r";
    // std::cout << str;

    std::printf("the value is %d\n", argument);
    return 0;
}
