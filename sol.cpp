class Solution {
    public:
        bool canDistribute(vector<int>& nums, vector<int>& quantity) {
            unordered_map<int, int> freq;
            
            
            for (int num : nums) {
                freq[num]++;
            }
            
            
            vector<int> freqValues;
            for (auto& [key, value] : freq) {
                freqValues.push_back(value);
            }
            
            
            sort(quantity.begin(), quantity.end(), greater<int>());
            
           
            return canDistributeHelper(0, quantity, freqValues);
        }
        
    private:
        bool canDistributeHelper(int index, vector<int>& quantity, vector<int>& freqValues) {
            if (index == quantity.size()) {
                return true;  
            }
            
            for (int i = 0; i < freqValues.size(); ++i) {
                if (freqValues[i] >= quantity[index]) {
                
                    freqValues[i] -= quantity[index];
                    if (canDistributeHelper(index + 1, quantity, freqValues)) {
                        return true; 
                    }
                    
                    freqValues[i] += quantity[index];
                }
            }
            
            return false;  
        }
    };