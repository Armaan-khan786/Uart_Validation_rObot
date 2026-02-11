import serial
import time

class uart_library:

    def __init__(self):
        self.ser = None

    def open_ports(self, port, baudrate):
        self.ser = serial.Serial(port, int(baudrate), timeout=1)
        time.sleep(2)

    def send_data(self, data):
        self.ser.write(data.encode())

    def read_data(self):
        return self.ser.readline().decode().strip()

    def close_ports(self):
        if self.ser:
            self.ser.close()