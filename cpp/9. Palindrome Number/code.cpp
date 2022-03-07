// does first digit equal last digit?
// does 2nd digit equal 2nd last digit?
// etc

class Solution {
public:
    bool isPalindrome(int x) {
        string bob = to_string(x);
        for(int i = 0; i<bob.length()/2;i++) {
            if(bob[i]!=bob[bob.length()-1-i]) {
                return false;
            }
        }
        return true;
    }
};