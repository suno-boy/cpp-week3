#include <iostream>
#include <string>

int main() {
  std::string num1,num2;

  std::cout << "First  number >> ";
  std::cin >> num1;
  std::cout << "Second number >> ";
  std::cin >> num2;

  std::string zeros = "";
    int len1 = num1.size();
    int len2 = num2.size();
    int size_diff = len1 - len2;
    if (size_diff < 0)
        size_diff *= -1;
    for (int i = 0; i < size_diff; i++)
        zeros += "0";
    if (len1 < len2)
        num1 = zeros + num1;
    else if (len1 > len2)
        num2 = zeros + num2;

  int carry = 0;
  int n1 = -1;
  int n2 = -1;
  std::string result = "";

  for(int i=num1.size()-1;i>=0;i--)
  {
    n1 = num1[i]-'0';
    n2 = num2[i]-'0';

    if((n1+n2)+carry>10)
    {
      result = std::to_string((n1+n2+carry)%10) + result;
      carry = 1;
    }
    else if ((n1+n2)+carry==10)
    {
      carry = 1;
      result = "0" + result;
    }
    else if((n1+n2)+carry<10)
    {
      result = std::to_string(n1+n2+carry) + result;
      carry = 0;
    }
    
  }

  if(carry==1)
  {
    result = "1" + result;
  }

  std::cout << "Sum           >> ";
  for(int i=0;i<result.size();i++)
  {
    std::cout <<result[i];
  }
  std::cout << std::endl;




  int negative = 0;
  for(int i=0;i<num1.size();i++)
  {
    if(num1[i]-num2[i]>0)
    {
      break;
    }
    else if(num1[i]-num2[i]<0)
    {
      std::string A = "";
      A = num1;
      num1 = num2;
      num2 = A;
      negative = -1;
    }
    else if(num1[i]-num2[i]==0)
    {
    
    }
  }


  int n1_sub = -1;
  int n2_sub = -1;
  std::string result_sub = "";


  for(int i=num1.size()-1;i>=0;i--)
  {
    n1_sub = num1[i]-'0';
    n2_sub = num2[i]-'0';
    if(n1_sub-n2_sub>=0)
    {
      result_sub = std::to_string(n1_sub-n2_sub) + result_sub;
    }
    else if(n1_sub-n2_sub<0)
    {
      result_sub = std::to_string(10+n1_sub-n2_sub) + result_sub;
      int test = num1[i-1] - '0';
      if(test!=0)
      {
        num1[i-1] = (char)(test-1);
      }
      else if(test==0)
      {
        int test2 = num1[i-2] - '0';
        num1[i-2] = (char)(test2-1);
        num1[i-1] = (char)(test+9);
      }
    }
  }

  
  if(negative==-1)
  {
    result_sub = "-" + result_sub;
  }


  std::cout << "Sub           >> ";
  for(int i=0;i<result_sub.size();i++)
  {
    std::cout <<result_sub[i];
  }    

  return 0;
}