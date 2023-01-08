#include "bits/stdc++.h"

using namespace std;

bool IsSorted_Array(int Arr[], int size) {

    if (size == 1 || size == 0)
        return true;
    if (Arr[0] > Arr[1]) {

        return false;

    }
    // size=size-1;

    bool Remaining_Part = IsSorted_Array(Arr + 1, --size);
    return Remaining_Part;

}

int arraySum(int *Arr, int size) {
    //base case
    if (size == 0)
        return 0;
    //ChotoProblem

    int boroProblem = Arr[0] + arraySum(Arr + 1, --size);
    return boroProblem;


}

int Linear_Search_Recursion(int *Arr, int size, int key) {
    if (size == 0)
        return -1;
    if (key == Arr[0])
        return size;
    int Check_Remaining_part = Linear_Search_Recursion(Arr + 1, --size, key);
    return Check_Remaining_part;
}

int FibonacciNumber(int n) {
    if (n <= 1) {
        return n;
    }

    int solution = FibonacciNumber(n - 1) + FibonacciNumber(n - 2);
    return solution;

}

int StairProblem(int n) {
    //base case
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    int solution = StairProblem(n - 1) + StairProblem(n - 2);
    return solution;
}

void SayDigits(string arr[], int num) {
    if (!num)
        return;
    //here string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten"}
    int d = num % 10;
    SayDigits(arr, num / 10);
    cout << arr[d] << " ";


}

int BinarySearch(int *Arr, int start, int end, int key) {
    if (start > end)
        return -1;
    int mid = start + ((end - start) / 2);
    if (Arr[mid] == key)
        return mid;

    else if (Arr[mid] > key)
        return BinarySearch(Arr, start, mid - 1, key);

    else
        return BinarySearch(Arr, mid + 1, end, key);


}

int BinarySearch_Using_Loop(int *Arr, int size, int key) {
    int start = 0, end = size - 1;
    while (end >= start) {
        int mid = start + (end - start) / 2;
        if (Arr[mid] == key)
            return mid;
        else if (Arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;

    }
    return -1;


}

void reverseStringUsingRecursion_02(string &s, int i) {
    if (i > s.length() - i - 1)
        return;
    swap(s[i], s[s.length() - i - 1]);
    i++;
    //j--;
    reverseStringUsingRecursion_02(s, i);
    // cout<<s<<endl;





}

void reverseString(string &str) {

    {
        if (str.length() == 0)
            return;
        char c = str.at(0);
        str.erase(0, 1);
        reverseString(str);
        str.push_back(c);
    }


}

void reversingUsingLoop(string &str) {
    cout << str << endl;
    int i = 0, j = str.length() - 1;
    while (i < j) {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    cout << str << endl;


}

bool isPallindrome(string s, int i, int j) {
    if (i > j)
        return true;
    if (s[i] != s[j])
        return false;
    else
        return isPallindrome(s, ++i, --j);

}

int exponentiation(int a, int b) {
    /* we need to calculate pow(a,b),mathematically if b is odd then
     the answer is a*pow(a,b/2)*pow(a,b/2)
     is case of even answer is pow(a,b/2)*pow(a,b/2)*/
    if (b == 0)
        return 1;
    int ans = exponentiation(a, b / 2);
    if (b & 1)
        return a * ans * ans;
    else
        return ans * ans;

}

void selectionSort_usingRecursion(int *arr, int size) {
    if (size == 1)
        return;
    int min = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[min] > arr[i])
            min = i;
    }
    swap(arr[0], arr[min]);
    selectionSort_usingRecursion(arr + 1, size - 1);

}

void solve_subsetGenerator(vector<int> num, int index, vector<int> output, vector<vector<int>> &ans) {
    if (index >= num.size()) {
        ans.push_back(output);
        return;
    }
    //exclude call
    solve_subsetGenerator(num, index + 1, output, ans);
    //include call
    output.push_back(num[index]);
    solve_subsetGenerator(num, index + 1, output, ans);

}

vector<vector<int>> subsetGenerator(vector<int> num) {
    int index = 0;
    vector<vector<int>> ans;
    vector<int> output;
    solve_subsetGenerator(num, index, output, ans);
    return ans;


}
vector<vector<char>> subsetGenerator_bitwise(string str)
{
    vector<char> output;
    vector<vector<char>> ans;
    for(int i=0;i< pow(2,str.length());++i)
    {
        for(int j=0;j<str.length();++j)
        {
            if(i & (1<<j))
            {
                std::cout<<str[j];
                output.push_back(str[j]);
            }
        }
        ans.push_back(output);
        output.clear();
    }
    return ans;
}
void solve(vector<string> &ans,string out,int index,string digits,string mapping[])
{
    if(index>=digits.length())
    {
        if(!out.empty())
           ans.push_back(out);
        return;
    }
    int num= digits[index]-'0';
    string value=mapping[num];
    for(int i=0;i<value.length();++i)
    {
        out.push_back(value[i]);
        solve(ans,out,index+1,digits,mapping);
        out.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string out;
    int index=0;
    string mapping[10]={""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(ans,out,index,digits,mapping);
    return ans;


}
void solve_permutationOfString(string &str,vector<string> &ans,int index)
{
    if(index>=str.length())
    {
        ans.push_back(str);
        return;
    }
    for(int i=index;i<str.length();++i)
    {
        swap(str[index],str[i]);
        solve_permutationOfString(str,ans,index+1);
        //backtracking
        swap(str[index],str[i]);





    }

}
vector<string> permutationOfString(string &&str)
{
    vector<string> ans;
    int index=0;
    solve_permutationOfString(str,ans,index);
    return ans;



}

int main() {


    int Arr[] = {11, 2, 30, 4, 6, 5, 7, 8, 9, 10};
    int arr[] = {1,2};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    vector<int> num;
    vector<string> ans;
    for (auto i = arr; i != end(arr); ++i) {
        num.push_back(*i);
    }
    //sort(num.begin(),num.end());
    ans = permutationOfString("nayem");

    for (const auto i: ans) {
         cout<<i<<" ";
        cout << endl;
    }



}