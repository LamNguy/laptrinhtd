#include <iostream>
#include <algorithm>
using namespace std;

struct pine{
    int start;
    int end;
};

// 1 if a < b
// 0 if a > b 
 
bool compare_pine( pine a , pine b ){
    if (a.start <= b.start )
        return a.end <= b.end;

    return 0 ; 
}   


int n ;

int main(){

    cin >> n ;
    pine arr[n];
    for ( int i = 0 ; i < n ; i++ ){
        int a, b;
        cin >> a >> b ;
        int start ,  end ;
        if (a < b ){
            start = a;
            end = b;
        } else {
            start =b ;
            end = a ;
        }
        arr[i].start = start;
        arr[i].end = end;

    }


    sort(arr, arr+n , compare_pine);
    

    int count = 1;
    int max_distance = 0;
    int max_start = arr[0].start;
    int max_end = arr[0].end;
    for ( int i = 0 ; i < n-1 ; i++ ){
        if ( arr[i].end >= arr[i+1].start ){
            max_end=arr[i+1].end;
        } else {
            count++ ;
            if (max_distance < max_end - max_start ){
                max_distance = max_end - max_start;   
            }
            max_start = arr[i+1].start;
            max_end = arr[i+1].end ;
        }

    }
    
    if (max_distance < max_end - max_start ) max_distance = max_end - max_start ;
    cout << count << " " << max_distance ;
    return 0;
}
