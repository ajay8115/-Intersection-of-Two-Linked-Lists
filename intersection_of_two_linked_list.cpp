// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // fun to find len
    int len(ListNode *head)
    {
        int cnt = 0;
        ListNode *cur = head;
        while (cur != NULL)
        {
            cnt++;
            cur = cur->next;
        }

        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        // if any one of them is null then return NULL
        if (head1 == NULL or head2 == NULL)
        {
            return NULL;
        }

        // length of both linked list
        int l1 = len(head1);
        int l2 = len(head2);
        ListNode *p1;
        ListNode *p2;

        // we start our p1 whose length is greater
        int d = 0;
        if (l1 > l2)
        {
            d = l1 - l2;
            p1 = head1; // if first linked list is  of greater len
            p2 = head2;
        }
        else if (l1 <= l2)
        {
            d = l2 - l1;
            p1 = head2; // if second list is of greater len then we p1 point to head2
            p2 = head1;
        }

        while (d--)
        {
            p1 = p1->next; // we traverse till from where both linked list of equal len
        }

        while (p1 != NULL and p2 != NULL)
        {
            if (p1 == p2)
            {
                return p1; // as p1 is == to p2 then return p1 or p2
            }
            p1 = p1->next; // or traverse further
            p2 = p2->next; // or traverse further
        }

        return NULL; // we reach here only if no interesecction point exist
    }
};