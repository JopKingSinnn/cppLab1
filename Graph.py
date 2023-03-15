#from sigma import k, ab
import numpy as np
from numpy import array, exp
import matplotlib.pyplot as plt
import csv
x=[]
y=[]
with open('your file directory.csv', 'r') as fd:
    reader = csv.reader(fd)
    for row in reader:
        x.append(int(array(row[0].split(','))))
        y.append(int(array(row[1].split(','))))
plt.scatter(x, y, color = 'cyan' ,marker = '*')
plt.legend(loc = 'best', fancybox = True, shadow = True)
plt.grid(True)
plt.show()
#print(k(x,y))
#print(ab(x,y))
