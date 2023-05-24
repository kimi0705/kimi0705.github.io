#include <bits/stdc++.h>
using namespace std;
string s;
int i;
int main() {
	while(cin >> s) {
		if(++i % 50) {
			cout << "CF" << s << ',';
		} else {
			cout << "CF" << s << '\n';
		}
	}
}
