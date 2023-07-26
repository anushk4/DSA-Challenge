// submission: https://leetcode.com/problems/game-of-life/submissions/1004494427/
// time complexity: O(mn), runtime: 0 ms

void gameOfLife(int** board, int boardSize, int* boardColSize){
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < *boardColSize; j++){
            int live_neighbour = 0;
            // checking for neighbours in the above row
            if (i > 0){
                if (j > 0){ // top left
                    if (abs(board[i-1][j-1])==1){
                        live_neighbour++;
                    }
                }
                if (abs(board[i-1][j])==1){ // top
                    live_neighbour++;
                }
                if (j!=*boardColSize-1){ // top right
                    if (abs(board[i-1][j+1])==1){
                        live_neighbour++;
                    }
                }
            }
            // checking for neighbours in the same row
            if (j > 0){ // left
                if (abs(board[i][j-1])==1){
                    live_neighbour++;
                }
            }
            if (j!=*boardColSize-1){ // right
                if (abs(board[i][j+1])==1){
                    live_neighbour++;
                }
            }
            // checking for neighbors in the bottom row
            if (i!=boardSize-1){
                if (j > 0){ // bottom left
                    if (abs(board[i+1][j-1])==1){
                        live_neighbour++;
                    }
                }
                if (abs(board[i+1][j])==1){ // bottom
                    live_neighbour++;
                }
                if (j!=*boardColSize-1){ // bottom right
                    if (abs(board[i+1][j+1])==1){
                        live_neighbour++;
                    }
                }
            }
            // checking for current condition
            if (board[i][j] == 1 && (live_neighbour < 2 || live_neighbour > 3)){
                board[i][j] = -1;
            }else if (board[i][j] == 0 && live_neighbour == 3){
                board[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < *boardColSize; j++){
            if (board[i][j] == 2){
                board[i][j] = 1;
            }else if (board[i][j] == -1){
                board[i][j] = 0;
            }
        }
    }
}
