#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> sta;
int main(){
    //freopen("ans.txt","r",stdin);
    //freopen("ans1.txt","w",stdout);
    int t;
    cin>>t;
    string s;
        getline(cin,s);
    while(t--){
        string s;
        getline(cin,s);
        //cout<<s<<endl;
        bool ok=true;
        while(!sta.empty())sta.pop();
        for(int i=0;i<s.size();i++){
            if(s[i]=='['||s[i]=='('){
                sta.push(s[i]);
            }
            if(s[i]==']'){
                if(sta.size()==0){
                    ok=false;
                    break;
                }
                char x=sta.top();
                if(x=='['){
                    sta.pop();
                }
                else {
                    ok=false;
                    break;
                }
            }
            if(s[i]==')'){
                if(sta.size()==0){
                    ok=false;
                    break;
                }
                char x=sta.top();
                if(x=='('){
                    sta.pop();
                }
                else {
                    ok=false;
                    break;
                }
            }
        }
        if(ok&&sta.size()==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;

}
