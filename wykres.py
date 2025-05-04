import matplotlib.pyplot as plt
import numpy as np

y = np.loadtxt('arduino_data31032025v4_kawa.txt')
x = np.array([i for i in range(0, len(y))])

# Create plot
plt.plot(x, y, marker='o', linestyle='-')

# Labels and title
plt.xlabel('t[0.5s]')
plt.ylabel('temp[C]')
plt.title('temp od czasu')

# Show plot
plt.show()
