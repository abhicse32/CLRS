#!/usr/bin/python
from random import randint
from datetime import datetime

class Max_Subarray:
    #arr is the array whose maximum subarray is to be calculated,
    def __init__(self,arr=None):
        self.arr= arr
        self.size = len(self.arr)
        self.INT_MIN = -10**18

    def brute_force(self):
        '''Starts with calculating the sum of the subarray from index (1...i) and sotres the
        result at index i. Next it considers all pairs of indices which may contain the maximum subarray'''

        calculated_sums, calculated_sums[0] = [0]*self.size, self.arr[0]
        for i in range(1,self.size): calculated_sums[i] = calculated_sums[i-1] + self.arr[i]
        max_val, left_index, right_index = self.INT_MIN, -1, -1
        calculated_sums = [0] + calculated_sums
        for i in range(1,self.size):
            for j in range(i,self.size+1):
                range_sum = calculated_sums[j] - calculated_sums[i-1]
                if range_sum >= max_val:
                    max_val, left_index, right_index = range_sum, i-1, j-1

        return (max_val, left_index, right_index)

    # This will return the maximum subarray crossing the mid point
    def find_maximum_crossing_subarray(self, left, mid, right):
        left_index, left_sum, right_index, right_sum, current_sum = -1, self.INT_MIN, -1, self.INT_MIN, 0
        for i in range(mid,left-1,-1):
            current_sum += self.arr[i]
            if left_sum < current_sum:
                left_sum, left_index = current_sum, i

        current_sum = 0
        for i in range(mid+1,right+1):
            current_sum += self.arr[i]
            if right_sum < current_sum:
                right_sum, right_index = current_sum, i

        return (left_sum + right_sum,left_index,right_index)

    def find_maximum_subarray(self,left,right):
        if left >= right:
            return (self.arr[left],left,right)
        mid = (left+right)>>1
        left_sum, left_left, left_right = self.find_maximum_subarray(left, mid)
        right_sum, right_left, right_right = self.find_maximum_subarray(mid+1,right)
        mid_sum, mid_left, mid_right = self.find_maximum_crossing_subarray(left, mid, right)

        if left_sum >= right_sum and left_sum >= mid_sum:
            return (left_sum, left_left, left_right)
        elif mid_sum >= right_sum and mid_sum >= left_sum:
            return (mid_sum, mid_left, mid_right)
        else:
            return (right_sum, right_left, right_right)

    """Linear Time Maximum Subarray"""
    def linear_time_Maximum_Subarray(self):
        max_sum, current_sum, left_index, right_index, i = self.INT_MIN, 0, -1, -1, 0
        for j in range(0, self.size):
            current_sum += self.arr[j]
            if current_sum > max_sum:
                max_sum, left_index, right_index = current_sum, i, j

            if current_sum <= 0:
                i, current_sum = j+1, 0

        return (max_sum, left_index, right_index)


    def D_and_C(self):
        return self.find_maximum_subarray(0,self.size-1)

if __name__=='__main__':
    array = [randint(-10,20) for i in range(randint(15,25))]
    max_subarray = Max_Subarray(array)
    print array
    print max_subarray.brute_force()
    print max_subarray.D_and_C()
    print max_subarray.linear_time_Maximum_Subarray()


