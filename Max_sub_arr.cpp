#include <iostream>
#include <vector>

int max( int a , int b ){
	return a >= b ? a : b ; 
}

int max_sum_array(std::vector<int> arr){
	
	std::vector<int> f(arr.size());
	f[0] = arr[0];
	int ans = f[0] ;
	for ( int i = 1; i < arr.size() ; i++ ){
		f[i] = max(arr[i],f[i-1]+arr[i]);
		ans = max(ans,f[i]);
	}
	return ans;
}

int main(){
	
	int n ;
	std::cin>> n ;
	std::vector<int> arr(n);
	while (n--){
		int i;
		std:: cin>> i ;
		arr.push_back(i);
	}

	std::cout << max_sum_array(arr);
}
