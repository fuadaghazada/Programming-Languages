/**
    Analyzing function parameters in C++

    @author: Fuad Aghazada
    @date: 20/04/2018
*/
#include <iostream>
#include <string>
#include <stdarg.h>

using namespace std;

// Example function for demonstrating positional and keyword parameter correspondence
void myFunction0(string par0, int par1)
{
    cout << par0 << " is the first parameter" << endl;
    cout << par1  << " is the second parameter\n" << endl;
}

// Example function for demonstrating default parameter correspondence
void myFunction1(string par0, int par1 = 666, string par2 = "Me too", int par3 = 100)
{
    cout << "Parameter 0: " << par0 <<  endl;
    cout << "Parameter 1: " << par1 <<  endl;
    cout << "Parameter 2: " << par2 <<  endl;
    cout << "Parameter 3: " << par3 << "\n" <<  endl;
}

// Example function for demonstrating variable number of parameters
void myFunction2(int parameters, ...)
{
    // variable list
    va_list valist;

    // creating variable list for the parameters
    va_start(valist, parameters);

    // Printing number of parameters
    cout << "Number of paramaters: " << parameters << endl;

    for(int i = 1; i <= parameters; i++)
    {
        cout << va_arg(valist, int) << endl;
    }

    cout << endl;

    // cleaning the memory
    va_end(valist);
}

// Example function for demonstrating parameter passing
void myFunction3(int par0, string par1, int *&par2, int **par3)
{
    // modifying the value of the parameters
    par0 += 77;
    par1 = "New String";

    par2[0] = 4;
    par2[1] = 5;
    par2[2] = 6;

    *(*par3) = 4;
    *(*par3 + 1) = 5;
    *(*par3 + 2) = 6;

    // values of parameters inside the function
    cout << "In myFunction3 par0: " << par0 << endl;
    cout << "In myFunction3 par1: " << par1 << endl;
    cout << "In myFunction3 par2: " << par2[0] << ", " << par2[1] << ", " << par2[2] << endl;
    cout << "In myFunction3 par3: " << *(*par3) << ", " << *(*par3 + 1) << ", " << *(*par3 + 2) << "\n" << endl;
}

// Example function for demonstrating variadic templates
void myFunction4()
{
    return;         // this function is the case when the parameters are empty
}

template <typename variadic, typename... parameters>
variadic myFunction4(variadic par, parameters... pars)
{
    // printing the parameters
    cout << par << endl;

    // recursive call for the remaining parameters
    myFunction4(pars...);
}

// Main function for execution
int main()
{
    // Positonal parameter correspondence -- Keyword is not available in C++
    myFunction0("sampleString", 7);

    // Formal parameter default values
    myFunction1("sampleString");
    myFunction1("sampleString", 7);
    myFunction1("sampleString", 7, "new_par_3");

    // Variable number of passing
    myFunction2(1, 1);
    myFunction2(3, 1, 2, 3);

    // Parameter passing
    int first_par = 7;
    string second_par = "sampleString";
    int *third_par = new int[3];
    third_par[0] = 1;
    third_par[1] = 2;
    third_par[2] = 3;

    int *forth_par = new int[3];
    forth_par[0] = 1;
    forth_par[1] = 2;
    forth_par[2] = 3;

    // Values before myFunction3
    cout << "Before calling myFunction3 first_par: " << first_par << endl;
    cout << "Before calling myFunction3 second_par: " << second_par << endl;
    cout << "Before calling myFunction3 third_par: " << third_par[0] << ", " << third_par[1] << ", " << third_par[2] << endl;
    cout << "Before calling myFunction3 forth_par: " << forth_par[0] << ", " << forth_par[1] << ", " << forth_par[2] << "\n" << endl;

    myFunction3(first_par, second_par, third_par, &forth_par);

    // Values after myFunction3
    cout << "After calling myFunction3 first_par: " << first_par << endl;
    cout << "After calling myFunction3 second_par: " << second_par << endl;
    cout << "After calling myFunction3 third_par: " << third_par[0] << ", " << third_par[1] << ", " << third_par[2] << endl;
    cout << "After calling myFunction3 forth_par: " << forth_par[0] << ", " << forth_par[1] << ", " << forth_par[2] << "\n" << endl;

    // deleting the array from heap
    delete third_par;
    delete forth_par;

    // Variadic templates
    myFunction4(1, 2, 12, 2342);
    myFunction4("string1", "string2", "string3");

    return 0;
}
