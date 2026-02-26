#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        
        while (pA != pB) {
          
            pA = (pA == nullptr) ? headB : pA->next;
            
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA; 
    }
};

vector<int> parseArray(string s) {
    vector<int> res;
    string temp = "";
    for (char c : s) {
        if (isdigit(c) || c == '-') {
            temp += c;
        }
        else {
            if (!temp.empty()) {
                res.push_back(stoi(temp));
                temp = "";
            }
        }
    }
    if (!temp.empty()) res.push_back(stoi(temp));
    return res;
}

void solve() {
    int intersectVal, skipA, skipB;
    string strA, strB;
    cin >> strA >> strB >> skipA >> skipB;
    cin >> intersectVal;

    vector<int> valsA = parseArray(strA);
    vector<int> valsB = parseArray(strB);

    ListNode* dummyA = new ListNode(0);
    ListNode* curr = dummyA;
    ListNode* intersectNode = nullptr;

    for (int i = 0; i < valsA.size(); ++i) {
        curr->next = new ListNode(valsA[i]);
        curr = curr->next;
        if (i == skipA) intersectNode = curr; 
    }

    ListNode* dummyB = new ListNode(0);
    curr = dummyB;
    for (int i = 0; i < skipB; ++i) {
        curr->next = new ListNode(valsB[i]);
        curr = curr->next;
    }

    if (intersectVal != 0) {
        curr->next = intersectNode;
    }

    ListNode* result = getIntersectionNode(dummyA->next, dummyB->next);

    
    if (result) {
        cout << "Intersected at '" << result->val << "'" << endl;
    }
    else {
        cout << "No intersection" << endl;
    }
}

int main() {
    
   
    solve();
    return 0;
}
