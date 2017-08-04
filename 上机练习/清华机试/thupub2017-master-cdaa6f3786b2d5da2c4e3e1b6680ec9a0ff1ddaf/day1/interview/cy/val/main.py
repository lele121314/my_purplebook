# encoding: utf-8

import os, sys, re, json

def process(index, nmin, nmax, mmin, mmax, kmin, kmax, hmin, hmax):
    print 'process', index
    input_file = ''
    output_file = ''
    if index < 0:
        input_file = '../down/interview%d.in' % (-index)
        output_file = '../down/interview%d.ans' % (-index)
    else:
        input_file = '../data/interview%d.in' % (index)
        output_file = '../data/interview%d.ans' % (index)
    
    cmd = './val.exe -nmin %d -nmax %d -mmin %d -mmax %d -kmin %d -kmax %d -hmin %d -hmax %d < %s' % (nmin, nmax, mmin, mmax, kmin, kmax, hmin, hmax, input_file)
    print cmd
    assert os.system(cmd) == 0
    assert os.system('cp %s interview.in' % input_file) == 0
    assert os.system('./std.exe') == 0
    assert os.system('diff %s interview.out' % output_file) == 0

def parse(name, arg):
    for i in range(1,10):
        a = '^%d' % i
        b = ''.join(['0' for k in range(i-1)])
        arg = arg.replace(a, b)
    d = re.compile(r'(\d+)\*(\d+)').search(arg)
    while d:
        arg = arg.replace(d.group(0), str(int(d.group(1))*int(d.group(2))))
        d = re.compile(r'(\d+)\*(\d+)').search(arg)

    pos = arg.find(name)
    mx = None
    mi = None
    if re.compile(r'\d+').search(arg[pos+1:]): mx = int(re.compile(r'\d+').search(arg[pos+1:]).group(0))
    if re.compile(r'\d+').search(arg[:pos][::-1]): mi = int(re.compile(r'\d+').search(arg[:pos][::-1]).group(0)[::-1])
    if mx == None: mx = mi
    if mi == None: mi = mx
    return [mi, mx]

def main():
    nmin = 1
    nmax = 100000
    mmin = 1
    mmax = 100000
    kmin = 0
    kmax = 100000
    hmin = 1
    hmax = 100000

    process(-1, nmin, nmax, mmin, mmax, kmin, kmax, hmin, hmax)
    process(-2, nmin, nmax, mmin, mmax, kmin, kmax, hmin, hmax)
    process(-3, nmin, nmax, mmin, mmax, kmin, kmax, hmin, hmax)
    process(-4, nmin, nmax, mmin, mmax, kmin, kmax, hmin, hmax)

    data = json.load(open('../prob.json'))['data']
    for index in range(1, 21):
        for info in data:
            if index in info['cases']:
                for arg in info['args']:
                    if arg == None: continue
                    if 'n' in arg:
                        [nmin, nmax] = parse('n', arg)
                    if 'm' in arg:
                        [mmin, mmax] = parse('m', arg)
                    if 'k' in arg:
                        [kmin, kmax] = parse('k', arg)
                    if 'h' in arg:
                        [hmin, hmax] = parse('h', arg)
        print index, nmin, nmax, mmin, mmax, kmin, kmax, hmin, hmax
        process(index, nmin, nmax, mmin, mmax, kmin, kmax, hmin, hmax)

if __name__ == '__main__':
    main()