import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
# Đọc ảnh ở chế độ ảnh xám (Grayscale) để ma trận đơn giản nhất (2D)
img_raw = plt.imread(r"C:\Users\ACER\Pictures\images (1).jpg") 
def show_image(im, title):
    plt.figure()
    plt.imshow(im, cmap='gray')
    plt.title(title)
    plt.axis('off')
    plt.show()
image_b = img_raw.copy()
image_b[:,:,(0,1)] = 0
show_image(image_b, "Ảnh gốc")