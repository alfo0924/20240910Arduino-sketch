# NodeMCU-32s Arduino 程式碼分析

這段程式碼是一個 Arduino sketch，用於控制 NodeMCU-32s 開發板。讓我們逐部分分析這段程式碼：

## setup() 函數

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
}
```

這個函數在程式開始時只執行一次：

- 將內建 LED 設置為輸出模式
- 初始化串口通信，波特率設為 9600

## loop() 函數

這個函數會不斷重複執行：

### LED 控制

```cpp
digitalWrite(LED_BUILTIN, HIGH);
delay(2000);
digitalWrite(LED_BUILTIN, LOW);
delay(5000);
```

- 打開內建 LED，持續 2 秒
- 關閉內建 LED，持續 5 秒
- 這將創建一個 LED 閃爍效果，亮 2 秒，滅 5 秒

### 串口輸出

```cpp
Serial.println("hello from NodeMCU-32s");
Serial.print("Hello world from NodeMCU-32s controll pad ");
Serial.println("initialing Multiplication table");
```

通過串口輸出三行文字，介紹設備並提示即將顯示乘法表

### 乘法表生成

```cpp
for (int i = 1; i <= 9; i++) {
  for (int i2 = 1; i2 <= 9; i2++) {
    String val = String(i) + "*" + String(i2) + "=" + (i*i2) + "\t";
    Serial.print(val);
  }
  Serial.println();
}
```

這段代碼生成並輸出一個 9x9 的乘法表：

- 使用嵌套的 for 循環遍歷 1 到 9 的所有組合
- 對每個組合，計算乘積並格式化為字符串
- 每行結束後換行

## 總結

這個程式實現了以下功能：

1. 控制 LED 閃爍（2 秒亮，5 秒滅）
2. 通過串口輸出歡迎信息
3. 生成並輸出 9x9 乘法表

這個程式展示了基本的 I/O 操作（LED 控制和串口通信）以及簡單的循環和字符串處理。它適合用於測試 NodeMCU-32s 的基本功能和串口通信。
