//Essa é a implementação genérica, teria que colocar para rodar com o equipamento funcionando!

String line = "";
bool stringComplete = false;

void setup() {
  Serial.begin(9600);
  //para mais portas (sensores) basta replicar as próximas duas linhas abaixo 
  pinMode("número porta a ser utilizada",OUTPUT);
  digitalWrite("número porta a ser utilizada",HIGH);

}

//de forma análoga a linha 6, para mais portas (sendores) basta replicar dentro do "if" e "else if" as devidas portas 
void loop() {
  if (stringComplete){
    if (line.equals("on\n")){
      digitalWrite("número porta a ser utilizada",LOW);
    }
    else if (line.equals("off\n")){
      digitalWrite("número porta a ser utilizada",HIGH);
    }
    stringComplete = false;
    line = "";
  }

}

//O serialEvent é para receber eventos da porta serial, evitando fazer polling vendo se tem algo na porta
//deixando o Arduino livre para outras tarefas enquanto não chega nada no barramento serial

void serialEvent(){  
  while(Serial.available()){
    char inChar = (char)Serial.read();
    line += inChar;
    if (inChar == '\n'){
      stringComplete = true;
      Serial.print(line);
    }
  }
}
