#include <gtest/gtest.h>

#include "00002_add_two_numbers.h"

#include <string>
#include <algorithm>

using namespace std;

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

//int main() {
//    string line;
//    while (getline(cin, line)) {
//        ListNode* l1 = stringToListNode(line);
//        getline(cin, line);
//        ListNode* l2 = stringToListNode(line);
//
//        ListNode* ret = Solution().addTwoNumbers(l1, l2);
//
//        string out = listNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}

TEST(add_two_numbers, same_length_integers)
{
	std::string line1 = "[2,4,3]";
	std::string line2 = "[5,6,4]";
	ListNode *l1 = stringToListNode(line1);
	ListNode *l2 = stringToListNode(line2);

	Solution solution;
	ListNode * ret = solution.addTwoNumbers(l1, l2);
	std::string out = listNodeToString(ret);
	EXPECT_STREQ("[7, 0, 8]", out.c_str());

	delete l1;
	delete l2;
	delete ret;
}

TEST(add_two_numbers, diff_length_integers)
{
	std::string line1 = "[2,4]";
	std::string line2 = "[5,6,4]";
	ListNode *l1 = stringToListNode(line1);
	ListNode *l2 = stringToListNode(line2);

	Solution solution;
	ListNode * ret = solution.addTwoNumbers(l1, l2);
	std::string out = listNodeToString(ret);
	EXPECT_EQ(std::string("[7, 0, 5]"), out);

	delete l1;
	delete l2;
	delete ret;
}

//int main(int argc, char *argv[])
//{
//	testing::InitGoogleTest(&argc, argv);
//
//	return RUN_ALL_TESTS();
//}
