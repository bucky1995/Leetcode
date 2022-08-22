class Solution {
public:
    
    void DFS(vector<vector<char>> buttons, int current_digits, string current_str, vector<string>& res){
        if(current_digits == buttons.size()){
            res.push_back(current_str);
            return;
        }
        
        vector<char> current_options = buttons[current_digits];
        
        for(int i=0;i<current_options.size();i++){
            string temp = current_str;
            temp.push_back(current_options[i]);
            DFS(buttons, current_digits+1, temp, res);
            temp.pop_back();
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0){
            return res;
        }
        
        unordered_map<char,vector<char>> map;
        
        map['0'] = {' '};
        map['1'] = {};
        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};
        
        vector<vector<char>> buttons;
        
        while(digits.size()!=0){
            buttons.push_back(
                map[
                    digits.front()
                ]
            );
            digits.erase(digits.begin());
        }
        DFS(buttons, 0,"", res);
        
        return res;
    }
};