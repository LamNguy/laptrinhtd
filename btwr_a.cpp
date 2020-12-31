#include <iostream>
#include <algorithm>
int N;
struct grass
{
    int A ;
    int B ;
};

bool grass_compare( grass a, grass b){
    return (a.A < b.A && a.B < b.B );
}

int btwr_result ( grass a[] , int N){
    int btwr[N];
    btwr[0]= 1;
    for (int i = 1; i < N ; i++)  
    { 
        btwr[i] = 1; 
        for (int j = 0; j < i; j++)   
            if (a[i].B > a[j].B && btwr[i] < btwr[j] + 1)  
                btwr[i] = btwr[j] + 1;  
    } 
    return *(std::max_element(btwr, btwr+N)); 

}

int main() {
    std::cin >> N;
    grass input[N];
    for (int i=0; i<N; i++) {
        std::cin >> input[i].A >> input[i].B;
    }
    std::sort(input,input+N,grass_compare);
    std::cout<<btwr_result(input,N);
    
}
