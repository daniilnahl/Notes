| Function           | Formatting power         | Auto‑newline?   | Use case                          |
| ------------------ | ------------------------ | --------------- | --------------------------------- |
| `printf(...)`      | Full C‑style (`%`-specifiers)  | No (needs `\n`) | Complex, C‑style formatted output |
| `Serial.print()`   | Some overloads for types | No              | Simple serial writes, no newline  |
| `Serial.println()` | Same as `.print()`       | Yes (`\r\n`)    | One‑line logging with newline     |


- **printf(...)** - printf("Temp = %.2f °C, Humidity = %d%%\n", temp, humidity);
- **println** = println("Temp=" + String(t,2) + "°C Humidity=" + String(h) + "%");
- **print**:
    - Serial.print("Temp=");      
    - Serial.print(t, 2);         /print float to 2 decimals
    - Serial.print("°C Humidity=");
    - Serial.print(h);
    - Serial.print("%\n"); 