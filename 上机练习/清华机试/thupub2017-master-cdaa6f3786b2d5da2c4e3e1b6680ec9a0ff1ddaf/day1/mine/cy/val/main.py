# encoding: utf-8

import os, sys, re

def process(index, n, m, q, type):
    input_file = ''
    output_file = ''
    if index < 0:
        input_file = os.path.join('..', 'down', 'mine%d.in' % (-index))
        output_file = os.path.join('..', 'down', 'mine%d.ans' % (-index))
    else:
        input_file = os.path.join('..', 'data', 'mine%d.in' % (index))
        output_file = os.path.join('..', 'data', 'mine%d.ans' % (index))
    
    cmd = './val.exe -n %d -m %d -q %d -t %s < %s' % (n, m, q, type, input_file)
    print cmd
    assert os.system(cmd) == 0
    assert os.system('cp %s mine.in' % input_file) == 0
    assert os.system('./std.exe') == 0
    assert os.system('diff mine.out %s' % output_file) == 0

def main():
    process(-1, 1000, 1000, 60000, 'N')
    process(-2, 1000, 1000, 60000, 'N')
    process(-3, 1000, 1000, 60000, 'N')

    process(1, 10, 10, 60, 'A')
    process(2, 10, 10, 60, 'A')
    process(3, 10, 10, 60, 'B')
    process(4, 10, 10, 60, 'B')
    process(5, 10, 10, 60, 'N')
    process(6, 10, 10, 60, 'N')
    process(7, 1, 1000, 1000, 'A')
    process(8, 1, 1000, 1000, 'A')
    process(9, 1, 1000, 1000, 'B')
    process(10, 1, 1000, 1000, 'B')
    process(11, 1, 1000, 1000, 'N')
    process(12, 1, 1000, 1000, 'N')
    process(13, 300, 300, 8000, 'A')
    process(14, 300, 300, 8000, 'A')
    process(15, 300, 300, 8000, 'B')
    process(16, 300, 300, 8000, 'B')
    process(17, 300, 300, 8000, 'N')
    process(18, 300, 300, 8000, 'N')
    process(19, 300, 300, 8000, 'N')
    process(20, 1000, 1000, 60000, 'N')

if __name__ == '__main__':
    main()