import serial
import time

# Open the serial port
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)

# Create or open a file to save data
filename = "arduino_data31032025v4_kawa.txt"
with open(filename, "w") as file:
    print("Receiving data...")
    try:
        while True:
            # Read data from Arduino
            data = arduino.readline().decode('utf-8').strip()
            if data:
                print(data)  # Print to console
                file.write(data + "\n")  # Save to file
    except KeyboardInterrupt:
        print("Data saving stopped by user.")

arduino.close()
