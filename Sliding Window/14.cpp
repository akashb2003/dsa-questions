// Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

// Example 1:

// Input:
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Explanation: for, orf and ofr appears
// in the txt, hence answer is 3.

class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int r=0,l=0,ans=0;
	    unordered_map<char,int>mp;
	    
	    for(int i=0;i<pat.size();i++){
	        mp[pat[i]]++;
	    }
	    int cnt = mp.size();
	    int k = pat.size();
	    
	    while(r<txt.size()){
	        if(mp.find(txt[r]) != mp.end()){
	            mp[txt[r]]--;
	            if(mp[txt[r]] == 0){
	                cnt--;
	            }
	        }
	        if(r-l+1 <k) r++;
	        else{
	            if(cnt==0) ans++;
	            if(mp.find(txt[l]) != mp.end()){
	                mp[txt[l]]++;
	                if(mp[txt[l]]==1){
	                    cnt++;
	                }
	            }
	            r++;
	            l++;
	        }
	    }
	    return ans;
	}
};
