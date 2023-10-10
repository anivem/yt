import serial
import pyautogui

# Replace 'COM3' with your actual COM port
ser = serial.Serial('COM3', 9600)

while True:
    try:
        data = ser.readline().decode().strip()
        
        if data == "vid":
            # Simulate pressing the 'K' key
            pyautogui.press('k')
        elif data == "for":
            # Simulate pressing the right arrow key
            pyautogui.press('right')
        elif data == "bac":
            # Simulate pressing the left arrow key
            pyautogui.press('left')
        else:
            print("Unknown command:", data)
            
    except KeyboardInterrupt:
        break

ser.close()
