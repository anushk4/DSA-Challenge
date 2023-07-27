// submission: https://leetcode.com/problems/spiral-matrix/submissions/1005362800/
// runtime = 0 ms

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int x_left = 0;
    int x_right = *matrixColSize - 1;
    int y_top = 0;
    int y_bottom = matrixSize - 1;
    int size = 0;
    int total = matrixSize * (*matrixColSize);
    int* result = (int*)malloc((matrixSize*(*matrixColSize))*sizeof(int));
    int start_x = x_left;
    int start_y = y_top;
    while(1){
        while (start_x <= x_right){
            result[size] = matrix[start_y][start_x];
            size++;
            start_x++;
        }
        y_top++;
        start_y++;
        start_x--;
        if (size == total) break;
        while (start_y <= y_bottom){
            result[size] = matrix[start_y][start_x];
            size++;
            start_y++;
        }
        x_right--;
        start_y--;
        start_x--;
        if (size == total) break;
        while (start_x >= x_left){
            result[size] = matrix[start_y][start_x];
            size++;
            start_x--;
        }
        y_bottom--;
        start_x++;
        start_y--;
        if (size == total) break;
        while (start_y >= y_top){
            result[size] = matrix[start_y][start_x];
            size++;
            start_y--;
        }
        x_left++;
        start_y++;
        start_x++;
        if (size == total) break;
    }
    *returnSize = size;
    return result;
}
