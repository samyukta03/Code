// Input vanthu two strings.
// The output should be yes or no.
// If two strings has no common letter then output should be yes 
// Incase of atleast one common letter, op should be no
// Eg
// Input 
// 1st string --> Abcd 
// 2nd string --> cfge
// Output
// No
------------------------------Case sensitive --------------------------------------
#include<bits/stdc++.h>
using namespace std;
bool commonchar(string a,string b){
    int arr1[26]={0}; //,arr2[26]={0};
    for(auto x:a)
      arr1[x-'a']++;
/* the below doesnt work bcz if there are repeated char in str a and not in b then that means it shoulf print yes 
so we store the freq of char in str1 and then compare it with char in str 2, so 
if theres gonna be repeated chat in str2 then it count will already be >=1, so then return false 
     for(auto y:b)
     arr2[y-'a']++;  */ 
    for(auto y:b){
        if(arr1[y-'a'] >= 1) {
            return false;
            // break ;   this si not needed bcz the return statement itself returns to the fn call 
        }
    }
    return true;
}
int main(){
    string a="aaabb";
    string b="codeb";
    if(commonchar(a,b)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
------------------------------Case insensitive --------------------------------------
#include<bits/stdc++.h>
using namespace std;
bool commonchar(string a,string b){
    int arr1[256]={0}; 
    for(auto x:a) { 
       if(x >='A' && x <='Z')
       arr1[x-'a'+32]=1; //a - 97 A-65, so if A occurs then 65-97+32=97-97=0, becomes 1 
       else 
       arr1[x-'a']=1; // if its not upper case directly store the occurance of lower case as 0
    }
    for(auto y:b){
         if(y >='A' && y <='Z') 
         { 
            if( arr1[y-'a'+32]==1)
             return false; 
         }
         else if (arr1[y-'a']==1) return false;
     }
    return true;
}
int main(){
    string a="hiii";
    string b="abcdI";
    if(commonchar(a,b)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}