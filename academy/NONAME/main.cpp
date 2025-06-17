#include<iostream>
#include<bits/stdc++.h>
#include<stdint.h>

using namespace std;

typedef long long (LL);

int computeSNModM(LL llN, int iM)
{
    if (llN == 0)
    {
        return (0%iM);
    }

    if (llN == 1)
    {
        return (1%iM);
    }

    LL llRemainder_i2 = (0%iM);
    LL llRemainder_i1 = (1%iM);
    LL llRemainder_i = 0;

    for(int i = 2; i <= llN; i++)
    {
        int iTemp1 = ((LL)llRemainder_i1 * llRemainder_i1) % iM;
        iTemp1 = (iTemp1 * llRemainder_i1) % iM;

        int iTemp2 = ((LL)llRemainder_i2 * llRemainder_i2) % iM;
        iTemp2 = (iTemp2 * llRemainder_i2) % iM;

        llRemainder_i = (iTemp1 + iTemp2) % iM;

        llRemainder_i2 = llRemainder_i1;
        llRemainder_i1 = llRemainder_i;
    }

    return llRemainder_i;
}

int main()
{
    int test_case;
    int T;

    freopen("input1.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int iM = 0;
        LL llN = 0;

        cin >> llN >> iM;

        int result = computeSNModM(llN, iM);

        cout << "#" << test_case << " " << result << endl;
    }

    return 0;
}