import serial
import time
import csv

ser = serial.Serial('/dev/ttyACM0')
ser.flushInput()
baud = 9600 #9600 baud do arduino
#fileName="dados-sensores.csv" #nome do arquivo CSV gerado.


while True:
    try:
        ser_bytes = ser.readline()
        decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
        print(decoded_bytes)
        
        with open("dados_sensores.csv","a") as f: #O "a" entre parênteses diz ao Python para anexar os dados da porta serial e garantir que nenhum dado seja excluido do arquivo existente
            writer = csv.writer(f,delimiter=",")
            writer.writerow([time.time(),decoded_bytes])
    except:
        print("Interrupção via teclado")
        break
