#define maxN 1001

using namespace std;

long n, sum, best_sum= 6*maxN, xoay, best_xoay=maxN+1;

long h[maxN], x[maxN], best_x[maxN], lsum;


void check() {
    int xoay = 0;
    for (int i=1; i<=n; i++) {
        if (x[i]==1) {
            sum -= 2*h[i];
            xoay++;
        }
    }

    if (sum<0) sum = -sum;

    if ((sum<best_sum)||((sum=best_sum)&&(xoay<best_xoay))) {
        best_sum = sum;
        best_xoay = xoay;
    }
}

void creat_(int i) {
    for (int j=0; j<=1; j++) {
        x[i]=j;
        if (i==n) {
            check();
            xoay = 0; sum = lsum;
        }
        else{
            creat_(i+1);
        }
    }
}

int main(){
    creat_(1);
    return 0;
}
