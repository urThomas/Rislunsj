

#include <stdio.h>
#include <bcm2835.h>


int SPI_init(){
	if (!bcm2835_init()){
		printf("bcm2835_init failed. Are you running as root??\n");
		return 1;
	}
	if (!bcm2835_spi_begin()){
		rintf("bcm2835_spi_begin failedg. Are you running as root??\n");
		return 1;
	}

	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // MSB kommer først i melding
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536); // The default
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // CS0 er vlgt
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
	return 0;
}

uint8_t SPI_read(int pin){
	if (0>pin || pin>1)
		printf("Udefinert CS under SPI_read\n");

	if (pin == 0) bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
	else if (pin == 1) bcm2835_spi_chipSelect(BCM2835_SPI_CS1);

	uint8_t dummy_data = 0x02
	uint8_t data = bcm2835_spi_transfer(dummy_data);
	return data;
}

void SPI_send(uint8_t data, int pin){
	if (0>pin || pin>1)
		printf("Udefinert CS under SPI_send\n");

	if (pin == 0) bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
	else if (pin == 1) bcm2835_spi_chipSelect(BCM2835_SPI_CS1);

	bcm2835_spi_transfer(data);
}