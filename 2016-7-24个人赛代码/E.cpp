#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
int t,cas;
int m;
char s[110][110];
int num[110];
int len;
int anspos;
bool flag1,flag2;
bool flaga,flagb,flagc;
map<string,bool>mp;
int cnt1[110][10];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %s",&cas,&m,s[1]);
		mp.clear();
		memset(cnt1,0,sizeof(cnt1));
		flag1=flag2=false;
		len=strlen(s[1]);
		mp[s[1]]=true;
		for(int i=0;i<len;i++)
			cnt1[1][s[1][i]-'0']++;
		for(int j=2;j<=m;j++)
		{
			for(int i=0;i<len;i++)
			{
				num[i]=s[j-1][i]-'0'+s[j-1][len-1-i]-'0';
			}
			for(int i=0;i<len-1;i++)
			{
				if(num[i]>=10)
				{
					num[i]-=10;
					num[i+1]++;
				}
			}
			if(num[len-1]>=10)
			{
				num[len-1]-=10;
				num[len]=1;
				len++;
			}
			sort(num,num+len);
			int pos=0;
			while(num[pos]==0)
				pos++;
			int cnt=0;
			for(int i=pos;i<len;i++)
			{
				s[j][cnt++]='0'+num[i];
				cnt1[j][num[i]]++;
			}
			s[j][cnt]='\0';
			len=cnt;
			if(mp[s[j]])
			{
				anspos=j;
				flag1=true;
				break;
			}
			else
			{
				mp[s[j]]=true;
			}
			if((cnt1[j][1]==1&&cnt1[j][2]==1&&cnt1[j][3]>=2&&cnt1[j][4]==4&&cnt1[j][1]+cnt1[j][2]+cnt1[j][3]+cnt1[j][4]==cnt)
				||(cnt1[j][5]==2&&cnt1[j][6]>=2&&cnt1[j][7]==4&&cnt1[j][5]+cnt1[j][6]+cnt1[j][7]==cnt))
			{
				flag2=true;
				anspos=j;
				break;
			}
		}
		len=strlen(s[1]);
		int j=1;
		if((cnt1[j][1]==1&&cnt1[j][2]==1&&cnt1[j][3]>=2&&cnt1[j][4]==4&&cnt1[j][1]+cnt1[j][2]+cnt1[j][3]+cnt1[j][4]==len)
				||(cnt1[j][5]==2&&cnt1[j][6]>=2&&cnt1[j][7]==4&&cnt1[j][5]+cnt1[j][6]+cnt1[j][7]==len))
		{
			flag2=true;
			anspos=j;
		}
		if(flag1)
			printf("%d R %d\n",cas,anspos);
		else if(flag2)
			printf("%d C %d\n",cas,anspos);
		else
			printf("%d %s\n",cas,s[m]);
	}
}