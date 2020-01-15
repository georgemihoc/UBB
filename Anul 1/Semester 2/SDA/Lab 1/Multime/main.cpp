#include <iostream>
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>

using namespace std;

int main() {
    testAll();
    cout<<"Short tests passed \n";
    testAllExtended();
    cout<<"Extended tests passed \n";
    cout<<"tun";
    return 0;
}