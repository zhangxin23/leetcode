class Solution {
    public:
        int str2Int(const char *str) {
            long long num = 0;
            int valid = 0;
            if(str != NULL && *str != '\0') {
                bool minus = false;
                if(*str == '+')
                    str++;
                else if(*str == '-') {
                    str++;
                    minus = true;
                }

                if(*str != '\0')
                    num = str2IntCore(str, minus, &valid);
            }

            if(valid != -1)
                return (int)num;
            else
                throw InvalidException();
        }
    private:
        static long long str2IntCore(const char* digit, bool minus, int *valid) {
            long long num = 0;
            while(*digit != '\0') {
                if(*digit >= '0' && *digit <= '9') {
                    int flag = minux ? -1 : 1;
                    num = 10 * num + flag * (*digit - '\0');
                    if((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000)) {
                        num = 0;
                        *valid = -1;
                        break;
                    }
                } else {
                    num = 0;
                    *valid = -1;
                    break;
                }
            }

            return num;
        }
};
