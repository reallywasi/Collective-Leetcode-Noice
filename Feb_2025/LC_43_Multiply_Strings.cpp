class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        vector<int>result(n1+n2,0);
  if (num1 == "0" || num2 == "0") return "0"; 
reverse(num1.begin(),num1.end());
reverse(num2.begin(),num2.end());


        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
int product=(num2[j]-'0')*(num1[i]-'0');
int sum= result[i+j]+product;
int carry=sum/10;
result[i+j]=sum%10;
result[i+j+1]+=carry;

            }
        }
int i=result.size()-1;
        while(i>0 && result[i]==0) i--;
string ans="";
        while (i >= 0) ans += (result[i--] + '0');
                return ans.empty() ? "0" : ans;

    }
};
