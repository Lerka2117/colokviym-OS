#include <memory>
#include <gtest/gtest.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

std::vector<int> listToVector(ListNode* head) {
    std::vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

// Unit tests
TEST(ReverseLinkedListTest, EmptyList) {
    EXPECT_EQ(reverseLinkedList(nullptr), nullptr);
}

TEST(ReverseLinkedListTest, SingleNode) {
    ListNode* node = new ListNode(1);
    ListNode* reversedHead = reverseLinkedList(node);
    EXPECT_EQ(reversedHead->val, 1);
    EXPECT_EQ(reversedHead->next, nullptr);
    deleteList(reversedHead);
}

TEST(ReverseLinkedListTest, MultipleNodes) {
    ListNode* list = createList({ 1, 2, 3 });
    ListNode* reversedHead = reverseLinkedList(list);
    std::vector<int> expected = { 3, 2, 1 };
    EXPECT_EQ(listToVector(reversedHead), expected);
    deleteList(reversedHead);
}

TEST(ReverseLinkedListTest, TwoNodes) {
    ListNode* list = createList({ 1, 2 });
    ListNode* reversedHead = reverseLinkedList(list);
    std::vector<int> expected = { 2, 1 };
    EXPECT_EQ(listToVector(reversedHead), expected);
    deleteList(reversedHead);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}