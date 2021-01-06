#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
 
int mem[50][50][50]; // Memorize visited states
 
void eval(const int& x, int &y, int &z) {
	if(x != -1) {
		y++;
		z += x;
	}
}
 
int solve(int r, int b, int out) {
 
	if(mem[r][b][out] != -1) return mem[r][b][out]; // Memorization
	else if(r == 1 && b == 0) return mem[r][b][out] = 0; // Base case one, we have a red ball
	else if(r == 0 && b == 1) return mem[r][b][out] = 1; // Base case two, we have a blue ball
	
	int cnt = 0, sum = 0;
	int val;
	
	/* Move 2 Red balls */
	if(r >= 2) {
		val = solve(r-1, b, out); // val should be equal to 0 which is red, and 1 which is blue
		eval(val, cnt, sum); // This is only to check if we can reach different base cases, but this will not happen in our example
	}
	 
	/* Move 2 Blue balls */
	if(b >= 2) {
		val = solve(r+1, b-2, out-1);
		eval(val, cnt, sum);
	}
	
	/* Move 1 Red, and 1 Blue */
	if(r >= 1 && b >= 1) {
		val = solve(r-1, b, out+1);
		eval(val, cnt, sum);
	}
	
	if(sum == 0) return mem[r][b][out] = 0; // Red ball
	else if(sum == cnt) return mem[r][b][out] = 1; // Blue ball
	return -1; // Some cases can be Red, and the other are Blue
}
 
int main() {
	memset(mem, -1, sizeof mem); // Doing init
	cout << solve(23, 21, 22) << endl; // Solve..
}
