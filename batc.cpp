#include <iostream>
using namespace std;

long int a, b, c, d, k;

int bact(int n){
    if (n == 0) {
        return a;
    }

    else if (a==a*b-c) return a;

    else if (a>=d) {
        a=d;
        if (d*b-c >= d) return a;
    }

    else {
        int temp = bact(n-1)*b - c;
        if(temp>d) return d;
        else if (temp <= 0) return 0;
        else return temp;
    }
}

int main(){
    cin >> a >> b >> c >> d >> k;
    cout << bact(k);
}
