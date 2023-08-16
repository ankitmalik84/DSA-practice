#include <bits/stdc++.h> 
int maxAreaContainer(vector<int> &arr) {
    // Write your code here.
    int low=0,high=arr.size()-1;
    int maxWater=0;
    while(low<high){
        int height = min(arr[low],arr[high]);
        int area = height*(high-low);
        if(area>maxWater){
            maxWater=area;
        }
        if(arr[low]==min(arr[low],arr[high])) low++;
        else high--;
    }
    return maxWater;
}