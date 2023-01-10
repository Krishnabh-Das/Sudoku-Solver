#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int>> board, int row, int col, int val){
    for (int i = 0; i < 9; i++)
    {
        //checking for horizontal
        if(board[row][i]==val) return false;
        //checking for vertical
        if(board[i][col]==val) return false;
        //checking for box
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val) return false;
    }
    return true;
}
bool sudoku(vector<vector<int>> &board){
    //Accessing Element
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //identifying empty element
            if(board[i][j]==0){

                //checking suitable value for the empty element
                for (int val = 1; val <= 9; val++)
                {
                    //checking if the value is safe
                    if(isSafe(board, i, j, val)){
                        /*assiging the value int the board and later checking is 
                        the choosen number right or it can include any other value
                        */
                        board[i][j]=val;
                        /*recursively calling the sudoku funtion, so that if the element 
                        choosen is wrong we can change it back, 
                        i.e the element can have more than one values
                        */
                        if(sudoku(board)){
                            return true;
                        }
                        /*if the first selected value is wrong than after recursion 
                        some element will be wrong, so we backtrack to the first element
                        by changing the changed value back to zero
                        */
                        else board[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<vector<int>> sud ={{0,0,6,0,4,0,0,9,7},
                              {0,4,0,7,3,0,0,1,0},
                              {0,1,7,0,9,2,0,3,0},
                              {6,0,0,0,7,0,0,8,0},
                              {1,0,5,0,6,0,9,0,3},
                              {0,2,0,0,1,0,0,0,6},
                              {0,5,0,9,8,0,1,6,0},
                              {0,9,0,0,5,6,0,7,0},
                              {8,6,0,0,2,0,3,0,0}};
    sudoku(sud);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<sud[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return -1;
}