#ifndef CIPHER_H
#define CIPHER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Caesar cipher functions
void caesarCipher(char *text, int shift);

// Substitution cipher functions
void substitutionCipher(char *text, const char *key);

// XOR cipher functions
char xorCipher(const char *ciphertext);

#endif