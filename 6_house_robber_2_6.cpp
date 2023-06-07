// dp on subsequence
// circle so first and last are adjacent
#include<bits/stdc++.h>
using namespace std;

// int f(vector<int> a)   // o(n)
// {
//     int n = a.size();
//    int prev=a[0];
//     int prev2 = 0;
//     for(int i=1;i<n;i++){
//         int take = a[i]; if(i>1) take+=prev2;      //  o(n) , o(1)
//         int nottake = 0 + prev;

//         int curri = max(take,nottake);
//         prev2 = prev;
//         prev = curri;
//     }
//     cout<<prev<<endl;
// }

// int ans(vector<int>&a){
//     vector<int>temp1,temp2;
//     int n = a.size();
//     if(n==1)
//     return a[0];
//     for(int i=0;i<n;i++){
//         if(i!=0) temp1.push_back(a[i]);
//         if(i!=n-1) temp2.push_back(a[i]);
//     }
//     return max(f(temp1) , f(temp2));
// }

int robber(vector<int>& a, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + a[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
}

int rob(vector<int>& a) {
        int n = a.size(); 
        if (n < 2)
        return n ? a[0] : 0;
        return max(robber(a, 0, n - 2), robber(a, 1, n - 1));
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<rob(a)<<endl;
}