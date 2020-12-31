// ý tưởng dùng backtrack liệt kê các chữ số có n chữ số
// tạo 1 struct lưu giá trị của số đó và tổng các chữ số trong số đó
// duyệt vòng lặp O(n^2) để tìm ra được chênh lệch lớn nhất


#include <iostream>
#include <vector>
#include <cmath>

int n ;
int a[100] ;

struct result {
    int value ;
    int sum ;
};

// vector of struct result
std::vector<result> vec ;

int max_difference () {
    int max = -1 ;
    for ( int i = vec.size()-1 ; i >=0 ; i-- ){
        for ( int j = i - 1 ; j >=0 ; j--){
            if (vec[i].sum == vec[j].sum){
                if ( max < vec[i].value - vec[j].value ){
                    max = vec[i].value - vec[j].value ;
                    //std::cout<<vec[i].value << " " << vec[j].value << std::endl ;
                }

            }
        }
    }
    return max ;
}

void init(){
    int value = 0 ;
    int sum = 0 ;
    for ( int i = 1 ; i <= n ; i++ ){
        if ( a[1] == 0 ) return ;
        sum+= a[i] ;
        value += a[i]*pow(10,n-i);
    }
    result test ;
    test.value =value ;
    test.sum = sum ;
    vec.push_back( test ) ;

}


void back ( int  pos ) {
    if ( pos ==  n+1) {
        init();
        return ;
    }

    for  (  int i = 0 ; i <= 9 ; i++ ){
        a[pos] = i ;
        back(pos+1) ;
    }

}


int main() {
    std::cin >> n  ;

    // kiem tra dieu kien n ở đây

    back(1);
    int res = max_difference();
    std::cout << res ;
    return 0;
}
