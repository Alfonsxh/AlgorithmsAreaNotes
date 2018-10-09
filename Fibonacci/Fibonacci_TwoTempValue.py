"""
@author: Alfons
@contact: alfons_xh@163.com
@file: Fibonacci_TwoTempValue.py
@time: 18-10-9 下午8:38
@version: v1.0 
"""


def FibsWithTempValue(n):
    i = 0
    first = 0
    second = 1

    while i < n - 1:
        tmp = first
        first = second
        second += tmp
        i += 1

    return second


if __name__ == "__main__":
    numZS = int(input('How many Fibonacci numbers do you want? '))
    print(FibsWithTempValue(numZS))
