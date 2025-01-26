#include "ArrayOperations.h"


/*Operations on arrays*/

//Basic arrays functions



//Initialize Array 
void initializeArray(int arr[], int size, int value){
    for(int i=0;i<size;i++){
      arr[i] = value ;
    }
}

//print araay
void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
      printf("%d",arr[i]) ;
    }
}


//Find Maximum 
int findMax(int arr[], int size){
    if(size == 0){
      return -9999  ; 
    } 
 int max = arr[0] ;
 for(int i=1;i<size;i++){
        if (arr[i]>max){
         max = arr[i];
        }
    }  
    return max ;
}

//Find Minimum 
int findMin(int arr[], int size){
    if(size == 0){
      return -9999 ; 
    } 
 int min = arr[0] ;
 for(int i=1;i<size;i++){
        if (arr[i]< min ){
         min = arr[i];
        }
    }  
    return min ;
}

//Calculate Sum 
int sumArray(int arr[], int size){
    int sum = 0 ;
    for (int i =0;i<size ; i++){
        sum+=arr[i] ;
    }
    return sum ;
}


//Calculate Average 
double averageArray(int arr[], int size){
    if(size == 0){
      return 0  ; 
    } 
    return (sumArray(arr,size)/(size-1));
}

//Check if Sorted 
bool isSorted(int arr[], int size){
    for (int i=0 ; i<size ; i ++ ){
        if (arr[i]>arr[i+1]){
            return false ;
        }
    }
    return true ;
}








//Intermediate Arry Functions 
//Reverse Array
void reverseArray(int arr[], int size){
    for(int i=0 ; i<=size/2 ; i++){
        swapArr( arr , i , size -1-i) ;
    } 
}

//Count Even and Odd Numbers 
void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount){
    *oddCount=0 ;
    *evenCount=0 ;
    for (int i = 0 ;i<size ; i++ ){
        if (isEven(arr[i])){
            (*evenCount) ++ ;
        }else{
            (*oddCount)++ ;
        }
    }
}

//Find Second Largest 
int secondLargest(int arr[], int size){
    if(size < 2) {
        return -1 ;
    }
        
    int first = max(arr[0],arr[1]), second = min(arr[0],arr[1]);
    for(int i = 2; i < size; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else {
               if(arr[i] >second && arr[i] != first) {
                  second = arr[i];
                }
        }  
        return second; 
    }
}


//Find Frequency of Elements 
void elementFrequency(int arr[], int size){
    int count ;
    for (int i=0 ; i <size-1 ; i++){
        for (int j=i+1 ; j<size ; j++){   
           count ++ ;
           printf ("arr[ %i ] repeated %count time " , &i , &count) ;
        }
    }
}


