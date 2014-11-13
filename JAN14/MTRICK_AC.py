t = int(raw_input());
while(t != 0):
	n = int(raw_input());
	array = map(int, raw_input().split());
		
	A, B, C = map(int, raw_input().split());
	
	X = A%C;
	Y = B%C;
	Z = C;
	s = str(raw_input());

	mul=1;
	add=0;
	swap = False;
	swap_ptr=0;

	for i in range(0, n):
		op = s[i];
		if (op=='A'):
			add = (add+X)%C;
		if (op=='M'):
			mul = (mul*Y)%C;
			add = (add*Y)%C;
		if (op=='R'):
			tmp = array[i:];
			for p in range(n-i-1, -1,-1):
				array[n-1-p] = tmp[p];
			#array[i], array[n-1] = array[n-1], array[i];
			#swap=True;
			array[i] = ( (((array[i]%Z)*(mul%Z))%Z) + (add%Z))%Z;
			#swap_ptr=2;
			#for j in range(0, n-1):
			#	print array[j],
			#print array[n-1];
			
			continue;

		#if (swap==True):
		#	if (i+1<n-swap_ptr):
		#		array[i+1], array[n-swap_ptr] = array[n-swap_ptr], array[i+1];
		#		swap_ptr += 1;
		#	else:
		#		swap=False;
		array[i]=( (((array[i]%Z)*(mul%Z))%Z) + (add%Z)) %Z;

	for j in range(0, n-1):
		print array[j],
	print array[n-1];
	t -= 1;