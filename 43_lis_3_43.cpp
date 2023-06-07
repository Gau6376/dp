// using binary search same problem 41 and 42
#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int>temp;
    int len=1;
    temp.push_back(nums[0]);
    for(int i=1;i<n;i++) {
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[ind] = nums[i];
        }
    }
    return len;
}

int main(){
int n;cin>>n; 
vector<int>nums(n);
for(int i=0;i<n;i++) cin>>nums[i];
cout<<lengthOfLIS(nums)<<endl;
}