#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

std::vector<int> generateFibonacci(int n) {
    if (n <= 0) {
        throw std::invalid_argument("Input must be a positive integer");
    }

    std::vector<int> fibSequence;

    if (n >= 1) {
        fibSequence.push_back(0);
    }
    if (n >= 2) {
        fibSequence.push_back(1);
    }

    for (int i = 2; i < n; ++i) {
        int nextNum = fibSequence[i - 1] + fibSequence[i - 2];
        fibSequence.push_back(nextNum);
    }

    return fibSequence;
}

// Unit tests
TEST(FibonacciTest, BaseCases) {
    EXPECT_EQ(generateFibonacci(1), std::vector<int>({ 0 }));
    EXPECT_EQ(generateFibonacci(2), std::vector<int>({ 0, 1 }));
    EXPECT_EQ(generateFibonacci(3), std::vector<int>({ 0, 1, 1 }));
}

TEST(FibonacciTest, MediumCases) {
    EXPECT_EQ(generateFibonacci(5), std::vector<int>({ 0, 1, 1, 2, 3 }));
    EXPECT_EQ(generateFibonacci(10), std::vector<int>({ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 }));
}

TEST(FibonacciTest, InvalidInput) {
    EXPECT_THROW(generateFibonacci(0), std::invalid_argument);
    EXPECT_THROW(generateFibonacci(-5), std::invalid_argument);
}