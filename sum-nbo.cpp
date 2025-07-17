#include <stddef.h> //size_t
#include <stdint.h> //uint8_t, uint32_t
#include <stdio.h> //printf, fprintf, fopen, fclose, stderr
#include <netinet/in.h> //ntohl
			
//declare
uint32_t read_ntohl(const char* filename);

int main() {
	uint32_t num1 = read_ntohl("thousand.bin");
	uint32_t num2 = read_ntohl("five-hundred.bin");
	uint32_t num3 = read_ntohl("two-hundred.bin");

	uint32_t total = num1 + num2 + num3;

	printf("%d(0x%0.8x) + %d(0x%0.8x) + %d(0x%0.8x) = %d(%0.8x)",
		num1, num1, num2, num2, num3, num3, total, total);

	return 0;
}

uint32_t read_ntohl(const char* filename) {
	FILE* fp = fopen(filename, "rb");

	uint32_t nbo_val;
	size_t byte_read = fread(&nbo_val, sizeof(uint32_t), 1, fp);

	if (byte_read != 1) {
		fprintf(stderr, "Failed to read 4 bytes file");
		fclose(fp);
		return 0;
	}

	fclose(fp);

	return ntohl(nbo_val);
}
