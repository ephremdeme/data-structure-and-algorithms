<?php
/**
 * Iterative solution for Pascal Triangle
 * Execute this file whith: php -f PascalTriangle.php
 * @author juanmagutierrez89
 */

/**
 * This function prints $n lines of Pascal Triangle
 * @param int $n number of lines desired to print
 * @return void
 */
function printPascalTriangle(int $n) : void {
   $arr = array(array());

   for ($line = 0; $line < $n ; $line++) {   
        for ($i = 0; $i < $line + 1 ; $i++) {
            if ($i === 0 || $i == $line) { 
               $arr[$line][$i] = 1;
               echo $arr[$line][$i]." ";
            } else { 
               $arr[$line][$i] = ($arr[$line - 1][$i - 1] + $arr[$line - 1][$i]);
               echo $arr[$line][$i]." ";           
            } 
        }
        echo ("\n");
    }
}

//First ten lines of Pascal Triangle
printPascalTriangle(10);
        
?>