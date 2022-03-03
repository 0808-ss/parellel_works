#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int test[1000][1000];
int use[1000];
int sum[1000];

int main() {
    //the flag of time
    long long head, tail , freq ;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    QueryPerformanceCounter((LARGE_INTEGER *)&head);
    for (int i = 0; i < 1000; i++)
        for(int j = 0; j < 1000; j++)
            test[i][j] = i + j;
    for (int i = 0; i < 1000; i++)
        use[i] = i;
    //initial the matrix

     for(int i = 0; i < 1000; i++){
         sum[i] = 0.0;
        for(int j = 0; j < 1000; j++)
            sum[i] += test[j][i] * use[j];
        }
     // the old way
//    for(int i = 0; i < 1000; i++)
//         sum[i] = 0.0;
//    for(int j = 0; j < 1000; j++)
//         for(int i = 0; i < 1000; i++)
//         sum[i] += test[j][i] * use[j];
//    // the cache way
    QueryPerformanceCounter((LARGE_INTEGER *)&tail);
    cout << "Col: " << ((tail - head) * 1000) << " ms " << endl ;

    return 0;
}
