# import cv2
# import numpy as np
# from matplotlib import pyplot as plt
# import os

# # Dynamically locate the file relative to the script's location
# script_dir = os.path.dirname(os.path.abspath(__file__))
# image_path = os.path.join(script_dir, 'content', 'cheetah.jpg')

# # Load the noisy image
# noisy_image = cv2.imread(image_path, 0)  # Load as grayscale
# if noisy_image is None:
#     print(f"Error: Unable to load image from path: {image_path}")
#     exit()

# # Apply a median filter to remove noise
# filter_size = 5  # Filter size (should be an odd number, e.g., 3, 5, 7)
# filtered_image = cv2.medianBlur(noisy_image, filter_size)

# # Define a low-pass filter kernel (Gaussian)
# kernel_size = 5
# sigma = 1.5
# low_pass_filter = cv2.getGaussianKernel(kernel_size, sigma)
# low_pass_filter = low_pass_filter * low_pass_filter.T
# smoothed_image = cv2.filter2D(filtered_image, -1, low_pass_filter)

# # Define a high-pass filter kernel (Laplacian)
# high_pass_filter = np.array([[0, -1, 0],
#                              [-1, 4, -1],
#                              [0, -1, 0]], dtype=np.float32)
# sharpened_image = cv2.filter2D(filtered_image, -1, high_pass_filter)

# # Display the images using Matplotlib
# plt.figure(figsize=(10, 7))

# # Original Image
# plt.subplot(2, 2, 1)
# plt.title("Original Noisy Image")
# plt.imshow(noisy_image, cmap='gray')
# plt.axis('off')

# # Median Filtered Image
# plt.subplot(2, 2, 2)
# plt.title("Median Filtered Image")
# plt.imshow(filtered_image, cmap='gray')
# plt.axis('off')

# # Smoothed Image
# plt.subplot(2, 2, 3)
# plt.title("Smoothed Image (Gaussian)")
# plt.imshow(smoothed_image, cmap='gray')
# plt.axis('off')

# # Sharpened Image
# plt.subplot(2, 2, 4)
# plt.title("Sharpened Image (Laplacian)")
# plt.imshow(sharpened_image, cmap='gray')
# plt.axis('off')

# # Show all images
# plt.tight_layout()
# plt.show()

import cv2
import numpy as np
from matplotlib import pyplot as plt

# Load the image
image_path = 'content/cheetah.jpg'
image = cv2.imread(image_path, 0)  # Load as grayscale
if image is None:
    print(f"Error: Unable to load image from path: {image_path}")
    exit()

# Define the kernel (structuring element)
kernel = np.ones((5, 5), np.uint8)

# Perform Erosion
erosion = cv2.erode(image, kernel, iterations=1)

# Perform Dilation
dilation = cv2.dilate(image, kernel, iterations=1)

# Perform Opening (Erosion followed by Dilation)
opening = cv2.morphologyEx(image, cv2.MORPH_OPEN, kernel)

# Perform Closing (Dilation followed by Erosion)
closing = cv2.morphologyEx(image, cv2.MORPH_CLOSE, kernel)

# Display the original image and the results using Matplotlib
plt.figure(figsize=(12, 6))

# Original Image
plt.subplot(1, 5, 1)
plt.title("Original")
plt.imshow(image, cmap='gray')
plt.axis('off')

# Erosion
plt.subplot(1, 5, 2)
plt.title("Erosion")
plt.imshow(erosion, cmap='gray')
plt.axis('off')

# Dilation
plt.subplot(1, 5, 3)
plt.title("Dilation")
plt.imshow(dilation, cmap='gray')
plt.axis('off')

# Opening
plt.subplot(1, 5, 4)
plt.title("Opening")
plt.imshow(opening, cmap='gray')
plt.axis('off')

# Closing
plt.subplot(1, 5, 5)
plt.title("Closing")
plt.imshow(closing, cmap='gray')
plt.axis('off')

plt.tight_layout()
plt.show()

# Save results to files (optional)
cv2.imwrite('erosion.jpg', erosion)
cv2.imwrite('dilation.jpg', dilation)
cv2.imwrite('opening.jpg', opening)
cv2.imwrite('closing.jpg', closing)

print("Images saved successfully.")
