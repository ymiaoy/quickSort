//
// Created by miao on 2019/9/27.
//

#ifndef INC_2019_9_27_SORTTESTHELPER_H
#define INC_2019_9_27_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper{
    //n 个元素的随机数组，每个元素的随机范围 [rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR)
    {
        //assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        //控制随机数生成范围[rangeL, rangeR]
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

}






#endif //INC_2019_9_27_SORTTESTHELPER_H
