class ProductOfNumbers {
public:
vector<int>res;
    ProductOfNumbers() {
       res={1};
 
    }
    
    void add(int num) {
        if(num==0) res={1};
        else res.push_back(num*res.back());
    }
    
    int getProduct(int k) {
        if(k>=res.size()) return 0;
        else return res.back()/res[res.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
