/**
 *Implement strStr().
 *Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 * */

class Solution {
    public:
        const char* strStr(const char* haystack, const char* needle) {
            if(needle == NULL || *needle == '\0')
                return haystack;

            const char* p1 = haystack, *p1_advance = haystack;
            const char* p2 = needle;
            while(*p2) {
                p1_advance++;
                p2++;
            }

            while(*p1_advance) {
                const char* p1_old = p1;
                p2 = needle;
                while(*p1 && *p2 && *p1 == *p2) {
                    p1++;
                    p2++;
                }

                if(!*p2)
                    return p1_old;

                p1 = p1_old + 1;
                p1_advance++;
            }

            return NULL;
        }
};
