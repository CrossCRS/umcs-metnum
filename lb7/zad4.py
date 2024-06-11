import numpy as np
from scipy.interpolate import CubicSpline
from scipy.interpolate import lagrange
import matplotlib.pyplot as plt

x = [-1.4, -1, 0,1, 2, 2.2, 2.5, 2.7, 3, 3.2]
y = [11.95,1.85,1,0.54,0.17,0.31,0.57,0.76,0.97,0.99]

xs = np.arange(-1.4, 3.2, 0.01)

cs = CubicSpline(x, y)
lag = lagrange(x, y)

fig, ax = plt.subplots(figsize=(6.5, 4))
ax.plot(x, y, 'o', label='data')
ax.plot(xs, (abs(np.cos(xs)))**xs, label='true')
#ax.plot(x, cs(x), label='Cubic')
ax.plot(x, lag(x), label='Lagrange')

ax.legend(loc='upper right', ncol=2)
plt.show()
