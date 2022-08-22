class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    //we only care about the peak element;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() >= right.size()){
            left.push(num);
            int a = left.top();
            left.pop();
            right.push(a);
        }else{
            right.push(num);
            int a = right.top();
            right.pop();
            left.push(a);
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            int a = right.top();
            int b = left.top();
            return (a+b)/2.0;
        }else if(left.size() > right.size()){
            int a = left.top();
            return a;
        }else{
            int a = right.top();
            return a;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */