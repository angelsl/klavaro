#!/usr/bin/python
# coding: utf-8
# Extract not allowed characters from paragraphs

import sys

try:
    par_file = sys.argv[1]
except:
    par_file = './ru.paragraphs'

try:
    kbd_file = sys.argv[2]
except:
    kbd_file = './jtsuken_ru.kbd'


with open(par_file) as pf:
    lines = pf.readlines()
#print(lines[:7])
with open(kbd_file) as kf:
    letters = set("\n".join(kf.readlines()))
#print(letters)
#color_begin = '\x1b[6;30;42m'
#color_end = '\033[0m'
color_end = '<##'
lnum = 1
for s in lines:
    ss = set(s) - letters
    if ss: 
        print(lnum)
        for c in ss:
            print(c)
            #s = s.replace(c, color_begin + c + color_end)
            #s = s.replace(c, c + color_end)
        #print(lnum, s)
    lnum += 1
