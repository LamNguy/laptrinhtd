#include <bits/stdc++.h> 
using namespace std; 

  
int main() 
{ 
    int N, L ;
    cin >> N;
    cin >> L;
    int arr[L];
    for (int i = 0; i < L; i++){
        cin >> arr[i];
    }  
    
    vector<int> track;
    int count = 1;
    while (track.size() < N) {
        bool check = false;
        for (int i = 0; i < L; i++){
            std::string e = std::to_string(arr[i]);
            std::string c = std::to_string(count);
            if (c.find(e) != std::string::npos){
                check = true;
                count ++;
            }
        }
        if (!check) {
            track.push_back(count);
            count ++;
        }
    }
    cout << track.back() ;
}
