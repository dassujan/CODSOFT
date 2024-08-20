# Import the OpenCV library
# pip install opencv-python          
import cv2

# Load the pre-trained model for face detection using the Haar Cascade classifier
# The haarcascade_frontalface_default.xml file contains the necessary data to detect faces
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Read the image from the file system
# 'image.jpg' should be replaced with the path to the actual image file you want to process
img = cv2.imread('image.jpg')

# Convert the image to grayscale
# Face detection typically works better on grayscale images because it simplifies the data
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Detect faces in the grayscale image
# The detectMultiScale function detects objects (faces) of different sizes in the input image
# scaleFactor adjusts how the image is scaled down to detect faces
# minNeighbors specifies how many neighbors each rectangle should have to retain it
# minSize defines the minimum size of the detected face
faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

# Draw rectangles around the detected faces in the original image
# For each face detected, (x, y) is the top-left corner and (w, h) are the width and height
for (x, y, w, h) in faces:
    cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)  # The rectangle is drawn in blue (255, 0, 0) with a thickness of 2

# Display the output image with the detected faces
cv2.imshow('Face Detection', img)

# Wait for a key press indefinitely or for a specified amount of time
# In this case, it waits indefinitely until a key is pressed
cv2.waitKey(0)

# Close the window that was opened with cv2.imshow()
cv2.destroyAllWindows()
