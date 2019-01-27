'''
    Analyzing function parameters in Python

    @author: Fuad Aghazada
    @date: 20/04/2018
'''

# Example function for demonstrating positional and keyword parameter correspondence
def myFunction0(par0, par1):
    print(str(par0) + " is the first parameter!")
    print(str(par1) + " is the second parameter!\n")

# Example function for demonstrating default parameter values
def myFunction1(par0, par1 = "I am a default parameter", par2 = "Me too", par3 = 100):
    print("Parameter 0: " + str(par0))
    print("Parameter 1: " + str(par1))
    print("Parameter 2: " + str(par2))
    print("Parameter 3: " + str(par3) + "\n")

# Example function for demonstrating variable number of parameers
def myFunction2(*pars):

    # printing number of parameters
    print("Number of parameters: " + str(len(pars)))

    # printing all parameters
    for p in pars:
        print(p)

    print("\n")

# Example function for demonstrating parameter passing
def myFunction3(par0, par1, par2):

    # modifiying the values of the parameters
    par0 += 77
    par1 = "New String"
    par2.append(100)

    # Values of paramaters inside the function
    print("In myFunction3 par0: " + str(par0))
    print("In myFunction3 par1: " + str(par1))
    print("In myFunction3 par2: " + str(par2) + "\n")


# Positional and Keyword parameter correspondence
myFunction0("sampleString", 7)                            # postional arguments
myFunction0(par0 = "sampleString", par1 = 7)              # keyword arguments
myFunction0(par1 = 7, par0 = "sampleString")              # keyword arguments

# Formal parameter default values
myFunction1("sampleString")
myFunction1("sampleString", 7)
myFunction1("sampleString", 7, "new_par_3")
myFunction1("sampleString", par2 = 7)
myFunction1("sampleString", par3 = "new_par_3")

# Variable number of parameters
myFunction2("myPar")
myFunction2(1, 2, 3, "myPar")

# Parameter passing
first_par = 7
second_par = "sampleString"
third_par = [1, 2, "aString"]

# Values before myFunction3
print("Before calling myFunction3 first_par: " + str(first_par))
print("Before calling myFunction3 second_par: " + str(second_par))
print("Before calling myFunction3 third_par: " + str(third_par) + "\n")

myFunction3(first_par, second_par, third_par)             # calling myFunction3

# Values after myFunction3
print("After calling myFunction3 first_par: " + str(first_par))
print("After calling myFunction3 second_par: " + str(second_par))
print("After calling myFunction3 third_par: " + str(third_par) + "\n")
