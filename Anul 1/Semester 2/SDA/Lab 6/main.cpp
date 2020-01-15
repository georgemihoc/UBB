#include <iostream>
#include "TestScurt.h"
#include "TextExtins.h"


int main() {
    testAllScurt();
    std::cout<<"\nShort tests passed\n";
    testAllExtended();
    std::cout<<"\nExtended test passed\n";
    std::cout<<"\nAll test passed\n";
    return 0;
}