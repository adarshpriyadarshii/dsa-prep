#include <iostream>
using namespace std;

int n=20;

class queue{
    int* arr;
    int front,back;
    public:
    queue(){
        arr =new int[n];
        front=-1,back=-1;
    }
    void push(int x){
        if(back==n-1){
            cout<<"Queue Full"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front++;
        }
    }
    void pop(){
        if(front==-1 || front>back){
            cout<<"Empty Queue"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 || front>back){
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front==-1 || front>back){
            cout<<"Empty Queue"<<endl;
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    int ans;
    ans=q.peek();
    cout<<ans<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    ans=q.peek();
    cout<<ans<<endl;
    q.pop();
    ans=q.peek();
    cout<<ans<<endl;
}