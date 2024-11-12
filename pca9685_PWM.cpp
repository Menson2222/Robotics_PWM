#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Ps3Controller.h>

// --- Khai báo biến để gán địa chỉ MAC của ESP32 ---
#define MAC_ADDRESS "E0:5A:1B:A1:F6:C8"

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
// --- Khai báo các biến cần sử dụng (người chơi - mức pin) ---
int player = 0;
int battery = 0;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);   

void PS3_State()
{
    // --- Những sự kiện Analog của các nút: Joystick ---
   if( abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2 ){
       Serial.print("Di chuyển Joystick bên trái:");
       Serial.print(" x = "); Serial.print(Ps3.data.analog.stick.lx, DEC);
       Serial.print(" y = "); Serial.print(Ps3.data.analog.stick.ly, DEC);
       Serial.println();
    }

   if( abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2 ){
       Serial.print("Di chuyển Joystick bên phải:");
       Serial.print(" x = "); Serial.print(Ps3.data.analog.stick.rx, DEC);
       Serial.print(" y = "); Serial.print(Ps3.data.analog.stick.ry, DEC);
       Serial.println();
   }

   // --- Những sự kiện: Mức pin ---
    if( battery != Ps3.data.status.battery ){
        battery = Ps3.data.status.battery;
        Serial.print("Mức pin của tay cầm: ");
        if( battery == ps3_status_battery_charging )      Serial.println("Đang sạc");
        else if( battery == ps3_status_battery_full )     Serial.println("ĐẦY");
        else if( battery == ps3_status_battery_high )     Serial.println("CAO");
        else if( battery == ps3_status_battery_low)       Serial.println("THẤP");
        else if( battery == ps3_status_battery_dying )    Serial.println("YẾU");
        else if( battery == ps3_status_battery_shutdown ) Serial.println("TẮT NGUỒN");
        else Serial.println("KHÔNG XÁC ĐỊNH");
    }

}

void PS3_onConnect(){
    Serial.println("Đã kết nối.");
}

void setup()
{
    Serial.begin(115200);
    pwm.begin();
    // --- Giới hạn hoạt động của chip PCA9685: 23MHz -> 27MHz ---
    pwm.setOscillatorFrequency(27000000);
    // --- Gán tần số (Chuẩn: 50Hz) ---
    pwm.setPWMFreq(MOTOR_FREQ);
      // --- Gán hàm dữ liệu PS3 ---
    Ps3.attach(PS3_State);
    // --- Gán hàm kiểm tra kết nối PS3 ---
    Ps3.attachOnConnect(PS3_onConnect);
    // --- Khởi tạo PS3 ---
    Ps3.begin(MAC_ADDRESS);
    // --- In trạng thái nếu đã thực thi được các lệnh trên ---
    Serial.println("Sẵn sàng.");
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

void  onestop() {
    pwm.setPWM(MOTOR_CHANNEL_A1, 0, 0);  
    pwm.setPWM(MOTOR_CHANNEL_A2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_B1, 0, 0); 
    pwm.setPWM(MOTOR_CHANNEL_B2, 0, 0);
    pwm.setPWM(MOTOR_CHANNEL_C1, 0, 0);    
    pwm.setPWM(MOTOR_CHANNEL_C2, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D1, 0, 0);     
    pwm.setPWM(MOTOR_CHANNEL_D2, 0, 0);   
}

void loop()
{ 
    if(!Ps3.isConnected()) 
        return;

    int lx = Ps3.data.analog.stick.lx;
    int ly = Ps3.data.analog.stick.ly;
    int rx = Ps3.data.analog.stick.rx;
    int ry = Ps3.data.analog.stick.ry;
    
    if (lx == 512 && ly == 512 && rx == 512 && ry == 512) {
        moveForward();
    }

}
