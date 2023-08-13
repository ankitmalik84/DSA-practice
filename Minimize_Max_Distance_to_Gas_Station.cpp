// Minimize Max Distance to Gas Station=========================>>>>>>>>>>>>>>>>>>>>>


#include<bits/stdc++.h>
long double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	vector<int> howMany(n-1,0);
	// yaha hum store karenge distance with index aur iska top element ka first hi answer hoga 
	priority_queue<pair<long double,int>> pq;
	for(int i=0;i<n-1;i++){
		// yaha hum diff k sath index dalenge har do element k bich ka
		pq.push({arr[i+1]-arr[i],i});
	}
	// yaha hum priority queue m se top utha te rahenge aur usme partition kr k ulta dal 
	// denge phir dubara top uthayenge phir dal denge
	for(int gasStation=1;gasStation<=k;gasStation++){
		auto tp=pq.top();pq.pop();
		// top utha liy
		int secInd = tp.second;
		// usme ek partition badhaya
		howMany[secInd]++;

		long double iniDiff = arr[secInd+1]-arr[secInd];
		// difference nikal k new partition k hisab se element push kar denge priority queue
		long double newSecLen = iniDiff / (long double)(howMany[secInd]+1);
		// yaha hum new element dal re hongee priority queue m 
		pq.push({newSecLen,secInd});
	}
	return pq.top().first;
}