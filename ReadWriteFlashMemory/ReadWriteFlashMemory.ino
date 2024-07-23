#include <Arduino.h>
#include <STM32Flash.h>

// Define the flash sector to use - adjust according to your STM32 board
#define FLASH_SECTOR FLASH_SECTOR_7

// Data structure to store in flash
struct StoredData {
  uint32_t value1;
  float value2;
};

// Address in flash memory where the data will be stored
#define DATA_ADDRESS 0x08060000 // Example address in Sector 7

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // Initialize STM32Flash library
  STM32Flash.begin();

  // Example data to store in flash memory
  StoredData dataToStore = {
    .value1 = 123,
    .value2 = 456.789
  };

  // Write data to flash memory
  STM32Flash.write(DATA_ADDRESS, (uint8_t*)&dataToStore, sizeof(dataToStore));
  Serial.println("Data written to flash memory.");

  // Read data from flash memory
  StoredData readData;
  STM32Flash.read(DATA_ADDRESS, (uint8_t*)&readData, sizeof(readData));

  // Print read data
  Serial.print("Read value1: ");
  Serial.println(readData.value1);
  Serial.print("Read value2: ");
  Serial.println(readData.value2);
}

void loop() {
  // Your code here
}
