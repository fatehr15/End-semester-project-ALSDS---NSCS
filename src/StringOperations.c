#include "StringOperations.h"
//Basic String Functions



//Calculate String Lenghth
int stringLength(char* str){
    int length = 0 ;
    while (str[length] != '\0' ){
        length++ ;
    }
    return length;
}

//Copy String 
void stringCopy(char* dest, const char* src){
    while (*src != '\0'){
        *dest = *src;
        dest++ ;
        src++ ;
    }
    *dest = '\0' ;
}


//Concatenate Strings 
void stringConcat(char* dest, const char* src){
    while (*dest != '\0') {
        dest++;
    }
    stringCopy(dest,src);
}

//Compare Strings
int stringCompare(const char* str1, const char* str2){
    while (*str1 && *str2   &&   *str1==*str2  ){
        str1++;
        str2++;
    }
    return (*str1-*str2)  ;
}

//Check if Empty 
bool isEmpty(char* str){
    return stringLength(str)==0   ; 
}

//Reverse a String 
void reverseString(char* str){
    int length = stringLength(str); 
     for (int i = 0; i < length / 2; i++) {
        char save = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = save;
    }
}

//Convert to Uppercase 
void toUpperCase(char* str){
    while (*str != '\0'){
          if (*str >= 'a' && *str <= 'z') { 
             *str = *str - ('a' - 'A');  
           }
     str++ ;
    }

}


//Convert to Lowercase 
void toLowerCase(char* str){
    while (*str != '\0'){
          if (*str >= 'A' && *str <= 'Z') { 
             *str = *str - ('A' - 'a');  
           }
     str++ ;
    }
}





//Intermedate String Functions

//Palindrome
bool isPalindrome(char* str){
    int len = stringLength(str)  ;
    for (int i = 0; i < len/2; i++) {
        if (str[i] !=str[len- i-1]) {
            return false  ;
        }
    }
    return true ;
}

//Count Vowels and Consonants 
void countVowelsConsonants ( char* str, int* vowels , int* consonants){
    *vowels = *consonants = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i])  ;
        if (c >= 'a' && c <= 'z') {
            if (c == 'a'||c=='e' ||c== 'i'||c  =='o'||c=='u' || c=="y")
                (*vowels) ++ ;
            else
                (*consonants) ++ ;
        }
    }
}

//Find Substring 
int findSubstring(const char* str, const char* sub){
    int lsub= stringLength(sub) ;
    int lstr= stringLength(str);
    if (lsub== 0||lstr < lsub)  {
        return -1;
    }
    for (int i = 0; i <= lstr - lsub; i++) {
        int j;
        for (j = 0; j < lsub; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }    
        if (j == lsub) {
            return i;
        }    
    }
    return -1 ;
}

//Remove Whitespaces 
void removeWhitespaces(char* str){
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}


//Count Words 
int countWords(char* str){
    int count = 0;
    bool inWord = false;
    while (*str) {
        if (*str != ' ' && !inWord) {
            inWord = true;
            count++;
        } else if (*str == ' ') {
            inWord = false;
        }
        str++;
    }
    return count;
}

//Remove Duplicate Characters 
void removeDuplicates(char* str){
    bool seen[256] = {false};
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (!seen[(unsigned char)str[i]]) {
            seen[(unsigned char)str[i]] = true;
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}



//Advanced String Functions


//String Compression 
void compressString(char* str, char* result) {
    int i = 0, j = 0;
    while (str[i]) {
        result[j++] =str[i];
        int count =1;
        while (str[i]==str[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            char buffer[20];
            int len =sprintf(buffer,"%d",count);
            strcpy(&result[j], buffer);
            j +=len;
        }
        i++;
    }
    result[j] = '\0';
}


 
