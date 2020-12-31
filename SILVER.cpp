#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int score[N];
    for(int i=0; i<N; i++){
        cin >> score[i];
    }
    int n = sizeof(score)/sizeof(score[0]);
    sort(score, score+n);

    int gold = score[N-1];
    int count = 0;
    int silver = 0;
    int first_silver_id;
    for(int i=N-1; i>=0; i--){
        if(score[i]<gold){
            silver = score[i];
            first_silver_id = i;
            count += score[i];
            break;
        }
    }

    cout<<silver;
}
