class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int max_size = min(str1.size(), str2.size());

        auto divides = [](string a, string b){
            int sa = a.size(), sb = b.size();
            if(sa > sb || sb % sa != 0) return false;

            for(int i = 0; i < b.size(); i+=sa){
                string factor = b.substr(i, sa);
                if(factor != a) return false;
            }

            return true;
        };

        for(int i = max_size-1; i >= 0; i--){
            string prfx1 = str1.substr(0, i+1);
            string prfx2 = str2.substr(0, i+1);

            if(prfx1 == prfx2){
                if(divides(prfx1, str1) && divides(prfx2, str2)) return prfx1;
            }
        }

        return "";
    }
};