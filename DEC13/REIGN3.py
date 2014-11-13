def main():
  ntest = int(raw_input());
  while ntest != 0:
      n,k = map(int, raw_input().split());
      HardLeftMax = [0]*n;
      HardRightMax = [0]*n;
      SoftLeftMax = [0]*n;
      SoftRightMax = [0]*n;

      a = map(int, raw_input().split());

      HardLeftMax[0] = a[0];
      for i in range(1,n):
          HardLeftMax[i] = max(HardLeftMax[i-1]+a[i], a[i]);
  
      HardRightMax[n-1] = a[n-1];
      for i in range(n-2, -1, -1):
          HardRightMax[i] = max(HardRightMax[i+1]+a[i], a[i]);

      SoftLeftMax[0] = a[0];
      for i in range(1,n):
          SoftLeftMax[i] = max(HardLeftMax[i], SoftLeftMax[i-1]);

      SoftRightMax[n-1] = a[n-1];
      for i in range(n-2, -1, -1):
          SoftRightMax[i] = max( HardRightMax[i], SoftRightMax[i+1]);

      res = -1*pow(10,10);

#      print HardLeftMax;
#      print HardRightMax;
#      print SoftLeftMax;
#      print SoftRightMax;

      for i in range(0, n-k-1):
          res = max(res, (SoftLeftMax[i] + SoftRightMax[i+k+1]));

      print res;
      ntest -= 1;

main();
