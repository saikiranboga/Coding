fact = 1
for i in range(91, 101):
	fact = fact*i;
for i in range(2, 11):
	fact = fact*i;
fact = fact%1000000007
print fact;