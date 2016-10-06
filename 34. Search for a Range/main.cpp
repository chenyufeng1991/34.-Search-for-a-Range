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
        long left = index;
        long right = index;
        for (long i = index - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                left = i;
                continue;
            }
            else
            {
                break;
            }
        }
        for (long i = index + 1; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                right = i;
                continue;
            }
            else
            {
                break;
            }
        }

        result.push_back((int)left);
        result.push_back((int)right);
    }

    return result;
}

int main(int argc, const char * argv[])
{
    int arr[] = {1,1,2};
    vector<int>vv(arr,arr+sizeof(arr)/sizeof(int));

    vector<int> res = searchRange(vv, 1);

    return 0;
}
