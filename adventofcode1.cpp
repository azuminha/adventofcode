#include <bits/stdc++.h>
#define MIN(a,b)(a<b?a:b)
using namespace std;

const int INF = 1e9;

int func1(){
	ifstream iFile("input.txt");
	string s;
	
	long long int ans = 0;
	while(iFile >> s){
		int a, b;
		a = b = -1;

		for(int i=0; i<s.length(); ++i){
			if(s[i] >= '0' && s[i] <= '9'){
				if(a == -1){
					a = s[i] - '0';
					b = a;
				}
				else b = s[i] - '0';
			}
		}
		ans += a*10 + b;
	}
	cout << ans << "\n";
	return ans;
}

int func2(){
	ifstream iFile("input.txt");
	string s;
	string numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


	long long int ans = 0;
	while(iFile >> s){
		vector<int> pos[10];
		pair<int, int> a = {-1, INF} , b = {-1, -1};

		for(int i=0; i<9; ++i){
			int p = s.find(numbers[i]), k = 1;// arrumar tenho que colocar todos os aparecimentos
			while(p != -1){
				pos[i+1].push_back(p);
				p = s.find(numbers[i], p+k);
				k++;
			}
		}

		for(int i=0; i<s.length(); ++i){
			if(s[i] >= '0' && s[i] <= '9'){
				int x = s[i] - '0';
				pos[x].push_back(i);
			}
		}
		for(int i=0; i<10; ++i){
			for(auto v: pos[i]){
				a = (v < a.second ? make_pair(i, v) : a);
				b = (v > b.second ? make_pair(i, v) : b);
			}
		}
		//cout << a.first*10 + b.first << "\n";
		ans += a.first*10 + b.first;
	}
	cout << ans << "\n";
	return ans;
}

int main(){
	func2();
}
