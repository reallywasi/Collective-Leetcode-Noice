Valid Parenthesis String
Given a string s containing only '(', ')', and '*', return true if the string is valid.
A string is valid if:
Every ‘(’ has a corresponding ‘)’.
Every ‘)’ has a corresponding ‘(’.
‘*’ can be treated as '(', ')', or an empty string.
_________________________________________________________________________________________________
  🚀 Approach:
We maintain two counters:

mini → minimum number of unmatched open brackets '(' considering '*' as ')' or empty.

maxi → maximum number of unmatched open brackets '(' considering '*' as '('.

As we iterate:

For '(': increment both mini and maxi.

For ')': decrement both mini and maxi.

For '*': decrement mini, increment maxi.

If at any point maxi < 0, return false (too many closing brackets).
Ensure mini never drops below 0 (mini = max(mini, 0)).

Return true if mini == 0 at the end (all open brackets are matched considering flexibility of '*').


  _________________________________________________________________________________________________

  
🧪 Dry Run:
Let's dry run for: s = "(*))"


Char	mini	maxi	Comment
(	1	1	'(' increases both
*	0	2	'*' decreases mini, increases maxi
)	-1→0	1	')' decreases both, mini reset to 0
)	-1→0	0	')' decreases both, mini reset to 0
At end: mini == 0 → ✅ Valid




//____________________________________________________________-
class Solution {
public:
    bool checkValidString(string s) {
      int mini=0;    int maxi=0;
for(char ch : s)
{
    if(ch=='(') { mini ++; maxi++;}
    else if ( ch==')') { mini--; maxi--;}
    else { maxi++; mini--;}
    if(mini<0) mini=0;
    if(maxi<0) return false;
}
return (mini==0);
    }
};
