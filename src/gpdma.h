#include <stdint.h>

#pragma once

void
gpdma_init(void);

void
gpdma_configure_channel(uint8_t channel_number,
			void *src,
			void *dst,
			uint32_t len);
