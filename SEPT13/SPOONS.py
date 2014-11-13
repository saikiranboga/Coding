import math
t = int(raw_input());
while t !=0 :
    n = int(raw_input());
    if n == 2:
        print 2;
    else:
        x = int((1+math.sqrt(1+8*n))/2);
        x += 10;
        temp = x*(x-1);
        while (temp >= 2*n):            
            x -= 1;
            temp = x*(x-1);
        x += 1;
        print int(x);
    t -= 1;
