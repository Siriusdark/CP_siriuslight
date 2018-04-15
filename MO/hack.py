n = int(raw_input())
mymap = {}
for i in range(n):
	line = raw_input().split()
	name, scores = line[0], line[1:]
	scores = map(float,scores)
	avg = 0.0
	for j in scores:
		avg = avg + j
	avg = avg / 3.0;
	mymap[name] = avg

query = raw_input()
print mymap[query]
