class Solution {
public:
    unordered_map<int, string> map;
    string three(int num){
        int hundred = num/100;
        int rest = num-hundred * 100;
        int ten = 0;
        if(rest>20){
            ten = rest/10;
            rest = rest-10*ten;
        }
        string res = "";
        if(hundred!=0){
            res+=map[hundred] + " " + "Hundred";
        }
        if(hundred!=0 || ten!=0){
            if(ten!=0){
                if(!res.empty())
                    res+=" ";
                res+=map[ten*10];
            }
        }
        if(rest!=0){
            if(!res.empty())
                res+=" ";
            res+=map[rest];
        }
        return res;
    }
    unordered_map<int, string> initial_map(){
        unordered_map<int, string> map;
        map[0] = "Zero";
        map[1] = "One";
        map[2] = "Two";
        map[3] = "Three";
        map[4] = "Four";
        map[5] = "Five";
        map[6] = "Six";
        map[7] = "Seven";
        map[8] = "Eight";
        map[9] = "Nine";
        map[10] = "Ten";
        map[11] = "Eleven";
        map[12] = "Twelve";
        map[13] = "Thirteen";
        map[14] = "Fourteen";
        map[15] = "Fifteen";
        map[16] = "Sixteen";
        map[17] = "Seventeen";
        map[18] = "Eighteen";
        map[19] = "Nineteen";
        map[20] = "Twenty";
        map[30] = "Thirty";
        map[40] = "Forty";
        map[50] = "Fifty";
        map[60] = "Sixty";
        map[70] = "Seventy";
        map[80] = "Eighty";
        map[90] = "Ninety";
        return map;
    }
    string numberToWords(int num) {
        if(num == 0)    return "Zero";
        map = initial_map();
        int billion = num/1000000000;
        int million = (num-billion*1000000000)/1000000;
        int thousand = (num - billion * 1000000000 - million * 1000000) / 1000;
        int rest = (num - billion * 1000000000 - million * 1000000 - thousand * 1000);
        string res = "";
        
        if(billion!=0){
            res+=three(billion) + " Billion";
        }
        if(million!=0){
            if(!res.empty())
                res+=" ";
            res+=three(million) + " Million";
        }
        if(thousand!=0){
            if(!res.empty())
                res+=" ";
            res+=three(thousand) + " Thousand";
        }
        if(rest!=0){
            if(!res.empty())
                res+=" ";
            res+=three(rest);
        }
        return res;
    }
};