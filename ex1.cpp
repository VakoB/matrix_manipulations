#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

const int m = 5;
const int n = 5;

void initArray(int[][n]);
void transponize(int[][n]);
void printArray(int[][n]);
void sortArrayRows(int[][n]);
void sortArrays(int[][n]);

int main()
{
    srand(time(0));
    int A[m][n];
    initArray(A);
    cout << "current array: " << endl;
    printArray(A);
    cout << endl;
    transponize(A);
    cout << "transponised array: " << endl;
    printArray(A);
    cout << endl;
    sortArrayRows(A);
    cout << "sorted array rows: " << endl;
    printArray(A);
    cout << endl;
    cout << "sorted array: " << endl;
    sortArrays(A);
    printArray(A);
}

void initArray(int A[][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = rand() % 30;
        }
    }
}

void printArray(int A[][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
}

void transponize(int A[][n]){
    for (int i = 0; i < m; i++){
        for (int j = i; j < n; j++){
            int t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
    }
}

void sortArrayRows(int A[][n]){
    bool swapped;
    for (int o = 0; o < m; o++){
        for (int i = 0; i < n; i++){
            swapped = false;
            for (int j = 0; j < n - i - 1; j++){
                if (A[o][j] > A[o][j + 1]){
                    int t = A[o][j];
                    A[o][j] = A[o][j + 1];
                    A[o][j + 1] = t;
                    swapped = true;
                }
            }
            if (swapped == false){
                break;
            }
        }
    }
}

void sortArrays(int A[][n]){
    int index = 0;
    int tempArray[m*n];
    bool swapped;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            tempArray[index++] = A[i][j];
        }
    }

    for (int i = 0; i < m*n; i++){
        swapped = false;
        for (int j = 0; j < n*m - i - 1; j++){
            if (tempArray[j] > tempArray[j + 1]){
                int t = tempArray[j];
                tempArray[j] = tempArray[j+1];
                tempArray[j + 1] = t;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    index = 0;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = tempArray[index++];
        }

    }

}



