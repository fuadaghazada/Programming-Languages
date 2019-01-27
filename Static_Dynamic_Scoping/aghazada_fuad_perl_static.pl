# Analyzing Static scoping on Perl language

# @author: Fuad Aghazada
# @date:   29/03/2018

# Test variable for the experiment
$testVariable = 7;

# Function bar - printing the value of my variable
sub bar
{
    my $testVariable = 19;                # my keyword is used, so it Perl will use static scoping

    print "In bar: $testVariable"."\n";   # print statement for indicating value for $testVariable in foo function

    return foo();                         # returning
}

# Function foo - print the value of $testVariable
sub foo
{
    my $testVariable = 20;                # my keyword is used, so it Perl will use static scoping

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
# Result of Analysis  for static scoping in Perl #
###################################################
=pod

Like most of the modern imperative languages, Perl has also static scoping.


Output:
Before calling function bar testVariable: 7
In bar: 19
In foo: 20
In goo: 7
After calling function bar testVariable: 7

=cut
