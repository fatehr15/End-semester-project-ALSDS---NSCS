#include "MatrixOperations.h"

/*Operations on matrices */

//Basic Matrix Functions
//Initialize Matrix 
void initializeMatrix(int rows, int cols, int matrix[rows][cols], int value){
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
         matrix[i][j] = value ;
        }
    }
}

//Print Matrix 
void printMatrix(int rows, int cols, int matrix[rows][cols]){
    for ( int i=0 ; i< rows ; i ++){
        for ( int j=0 ; j< cols ; j++){
            printf ("%4d" , matrix[i][j] ) ;
        }
        printf("\n") ;
    }
}

//Input Matrix 
void inputMatrix(int rows, int cols, int matrix[rows][cols]){
     for ( int i=0 ; i< rows ; i ++){
       for ( int j=0 ; j< cols ; j++){
         scanf ("%d" , &matrix[i][j]  ) ;
        }
    }  
}

//Matrix Arithmetic
//Matrix Addition 
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]){
 for ( int i=0 ; i< rows ; i ++){
       for ( int j=0 ; j< cols ; j++){
         result[i][j] = mat1[i][j] + mat2[i][j] ;     
        }
    }  
}

//Matrix Subtraction 
void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]){
 for ( int i=0 ; i< rows ; i ++){
       for ( int j=0 ; j< cols ; j++){
         result[i][j] = mat1[i][j] - mat2[i][j] ;     
        }
    }  
}

//Matrix multiplication
void multiplyMatrices(int rows1, int cols1,int rows2 , int cols2 , int mat1[rows1][cols1], int mat2[rows2][cols2], int result[rows1][cols2]){


    if (cols1 != rows2) {
        printf("Error: Matrix dimensions incompatible for multiplication!\n");
        printf("Columns of first matrix (%d) must match rows of second matrix (%d)\n", cols1, rows2);
        return;
    }

    for (int i = 0; i < rows1; i++) {       
        for (int j = 0; j < cols2 ;j++)  {     
            result[i][j] = 0;                
            for (int k = 0; k < cols1;k++){
                result[i][j] +=mat1[i][k] *mat2[k][j] ;
            }
        }
    }
}


//Scalar Multiplication 
void scalarMultiplyMatrix(int rows, int cols, int matrix[rows][cols], int scalar){
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar; 
        }
    }

}

//Matrix Properties and Checks
//Check if Square Matrix 
bool isSquareMatrix( int rows, int cols){
    return (rows == cols) ;
}

//Check if Identity Matrix 
bool isIdentityMatrix(int size, int matrix[size][size]) {
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] != 1) {
            return false;
        }
    }
    return isDiagonalMatrix(size, matrix);  
}

//Check if Diagonal Matrix 
bool isDiagonalMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i!= j && matrix[i][j]!= 0){
                return false;
            }
        }
    }
    return true;      
}

//Check if Symmetric Matrix 
bool isSymmetricMatrix(int size, int matrix[size][size]){
    for ( int i  =0 ; i<size ; i++){
        int j = i ;
        int k=0 ;
        int l=size-1 ;
        while (k!=i && l!=i ){
            if (matrix[i+l][j] != matrix[i-k][j] ){
                return false ;
            }
            if (k!= i ){
                k++ ;
            }
            if (l!=i){
                l-- ;
            }
        }
    }
    return true ;
}

//Check if Upper Triangular Matrix 
bool isUpperTriangular(int size, int matrix[size][size]){
    for ( int i  = 0 ; i<size ; i++){
        int j = i ;
        int k=1 ;
        while (k!=i){
            if (matrix [i-k][i]!=0){
                return false ;
            }
            k++ ;
        }
    }
    return true ;
}






//Matrix Operations


//Transpose Matrix 
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

