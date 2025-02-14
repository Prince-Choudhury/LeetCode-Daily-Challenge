#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> v;  

    ProductOfNumbers() : v(10000000, 0) {  // Initialize v here
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int n = v.size();
        int ans = 1;
        for (int j = n - 1; j > n - 1 - k; j--) {
            ans = ans * v[j];
        }
        return ans;
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */