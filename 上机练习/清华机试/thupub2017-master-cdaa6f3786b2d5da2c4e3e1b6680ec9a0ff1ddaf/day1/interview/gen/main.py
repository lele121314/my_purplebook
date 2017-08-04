# encoding: utf-8

import os, sys

STD = '../cy/std.exe'

def process(index, n, m, k, h, seed):
    input_file = ''
    output_file = ''

    if index < 0:
        input_file = os.path.join('..', 'down', 'interview%d.in' % (-index))
        output_file = os.path.join('..', 'down', 'interview%d.ans' % (-index))
    else:
        input_file = os.path.join('..', 'data', 'interview%d.in' % (index))
        output_file = os.path.join('..', 'data', 'interview%d.ans' % (index))

    cmd = './random2.exe -n %d -m %d -k %d -h %d --seed %s > interview.in' % (n, m, k, h, seed)
    print cmd
    assert os.system(cmd) == 0
    assert os.system(STD) == 0
    assert os.system('cp interview.in %s' % input_file) == 0
    assert os.system('cp interview.out %s' % output_file) == 0

def main():
    process(-4, 900, 800, 500, 1000, '89u9n89809')

    process(1, 90, 60, 0, 70, 'sadqwe1')
    process(2, 98, 55, 0, 30, '3124e2dq')
    process(3, 1900, 740, 45, 100, '324234e23')
    process(4, 1990, 850, 43, 100, 'qdd12fw')
    process(5, 1990, 700, 90, 4900, '54353f2rd')
    process(6, 1987, 770, 98, 4980, '43t34f23df')
    process(7, 1999, 700, 80, 4990, '3542fec2')
    process(8, 2000, 760, 99, 5000, '342r2edc2w')
    process(9, 1990, 790, 2100, 5000, '3242d2ed2')
    process(10, 1988, 850, 2520, 5000, 'e32f2d21')
    process(11, 2000, 770, 2720, 5000, '234e1d1c')
    process(12, 1999, 800, 2550, 5000, '4325423fwdr2')
    process(13, 2000, 1700, 59500, 100000, '32423d2e')
    process(14, 2000, 1600, 48550, 100000, '3214213d2dx')
    process(15, 100000, 79000, 100, 100000, '3214e132d21e12')
    process(16, 100000, 77000, 99, 100000, '23412e12e12')
    process(17, 100000, 67000, 56500, 100000, '4312r32ed312e32')
    process(18, 99990, 77200, 40500, 100000, 'dqxqd32wdx23')
    process(19, 99990, 67004, 49500, 100000, '341xs1e21')
    process(20, 99990, 77000, 51300, 100000, '21sd1ws211')

if __name__ == '__main__':
    main()