#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku {
  public:
    Sudoku();
    int arr[9][9];
    int count;
    // bool isCorrect;


    // solve
    // void solve_at(int);
    bool isValid(int c, int r, int n);
    bool backTracking(int c, int r);
    // bool wrong();
    // void cross(int, int, int);
    // int getMin();

};

#endif // SUDOKU_H