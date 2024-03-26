#include <iostream>
#include <string>

int main() {
    std::string num1, num2;

    std::cout << "First  number >> ";
    std::cin >> num1;
    std::cout << "Second number >> ";
    std::cin >> num2;


    int len1 = num1.size();
    int len2 = num2.size();
    int size_diff = len1 - len2;
    if (size_diff < 0)
        num1 = std::string(-size_diff, '0') + num1;
    else if (size_diff > 0)
        num2 = std::string(size_diff, '0') + num2;

    std::string result_add = "";
    int carry = 0;

    // Addition
    for (int i = num1.size() - 1; i >= 0; --i) {
        int n1 = num1[i] - '0';
        int n2 = num2[i] - '0';
        int sum = n1 + n2 + carry;
        result_add = std::to_string(sum % 10) + result_add;
        carry = sum / 10;
    }
    if (carry != 0)
        result_add = std::to_string(carry) + result_add;

    std::cout << "Sum           >> " << result_add << std::endl;

    // Swap 
    bool negative = false;
    for (int i = 0; i < num1.size(); ++i) {
        if (num1[i] < num2[i]) {
            std::swap(num1, num2);
            negative = true;
            break;
        } else if (num1[i] > num2[i]) {
            break;
        }
    }

    std::string result_sub = "";
    carry = 0;

    // Subtraction
    for (int i = num1.size() - 1; i >= 0; --i) {
        int n1 = num1[i] - '0';
        int n2 = num2[i] - '0';
        int diff = n1 - n2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result_sub = std::to_string(diff) + result_sub;
        if(result_sub=="") {
          result_sub="0";
        }
    }

    //불필요한 0 지우기
    result_sub.erase(0, result_sub.find_first_not_of('0'));

    if (negative)
        result_sub = '-' + result_sub;

    std::cout << "Sub           >> " << result_sub << std::endl;

    return 0;
}
