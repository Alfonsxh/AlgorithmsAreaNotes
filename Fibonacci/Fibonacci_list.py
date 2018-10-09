"""
@author: Alfons
@contact: alfons_xh@163.com
@file: Fibonacci_list.py
@time: 18-10-8 下午10:36
@version: v1.0 
"""
from timer import timer

fibs = [0, 1]


@timer
def FibsList(numZS):
    for i in range(numZS - 1):
        fibs.append(fibs[-2] + fibs[-1])

    print(fibs[-1])
    # for fib in fibs:
    #     print(fib)


if __name__ == "__main__":
    numZS = int(input('How many Fibonacci numbers do you want? '))
    FibsList(numZS)
    # 100 354224848179261915075