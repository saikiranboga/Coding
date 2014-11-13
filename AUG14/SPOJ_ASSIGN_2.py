n = int(raw_input());
M = [[0 for cols in range(100)] for rows in range(100)]
for i in range(n):
	line = map(int,raw_input().split(' '));
	for j in line:
		M[i][j-1] = 1;

#M = [[1,1,1,0],[1,1,1,0],[1,1,1,0]]
L = len(M)
M = [[k for k in xrange(L) if l[k] == 1] for l in M]

def count_assignment(taken,row):
       if row >= L: return 1
       c = 0
       for e in M[row]:
          if e not in taken: c = c + count_assignment(taken + [e], row + 1)
       return c

print count_assignment([], 0)