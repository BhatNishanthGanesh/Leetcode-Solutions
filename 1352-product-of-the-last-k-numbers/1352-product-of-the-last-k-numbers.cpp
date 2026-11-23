class ProductOfNumbers {
public:
    vector<int>pref;
    ProductOfNumbers() {

    }
    
    void add(int num) {
        if(num==0){
            pref.clear();
        }else{
            if(pref.empty()) pref.push_back(num);
            else pref.push_back(pref.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n=pref.size();
        if(k>n) return 0;
        if(k==n) return pref.back();
        return pref.back()/pref[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */