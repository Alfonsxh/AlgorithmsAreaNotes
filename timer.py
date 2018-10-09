"""
@author: Alfons
@contact: alfons_xh@163.com
@file: timer.py
@time: 18-10-8 下午10:44
@version: v1.0 
"""
import time


def timer(func):
    def wrapper(*args, **kwargs):
        startTime = time.time()
        ret = func(*args, **kwargs)
        stopTime = time.time()

        print("{func} use time -> {time}'s".format(func=func.__name__,
                                                   time=stopTime - startTime))
        return ret

    return wrapper
