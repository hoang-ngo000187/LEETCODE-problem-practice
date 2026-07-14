#include<iostream>
#include<bits/stdc++.h>
#include<stdint.h>

#define NUM_MAX         (10)
#define MULTIPLY_BTN    (1)
#define ENTER_BTN       (1)
#define IMPOSSIBLE      (-1)

using namespace std;

int32_t CheckCurrNumIsValid(uint32_t u32Num, uint32_t u32Arr[])
{
    int32_t n32Ret = 0;
    uint32_t u32R = 0;
    
    while (u32Num > 0)
    {
        u32R = (u32Num) % (10);
        u32Num /= 10;

        if (u32Arr[u32R] != 1)
        {
            n32Ret = IMPOSSIBLE;
            break;
        }
        else
        {
            n32Ret++;
        }
    }

    return n32Ret;
}

int32_t CalculateMinPressedTimes(uint32_t u32Num, uint32_t u32Arr[])
{
    int32_t n32Ret = 0, n32Temp = 0;
    uint32_t u32Num_1 = 0, u32Num_2 = 0, u32Times_1 = 0, u32Times_2 = 0;

    n32Ret = CheckCurrNumIsValid(u32Num, u32Arr);

    if (n32Ret != IMPOSSIBLE)
    {
        return n32Ret;
    }
    else
    {
        n32Ret = INT_MAX;

        for (u32Num_1 = 2; u32Num_1*u32Num_1 < u32Num; u32Num_1++)
        {
            if (u32Num % u32Num_1 == 0)
            {
                u32Num_2 = (u32Num)/(u32Num_1);

                u32Times_1 = CalculateMinPressedTimes(u32Num_1, u32Arr);
                u32Times_2 = CalculateMinPressedTimes(u32Num_2, u32Arr);

                if ((u32Times_1 != INT_MAX) && (u32Times_2 != INT_MAX))
                {
                    n32Temp = u32Times_1 + u32Times_2 + MULTIPLY_BTN;

                    if (n32Temp < n32Ret)
                    {
                        n32Ret = n32Temp;
                    }
                }
            }
        }
    }

    return n32Ret;
}

int main()
{
    int test_case;
    int T;

    freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        uint32_t u32MinPressed = 0;
        uint32_t u32ArrValidNums[NUM_MAX] = {0};
        uint32_t u32X = 0, u32X01 = 0, u32X02 = 0;
        int32_t n32Times01 = 0, n32Times02 = 0;

        for(int32_t n32i = 0; n32i < NUM_MAX; n32i++)
        {
            cin >> u32ArrValidNums[n32i];
        }
        
        cin >> u32X;
        
        /* check if u32X can be pressed by current valid nums or not */
        u32MinPressed = CalculateMinPressedTimes(u32X, u32ArrValidNums) + ENTER_BTN;

        cout << "#" << test_case << " " << u32MinPressed << endl;
    }

    return 0;
}