#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    // pointer assignment can't be changed.
    const char *testString = "nihargoli";
    char *testCopyStr      = "nihar";

    // chaning the value of testString will throw an error
    // because const is for char so chanign pointer value would throw an error
    // *testString = testCopyStr;
    //***
    // Always read it this way type to the left of the const is constant
    // If nothing on the left, then thing on the right is const.
    //***
    // but the below is correct; we can change the pointer itself
    testString = testCopyStr;
    printf("string is %s\n", testString);

    const char *const testString2 = "nihargoli";
    // testString2 = testCopyStr;
    // Something on below lines will fail to compile.
    // *testString2 = *testCopyStr;
    // strcpy(testString, testCopyStr);

}
