bool isLittleEndian() {
    uint32_t x = 1;
    return *(uint8_t*)&x == 1;
}

//Main idea is that if we know what should exist in 
//the 1st byte of a register we should check that 1st byte
//in isolation from the full register.

//Thus we cast the word type into single byte type (which if we are little endian)
//should hold the value of 1) and compare it with 1 to determine what endian type it is.