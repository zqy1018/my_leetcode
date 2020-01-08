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
    string fractionToDecimal(int numerator, int denominator) {
		if (!numerator) return string("0");
		string ans;
		
		int flag1 = 0, flag2 = 0;
		long long n = numerator, d = denominator;
		if (numerator < 0) ++flag1, n = -n;
		if (denominator < 0) ++flag2, d = -d;
		if (flag1 + flag2 == 1) ans.push_back('-');

        if (n >= d)
			ans += to_string(n / d), 
			n %= d;
		else ans.push_back('0');
		if (!n) return ans;

		long long g = __gcd(n, d);
		n /= g, d /= g;

		vector<int> val(1, 0);
		unordered_map<int, int> mp;

		int cnt = 0, cycle, shang, yushu;
		for(; n; n *= 10ll){
			shang = n / d, 
			yushu = n % d;
			cout << n << "  " << d << endl;
			val.push_back(shang), ++cnt;
			if(mp.count(yushu)) 
				break;
			mp[yushu] = cnt;
			n %= d;
		}
		ans.push_back('.');
		if(!n){
			for (int i = 2; i <= cnt; ++i)
				ans.push_back(val[i] + '0');
		}else{
			cycle = mp[yushu] + 1;
			for(int i = 2; i < cycle; ++i)
				ans.push_back(val[i] + '0');
			ans.push_back('(');
			for(int i = cycle; i <= cnt; ++i)
				ans.push_back(val[i] + '0');
			ans.push_back(')');
		}
		return ans;
    }
};
Solution sol;
void init(){
    cout << sol.fractionToDecimal(-1, INT_MIN) << endl;
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
