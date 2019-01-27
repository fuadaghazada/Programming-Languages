/**
    Analyzing function parameters in C

    @author: Fuad Aghazada
    @date: 20/04/2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Example function for demonstrating postional / keyword parameter correspondence
void myFunction0(char par0[], int par1)
{
    printf("%s is the first parameter\n", par0);
    printf("%d is the second parameter\n\n", par1);
}

// Example function for demonstrating variable number of parameters
void myFunction2(int parameters, ...)
{
    va_list valist;

    // creating variable list for the parameters
    va_start(valist, parameters);

    // Printing number of parameters
    printf("Number of paramaters: %d\n", parameters);

    int i;
    for(i = 1; i <= parameters; i++)
    {
        printf("%d\n", va_arg(valist, int));
    }

    printf("\n");

    // cleaning the memory
    va_end(valist);
}

// Example function for demonstrating parameter passsing
void myFunction3(int par0, char par1[], int ** par2)
{
    // modifying the value of the parameters
    par0 += 77;
    par1 = "New String";

    *(*par2) = 4;
    *(*par2 + 1) = 5;
    *(*par2 + 2) = 6;

    // Values of parameters inside myFunction3
    printf("In myFunction3 par0: %d\n", par0);
    printf("In myFunction3 par1: %s\n", par1);
    printf("In myFunction3 par2: %d, %d, %d\n\n", *(*par2), *(*par2 + 1), *(*par2 + 2));
}

// Main function
int main()
{
    // Positional / Keyword parameter
    myFunction0("sampleString", 7);

    // Variable number of passing
    myFunction2(1, 1);
    myFunction2(3, 1, 2, 3);

    // Parameter passsing
    int first_par = 7;
    char *second_par = "sampleString";
    int  *third_par = malloc(3 * sizeof(int));

    third_par[0] = 1;
    third_par[1] = 2;
    third_par[2] = 3;

    // Values before calling myFunction3
    printf("Before calling myFunction3 first_par: %d\n", first_par);
    printf("Before calling myFunction3 second_par: %s\n", second_par);
    printf("Before calling myFunction3 third_par: %d, %d, %d\n\n", third_par[0], third_par[1], third_par[2]);

    myFunction3(first_par, second_par, &third_par);

    // Values after calling myFunction3
    printf("After calling myFunction3 first_par: %d\n", first_par);
    printf("After calling myFunction3 second_par: %s\n", second_par);
    printf("After calling myFunction3 third_par: %d, %d, %d\n\n", third_par[0], third_par[1], third_par[2]);

    // delete from heap
    free(third_par);

    return 0;
}
