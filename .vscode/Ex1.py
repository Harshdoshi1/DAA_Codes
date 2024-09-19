import numpy as np
import matplotlib.pyplot as plt

# Define discrete delta function
def delta(n, n0):
    return np.where(n == n0, 1, 0)

# Define discrete unit step function
def u(n, n0=0):
    return np.where(n >= n0, 1, 0)

# Define continuous unit step function
def u_cont(t, t0=0):
    return np.where(t >= t0, 1, 0)

# Generate discrete-time index
n = np.arange(-10, 15, 1)
# Generate continuous-time index
t = np.linspace(-10, 10, 1000)

# Signal 1: X(n) = 3delta(n) + 5delta(-n-5) + 8delta(n-7)
X1 = 3 * delta(n, 0) + 5 * delta(n, -5) + 8 * delta(n, 7)

# Signal 2: X(n) = u(n-7)
X2 = u(n, 7)

# Signal 3: X(n) = u(n) + u(n-3) + 6u(n-2) + 8u(-n-1)
X3 = u(n) + u(n-3) + 6 * u(n-2) + 8 * u(-n-1)

# Signal 4: X(t) = u(t) + 6u(-t) + 8u(t-1)
X4 = u_cont(t) + 6 * u_cont(-t) + 8 * u_cont(t-1)

# Plotting Signal 1
plt.figure(figsize=(12, 8))
plt.subplot(2, 2, 1)
plt.stem(n, X1, basefmt=" ")
plt.title(r'Signal 1: $X(n) = 3\delta(n) + 5\delta(-n-5) + 8\delta(n-7)$')
plt.xlabel('n')
plt.ylabel('X(n)')
plt.grid(True)

# Plotting Signal 2
plt.subplot(2, 2, 2)
plt.stem(n, X2, basefmt=" ")
plt.title(r'Signal 2: $X(n) = u(n-7)$')
plt.xlabel('n')
plt.ylabel('X(n)')
plt.grid(True)

# Plotting Signal 3
plt.subplot(2, 2, 3)
plt.stem(n, X3, basefmt=" ")
plt.title(r'Signal 3: $X(n) = u(n) + u(n-3) + 6u(n-2) + 8u(-n-1)$')
plt.xlabel('n')
plt.ylabel('X(n)')
plt.grid(True)

# Plotting Signal 4
plt.subplot(2, 2, 4)
plt.plot(t, X4)
plt.title(r'Signal 4: $X(t) = u(t) + 6u(-t) + 8u(t-1)$')
plt.xlabel('t')
plt.ylabel('X(t)')
plt.grid(True)

plt.tight_layout()
plt.show()
 
##