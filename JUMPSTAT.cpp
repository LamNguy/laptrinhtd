#include<iostream>
using namespace std; 
int countWaysUtil(int n, int m) 
{ 
    int res[n]; 
    res[0] = 1; 
    res[1] = 1; 
      
    for(int i = 2; i < n; i++)  
    { 
       res[i] = 0; 
         
       for(int j = 1; j <= m && j <= i; j++) 
          res[i] += res[i - j]; 
    } 
    return res[n - 1]; 
} 
  
// Returns number of ways to reach s'th stair 
int countWays(int s, int m) 
{ 
    return countWaysUtil(s + 1, m); 
} 
  
// Driver code 
int main() 
{ 
    int n ; 
    cin >> n ;
      
    cout << "Number of ways = " << countWays(n-1, n); 
           
    return 0; 
} 

// 11111
// 1211
// 1121
// 2111
// 1112
// 221
// 121
// 212
