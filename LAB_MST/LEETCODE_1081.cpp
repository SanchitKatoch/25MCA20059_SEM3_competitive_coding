https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/submissions/2155844600/
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26,0);
        vector<bool> visited(26,false);

        for(char c:s){
            count[c-'a']++;
        }

        string result="";

        for(char c:s){
            count[c-'a']--;
            if (visited [c-'a']){
                continue;
            }

            while(!result.empty()){
                char lastChar=result.back();

                if(lastChar <= c){
                    break;
                }

                if(count[lastChar-'a']==0){
                    break;
                }

                visited[lastChar-'a']=false;
                result.pop_back();
            }

            result.push_back(c);
            visited[c-'a']=true;
        }

        return result;
    }
};
