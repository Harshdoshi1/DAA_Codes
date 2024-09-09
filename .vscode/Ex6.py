import numpy as np
import matplotlib.pyplot as plt

# Original signal
signal = np.array([1, 2, 3, 4, 5, 6, 7, 8])

# Compute the FFT of the signal
fft_result = np.fft.fft(signal)

# Compute the magnitude and phase spectrum of the FFT result
magnitude_spectrum = np.abs(fft_result)
phase_spectrum = np.angle(fft_result)

# Compute the IFFT of the FFT result
reconstructed_signal = np.fft.ifft(fft_result)

# Plot the original signal
plt.figure(figsize=(12, 6))

plt.subplot(3, 1, 1)
plt.stem(signal)
plt.title('Original Signal')
plt.xlabel('Sample Index')
plt.ylabel('Amplitude')

# Plot the magnitude spectrum
plt.subplot(3, 1, 2)
plt.stem(magnitude_spectrum)
plt.title('Magnitude Spectrum')
plt.xlabel('Frequency Bin')
plt.ylabel('Magnitude')

# Plot the phase spectrum
plt.subplot(3, 1, 3)
plt.stem(phase_spectrum)
plt.title('Phase Spectrum')
plt.xlabel('Frequency Bin')
plt.ylabel('Phase (radians)')

plt.tight_layout()
plt.show()

# Verify that the reconstructed signal matches the original signal
print("Original Signal:", signal)
print("Reconstructed Signal:", np.real(reconstructed_signal))
    