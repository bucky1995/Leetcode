long long subArrayRanges(vector<int>& nums) {
        // the method is to find each nums[i] contributes to the maximum value and minimum value to the final result
        // for nums[i], if nums[i] < nums[k] where k < i && nums[i] < nums[j] where j > i
        // then nums[i] contributes -nums[i] * (i - k) * (j - i) to the final result
        // likewise if nums[i] > nums[u] where u < i and nums[i] > nums[v] where v > i then nums[i] contributes nums[i] * (i - u) * (v - i) to the final result
        int size = nums.size();
        stack<int> indexStack;
        long long result = 0;
        // we can use monotonic stack to find the range of minimum and maximum for every item in nums
        // for j = indexStack.top() if it's larger than nums[i], then it means that in the range of [j, i), nums[j] is the smallest number, 
        // and the next item under the indexStack top, that's indexStack.pop(), k = indexStack.top(). k is in front of j in the stack, 
        // which means nums[k] < nums[j], so in the range of (k, j], nums[j] is the smallest. 
        // So nums[j] contributes -nums[j] * (j - k) * (i - j) to the final result
        
        // after interating over the nums, we need to calculation how many the items left in the indexStack
        // contribute to the final result, since the items left in the stack are storing in decreasing order from top to bottom in the stack
        // so the right boundary of the range is always nums.size()
        for (int i = 0; i <= size; i++) {
            while (indexStack.size() > 0 && (i == size || nums[indexStack.top()] > nums[i])) {
                int index = indexStack.top();
                indexStack.pop();
                int leftIndex = indexStack.size() > 0 ? indexStack.top() : -1;
                result -= (long long)nums[index] * (index - leftIndex) * (i - index);
            }
            indexStack.push(i);
        }
        indexStack = stack<int>();
        // we compute the maximum contribution of each nums[i] to the final result in a similar way
        for (int i = 0; i <= size; i++) {
            while (indexStack.size() > 0 && (i == size || nums[indexStack.top()] < nums[i])) {
                int index = indexStack.top();
                indexStack.pop();
                int leftIndex = indexStack.size() > 0 ? indexStack.top() : -1;
                result += (long long)nums[index] * (index - leftIndex) * (i - index);
            }
            indexStack.push(i);
        }
        return result;
    }

