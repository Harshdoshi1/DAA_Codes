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
