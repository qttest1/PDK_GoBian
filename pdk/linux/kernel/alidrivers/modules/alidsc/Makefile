#
# Makefile for the ali dsc driver
#

obj-$(CONFIG_ALI_DSC)             += alidsc.o
alidsc-y := ali_dsc_rpc.o ali_dsc.o ali_dsc_csa.o ali_dsc_aes.o ali_dsc_des.o ali_dsc_sha.o
alidsc-$(CONFIG_ALI_CRYPTO_NAND)  += ali_dsc_nand.o
