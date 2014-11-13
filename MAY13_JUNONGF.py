MOD = 1000000007
def repeat_sqr(base, power):
    if(power == 1):
        return base;    
    elif(power ==0):
        return 1;
    else:
        temp = repeat_sqr(base,power/2);
        if(power%2 == 0):
            return ((temp*temp)%MOD);        
        else:
            return ((((temp*temp)%MOD)*base)%MOD);  

def main():
    t = int(raw_input());
    for i in range(t):
        P=[];
        Q=[];
        L=[];
        V,N = map(int,raw_input().split(' '));
        p0,p1,A0,B0,C0,M0=map(int,raw_input().split(' '));
        q0,q1,A1,B1,C1,M1=map(int,raw_input().split(' '));
        P.append(p0);P.append(p1);
        Q.append(q0);Q.append(q1);
        for j in range(2,N):
            P.append((A0 * A0 * P[j-1] + B0 * P[j-2] + C0 )% (M0));
            Q.append((A1 * A1 * Q[j-1] + B1 * Q[j-2] + C1 )% (M1));
        for j in range(0,N):
            L.append(P[j]*(M1)+Q[j]+1);        

#        ans = 1;
#        power = 1;
#        for j in range(0,N):
#            power = power*(L[j]-1);

#        for j in range(0,power):
#            ans = (ans*V)%MOD;

        ans = V
        for j in range(0,N):
            ans = (repeat_sqr(ans,L[j]-1))%MOD;
      
        print (ans%MOD);

main()
