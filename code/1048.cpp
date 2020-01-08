#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return f * x; 
}
template<class T>
void rev(T* arr, int siz){
    T tmp;
    for (int i = 0; i < siz >> 1; ++i)
        tmp = arr[i], arr[i] = arr[siz - i - 1], arr[siz - i - 1] = tmp;
}
class Solution {
public:
    string convert(string s, int numRows) {
        
    }
};
Solution sol;
void init(){
    int v[] = {1, 2, 3, 4, 5};
    double b[] = {1, 2, 3, 4, 5, 6.7};
    rev(b, 5);
    for (int i = 0; i < 5; ++i)
        cout << b[i] << endl;
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
