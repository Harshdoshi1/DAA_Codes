#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findlength(long long int n){
    int size = 0;
    while (n != 0)
    {
        n = n/10;
        size ++;
    }
    return size;
    
}

long long int karatsuba(long long int x, long long int y){
    int size1 = findlength(x);
    int size2 = findlength(y);

    if (size1 || size2 == 1)
    {
        return x*y;
    }

    int n = max(size1,size2);
    int m = n/2;

    long long int a = x/pow(10,m);
    long long int b = x%int(pow(10,m));
    long long int c = y/pow(10,m);
    long long int d = y%int(pow(10,m));
    long long int ac = karatsuba(a,c);
    long long int bd = karatsuba(b,d);
    long long int adbc = karatsuba(a+b,c+d) - ac - bd;
    return ac*pow(10,2*m) + adbc*pow(10,m) + bd;
}

int main(){
    long long int x = 123456789;
    long long int y = 987654321;

    cout << karatsuba(x,y);
}