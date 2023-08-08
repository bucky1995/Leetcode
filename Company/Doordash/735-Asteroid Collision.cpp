class Solution {
public:
    stack<int> collision(stack<int> buffer, int e){
        while(buffer.size()!=0 && buffer.top()*e<0){
            if(abs(buffer.top()) > abs(e)){
                e = 1001;
                break;
            }else if(abs(buffer.top()) < abs(e)){
                buffer.pop();
            }else{
                buffer.pop();
                return buffer;
            }
        }
        if(e!=1001){
            buffer.push(e);
        }
        return buffer;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> buffer;
        for(int e : asteroids){
            if(buffer.size() == 0){
                buffer.push(e);
            }else{
                if(buffer.top()>0 && e<0){
                    buffer = collision(buffer, e);
                }else{
                    buffer.push(e);
                }
            }
        }
        vector<int> res;
        while(!buffer.empty()){
            res.push_back(buffer.top());
            buffer.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};