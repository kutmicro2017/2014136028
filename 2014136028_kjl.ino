
#define Up_R 25 //�� ��ȣ��
#define Up_Y 26
#define Up_G 27
#define Do_R 4 //�� ��ȣ��
#define Do_Y 5
#define Do_G 6
#define Le_R 7 // �� ��ȣ��
#define Le_Y 8
#define Le_G 9
#define Ri_R 22 // �� ��ȣ��
#define Ri_Y 23
#define Ri_G 24 
#define Button_A 2 // ����ġ
int delaytime = 10000; //40��
volatile bool state = true; //����ġ ����, ���� �� false

void setup() {  // OUTPUT ����
  pinMode(Up_R, OUTPUT);
  pinMode(Up_G, OUTPUT);
  pinMode(Up_Y, OUTPUT);
  pinMode(Do_R, OUTPUT);
  pinMode(Do_G, OUTPUT);
  pinMode(Do_Y, OUTPUT);
  pinMode(Le_R, OUTPUT);
  pinMode(Le_G, OUTPUT);
  pinMode(Le_Y, OUTPUT);
  pinMode(Ri_R, OUTPUT);
  pinMode(Ri_G, OUTPUT);
  pinMode(Ri_Y, OUTPUT);
  pinMode(Button_A, INPUT_PULLUP); //�⺻�� HIGH input���� �ٸ��� ���μ��� ���� ������ ���
  attachInterrupt(0,Botton, FALLING); // ���ͷ�Ʈ 0 �� �� 2�� ��ȣ�ۿ� ���� ����ġ�� 2���� �ް�
}

void loop() {
// -----------------------------------------------------
//������ ��-��-��-��
// -----------------------------------------------------


//------------��ó��, �� ��ȣ� �ʷϻ� ----------------  
digitalWrite(Le_R, HIGH);
digitalWrite(Ri_R, HIGH);
digitalWrite(Do_R, HIGH);
digitalWrite(Up_R, LOW);
digitalWrite(Up_G, HIGH);
delay(delaytime); //40�� ���� ����
//------------------------------------------------------.
digitalWrite(Up_G, LOW); // �� ��ȣ�� �ʷϻ� ����

// -------------�ʷϻ� -> ������ �ɶ� ------------------------
Yellow(Up_Y);
// --------------------------------------------------------
// ---------------------�� ��ȣ�� �������� �ʷϺҷ� �ٲ�------------------------
digitalWrite(Up_R, HIGH); 
digitalWrite(Do_R, LOW);
digitalWrite(Do_G, HIGH); 
// ------------------------------------------------------------------------------

for(int count=0; count<1000;count++) { // ������ 10�ʵ��� �ݺ�
 if(state == false) { //����ġ�� ��������
    delay(1000); //3�� ���
    digitalWrite(Do_G, LOW); // �� ��ȣ�� �ʷϺ��� ���ش�
    Yellow(Do_Y); // �� ��ȣ�� ����� ����
    digitalWrite(Do_R, HIGH); // �� ��ȣ�� �������� �Ҵ�
    state = true; // ���¸� ó���� ture �� �ٲ���
 }
 if(count == (delaytime/1000)) break;
 delay(1000); // ������ ������ 10�� ��ٸ���
}


if(digitalRead(Do_G) == HIGH) { //����ġ�� ������ �ʾ��� ��� ����
    digitalWrite(Do_G, LOW);  // �� �ʷϺ� ����
    Yellow(Do_Y); // �� ����� ����
    digitalWrite(Do_R, HIGH); // �� ������ ����
}



digitalWrite(Do_R, HIGH);  // �� ������ ��������
digitalWrite(Le_R, LOW); // �� ������ ����
digitalWrite(Le_G, HIGH); // �� ��ȣ�� �ʷϺҸ� ����
delay(delaytime); //40�ʰ� ����
digitalWrite(Le_G, LOW); //�� �ʷϺ� ����
Yellow(Le_Y); //�� ����� ����
digitalWrite(Le_R, HIGH); // �� ������ ����


digitalWrite(Ri_R, LOW); // �� ������ ����
digitalWrite(Ri_G, HIGH);  // �� �ʷϺ� ����
delay(delaytime); 
digitalWrite(Ri_G, LOW); // �� �ʷϺ� ����
Yellow(Ri_Y); // �� ����� ����
digitalWrite(Ri_G, LOW); // �� �ʷϺ� ����
digitalWrite(Ri_R, HIGH); // �� ������ ����

}











//----------------------------------�Լ���--------------------------------
void Botton(){ //����ġ�� ������ �� ����Ǵ� �Լ�
 if(digitalRead(Do_G) == HIGH) state = false; //����ġ�� ������ state�� ���� �ٲ��ش�
}




void Yellow(const int LED) {  //yellow��ȣ ����
   for(int i =0; i < 10; i++) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
   }
}

//----------------------------------------------------------------------------