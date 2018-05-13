
#define BTN_1 A1
#define BTN_2 A2
#define BTN_3 A3


/* Define shift register pins used for seven segment display */
#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

/* Segment byte maps for numbers 0 to 9 */
const byte SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0X80, 0X90};

/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};

const int LED_1 = 13;
const int LED_2 = 12;
const int LED_3 = 11;

void setup() {
    /* Set DIO pins to outputs */
    pinMode(LATCH_DIO, OUTPUT);
    pinMode(CLK_DIO, OUTPUT);
    pinMode(DATA_DIO, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
}

/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value) {
    digitalWrite(LATCH_DIO, LOW);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment]);
    digitalWrite(LATCH_DIO, HIGH);
}

void loop() {

    if (!digitalRead(BTN_1)) {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, HIGH);
        WriteNumberToSegment(3, 1);
    }

    if (!digitalRead(BTN_2)) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, HIGH);
        WriteNumberToSegment(3, 2);
    }

    if (!digitalRead(BTN_3)) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, LOW);
        WriteNumberToSegment(3, 3);
    }


}
