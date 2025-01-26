#include "Cipher.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void test_caesar_cipher() {
    char text[] = "Hello World!";
    
    // Test encryption
    caesarCipher(text, 3);
    assert(strcmp(text, "Khoor Zruog!") == 0);
    
    // Test decryption
    caesarCipher(text, -3);
    assert(strcmp(text, "Hello World!") == 0);
    
    // Test wrap-around
    char text2[] = "XYZxyz";
    caesarCipher(text2, 5);
    assert(strcmp(text2, "CDEabc") == 0);
}

void test_substitution_cipher() {
    char text[] = "ATTACK AT DAWN";
    const char *key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    
    substitutionCipher(text, key);
    assert(strcmp(text, "QZZQEA QZ WQFS") == 0);
    
    // Test invalid key
    char invalid_key[] = "AAAERTYUIOPASDFGHJKLZXCVBNM";
    char original[] = "TEST";
    substitutionCipher(original, invalid_key);
    assert(strcmp(original, "TEST") == 0);
}

void test_xor_cipher() {
    const char *original = "Secret Message";
    char ciphertext[50];
    char key = 0x55;
    
    // Create test ciphertext
    for(int i = 0; original[i]; i++) {
        ciphertext[i] = original[i] ^ key;
    }
    ciphertext[strlen(original)] = '\0';
    
    // Test key detection
    assert(xorCipher(ciphertext) == key);
}

int main() {
    test_caesar_cipher();
    test_substitution_cipher();
    test_xor_cipher();
    
    printf("All tests passed!\n");
    return 0;
}