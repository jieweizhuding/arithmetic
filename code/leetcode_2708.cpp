#include<iostream>
#include<vector>
#include<climits>
#include<functional>

using namespace std;

long long maxStrength(vector<int>& nums) {
    int size=nums.size();
    long long ans=0;
    long long result=1;
    function<void(int)> dfs=[&](int i){
        ans=max(ans,result);
        if(i==size){
            return;
        }
        for(int j=i;j<size;j++){
            if(nums[j]==0)
            continue;
            result*=nums[j];
            dfs(j+1);
            result/=nums[j];
        }
    };
    dfs(0);
    return ans;
}

int main(){
    vector<int> v={8,8,-6,-4,-6,-4,-6,-5,0,-9,-6,-3};
    maxStrength(v);
    return 0;
}