#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int minEle;
void getMin(){
    if(s.size()==0) cout<< -1<<endl;
    cout<<minEle<<endl;
}
void Push(int a){
    if(s.size()==0 ){ 
        s.push(a);
        minEle=a;
        }
    else{
        if(a>=minEle)s.push(a);
        else if(a<minEle){
            s.push(2*a-minEle);
            minEle=a;
        }
    }
}
void Pop(){
    if(s.size()==0)cout<<-1<<endl;
   else{
       if(s.top()>=minEle)s.pop();
       else if(s.top()<minEle){
           minEle=2*minEle-s.top();
           s.pop();
       }
   }
}
void Top(){
    if(s.size()==0)cout<< -1<<endl;
    else{
        if(s.top()>=minEle)cout<< s.top()<<endl;
        else if(s.top()<minEle){
            cout<< minEle<<endl;
        }
    }
}

int main(){
    Push(18);
    Push(19);
    Push(29);
    getMin();
    Top();
    Pop();
    Push(15);
    Push(16);
    getMin();
    Top();
    Pop();
    Top();
    return 0;
}