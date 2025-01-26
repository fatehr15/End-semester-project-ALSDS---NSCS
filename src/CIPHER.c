#include "Cipher.h"

//Caeser cipher 
char rightShiftChar(char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        return ((c - 'a' + shift) % 26 + 'a'); 
    } else if (c >= 'A' && c <= 'Z') {
        return ((c - 'A' + shift) % 26 + 'A');
    return c; 
    }
}

void caesarCipher(char *text, int shift) {
    void caesarCipherRecursive(char *text, int shift, int index) {
        if (text[index] == '\0') {
            return; 
        }

        text[index] = rightShiftChar(text[index], shift); 
        caesarCipherRecursive(text, shift, index + 1); 
        }

    caesarCipherRecursive(text, shift, 0); 
}



void substitutionCipher(char *text, const char *key) {

    if (strlen(key)!= 26) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            return ;
        }

        for (int j = i+1 ; j < 26; j++) {
            if (tolower(key[i]) == tolower(key[j])){
               return ;
            }
        }
    }


    for (int i = 0; text[i]; i++) {
       if (isalpha(text[i])) {
           if (islower(text[i])) {
              int index =text[i]-'a';
              text[i] = tolower(key[index])  ;
           }else{
              int index =text[i]-'A';
              text[i] = toupper(key[index]) ;
            }
       }
    }

}


void xorCipher(char *text, const char *key) {
    char bestkey = 0 ;
    int highestcount = 0 ;

    for (int key = 0; key < 256; key++) {
        int count = 0;
        
        for (int i = 0; text[i] != '\0' ; i++) {
            char decrypted = text[i] ^ key;
            
 
            if ((decrypted >= 'A' && decrypted <= 'Z') ||(decrypted >= 'a' && decrypted <= 'z') ||decrypted == ' ') {
                count++;
            }
        }


        if (count > highestcount) {
            highestcount = count;
            bestkey = key;
        }

    }

    return bestkey;
}