//Determinant of a Matrix 
int determinantMatrix(int size, int matrix[size][size]){
    int det = 0 ;
    int smatrix[size - 1][size- 1]; 
    if (size == 1) {
        return matrix[0][0];
    }

    if (size == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    int submatrix[size-1][size-1] ;
    int det = 0 ;
    int sign = 1 ;


    for (int col = 0; col < size ; col++) {
        int  l ;
        for (int i = 0 ;i<size ; i++){
           if (i==col){
             l++ ;
            }
            for (int j=1 ; j<size ; j++){           
             submatrix[i][j-1]=matrix[l][j] ; 
            }
            l++ ;   
        }

        det += sign * matrix[0][col] * determinantMatrix(size- 1, submatrix) ;
        sign *= -1 ;  
    }

    return det;
}

void adjointMatrix(int size, int matrix[size][size], int adjoint[size][size]) ;

//Inverse of a Matrix 
void inverseMatrix(int size, int matrix[size][size], int result[size][size]){
    
    double det = determinant(size, matrix);
    if (det == 0) {
        printf("The inverse does not exist.");
        return ;
    }else{
        adjointMatrix (size , matrix , result ) ;
        for ( int i ; i<size ; i++){
            for ( int j ; j<size ;j++){
                result[i][j]/=det ;
            }
        }
    }

}



//Matrix Power 
void matrixPower(int size, int matrix[size][size], int power, int result[size][size]){
    if (power == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
               if (i == j) {         
                    result[i][j] = 1; 
             }else {            
                  result[i][j] = 0; 
                }
            }
        }
        return;
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix[i][j] ;
        }
    }


    int temp[size][size] ;
    for (int p = 1; p < power; p++) {
        multiplyMatrices (size, size, result, size, size, matrix, temp ) ;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = temp[i][j];
            }
        }

    }
}



//Advanced Matrix Functions

//Minor of a matrix
int Minor( int a , int b ,int size, int matrix[size][size], int minor[][size-1]){
    int mini = 0;
    for(int i = 0; i <size; i++) {
        if(i ==a) {
            continue;
        }
        int minj = 0;
        for(int j = 0; j < size; j++) {
            if(j == b) {
                continue;
            }

            minor[mini][minj] = matrix[i][j];
            minj++;
        }

        mini++;
    }
}



//Cofactor Matrix 
void cofactorMatrix(int size, int matrix[size][size], int cofactor[size][size]){
    int minor[size-1][size-1];
    for(int i = 0; i < size;i++){
        for(int j = 0; j < size;j++){
            getMinor(size,matrix,i,j,minor);
            int sign;
            if ((i + j) % 2 == 0) { 
                sign = 1 ;
         } else {                 
                sign = -1 ;
            }
            cofactor[i][j] = sign* determinantMatrix(size-1 , minor)  ;
        }
    }
}

//Adjoint Matrix 
void adjointMatrix(int size, int matrix[size][size], int adjoint[size][size]){
    int cofactor[size][size] ;  
    cofactorMatrix ( size , matrix , cofactor);
    transposeMatrix(size , size , cofactor , adjoint ) ;
}



//LU Decomposition 
void luDecomposition (int size, double matrix[size][size], double lower[size][size], double upper[size][size]){

    for(int i = 0; i < size; i++) {

        for(int k = i; k < size; k++) {
            double sum = 0;
            for(int j = 0; j < i; j++){
                sum += lower[i][j] * upper[j][k] ;
            }
            upper[i][k] =matrix[i][k] -sum ;
        }


        for(int k = i; k < size; k++) {

            if(i == k) {
                lower[i][i] = 1;
            } else {
                double sum = 0;
                for(int j = 0; j < i; j++) {
                    sum += lower[k][j] * upper[j][i] ;
                }
                lower[k][i] = (matrix[k][i] - sum) /upper[i][i]   ;
            }

        }
    }
}







//Special Matrix Operations



//Find Trace of a Matrix 
int traceMatrix(int size, int matrix[size][size]){
    int trace =0  ;
    for(int i = 0 ; i < size ; i++) {
        trace +=  matrix[i][i] ;
    }
    return trace ;
}


//Rotate Matrix 90 Degrees 
void rotateMatrix90 (int size, int matrix[size][size]){
    int tempMatrix[size][size] ;
    for ( int i = 0 ; i<size ; i++){
        for ( int j=0 ; j<size ; j++){
            tempMatrix[i][j] = matrix[size-1 -j][i] ;
        }
    }
    for ( int i = 0 ; i<size ; i++){
        for ( int j ; j<size ; j++){
            matrix[i][j]= tempMatrix[i][j] ;
        }
    }
}


//Find Eigenvalues
void findEigenvalues(int size, double matrix[size][size], double eigenvalues[size]) {

}

