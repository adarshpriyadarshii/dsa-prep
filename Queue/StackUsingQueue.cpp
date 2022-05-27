#include <iostream>
#include <queue>
using namespace std;

//Method 1: using two queues.

class stack{
    queue<int> q;
    public:
    void push(int x){
        queue<int> temp;
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        swap(q,temp);
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