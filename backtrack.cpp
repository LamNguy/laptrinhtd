#include <iostream>

// list permutation, O(n*n!)

int n;
bool used[100];
int a[100];

void show(){
	for ( int i = 1; i<=n ; i++){
		std::cout<< a[i];

	}
	std::cout<< std::endl;
}

void back( int pos ){
	if ( pos == n+1 ){
		show();
		return ;
	}

	for (int i =1;i <=n ;i++){
		if ( not used[i]){
			a[pos]=i;
			used[i]=true;
			back(pos+1);
			used[i]= false;
		}
	}

}


int main()
{
	std:: cin >> n ; 
	back(1);
	return 0;
}
