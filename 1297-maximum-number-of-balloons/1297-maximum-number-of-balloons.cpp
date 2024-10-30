class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> vec(26,0);
        for(int i=0;i<text.size();i++){
            vec[text[i]-'a']++;
        }
        vector<int>ans;
            ans.push_back(vec[0]);
            ans.push_back(vec[1]);
            ans.push_back((vec[11]/2));
            ans.push_back(vec[13]);
            ans.push_back(vec[14]/2);

        auto minElement = std::min_element(ans.begin(), ans.end());
         
        return *minElement;
    }
};