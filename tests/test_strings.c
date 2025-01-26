#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "StringOperations.h"

void test_basic_string_ops() {
    printf("\n=== Testing Basic String Operations ===\n");
    char dest[100];
    const char *src = "Hello";
    
    // Test stringLength
    printf("stringLength(\"%s\") = %d (Expected 5)\n", src, stringLength((char*)src));
    
    // Test stringCopy
    stringCopy(dest, src);
    printf("stringCopy result: \"%s\" (Expected \"Hello\")\n", dest);
    
    // Test stringConcat
    stringConcat(dest, " World!");
    printf("stringConcat result: \"%s\" (Expected \"Hello World!\")\n", dest);
    
    // Test stringCompare
    printf("stringCompare(\"apple\", \"apple\") = %d (Expected 0)\n", 
          stringCompare("apple", "apple"));
    printf("stringCompare(\"apple\", \"apples\") = %d (Expected negative)\n",
          stringCompare("apple", "apples"));
}

void test_string_properties() {
    printf("\n=== Testing String Properties ===\n");
    char str[100];
    
    // Test isEmpty
    strcpy(str, "");
    printf("isEmpty(\"%s\") = %s (Expected true)\n", str, isEmpty(str) ? "true" : "false");
    strcpy(str, "test");
    printf("isEmpty(\"%s\") = %s (Expected false)\n", str, isEmpty(str) ? "true" : "false");
    
    // Test reverseString
    strcpy(str, "hello");
    reverseString(str);
    printf("reverseString(\"hello\") = \"%s\" (Expected \"olleh\")\n", str);
    
    // Test case conversion
    strcpy(str, "MixEd CaSe");
    toUpperCase(str);
    printf("toUpperCase result: \"%s\" (Expected \"MIXED CASE\")\n", str);
    
    toLowerCase(str);
    printf("toLowerCase result: \"%s\" (Expected \"mixed case\")\n", str);
}

void test_intermediate_ops() {
    printf("\n=== Testing Intermediate Operations ===\n");
    char str[100];
    int vowels, consonants;
    
    // Test isPalindromeStr
    strcpy(str, "madam");
    printf("isPalindromeStr(\"%s\") = %s (Expected true)\n", 
          str, isPalindromeStr(str) ? "true" : "false");
    strcpy(str, "hello");
    printf("isPalindromeStr(\"%s\") = %s (Expected false)\n", 
          str, isPalindromeStr(str) ? "true" : "false");
    
    // Test countVowelsConsonants
    strcpy(str, "Programming");
    countVowelsConsonants(str, &vowels, &consonants);
    printf("countVowelsConsonants(\"%s\") = V:%d, C:%d (Expected V:3, C:8)\n",
          str, vowels, consonants);
    
    // Test findSubstring
    printf("findSubstring(\"hello world\", \"world\") = %d (Expected 6)\n",
          findSubstring("hello world", "world"));
    printf("findSubstring(\"test\", \"none\") = %d (Expected -1)\n",
          findSubstring("test", "none"));
}

void test_advanced_ops() {
    printf("\n=== Testing Advanced Operations ===\n");
    char str[100];
    char result[200];
    
    // Test removeWhitespaces
    strcpy(str, "  Hello   World!  ");
    removeWhitespaces(str);
    printf("removeWhitespaces result: \"%s\" (Expected \"HelloWorld!\")\n", str);
    
    // Test countWords
    strcpy(str, "   C programming  is   fun!  ");
    printf("countWords(\"%s\") = %d (Expected 4)\n", str, countWords(str));
    
    // Test removeDuplicates
    strcpy(str, "programming");
    removeDuplicates(str);
    printf("removeDuplicates result: \"%s\" (Expected \"progamin\")\n", str);
    
    // Test compressString
    strcpy(str, "aaabbbcccd");
    compressString(str, result);
    printf("compressString result: \"%s\" (Expected \"a3b3c3d1\")\n", result);
}

int main() {
    printf("=== Starting String Operations Test Suite ===\n");
    
    test_basic_string_ops();
    test_string_properties();
    test_intermediate_ops();
    test_advanced_ops();
    
    printf("\n=== All String Tests Completed ===\n");
    return 0;
}