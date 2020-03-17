
#디지털 영상처리 chapter 2의 6번 문항
import numpy as np
import cv2
import random

def onMouse(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONDOWN:
        cv2.circle(img,(x,y), 100,(random.randrange(256),random.randrange(256),random.randrange(256)),-1)
    if event == cv2.EVENT_RBUTTONDOWN:
        cv2.rectangle(img,(x-50,y-50),(x+50,y+50),
        (random.randrange(256),random.randrange(256),random.randrange(256)),-1)

img = np.zeros((600, 800, 3), dtype = np.uint8)
cv2.namedWindow('image')
cv2.setMouseCallback('image', onMouse)

while(1):
    cv2.imshow('image',img)
    if cv2.waitKey(1) & 0xFF == 27:
        break

cv2.destroyAllWindows()
