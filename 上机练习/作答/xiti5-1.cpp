#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
int siz[200]={0};
vector<string> ad[1050];
void pint(int x){
    for(int i=0;i<x;i++)cout<<' ';
}

int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    memset(siz,0,sizeof(siz));
    string s;
    int line=0;
    while(getline(cin,s)){
        stringstream ss(s);
        string words;
        int col=0;
        while(ss>>words){
            ad[line].push_back(words);
            if(words.size()>siz[col])siz[col]=words.size();
            col++;
        }
        line++;
    }
    for(int i=0;i<line;i++){
        for(int j=0;j<ad[i].size();j++){
            cout<<ad[i][j];

            if(j!=ad[i].size()-1){
                    cout<<' ';
            pint(siz[j]-ad[i][j].size());
            }
        }
        cout<<endl;
    }
}
