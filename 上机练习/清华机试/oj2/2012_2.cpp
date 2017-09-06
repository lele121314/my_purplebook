#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
int n;
string s;
set<string> se;
bool is_find(string &ss){
    if(ss.find("2012")!=-1)return true;
    else return false;
}
void judge(){
    queue<string> q1;
    queue<int> q2;
    q1.push(s);
    q2.push(0);
    se.insert(s);
    while(!q1.empty()){
        string ss=q1.front();q1.pop();
        int step=q2.front();q2.pop();
        if(is_find(ss)){
            cout<<step<<endl;
            return;
        }
        for(int i=0;i<n-1;i++){
            string temp=ss;
            //cout<<temp<<endl;
            swap(temp[i],temp[i+1]);
            //cout<<temp<<endl;
            if(se.count(temp))continue;
            se.insert(temp);
            q1.push(temp);
            q2.push(step+1);
        }
    }
}
void solve(){
    if(n<4){
        cout<<-1<<endl;
        return ;
    }
    int a[3]={0};
    for(int i=0;i<s.size();i++){
        a[s[i]-'0']++;
    }
    if(a[0]<1||a[1]<1||a[2]<2){
        cout<<-1<<endl;
        return ;
    }
    judge();
}
int main(){
    while(cin>>n>>s){
        se.clear();
        solve();
    }
    return 0;
}
