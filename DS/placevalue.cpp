#include<bits/stdc++.h>
using namespace std;
int placeval(int num,int val){
    int place=1,rem=0;
    while(num>0){
        rem - num % 10;
        num/=10;
        if(rem == val){
            return place*rem; //if the val is eqal, mult the val wiht the place val got till now and print it 
        }
        place*=10; //for every place val, increase it by mult by 10
    }
    return 0;
}
int main(){
    int n=1345;
    int a = 3;
    cout<<placeval(n,a);
    return 0;
}