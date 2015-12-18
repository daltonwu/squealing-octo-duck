def area(a, b, c):
	m = a * b
	n = a * c
	o = b * c
	return 2 * (m + n + o) + min(m, min(n, o))
def main():
	count = 0
	f = open('input-02-1.txt', 'r')
	s = f.read()
	ss = s.split()
	for line in ss:
		sss = line.split('x');
		count += area(int(sss[0]), int(sss[1]), int(sss[2]))
	print count
main()
