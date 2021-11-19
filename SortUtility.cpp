#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <windows.h>
#include "baseSort.h"
#include "shellsort.h"
#include "testSort.h"

using namespace std;
const string RANDOM = "RANDOM";
const string INCREASE = "INCREASE";
const string DECREASE = "DECREASE";



/**
 * 随机数生成
 * 规模： 10 100 1000 10000 100000 1000000
 * 文件生成(先生成输入文件，然后输出排序后的文件，顺便输出相应的执行时间)
 * 时间计算(从开始到结束)
 *
 * */
void generateRandomData(int size, string sortName, string mode, int append);
bool compare_increase(int a, int b);
bool compare_decrease(int a, int b);
template <typename E>
void execute(baseSort<E>* base, int size, string mode, int append);
int main() {
    //Initialize
    shellsort<int>* shellsort = new ::shellsort<int>;
    testSort<int>* testsort = new ::testSort<int>;
    srand(time(NULL));
    cout << testsort->getName() << endl;
    generateRandomData(10, testsort->getName(), RANDOM, 0);
    cout << "123" << endl;
    execute(testsort, 10, RANDOM, 0);
    delete shellsort;
    delete testsort;
    return 0;
}
void generateRandomData(int size, string sortName, string mode, int append) {
    //TODO append未实现
    cout << "123" << endl;
    int dataSet[MAXLENGTH];
    //默认单个数据大小为0~50000
    sortName = "./" + sortName + "_" +std::to_string(size) + "_" + mode + ".txt";
    cout << sortName << endl;
    const char* fileName = sortName.c_str();

    for (int i = 1; i <= size; ++i) {
        dataSet[i] = rand() % 50001;
    }
    if (mode == INCREASE) {
        sort(dataSet + 1, dataSet + 1 + size, compare_increase);
    }
    if (mode == DECREASE) {
        sort(dataSet + 1, dataSet + 1 + size, compare_decrease);
    }
    for (int i = 1; i <= size; ++i) {
        cout << dataSet[i] << endl;
    }
    //Output to file
    FILE* fp = freopen(fileName, "w", stdout);
    cout << size << endl;
    for (int i = 1; i <= size; ++i) {
        cout << dataSet[i] << endl;
    }
    fflush(fp);
    freopen("CON", "w", stdout);
    printf("OVER");
}
template <typename E>
void execute(baseSort<E>* base, int size, string mode, int append) {
    cout << "1233" << endl;
    int dataSet[MAXLENGTH];
    int result[MAXLENGTH];
    // sortName = "./" + sortName + "_" +std::to_string(size) + "_" + mode + ".txt";
    string fileName = "./" + base->getName() + "_" + to_string(size) +"_" + mode + ".txt";
    const char* filePath = fileName.c_str();
    freopen(filePath, "r", stdin);
    int temp;
    scanf("%d", &temp);
    for (int i = 1; i <= size; ++i) {
        scanf("%d", &temp);
        dataSet[i] = temp;
    }
    cout << "Test:" << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << dataSet[i] << endl;
    }
    base->prepare(dataSet, size);
    cout << "Ready to execute" << endl;
    DWORD startTime = GetTickCount64();//计时开始
    base->sort(size);
    cout << "Over" << endl;
    //result = base->getresult();
    DWORD endTime = GetTickCount64();//计时结束
    cout << startTime - endTime << endl;

    //TODO 输出相应文件
}
bool compare_increase(int a, int b)
{
    return a < b;
}
bool compare_decrease(int a, int b)
{
    return a > b;
}