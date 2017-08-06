#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000000;
map<string,int> mp;
vector<string> vc;
vector<int> depend[maxn],depend2[maxn],installed;
int status[maxn];

int id(string& s){
    if(mp.count(s))return mp[s];
    vc.push_back(s);
    return mp[s]=vc.size()-1;
}
void install(int item,bool toplevel){
    if(!status[item]){
        for(int i=0;i<depend[item].size();i++){
            install(depend[item][i],false);
        }
        cout<<"   Installing "<<vc[item]<<"\n";
        status[item]=toplevel?1:2;
        installed.push_back(item);
    }
    else if(toplevel){
        cout<<"   "<<vc[item]<<" is already installed."<<endl;
    }
}
bool needed(int item){
    for(int i=0;i<depend2[item].size();i++){
        if(status[depend2[item][i]])return true;
    }
    return false;
}
void rremove(int item,bool toplevel){
    if(status[item]==0&&toplevel){
        cout<<"   "<<vc[item]<<" is not installed."<<endl;
    }
    else if((toplevel||status[item]==2)){
        if(!needed(item)){
            status[item]=0;
            installed.erase(remove(installed.begin(),installed.end(),item),installed.end());
            cout<<"   Removing "<<vc[item]<<endl;
            for(int i=0;i<depend[item].size();i++)
                rremove(depend[item][i],false);
        }else if(toplevel) cout<<"   "<<vc[item]<<" is still needed."<<endl;
    }
}
int main(){
   freopen("ans.txt","r",stdin);
  freopen("ans1.txt","w",stdout);
    memset(status, 0, sizeof(status));
    string buf;
    while(getline(cin,buf)){
        if (buf[0]=='E')break;
        cout<<buf<<endl;
        stringstream ss(buf);
        string command;
        ss>>command;
        if(command[0]=='D'){
            string item1,item2;
            ss>>item1;
            int id1=id(item1);
            while(ss>>item2){
                int id2=id(item2);
                depend[id1].push_back(id2);
                depend2[id2].push_back(id1);
            }
        }
        else if(command[0]=='I'){
            string item1;
            ss>>item1;
            int id1=id(item1);
            install(id1,true);
        }
        else if(command[0]=='R'){
            string item1;
            ss>>item1;
            int id1=id(item1);
            rremove(id1,true);
        }
        else if(command[0]=='L'){
            for(int i=0;i<installed.size();i++){
                cout<<"   "<<vc[installed[i]]<<endl;
            }
        }

    }
    cout<<"END"<<endl;
    return 0;
}
