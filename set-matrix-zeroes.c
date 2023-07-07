#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Two arrays for storing the row and column of the 0s in the matrix is created. 
// Then for each value of the matrix, if either the row or the column is set to 1 (or true) in the rows and cols matrix, 
// indicating the presence of 0 in that particular row or column, then it is set to 0.

// Time complexity- O(mn)
// Space complexity- O(m+n)
// submission: https://leetcode.com/problems/set-matrix-zeroes/submissions/986917329/

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
     int *rows = (int*)malloc(matrixSize*sizeof(int));
    memset(rows, -1, matrixSize * sizeof(int));
    int *cols = (int*)malloc((*matrixColSize)*sizeof(int));
    memset(cols, -1, (*matrixColSize) * sizeof(int));
    for (int i=0;i<matrixSize;i++){
        for (int j=0;j<*matrixColSize;j++){
            if (matrix[i][j]==0){
                rows[i]=1;
                cols[j]=1;
            }
        }
    }
    for (int i=0;i<matrixSize;i++){
        for (int j=0;j<*matrixColSize;j++){
            if (rows[i]==1 || cols[j]==1){
                matrix[i][j]=0;
            }
        }
    }
    free(rows);
    free(cols);
}
