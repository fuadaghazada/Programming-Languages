/***
    Analyzing Static scoping on C language

    @author: Fuad Aghazada
    @date:   29/03/2018
*/

#include<stdio.h>

//Test variable for the experiment
int testVariable = 7;

/*
  Function goo -- prints the testVaribale (global) without declaring a local one.
*/
int goo()
{
    printf("In goo: %d \n", testVariable);    // static scope: in parent there is only testVariable = 7

    return testVariable;                      // returns 7
}

int foo()
{
    int testVariable = 20;

    printf("In foo: %d \n", testVariable);

    return goo();
}

int bar()
{
    int testVariable = 19;

    printf("In bar: %d \n", testVariable);

    return foo();
}

// main method for calling the function bar
int main()
{
    printf("Before calling function bar testVariable: %d \n", testVariable);

    bar();

    printf("After calling function bar testVariable: %d \n", testVariable);
}

// Result of Analysis  for static scoping in C

/*

Output:
Before calling function bar testVariable: 7
In bar: 19
In foo: 20
In goo: 7
After calling function bar testVariable: 7

*/
