#include <iostream>
using namespace std;


int bs(int a[], int n, int x){
    int res = -1;

    int l = 0;
    int r = n - 1;

    while(l <= r){
        int m = l + (r - l) / 2;

        if(a[m] > x){
            r = m - 1;
        }else if(a[m] < x){
            l = m + 1;
        }else if(a[m] == x){
            r = m;
            break;
        }
    }

    if(x == a[r]){
        res = r;
    }

    return res;
}

void assert(int testNo, int expected, int output){
    if( output == expected){
        printf("test: %i - Passed", testNo);
    }else{
        printf("test: %i - Failed", testNo);
    }
}

void test1(){
    int a[] = {1,2,3,4};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 1;
    int expected = 0;
    assert(1, expected, bs(a, n, x) );
}



int main(){
   
   
    return 0;
}