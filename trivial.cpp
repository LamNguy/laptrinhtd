#include<iostream>
#include<bits/stdc++.h>
using namespace std;

float divNorm(int num){
    float result = 0;

    for (int i=2; i<=sqrt(num); i++)
    {
        if (num%i==0)
        {
            if (i==(num/i)){
                result += i;
            }

            else{
                result += (i + num/i);
            }
        }
    }

    return (result + 1) / num;
}

int main() {
    int a, b;
    std::cin>> a;
    std::cin>> b;

    float min = divNorm(a);
    float max = divNorm(b);

    int min_res = 0;
    int max_res = 0;
    for (int i = a; i <= b; i++) {
        if (divNorm(i) < min) {
            min = divNorm(i);
            min_res = i;
        }
        else if (divNorm(i) >= max) {
            max = divNorm(i);
            max_res = i;
        }
    }
    std::cout << min_res << " " << max_res ;

}
