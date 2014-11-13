import operator
# A slightly efficient superset of primes.

cases = int(raw_input())

def PrimesPlus():
  yield 2
  yield 3
  i = 5
  while True:
    yield i
    if i % 6 == 1:
      i += 2
    i += 2
# Returns a dict d with n = product p ^ d[p]
def GetPrimeDecomp(n):
  d = {}
  primes = PrimesPlus()
  for p in primes:
    while n % p == 0:
      n /= p
      d[p] = d.setdefault(p, 0) + 1
    if n == 1:
      return d
def NumberOfDivisors(n):
  d = GetPrimeDecomp(n)
  powers_plus = map(lambda x: x+1, d.values())
  return reduce(operator.mul, powers_plus, 1)

while cases != 0:
  num = int(raw_input());
  ans = 0;
  for nm in range(1,num+1):
    temp = NumberOfDivisors(nm);
    ans += temp;
  print str(ans)+'/'+str(num*num);
  cases -= 1;
