#include <stdexcept>
#include <gtest/gtest.h>

bool isPalindrome(int number) {
    if (number < 0) {
        return false;
    }

    int original = number;
    long reversedNum = 0; 

    while (number > 0) {
        int digit = number % 10;
        reversedNum = reversedNum * 10 + digit;
        number = number / 10;
    }

    return original == reversedNum;
}

// Unit tests
TEST(PalindromeTest, PositiveCases) {
    EXPECT_TRUE(isPalindrome(121));
    EXPECT_TRUE(isPalindrome(12321));
    EXPECT_TRUE(isPalindrome(0));
    EXPECT_TRUE(isPalindrome(1));
    EXPECT_TRUE(isPalindrome(99));
}

TEST(PalindromeTest, NegativeCases) {
    EXPECT_FALSE(isPalindrome(123));
    EXPECT_FALSE(isPalindrome(1234));
    EXPECT_FALSE(isPalindrome(10));
    EXPECT_FALSE(isPalindrome(-121));
}