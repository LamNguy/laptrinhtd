#include <iostream>
#include <cstring>

#define maxN 20

using namespace std;

int n, best_a[maxN], a[maxN], b[2*maxN], c[2*maxN], d[maxN];

long w[maxN][maxN];

long long bestsum = -1;

void read_input(){

    cin >> n;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> w[i][j];
        }
    }
}

void perfect() {

    long long sum=0;

    for (int i=1; i<=n; i++){
        sum += w[i][a[i]];
    }

    if (sum>bestsum) {

        bestsum=sum;

        memmove(best_a, a, sizeof(a));

    }
}

void find(int i){

    for(int j=1;j<=n;j++){

        if(!d[j]&&!b[i+j]&&!c[i-j]) {

            d[j]=1;b[i+j]=1;c[i-j]=1;

            a[i]=j;

            if(i==n){
                perfect();
            }

            else{
                find(i+1);
            }

            d[j]=0;b[i+j]=0;c[i-j]=0;

        }
    }

}

int main(){
    read_input();

    find(1);

    cout << bestsum << endl;

    for (int i=1; i<=n; i++){
        cout << best_a[i];
    }

    return 0;

}
