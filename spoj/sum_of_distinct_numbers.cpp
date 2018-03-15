#include <bits/stdc++.h>
using namespace std;

typedef long lli;
typedef pair<unsigned short int, int> pil; 
typedef pair<char, pil> pcil;

struct node{

	lli val;
	node *izq,*der;

	node(): izq(NULL),der(NULL),val(0){}

};

typedef node* pnode;
const int MAXQ = 100009;
const int MAXN = 50009;
 
int N;
pnode ST[MAXN * 2 + 35000];

lli query(int inir, int finr, pnode &raiz, int ini = 1, int fin = N + 1){

	if( finr < ini || fin < inir ) return 0;
	if (raiz == NULL) return 0;
	if(ini >= inir && fin <= finr){
		return raiz->val;
	}

	int mitad = (ini+fin)/2;
	return query(inir, finr, raiz->izq, ini, mitad) + query(inir, finr, raiz->der, mitad + 1, fin);
}

void update(int pos, lli val, pnode &raiz, int ini = 1, int fin = N + 1) {
	// cout << pos << ' ' << val << ' ' << ini << ' ' << fin << '\n';
	if (raiz == NULL) raiz = new node();
	if( pos < ini || fin < pos ) return;
	if(ini == pos && fin == pos){
		raiz->val += val;
		return;
	}	
	
	int mitad = (ini+fin)/2;
	update(pos, val, raiz->izq, ini, mitad);
	update(pos, val, raiz->der, mitad+1, fin);
	
	raiz->val = raiz->izq->val + raiz->der->val;
}

void Update(int pos, int posInTree, lli val, int n = 1, int ini = 1, int fin = N) {
	// cout << pos << ' ' << posInTree << ' ' << val << ' ' << n << ' ' << ini << ' ' << fin << '\n'; 
	if( pos < ini || fin < pos ) return;
	update(posInTree, val, ST[n]);
	if (ini == fin) return;
	int mitad = (ini + fin) / 2, ls = n << 1, rs = ls + 1;
	Update(pos, posInTree, val, ls, ini, mitad);
	Update(pos, posInTree, val, rs, mitad + 1, fin);
}

lli Query(int inir, int finr, int inirInTree, int finrInTree = N + 1, int n = 1, int ini = 1, int fin = N) {
	if( finr < ini || fin < inir ) return 0;
	if(ini >= inir && fin <= finr){
		return query(inirInTree, finrInTree, ST[n]);
	} 
	int mitad = (ini + fin) / 2, ls = n << 1, rs = ls + 1;
	return Query(inir, finr, inirInTree, finrInTree, ls, ini, mitad) + Query(inir, finr, inirInTree, finrInTree, rs, mitad + 1, fin);
}

int arr[MAXN];
pcil oper[MAXQ];
set<unsigned short int> ocur[MAXQ + MAXN];

int main() {
	// cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N;
	// scanf("%d", &N);
	map<int, unsigned short int> mp;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		// scanf("%d", &arr[i]);
		mp[arr[i]] = 1;
	}
	
	int Q;

	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		cin >> oper[i].first;
		// oper[i].first = getchar();
		int xi, yi;
		cin >> xi >> yi;
		// scanf("%d%d", &xi, &yi);
		oper[i].second.first = xi;
		oper[i].second.second = yi;
		if (oper[i].first == 'U') mp[oper[i].second.second] = 1;
	}

	
	int cnt = 1;

	for (auto it : mp) {
		ocur[cnt].insert(0);
		ocur[cnt].insert(N + 1);
		mp[it.first] = cnt++;
	}
	
	for (int i = 1; i <= N; ++i) {
		ocur[mp[arr[i]]].insert(i);
	}
	
	for (int i = 1; i <= N; ++i) {
		auto nextIterator = ocur[mp[arr[i]]].upper_bound(i);
		// cout << "BUP: " << i << ' ' << *nextIterator << ' ' << arr[i] << '\n'; 
		Update(i, *nextIterator, arr[i]);
	}

	for (int i = 0; i < Q; ++i) {
		if (oper[i].first == 'Q') {
			cout << Query(oper[i].second.first, oper[i].second.second, oper[i].second.second + 1) << '\n';
			// printf("%lld\n", Query(oper[i].second.first, oper[i].second.second, oper[i].second.second + 1));
		} else {
			auto currentIterator = ocur[mp[arr[oper[i].second.first]]].lower_bound(oper[i].second.first);
			auto previousIterator = currentIterator; --previousIterator;
			auto nextIterator = currentIterator; ++nextIterator;
			// removing old element
			if (*previousIterator > 0) {
				// cout << *previousIterator << ' ' << *nextIterator << ' ' << oper[i].second.first << ' ' << arr[*previousIterator] << '\n';
				Update(*previousIterator, oper[i].second.first, -arr[*previousIterator]);
				Update(*previousIterator, *nextIterator, arr[*previousIterator]);
			}

			// cout << oper[i].second.first << ' ' << *nextIterator << ' ' << arr[oper[i].second.first] << '\n';
			Update(oper[i].second.first, *nextIterator, -arr[oper[i].second.first]);
			ocur[mp[arr[oper[i].second.first]]].erase(currentIterator);

			// adding new element
			arr[oper[i].second.first] = oper[i].second.second;
			ocur[mp[arr[oper[i].second.first]]].insert(oper[i].second.first);
			currentIterator = ocur[mp[arr[oper[i].second.first]]].lower_bound(oper[i].second.first);
			previousIterator = currentIterator; --previousIterator;
			nextIterator = currentIterator; ++nextIterator;
			if (*previousIterator > 0) {
				// cout << *previousIterator << ' ' << *nextIterator << ' ' << oper[i].second.first << ' ' << arr[*previousIterator] << '\n';
				Update(*previousIterator, oper[i].second.first, arr[*previousIterator]);
				Update(*previousIterator, *nextIterator, -arr[*previousIterator]);
			}
			Update(oper[i].second.first, *nextIterator, arr[oper[i].second.first]);
		}
	}

	return 0;
}