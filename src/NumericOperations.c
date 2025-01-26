
/*Operations on numbers*/
#include "NumericOperations.h"
  
//Operations on numbers
//Sum of digits
int sumOFDigits(int num) {
    int sum = 0,save = num ;

    while (num > 0) { 
        sum += num % 10; 
        num /= 10;       
    }
    num = save ;
    return sum;
}

// Reverse the digits of agiven number
int reverseNumber(int num ) {
    int reverse = 0 ,save = num ;
    while (num > 0 ){
        reverse=(num%10)+reverse*10 ;
        num=num/10 ;
    }
    num = save ;
    return reverse ;
}


// Palindrome
bool isPalindrome(int num){
    return num == reverseNumber(num);
}


// Prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

//Greatest Common Divisor
int gcd(int a , int b ){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//Least Common Multiple
int lcm(int a ,int b) {
    if (a ==0||b==0) {
        return 0;
    }
    return (a*b / gcd(a,b));
}


//Factorial
long factorial(int num) {
    if (num < 0) {
        return -1 ;
    }
    long fact = 1 ;
    for(int i=1 ; i<=num ; i++){
        fact=fact*i ;
    }
    return fact ;
}


//Combination
int Combination(int n , int p ){
    return factorial(n)/(factorial(p)*factorial(n-p)) ;
}


//Even or odd
bool isEven(int num){
    if((num%2)==0){
     return true ;
    }else{
     return false ;
    }
}


//number of digits
int nd (int num ){
    if (num == 0){ 
        return 1;
    }
    int  nd ;
    while(num / 10 != 0){
        nd ++ ;
        num=num/10 ;
    }
 return nd ;
}



//Prime Factorization 
void primeFactors(int num) {
    int i;
    for(i=2;i<=num;i++){
      while(isPrime(i) && num%i==0) {
          printf("%d * ", i);
          num/=i;
       }
    }
}


// armstrong number 
bool isArmstrong(int num){
int i,;
while(num>0){
    int save = num, sum = 0;
    int digits = nd(num) ;
    while (num > 0) {
        sum += pow(num % 10, digits);
        num /= 10;
    }
    return sum == save ;
}
}



//Fibonacci Sequence 
void fibonacciSeries(int n) {
int first = 0, second = 1, next ;
    for (int i =1;i<=n;i++) {
        if (i == 1) {
            printf("%d ", first);
        }
        if (i == 2) {
            printf("%d ", second) ;
        }

        next = first + second;
        first = second;
        second = next;
        printf("%d ", next) ;
    }
}

//Sum of Divisors 
int sumDivisors(int num){
    if (num <= 0) {
        return 0;
    }
    int sum ;
    for (int i=1 ; i<=sqrt(num) ; i++ ){
        if (num%i == 0 ){
            sum +=i ;
            if (i != num /i) {
                sum += num / i;
            }
        }
    }
    return sum ;
}


//Perfect Number
bool isPerfect(int num) {
    return (sumDivisors(num) - num )==num  ;
}


//Magic Number 
bool isMagic(int num){
  int save= num ;
  bool magic = false ;
  do{
    if ( sumOFDigits(num) == 1 ){
      magic = true ;
    }
    num = sumOFDigits(num) ;
  }while(num/10 != 0 ) ;
  num = save ;
return magic ;
}


//Automorphic Number
bool isAutomorphic(int num){
  bool Automorphic = false ;
  int nd = nd(num) ;
     if( sqr(num) % pow(10 , nd ) == num){
     Automorphic = true ;
    }
 return Automorphic ;
}










//Advanced operations on numbers
//Binary coversion
void toBinary(int num) {void toBinary(int num){
    long bin=0;
    while(num/2!=0) {
     bin=num%2;
     printf("%d",bin) ;
     num/=2;
    }
     printf("%d",num%2) ;
}


//Narcissistic Number 
bool isNarcissistic(int num ){
 int save = num ;
 int nar = 0 ;
 bool isnar=false ;
 do {
     nar += pow (num%10,nd(num)) ;
     num = num/10 ;
    }while(num!=0 ) ;
 num =save ;
 if(num == nar){
     isnar=true ;
    }
 return isnar ;
}

//Square Root Calculation 
double sqrtApprox(int num){
    if (num < 0){
        return -1.0;
    }
    double x=num, y=1;
    int precision = 0.000001   ;


    while (fabs(x-y) > precision) {
        x =(x+y)/ 2 ;
        y =num/ x  ;
    }
    return x ;
}

//Exponentiation 
double power(int base, int exp) {
    if (base == 0 && exp <= 0) {
        return 0  ;
    }
    double power = 1;
    if (exp < 0) {
        base = 1 / base; 
        exp = -exp ;            
    }
    for (int i = 0; i < exp ; i++) {
        power *= base;
    }
    return power;
}


//Happy Number 
bool isHappy(int num) {
    while (num != 1 && num != 4) { 
        int sum = 0;
        while (num > 0) {
            sum + =(num% 10)*(num %10);
            num / =  10;
        }
        num =sum  ;
    }
    return num ==1  ;
}


//Abundant Number 
bool isAbundant(int num){
    if(sumDivisors(num)>num){
        return true ;
    }else{
        return false ;
    }
}



//Deficient Number 
bool isDeficient(int num){
    return !isAbundant ;
}



//Sum of Fibonacci Even Numbers
int sumEvenFibonacci(int n){
   double f1=((1+sqrt(5))/2),f2=((1-sqrt(5))/2);
   long long  F;
   if(n<0)
    {
        F=-1;
    }else {            
    for (int i=0;i<=n;i++) {

        F=((pow(f1,i)-pow(f2,i))/sqrt(5));
        printf("%lld  ",  F);

        }
    }

}


//Harshad Number 
bool isHarshad(int num){
    bool har=false ;
    if (num % sumOFDigits(num)==0){
        har = true ;
    }
    return har ;
}


//Catalan Number Calculation 
unsigned long catalanNumber(int n){
    return factorial(2 *n)/(factorial (n+1)*factorial  (n) )   ;
}


//Pascal Triangle 
void pascalTriangle(int n){
    for (int i=1 ; i<=n ; i++ ){
        for (int j =1 ; j<=i ; j++ ){
            printf ("%d", Combination(i,j)) ;
        }
        printf("\n");
    }

}



//Bell Number 
unsigned long bellNumber(int n){
    int y=0 ,x=1 ;
    for (int i=1 ; i<=n ; i++){
        y=0 ;
        for(int j=0 ; j<=i ; j++){
            y += Combination(i,j)*x ;
        }
         x = y ;
    }
    return x ;
}






//Kaprekar Number 
bool isKaprekar(int num){
 bool kap = false ;
 int ndnew=nd(num)/2 ;
 if(isEven(nd(num*num)) && (num*num/((int)pow(10,ndnew)) == num*num%  (int)pow(10,ndnew))){
    kap = true ;
 }
 return kap ;
}



//Smith Number 
bool isSmith(int num){

 if (isPrime(num)){
    return false ;
 }else{
     int i ,sum=0 ;
       for(i=1 ; i<= sqrt(num) ; i++){    
           if( num%i==0 && isPrime(i)==true ){
              sum += sumOFDigits(i) ;
           }  
        }
     if(sum==sumOFDigits(num)){
        return true ;
     }else{
        return false ;
     }
    }
}

//Sum of Prime Numbers 
int sumOfPrimes(int n){
    int sum ;
    for (int i=2 ; i<=n ; i ++){
        if(isPrime(i)){
            sum+=i ;
        }
    }
    return sum ;
}
