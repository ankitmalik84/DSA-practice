#include <bits/stdc++.h> 

vector<int> getFrequency(string& s, vector<string>& words, int n) {

    string lol="";

    bool flag=false;

    unordered_map<string,int> map;

    for(int i=0; i<s.length(); i++)

    {

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))

        {

           lol=lol+s[i];

           flag=true;

        }

        else

        {

            if(flag)

            map[lol]++;

            flag=false;

            lol="";

        }

        

    }

    if(lol.size()!=0)

    map[lol]++;

 

    vector<int> ans;

 

    for(int i=0; i<words.size(); i++)

    {

      ans.push_back(map[words[i]]);

    }

    return ans;

 

}