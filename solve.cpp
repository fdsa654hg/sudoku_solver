#include <iostream>
#include "sudoku.h"
#include <ctime>
using namespace std;

Sudoku::Sudoku() {
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            arr[i][j] = 0;
        }
    }
}

bool Sudoku::isValid(int c, int r, int n) {
    //check row
    for(int i=0; i<9; ++i) {
        if(arr[i][c]==n)
            return false;
    }
    //check column
    for(int j=0; j<9; ++j) {
        if(arr[r][j]==n)
            return false;
    }
    //check box
    for(int i=c/3*3; i<c/3*3+3; ++i) {
        for(int j=r/3*3; j<r/3*3+3; ++j) {
            if(arr[j][i]==n)
                return false;
        }
    }
    return true;
}

bool Sudoku::backTracking(int c=0, int r=0) {
    if(c==9) {
        if(r==8) {
            if(count>=10) {
                return true;
            }
            count += 1;
            for(int i=0; i<9; ++i) {
                for(int j=0; j<9; ++j) {
                    cout<< arr[i][j]<< " ";
                }
                cout<<endl;
            }
            cout<<endl;
            return false;
        }
        return backTracking(0, r+1);
    }
    else if(arr[r][c]!=0) {
        return backTracking(c+1, r);
    }
    for(int n=1; n<=9; ++n) {
        if(isValid(c, r, n)) {
            arr[r][c] = n;
            if(backTracking(c+1, r))
                return true;
            arr[r][c] = 0;
        }
    }
    return false;

}

// bool buildMatrix() {

// }
// bool dlx() {
    
// }

int main() {
    Sudoku su;
    su.count=0;
    cout<<"Input sudoku:"<<endl;
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cin>> su.arr[i][j];
        }
    }
    cout<<endl;
    clock_t start,end;
    start = clock();
    cout<<"Output sudoku:"<<endl;
    su.backTracking();
    cout<<"there are a total of "<<su.count<<" solution(s)."<<endl;
 
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
}