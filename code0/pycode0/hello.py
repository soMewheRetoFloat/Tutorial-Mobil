
# backtrack 回溯
# dfs + iter


def subset(arr):
    res = []  # empty list
    n = len(arr)  # n == 5

    # nested fn
    # recur


'''
形式上模拟你的思维。实现上把内存管理交给 system
'''
res = []

def dfs(idx, path, n):
    res.append(path)  # l = [1, 2, 3], l.append(2) -> [1, 2, 3, 2]
    for i in range(idx + 1, n):  # range 左闭右开
        dfs(i, path + [arr[i]], n)  # n is always 5 here

    dfs(-1, [], n)
    return res

arr = [1, 2, 3, 4, 5]
print(subset(arr), len(subset(arr)))
'''
Dry run: 用手和嘴跑代码
[[]]
[[], [1], [2], [3], [4], [5]]
i = 0, path + [arr[i]] = [1], n = 5
idx = 0
idx + 1 = 1,2,3,4
[[], [1], [2], [3], [4], [5], [1,2], [1,3], [1,4], [1,5]]
starts with 1, len is 2, all found
i = 1, path + [arr[i]] = [2], n = 5

Ques 1:
[[1,2], [2,1]]??
only [1, 2]

Ques 2:
will this fn stop? if so, when?

Ques 3:
What if i want true subset?

Ques 4:
What if i want non-empty subset?
'''
"""
Method 1:
[]
1
12
13
14
15
123
124
125
134
135
145
.......
"""

# Task
# 手写 [1, 2, 3] 每一层的每一个变量，并计算复杂度（时间、空间）
# 熟悉一下就行，不用给我看，确保你 dry run 和 ide run 输出一样