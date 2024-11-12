#include <Adafruit_PWMServoDriver.h>

#define PWM_Pulse 4095     
#define MOTOR_FREQ 50
// Motor Trên góc Trái
#define MOTOR_CHANNEL_A1 15      
#define MOTOR_CHANNEL_A2 16 
// Motor Trên góc Phải
#define MOTOR_CHANNEL_B1 17
#define MOTOR_CHANNEL_B2 18
// Motor Dưới góc Phải
#define MOTOR_CHANNEL_C1 21
#define MOTOR_CHANNEL_C2 22
// Motor Dưới góc Trái
#define MOTOR_CHANNEL_D1 19
#define MOTOR_CHANNEL_D2 20

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);   

void setup()
{
    Serial.begin(115200);
    pwm.begin();
    // --- Giới hạn hoạt động của chip PCA9685: 23MHz -> 27MHz ---
    pwm.setOscillatorFrequency(27000000);
    // --- Gán tần số (Chuẩn: 50Hz) ---
    pwm.setPWMFreq(MOTOR_FREQ);
    
}

// Di chuyển tiến
void moveForward() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, PWM_Pulse);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, PWM_Pulse); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, PWM_Pulse);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, PWM_Pulse);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, 0);   
}

// Di chuyển lùi
void moveBackward() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, 0);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, PWM_Pulse);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, 0); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, PWM_Pulse);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, 0);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, PWM_Pulse);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, PWM_Pulse);   
}

// Ngang Trái 
void moveleft() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, PWM_Pulse);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, 0); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, PWM_Pulse);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, PWM_Pulse);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, PWM_Pulse);   
}

// Ngang phải
void moveRight() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, 0);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, PWM_Pulse);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, PWM_Pulse); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, 0);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, PWM_Pulse);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, PWM_Pulse);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, 0);   
}
 
// Chéo Phải trên
void forwardRight() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, 0);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, PWM_Pulse); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, 0);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, PWM_Pulse);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, 0);   
}
// Chéo Trái trên
void forwardLeft() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, PWM_Pulse);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, 0); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, PWM_Pulse);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, 0);   
}

// Chéo Phải dưới
void backwardRight() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, 0);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, PWM_Pulse);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, 0); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, 0);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, PWM_Pulse);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, 0);    
}

// Chéo Trái dưới
void backwardLeft() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, 0);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, 0); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, PWM_Pulse);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, 0);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, PWM_Pulse);   
}

// Xoay trái
void turnLeft() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, 0);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, PWM_Pulse);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, PWM_Pulse); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, PWM_Pulse);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, PWM_Pulse);   
}

// Xoay phải
void turnRight() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, PWM_Pulse);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, 0); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, PWM_Pulse);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, 0);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, PWM_Pulse);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, PWM_Pulse);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, 0);   
}

void loop()
{ 
    delay(10000);
}
