#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <windows.h>
#include "baseSort.h"
#include "shellsort.h"
#include "shellSortPro.h"
#include "heapSort.h"
#include "binSort.h"
#include "radixSortDec.h"
#include "testSort.h"

using namespace std;
const string RANDOM = "RANDOM";
const string INCREASE = "INCREASE";
const string DECREASE = "DECREASE";



/**
 * 随机数生成
 * 规模： 10 100 1000 10000 100000 1000000 10000000
 * 文件生成(先生成输入文件，然后输出排序后的文件，顺便输出相应的执行时间)
 * 时间计算(从开始到结束)
 *
 * */
void generateRandomData(string sortName, int size, string mode, int round);
bool compare_increase(int a, int b);
bool compare_decrease(int a, int b);
template <typename E>
double execute(baseSort<E>* base, int size, string mode, int round,int repeat);
int read();
void write(int x);
template <typename E>
void singleRoundTest(baseSort<E>* base, int size, string mode, int repeat);
template <typename E>
void multiRoundTest(baseSort<E>* base, int size, string mode,int round, int repeat);
void clear();



int main() {
    //Initialize
    shellSort<int>* shellsort = new ::shellSort<int>;
    shellSortPro<int>* shellsortpro = new ::shellSortPro<int>;
    testSort<int>* testsort = new ::testSort<int>;
    heapSort<int>* heapsort = new ::heapSort<int>;
    binSort<int>* binsort = new ::binSort<int>;
    radixSortDec<int>* radixsortdec = new ::radixSortDec<int>;

    srand(time(NULL));
    cout << binsort->getName() << endl;
    int testSize = 10000;
    //testSize最大不能超过：
    //100000001
    
    cout << testSize * sizeof(int)/1024/1024 << endl;
   

    //singleRoundTest(binsort, testSize, RANDOM);
    multiRoundTest(shellsortpro, testSize, RANDOM,1,1);


   /* generateRandomData(radixsortdec->getName(),testSize, RANDOM, 0);
    execute(radixsortdec, testSize, RANDOM, 0);

    generateRandomData(binsort->getName(),testSize, RANDOM, 0);
    execute(binsort, testSize, RANDOM, 0);


    generateRandomData(heapsort->getName(), testSize, RANDOM, 0);
    execute(heapsort, testSize, RANDOM, 0);*/

    delete shellsort;
    delete testsort;
    delete heapsort;
    delete binsort;
    clear();
    return 0;
}



void generateRandomData(string sortName,int size, string mode, int round) {
    int dataSet[MAXLENGTH];
    //默认单个数据大小为0~50000
    sortName = "./" + sortName + "_" +std::to_string(size) + "_" + mode +"_" + std::to_string(round) + ".txt";
    cout << sortName << endl;
    const char* fileName = sortName.c_str();

    for (int i = 1; i <= size; ++i) {
        dataSet[i] = rand()*rand() % 100000001;
        //dataSet[i] = rand()*rand() % 500000001;
    }
    if (mode == INCREASE) {
        sort(dataSet + 1, dataSet + 1 + size, compare_increase);
    }
    if (mode == DECREASE) {
        sort(dataSet + 1, dataSet + 1 + size, compare_decrease);
    }
  /*  for (int i = 1; i <= size; ++i) {
        cout << dataSet[i] << endl;
    }*/
    //Output to file
    FILE* fp = freopen(fileName, "w", stdout);
    cout << size << endl;
    for (int i = 1; i <= size; ++i) {
        //cout << dataSet[i] << endl;
        write(dataSet[i]);
        printf("\n");
    }
    fflush(fp);
    freopen("CON", "w", stdout);
}
template <typename E>
double execute(baseSort<E>* base, int size, string mode, int round,int repeat) {
    int dataSet[MAXLENGTH];
    int result[MAXLENGTH];
    // sortName = "./" + sortName + "_" +std::to_string(size) + "_" + mode + ".txt";
    string fileName = "./" + base->getName() + "_" + to_string(size) +"_" + mode + "_" + std::to_string(round) + ".txt";
    const char* filePath = fileName.c_str();
    freopen(filePath, "r", stdin);
    int temp;
    scanf("%d", &temp);
    for (int i = 1; i <= size; ++i) {
        temp = read();
        dataSet[i] = temp;
    }
    /*cout << "Test:" << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << dataSet[i] << endl;
    }*/


    DWORD startTime = GetTickCount64();//计时开始
    for (int i = 1; i <= repeat; i++)
    {
        base->prepare(dataSet, size);
        if(repeat<=3)
        printf("Ready to execute\n");
        base->sort(size);
        if(repeat<=3)
        printf("Over\n");
    }
    DWORD endTime = GetTickCount64();//计时结束

    cout << "startTime:" << startTime << endl;
    cout << "endTime:" << endTime << endl;
    cout << "repeatTimes:" << repeat << endl;
    int temp2 = endTime - startTime;
    double exeTime = temp2 * 1.0/repeat;
    cout <<"Time consuming:" << exeTime << endl;
    
    //base->printAll(size);

    return exeTime;
}
bool compare_increase(int a, int b)
{
    return a < b;
}
bool compare_decrease(int a, int b)
{
    return a > b;
}
inline int read() {
    register int x = 0, t = 1;
    register char ch = getchar(); // 读入单个字符到寄存器
    while (ch < '0' || ch>'9') {
        if (ch == '-')
            t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);  // 移位与异或
        // 第十行可以换成 x = x * 10 + ch - '0'
        ch = getchar();
    }
    return x * t;
}
inline void write(int x)
{
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
template <typename E>
void singleRoundTest(baseSort<E>* base, int size, string mode, int repeat)
{
    generateRandomData(base->getName(), size, mode, 1);
    execute(base, size, mode, 1, repeat);
}
template <typename E>
void multiRoundTest(baseSort<E>* base, int size, string mode, int round, int repeat)
{
    double totalTime = 0;
    double roundTime[10000];
    memset(roundTime, 0, sizeof(roundTime));
    for (int i = 1; i <= round; i++)
    {
        generateRandomData(base->getName(), size, mode, i);
        roundTime[i] = execute(base, size, mode, i,repeat);
    }
    for (int i = 1; i <= round; i++)
    {
        cout << "Round " << i << ": " << roundTime[i] << endl;
        totalTime += roundTime[i];
    }
    cout << "Average Time Consuming: " << totalTime / round*1.0 << endl;
}
void clear()
{
    //TODO 未完成
}