#include<queue>
#include<cstdio>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    printf("%d",q.front());
    q.pop();
    printf("%d",q.front());
}
