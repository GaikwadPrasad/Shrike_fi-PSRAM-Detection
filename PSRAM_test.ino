void setup()
{
    Serial.begin(115200);

    if (psramFound()) {
        Serial.printf("PSRAM Found\n");
    } 
    else {
        Serial.println("PSRAM NOT Found");
        return;
    }

   //Check the total size of PSRAM
    Serial.printf("Size of PSRAM: %d bytes \n", ESP.getPsramSize());

    //Allocating the memory in PSRAM as a Example
    size_t buffer_size = 2 * 1024 * 1024;

    uint8_t *data = (uint8_t *)ps_malloc(buffer_size);

    Serial.printf("Buffer size: %d bytes \n", buffer_size);
}

void loop()
{
}