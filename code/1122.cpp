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
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<pair<int, int> > vec;
        map<int, int> mp;
        for (int i = 0; i < arr2.size(); ++i){
            mp[arr2[i]] = i;
        }
        for (int i = 0; i < arr1.size(); ++i){
            if(mp.count(arr1[i]))
                vec.push_back(make_pair(mp[arr1[i]], arr1[i]));
            else vec.push_back(make_pair(arr2.size(), arr1[i]));
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < arr1.size(); ++i){
            arr1[i] = vec[i].second;
        }
        return arr1;
    }
};
Solution sol;
void init(){
    
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
