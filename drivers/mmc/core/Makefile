#
# Makefile for the kernel mmc core.
#

obj-$(CONFIG_MMC)		+= mmc_core.o
mmc_core-y			:= core.o bus.o host.o \
				   mmc.o mmc_ops.o sd.o sd_ops.o \
				   sdio.o sdio_ops.o sdio_bus.o \
				   sdio_cis.o sdio_io.o sdio_irq.o \
				   quirks.o slot-gpio.o

mmc_core-$(CONFIG_MMC_PASSWORDS) += lock.o sysfs.o
mmc_core-$(CONFIG_OF)		+= pwrseq.o pwrseq_simple.o pwrseq_emmc.o
mmc_core-$(CONFIG_DEBUG_FS)	+= debugfs.o
obj-$(CONFIG_MMC_CQ_HCI) += hisi_cmdq_core.o
obj-$(CONFIG_HISI_MMC) += hisi_core_mmc.o
