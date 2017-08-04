#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef struct e{
    string name,auth;
//    int state=0;
    //0 on 1 borrow 2 return
    bool operator < (const e &b) const{
        if(auth!=b.auth)return auth<b.auth;
        return name<b.name;
    }
}book ;

vector<book> bo;
map<string,int > ma;
void okk(char op,string& name){
    if(op=='B')ma[name]=1;
    else ma[name]=2;
}
void solve(){
    int begi=0;
    for(int i=0;i<bo.size();i++){
            //cout<<bo[i].name<<ma[bo[i].name]<<endl;

        if(ma[bo[i].name]==1)begi++;
        else if(ma[bo[i].name]==2){

            ma[bo[i].name]=0;

            if(i==begi)cout<<"Put "<<bo[i].name<<" first"<<endl;
            else {
                int j;
                for( j=i-1;j>=0;j--){
                    //cout<<bo[j].name<<','<<ma[bo[j].name]<<endl;
                    if (ma[bo[j].name]==0)break;
                }
                cout<<"Put "<<bo[i].name<<" after "<<bo[j].name<<endl;
            }
            begi=10000;
        }
        else begi=10000;
    }
    cout<<"END"<<endl;
}

int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    string s;
    while(getline(cin,s)){
        if(s[0]=='E')break;
        int by=s.find(" by ");
        book tem;
        tem.name=s.substr(0,by);
        tem.auth=s.substr(by+4);
        ma[tem.name]=0;
        bo.push_back(tem);
        //cout<<tem.name<<endl;
    }
    sort(bo.begin(),bo.end());
//    for(int i=0;i<bo.size();i++){
//        cout<<bo[i].name<<','<<bo[i].auth<<endl;
//    }
//
//    cout<<endl<<endl;
    while(getline(cin,s)){
        if(s[0]=='E')break;
        if(s[0]=='S'){solve();continue;}
        int lo=s.find('"');

        string nam=s.substr(lo);
        //cout<<ma[nam]<<endl;
        //cout<<nam<<endl;
        okk(s[0],nam);
        //cout<<ma[nam]<<endl;
    }
   // cout<<"END"<<endl;
    return 0;
}
