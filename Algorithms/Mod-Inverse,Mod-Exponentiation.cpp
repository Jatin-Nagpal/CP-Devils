int power(int x,int y,int m) 
{
	if(y == 0) 
		return 1; 
	int p = power(x, y/2, m) % m; 
	p = (p * p) % m; 
	return (y%2 == 0)? p : (x * p) % m; 
}
int modinv(int a, int m) 
{ 
	return power(a, m-2, m);
}