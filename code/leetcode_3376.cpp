#include<iostream>
#include<vector>
#include<climits>
#include<functional>

using namespace std;

int findMinimumTime(vector<int>& strength, int k) {
    int size=strength.size();
    int time=0;
    int X=1;
    int energy=0;
    int minor=INT_MAX;
    vector<bool> open(size,false);
    vector<int> path;
    function<void()> dfs=[&](){
        if(path.size()==size){
            minor=min(minor,time);
            return;
        }
        for(int i=0;i<size;i++){
            if(open[i]){
                continue;
            }
            int flash_shoot_energy=energy;
            int flash_shoot_time=time;
            int temp=abs(strength[i]-energy)%X;
            if(temp==0){
                energy=0;
                time+=abs(strength[i]-energy)/X;
            }else{
                energy=X-temp;
                time+=abs(strength[i]-energy)/X;
                time++;
            }
            X+=k;
            open[i]=true;
            path.push_back(i);
            dfs();
            path.pop_back();
            open[i]=false;
            X-=k;
            energy=flash_shoot_energy;
            time=flash_shoot_time;
        }
    };

    dfs();
    return minor;
}
int main(){
    vector<int> in={2,5,4};
    int k=2;
    findMinimumTime(in,k);
    return 0;
}