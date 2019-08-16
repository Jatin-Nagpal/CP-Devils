#define TP int
int n=100005;
TP bit[100005]; //Check the limits Dummy
TP Func(TP a,TP b) {
	return (a+b);
}
TP sum(int r) {
	TP ret = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		ret=Func(ret,bit[r]);
	return ret;
}
int sum(int l, int r) {
	return sum(r) - sum(l - 1);
}
void add(int idx, int delta) {
	for (; idx < n; idx = idx | (idx + 1))
		bit[idx]=Func(bit[idx],delta);
}