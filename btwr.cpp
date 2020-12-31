#include<iostream>
#include<algorithm>


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int arr[], int x[], int n) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
        swapped = false; 
        for (j = 0; j < n-i-1; j++) 
        { 
            if (arr[j] > arr[j+1]) 
            {
                swap(&arr[j], &arr[j+1]); 
                swap(&x[j], &x[j+1]);
                swapped = true; 
            } 
        } 
    
        if (swapped == false) 
            break; 
   } 
} 


int btwr(int A[], int B[], int n)  
{  
    int btwr[n]; 
   
    btwr[0] = 1;    
  
    for (int i = 1; i < n; i++)  
    { 
        btwr[i] = 1; 
        for (int j = 0; j < i; j++)   
            if (B[i] > B[j] && btwr[i] < btwr[j] + 1)  
                btwr[i] = btwr[j] + 1;  
    } 

    return *(std::max_element(btwr, btwr+n)); 
}  

int main() {
    int N;
    std::cin >> N;
    int A[N], B[N];
    for (int i=0; i<N; i++) {
        std::cin >> A[i] >> B[i];
    }

    bubbleSort(A, B, N);
    std::cout << btwr(A, B, N);
}	
