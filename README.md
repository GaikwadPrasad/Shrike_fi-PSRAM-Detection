# PSRAM Test (Shrike fi)

This project verifies whether the PSRAM is being detected in the Shrike-Fi board.

Example:- allocates a 2 MB buffer in PSRAM.

## What `PSRAM_test.ino` does

1. Starts serial communication at `115200` baud.
2. Checks PSRAM availability using `psramFound()`.
3. Prints total PSRAM size using `ESP.getPsramSize()`.
4. Allocates a `2 * 1024 * 1024` byte buffer with `ps_malloc()` it adjustable upto 8 MB.
5. Prints the requested buffer size.

## Requirements

- Arduino IDE
- ESP32 board package installed
- An ESP32 board variant that supports PSRAM (for example ESP32-WROVER)

## Arduino IDE Setup

1. Open `PSRAM_test.ino`.
2. In the Tools menu, select ESP32S3 Dev Module as the board[**Tools > Board**].
3. In the Tools menu, select the port to which the Shrike-Fi is connected [**Tools > Port**].
4. In the Tools menu, if PSRAM is disabled by default. Click on PSRAM and select QSPI PSRAM [**Tools > PSRAM**].
5. Upload the sketch.

## How to Run

1. Open **Serial Monitor**.
2. Set baud rate to **115200**.
3. Press reset (if needed).
4. Check the printed output.

## Expected Output

If PSRAM is available:

```text
PSRAM FoundSize of PSRAM: <number> bytes
Buffer size: 2097152 bytes
```

If PSRAM is not available:

```text
PSRAM NOT Found
```

## Notes

- `ps_malloc()` returns a pointer in external PSRAM.
- This sketch currently does not validate whether `ps_malloc()` returned `nullptr`.
- `Serial.printf("PSRAM Found")` does not include a newline, so the next message appears on the same line.
