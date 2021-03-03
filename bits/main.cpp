#include <cstdio>
#include <cstdint>

template <class T>
void printbinary(T value) {
    for(int i = 0; i < sizeof(T) * 8; i++) {
        printf("%c", (value >> i & 0x01) == 0 ? '0' : '1');
    }
    printf("\n");
}


int main(int argc, char* argv[]) {
    float f = 5.7124564;
    uint8_t u8 = 10;
    int8_t s8 = 10;
    int8_t ns8 = -10;
    uint16_t u16 = 10;
    int16_t s16 = 5334;
    int16_t ns16 = -5334;
    uint32_t u32 = 678329;
    int32_t s32 = -678329;
    uint64_t u64 = 123141289;
    int64_t s64 = -123141289;

    printf("8-bit unsigned integer val = %u: ", u8);
    printbinary<uint8_t>(u8);
    printf("8-bit signed integer val = %d: ", s8);
    printbinary<int8_t>(s8);
    printf("8-bit negative signed integer val = %d: ", ns8);
    printbinary<int8_t>(ns8);
    printf("16-bit unsigned integer val = %d: ", u16);
    printbinary<int16_t>(u16);
    printf("16-bit signed integer val = %d: ", s16);
    printbinary<int16_t>(s16);
    printf("16-bit negative signed integer val = %d: ", ns16);
    printbinary<int16_t>(ns16);
    printf("32-bit unsigned integer val = %u: ", u32);
    printbinary<int16_t>(u32);
    printf("32-bit signed integer val = %d: ", s32);
    printbinary<int16_t>(s32);
    printf("64-bit unsigned integer val = %llu: ", u64);
    printbinary<int16_t>(u64);
    printf("64-bit signed integer val = %lld: ", s64);
    printbinary<int16_t>(s64);
}
