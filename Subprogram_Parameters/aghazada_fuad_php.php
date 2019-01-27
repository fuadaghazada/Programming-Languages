<?php
    /***
        Analyzing function parameters in PHP

        @author: Fuad Aghazada
        @date: 20/04/2018
    */

    // Example function for demonstrating positional and keyword parameter correspondence
    function myFunction0($par0, $par1)
    {
        echo $par0." is the first parameter\n";
        echo $par1." is the second parameter\n\n";
    }

    // Example function for demonstrating default parameter correspondence
    function myFunction1($par0, $par1 = "I am a default parameter", $par2 = "Me too", $par3 = 100)
    {
        echo "Parameter 0: ".$par0."\n";
        echo "Parameter 1: ".$par1."\n";
        echo "Parameter 2: ".$par2."\n";
        echo "Parameter 3: ".$par3."\n\n";
    }

    // Example function for demonstrating variable number of parameters
    function myFunction2()
    {
        // printing number of parameters
        $number_of_pars = func_num_args();

        echo "Number of parameters: ".$number_of_pars."\n";

        for($i = 0; $i < $number_of_pars; $i++)
        {
            echo func_get_arg($i)."\n";
        }
        echo "\n";
    }

    // Example function for demonstrating parameter passing
    function myFunction3($par0, $par1, &$par2)
    {
       // modifying the values of the parameters
       $par0 += 77;
       $par1 = "New String";
       $par2 = array(4, 5, 6);

       // values of parameters inside the function
       echo "In myFunction3 par0: $par0 \n";
       echo "In myFunction3 par1: $par1 \n";
       echo "In myFunction3 par2: ";
       print_r($par2);
       echo "\n\n";
    }

    // Positonal parameter correspondence -- Keyword is not available in PHP
    myFunction0("sampleString", 7);

    // Formal parameter default values
    myFunction1("sampleString");
    myFunction1("sampleString", 7);
    myFunction1("sampleString", 7, "new_par_3");

    // Variable number of parameters
    myFunction2("myPar");
    myFunction2(1, 2, 3, "myPar");

    // Parameter passing
    $first_par = 7;
    $second_par = "sampleString";
    $third_par = array(1, 2, "aString");

    // Values before myFunction3
    echo "Before calling myFunction3 first_par: $first_par \n";
    echo "Before calling myFunction3 second_par: $second_par \n";
    echo "Before calling myFunction3 third_par: ";
    print_r($third_par);
    echo "\n\n";

    myFunction3($first_par, $second_par, $third_par);               // calling myFunction3

    // Values after myFunction3
    echo "After calling myFunction3 first_par: $first_par \n";
    echo "After calling myFunction3 second_par: $second_par \n";
    echo "After calling myFunction3 third_par:";
    print_r($third_par);
    echo "\n\n";

?>
