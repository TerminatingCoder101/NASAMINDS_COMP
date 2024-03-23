#include "switches.h"
#include "times.h"
#include "store.h"
#include "find.h"
/*多次读取指令 - leia o comando várias vezes*/
unsigned char ReadMulti[10] = {0XAA,0X00,0X27,0X00,0X03,0X22,0XFF,0XFF,0X4A,0XDD};
unsigned int timeSec = 0;
unsigned int timemin = 0;
unsigned int dataAdd = 0;
unsigned int incomedate = 0;
unsigned int parState = 0;
unsigned int codeState = 0;
int TAG[100];
int Location[15];
int tag;
bool trans=false;
int add=0;
int strength;
void setup() {
  //设置串口，并设置 - Defina a porta serial e defina - LED
  pinMode(LED_BUILTIN, OUTPUT);
  //pins for switch 1
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  //pins for the main switch
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  //pins for switch 2
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(115200); //设置串口波特率 - Defina a taxa de transmissão da porta serial 115200
  
  Serial.println("Hello world.");// "Hello world."
  
  Serial.write(ReadMulti,10);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(3,HIGH);
}

void loop() {

  //间隔一段时间后发生循环读取命令 - Comandos de leitura cíclica ocorrem após algum intervalo de tempo
  timeSec ++ ;
  switcher();
  if (main_switch==0){
     antenna_switch_1();
   }
  if(main_switch==1){
     antenna_switch_2();
   }
  time_function();
  if(timeSec >= 50000){
    timemin ++;
	
    timeSec = 0;
	
    if(timemin >= 20){
      timemin = 0;
      //发送循环读取指令 - Enviar comando de leitura cíclica
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.write(ReadMulti,10);
      digitalWrite(LED_BUILTIN, LOW); 
    }
  }
  if (finish==1){
    Serial.print("Location: [");
    for (int k=0;k<15;k++){
      Serial.print(Location[k]);Serial.print(",");
    }
    Serial.print(" ]");Serial.println(" ");
    finish++;
  }
 //Serial.print("antenna number :");Serial.println(antenna);Serial.print("time :");Serial.println(time);Serial.print("Switch :");Serial.println(main_switch);
  if(Serial.available() > 0 && finish==0)//串口接收到数据 - A porta serial recebe dados
  {
    //收到回复,以下是读到卡片示例 - Recebi uma resposta, o seguinte é um exemplo de um cartão de leitura
    //AA 02 22 00 11 C7 30 00 E2 80 68 90 00 00 50 0E 88 C6 A4 A7 11 9B 29 DD 
    /*
    AA:帧头
    02:指令代码
    22:指令参数
    00 11:指令数据长度，17个字节
    C7：RSSI信号强度
    30 00:标签PC码：标签厂相关信息登记
    E2 80 68 90 00 00 50 0E 88 C6 A4 A7：EPC代码
    11 9B:CRC校验
    29:校验
    DD:帧尾 
	--------
	AA: cabeçalho do quadro
    02: Código de comando
    22: Parâmetro de comando
    00 11: comprimento dos dados da instrução, 17 bytes
    C7: intensidade do sinal RSSI
    30 00: código do PC da etiqueta: registro de informações relacionadas à fábrica da etiqueta
    E2 80 68 90 00 00 50 0E 88 C6 A4 A7: código EPC
    11 9B: Verificação CRC
    29: Verificar
    DD: fim do quadro
	*/
	
    incomedate = Serial.read();//获取串口接收到的数据 - Obtenha os dados recebidos pela porta serial
	
    //判断是否为对应指令代码 - Determine se é o código de instrução correspondente
    if((incomedate == 0x02)&(parState == 0))
    {
      parState = 1;
    }
    //判断是否为对应指令参数 - Determine se é o parâmetro de instrução correspondente
    else if((parState == 1)&(incomedate == 0x22)&(codeState == 0)){  
        codeState = 1;
        dataAdd = 3;
    }
    else if(codeState == 1){
      dataAdd ++;
	  
      //获取RSSI - Obter RSSI
      if(dataAdd == 6)
      {
        //Serial.print("RSSI:"); 
        strength=incomedate;               //STRENGTH 
        }
       //获取PC码 - Obter código do PC
       else if((dataAdd == 7)|(dataAdd == 8)){
        if(dataAdd == 7){
          //Serial.print("PC:"); 
          //Serial.print(incomedate, HEX);
        }
        else {
           //Serial.println(incomedate, HEX);
        }
       }
       //获取EPC，如需对EPC处理，可以在该处进行获取EPC，如需对EPC处理，可以在该处进行
	   //Obtenha EPC, se precisar processar EPC, pode fazê-lo aqui Obtenha EPC, se precisar processar EPC, pode fazê-lo aqui
       else if((dataAdd >= 9)&(dataAdd <= 20)){
        if(dataAdd == 9){
          //Serial.print("EPC:"); 
        }        
        //Serial.print(incomedate, HEX);
        //Serial.println(incomedate);           //TAG ID
        add=add+incomedate;
       }
       //位置溢出，进行重新接收 - Estouro de localização, re-receber
       else if(dataAdd >= 21){
        Serial.println(" ");
        dataAdd= 0;
        parState = 0;
        codeState = 0;
        storing(add,TAG);
        finder(add,TAG[0],antenna_number,Location);
        add=0;
        Serial.println(TAG[0]); Serial.print("antenna:");Serial.println(antenna_number);Serial.println(time);
        //Serial.println(main_switch);
        //Serial.println(antenna_number);
        //Serial.println(Location[14]);
        }
    }
     else{
      dataAdd= 0;
      parState = 0;
      codeState = 0;
      add=0;
    }
  }
}
