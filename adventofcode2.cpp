#include <bits/stdc++.h>
#define MIN(a,b)((a)<(b)?(a):(b))
#define MAX(a,b)((a)>(b)?(a):(b))
using namespace std;

#define RED		0
#define GREEN	1
#define BLUE	2

const int INF = 1e9;

int func1(){	
	// 12 red; 13 green; 14 blues
	int ans = 0;
	ifstream iFile("input");
	string s;

	int game = 0;
	int color[3] = {0};
	int possible = 1;
	while(iFile >> s){
		//cout << s << "\n";
		if(s == "Game"){
			color[0] = color[1] = color[2] = 0;
			game++;
			iFile >> s;
			possible = 1;
			//cout << "RESET\n";
		}else{
			int value;
			if((value = atoi(s.c_str())) != 0){
				string x;
				iFile >> x;

				if(x[0] == 'b') color[BLUE] = MAX(color[BLUE], value);
				if(x[0] == 'r') color[RED]	= MAX(color[RED], value);
				if(x[0] == 'g') color[GREEN] = MAX(color[GREEN], value);

				if(x[x.length()-1] != ','){
					if(!(color[RED] <= 12 && color[GREEN] <= 13 && color[BLUE] <= 14)){
						possible = 0;
					}
				}
				if(x[x.length()-1] != ',' && x[x.length()-1] != ';' && possible){
					cout << "GAME : " << game << " POSSIBLE : " << possible << "\n";
					ans += game;
				}
			}
		}
	
	}
	cout << "ANS: " << ans << "\n";
	return ans;
}

int func2(){	
	int ans = 0;
	ifstream iFile("input");
	string s;

	int game = 0;
	int color[3] = {0};
	while(iFile >> s){
		//cout << s << "\n";
		if(s == "Game"){
			color[0] = color[1] = color[2] = 0;
			game++;
			iFile >> s;
			//cout << "RESET\n";
		}else{
			int value;
			if((value = atoi(s.c_str())) != 0){
				string x;
				iFile >> x;

				if(x[0] == 'b') color[BLUE] = MAX(color[BLUE], value);
				if(x[0] == 'r') color[RED]	= MAX(color[RED], value);
				if(x[0] == 'g') color[GREEN] = MAX(color[GREEN], value);

				if(x[x.length()-1] != ',' && x[x.length()-1] != ';'){
					cout << "GAME " << game << " : POWER : " << color[RED] * color[GREEN] * color[BLUE] << "\n";	
					ans += color[RED] * color[BLUE] * color[GREEN];
				}
			}
		}
	
	}
	cout << "ANS: " << ans << "\n";
	return ans;
}

int main(){
	func2();
}
