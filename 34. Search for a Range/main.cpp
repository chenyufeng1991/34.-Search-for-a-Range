//
//  main.cpp
//  34. Search for a Range
//
//  Created by chenyufeng on 10/6/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 *  Given [5, 7, 7, 8, 8, 10] and target value 8,
     return [3, 4].
 *   
 使用二分查找
 */

long BinarySearch(vector<int>& nums, long begin, long end, int target)
{
    while (begin <= end)
    {
        long mid = (begin + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }
        else if (target > nums[mid])
        {
            begin = mid + 1;
        }
    }

    return -1;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    long begin = 0;
    long end = nums.size() - 1;

    long index = BinarySearch(nums, begin, end, target);

    vector<int> result;
    if (index == -1)
    {
        result.push_back(-1);
        result.push_back(-1);
    }
    else
    {
        // 继续进行二分查找
        long left = BinarySearch(nums, begin, index - 1, target);
        long right = BinarySearch(nums, index + 1, end, target);

        if (left == -1)
        {
            result.push_back((int)index);
        }
        else
        {
            result.push_back((int)left);
        }

        if (right == -1)
        {
            result.push_back((int)index);
        }
        else
        {
            result.push_back((int)right);
        }
    }

    return result;
}

int main(int argc, const char * argv[])
{
    int arr[] = {5, 7, 7, 8, 8, 10};
    vector<int>vv(arr,arr+sizeof(arr)/sizeof(int));

    vector<int> res = searchRange(vv, 7);

    return 0;
}





