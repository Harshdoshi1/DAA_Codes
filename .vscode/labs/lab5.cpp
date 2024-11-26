
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <cmath>

int Findlength(long long int n){
    int size =0;
    while (n!=0){
        n = n/10;
        size++;
    }
    return size;
}

long long int Kartsuba (long long int x, long long int y){
    int size1 = Findlength(x);
    int size2 = Findlength(y);
    
    if(size2|| size2 == 1){
        return x*y;
    }
    int n = std::max(size1,size2);
    int m = n/2;
    long long int a = x/pow(10,m);
    long long int b = x%int(pow(10,m));
    long long int c = y/pow(10,m);
    long long int d = y%int(pow(10,m));
    long long int ac = Kartsuba(a,c);
    long long int bd = Kartsuba(b,d);
    long long int adbc = Kartsuba(a+b,c+d) - ac - bd;
    return ac*pow(10,2*m) + adbc*pow(10,m) + bd;

} 

int main(){
    long long int x = 12345678;
    long long int y = 987654321;

    std::cout << Kartsuba(x,y);
    
    return 0;

}