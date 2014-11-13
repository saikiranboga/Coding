import sys;
from collections import namedtuple
from operator import mul

Info = namedtuple('Info', 'start height')

def max_size(mat, value=0):
    """Find height, width of the largest rectangle containing all `value`'s."""
    it = iter(mat)
    hist = [(el==value) for el in next(it, [])]
    max_size = max_rectangle_size(hist)
    for row in it:
        hist = [(1+h) if el == value else 0 for h, el in zip(hist, row)]
        max_size = max(max_size, max_rectangle_size(hist), key=area)
    return max_size

def max_rectangle_size(histogram):
    """Find height, width of the largest rectangle that fits entirely under
    the histogram.
    """
    stack = []
    top = lambda: stack[-1]
    max_size = (0, 0) # height, width of the largest rectangle
    pos = 0 # current position in the histogram
    for pos, height in enumerate(histogram):
        start = pos # position where rectangle starts
        while True:
            if not stack or height > top().height:
                stack.append(Info(start, height)) # push
            elif stack and height < top().height:
                max_size = max(max_size, (top().height, (pos - top().start)),
                               key=area)
                start, _ = stack.pop()
                continue
            break # height == top().height goes here

    pos += 1
    for start, height in stack:
        max_size = max(max_size, (height, (pos - start)), key=area)    
    return max_size

def area(size):
    return reduce(mul, size)

class LoL(list):
    def __init__(self, *args):
        list.__init__(self, *args)
    def __getitem__(self, item):
        try:
            return list.__getitem__(self, item)
        except TypeError:
            rows, cols = item
            return [row[cols] for row in self[rows]]

def main():
    #N, M, K = map(int, raw_input().split());
    N, M, K = map(int,sys.stdin.readline().split());
    m = LoL([[0]*M for i in range(N)]);
    for i in range(K):
        #x,y = map(int, raw_input().split());
        x, y = map(int, sys.stdin.readline().split());
        m[x-1][y-1] = 1;
    
    #Q = int(raw_input());
    Q = int(sys.stdin.readline());
    for i in range(Q):
        #r1, r2 = map(int, raw_input().split());
        r1, r2 = map(int, sys.stdin.readline().split());
        _m = m[r1-1:r2,:];
        print area( max_size(_m) );

main();