#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

template<class T>
void print_vect(vector<T> arr){
    for(auto val: arr)
        cout << val <<" ";
    cout <<endl;
}

vi counting_sort(vi& arr, int k){
    vi result(arr.size(), 0);
    static vi count(k+1, 0);
    for(auto val: arr)
        ++count[val];
    for(int i = 1; i <= k; ++i)
        count[i] += count[i-1];
    for(vi::reverse_iterator it = arr.rbegin(), end = arr.rend(); it != end; ++it){
        result[count[*it]-1] = *it;
        --count[*it];
    }
    return result;
} 

vi counting_sort(int* arr, int n, int k){
    vi result(n, 0);
    vi count(k+1, 0);
    for(int i = 0; i < n; ++i)
        ++count[arr[i]];

    for(int i=0, l = 0, j; i <= k; ++i){
        j = count[i];
        while(j--) result[l++] = i; 
    }
    return result;
}

// only applicable for sorting d-digit integers
vector<string> radix_stable_sort(vector<string> str_arr, int index, int k){
    vector<string> result(str_arr.size());
    vi count(k+1, 0);
    for(auto val: str_arr)
        ++count[val[index] - '0'];
    for(int i = 1; i <= k;++i)
        count[i] += count[i-1];
    for(vector<string>::reverse_iterator it = str_arr.rbegin(), end = str_arr.rend(); it != end; ++it){
        int digit = (*it)[index] - '0';
        result[count[digit] - 1] = *it;
        --count[digit];
    }
    return result;
}

vi radix_sort(vi arr, int d){
    vector<string> str_arr(arr.size(), ""); 
    transform(arr.begin(), arr.end(), str_arr.begin(), [&](int a) -> string{
            string str = to_string(a);
            str.insert(0, d - str.size(), '0');
            return str;
        });
    for(int i = d-1; i >= 0; --i)
         str_arr = radix_stable_sort(str_arr, i, 9);
    
    transform(str_arr.begin(), str_arr.end(), arr.begin(), [](string str) -> int{
                return stoi(str);
            });
    return arr; 
}

int main(){
    vi arr{123,45,98,123,97,345,466};
    vi result = radix_sort(arr, 3);
}
