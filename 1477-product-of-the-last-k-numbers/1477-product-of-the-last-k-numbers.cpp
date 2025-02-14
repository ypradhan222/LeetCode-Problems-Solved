class ProductOfNumbers {
public:
    vector<int> lst;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        lst.push_back(num);
    }
    
    int getProduct(int k) {
       int prod=1;
       int n= size(lst);
       for(int i=n-k;i<n;i++){
        prod*=lst[i];
       } 
       return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */