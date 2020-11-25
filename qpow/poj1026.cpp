#include<iostream>
#include <cstring>
#define ll long long
using namespace std;
const int N=2e5+10;
// void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
int to[210],kto[210],a[210],temp[210];
int n,k;
char temps[210];
void print()
{
	cout<<"kto"<<endl;
	for(int i=1;i<=n;i++)
		cout<<kto[i]<<" ";
	cout<<endl;
}
void printa()
{
	cout<<"a"<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void qchange()
{
	for(int i=1;i<=n;i++)
		kto[i]=i;
	memcpy(a,to,sizeof(int)*210);
	// print();
	while(k)
	{
		if(k&1)
		{
			memcpy(temp,kto,sizeof(int)*210);
			for(int i=1;i<=n;i++)
				kto[a[i]]=temp[i];
		}
		k>>=1;
		memcpy(temp,a,sizeof(int)*210);
		for(int i=1;i<=n;i++)
			a[i]=temp[temp[i]];
	}
}
int main(int argc, char const *argv[])
{
	char s[210]={};
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&to[i]);
		}
		while(1)
		{
			scanf("%d",&k);
			if(k==0)break;
			getchar();
			fgets(s+1,201,stdin);
			int len=strlen(s+1);
			for(int i=len;i<=n;i++)
			{
				s[i]=' ';
			}
			s[n+1]='\0';
			// printf("%s\n",s+1 );
			qchange();
			memcpy(temps,s,sizeof(char)*210);
			for(int i=1;i<=n;i++)
				s[i]=temps[kto[i]];
			for(int i=1;i<=n;i++)
				printf("%c",s[i] );
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}