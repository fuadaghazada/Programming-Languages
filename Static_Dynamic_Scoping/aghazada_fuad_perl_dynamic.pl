# Analyzing Dynamic scoping on Perl language

# @author: Fuad Aghazada
# @date:   29/03/2018

# Test variable for the experiment
$testVariable = 7;

# Function bar - printing the value of local variable
sub bar
{
    local $testVariable = 19;             # local keyword is used, so it Perl will use dynamic scoping

    print "In bar: $testVariable"."\n";   # print statement for indicating value for $testVariable in foo function

    return foo();                         # returning
}

# Function foo - print the value of $testVariable
sub foo
{
    local $testVariable = 20;             # local keyword is used, so it Perl will use dynamic scoping

    print "In foo: $testVariable"."\n";   # print statement for indicating value for $testVariable in foo function

    return goo();                         #
}

# Function goo - print the value of $testVariable
sub goo
{
    print "In goo: $testVariable"."\n";   # print statement for indicating value for $testVariable in foo function

    return $testVariable;
}

print "Before calling function bar testVariable: $testVariable "."\n";  # before bar()

bar(); # calling function bar

print "After calling function bar testVarible: $testVariable"."\n";    # after bar()


###################################################
# Result of Analysis  for dynamic scoping in Perl #
###################################################
=pod

Perl is one of languages which has not only the static scoping, but the dynamic scoping.
Dynamic scoping can be used by the keyword 'local'.

Output:
Before calling function bar testVariable: 7
In bar: 19
In foo: 20
In goo: 20
After calling function bar testVariable: 7

=cut
