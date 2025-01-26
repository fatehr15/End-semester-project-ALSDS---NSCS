//Test_num

#include <stdio.h>
#include <stdbool.h>
#include "NumericOperations.h"

void test_basic_operations() {
    printf("\n=== Testing Basic Number Operations ===\n");
    
    // Test sumOfDigits
    printf("sumOfDigits(12345) = %d (Expected 15)\n", sumOFDigits(12345));
    
    // Test reverseNumber
    printf("reverseNumber(12345) = %d (Expected 54321)\n", reverseNumber(12345));
    
    // Test isPalindrome
    printf("isPalindrome(12321) = %s (Expected true)\n", 
          isPalindrome(12321) ? "true" : "false");
    
    // Test isPrime
    printf("isPrime(17) = %s (Expected true)\n", isPrime(17) ? "true" : "false");
    printf("isPrime(15) = %s (Expected false)\n", isPrime(15) ? "true" : "false");
}

void test_math_operations() {
    printf("\n=== Testing Math Operations ===\n");
    
    // Test GCD and LCM
    printf("gcd(48, 18) = %d (Expected 6)\n", gcd(48, 18));
    printf("lcm(12, 15) = %d (Expected 60)\n", lcm(12, 15));
    
    // Test factorial
    printf("factorial(5) = %ld (Expected 120)\n", factorial(5));
    
    // Test Combination
    printf("Combination(10, 3) = %d (Expected 120)\n", Combination(10, 3));
}

void test_number_properties() {
    printf("\n=== Testing Number Properties ===\n");
    
    // Test isEven
    printf("isEven(24) = %s (Expected true)\n", isEven(24) ? "true" : "false");
    
    // Test number of digits
    printf("nd(12345) = %d (Expected 5)\n", nd(12345));
    
    // Test prime factors
    printf("primeFactors(28): ");
    primeFactors(28);  // Expected: 2 2 7
    
    // Test Armstrong number
    printf("\nisArmstrong(153) = %s (Expected true)\n", 
          isArmstrong(153) ? "true" : "false");
}

void test_series_functions() {
    printf("\n=== Testing Series Functions ===\n");
    
    // Test Fibonacci series
    printf("Fibonacci series(7): ");
    fibonacciSeries(7);  // Expected: 0 1 1 2 3 5 8
    
    // Test sumDivisors and perfect number
    printf("\nsumDivisors(28) = %d (Expected 28)\n", sumDivisors(28));
    printf("isPerfect(28) = %s (Expected true)\n", isPerfect(28) ? "true" : "false");
}

void test_advanced_operations() {
    printf("\n=== Testing Advanced Operations ===\n");
    
    // Test magic number
    printf("isMagic(1234) = %s (Expected false)\n", isMagic(1234) ? "true" : "false");
    
    // Test automorphic number
    printf("isAutomorphic(25) = %s (Expected true)\n", isAutomorphic(25) ? "true" : "false");
    
    // Test binary conversion
    printf("Binary of 10: ");
    toBinary(10);  // Expected: 1010
    
    // Test narcissistic number
    printf("\nisNarcissistic(9474) = %s (Expected true)\n", 
          isNarcissistic(9474) ? "true" : "false");
}

void test_special_numbers() {
    printf("\n=== Testing Special Numbers ===\n");
    
    // Test Harshad number
    printf("isHarshad(18) = %s (Expected true)\n", isHarshad(18) ? "true" : "false");
    
    // Test Catalan number
    printf("catalanNumber(4) = %lu (Expected 14)\n", catalanNumber(4));
    
    // Test Smith number
    printf("isSmith(22) = %s (Expected true)\n", isSmith(22) ? "true" : "false");
    
    // Test sum of primes
    printf("sumOfPrimes(10) = %d (Expected 17)\n", sumOfPrimes(10));
}

int main() {
    printf("=== Starting Numeric Operations Test Suite ===\n");
    
    test_basic_operations();
    test_math_operations();
    test_number_properties();
    test_series_functions();
    test_advanced_operations();
    test_special_numbers();
    
    printf("\n=== All Tests Completed ===\n");
    return 0;
}