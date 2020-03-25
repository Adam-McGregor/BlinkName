int led1 = D0;
// You'll need to wire an LED to this one to see it blink.

int led2 = D7;
// This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.


const int sig = 36;
const char letter[sig][2]   =   {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U" , "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
const int code_length[sig]  =   {2, 4, 4, 3, 1, 4, 3, 4, 2, 4, 3, 4, 2, 2, 3, 4, 4, 3, 3, 1, 3, 4, 3, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
const int code[sig][5]      =   {
                                    {1, 3},
                                    {3, 1, 1, 1},
                                    {3, 1, 3, 1},
                                    {3, 1, 1},
                                    {1},
                                    {1, 1, 3, 1},
                                    {3, 3, 1},
                                    {1, 1, 1, 1},
                                    {1, 1},
                                    {1, 3, 3, 3},
                                    {3, 1, 3},
                                    {1, 3, 1, 1},
                                    {3, 3},
                                    {3, 1},
                                    {3, 3, 3},
                                    {1, 3, 3, 1},
                                    {3, 3, 1, 3},
                                    {1, 3, 1},
                                    {1, 1, 1},
                                    {3},
                                    {1, 1, 3},
                                    {1, 1, 1, 3},
                                    {1, 3, 3},
                                    {3, 1, 1, 3},
                                    {3, 1, 3, 3},
                                    {3, 3, 1, 1},
                                    {1, 3, 3, 3, 3},
                                    {1, 1, 3, 3, 3},
                                    {1, 1, 1, 3, 3},
                                    {1, 1, 1, 1, 3},
                                    {1, 1, 1, 1, 1},
                                    {3, 1, 1, 1, 1},
                                    {3, 3, 1, 1, 1},
                                    {3, 3, 3, 1, 1},
                                    {3, 3, 3, 3, 1},
                                    {3, 3, 3, 3, 3},
                                };
char space[2] = " ";


char word[5] = "ADAM";


void setup() {

  // We are going to tell our device that D0 and D7 (which we named led1 and led2 respectively) are going to be output
  // (That means that we will be sending voltage to them, rather than monitoring voltage that comes from them)

  // It's important you do this here, inside the setup() function rather than outside it or in the loop function.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}


void loop() {
 
    for (int i = 0; i < 4; i++)
    {
        if (word[i] == space[0])
        {
            delay(3000);
            break;
        }
        for (int j = 0; j < sig; j++)
        {
            if (word[i] == letter[j][0])
            {
                for (int k = 0; k < code_length[j]; k++)
                {
                    digitalWrite(led1, HIGH);
                    digitalWrite(led2, HIGH);
                    
                    delay(code[j][k] * 1000); //seconds
                    
                    digitalWrite(led1, LOW);
                    digitalWrite(led2, LOW);
                    
                    delay(1000);
                }
                break;
            }
        }
        delay(2000); //delay 3 seconds 1000 + 2000
    }
    
    delay(4000); //delay 7000 for next word

}
