#
# Makefile for the kernel usb drivers.
#
obj-y += aliusb.o
aliusb-$(CONFIG_USB_ALI_HCD)   += ali-hcd.o

EXTRA_CFLAGS += -I$(LINUX_DIR)/drivers/usb/core
