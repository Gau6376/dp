#include<bits/stdc++.h>
using namespace std;

bool check(string &s1,string &s2){
    if(s1.size() != s2.size()+1) return false;
    int first=0,second=0;
    while(first<s1.size()){
        if(s1[first]==s2[second] && second<s2.size()){
            first++;second++;
        }
        else{
            first++;
        }
    }
    if(first==s1.size() && second==s2.size()) return true;
    return false;
}

bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}

int longestStrChain(vector<string>& words) {
    int n = words.size();
    int maxi=1;
    vector<int>dp(n,1);
    sort(words.begin(),words.end(),comp);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(check(words[i],words[prev]) && 1+dp[prev]>dp[i]){     
            dp[i]=1+dp[prev];
           }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
        }
    } 
    return maxi;
}

int main(){
int n;cin>>n;
vector<string>words(n);
for(int i=0;i<n;i++){
    string s;cin>>s;
    words.push_back(s);
}
cout<<longestStrChain(words)<<endl;
}