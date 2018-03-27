mport processing.serial.*;

import processing.video.*;

 

Serial port;     

 

 

int v0 = 0, v1 = 0;

 

int prevSum = 75, sum; //Checking PrevSum

boolean bPlayMovie = false;

boolean bPlaying = false;

int nCnt = 0;

 

PImage bgImage;

 

Movie mov;

int movieIndex = 0;

 

void setup() {

  size(1366, 768);  // Stage size

  background(0);

 

  frameRate(5); // What's this?  

  

  println(Serial.list());    // print a list of available serial ports

  // choose the number between the [] that is connected to the Arduino

  port = new Serial(this, Serial.list()[0], 9600);  // make sure Arduino is talking serial at this baud rate

  port.clear();            // flush buffer

  port.bufferUntil('\n');  // set buffer full flag on receipt of carriage return

  

  bgImage = loadImage("bgimg.JPG");

}

  

void draw() {

  

//  background(0);

  image(bgImage, 0, 0);

  

  if( bPlaying )

  {

    /*int n = 0;

    mov = new Movie(this, n+ ".mov");

    

    bPlaying = true;

    

    mov.play();

    mov.jump(0);*/

    image(mov, 0, 0, width, height);

    

  }

  else

  {

    sum = v0 + v1;

    println("v0 : " + v0 + " , v1 : " + v1 + " , sum : " + sum + ", prevsum : " + prevSum);

    

    if( ( prevSum - sum ) > 30 ) //Checking 100 after blowing

    {

      bPlayMovie = true;

    }

 

  

    if( bPlayMovie )  

    {    

      bPlayMovie = false;

      

      int n = (int)random(1, 6);

      println("PLAY MOVIE " + n + "(" + prevSum + "," + sum + ")");

      mov = new Movie(this, n + ".mov");

      

      bPlaying = true;

      

      mov.play();

      mov.jump(0);

  //    mov.pause();

    }

 

  }

 

  prevSum = sum;

}  //end of draw loop

 

void movieEvent(Movie m) {

  m.read();

  

  if( m.duration() == m.time() )  bPlaying = false;

}

 

void serialEvent(Serial port){ 

   String inData = port.readStringUntil('\n');

   inData = trim(inData);                 // cut off white space (carriage return)

 

//  println(inData);

   

   if (inData.charAt(0) == 'L'){

     inData = inData.substring(1);

     v0 = int(inData);

   }

   if (inData.charAt(0) == 'R'){

     inData = inData.substring(1);

     v1 = int(inData);

   }

}

 

