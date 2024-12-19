import cv2
import numpy as np
import matplotlib.pyplot as plt
import os

# Function to apply a Gaussian filter in the frequency domain
def apply_gaussian_filter(image, sigma):
    # Convert image to float32 for Fourier Transform
    image = np.float32(image)

    # Perform Fourier Transform
    frequency_domain = cv2.dft(image, flags=cv2.DFT_COMPLEX_OUTPUT)

    # Shift the zero-frequency component to the center of the spectrum
    shifted_frequency_domain = np.fft.fftshift(frequency_domain)

    # Create Gaussian filter mask
    rows, cols = image.shape
    crow, ccol = rows // 2, cols // 2
    mask = np.zeros((rows, cols, 2), np.float32)
    for i in range(rows):
        for j in range(cols):
            distance = ((i - crow) ** 2 + (j - ccol) ** 2)
            mask[i, j] = np.exp(-distance / (2 * sigma ** 2))

    # Apply the Gaussian filter in the frequency domain
    filtered_frequency_domain = shifted_frequency_domain * mask

    # Perform Inverse Fourier Transform to obtain the filtered image
    shifted_back = np.fft.ifftshift(filtered_frequency_domain)
    filtered_image = cv2.idft(shifted_back, flags=cv2.DFT_SCALE | cv2.DFT_REAL_OUTPUT)

    # Normalize and convert the filtered image to uint8
    filtered_image = cv2.normalize(filtered_image, None, 0, 255, cv2.NORM_MINMAX)
    filtered_image = np.uint8(filtered_image)

    return filtered_image

# Function to apply a sharpening filter in the frequency domain
def apply_sharpening_filter(image, strength):
    # Convert image to float32 for Fourier Transform
    image = np.float32(image)

    # Perform Fourier Transform
    frequency_domain = cv2.dft(image, flags=cv2.DFT_COMPLEX_OUTPUT)

    # Shift the zero-frequency component to the center of the spectrum
    shifted_frequency_domain = np.fft.fftshift(frequency_domain)

    # Create high-pass filter mask
    rows, cols = image.shape
    crow, ccol = rows // 2, cols // 2
    mask = np.ones((rows, cols, 2), np.float32)
    mask[crow - strength:crow + strength, ccol - strength:ccol + strength] = 0

    # Apply the high-pass filter in the frequency domain
    filtered_frequency_domain = shifted_frequency_domain * mask

    # Perform Inverse Fourier Transform to obtain the filtered image
    shifted_back = np.fft.ifftshift(filtered_frequency_domain)
    filtered_image = cv2.idft(shifted_back, flags=cv2.DFT_SCALE | cv2.DFT_REAL_OUTPUT)

    # Normalize and convert the filtered image to uint8
    filtered_image = cv2.normalize(filtered_image, None, 0, 255, cv2.NORM_MINMAX)
    filtered_image = np.uint8(filtered_image)

    return filtered_image

# Dynamically locate the file relative to the script's location
script_dir = os.path.dirname(os.path.abspath(__file__))
image_path = os.path.join(script_dir, 'content', 'cheetah.jpg')

# Load the input image
input_image = cv2.imread(image_path, 0)  # Load the image in grayscale
if input_image is None:
    print(f"Error: Unable to load image from path: {image_path}")
    exit()

# Apply Gaussian filter
sigma = 20  # Adjust the value to control the amount of smoothing
smoothed_image = apply_gaussian_filter(input_image, sigma)

# Apply sharpening filter
strength = 20  # Adjust the value to control the strength of sharpening
sharpened_image = apply_sharpening_filter(input_image, strength)

# Display the original image and the filtered images side by side
plt.figure(figsize=(12, 6))
plt.subplot(1, 3, 1)
plt.title("Original Image")
plt.imshow(input_image, cmap='gray')
plt.axis('off')

plt.subplot(1, 3, 2)
plt.title("Smoothed Image")
plt.imshow(smoothed_image, cmap='gray')
plt.axis('off')

plt.subplot(1, 3, 3)
plt.title("Sharpened Image")
plt.imshow(sharpened_image, cmap='gray')
plt.axis('off')

plt.tight_layout()
plt.show()

# Save the filtered images (optional)
smoothed_path = os.path.join(script_dir, 'smoothed_image.jpg')
sharpened_path = os.path.join(script_dir, 'sharpened_image.jpg')
cv2.imwrite(smoothed_path, smoothed_image)
cv2.imwrite(sharpened_path, sharpened_image)
print(f"Smoothed image saved at: {smoothed_path}")
print(f"Sharpened image saved at: {sharpened_path}")
