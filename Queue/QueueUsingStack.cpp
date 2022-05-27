#include <iostream>
#include <stack>
using namespace std;

class queue{
    stack<int> s1,s2;
    public:
    void push(int x){
        s1.push(x);
    }
    void pop(){
        if(!s2.empty()){
            s2.pop();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
    int top(){
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};

int main(){
    queue s;
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