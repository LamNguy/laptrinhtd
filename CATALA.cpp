#include<iostream>
using namespace std;
long int catalan( int n) {
   if (n <= 1){
      return 1;
   }
   long int result = 0;
   for (int i=0; i<n; i++){
      result += catalan(i)*catalan(n-i-1);
   }
   return result;
}
int main(){
   int n ;
   cin >> n ;
   int a = 1e9+7 ;
   long int result = catalan(n) % a ;
   std::cout << result;
   return 0;
}
