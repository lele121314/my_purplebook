import os
import json
import random
import math
import shutil

folders = ['down', 'data']

random.setstate(eval(open('random_state').read()))

def gen(f, glb_args, args):
	n = args['n']
	k = args['k']
	if 'graph' in args:
		lower = glb_args['upper'] // 2
		upper = lower * 2
	else:
		lower = 1
		upper = glb_args['upper'] // (n // 2)
	f.write('%d %d\n' % (n, k))
	tweak = lambda y : y // 10000 if 'tweak' in args else y
	graph = [
		[
			tweak(random.randint(lower, upper)) if i != j else 0 \
			for j in range(n)
		] for i in range(n)
	]
	
	if 'graph' in args:
		seq = list(range(n))
		if args['graph'] == 0:
			for i in range(1, n):
				graph[seq[i - 1]][seq[i]] = random.randint(1, lower // (n * n))
		elif args['graph'] == 1:
			sub = seq[1:]
			random.shuffle(sub)
			seq = [0] + sub
			for i in range(1, n):
				graph[seq[random.randint(0, i - 1)]][seq[i]] = random.randint(1, lower // (n * n))
		elif args['graph'] == 2:
			sub = seq[1:]
			random.shuffle(sub)
			seq = [0] + sub
			for i in range(n * 10):
				while True:
					x = random.randint(0, n - 1)
					y = random.randint(0, n - 1)
					if x < y:
						break
				graph[seq[x]][seq[y]] = random.randint(1, lower // (n * n))
	if 'shortest' in args and args['shortest']:
		for p in range(n):
			for i in range(n):
				for j in range(n):
					graph[i][j] = min(graph[i][j], graph[i][p] + graph[p][j])
	for line in graph:
		f.write(' '.join(map(str, line)) + '\n')
	used = set()
	tweak = lambda y : (y // 100000 if args['tweak'] == x + 1 else y // 10000) if 'tweak' in args else y
	#tweak = lambda y : y // 10 if 'tweak' in args and args['tweak'] == x + 1 else y
	for i in range(k):
		while True:
			x = random.randint(0, n - 1)
			if x not in used:
				break
		used.add(x)
		f.write('%d %d\n' % (x + 1, tweak(random.randint(
			glb_args['upper'] // 2 if 'valuable ruby' in args else 1, 
			glb_args['upper'] if 'graph' not in args else lower // n
		))))
	if 'ans' in args:
		ans = max(args['ans'])
		scoring = sorted(args['ans'])
		l = len(scoring) - 1
		f.write(' '.join(map(str,
			[ans - scoring[i * l // 8] for i in range(8)]
		)) + '\n')
	
if __name__ == '__main__':
	try:
		os.makedirs('data')
	except:
		pass
	try:
		os.makedirs('data/chk')
	except:
		pass
	try:
		os.makedirs('down')
	except:
		pass
	try:
		os.makedirs('down/checker')
	except:
		pass
	shutil.copyfile('checker.cpp', 'data/chk/chk.cpp')
	shutil.copyfile('checker.cpp', 'down/checker/checker.cpp')
	conf = json.loads(open('prob.json', 'rb').read().decode('utf-8'))
	for folder in folders:
		for item in conf[folder]:
			for case in item['cases']:
				print('case %s %d' % (folder, case))
				with open(os.path.join(folder, conf['name'] + str(case) + '.in'), 'w') as fin:
					gen(fin, conf['args'], item['args'])
				if folder != 'down' and 'ans' in item['args']:
					with open(os.path.join(folder, conf['name'] + str(case) + '.ans'), 'w') as fans:
						fans.write('%d\n' % max(item['args']['ans']))
