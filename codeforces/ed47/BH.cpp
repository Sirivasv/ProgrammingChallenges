#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main()
{
	ll n,i,j,k;
	string s;
	cin >> s;
	ll len=s.size();
	string ans="";
	string an="",ter="",fin="";
	for(i=0;i<len;i++)
	{
		if(s[i]!='1')
			ans+=s[i];
		else
			an+=s[i];
	}
	for(i=0;i<ans.size();i++)
	{
		if(ans[i]=='2')
		{
			for(j=i;j<ans.size();j++)
				fin+=ans[j];
			break;
		}
		else
			ter+=ans[i];	
	}

	cout << ter+an+fin <<endl;
}