___________________________________________________________________________________________________________________________________
Question

Hard

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.





Link : 
_______________________________________________________________________________________________________________________________________
Approach


result= result+number*sign;
stack ke andar bracket se pehle ka part jyga evaluate hoke ie result banke 
then when bracket is closed wo stack wala part compute hoga.





_______________________________________________________________________________________________________________________________________
Code
class Solution {
public:
    int calculate(string s) {
       stack<int>st;
       int n=s.size();
       int result=0;
       int sign=1;
       int number=0;
       for(int i=0;i<n;i++)
       {
        if(isdigit(s[i]))
        {
number=number*10+(s[i]-'0');
        }
        else if(s[i]=='+')
        {
result=result+(number*sign);
sign=1;
number=0;
        }
         else if(s[i]=='-')
        {
          result=result+(number*sign);
sign=-1;  
number=0;
        }
         else if(s[i]=='(')
        {
            st.push(result);
            result=0;
            st.push(sign);
            result=0;
            number=0;
            sign=1;
        }
         else if(s[i]==')')
        {
   result=result+(number*sign);
   number=0;
   int lastsign=st.top();
   st.pop();
   int lastnumber=st.top();
   st.pop();
      result=lastnumber+(result*lastsign);


        }
       }
       result=result+(number*sign);
       return result;
    }
};













_______________________________________________________________________________________________________________________________________
