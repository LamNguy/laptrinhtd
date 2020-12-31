#include <iostream>
#include <cmath>

bool isPrime(int x) {

	if ( x== 0 || x ==1 ) return false ;
	for (int i=2;i <= sqrt(x) ; i++){
		if (x % j == 0) return false ;
	}

	return true;

}



if (x == 2) return true;
    for (int j=2; j*j<=x; j++) {
        if (x % j == 0) break;
        else if (j+1 > sqrt(x)) {
            return true;
        }

    }
    return false;


bool containsDigit(int number, int digit) {
    while (number != 0) {
        int temp = number % 10;
        if (temp == digit) return true;
        number /= 10;
    }
    return false;
}


int A,B,D;
int count = 0 ;

int main() {
    
    std::cin >> A >> B >> D ; 

    for (int i= A ; i<=B; i++){
        if(isPrime(i) && containsDigit(i, D)) { count ++; }
    }
    
    std::cout << count << std::endl;
}