//Remove Duplicates 
int removeDuplicates(int arr[], int size){
    if(size <= 1) {
        return size ;
    }
    
    int newSize = 1 ;
    for(int i = 1; i < size; i++) {
        if(arr[i] != arr[newSize-1]) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    return newSize;
}

//Binary Search 
int binarySearch(int arr[], int size, int target){
    int low = 0  ;
    int high = size-1 ;

    while(low <= high) {
        int mid = low + (high - low)/2 ;

        if(arr[mid] == target) {
            return mid;
        } else {
               if(arr[mid] < target) {
                  low = mid +1;
              } else {
                  high = mid -1;
                }
        }
    }
    return -1;
}


//Linear Search 
int linearSearch(int arr[], int size, int target){
    for (int i=0 ; i<size ; i++){
        if(arr[i]==target){
            return i ;
        }
    }
    return -1 ;
}

//Left Shift Array 
void leftShift(int arr[], int size, int rotations){
    rotations %= size;
    while(rotations--) {
        int temp = arr[0];
        for(int i = 0; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[size-1] = temp;
    }
}

//right Shift Array 
void rightShift(int arr[], int size, int rotations){
    rotations %= size;
    while(rotations--) {
        int temp = arr[size-1] ;
        for(int i = size-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = temp ;
    }
}


//swapArr
void SwappArr(int arr , int* a, int* b){
    int temp=arr[a];
    arr[a]= arr[b] ;
    arr[b]=temp ;
}








//Sorting Algorithms

//Bubble Sort 
void bubbleSort(int arr[], int size){
    for(int i =0; i <size-1 ; i++) {
        for(int j=0; j <size - i-1;  j++) {
            if(arr[j] > arr[j+1])  {
                swapArr(arr, j, j+1 );
            }
        }
    }
}

//Selection Sort 
void selectionSort(int arr[], int size ){
    for(int i = 0; i < size-1; i++) {
        int min = i;

        for(int j = i+1 ; j < size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        swapArr(arr, i, min );

    }
}


//Insertion Sort 
void insertionSort(int arr[], int size){
    for (int i = 1; i < size ; i++ ) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j +1] = arr[j] ;
            j = j-1 ;
        }
        arr[j+1] = key ;
    }

}


//Merge Sort 
void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int LEFT[size1], RIGHT[size2];

    // Copy subarrays
    for(int i = 0; i < size1; i++) {
        LEFT[i] = arr[left + i];
    }
    for(int j = 0; j < size2; j++) {
        RIGHT[j] = arr[mid + 1 + j];
    }

    // Merge
    int i = 0, j = 0, k = left;
    while(i < size1 && j < size2) {
        if(LEFT[i] <= RIGHT[j]) {
            arr[k++] = LEFT[i++];
        } else {
            arr[k++] = RIGHT[j++];
        }
    }

    // Copy remaining elements
    while(i < size1) arr[k++] = LEFT[i++];
    while(j < size2) arr[k++] = RIGHT[j++];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        // Prevent overflow for large arrays
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


//Quick Sort 
void quickSort(int arr[], int low, int high){

}




// ADVANCED ARRAY OPOERATION 


// FIND MISSING NUMBER 
int FindMissingNumber(int arr[],int size)
{
    int S,s,i ;
    S=((size+1) *(size+2))/2 ; // calculate the sum of numbers from 1 to n
    s=0; 
    for(i=0;i<size;i++)
    {
        s+=arr[i]; // calculate the sum of all numbers of the array 

    }
    return S-s ;
}


// FIND PAIRS WITH GIVEN SUM 

  void FindPairsWithSum(int arr[],int size,int sum)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1 ;j<size;j++)
        {
            if (arr[i]+arr[j]==sum)
            {
                printf("(%d,%d)\n",arr[i],arr[j]);
            }
        }
    }
}


// SUBARRAY WITH GIVEN SUM 

void findSubArrayWithSum(int arr[],int size,int sum)
{
    int begin,end , subsum,i ;
    for(begin=0;begin<size;begin++)
    {
        subsum=0;
        for( end=0 ;end<size;end++)
        {
            subsum+=arr[end]; // calculate the sum  subarrays
            if(subsum==sum)
            {
                for(i=begin;i<=end;i++)
                {
                  printf(" %d ",arr[i]); 
                }
                printf("\n");
            }
        }
    }


}


// REARRANGE POSITIVE AND NEGATIVE NUMBERS
void rearrangeAlternatePositiveNegative(int arr[],int size)
{
    int left=0,right=size-1,temp ;
    while(left<=right)
    {
        if(arr[left] < 0)
        {
        left++;
        }
        else 
        {
            if (arr[right]>=0)
            {
                right--;
            }
            else
            {
                temp=arr[left];
                arr[left]=arr[right];
                arr[right]=temp;
                left++;
                right--;

            }
        }
        

    }
}

//FIND MAJORITY ELEMENT
int findMajorityElement(int arr[] , int size)
{
    int i,j,c;
    for(i=0;i<size;i++)
    { c=0;
      
        for(j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                c++;
            }
            if(c>(size/2))
            {
                return arr[i];
    
            }

        }
    }
    return -1;
}

// LONGEST INCREASING SUBSEQUENCE
int longestIncreasingSubsequence(int arr[], int size){
    if (size == 0) {
        return 0;
    }
    int i, longest=1,length=1 ;

    for(i=1;i<size;i++)
    {
        if(arr[i]>arr[i-1])
        {
            length++;
            if(length>longest)
            {
                longest = length;
            }
        }
        else 
        {
            length = 1;
        }
    }
    return longest;
}

