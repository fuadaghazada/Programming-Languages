# Analyzing Static scoping on Python language

# @author: Fuad Aghazada
# @date:   29/03/2018

# Test variable for the experiment
testVariable = 7

def bar():
    testVariable = 19

    print("In bar: " + str(testVariable) + "\n")

    return foo()

def foo():
    testVariable = 20

    print("In foo: " + str(testVariable) + "\n")

    return goo()

def goo():

    print("In goo: " + str(testVariable) + "\n")

    return testVariable



print("Before calling function bar testVariable: " + str(testVariable) + "\n")

bar()

print("After calling function bar testVariable: " + str(testVariable) + "\n")

###################################################
# Result of Analysis  for static scoping in Python3 #
###################################################
'''

Output:
Before calling function bar testVariable: 7
In bar: 19
In foo: 20
In goo: 7
After calling function bar testVariable: 7

'''
