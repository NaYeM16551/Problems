#include "bits/stdc++.h"

using namespace std;

//a problem to check valid string or not
bool ispar(string x) {
    // Your code here
    stack<char> s;
    for (auto ch: x) {
        if (s.empty())
            s.push(ch);
        else if (ch - s.top() == 2 || ch - s.top() == 1)
            s.pop();
        else
            s.push(ch);
    }
    return s.empty();
}

//self made tokenize function
void tokenize(std::string const &str, const char delim,
              std::vector<std::string> &out) {
    // construct a stream from the string
    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }

}

//sub-array withGiven sum
vector<int> subarraySum(vector<int> arr, int n, long long s) {
    // Your code here
    if (s == 0)return {-1};
    long long sum = 0;
    int left_pointer = 0, right_pointer = 0;
    while (left_pointer < n && right_pointer <= n) {

        if (s > sum) {
            sum += arr[right_pointer];
            right_pointer++;
        } else if (s < sum) {
            sum -= arr[left_pointer];
            left_pointer++;
        } else
            return {left_pointer + 1, right_pointer};


    }
    return {-1};
}

//Sort an array of 0s, 1s and 2s
void sort012(int a[], int n) {
    // code here
    int mid = 0, low = 0, high = n - 1;
    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            mid++;
            low++;
        } else if (a[mid] == 1)
            mid++;
        else {
            swap(a[high], a[mid]);
            high--;


        }


    }
}

//reverse a word based on dot
string reverseWords(string s) {
    // code here
    string str;
    for (int i = s.length() - 1; i >= 0; --i) {

        int start = i;
        while (s[i] != '.' && i >= 0)i--;
        str += s.substr(i + 1, start - i) + ".";

    }
    str.pop_back();
    return str;


}

bool isPalindrome(string str) {
    int i = 0, j = str.length() - 1;
    while (j >= i) {
        if (str[i++] != str[j--])
            return false;
    }
    return true;

}

string longestPalin(string S) {
    // code here
    string longestPalindrome;
    size_t length = S.length();
    auto subLength = 0;
    for (int L = 0; L < length; ++L) {
        for (int R = L; R < length; ++R) {
            string sub = S.substr(L, R - L + 1);
            if (sub.length() > subLength && isPalindrome(sub)) {
                longestPalindrome = sub;
                subLength = sub.length();

            }
        }
    }
    return longestPalindrome;

}

//remove all duplicate element recursively
string removeA(string s) {

    string ans;
    int i = 0;
    while (s[i]) {
        if (s[i] != s[i + 1])
            ans += s[i];
        else {
            while (s[i] == s[i + 1])
                i++;
        }
        i++;


    }
    if (ans.size() == s.size())
        return ans;
    return removeA(ans);

}

string rremove(string s) {
    // code here
    stack<char> sta;
    for (auto ch: s) {
        if (sta.empty())
            sta.push(ch);
        else if (ch == sta.top())
            sta.pop();
        else
            sta.push(ch);
    }
    std::stack<int> reversed_stack;
    while (!sta.empty()) {
        reversed_stack.push(sta.top());
        sta.pop();
    }
    string st;
    while (!reversed_stack.empty()) {
        st.push_back(reversed_stack.top());
        reversed_stack.pop();

    }
    return st;

}
//first three negative Number

vector<int> printFirstNegativeInteger(int arr[], int n, int k) {
    deque<int> d;
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
        if (arr[i] < 0)
            d.push_back(i);
    }
    if (!d.empty())
        ans.push_back(arr[d.front()]);
    else
        ans.push_back(0);
    for (int i = k; i < n; ++i) {
        //removal wala logic
        if (!d.empty() && i - d.front() >= k) {
            d.pop_front();
        }
        if (arr[i] < 0)
            d.push_back(i);
        if (!d.empty())
            ans.push_back(arr[d.front()]);
        else
            ans.push_back(0);
    }
    return ans;

}

string largestNumberCombinationOfArray(string s) {
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j < s.length(); ++j) {
            if (stoi(to_string(s[j]) + to_string(s[i])) > stoi(to_string(s[i]) + to_string(s[j])))
                swap(s[i], s[j]);
        }

    }
    return s;


}

string findLargest(int N, int S) {
    if (S == 0 && N > 1)
        return "-1";
    string ans;
    while (ans.length() < N) {
        if (S > 9) {
            ans += "9";
            S -= 9;
        } else {
            ans += to_string(S);
            S = 0;
        }


    }
    return S == 0 ? ans : "-1";
}

int peakElement(int arr[], int n) {
    // Your code here
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
    if (arr[0] >= arr[n - 1])
        return 0;
    return n - 1;
}

int pickFindingUsingBS(int *arr, int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > arr[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }
    return l;
    /*int s=0,e=n-1;

     while(s<=e)
     {
         int mid=s+(e-s)/2;
         if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid]>=arr[mid+1]))
         return mid;
         else if(mid>0 && arr[mid-1]>arr[mid])
         e=mid-1;
         else
         s=mid+1;

     }*/


}
char* reverse(char *S, int len)
{
    //code here
    stack<char> s;
    for(int i=0;i<len;++i)
    {
        s.push(S[i]);

    }
    int i=0;
    while(!s.empty())
    {
        char c=s.top();
        s.pop();
        S[i++]=c;

    }
    return S;
}

vector<int> leaders(int arr[], int n) {

    vector<int> ans;
    int max = arr[n - 1];
    ans.push_back(max);

    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] >= max) {
            ans.push_back(arr[i]);
            max = arr[i];
        }


    }
    reverse(ans.begin(), ans.end());
    return ans;

}
void merge(int *arr1,int*arr2,int m,int n)
{
    int j=0,i=m-1;
    while(i>=0 && j<n)
    {
        if(arr1[i]> arr2[j])
        {
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(arr1,arr1+m);
    sort(arr2,arr2+n);


}


int main() {
    int arr[3]={1,3,6};
    int arr2[5]={2,4,5,7,8};
    merge(arr,arr2,3,5);
    for(int i :arr)
        cout<<i<<" ";
    cout<<endl;
    for(int i :arr2)
        cout<<i<<" ";
    cout<<endl;



}








