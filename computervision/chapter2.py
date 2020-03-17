# 디지털 영상처리 chapter 2의 5번 문항
import numpy as np
import cv2

'''
np.zeros : c++에서 mat 역활(캔버스 생성), 원래는 행렬 생산
(row, col, channel, type) row 행, col 열, channel 색상 채널 수
'''
src = np.zeros((600, 800, 3), dtype = np.uint8)

'''
circle 매개변수
1. src : 만들 그림(캔버스)
2. 100,100 : 만들 위치(y,x)
3. 50 : 반지름(radius)
4. (255,0,0) : B G R 색상조합
5. 0 : 원 안에 안 채움, -1 : 원 안 채움
6. 외곽선: line_4, line_8 선의 형태 
'''
cv2.circle(src, (100, 100), 50, (255, 0, 0), 30, cv2.LINE_8)

cv2.imshow("src", src)
cv2.waitKey(0)
cv2.destroyAllWindows()