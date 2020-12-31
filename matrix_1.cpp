#include <iostream>
#include <cmath>
int arr[3] ;
int tri[3] ;
bool check[3];
int max  =  -1 ;

void setmax(){
    int value = 0;
    for ( int i = 0 ; i  < 3 ; i++){
        value +=  arr[i]*pow(10,2-i);
        if (value > max) max = value;

    }
}

void back(int pos){
    if ( pos == 3 ) {
        setmax();
        return ;
    }
    for ( int i =0 ; i < 3 ; i++){
        if (  ! check[i]){
            arr[pos]= tri[i] ;
            check[i] = true ;
            back(pos+1);
            check[i] = false ;
        }

    }
}

int main() {
    std::cin >> tri[0] >> tri[1] >> tri[2] ;
    back(0);
    std::cout<<max ;
    return 0;
}
