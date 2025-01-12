class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        int carry = 0;
        string ans = "";

        // Iterate while there are digits left in either string or there is a carry
        while (p1 >= 0 || p2 >= 0 || carry != 0) {
            int n1 = (p1 >= 0 ? num1[p1] - '0' : 0); // Get digit from num1 if available
            int n2 = (p2 >= 0 ? num2[p2] - '0' : 0); // Get digit from num2 if available
            int sum = n1 + n2 + carry; // Calculate the sum of digits plus carry
            int digit = sum % 10; // The digit to store in the current place
            carry = sum / 10; // Calculate new carry
            ans.push_back(digit + '0'); // Append the digit to the answer
            
            // Move to the next digits
            p1--;
            p2--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};