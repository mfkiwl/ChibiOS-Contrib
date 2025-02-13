ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/UARTv1/hal_serial_lld.c
endif
ifneq ($(findstring HAL_USE_UART TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/UARTv1/hal_uart_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/UARTv1/hal_serial_lld.c
PLATFORMSRC += $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/UARTv1/hal_uart_lld.c
endif

PLATFORMINC += $(CHIBIOS_CONTRIB)/os/hal/ports/ES32/LLD/UARTv1
