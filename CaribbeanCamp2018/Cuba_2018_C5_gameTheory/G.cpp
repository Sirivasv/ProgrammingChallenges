#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

const int MAXN = 1000000;	
bool malo[MAXN + 2];

int main(){
	
	int k ;
	int N , M ;
	
	optimizar_io(0);
	
	cin >> k;
	vector<int> valor(k);
	for(int i = 0 ; i < k ; i++) cin >> valor[i];

	malo[0] = true;
	for(int i = 1 ; i <= MAXN ; i++){
		malo[i] = true;
		for(int j = 0 ; j < k ; j++){
			if( i - valor[j] < 0 ) continue;
			if(malo[i-valor[j]]){
				malo[i] = false;
				break;
			}
		}
	
	}
	
	cin >> M ;
	for(int i = 0 ; i < M ; i++){
		cin >> N ; 
		cout << (malo[N] ? "Second\n" : "First\n") ; 
	}
	
	return 0;
}
