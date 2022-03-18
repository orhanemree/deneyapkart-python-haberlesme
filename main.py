from serial import Serial
from time import sleep

COM = "COM7"
PORT = 9600

outputs = [
    "buton", "button",
    "pmetre", "potansiyometre",
    "isensor", "ışık sensörü"
]

serial = Serial(COM, PORT)

print("Deneyapkart kontrole hoş geldiniz.\n")
print("\tKomutlar: [ kırmızı, yeşil, mavi, button, pmetre, isensor ]")
print("\n(Çıkmak için \"q\" basınız.)")

while 1:
    i = input(">>> ").strip()
    if i == "q":
        exit()
    else:
        serial.write(i.encode("utf-8"))
    
    if i in outputs:
        o = serial.readline().decode("utf-8").replace("\r", "").replace("\n", "")
        print(o)
