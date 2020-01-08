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
    int calculate(string s) {
        s = "(" + s + ")";
        stack<int> operand;
        stack<char> oprt;

        auto calc = [&operand, &oprt]() -> void{
            int r2 = operand.top();
            operand.pop();
            int r1 = operand.top();
            operand.pop();
            if(oprt.top() == '+') operand.push(r1 + r2);
            else operand.push(r1 - r2);
            oprt.pop();
        };

        int n = s.size();
        for (int i = 0, t = -1; i < n; ++i){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                if(t < 0) t = s[i] - '0';
                else t = t * 10 + (s[i] - '0');
            }else{
                if(s[i] == '('){
                    oprt.push(s[i]);
                }else{
                    if(t >= 0) operand.push(t), t = -1;
                    while(oprt.top() != '(')
                        calc();
                    if(s[i] == ')') oprt.pop();
                    else oprt.push(s[i]);
                }
            }
        }
        return operand.top();
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
