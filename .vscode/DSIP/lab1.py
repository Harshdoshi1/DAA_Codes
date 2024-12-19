import cv2
import numpy as np
from matplotlib import pyplot as plt
import os

# Dynamically locate the file relative to the script's location
script_dir = os.path.dirname(os.path.abspath(__file__))
image_path = os.path.join(script_dir, 'content', 'knight.jpg')

# Load the image
image = cv2.imread(image_path, 0)  # Load as grayscale
if image is None:
    print(f"Error: Unable to load image from path: {image_path}")
    exit()

# Define a low-pass filter kernel (Gaussian)
kernel_size = 5
sigma = 1.5
low_pass_filter = cv2.getGaussianKernel(kernel_size, sigma)
low_pass_filter = low_pass_filter * low_pass_filter.T

# Apply the low-pass filter to the image
smoothed_image = cv2.filter2D(image, -1, low_pass_filter)

# Define a high-pass filter kernel (Laplacian)
high_pass_filter = np.array([[0, -1, 0],
                             [-1, 4, -1],
                             [0, -1, 0]], dtype=np.float32)

# Apply the high-pass filter to the image
sharpened_image = cv2.filter2D(image, -1, high_pass_filter)

# Display the images using Matplotlib
plt.figure(figsize=(10, 5))

# Original Image
plt.subplot(1, 3, 1)
plt.title("Original Image")
plt.imshow(image, cmap='gray')
plt.axis('off')

# Smoothed Image
plt.subplot(1, 3, 2)
plt.title("Smoothed Image")
plt.imshow(smoothed_image, cmap='gray')
plt.axis('off')

# Sharpened Image
plt.subplot(1, 3, 3)
plt.title("Sharpened Image")
plt.imshow(sharpened_image, cmap='gray')
plt.axis('off')

# Show all images
plt.tight_layout()
plt.show()
