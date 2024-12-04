#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /* Leetcode 116 */
    string fractionToDecimal(int numerator, int denominator) {
        string chuoi_kq = "";
        string chuoi_tam = "";
        bool chiahet = false, ngoac = false;
        long long sodu = 0, kq = 0, idx = 1, sokytucanlay = 0, sochia = 0, sobichia = 0;

        unordered_map <long long, long long> sodutontai;

        sobichia = numerator;
        sochia = denominator;

        kq = (sobichia / sochia);
        sodu = (sobichia % sochia);
        if (sodu < 0)
            sodu *= -1;
        sodutontai[sodu] = idx;
        
        if ((sobichia != 0) && (kq == 0))
        {
            if ((sobichia < 0 && sochia > 0) || (sobichia > 0 && sochia < 0))
                chuoi_kq += '-';
        }
        
        chuoi_kq += to_string(kq);

        if (sodu != 0)
        {
            chuoi_kq += '.';
            if (sochia < 0)
                sochia = sochia*(-1);

            while(1)
            {
                sobichia = sodu*10;
                kq = sobichia/sochia;
                sodu = sobichia%sochia;
                chuoi_tam += to_string(kq);

                if (sodu == 0)
                {
                    chiahet = true;
                    break;
                }

                // Check if sodu exists or not?
                if (sodutontai[sodu] > 0)
                {
                    chuoi_tam += ')';
                    sokytucanlay = sodutontai[sodu] - 1;
                    idx++;
                    break;
                }
                else
                {
                    idx++;
                    sodutontai[sodu] = idx;
                }
            }

            if (chiahet == true)
            {
                chuoi_kq += chuoi_tam;
            }
            else
            {
                // for (int i = 0; i < idx; i++)
                int i = 0;
                while(i < idx)
                {
                    if (i == sokytucanlay && ngoac == false)
                    {
                        chuoi_kq += '(';
                        ngoac = true;
                    }
                    else
                    {
                        chuoi_kq += chuoi_tam[i];
                        i++;
                    }
                }
            }
        }
        
        return chuoi_kq;
    }

    /* Leetcode 724 */
    int pivotIndex(vector<int>& nums) {
        int L = nums.size(), ret = -1;
        vector<int> prefix_sum(L, 0);

        prefix_sum[0] = nums[0];
        for(int i = 1; i < L; i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        int i = L-1;
        while(i >= 0)
        {
            if(prefix_sum[i] == (prefix_sum[L-1] - prefix_sum[i]))
            {
                ret = i;
                break;
            }
            i--;
        }
        if (ret == -1)
            return -1;
        else if (ret == 0)
            return 0;
        else
            return nums[ret];
    }

    /* Leetcode 2259. Remove Digit From Number to Maximize Result */
    string removeZeroInTheFirst(string str)
    {
        bool flag = false;
        string ret = "";
        int i = 0, L = str.length();
        while(str[i] == '0')
        {
            i++;
            flag = true;
        }

        if (flag == true)
        {
            ret = str.substr(i, L-1);
        }
        else
        {
            ret = str;
        }

        return ret;
    }

    bool compare_string_value(string str1, string str2)
    {
        int L1 = str1.length(), L2 = str2.length();
        bool ret = true; // default str1_val > str2_val

        if (L2 > L1)
        {
            ret = false;
        }
        else if (L2 == L1)
        {
            for(int i = 0; i < L1; i ++)
            {
                if (str1[i] > str2[i])
                {
                    break;
                }
                else if (str2[i] > str1[i])
                {
                    ret = false;
                    break;
                }
            }
        }

        return ret;
    }

    string removeDigit(string number, char digit) {
        unordered_map<int, string> before;
        unordered_map<int, string> after;
        vector<int> index;

        string ret = "", temp_before = "", temp_after = "", temp_str = "", max_str = "";
        
        int SIZE = number.length();
        int L = 0, R = SIZE - 1, count = 0, max_val = -1;
        long long temp_val = 0;
        bool stop = false;

        while(stop != true)
        {
            if (number[L] == digit)
            {
                temp_before = number.substr(0, L);
                temp_before = removeZeroInTheFirst(temp_before);
                before[L] = temp_before;
                if (after[L] == "")
                    index.push_back(L);
            }

            if (number[R] == digit)
            {
                temp_after = number.substr(R+1, SIZE-(R+1));
                after[R] = temp_after;
                if (before[R] == "")
                    index.push_back(R);
            }

            L++;
            R--;
            if (L == SIZE)
            {
                stop = true;
            }
        }

        // string a = "123";
        // string b = "456";

        // string c = a +b;
        // cout << c;

        for(int x: index)
        {
            temp_str = before[x] + after[x];

            if (compare_string_value(temp_str, max_str) == true)
            {
                max_str = temp_str;
            }
        }

        return max_str;
    }

    /* Leet code 2275. Largest Combination With Bitwise AND Greater Than Zero */
    int largestCombination(vector<int>& candidates) {
        int cnt = -1, cnt_tmp;
        int L = candidates.size(), tmp;

        for(int i = 0; i < L-1; i++)
        {
            tmp = candidates[i];
            cnt_tmp = 1;
            cout << tmp << " ";
            for(int j = i+1; j < L; j++)
            {
                if ((tmp & candidates[j]) != 0)
                {
                    cnt_tmp += 1;
                    tmp = tmp & candidates[j];
                    cout << candidates[j] << " ";
                }
                else
                {
                    continue;
                }
            }
            if (cnt_tmp > cnt)
                cnt = cnt_tmp;
            cout << "Length: " << cnt_tmp << "\n";
        }

        return cnt;
    }

    /* Leetcode 1829. Maximum XOR for Each Query */
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int L = nums.size();
        vector<int> bits(L, 0);
        vector<int> ret(L, 0);
        int temp1 = 0, temp2 = 0, cnt = L-1;;
        
        for(int i = 0; i < L; i++)
        {
            temp1 = temp1 ^ nums[i];
            temp2 = 0;
            for(int j = 0; j < maximumBit; j++)
            {
                int x = (temp1 & (1 << j));
                if (((temp1 & (1 << j)) >> j) == 1)
                {
                    temp2 &= ~(1 << j);
                }
                else
                {
                    temp2 |= (1 << j);
                }
            }
            ret[cnt] = temp2;
            cnt --;
        }

        return ret;
    }

    /* Leetcode 1574. Shortest Subarray to be Removed to Make Array Sorted */
    int findLengthOfShortestSubarray(vector<int>& arr) {
        /* 4 5 7 13 , 6 4 3 1 1 2 5 6 4 3 , 2 7 7 7 9 12 */

        int SIZE = arr.size();
        int L = 0, R = 0;
        int shortest_remove = 0, temp1 = 0, temp2 = 0, before = arr[0];
        bool stop = false;

        /* 1. Find right index */
        for(int i = SIZE - 1; i > 0; i--)
        {
            if (arr[i] < arr[i-1])
            {
                R = i;
                shortest_remove = R;
                break;
            }
        }
        temp1 = shortest_remove;
        temp2 = R;
        
        for(int i = L; i < R; i++)
        {
            if (arr[i] < before)
            {
                break;
            }

            temp2 = R;
            stop = false;
            while(temp2 < SIZE)
            {
                if (arr[i] <= arr[temp2])
                {
                    temp1 = temp2 - (i + 1);
                    stop = true;
                    break;
                }
                else
                {
                    temp2 += 1;
                }
            }

            if (stop != true)
            {
                temp1 = SIZE - (i+1);
            }

            if (temp1 < shortest_remove)
                shortest_remove = temp1;
            
            before = arr[i];
        }

        return shortest_remove;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        int L = nums.size();

        vector<int> power;
        deque<int> window;

        for(int i = 0; i < L; ++i)
        {
            if ((!window.empty()) && (window.front() <= i-k))
            {
                window.pop_front();
            }

            while ((!window.empty()) && (nums[window.back()] != nums[i] - 1))
            {
                window.pop_back();
            }

            window.push_back(i);

            if ((i+1) >= k)
            {
                if (window.size() == k)
                {
                    power.push_back(nums[window.back()]);
                }
                else
                {
                    power.push_back(-1);
                }
            }
        }

        return power;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int L = nums.size();
        int minLen = L, sum = 0, tempLen = 0;
        deque<int> window;
        bool flag = false, continue_flag = false;

        for(int i = 0; i < L; i++)
        {
            sum = sum + nums[i];
            window.push_back(nums[i]);

            if (i == L-1 && window.front() < 0)
            {
                continue_flag = true;
            }

            while(sum >= target || continue_flag == true)
            {
                if (continue_flag == true)
                    continue_flag = false;
                
                tempLen = window.size();
                
                if (sum >= target)
                {
                    if (tempLen < minLen)
                        minLen = tempLen;
                }
                sum = sum - window.front();
                window.pop_front();
                flag = true;

                if (window.empty() != true && window.front() < 0)
                    continue_flag = true;
            }
        }

        if (flag == false)
            minLen = -1;

        return minLen;
    }

    /* Leetcode 862. Shortest Subarray with Sum at Least K */ // -----------------------------------> NOT YET 
    int shortestSubarray(vector<int>& nums, int k) {
        int L = nums.size();
        int minLen = L, left = 0, right = 0, sum = 0, tmpLen = 0;
        bool flag = false;
        sum = nums[0];
        while (left < L && right <L)
        {
            if(left == right)
            {
                if (nums[left] >= k)
                {
                    tmpLen = 1;
                    flag = true;
                    if (tmpLen <= minLen)
                        minLen = tmpLen;
                }
                right += 1;
            }
            else
            {
                sum += nums[right];
                if (sum < k)
                {
                    right += 1;
                }
                else
                {
                    tmpLen = right - left + 1;
                    sum -= nums[left];
                    left += 1;
                    flag = true;

                    if (tmpLen <= minLen)
                        minLen = tmpLen;
                }
            }
        }

        if (flag == false)
            minLen = -1;
            
        return minLen;
    }

    /* Leetcode 1652. Defuse the Bomb */
    vector<int> decrypt(vector<int>& code, int k) {
        int L = code.size(), left = 1, right = L-2, delta = 0;
        vector<int> prefix_front(L, 0);
        vector<int> prefix_back(L, 0);
        vector<int> decode(L, 0);
        
        if (L == 1 || k == 0)
        {
            return decode;
        }

        prefix_front[0] = code[0];
        prefix_back[L-1] = code[L-1];

        while(1)
        {
            prefix_front[left] = prefix_front[left-1] + code[left];
            prefix_back[right] = prefix_back[right+1] + code[right];
            left++;
            right--;
            if(left > L || right < 0)
                break;
        }
        
        if (k > 0)
        {
            for(int i = 0; i < L; ++i)
            {
                if ((i+k) < (L-1))
                {
                    decode[i] = prefix_back[i+1] - prefix_back[(i+k) + 1];
                }
                else if ((i+k) == (L-1))
                {
                    decode[i] = prefix_back[i+1];
                }
                else
                {
                    if (i == (L-1))
                    {
                        decode[i] = prefix_front[k-1];
                    }
                    else
                    {
                        delta = k - (L-1-i);
                        decode[i] = prefix_back[i+1] + prefix_front[delta-1];
                    }
                }
            }
        }
        else
        {
            k *= -1;
            for (int i = L-1; i >= 0; --i)
            {
                if (i - k > 0)
                {
                    decode[i] = prefix_front[i-1] - prefix_front[(i-k)-1];
                }
                else if (i - k == 0)
                {
                    decode[i] = prefix_front[i-1];
                }
                else
                {
                    if (i == 0)
                    {
                        decode[i] = prefix_back[(L-1)-k+1];
                    }
                    else
                    {
                        decode[i] = prefix_front[i-1] + prefix_back[(L-1)-(k-i)+1];
                    }
                }
            }
        }

        return decode;
    }
    
    /* Leetcode 2461. Maximum Sum of Distinct Subarrays With Length K */
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long L = nums.size(), sum_tmp = 0, max_sum = 0;
        deque<int> window;
        unordered_map<int, int> map;

        for(long long i = 0; i < L; i++)
        {
            if (map[nums[i]] == 0)
            {
                window.push_back(nums[i]);
                map[nums[i]] = 1;
                sum_tmp += nums[i];
            }
            else
            {
                window.push_back(nums[i]);
                while (window.front() != nums[i])
                {
                    sum_tmp -= window.front();
                    map[window.front()] = 0;
                    window.pop_front();
                }
                window.pop_front();
            }

            if (window.size() == k)
            {
                if (sum_tmp > max_sum)
                    max_sum = sum_tmp;
                
                sum_tmp -= window.front();
                map[window.front()] = 0;
                window.pop_front();
            }

            if (window.size() + (L-1 - i) < k)
                break;
        }
        return max_sum;
    }

    /* Leetcode 1861. Rotating the Box */
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int hang = box.size(), cot = box[0].size();\
        int hang_moi = cot, cot_moi = hang, tmp1 = 0, tmp2 = 0, cnt = 0, idx = 0;
        bool fall = false;

        vector<vector<char>> rotatebox (hang_moi, vector<char> (cot_moi, '.'));
        cout << hang << " " << cot;


        for(int i = 0; i < cot_moi; i++)
        {
            idx = hang_moi - 1;
            for(int j = cot - 1; j >= 0; j--)
            {
                if (box[hang-1-i][j] == '.' && j>0)
                {
                    fall = true;
                    // if (box[hang-1-i][j-1] == '#')
                    // {
                    //     box[hang-1-i][j] = '#';
                    //     box[hang-1-i][j-cnt] = '.';
                    // }
                }
                else if (box[hang-1-i][j] == '#')
                {
                    if (fall == true)
                    {
                        rotatebox[idx][i] = '#';
                        fall = false;
                    }
                    else
                    {
                        rotatebox[idx][i] = '#';
                    }
                    idx--;
                }
                else
                {
                    rotatebox[j][i] = '*';
                    fall = false;
                    idx = j-1;
                }
            }
        }

        // for(int i = 0; i < hang_moi; i++)
        // {
        //     for(int j = hang-1; j >= 0; j--)
        //     {
        //         rotatebox[i][hang-1 - j] = box[j][i];
        //     }
        // }
        
        return rotatebox;
    }

    /* Leetcode 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence */
    int isPrefixOfWord(string sentence, string searchWord) {
        int space = 1, L = sentence.size(), idx = 0, l = searchWord.size(), ret = -1;;
        bool next = true;

        for(int i = 0; i < L; ++i)
        {
            if (sentence[i] == ' ')
            {
                space += 1;
                next = true;
            }

            if ((sentence[i] == searchWord[idx]) && next == true)
            {
                idx += 1;
            }
            else
            {
                if (sentence[i] != ' ')
                    next = false;
                idx = 0;
            }

            if (idx == l)
            {
                ret = space;
                break;
            }
        }
        return ret;
    }

    /* Leetcode 2109. Adding Spaces to a String */
    string addSpaces(string s, vector<int>& spaces) {
        string output = "";
        int L = s.length(), l = spaces.size(), idx = 0;

        if (spaces[idx] == 1)
            cout << "OK";
            
        for(int i = 0; i < L; i++)
        {
            if (idx <= l - 1)
            {
                if (spaces[idx] == i)
                {
                    output += ' ';
                }
            }
            output += s[i];
        }

        return output;
    }

    /* Leetcode 2825. Make String a Subsequence Using Cyclic Increments */
    bool canMakeSubsequence(string str1, string str2) {
        int L1 = str1.length(), L2 = str2.length(), j = 0;
        bool ret = false;
        char tmp = 0;

        for(int i = 0; i < L1; i++)
        {
            if (str1[i] == 'z')
                tmp = 'a';
            else
                tmp = str1[i] + 1;

            if (str1[i] == str2[j] || tmp == str2[j])
            {
                j++;
                if (j == L2)
                {
                    ret = true;
                    break;
                }
            }
        }

        return ret;
    }

};


int main()
{
    Solution S;
    string STR_RESULT = "";
    int INT_RESULT = 0;
    bool BOOL_RESULT = false;
    vector<int> VECTOR_RESULT;
    vector<vector<char>> VECTOR_2D_RESULT;

    string a = "abc";
    string b = "ad";

    BOOL_RESULT = S.canMakeSubsequence(a, b);
    //cout << VECTOR_RESULT;
    return 0;
}