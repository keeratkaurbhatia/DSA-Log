//o(NL2), o(NL2)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string,vector<string>> sim;

        for (string s: wordList)
        {
            for (int i = 0; i<s.size();i++)
            {
                string pattern = s.substr(0,i)+'*'+s.substr(i+1);
                if(sim.find(pattern)==sim.end())
                {
                    sim[pattern] = {};
                }
                sim[pattern].push_back(s);
            }
        }
        queue<string> q;
        unordered_map<string,bool> visited;
        for(string s: wordList)
        {
            visited[s]=false;
        }
        q.push(beginWord);
        visited[beginWord]=true;
        int level = 0;
        while(!q.empty())
        {
            
            int size = q.size();
            for (int i = 0; i<size; i++)
            {
                string node = q.front();
                q.pop();
                for (int i = 0; i<node.size();i++)
                {
                    string pattern = node.substr(0,i)+'*'+node.substr(i+1);
                    
                    for (string s: sim[pattern])
                    {
                        if(s==endWord)
                        {
                            return level+2;
                        }
                        if(!visited[s])
                        {
                            visited[s]=true;
                            q.push(s);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};
