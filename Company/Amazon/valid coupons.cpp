int valid_coupon(string coupon){
    if(coupon.size() == 0) return 1;
    else {
        int size = 1;
        while (size <= coupon.size() / 2) {
            string left = coupon.substr(0, size);
            string right = coupon.substr(coupon.size() - size, size);
            if (left.compare(right) == 0) {
                return 1;
            }
            if (left.size() + right.size() == coupon.size()) {
                if (valid_coupon(left) == 1 && valid_coupon(right) == 1) {
                    return 1;
                }
            }
            size++;
        }
    }
    return 0;
}
vector<int> valid_copouns(vector<string> coupons){
    vector<int> res;
    for(string coupon: coupons){
        res.push_back(valid_coupon(coupon));
    }
    return res;
}