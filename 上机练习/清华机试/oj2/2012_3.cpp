#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;


int main()
{
    char N[110] = {0};
    while(cin>>N)
    {
        int i,t = 0;
        int result,num,cnt;
        //result�ǽ����num�ǵ�ǰ�����N��cnt��num������е�1,2����
        result = num = cnt = 0;
        int len = strlen(N);
        for(i = 0; i < len; i++)
        {
            t = N[i] - '0';
            result = (result - cnt)*10 + cnt*(t+1) + num*2 + min(t,2);
            num = num*10 + t;


            if(t == 1 || t == 2)
            cnt++;
            num %= 20123;
            result %= 20123;
        }
        printf("%d\n",result);
    }
    return 0;
}

