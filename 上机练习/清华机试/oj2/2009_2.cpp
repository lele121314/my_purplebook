#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
using namespace std;
int n,m;
char t[100];
map <string,int> pat;
string s[1005];
string p[5005];
int a[10005];
bool cek[5005];
bool check(int n)
{
    for(int i = 0 ;i<n;i++)
    {
        if(cek[i]==0)
            return false;
    }
    return true;
}
map<string,int>::iterator ite;
int main()
{
    while(~scanf("%d",&n))
    {
        pat.clear();
        for(int i = 0 ; i< n ;i++)
        {
            cin>>s[i];
            pat[s[i]] = i;
        }
        scanf("%d",&m);
        int num = 0;
        for(int i = 0;i<m;i++)
        {
            cin>>p[i];            //scanf("%s",p[i]);
            ite = pat.find(p[i]);
            if(ite!=pat.end())
            {
                if(num==0||a[num-1]!=pat[p[i]])
                a[num++] = pat[p[i]];
            }
        }
        int ans = 0;
        memset(cek,0,sizeof(cek));
        for(int i =0;i<num;i++)
        {
         //   cout<<a[i]<<endl;
            cek[a[i]] = 1;
            if(check(n))
            {
                ans++;
                memset(cek,0,sizeof(cek));
            }
        }
        if(n==1)
        {
            int f = 0;
            for(int i = 0;i<m;i++)
                if(p[i]==s[0])
                    f = 1;
            if(f)
                cout<<-1<<endl;
            else
                cout<<0<<endl;
        }
        else
            cout<<ans<<endl;
    }
}


/*
²âÊÔÊý¾Ý£º ´ð°¸2 0 -1
3
166.111.4.100
162.105.131.113
202.112.128.69
10
72.14.235.104
166.111.4.100
207.46.19.190
202.112.128.69
162.105.131.113
118.214.226.52
166.111.4.100
166.111.4.100
162.105.131.113
202.112.128.69

1
166.111.4.101
10
72.14.235.104
166.111.4.100
207.46.19.190
202.112.128.69
162.105.131.113
118.214.226.52
166.111.4.100
166.111.4.100
162.105.131.113
202.112.128.69

1
166.111.4.100
10
72.14.235.104
166.111.4.100
207.46.19.190
202.112.128.69
162.105.131.113
118.214.226.52
166.111.4.100
166.111.4.100
162.105.131.113
202.112.128.69
*/
