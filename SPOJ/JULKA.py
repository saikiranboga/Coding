t = 10;
while(t):
	n = int(raw_input());
	e = int(raw_input());
	second = int((n-e)/2);
	first = int((n-e)/2) + e;
	print first;
	print second;
	t -=1;