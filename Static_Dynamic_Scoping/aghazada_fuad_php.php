<?php

    /***
        Analyzing Static scoping on PHP language

        @author: Fuad Aghazada
        @date:   29/03/2018
    */


    // Test Variable
    $testVariable = 7;

    function bar()
    {
        $testVariable = 19;

        echo nl2br("In bar: $testVariable \r\n");

        return foo();
    }

    function foo()
    {
        $testVariable = 20;

        echo nl2br("In foo: $testVariable \r\n");

        return goo();
    }

    function goo()
    {
        global $testVariable;

        echo nl2br("In goo: $testVariable \r\n");

        return $testVariable;
    }

    echo nl2br("Before calling function bar testVariable: $testVariable \r\n");

    bar();

    echo nl2br("After calling function bar testVariable: $testVariable \r\n");

    // Result of Analysis  for static scoping in PHP

    /*
        Output:
        Before calling function bar testVariable: 7
        In bar: 19
        In foo: 20
        In goo: 7
        After calling function bar testVariable: 7
    */
?>
