int sPin0 =0; 
int sPin1 =1;

Void setup()
{ 
  Serial.begin(9600);
}

Void loop()
{
  int v0 = analogRead(sPin0);
  int v1 = analogRead(Spin1);
  
  Char _log [100];
  
  Sprintf( _log, “L%d\nR%\n”, v0, v1);
  Serial.print(_log); Delay(10);
}
