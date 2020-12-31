#include <iostream>
#include <climits>
#include <cmath>
int dp [1000] = {0};
int C,N ;

int minCoins(int C , int N , int coins[])
{
  // C: value, N:number of coins
  
  // initiate
  for(int i = 0;i<= C	 ;i++)
    dp[i] = INT_MAX;
  
  // base case
  dp[0] = 0;
 
  for(int i = 1;i<= C ;i++)
  {
    for(int j = 0;j< N ;j++)
    {
      
      if(coins[j] <= i)
      {
        dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }
  return dp[C];
}

int main() {

  std::cin >> C >> N ; 
  int coins[N];
  for ( int i = 0 ; i < N ; i++){
  	std:: cin >> coins[i];
  }

  std::cout << minCoins( C ,N, coins);
}
