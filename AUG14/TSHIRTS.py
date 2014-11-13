def main():
	n=int(raw_input());

	cnts=[0]*(n+1);
	ar=[0]*(n+1);
	ar_sizes=[0]*(n+1);
	prod=1;

	for i in range(n):
		line = map(int,raw_input().split(" "));
        ar_sizes[i] += len(line);
        prod = prod*ar_sizes[i];
        for j in line:
            ar[i] = ar[i] | (1<<j);
	
	print ar_sizes[0];

	mx = (1<<n)-1;

	mk = int(3);
	ind = int(0);
	for m in range(3,mx):
		ind = int(0);
    	msk = mk;
    	first_seen = False;
    	accumulate = int(0);
    	n_sets = int(0);
    	cur_prod = prod;

    	while(msk>0):
    		if(msk&1==1):
    			n_sets += 1;
    			if(first_seen==False):
    				accumulate = ar[ind];
    				first_seen = True;
				accumulate = accumulate & ar[ind];
    			cur_prod = cur_prod/ar_sizes[ind];
    		ind += 1;
    		msk = msk/2;

    	intersxn = int(0);
    	while(accumulate>0):
    		if(accumulate&1==1):
    			intersxn += 1;
    		accumulate /= 2;

    	cnts[n_sets] += (intersxn*cur_prod);
    	mk += 1;

	ans = prod;
	for i in range(2,n+1):
		ans = ans + pow(-1,i+1)*cnts[i];

	print ans;

t = int(raw_input());
while(t>=0):
	main();
	t -= 1;