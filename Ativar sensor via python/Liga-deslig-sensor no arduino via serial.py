#com o arduino ligado executar esse script no terminal

import serial

#Para saber qual a porta utilizada pelo microcontrolador basta executar no terminal Linux,
#com o microcontrolador conectado: python -m serial.tools.list_ports

arduino = serial.Serial('/dev/ttyACM0',9600,timeout=2)

arduino.write("on\n")

#Caso necessário, para ler a resposta do arduino
#arduino.read_until('\n')
 
