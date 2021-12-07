#define pinCLK 2
#define pinDT 7
#define pinSW A0
 uint8_t CLK;
  uint8_t DT;
  uint8_t pas_CLK=0;
  uint8_t pas_DT=0;
 int8_t count=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
  pinMode(pinCLK,INPUT);
  pinMode(pinDT,INPUT);
  pinMode(pinSW,INPUT);

}
void loop() {
  // put your main code here, to run repeatedly
 
   CLK=digitalRead(pinCLK)&0x01;
  DT=digitalRead(pinDT)&0x01;
 
 if((pas_CLK==0&&CLK==1)&&(pas_DT|DT==1))//filter
 {
  count--;
  Serial.print("Position: ");
    Serial.println(count);
 }
 if((pas_CLK==1&&CLK==0)&&(pas_DT|DT==1))//filter
 {
  count++;
 Serial.print("Position: ");
    Serial.println(count);
 }
 if(digitalRead(pinSW)==0)
 {
  Serial.println("Push ");
 }
  pas_CLK=CLK;
  pas_DT=DT;
}
