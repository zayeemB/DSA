class Solution {
public:
    long long minEnd(int n, int x) {
        int num = n-1;
        int num_lz = num == 0? 0 : __builtin_clz(num);
        vector<int> num_bits;

        long long xl = (long long) x;

        for(int i = 0; i < 32-num_lz; i++){
            if(num & (1U << i)) num_bits.push_back(1);
            else num_bits.push_back(0);
            cout<<num_bits.back();
        }

        int bit_idx = 0;
        int n_bits = num_bits.size();

        for(int i = 0; i < 63 && bit_idx < n_bits; i++){
            if(!(xl & (1LL << i))){
                if(num_bits[bit_idx] == 1)
                    xl |= (1LL << i);
                else 
                    xl &= ~(1LL << i);
                bit_idx++;
            }
        }

        return xl;
    }
};