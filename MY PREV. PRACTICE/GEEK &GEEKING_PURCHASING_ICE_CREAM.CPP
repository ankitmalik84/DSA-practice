/*
GEEK & GEEKING PURCHASING ICE CREAM 

Input:
n = 5, k = 2
a = {1, 2, 2, 1, 2} 

Output:
3

Explanation:
Possible pairs are found at indices 
(0, 3) where distance, 3-0 >= 2
(1, 4) where distance, 4-1 >= 2
(2, 4) where distance, 4-2 >= 2*/

class Solution {
  public:
    long long findGoodPairs(vector<int> a, int n, int k) {
        map<int,vector<int>> mp;
    for(int i =0;i<n;i++){
        mp[a[i]].push_back(i);
    }
    long long ans = 0 ;
    for(auto &x : mp){
        for(int i=0;i<x.second.size();i++){
            for(int j = i+1 ; j<x.second.size();j++){
                if(x.second[j] - x.second[i] >= k){
                    ans += x.second.size() - j;
                    break;
                };
            }
        }
    }

    return ans; // code here
    }
};