/* **************************************************************************

    * File Name : The_3n+1_problem.cpp

    * Creation Date : 2018-08-30 09:37:55

    * Last Modified : 2018-08-30 10:13:44

    * Created By : Samuel Chi <Yu-Ning Chi>

************************************************************************** */

#include <iostream>
using namespace std;

int cycleLength(int n) //計算循環次數，使用考拉茲公式進行遞迴
{
    if(n == 1)
        return 1; //如果n為1，則回傳1
    else if(n % 2 == 0) //n為偶數，則n除以2，並加上自己本身，故加1
        return cycleLength(n / 2) + 1;
    else //n為奇數，則n乘以3加1，並加上自己本身，故加1
        return cycleLength(n * 3 + 1) + 1;
}

int main()
{
    int inputNum_1, inputNum_2; //輸入的兩個數字
    int firstNum, secondNum; //firstNum為輸入數字中較小數，secondNum為較大數
    int Max; //循環次數最大者

    while(cin >> inputNum_1 >> inputNum_2)
    {
        Max = 0; //初始化Max
        if(inputNum_1 < inputNum_2) //若inputNum_2大於inputNum_1
        {
            firstNum = inputNum_1;
            secondNum = inputNum_2;
        }
        else
        {
            firstNum = inputNum_2;
            secondNum = inputNum_1;
        }
        for(int i = firstNum; i <= secondNum; i++) //根據範圍測試何數最大
            Max = (Max < cycleLength(i)) ? cycleLength(i) : Max;
        cout << inputNum_1 << " " << inputNum_2 << " " << Max << endl; //印出
    }
    return 0;
}
