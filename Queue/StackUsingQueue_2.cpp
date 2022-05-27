#include <iostream>
#include <queue>
using namespace std;

//Method 2: using one queue.

class stack{
    queue<int> q;
    public:
    void push(int x){
       q.push(x);
       for(int i=0;i<q.size()-1;i++){
           q.push(q.front());
           q.pop();
       }
    }
    void pop(){
        q.pop();
    }
    int top(){
       return  q.front();
    }
    bool empty(){
        return q.empty();
    }
};

int main(){
    stack s;
    int ans;
    s.push(10);
    s.push(20);
    s.push(70);
    ans=s.top();
    cout<<ans<<endl;
    s.pop();
    ans=s.top();
    cout<<ans<<endl;
}