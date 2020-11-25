#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res*=a;
		b>>=1;
		a*=a;
	}
	return res;
}
void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
int main(int argc, char const *argv[])
{
	io();
	cout<<qpow(2,3);
	return 0;
}